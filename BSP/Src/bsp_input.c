#include "bsp_input.h"

extern void GUI_Touch_update(int x, int y,uint8_t state);
extern void GUI_KEY_update(unsigned int key);


void BSP_EC_IT(BSP_Input_Interrupt line)
{
    if(line == BSP_INIT_ECA)
    {
        if(LL_GPIO_IsInputPinSet(ECB_GPIO_Port,ECB_Pin) == GPIO_PIN_SET)
        {
            //left
            GUI_KEY_update(0);
        }else
        {
            //right
            GUI_KEY_update(1);
        }
    }else if(line == BSP_INIT_ECS)
    {
        GUI_KEY_update(2);
    }else if(line == BSP_INIT_KFA)
    {
        if(LL_GPIO_IsInputPinSet(KFA_GPIO_Port,KFA_Pin) == GPIO_PIN_RESET)
        {
            
        }
    }else if(line == BSP_INIT_KFB)
    {
        if(LL_GPIO_IsInputPinSet(KFB_GPIO_Port,KFB_Pin) == GPIO_PIN_RESET)
        {
            
        }
    }
}

