#ifndef __SYS_H_
#define __SYS_H_

#include "main.h"
#include "cmsis_os.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//没有什么实际作用的枚举
typedef enum
{
    ERR_InitFault,
    ERR_DWR,
    ERR_DEVICE_STOP
}ERR_CODE;


typedef struct
{
    /* Is charging */
    uint8_t PWR_State;
    //计算后的电量，0-100
    uint8_t PWR_BAT;
    //故障代码
    uint8_t Error_Code;
    //计算后电压
    float battery_vot;
    float core_temp;
    float battery_cc;
    //CPU占用率
    uint8_t CPU_usage;
}Sysinfo;

extern Sysinfo SystemState;
extern uint8_t ECG_BMP;
extern uint8_t RESP_RATE;

extern osThreadId GUI_Task_ID;

void Program_Boot(void);
void SYS_SOFT_RESET(void);

#endif
