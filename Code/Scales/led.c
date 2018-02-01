/*
 * led.c
 *
 * Created: 26-9-2015 18:22:40
 *  Author: Thom
 */ 

#include "led.h"

void led_init(void){
	/* set pin 5 of PORTB for output*/
	DDRB |= _BV(DDB5);
}

void powerled(void){
	PORTB |= _BV(PORTB5);	
}