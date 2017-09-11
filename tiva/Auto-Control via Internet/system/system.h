/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 04/09/2017.
 *	Version	: 1.0.1.
 */
#ifndef	SYSTEM_H_
#define	SYSTEM_H_
/******************************************************************************
 *	Include
 *****************************************************************************/
/* Standard */
#include <stdint.h>
#include <stdbool.h>

/* Driver */
#include <GPIO.1.0.1.h>
#include <CLK.1.0.1.h>
#include <UART.1.0.1.h>
#include <TIMER.1.0.1.h>

/* Project */
#include "../modules/pin_def.h"
#include "../modules/icdi/icdi.h"
#include "../modules/actuator/actuator.h"
#include "../modules/keypad/keypad.h"
#include "../modules/lcd/lcd.h"
#include "../modules/wifi/wifi.h"


/******************************************************************************
 *	Definition
 *****************************************************************************/
/* Modules of system */
typedef enum
{
    modid_Icdi  = 0,
	modid_Act	= 1,
	modid_Kp	= 2,
	modid_Lcd	= 3,
	modid_Wifi	= 4,
} e_modid;
#define	modid(x)	(modid_##x)

typedef struct
{
	e_modid modid;		// Module ID
	bool (*callback)();	// Setup callback
} s_sysmod;


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	System setups modules.
 */
bool
systemSetup
();


#endif	/* SYSTEM_H_ */

