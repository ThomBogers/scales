/*
 * esp8266.h
 *
 * Created: 26-9-2015 20:40:27
 *  Author: Thom
 */ 


#ifndef ESP8266_H_
#define ESP8266_H_

#include <string.h>
#include "common.h"
#include "uart.h"

#define SSID "ToegangTotHetInternet"
#define PASS "T4nd3nf33"

//Commands
static const char cmd_reset[] = "AT+RST\r\n";

static const char cmd_wifi_mode[]    = "AT+CWMODE=1\r\n";
static const char cmd_wifi_mux[]     = "AT+CIPMUX=1\r\n";
static const char cmd_wifi_connect[] = "AT+CWJAP=\"%s\",\"%s\"\r\n";


//const char cmd_client_connect[] = "AT+CIPSTART=4,\"_TCP_\",\"_IP_\"_PORT_";

static const char cmd_client_connect[]    = "AT+CIPSTART=4,\"%s\",\"%s\",%d\r\n";
static const char cmd_client_disconnect[] = "AT+CIPCLOSE\r\n";
//static const char cmd_client_mode[]       = "AT+CIPMOD=\"%d\"\r\n";

static const char cmd_message_len[]     = "AT+CIPSEND=%d\r\n";
static const char cmd_message_content[] = "%c%s%c\r\n";

static const char message_start = 255;
static const char message_end   = 254;

void esp_reset(void);
void esp_init(void);

//Connect to a server, type can be TCP or UDP
void esp_connect(char* type, char* ip, int port);
void esp_disconnect(void);

//Data transmission mode, normal mode or "unvarnished transmission mode"
void esp_mode(int mode);
void esp_send(char* message);



#endif /* ESP8266_H_ */