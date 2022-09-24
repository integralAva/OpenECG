#include "System.h"



//function prototypes
Sysinfo SystemState;
void RefreshADC_OS(void const * argument);

//Thread ID
osThreadId GUI_Task_ID;

/***
* Include For Test
*/
#include "bsp_led.h"
#include "bsp_uart.h"
#include "bsp_adc.h"
#include "bsp_lcd.h"
#include "tim.h"
#include "bsp_beep.h"
#include "ADAS1000.h"
#include "bsp_spi.h"
#include "DataCenter.h"
#include "filter.h"
#include "WarSys.h"
#include "cpu_utils.h"
#include "ExtraUI.h"

//Transfer GuiLite 32 bits color to your LCD color
#define GL_RGB_32_to_16(rgb) (((((unsigned int)(rgb)) & 0xFF) >> 3) | ((((unsigned int)(rgb)) & 0xFC00) >> 5) | ((((unsigned int)(rgb)) & 0xF80000) >> 8))
//Encapsulate your LCD driver:
void gfx_draw_pixel(int x, int y, unsigned int rgb)
{
	BSP_LCD_DrawPixel(x, y, GL_RGB_32_to_16(rgb));
}

void gfx_fill_rect(int x0, int y0, int x1, int y1, unsigned int rgb)
{
    BSP_LCD_Fill(x0,y0,x1,y1,GL_RGB_32_to_16(rgb));
}

struct EXTERNAL_GFX_OP
{
    void (*draw_pixel)(int x, int y, unsigned int rgb);
	void (*fill_rect)(int x0, int y0, int x1, int y1, unsigned int rgb);
}gfx_op;

extern void startGUI(int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
extern void GUI_Draw_BigNum(uint16_t x,uint16_t y,short num,uint32_t color,uint32_t bk);
extern void GUI_Show_SysValue(void);


static void Setup_GUI(void const * argument)
{
    startGUI(800,480,2,&gfx_op);
    while(1);
}

static void GUI_ECG_Value(void const * argument)
{
    LCD_ShowString(610,0,100,32,32,(char*)"HR",0xFF00);
    LCD_ShowString(610,130,100,32,32,(char*)"RR",0xFFFF00);
    while(1)
    {
        //LCD_ShowNum(610,20,ECG_BMP,3,32,Green);
        BSP_LCD_Fill(600,30,800,130,0);
        GUI_Draw_BigNum(610,20,ECG_BMP,0xFF00,0);
        BSP_LCD_Fill(600,160,800,270,0);
        GUI_Draw_BigNum(610,160,RESP_RATE,0xFFFF00,0);
        osDelay(2000);
    }
}



static void LOFF_Disp(void const * argument)
{
    while(1)
    {
        BSP_LCD_Fill(600,280,800,330,0);
        if(ADAS1000_Data.LOFF != 0)
        {
            HAL_TIM_Base_Stop_IT(&htim14);
            LCD_ShowString(610,280,90,50,32,(char*)"LOFF:",0xFFFF00);
            CreatWaring(WAR_NOR);
        }else
        {
            HAL_TIM_Base_Start_IT(&htim14);
            CreatWaring(WAR_Clear);
        }
        
        if((ADAS1000_Data.LOFF & (1 << 19)) != 0)
        {
            LCD_ShowString(700,280,100,50,32,(char*)"V",0xFFFF00);
            osDelay(1000);
        }
        if((ADAS1000_Data.LOFF & (1 << 22)) != 0)
        {
            LCD_ShowString(700,280,100,50,32,(char*)"LA",0xFFFF00);
            osDelay(1000);
        }
        if((ADAS1000_Data.LOFF & (1 << 20)) != 0)
        {
            LCD_ShowString(700,280,100,50,32,(char*)"RA",0xFFFF00);
            osDelay(1000);
        }
        if((ADAS1000_Data.LOFF & (1 << 21)) != 0)
        {
            LCD_ShowString(700,280,100,50,32,(char*)"LL",0xFFFF00);
            osDelay(1000);
        }
        if((ADAS1000_Data.LOFF & (1 << 23)) != 0)
        {
            LCD_ShowString(700,280,100,50,32,(char*)"RLD",0xFFFF00);
            osDelay(1000);
        }
    }
}

static void RR_Calc_Func(void const * argument)
{
    while(1)
    {
        RR_Calc();
        osDelay(1000);
    }
}

/* Include For Program */
void Program_Boot(void)
{
    //电容上电缓冲
    osDelay(100);
    
 
    /*Init Device*/
    BSP_LED_Init();
    BSP_BEEP_Init();
    BSP_ADC_Init();
    BSP_LCD_Init();
    
    /*Init Timer*/
    HAL_TIM_Base_Start_IT(&htim6);
    
    /*Set Device*/
    BSP_BEEP_Set_Volume(10);
    
    
    /*Init Apps*/
    gfx_op.draw_pixel = gfx_draw_pixel;
    gfx_op.fill_rect = gfx_fill_rect;
    
    #ifndef __ANA_DISABLE_
    Filter_Init();
    ADAS1000_Init();
    //TIM17 is used to check DRDY pin
    HAL_TIM_Base_Start_IT(&htim13);
    //TIM7 is used to calculate Basicline
    HAL_TIM_Base_Start_IT(&htim7);
    
    #endif

    //GUI线程
    osThreadDef(GUI_Task, Setup_GUI, osPriorityNormal, 0, 1024);
    GUI_Task_ID = osThreadCreate(osThread(GUI_Task), NULL);
    //显示线程
    osThreadDef(GUI_ValueTask, GUI_ECG_Value, osPriorityBelowNormal, 0, 512);
    osThreadCreate(osThread(GUI_ValueTask), NULL);
    osDelay(100);
    //系统变量进程
    osThreadDef(BatteryCalc_Task, RefreshADC_OS, osPriorityIdle, 0, 512);
    osThreadCreate(osThread(BatteryCalc_Task), NULL);
    
    osDelay(500);
    
    while(1)
    {
        if(ADAS1000_Data.LOFF != 0xF80000)
        {
            break;
        }
        osDelay(1);
    }
    
    //ECG & RR计算进程
    //TIM14 for BMP
    HAL_TIM_Base_Start_IT(&htim14);
    osThreadDef(RRCalc_Task, RR_Calc_Func, osPriorityLow, 0, 512);
    osThreadCreate(osThread(RRCalc_Task), NULL);
    //LOFF
    osThreadDef(LOFF_Task, LOFF_Disp, osPriorityLow, 0, 512);
    osThreadCreate(osThread(LOFF_Task), NULL);
    
    while(1)
    {
        //开始数据处理
        DataCenter_Run();
        osDelay(1);
    }
}

void SYS_SOFT_RESET(void)
{
    __disable_irq();
    HAL_NVIC_SystemReset();
}


void RefreshADC_OS(void const * argument)
{
    while(1)
    {
        BSP_Get_BatteryVot();
        BSP_Get_BatteryCur();
        BSP_Get_CoreTempature();
        float stand_bat = (SystemState.battery_vot*100.0f - 360.0f)/0.6f;
        uint8_t bv = (uint8_t)stand_bat;
        SystemState.PWR_BAT = bv;
        SystemState.CPU_usage = osGetCPUUsage();
        GUI_Show_SysValue();
        osDelay(2000);
    }
}



