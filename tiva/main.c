/*
 *	Author      : Thuy Nguyen-Chinh.
 *	Date        : Sep 04, 2017
 *	Description : This is the main file of the project.
 *	Version	    : 1.0.1.
 */
/******************************************************************************
 *  Include
 *****************************************************************************/
/* Project */
#include "modules/pin_def.h"
#include "system/system.h"
#include "modules/ui/ui.h"


/******************************************************************************
 *  Main
 *****************************************************************************/
void main()
{
    /* Setup */
    systemSetup();

    /* Serve */
    while(1)
    {
        /* Idle: Toggle LED */
        actIdle();
        clkDelayMs(10);

        /* Sweep keypad */
        kpSweep();
        flgBtnInt = kpCheck();

        /* User interface */
        uiServing();
    }
}

