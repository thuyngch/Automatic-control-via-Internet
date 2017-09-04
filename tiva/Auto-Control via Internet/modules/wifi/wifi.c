/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 04/09/2017.
 *	Version	: 1.0.1.
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "wifi.h"


/******************************************************************************
 *	Private
 *****************************************************************************/
/* State register */
typedef struct
{
    unsigned Null   : 1;    // Meet '\0' character or not?
} s_regstate;

static  s_regstate  sRegState;
//-----------------------------------------------------------------------------
/* Buffer */
uint8_t     wifiBuff[256];
uint8_t     buffCount;
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
static void espSetupProtocol(uint32_t timeout)
{
    /* Initialize */
    espSetup(WIFI_MODULE, WIFI_PORT_CTL, WIFI_PIN_RST, WIFI_PIN_EN);
    wifiStartTimerCount(timeout);
    while(!wifiCheckATCmdComplete("ready"))
        wifiStartTimerCount(timeout);

    /* Check module */
    espCheckModule();
    wifiStartTimerCount(timeout);
    while(!wifiCheckATCmdComplete("OK"))
        wifiStartTimerCount(timeout);

    /* Connect to Access-Point */
    espConnectWifi("user-name", "password");
    wifiStartTimerCount(timeout);
    while(!wifiCheckATCmdComplete("OK"))
        wifiStartTimerCount(timeout);

    /* Mode of connection */
    espMultiConnection();
    wifiStartTimerCount(timeout);
    while(!wifiCheckATCmdComplete("OK"))
        wifiStartTimerCount(timeout);

    /* Configure server */
    espMakeServer(8000);
    wifiStartTimerCount(timeout);
    while(!wifiCheckATCmdComplete("OK"))
        wifiStartTimerCount(timeout);

    /* Get IP address of ESP8266 */
    espGetIP();
    wifiStartTimerCount(timeout);
    while(!wifiCheckATCmdComplete("OK"))
        wifiStartTimerCount(timeout);
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :   (bool) True of matched, False if not.
 */
static bool wifiCheckATCmdComplete(char* strCheck)
{
    while(!sRegState.Null);                 // While unless matching '\0'
    wifiStopTimerCount();                   // Stop Timer count
    sRegState.Null = false;                 // Reset [Null] field
    wifiClearBuffer(wifiBuff, buffCount);   // Clear buffer
    buffCount = 0;                          // Reset counter of buffer
    return strstr((char*)wifiBuff, strCheck);
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
static void wifiStartTimerCount(uint32_t timeout)
{
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
static void wifiStopTimerCount(void)
{
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
static void wifiClearBuffer(uint8_t buff[], uint8_t len)
{
    uint8_t i;
    for(i = 0; i < len; i++)
        buff[i] = 0;
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


/******************************************************************************
 *	Public
 *****************************************************************************/
/*
 *  Function:   Setup [WiFi] module.
 *
 *	Input	:	(void).
 *
 *	Output	:	(void).
 */
bool wifiSetup()
{
	/* GPIO setup */
	gpioOutputSetup(WIFI_PORT_CTL, WIFI_PIN_RST | WIFI_PIN_EN);

	/* UART setup */
    uartSetup(ui32ClkFreq, WIFI_MODULE, 115200, UART_INT_RT | UART_INT_RX);
	
	/* ESP8266 setup */
    espSetupProtocol(65000);

	/* Notify */
	uartPrintf("[WiFi] module is enabled.\n");

	/* If no error, return false */
	return false;
}
//-----------------------------------------------------------------------------

