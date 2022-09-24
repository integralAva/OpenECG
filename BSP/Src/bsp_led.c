#include "bsp_led.h"
#include "tim.h"

//template
const LED_ColorType LED_Left_Red[4] = {LED_Color_Red,LED_Color_Red,LED_Color_None,LED_Color_None};
const LED_ColorType LED_Right_Red[4] = {LED_Color_None,LED_Color_None,LED_Color_Red,LED_Color_Red};
const LED_ColorType LED_Full_Red[4] = {LED_Color_Red,LED_Color_Red,LED_Color_Red,LED_Color_Red};
const LED_ColorType LED_Full_Green[4] = {LED_Color_Green,LED_Color_Green,LED_Color_Green,LED_Color_Green};
const LED_ColorType LED_Full_Blue[4] = {LED_Color_Blue,LED_Color_Blue,LED_Color_Blue,LED_Color_Blue};
const LED_ColorType LED_Full_Yellow[4] = {LED_Color_Yellow,LED_Color_Yellow,LED_Color_Yellow,LED_Color_Yellow};

//memorize led state
static LED_ColorType LED_State[4] = {LED_Color_Red,LED_Color_Red,LED_Color_Red,LED_Color_Red};



static void LED_Clear_Point(void)
{
    /*
    LL_GPIO_ResetOutputPin(L1_GPIO_Port,L1_Pin);
    LL_GPIO_ResetOutputPin(L2_GPIO_Port,L2_Pin);
    LL_GPIO_ResetOutputPin(L3_GPIO_Port,L3_Pin);
    LL_GPIO_ResetOutputPin(L4_GPIO_Port,L4_Pin);
    */
    L1_GPIO_Port->BSRR = (L1_Pin | L2_Pin | L3_Pin | L4_Pin) << 16;
}

static void LED_Clear_Color(void)
{
    /*
    LL_GPIO_SetOutputPin(LR_GPIO_Port,LR_Pin);
    LL_GPIO_SetOutputPin(LG_GPIO_Port,LG_Pin);
    LL_GPIO_SetOutputPin(LB_GPIO_Port,LB_Pin);
    */
    LR_GPIO_Port->BSRR = (LR_Pin | LG_Pin | LB_Pin);
}


static void LED_Select(uint8_t Point)
{
    LED_Clear_Point();
    switch(Point)
    {
        case 0:
            LL_GPIO_SetOutputPin(L1_GPIO_Port,L1_Pin);
            break;
        case 1:
            LL_GPIO_SetOutputPin(L2_GPIO_Port,L2_Pin);
            break;
        case 2:
            LL_GPIO_SetOutputPin(L3_GPIO_Port,L3_Pin);
            break;
        case 3:
            LL_GPIO_SetOutputPin(L4_GPIO_Port,L4_Pin);
            break;
        default:
            break;
    }
}

static void LED_Color(LED_ColorType Color)
{
    LED_Clear_Color();
    switch(Color)
    {
        case LED_Color_Red:
            LL_GPIO_ResetOutputPin(LR_GPIO_Port,LR_Pin);
            break;
        case LED_Color_Blue:
            LL_GPIO_ResetOutputPin(LB_GPIO_Port,LB_Pin);
            break;
        case LED_Color_Green:
            LL_GPIO_ResetOutputPin(LG_GPIO_Port,LG_Pin);
            break;
        case LED_Color_Yellow:
            LL_GPIO_ResetOutputPin(LR_GPIO_Port,LR_Pin);
            LL_GPIO_ResetOutputPin(LG_GPIO_Port,LG_Pin);
            break;
        default:
            break;
    }
}

static void LED_Control(uint8_t Point,LED_ColorType Color)
{
    LED_Select(Point);
    LED_Color(Color);
}

void LED_SetBit(uint8_t Point,LED_ColorType Color)
{
    LED_State[Point] = Color;
}

void LED_SetGroup(const LED_ColorType* Tag)
{
    LED_Clear_All();
    for(int i = 0;i < 4;i++)
    {
        LED_State[i] = *Tag;
        Tag++;
    }
}

void LED_Clear_All(void)
{
    LED_State[0] = LED_Color_None;
    LED_State[1] = LED_Color_None;
    LED_State[2] = LED_Color_None;
    LED_State[3] = LED_Color_None;
}

void LED_Toggle(uint8_t point,LED_ColorType Color)
{
    if(LED_State[point] == LED_Color_None)
    {
        LED_State[point] = Color;
    }else
    {
        LED_State[point] = LED_Color_None;
    }
}

void BSP_LED_Init()
{
    LED_Clear_Color();
    LED_Clear_Point();
    LED_Clear_All();
    //Start TIM6
}


static uint8_t LED_Point_Count = 0;
void LED_Tick(void)
{
    LED_Control(LED_Point_Count,LED_State[LED_Point_Count]);
    LED_Point_Count = (LED_Point_Count >= 3) ? 0 : (LED_Point_Count + 1);
}
