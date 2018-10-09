/*
 *  Author  : Nguyen Chinh Thuy.
 *  Date    : 04/09/2017.
 *  Version : 1.0.1.
 */
#ifndef FRAME_H_
#define FRAME_H_
/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


/******************************************************************************
 *	Define
 *****************************************************************************/
/*
 * Frame structre:
 *			[START1][START2][ADDR][FNC][NUM][DATA...][END1][END2]
 */

/* State machine */
typedef enum
{
	sm_Idle 		= 0,
	sm_Prestart 	= 1,
	sm_Start 		= 2,
	sm_Addr 		= 3,
	sm_Fnc 			= 4,
	sm_Data 		= 5,
	sm_Enddata 		= 6,
	sm_Preend 		= 7,
	sm_Error 		= 8,
} t_state_machine;

/* Special bytes */
#define START1 		1
#define START2		2
#define END1		3
#define END2		4

/* Length of buffer */
#define BUFF_LEN	256


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Decode a data package to elements.
 */
bool frameDecode
(uint8_t input, uint8_t *addr, uint8_t *fnc, uint8_t *num, uint8_t data[]);


/*
 *	Encode elements into a data package.
 */
void frameEncode
(uint8_t addr, uint8_t fnc, uint8_t num_data, uint8_t data[],
 uint16_t *num_out, uint8_t output[]);


#endif /* FRAME_H_ */

