/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 08/09/2017.
 *	Version	: 1.0.1.
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "icdi.h"


/******************************************************************************
 *	Public
 *****************************************************************************/
bool flgICDI;
char buff[256];


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *  Function:   Setup ICDI module.
 *
 *  Input   :   (void)
 *
 *  Output  :   (bool) False if there is no error, True if not.
 */
bool icdiSetup()
{
    /* Setup UART */
    uartSetup(ui32ClkFreq, ICDI_MODULE, 115200, UART_INT_RT | UART_INT_RX);

    /* Notify */
    icdiSendStr("\r\n>>> [ICDI] module is enabled.\r\n");

    /* Return */
    return false;
}
//-----------------------------------------------------------------------------
/*
 *  Function:   Send a character to Terminal through UART_ICDI.
 *
 *  Input   :   ch: The character that will be sent.
 *
 *  Output  :   (void).
 */
void icdiSendChar(char ch)
{
    uartSendChar(ICDI_MODULE, ch);
}
//-----------------------------------------------------------------------------
/*
 *  Function:   Send a string to Terminal through UART_ICDI.
 *
 *  Input   :   str: The string that will be sent.
 *
 *  Output  :   (void)
 */
void icdiSendStr(char *str)
{
    uartSendStr(ICDI_MODULE, str);
}
//-----------------------------------------------------------------------------
/*
 *  Function:   Send an array to Terminal through UART_ICDI.
 *
 *  Input   :   arr: The array that will be sent.
 *              len: Lenght of the array.
 *
 *  Output  :   (void)
 */
void icdiSendArr(uint8_t arr[], uint16_t len)
{
    uartSendArr(ICDI_MODULE, arr, len);
}
//-----------------------------------------------------------------------------
/*
 *  Function:   UART_ICDI interrupt service routine.
 *
 *  Input   :   (void)
 *
 *  Output  :   (void)
 */
void UART0_Handler()
{
    /* Clear interrupt */
    UARTIntClear(ICDI_MODULE, UART_INT_RX | UART_INT_RT);

    /* Read received data */
    uint8_t ch = uartGetChar(ICDI_MODULE);

    /* Redirect data to ESP8266 */
    uartSendChar(WIFI_MODULE, ch);
}


