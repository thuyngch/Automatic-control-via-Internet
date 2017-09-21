/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 14/09/2017.
 *	Version	: 1.0.1.
 */
#ifndef	LCD_H_
#define	LCD_H_
/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include <GPIO.1.0.1.h>
#include <UART.1.0.1.h>

#include"../pin_def.h"


/******************************************************************************
 *	Definition
 *****************************************************************************/


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *  Setup module [LCD].
 */
bool lcdSetup();

/*
 *
 */
void lcdClearScreen();

/*
 *
 */
void lcdChangeLine(uint8_t line_th);

/*
 *
 */
void lcdDisplay(char *str);

/*
 *
 */
void lcdAddChar(char ch);

/*
 *
 */
void lcdAddStr(char str[], uint8_t len);

/*
 *
 */
void lcdBackspace();


#endif	/* LCD_H_ */

