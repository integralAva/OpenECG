#include "InterruptCenter.h"

#include "tim.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "ADAS1000.h"
#include "DataCenter.h"
#include "filter.h"

extern void (*ECG_BMP_Calc)(void);

/* TIM IT */
void TimerCountout(TIM_HandleTypeDef *htim)
{
    if(htim == &htim13)
    {
        //This Timer is used to check the DRDY pin
        ADAS1000_IT();
    }else if(htim == &htim7)
    {
        //TIM7 is used to calculate Basicline
        Filter_Basicline();
    }else if(htim == &htim6)
    {
        //1ms
        LED_Tick();
        BSP_BEEP_Tick();
        SYS_Basic_Count();
    }else if(htim == &htim14)
    {
        (*ECG_BMP_Calc)();
    }
}

