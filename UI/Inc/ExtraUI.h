#ifndef __EXT_UI_H_
#define __EXT_UI_H_

#include "System.h"

void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode,uint32_t POINT_COLOR);
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint32_t POINT_COLOR);
void LCD_ShowxNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode,uint32_t POINT_COLOR);
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,char *p,uint32_t POINT_COLOR);

#endif

