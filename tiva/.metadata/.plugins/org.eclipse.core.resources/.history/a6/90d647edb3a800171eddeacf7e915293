/*
 *	Author	    : Thuy Nguyen-Chinh.
 *	Date	    : Sep 14, 2017.
 *	Description : User interface including LCD 16x2 and keypad.
 *	Version	    : 1.0.1.
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "ui.h"


/******************************************************************************
 *	Private
 *****************************************************************************/
 /* Pages state */
t_page  pageState;

//-----------------------------------------------------------------------------
/* Username and password */
char usr[UI_LEN+1];     int8_t usr_count = 0;
char pass[UI_LEN+1];    int8_t pass_count = 0;

//-----------------------------------------------------------------------------
/*
 *  Function:   Call page corresponding to state register.
 *
 *  Input   :   (void)
 *
 *  Output  :   (void)
 */
static void uiCallPage(t_KpBtn readbtn)
{
    switch(pageState)
    {
    case page_idle:
        uiPageUsr(readbtn);
        pageState = page_usr;
        break;
    case page_usr:
        uiPageUsr(readbtn);
        break;
    case page_pass:
        uiPagePass(readbtn);
        break;
    case page_result:
        uiPageResult(usr, pass);
        break;
    }
}
//-----------------------------------------------------------------------------
/*
 *  Function:   Display welcome string.
 *
 *  Input   :   (void).
 *
 *  Output  :   (void).
 */
static void uiPageIdle()
{
    lcdClearScreen();
    lcdDisplay("Welcome");
}
//-----------------------------------------------------------------------------
/*
 *  Function:   Page serves for the username-input process.
 *
 *  Input   :   readbtn : Read button.
 *
 *  Output  :   (void)
 */
static void uiPageUsr(t_KpBtn readbtn)
{
    /* Title line */
    lcdClearScreen();
    lcdDisplay("Username:");

    /* Update buffer */
    if(readbtn == BTN(Clr))
    {
        //-Back to the Idle page-//
        if(--usr_count < 0)             // Backspace current cursor
        {
            usr_count = 0;              // Reset count
            pageState = page_idle;  // Set the page to Idle
            uiPageIdle();
            return;
        }
        //-Remove the last character-//
        else
            usr[usr_count] = 0;
    }
    //-------------------------------------------------------------------------
    else if(readbtn == BTN(Cfm))
    {
        if(usr_count == 0)
        {
            //-Overflow notification-//
            lcdClearScreen();
            lcdDisplay("Empty");

            //-Delay interval-//
            clkDelayMs(1000);

            //-Return to the current state-//
            lcdClearScreen();
            lcdDisplay("Username:");
        }
        else
        {
            lcdClearScreen();
            lcdDisplay("Password:");

            pageState = page_pass;
            readBtn = BTN(None);
        }
        return;
    }
    //-------------------------------------------------------------------------
    else if((readbtn >= BTN(0)) && (readbtn <= BTN(9)))
    {
        if(usr_count == UI_LEN)
        {
            //-Overflow notification-//
            lcdClearScreen();
            lcdDisplay("Overflow");

            //-Delay interval-//
            clkDelayMs(1000);

            //-Return to the current state-//
            lcdClearScreen();
            lcdDisplay("Username:");
        }
        else
        {
            usr[usr_count++] = readbtn - BTN(0) + '0';
            usr[usr_count] = 0;
        }
    }
    //-------------------------------------------------------------------------
    else if((readbtn >= BTN(A)) && (readbtn <= BTN(D)))
    {
        if(usr_count == UI_LEN)
        {
            //-Overflow notification-//
            lcdClearScreen();
            lcdDisplay("Overflow");

            //-Delay interval-//
            clkDelayMs(1000);

            //-Return to the current state-//
            lcdClearScreen();
            lcdDisplay("Username:");
        }
        else
        {
            usr[usr_count++] = readbtn - BTN(A) + 'A';
            usr[usr_count] = 0;
        }
    }

    /* Content line */
    lcdChangeLine(1);
    lcdDisplay(usr);
}
//-----------------------------------------------------------------------------
/*
 *  Function:   Page serves for the password-input process.
 *
 *  Input   :   readbtn : Read button.
 *
 *  Output  :   (void)
 */
static void uiPagePass(t_KpBtn readbtn)
{
    /* Declare */
    uint8_t i;

    /* Title line */
    lcdClearScreen();
    lcdDisplay("Password:");

    /* Update buffer */
    if(readbtn == BTN(Clr))
    {
        //-Back to the Idle page-//
        if(--pass_count < 0)             // Backspace current cursor
        {
            pass_count = 0;              // Reset count
            readBtn = BTN(None);
            pageState = page_usr;   // Set the page
            uiPageUsr(readBtn);
            return;
        }
        //-Remove the last character-//
        else
            pass[pass_count] = 0;
    }
    //-------------------------------------------------------------------------
    else if(readbtn == BTN(Cfm))
    {
        if(pass_count == 0)
        {
            //-Overflow notification-//
            lcdClearScreen();
            lcdDisplay("Empty");

            //-Delay interval-//
            clkDelayMs(1000);

            //-Return to the current state-//
            lcdClearScreen();
            lcdDisplay("Password:");
        }
        else
        {
            pageState = page_result;
            uiPageResult(usr, pass);
        }
        return;
    }
    //-------------------------------------------------------------------------
    else if((readbtn >= BTN(0)) && (readbtn <= BTN(9)))
    {
        if(pass_count == UI_LEN)
        {
            //-Overflow notification-//
            lcdClearScreen();
            lcdDisplay("Overflow");

            //-Delay interval-//
            clkDelayMs(1000);

            //-Return to the current state-//
            lcdClearScreen();
            lcdDisplay("Password:");
        }
        else
        {
            pass[pass_count++] = readbtn - BTN(0) + '0';
            pass[pass_count] = 0;
        }
    }
    //-------------------------------------------------------------------------
    else if((readbtn >= BTN(A)) && (readbtn <= BTN(D)))
    {
        if(pass_count == UI_LEN)
        {
            //-Overflow notification-//
            lcdClearScreen();
            lcdDisplay("Overflow");

            //-Delay interval-//
            clkDelayMs(1000);

            //-Return to the current state-//
            lcdClearScreen();
            lcdDisplay("Password:");
        }
        else
        {
            pass[pass_count++] = readbtn - BTN(A) + 'A';
            pass[pass_count] = 0;
        }
    }

    /* Content line */
    lcdChangeLine(1);
    for(i = 0; i < strlen(pass); i++)
        lcdAddChar('*');
}
//-----------------------------------------------------------------------------
/*
 *  Function:   Page serves for the result process.
 *
 *  Input   :   usr     : Confirmed username
 *              pass    : Confirmed password
 *
 *  Output  :   (void)
 */
static void uiPageResult(char *usr, char *pass)
{
    /* Declare */
    bool match_result = false;

    /* Wait for server */
    lcdClearScreen();
    lcdDisplay("Verifying...");

    /* Send data */
    wifiConnectServer();
    wifiSendData(usr, pass);

    /* Receive data */
    match_result = wifiRecData();

    /* Disconnect from the server */
    wifiDisconnectServer();

    /* Display the result */
    lcdClearScreen();
    if(match_result)
    {
        lcdDisplay("Valid");
        icdiSendStr("\r\n>> Valid verification\r\n");
        actServe(true);
    }
    else
    {
        lcdDisplay("Invalid");
        icdiSendStr("\r\n>> Invalid verification\r\n");
        clkDelayMs(5000);
    }

    /* Reset username and password */
    memset(usr, 0, UI_LEN+1);   usr_count = 0;
    memset(pass, 0, UI_LEN+1);  pass_count = 0;

    /* Return to Idle page */
    pageState = page_idle;
    uiPageIdle();
}


/******************************************************************************
 *  Public
 *****************************************************************************/
/*
 *  Function:   User interface service.
 *
 *  Input   :   (void)
 *
 *  Output  :   (void)
 */
void uiServing()
{
    if(flgBtnInt)
    {
        flgBtnInt = false;
        uiCallPage(readBtn);
    }
}
//-----------------------------------------------------------------------------


