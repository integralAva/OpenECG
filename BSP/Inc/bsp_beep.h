#ifndef __BSP_BEEP_H_
#define __BSP_BEEP_H_

#include "System.h"

void BSP_BEEP_Tick(void);
void BSP_BEEP_Set_Volume(uint16_t vol);
void BSP_BEEP_Run(uint16_t frq,uint16_t time);
void BSP_BEEP_Init(void);

#endif

