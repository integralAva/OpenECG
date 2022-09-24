#ifndef __BSP_LED_H_
#define __BSP_LED_H_

#include "System.h"

typedef enum{
    LED_Color_Red,
    LED_Color_Blue,
    LED_Color_Green,
    LED_Color_Yellow,
    LED_Color_None
}LED_ColorType;


/*
 Display Template
*/
extern const LED_ColorType LED_Left_Red[4];
extern const LED_ColorType LED_Right_Red[4];
extern const LED_ColorType LED_Full_Red[4];
extern const LED_ColorType LED_Full_Green[4];
extern const LED_ColorType LED_Full_Blue[4];
extern const LED_ColorType LED_Full_Yellow[4];

void LED_Tick(void);
void LED_SetBit(uint8_t Point,LED_ColorType Color);
void LED_Clear_All(void);
void LED_SetGroup(const LED_ColorType * Tag);
void LED_Toggle(uint8_t point,LED_ColorType Color);
void BSP_LED_Init(void);

#endif
