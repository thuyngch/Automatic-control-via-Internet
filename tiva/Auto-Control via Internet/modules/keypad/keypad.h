/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 04/09/2017.
 *	Version	: 1.0.1.
 */

#ifndef	KEYPAD_H_
#define	KEYPAD_H_

/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include <GPIO.1.0.1.h>

#include"../pin_def.h"


/******************************************************************************
 *	Include
 *****************************************************************************/
/* Enum of Button */
typedef enum
{
	edmcKpBtn_None	= 0,
	edmcKpBtn_0		= 1,
	edmcKpBtn_1		= 2,
	edmcKpBtn_2		= 3,
	edmcKpBtn_3		= 4,
	edmcKpBtn_4		= 5,
	edmcKpBtn_5		= 6,
	edmcKpBtn_6		= 7,
	edmcKpBtn_7		= 8,
	edmcKpBtn_8		= 9,
	edmcKpBtn_9		= 10,
	edmcKpBtn_A		= 11,
	edmcKpBtn_B		= 12,
	edmcKpBtn_C		= 13,
	edmcKpBtn_D		= 14,
	edmcKpBtn_Clr	= 15,
	edmcKpBtn_Cfm	= 16
} tKpBtn;

#define	BTN(x)		(edmcKpBtn_##x)	// Get name of Button
//-------------------------------------------------------------------------------------------------
/* Setup */
bool
kpSetup
();

uint32_t
edmcKpEnable		(void);
//-------------------------------------------------------------------------------------------------
/* Sweep */
void
edmcKpSweep			(void);
//-------------------------------------------------------------------------------------------------
/* Read button */
tKpBtn
kpReadBtnFromISR	(void);
//-------------------------------------------------------------------------------------------------
/* Password */
bool
edmcKpPassIsRight	(void);
void
edmcKpPassDisable	(void);
void
edmcKpPassPrc		(tKpBtn ui8Btn);
//-------------------------------------------------------------------------------------------------
/* Interrupt */
void
EDMC_KP_ISR			(void);


/******************************************************************************
 *	Function
 *****************************************************************************/
/* Password */
static	void
kpPassData			(tKpBtn ui8Btn);
static	void
kpPassClr			(void);
static	bool
kpPassCfm			(void);
static	void
kpPassRight			(void);
static	void
kpPassWrong			(void);
static	void
kpPassOvf			(void);


#endif	/* KEYPAD_H_ */
