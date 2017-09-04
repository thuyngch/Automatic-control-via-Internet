/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 04/09/2017.
 *	Version	: 1.0.1.
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "actuator.h"


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
 *  Function: Setup module [WiFi].
 *
 *  Input   : (void).
 *
 *  Output  : (bool) True if error, False if no error.
 */
bool actSetup()
{
    gpioOutputSetup(ACT_PORT, ACT_PIN_ON | ACT_PIN_OFF);
    uartPrintf("[Actuator] module is enabled.\n");
    return false;
}
//-----------------------------------------------------------------------------
/*
 *  Function: Module [Actuator] serves for requests.
 *
 *  Input   : result    : Matching result.
 *            interval  : Interval of delay between two logins.
 *
 *  Output  : (void).
 */
void actServe(bool result, uint32_t interval)
{
    if(result)
    {
        gpioHigh(ACT_PORT, ACT_PIN_ON);
        timerDelay(interval);
        gpioLow(ACT_PORT, ACT_PIN_ON);
    }
    else
    {
        gpioHigh(ACT_PORT, ACT_PIN_OFF);
        timerDelay(interval);
        gpioLow(ACT_PORT, ACT_PIN_OFF);
    }
}
//-----------------------------------------------------------------------------
