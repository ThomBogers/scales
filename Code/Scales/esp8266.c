/*
 * esp8266.c
 *
 * Created: 26-9-2015 20:40:43
 *  Author: Thom
 */ 

#include "esp8266.h"

void esp_reset(void){
	USART_putstring(cmd_reset);
}

void esp_init(void){
	USART_init(BAUD_115200);
	
	//Set esp to client mode (not ap mode)
	USART_putstring(cmd_wifi_mode);
	
	USART_putstring(cmd_wifi_mux);
	
	char command[64];
	sprintf(command, cmd_wifi_connect, SSID, PASS);
	USART_putstring(command);	
}

void esp_connect(char* type, char* ip, int port){
	char command[64];
	sprintf(command, cmd_client_connect, type, ip, port);
	USART_putstring(command);
}

void esp_disconnect(void){
	USART_putstring(cmd_client_disconnect);
}
/*
void esp_mode(int mode){
	char command[64];
	sprintf(command, cmd_client_mode ,mode);
	USART_putstring(command);
}
*/

void esp_send(char* message){
	char command[64];
	sprintf(command, cmd_message_len , strlen(message) + 4);
	USART_putstring(command);
	
	sprintf(command, cmd_message_content , message_start, message, message_end);
	
	USART_putstring(command);	
}