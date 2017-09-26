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

#include "../pin_def.h"
#include "../icdi/icdi.h"


/******************************************************************************
 *	Definition
 *****************************************************************************/
/* Sweep cycle */
#define KEYPAD_SWEEP_CYCLE      50      // ms
//-----------------------------------------------------------------------------

/* Anti-noise delay */
#define KEYPAD_ANTI_NOISE       10      // ms

//-----------------------------------------------------------------------------

/* Enum of Button */
typedef enum
{
	kpBtn_None	= 0,
	kpBtn_0		= 1,
	kpBtn_1		= 2,
	kpBtn_2		= 3,
	kpBtn_3		= 4,
	kpBtn_4		= 5,
	kpBtn_5		= 6,
	kpBtn_6		= 7,
	kpBtn_7		= 8,
	kpBtn_8		= 9,
	kpBtn_9		= 10,
	kpBtn_A		= 11,
	kpBtn_B		= 12,
	kpBtn_C		= 13,
	kpBtn_D		= 14,
	kpBtn_Clr	= 15,
	kpBtn_Cfm	= 16
} t_KpBtn;
#define	BTN(x)		(kpBtn_##x)	// Get name of Button

//-----------------------------------------------------------------------------
/* Available interrupt */
extern  bool    flgBtnInt;      // Indicate whether a button is pressed
extern  t_KpBtn readBtn;        // Which button is pressed


/******************************************************************************
 *  Function
 *****************************************************************************/
/* Setup */
bool kpSetup();

/* Sweep */
void kpSweep();

/* Interrupt */
void GPIO_PK_Handler();


/******************************************************************************
 *	Private
 *****************************************************************************/
/* Read button */
static t_KpBtn kpReadBtnFromISR();


#endif	/* KEYPAD_H_ */
