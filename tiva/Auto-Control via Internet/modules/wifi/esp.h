/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 30/10/2016.
 *	Version	: 1.0.1.
 */
/**************************************************************************************************
 *	PRE-DEFINITIONs
 *************************************************************************************************/
#ifndef ESP_H_
#define ESP_H_


/**************************************************************************************************
 *	INCLUDEs
 *************************************************************************************************/
/* Standard Library */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* Driver */
#include <GPIO.1.0.1.h>
#include <UART.1.0.1.h>
#include <CLK.1.0.1.h>


/**************************************************************************************************
 *	DEFINITIONs
 *************************************************************************************************/
/* GPIO PORT */
#define	ESP_PORT_1							(&P1OUT)
#define	ESP_PORT_2							(&P2OUT)

/* AT commands */
#define	ESP_AT_CHECK_MODULE					"AT\r\n"
#define	ESP_AT_RESET						"AT+RST\r\n"
#define	ESP_AT_CHECK_FIRMWARE				"AT+GMR\r\n"

#define	ESP_AT_CONNECT_WIFI					"AT+CWJAP="
#define	ESP_AT_DISCONNECT_WIFI				"AT+CWQAP\r\n"
#define	ESP_AT_GET_IP						"AT+CIFSR\r\n"

#define	ESP_AT_SET_TCP_SINGLE				"AT+CIPMUX=0\r\n"
#define	ESP_AT_SET_TCP_MULTI				"AT+CIPMUX=1\r\n"
#define	ESP_AT_MAKE_SERVER					"AT+CIPSERVER=1,"
#define	ESP_AT_CONNECT_TCP					"AT+CIPSTART="
#define	ESP_AT_DISCONNECT_TCP				"AT+CIPCLOSE\r\n"

#define	ESP_AT_CHECK_STATUS					"AT+CIPSTATUS\r\n"


/**************************************************************************************************
 *	PUBLICs
 *************************************************************************************************/


/**************************************************************************************************
 *	FUNCTIONs
 *************************************************************************************************/
/* Setup */
void
espSetup
(uint32_t ESP_MODULE_, uint32_t ESP_PORT_, uint32_t ESP_PIN_RST_, uint32_t ESP_PIN_EN_);

/* Control */
bool
espCheckModule		(void);
void
espResetHardware	(void);
bool
espResetSofware		(void);
bool
espCheckFirmware	(void);

/* WiFi */
bool
espConnectWifi		(char strSSID[], char strPassword[]);
bool
espDisconnectWifi	(void);
bool
espGetIP			(void);

/* TCP */
bool
espConnectTCP		(char strIPAddr[], uint16_t varPort);
bool
espDisconnectTCP	(void);
bool
espMakeServer		(uint16_t varPort);
bool
espSingleConnection	(void);
bool
espMultiConnection	(void);

/* Status */
void
espCheckStatus		(void);


#endif /* ESP_H_ */
