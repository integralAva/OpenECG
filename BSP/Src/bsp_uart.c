#include "bsp_uart.h"

#include "usbd_cdc_if.h"


struct __FILE 
{ 
	int handle; 
}; 
  FILE __stdout;     
int fputc(int ch, FILE *f)
{ 	
	while((USART1->ISR&0X40)==0);
	USART1->TDR=(uint8_t)ch;
	return ch;
}

void BSP_USB_Transmit(uint8_t * Data,uint16_t len)
{
    CDC_Transmit_HS(Data,len);
}

#include <stdarg.h>
static uint8_t UserTxBufferHS[APP_TX_DATA_SIZE];
void usb_printf(const char *format, ...)
{
    va_list args;
    uint32_t length;
 
 
    va_start(args, format);
    length = vsnprintf((char *)UserTxBufferHS, APP_TX_DATA_SIZE, (char *)format, args);
    va_end(args);
    CDC_Transmit_HS(UserTxBufferHS, length);
}

