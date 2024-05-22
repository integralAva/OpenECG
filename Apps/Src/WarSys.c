/**
 * 报警模板
 * 纯纯的过程描述~
*/
#include "WarSys.h"
#include "bsp_beep.h"
#include "bsp_led.h"

char War_List[10];

static void Normal_Waring(void* argument)
{
    LED_SetGroup(LED_Full_Yellow);
    BSP_BEEP_Run(440,700);
    vTaskDelete(NULL);
}

static void ANormal_Waring(void* argument)
{
    BSP_BEEP_Set_Volume(137);
    LED_SetGroup(LED_Full_Yellow);
    BSP_BEEP_Run(440,200);
    osDelay(300);
    BSP_BEEP_Run(440,200);
    osDelay(300);
    BSP_BEEP_Run(440,200);
    osDelay(300);
    vTaskDelete(NULL);
}

static void Mid_Waring(void* argument)
{
    BSP_BEEP_Set_Volume(137);
    LED_SetGroup(LED_Full_Red);
    BSP_BEEP_Run(440,1000);
    vTaskDelete(NULL);
}

static void AMid_Waring(void* argument)
{
    BSP_BEEP_Set_Volume(137);
    LED_SetGroup(LED_Full_Red);
    BSP_BEEP_Run(440,500);
    osDelay(600);
    BSP_BEEP_Run(440,500);
    osDelay(600);
    BSP_BEEP_Run(440,500);
    osDelay(600);
    vTaskDelete(NULL);
}

void CreatWaring(WarningType war)
{
    void (*program)(void * argument);
    switch(war){
        case WAR_NOR:
            program = Normal_Waring;
            break;
        case WAR_ANOR:
            program = ANormal_Waring;
            break;
        case WAR_MID:
            program = Mid_Waring;
            break;
        case WAR_AMID:
            program = AMid_Waring;
            break;
        case WAR_Clear:
            LED_Clear_All();
            return;
    }
    xTaskCreate(program,NULL,128,NULL,osPriorityIdle,NULL);
    
}
