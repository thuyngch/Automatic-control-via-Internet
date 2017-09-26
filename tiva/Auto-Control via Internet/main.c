/*
 *	Author	    : Thuy Nguyen-Chinh.
 *	Date	    : Sep 04, 2017
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
    /* Declare */
//    bool match_result = false;

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

        //-Testing of [DataTransaction]-//
//        if(flgICDI)
//        {
//            //-Remove ICDI interrupt flag-//
//            flgICDI = false;
//
//            //-Connect to the server-//
//            wifiConnectServer();
//
//            //-Send and receive data from the server-//
//            wifiSendData(buff, buff+7);
//            match_result = wifiRecData();
//
//            //-Display result into the Terminal-//
//            clkDelayMs(100);
//            if(match_result)
//                icdiSendStr("\n>>> Verification is correct!\n");
//            else
//                icdiSendStr("\n>>> Verification is wrong!\n");
//        }
    }
}

