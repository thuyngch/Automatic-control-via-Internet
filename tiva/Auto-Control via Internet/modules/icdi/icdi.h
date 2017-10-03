/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 08/09/2017.
 *	Version	: 1.0.1.
 */

#ifndef	ICDI_H_
#define	ICDI_H_

/******************************************************************************
 *	Include
 *****************************************************************************/
/* Standard */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* Driver */
#include "../../lib/UART.1.0.1.h"

/* Project */
#include "../pin_def.h"
#include "../wifi/wifi.h"


/******************************************************************************
 *	Definition
 *****************************************************************************/
extern bool flgICDI;
extern char buff[256];


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *  Setup ICDI module.
 */
bool icdiSetup();


/*
 *  Send a character through UART0
 */
void icdiSendChar(char ch);


/*
 *  Send a string through UART0
 */
void icdiSendStr(char *str);


/*
 *  Send an array specified by its length through UART0
 */
void icdiSendArr(uint8_t arr[], uint16_t len);


/*
 *  UART0 interrupt
 */
void UART0_Handler();


#endif	/* ICDI_H_ */

