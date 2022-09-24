#include "bsp_beep.h"

#include "tim.h"

static uint8_t task = 0;
static uint16_t now_time,end;

static void Set_Beep(uint8_t state)
{
    if(state)
    {
        HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
    }else
    {
        HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1);
    }
}

static void Set_Frequency(uint16_t frq)
{
    uint16_t reload;
    reload = 1000000 / frq;
    __HAL_TIM_SetAutoreload(&htim2,reload);
}

/* 0 - 137 */
void BSP_BEEP_Set_Volume(uint16_t vol)
{
    __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,vol);
}

void BSP_BEEP_Tick(void)
{
    if(task)
    {
        now_time++;
        if(now_time >= end)
        {
            task = 0;
            Set_Beep(0);
        }
    }
}

void BSP_BEEP_Run(uint16_t frq,uint16_t time)
{
    Set_Frequency(frq);
    end = time;
    Set_Beep(1);
    now_time = 0;
    task = 1;
}

void BSP_BEEP_Init()
{
    BSP_BEEP_Set_Volume(137);
    Set_Frequency(440);
    //Turn On TIM6
}
