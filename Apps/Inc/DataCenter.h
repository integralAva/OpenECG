#ifndef __APP_DC_H_
#define __APP_DC_H_

#include "System.h"

typedef struct
{
    int32_t Lead_I;
    int32_t Lead_II;
    int32_t Lead_III;
    int32_t Lead_V;

    int32_t Resp;

    int32_t Lead_aVR;
    int32_t Lead_aVL;
    int32_t Lead_aVF;
}ECG_DataStruct;

typedef enum{
    bmp_LEAD_I,
    bmp_LEAD_II,
    bmp_LEAD_III
}ECG_BMP_CH;

extern ECG_DataStruct ECG_Data;


void DataCenter_Run(void);
void SYS_Basic_Count(void);
void RR_Calc(void);
//void ECG_CalcBMP_function(ECG_BMP_CH ch);


#endif

