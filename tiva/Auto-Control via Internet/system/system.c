/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 04/09/2017.
 *	Version	: 1.0.1.
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
    {modid(Act)     , actSetup},
    {modid(Kp)      , kpSetup},
    {modid(Lcd)     , lcdSetup},
    {modid(Wifi)    , wifiSetup},
};
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

    /* Number of modules */
    num = sizeof(SystemModule) / sizeof(s_sysmod);

    /* Loop for setupping modules. If error, return true */
    for(i = 0; i < num; i++)
        if(SystemModule[i].callback())
            return true;

    /* If  no error, return false */
    return false;
}
//-----------------------------------------------------------------------------
