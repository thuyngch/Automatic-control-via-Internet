/******************************************************************************
 *  Author      : Thuy Nguyen-Chinh
 *  Date        : 02 Oct 2017
 *
 *  IDE         : Sublime Text 3
 *
 *  Description : Account provider and pre-verifier.
 *****************************************************************************/
#ifndef ACCOUNT_H_
#define ACCOUNT_H_


/******************************************************************************
 *  Include
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


/******************************************************************************
 *  Definition
 *****************************************************************************/
/*  Framework: [d0][d1][d2][d3][d4][d5]

    [d] is a digit, which may be '0'...'9', 'A'...'D'.
    [odd] is the group of odd digits.
    [even] is the group of even digits.
    [n] is the number of odd digits, which have value that exceeds 4.

    Validity: (2*sum(odd) + sum(even) + n) mod 10 == 0
*/

/* Maximum lenght of account element (username and password) */
#define ACC_LEN         6


/******************************************************************************
 *  Function
 *****************************************************************************/
/*
 *
 */
bool accPreCheck(char* usrname);


#endif /* ACCOUNT_H_ */

