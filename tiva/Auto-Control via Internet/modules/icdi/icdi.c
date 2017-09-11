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
 *	Private
 *****************************************************************************/
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */

//-----------------------------------------------------------------------------


/******************************************************************************
 *	Public
 *****************************************************************************/
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
bool icdiSetup()
{
    /* Setup UART */
    uartSetup(ui32ClkFreq, ICDI_MODULE, 115200, UART_INT_RT | UART_INT_RX);

    /* Notify */
    icdiSendStr(">>> [ICDI] module is enabled.\n");

    /* Return */
    return false;
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
void icdiSendChar(char ch)
{
    uartSendChar(ICDI_MODULE, ch);
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
void icdiSendStr(char *str)
{
    uartSendStr(ICDI_MODULE, str);
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
void icdiSendArr(uint8_t arr[], uint16_t len)
{
    uartSendArr(ICDI_MODULE, arr, len);
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
void UART0_Handler()
{
    /* Clear interrupt */
    UARTIntClear(WIFI_MODULE, UART_INT_RX | UART_INT_RT);

    /* Redirect received data to ESP8266 */
    uartSendChar(WIFI_MODULE, uartGetChar(ICDI_MODULE));
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */

//-----------------------------------------------------------------------------

