#ifndef __BSP_IN_H_
#define __BSP_IN_H_

#include "System.h"

extern uint16_t frq;
extern uint16_t time;

typedef enum{
    BSP_INIT_ECA,
    BSP_INIT_ECS,
    BSP_INIT_KFA,
    BSP_INIT_KFB
}BSP_Input_Interrupt;

void BSP_EC_IT(BSP_Input_Interrupt line);


#endif

