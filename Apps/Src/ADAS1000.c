/**
 * "ADAS1000.c"
 * 这里是ADAS1000的驱动程序
 * 主要功能：初始化，操作ADAS1000并提供原始数据
*/
#include "ADAS1000.h"
#include "RegisterMap.h"
#include "bsp_spi.h"
#include "tim.h"

ADAS1000_DataStruct ADAS1000_Data;

/**
 * 去除数据的地址位并转为有符号数据
*/
static int32_t uint_to_int(uint32_t data)
{
    int32_t val = data & 0xFFFFFF;
    val <<= 8;
    val >>= 8;
    return val;
}

/**
 * 读寄存器函数
*/
static void ReadRegister(uint8_t RegAddr,uint32_t * Data)
{
    uint32_t Buf;
    Buf = RegAddr << 24;
    //拉低CS
    ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin << 16;
    //先发送地址，再接收数据
    SPI_Transmit32bit(Buf);
    Buf = SPI_Transmit32bit(ADAS1000_NOP);
    ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin;
    *Data = Buf;
}

static void WriteRegister(uint8_t RegAddr,uint32_t Data)
{
    uint32_t Buf;
    //最高位 置位表示写数据
    RegAddr |= 0x80;
    Buf = Data | (RegAddr << 24);
    ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin << 16;
    SPI_Transmit32bit(Buf);
    ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin;
}

void ADAS1000_PowerMode(ADAS1000_PWR mode)
{
    uint32_t temp;
    if(mode == ADAS1000_PowerDown)
    {
        ReadRegister(ADAS1000_ECGCTL,&temp);
	    WriteRegister(ADAS1000_ECGCTL,temp&(0xFFFFFFFFul-ADAS1000_ECGCTL_PWREN));
    }else if(mode == ADAS1000_PowerOn)
    {
        ReadRegister(ADAS1000_ECGCTL,&temp);
	    WriteRegister(ADAS1000_ECGCTL,temp | ADAS1000_ECGCTL_PWREN);
    }
}

static void Device_Reset(void)
{
    WriteRegister(ADAS1000_ECGCTL,ADAS1000_ECGCTL_SWRST);
    WriteRegister(ADAS1000_NOP,0);
}



static void Normal_RegisterConfig(void)
{
    uint32_t temp,read;
    /* Config CMREFCTL */
    temp = 0xE0700A;
    WriteRegister(ADAS1000_CMREFCTL,temp);
    ReadRegister(ADAS1000_CMREFCTL,&read);
    read &= 0xFFFFFF;
    if(read != temp)
    {
        Error_Handler();
    }

    /* Config FRMCTL */
    /* Speed = 2KHz Len = 6*32bit */
    /* Header,I,II,III,V,RESP */
    temp = 0xFD640;
    WriteRegister(ADAS1000_FRMCTL,temp);
    ReadRegister(ADAS1000_FRMCTL,&read);
    read &= 0xFFFFFF;
    if(read != temp)
    {
        Error_Handler();
    }

    /* Config RESPCTL */
    
    temp = 0x3319;
    WriteRegister(ADAS1000_RESPCTL,temp);
    ReadRegister(ADAS1000_RESPCTL,&read);
    read &= 0xFFFFFF;
    if(read != temp)
    {
        Error_Handler();
    }
    

    /* Config LOFFCTL */
    
    temp = 0x15;
    WriteRegister(ADAS1000_LOFFCTL,temp);
    ReadRegister(ADAS1000_LOFFCTL,&read);
    read &= 0xFFFFFF;
    if(read != temp)
    {
        Error_Handler();
    }
    

    /* Config ECGCTL */
    /* GAIN = X2.1 */
    /* Start ADC */
    temp = 0xF000AE;
    WriteRegister(ADAS1000_ECGCTL,temp);
    ReadRegister(ADAS1000_ECGCTL,&read);
    read &= 0xFFFFFF;
    if(read != temp)
    {
        Error_Handler();
    }

    //此处对表头寄存器进行操作以启用帧传输
    ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin << 16;
    SPI_Transmit32bit(0x40000000);
    ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin;
}




void ADAS1000_Init(void)
{
    Device_Reset();
    osDelay(100);
    while (LL_GPIO_IsInputPinSet(ADC_DR_GPIO_Port,ADC_DR_Pin));
    Normal_RegisterConfig();
}

/**
 * 读帧数据
*/
static void ReadFrame(void)
{
    uint32_t Frame_Cache[7];
    uint32_t DC_LEAD;
    
    ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin << 16;

    //对0x40寄存器的操作仅用于保持帧传输，无意义
    Frame_Cache[0] = SPI_Transmit32bit(0x40000000);
    //检查就绪位
    while((Frame_Cache[0] & (1 << 30)) != 0)
    {
        //如果未就绪，继续循环等待直到就绪
        Frame_Cache[0] = SPI_Transmit32bit(0);
        //当DRDY引脚处于高电平则跳出，防止卡死在while里
        if(LL_GPIO_IsInputPinSet(ADC_DR_GPIO_Port,ADC_DR_Pin) == GPIO_PIN_SET)
        {
            ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin;
            return;
        }
    }
    //已就绪，继续读数据
    for (uint8_t i = 1; i < 7; i++)
    {
        Frame_Cache[i] = SPI_Transmit32bit(0);
    }
    
    ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin;

    ADAS1000_Data.State = Frame_Cache[0];
    ADAS1000_Data.Lead_I = uint_to_int(Frame_Cache[1]);
    ADAS1000_Data.Lead_II = uint_to_int(Frame_Cache[2]);
    ADAS1000_Data.Lead_III = uint_to_int(Frame_Cache[3]);
    ADAS1000_Data.Lead_V = uint_to_int(Frame_Cache[4]);
    ADAS1000_Data.Resp = uint_to_int(Frame_Cache[5]);
    ADAS1000_Data.LOFF = Frame_Cache[6];
    
    //此处读导联脱离寄存器并重启帧传输
    ReadRegister(ADAS1000_LOFF,&DC_LEAD);
    ADAS1000_Data.LOFF = DC_LEAD & 0xFFFFFF;
    ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin << 16;
    SPI_Transmit32bit(0x40000000);
    ADC_CS_GPIO_Port->BSRR = ADC_CS_Pin;
}

void ADAS1000_IT(void)
{
    if (LL_GPIO_IsInputPinSet(ADC_DR_GPIO_Port,ADC_DR_Pin) == GPIO_PIN_RESET)
    {
        ReadFrame();
    }
}
