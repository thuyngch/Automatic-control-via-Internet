/******************************************************************************
 *  Author      : Thuy Nguyen-Chinh
 *  Date        : 02 Oct 2017
 *
 *  IDE         : Sublime Text 3
 *
 *  Description : Account provider and pre-verifier.
 *****************************************************************************/

/******************************************************************************
 *  Include
 *****************************************************************************/
#include "account.h"


/******************************************************************************
 *  Definition
 *****************************************************************************/


/******************************************************************************
 *  Function
 *****************************************************************************/
/*
 *  Function: Pre-heck the validity of login username.
 *
 *  Input   : usrname: Login username.
 *
 *  Output  : (bool) True if username is correct to the framework.
 */
bool accPreCheck(char* usrname)
{
    /* Declare */
    char data[ACC_LEN+1];           // Buffer to load username
    uint8_t oddn = 0;               // Number of odd digit exceeds 4
    int validity;                   // Result value
    uint8_t i;						// Counter to scan data

    /* Convert string to numbers */
    strcpy(data, usrname);
    for(int i = 0; i < ACC_LEN; i++)
    {
        if((data[i] >= '0') && (data[i] <= '9'))
            data[i] -= '0';
        else if((data[i] >= 'A') && (data[i] <= 'D'))
            data[i] -= 'A' + 10;
    }

    /* Calculate the validity */
    for(i = 0; i < ACC_LEN; i++)
    {
    	if(i%2)
    		validity += data[i];
    	else
    	{
    		validity += 2*data[i];
    		if(data[i] > 4)
    			oddn++;
    	}
    }
    validity += oddn;

    /* Return */
    if(validity % 10)
        return false;
    else
        return true;
}
//-----------------------------------------------------------------------------
