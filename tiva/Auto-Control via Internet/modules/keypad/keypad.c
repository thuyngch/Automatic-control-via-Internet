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
 *  Private
 *****************************************************************************/
/*
 *  Function:   Read which button is pressed
 *
 *  Input   :   (void)
 *
 *  Output  :   Pressed button
 */
#define IN(x)       (KP_PIN_IN_##x)     // Get name of Input pin
#define OUT(x)      (KP_PIN_OUT_##x)    // Get name of Output pin

static t_KpBtn kpReadBtnFromISR()
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
            case OUT(3) :   return BTN(1);
            case OUT(2) :   return BTN(2);
            case OUT(1) :   return BTN(3);
            case OUT(0) :   return BTN(A);
            default     :   return BTN(None);
        }
    case IN(2):
        switch(ui8Btn & KP_PIN_OUT)
        {
            case OUT(3) :   return BTN(4);
            case OUT(2) :   return BTN(5);
            case OUT(1) :   return BTN(6);
            case OUT(0) :   return BTN(B);
            default     :   return BTN(None);
        }
    case IN(1):
        switch(ui8Btn & KP_PIN_OUT)
        {
            case OUT(3) :   return BTN(7);
            case OUT(2) :   return BTN(8);
            case OUT(1) :   return BTN(9);
            case OUT(0) :   return BTN(C);
            default     :   return BTN(None);
        }
    case IN(0):
        switch(ui8Btn & KP_PIN_OUT)
        {
            case OUT(3) :   return BTN(Clr);
            case OUT(2) :   return BTN(0);
            case OUT(1) :   return BTN(Cfm);
            case OUT(0) :   return BTN(D);
            default     :   return BTN(None);
        }
    default             :   return BTN(None);
    }
}


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *  Function:   Setup Keypad module
 *
 *  Input   :   (void)
 *
 *  Output  :   (bool) False if there is nothing error, True if not.
 */
bool kpSetup()
{
    /* Output */
    gpioOutputSetup(KP_PORT, KP_PIN_OUT);

    /* Input */
    gpioInputSetup(KP_PORT, KP_PIN_IN, GPIO_IN_PULL_UP);

    /* Interrupt */
    gpioIntSetup(KP_PORT, KP_PIN_IN, GPIO_IN_DETECT_FALL, GPIO_PK_Handler);

    /* Notify */
    uartSendStr(UART_ICDI, "\r\n>>> [Keypad] module is enabled.\r\n");

    /* Return */
    return false;
}
//-----------------------------------------------------------------------------
/*
 *  Function: Sweep the keypad.
 *
 *  Input   : (void)
 *
 *  Output  : (void)
 */
void kpSweep()
{
	/* Declare */
	static uint8_t	i = 255;
	
	/* Sweep */
	switch(++i % 4)
	{
		case 0:
			gpioHigh(KP_PORT, KP_PIN_OUT_3);
			gpioLow(KP_PORT, KP_PIN_OUT_0);
            clkDelayMs(KEYPAD_SWEEP_CYCLE);
			break;
		case 1:
			gpioHigh(KP_PORT, KP_PIN_OUT_0);
			gpioLow(KP_PORT, KP_PIN_OUT_1);
            clkDelayMs(KEYPAD_SWEEP_CYCLE);
			break;
		case 2:
			gpioHigh(KP_PORT, KP_PIN_OUT_1);
			gpioLow(KP_PORT, KP_PIN_OUT_2);
            clkDelayMs(KEYPAD_SWEEP_CYCLE);
			break;
		case 3:
			gpioHigh(KP_PORT, KP_PIN_OUT_2);
			gpioLow(KP_PORT, KP_PIN_OUT_3);
            clkDelayMs(KEYPAD_SWEEP_CYCLE);
			break;
	}
}
//-----------------------------------------------------------------------------
/*
 *	Input		:	None
 *	Output		:	None
 *	Description	:	Interrupt of Keypad (GPIO portK)
 */
void GPIO_PK_Handler()
{
    /* Anti-noise delay */
    clkDelayMs(KEYPAD_ANTI_NOISE);

	/* Read button */
    readBtn = kpReadBtnFromISR();
	
	/* Exit ISR */
	gpioIntExit(KP_PORT, KP_PIN);
}

