#include "DataCenter.h"

#include "ADAS1000.h"
#include "EEPROM.h"
#include "bsp_uart.h"
#include "Filter.h"
#include "bsp_beep.h"

//Data had processed
ECG_DataStruct ECG_Data;

static void ECG_CalcBMP_I(void);
static void ECG_CalcBMP_II(void);
static void ECG_CalcBMP_III(void);

//function pointer of BMP_Calc
void (*ECG_BMP_Calc)(void) = &ECG_CalcBMP_III;

//calculate vector lead
static int32_t comput_aVR(int32_t I,int32_t II)
{
    int32_t output = (-0.5*(I+II));
    return output;
}

static int32_t comput_aVL(int32_t I,int32_t III)
{
    int32_t output = (0.5*(I-III));
    return output;
}

static int32_t comput_aVF(int32_t II,int32_t III)
{
    int32_t output = (0.5*(II+III));
    return output;
}


void DataCenter_Run(void)
{
    //call this function every 1/1000 second
    Filter_Run();
    ECG_Data.Lead_aVR = comput_aVR(ECG_Data.Lead_I,ECG_Data.Lead_II);
    ECG_Data.Lead_aVL = comput_aVL(ECG_Data.Lead_I,ECG_Data.Lead_III);
    ECG_Data.Lead_aVF = comput_aVF(ECG_Data.Lead_II,ECG_Data.Lead_III);
    
}


static uint32_t BMP_Time = 0;
static uint32_t RR_Time = 0;
static int32_t data[2];
static int32_t r_data[2];
uint8_t ECG_BMP;
uint8_t RESP_RATE;

void SYS_Basic_Count(void)
{
    BMP_Time++;
    RR_Time++;
}

void RR_Calc(void)
{
    if(RR_Time > 20000)
    {
        RESP_RATE = 0;
        RR_Time = 0;
    }
    else if(RR_Time > 2000)
    {
        r_data[1] = ECG_Data.Resp;
        int32_t val = r_data[1] - r_data[0];
        if(val > 500 && val < 1500)
        {
            RESP_RATE = 60000/RR_Time;
            RR_Time = 0;
        }
        r_data[0] = r_data[1];
    }
}


void ECG_CalcBMP_function(ECG_BMP_CH ch)
{
    switch(ch)
    {
        case bmp_LEAD_I:
            ECG_BMP_Calc = &ECG_CalcBMP_I;
            break;
        case bmp_LEAD_II:
            ECG_BMP_Calc = &ECG_CalcBMP_II;
            break;
        case bmp_LEAD_III:
            ECG_BMP_Calc = &ECG_CalcBMP_III;
            break;
    }
}

static void ECG_CalcBMP_I(void)
{
    if(BMP_Time > 5000)
    {
        ECG_BMP = 0;
        BMP_Time = 0;
    }
    else if(BMP_Time > 100)
    {
        data[1] = ECG_Data.Lead_I;
        int32_t val = data[1] - data[0];
        if(val < -800 && val > -1600)
        {
            ECG_BMP = 60000/BMP_Time;
            BSP_BEEP_Run(320+2*ECG_BMP,50);
            BMP_Time = 0;
        }
        data[0] = data[1];
    }
}

static void ECG_CalcBMP_II(void)
{
    if(BMP_Time > 5000)
    {
        ECG_BMP = 0;
        BMP_Time = 0;
    }
    else if(BMP_Time > 100)
    {
        data[1] = ECG_Data.Lead_II;
        int32_t val = data[1] - data[0];
        if(val > 800 && val < 1600)
        {
            ECG_BMP = 60000/BMP_Time;
            BSP_BEEP_Run(320+2*ECG_BMP,50);
            BMP_Time = 0;
        }
        data[0] = data[1];
    }
}

static void ECG_CalcBMP_III(void)
{
    if(BMP_Time > 5000)
    {
        ECG_BMP = 0;
        BMP_Time = 0;
    }
    else if(BMP_Time > 100)
    {
        data[1] = ECG_Data.Lead_III;
        int32_t val = data[1] - data[0];
        if(val > 1000 && val < 2000)
        {
            ECG_BMP = 60000/BMP_Time;
            BSP_BEEP_Run(320+2*ECG_BMP,50);
            BMP_Time = 0;
        }
        data[0] = data[1];
    }
}



