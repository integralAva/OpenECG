#ifndef __BSP_LCD_H_
#define __BSP_LCD_H_

#include "System.h"

void BSP_LCD_SetLight(uint16_t light);
void BSP_LCD_Init(void);
void BSP_LCD_DrawPixel(uint16_t x,uint16_t y,uint16_t color);
uint16_t BSP_LCD_GetPixel(uint16_t x,uint16_t y);
void BSP_LCD_Fill(uint16_t x,uint16_t y,uint16_t xend,uint16_t yend,uint16_t Color);

#define White          0xFFFF
#define Black          0x0000
#define Blue           0x001F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

#endif

