/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 04/09/2017.
 *	Version	: 1.0.1.
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "keypad.h"


/******************************************************************************
 *	Public
 *****************************************************************************/
/* Available interrupt */
bool        flgBtnInt;
t_KpBtn     readBtn;
 
 
/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
bool kpSetup()
{
    /* Input */
    gpioInputSetup(KP_PORT, KP_PIN_IN, GPIO_IN_PULL_UP);

    /* Output */
    gpioOutputSetup(KP_PORT, KP_PIN_OUT);

    /* Interrupt */
    gpioIntSetup(KP_PORT, KP_PIN_IN, GPIO_IN_DETECT_FALL, GPIO_PK_Handler);

    /* Notify */
    icdiSendStr(">>> [Keypad] module is enabled.\n");

    /* Return */
    return false;
}
//-----------------------------------------------------------------------------
/*
 *	Input		:	None
 *	Output		:	None
 *	Description	:	Sweep keypad
 */
void	kpSweep(void)
{
	/* Declare */
	static	uint8_t	i = 255;
	
	/* Update state */
	i++;
	if(i == 4)	i = 0;
	
	/* Sweep */
	switch(i)
	{
		case 0:
			gpioHigh(KP_PORT, KP_PIN_OUT_3);
			gpioLow(KP_PORT, KP_PIN_OUT_0);
			break;
		case 1:
			gpioHigh(KP_PORT, KP_PIN_OUT_0);
			gpioLow(KP_PORT, KP_PIN_OUT_1);
			break;
		case 2:
			gpioHigh(KP_PORT, KP_PIN_OUT_1);
			gpioLow(KP_PORT, KP_PIN_OUT_2);
			break;
		case 3:
			gpioHigh(KP_PORT, KP_PIN_OUT_2);
			gpioLow(KP_PORT, KP_PIN_OUT_3);
			break;
	}
}//-----------------------------------------------------------------------------
/*
 *	Input		:	None
 *	Output		:	Pressed button
 *	Description	:	Read which button is pressed
 */
#define	IN(x)		KP_PIN_IN_##x	// Get name of Input pin
#define	OUT(x)		KP_PIN_OUT_##x	// Get name of Output pin

t_KpBtn	kpReadBtnFromISR(void)
{
	/* Read */
	uint8_t ui8Btn = gpioRead(KP_PORT, KP_PIN);
	ui8Btn = (~ui8Btn & KP_PIN_IN) | (~ui8Btn & KP_PIN_OUT);
	
	/* Process */
	switch(ui8Btn & KP_PIN_IN)
	{
	case IN(3):
		switch(ui8Btn & KP_PIN_OUT)
		{
			case OUT(3)	:	return BTN(1);
			case OUT(2)	:	return BTN(2);
			case OUT(1)	:	return BTN(3);
			case OUT(0)	:	return BTN(A);
			default		:	return BTN(None);
		}
	case IN(2):
		switch(ui8Btn & KP_PIN_OUT)
		{
			case OUT(3)	:	return BTN(4);
			case OUT(2)	:	return BTN(5);
			case OUT(1)	:	return BTN(6);
			case OUT(0)	:	return BTN(B);
			default		:	return BTN(None);
		}
	case IN(1):
		switch(ui8Btn & KP_PIN_OUT)
		{
			case OUT(3)	:	return BTN(7);
			case OUT(2)	:	return BTN(8);
			case OUT(1)	:	return BTN(9);
			case OUT(0)	:	return BTN(C);
			default		:	return BTN(None);
		}
	case IN(0):
		switch(ui8Btn & KP_PIN_OUT)
		{
			case OUT(3)	:	return BTN(Clr);
			case OUT(2)	:	return BTN(0);
			case OUT(1)	:	return BTN(Cfm);
			case OUT(0)	:	return BTN(D);
			default		:	return BTN(None);
		}
	default				:	return BTN(None);
	}
}
//-----------------------------------------------------------------------------
/*
 *	Input		:	None
 *	Output		:	None
 *	Description	:	Interrupt of Keypad (GPIO portK)
 */
void GPIO_PK_Handler(void)
{
	/* Read button */
    readBtn = kpReadBtnFromISR();
	
	/* Exit ISR */
	gpioIntExit(KP_PORT, KP_PIN);
}
//-----------------------------------------------------------------------------
/*
 *	Input		:
 *	Output		:
 *	Description	:
 */

