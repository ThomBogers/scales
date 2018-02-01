/*
 * Scales.c
 *
 * Created: 17-9-2015 23:02:57
 *  Author: Thom Bogers
 */
#include "common.h"
#include "esp8266.h"
#include "led.h"

int main(void){
	_delay_ms(3000);
	
	esp_reset();
	esp_init();
	esp_connect("TCP", "192.168.1.99", 6666);
	
	while(1){
		esp_send("{\"test\":1}");
		_delay_ms(5000);
	}
	
	return 0;
}
