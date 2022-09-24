#ifndef __BSP_USB_H_
#define __BSP_USB_H_

#include "System.h"

void BSP_USB_Transmit(uint8_t * Data,uint16_t len);
void usb_printf(const char *format, ...);

#endif

