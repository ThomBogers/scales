/*
 * uart.c
 *
 * Created: 24-9-2015 15:15:23
 *  Author: Thom
 */

#include "uart.h"

void USART_init(baud_t prescaler){
	
	//Set baudrate register high and low
	UBRR0H = (uint8_t)( prescaler >> 8 );
	UBRR0L = (uint8_t)( prescaler );
	
	/*Enable receiver and transmitter*/
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	/*Use double speed mode*/
	UCSR0A |= (1 << U2X0);
	
	/* Set frame format, asynchronous, 8bit data*/
	UCSR0C = (1<<UMSEL01)|(3<<UCSZ00);
	
}


unsigned char USART_receive(void){
	
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
	
}

void USART_send( unsigned char data){
	
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
	
}

void USART_putstring(const char* StringPtr){
	_delay_ms(2000);
	
	while(*StringPtr != '\0'){
		USART_send(*StringPtr);
	StringPtr++;}
	
}