/*
 * uart.h
 *
 * Created: 24-9-2015 15:15:48
 *  Author: Thom
 */ 
#ifndef INCUART_H_
#define INCUART_H_

#include "common.h"


/*Define dividers for baud rates, based on:
	- http://www.digi.com/support/forum/4787/using-the-xbee-at-115-200-baud-updated-16-march-2010
	- http://wormfood.net/avrbaudcalc.php?postbitrate=115200&postclock=16&u2xmode=1&hidetables=1
*/
typedef enum {
	BAUD_9600 = 207,
	BAUD_19200 = 103,
	BAUD_38400 = 51,
	BAUD_57600 = 34,
	BAUD_115200 = 16,
	BAUD_250000 = 7,
} baud_t;

//Declaration of our functions
void USART_init(baud_t prescaler);

void set_baud_9600(void);
void set_baud_115200(void);

unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_putstring(const char* StringPtr);

#endif /* INCUART_H_ */