/*
 *	Author	    : Thuy Nguyen-Chinh.
 *	Date	    : Sep 04, 2017
 *	Description : This file is responsible for initializing the whole of system.
 *	Version	    : 1.0.1.
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
/* Standard */

/* Driver */

/* Project */
#include "system.h"


/******************************************************************************
 *	Private
 *****************************************************************************/
/* Modules of system */
s_sysmod SystemModule[] = {
    {modid(Icdi)    , icdiSetup},
    {modid(Act)     , actSetup},
    {modid(Lcd)     , lcdSetup},
    {modid(Kp)      , kpSetup},
    {modid(Wifi)    , wifiSetup},
};


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
bool systemSetup()
{
    /* Declare */
    uint8_t i, num;

    /* Setup clock */
    clkSetup(CLK_SRC_MAIN, CLK_PLL_ON, CLK_FREQ_120MHZ);

    /* Number of modules */
    num = sizeof(SystemModule) / sizeof(s_sysmod);

    /* Loop for setupping modules. If error, return true */
    for(i = 0; i < num; i++)
        if(SystemModule[i].callback())
            return true;

    /* Welcome interface */
    lcdClearScreen();
    lcdChangeLine(0);
    lcdDisplay("Welcome");

    /* If  no error, return false */
    return false;
}
//-----------------------------------------------------------------------------
