#ifndef __APP_ADAS1000_H_
#define __APP_ADAS1000_H_

#include "System.h"

typedef struct
{
    int32_t Lead_I;
    int32_t Lead_II;
    int32_t Lead_III;
    int32_t Lead_V;
    int32_t Resp;
    uint32_t LOFF;
    uint32_t State;
}ADAS1000_DataStruct;

extern ADAS1000_DataStruct ADAS1000_Data;

typedef enum
{
    ADAS1000_PowerDown,
    ADAS1000_PowerOn
}ADAS1000_PWR;


void ADAS1000_IT(void);
void ADAS1000_PowerMode(ADAS1000_PWR mode);
void ADAS1000_Init(void);

#endif

