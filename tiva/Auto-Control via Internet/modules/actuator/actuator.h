/*
 *	Author	: Nguyen Chinh Thuy.
 *	Date	: 04/09/2017.
 *	Version	: 1.0.1.
 */

#ifndef	ACTUATOR_H_
#define	ACTUATOR_H_

/******************************************************************************
 *	Include
 *****************************************************************************/
/* Standard */
#include <stdint.h>
#include <stdbool.h>

/* Driver */
#include <GPIO.1.0.1.h>
#include <UART.1.0.1.h>
#include <TIMER.1.0.1.h>

/* Project */
#include "../pin_def.h"
#include "../icdi/icdi.h"


/******************************************************************************
 *	Definition
 *****************************************************************************/
#define ACT_DELAY_INTERVAL      120000000   // 1s interval


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *  Setup [Actuator] module.
 */
bool actSetup();


/*
 *  [Actuator] module serves for requests.
 */
void actServe(bool result, uint32_t interval);


/*
 *  Idle state.
 */
void actIdle();


#endif	/* ACTUATOR_H_ */

