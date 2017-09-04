/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 04/09/2017.
 *	Version	: 1.0.1.
 */
#ifndef	WIFI_H_
#define	WIFI_H_
/******************************************************************************
 *	Include
 *****************************************************************************/
/* Standard */
#include <stdint.h>
#include <stdbool.h>

/* Driver */
#include <GPIO.1.0.1.h>
#include <UART.1.0.1.h>
#include <TIMER.1.0.1.h>

/* Project */
#include "../pin_def.h"
#include "esp.h"


/******************************************************************************
 *	Definition
 *****************************************************************************/


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *  Setup [WiFi] module.
 */
bool
wifiSetup
();


/******************************************************************************
 *  Private
 *****************************************************************************/
static void espSetupProtocol();
static bool wifiCheckATCmdComplete(char* strCheck);
static void wifiStartTimerCount(uint32_t timeout);
static void wifiStopTimerCount(void);
static void wifiClearBuffer(uint8_t buff[], uint8_t len);


#endif	/* WIFI_H_ */
