/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 14/09/2017.
 *	Version	: 1.0.1.
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "lcd.h"


/******************************************************************************
 *	Private
 *****************************************************************************/
 
 
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
bool lcdSetup()
{
    /* LCD 16x2 setup */
    LCD_Setup(LCD_PORT_CTRL, LCD_PIN_RS, LCD_PIN_EN, LCD_PORT_DATA, LCD_OFFSET);
    lcdClearScreen();
    lcdChangeLine(0);
    lcdDisplay("Initializing...");

    /* Notify through ICDI */
    icdiSendStr("\r\n>>> [Lcd] module is enabled.\r\n");

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
void lcdClearScreen()
{
    LCD_Clear();
    LCD_Home();
}
//-----------------------------------------------------------------------------
/*
 *  Function:   Change the current line on the screen.
 *
 *  Input   :   line_th : [false] for 1st line, [true] for 2nd line.
 *
 *  Output  :   (void).
 */
void lcdChangeLine(bool line_th)
{
    if(!line_th)
        LCD_Goto(1, 1);
    else
        LCD_Goto(2, 1);
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
void lcdDisplay(char *str)
{
    LCD_PrintString(str);
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
void lcdAddChar(char ch)
{
    LCD_Display(ch);
}
//-----------------------------------------------------------------------------
/*
 *  Function:
 *
 *  Input   :
 *
 *  Output  :
 */
void lcdAddStr(char str[], uint8_t len)
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
void lcdBackspace()
{
}
//-----------------------------------------------------------------------------
