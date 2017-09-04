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
    unsigned Null       : 1;    // Meet '\0' character or not?
    unsigned isSetup    : 1;    // In the Setup progress.
    unsigned flgUartInt : 1;    // UART3 interrupt flag.
} s_regstate;

 s_regstate  sRegState;
//-----------------------------------------------------------------------------
/* Buffer */
uint8_t     buffCount;
uint8_t     wifiBuff[256];
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
    TimerLoadSet(TIMER0, TIMER_A, timeout);
    TimerEnable(TIMER0, TIMER_A);
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
    TimerDisable(TIMER0, TIMER_A);
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
    sRegState.isSetup = true;
    uartSetup(ui32ClkFreq, WIFI_MODULE, 115200, UART_INT_RT | UART_INT_RX);

    /* Setup timer */
    timerSetup(TIMER0, TIMER_A, TIMER_CFG_PERIODIC_UP, true, 1, WIFI_TIMEOUT);
	
	/* ESP8266 setup */
    espSetupProtocol(WIFI_TIMEOUT);

	/* Notify */
	uartPrintf("[WiFi] module is enabled.\n");

	/* If no error, return false */
    sRegState.isSetup = false;
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
void wifiSendData(char *usr, char *pass)
{
    /* Declare */
    uint8_t frame[30];
    uint8_t data[20];
    uint16_t framelen;

    /* Encode frame */
    sprintf((char*)data, "%s %s", usr, pass);
    data[strlen(usr)] = 0;
    frameEncode(WIFI_ADDR, WIFI_SERVICE_LOGIN,
                strlen(usr)+strlen(pass)+1, data, &framelen, frame);

    /* Send */
    uartSendArr(WIFI_MODULE, frame, framelen);
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
bool wifiRecData()
{
    /* Declare */
    uint8_t addr, fnc;
    uint8_t num;
    uint8_t data[5];

    /* Wait for received data */
WAIT:
    while(!sRegState.flgUartInt);
    sRegState.flgUartInt = false;

    /* Analyze data */
    if(frameDecode(wifiBuff[buffCount-1], &addr, &fnc, &num, data))
    {
        if(addr==WIFI_ADDR_SERVER && fnc==WIFI_SERVICE_ANSWER)
        {
            if(num==1)
            {
                if(data[0])
                    return true;
                else
                    return false;
            }
        }
    }
    else
        goto WAIT;
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
void UART3_Handler(void)
{
    /* Clear interrupt */
    UARTIntClear(WIFI_MODULE, UART_INT_RX | UART_INT_RT);
    sRegState.flgUartInt = true;

    /* Setup progress */
    if(sRegState.isSetup)
    {
        wifiBuff[buffCount] = uartGetChar(UART3);
        if(wifiBuff[buffCount++] == '\0')
            sRegState.Null = true;
        else
            sRegState.Null = false;
    }

    /* Serving progress */
    else
        wifiBuff[buffCount++] = uartGetChar(UART3);
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
void TIMER0A_Handler()
{
    sRegState.Null = true;  // Overflow, escape the loop
    timerIntExit(TIMER0, TIMER_A);
}
//-----------------------------------------------------------------------------

