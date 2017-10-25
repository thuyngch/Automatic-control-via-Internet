/*
 *  Author  : Nguyen Chinh Thuy.
 *  Date    : 04/09/2017.
 *  Version : 1.0.1.
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "frame.h"

// #define _DEBUG_		// print result into screen for debugging


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Function: State machine of the [FrameDecode] module.
 *
 *	Input	: 	input 	: Input data
 *				addr 	: Address of the device
 *
 *	Output	: 	fnc 	: Mode of data
 *				num 	: Number of content
 *				data 	: Content
 * 				(bool)	: Indicate a frame analysized completely
 */
bool frameDecode
(uint8_t input, uint8_t *addr, uint8_t *fnc, uint8_t *num, uint8_t data[])
{
	/* Static */
	static t_state_machine state = sm_Idle;
	static uint8_t addr_buff, fnc_buff, num_buff;
	static uint8_t data_buff[BUFF_LEN];
	static uint8_t i, count = 0;

	/* Analysize the input */
	switch(state)
	{
		case sm_Idle:
#ifdef _DEBUG_
	printf("sm_Idle\n");
#endif /* _DEBUG_ */
			if(input == START1)
				state = sm_Prestart;
			break;
		//---------------------------------------------------------------------
		case sm_Prestart:
#ifdef _DEBUG_
	printf("sm_Prestart\n");
#endif /* _DEBUG_ */
			if(input == START2)
				state = sm_Start;
			else
				state = sm_Idle;
			break;
		//---------------------------------------------------------------------
		case sm_Start:
#ifdef _DEBUG_
	printf("sm_Start\n");
#endif /* _DEBUG_ */
			addr_buff = input;
			state = sm_Addr;
			break;
		//---------------------------------------------------------------------
		case sm_Addr:
#ifdef _DEBUG_
	printf("sm_Addr\n");
#endif /* _DEBUG_ */
			fnc_buff = input;
			state = sm_Fnc;
			break;
		//---------------------------------------------------------------------
		case sm_Fnc:
#ifdef _DEBUG_
	printf("sm_Fnc, numData=%d\n", input);
#endif /* _DEBUG_ */
			num_buff = input;
			state = sm_Data;
			break;
		//---------------------------------------------------------------------
		case sm_Data:
#ifdef _DEBUG_
	printf("sm_Data\n");
#endif /* _DEBUG_ */
			data_buff[count++] = input;
			if(count == num_buff)
				state = sm_Enddata;
			break;
		//---------------------------------------------------------------------
		case sm_Enddata:
#ifdef _DEBUG_
	printf("sm_Enddata\n");
#endif /* _DEBUG_ */
			if(input == END1)
				state = sm_Preend;
			else
				state = sm_Error;
			break;
		//---------------------------------------------------------------------
		case sm_Preend:
#ifdef _DEBUG_
	printf("sm_Preend\n");
#endif /* _DEBUG_ */
			if(input == END2)
			{
				state = sm_Idle;
				count = 0;
				*addr = addr_buff;
				*fnc = fnc_buff;
				*num = num_buff;
				for(i=0; i<num_buff; i++)
					data[i] = data_buff[i];
				return true;
			}
			else
				state = sm_Error;
			break;
		//---------------------------------------------------------------------
		case sm_Error:
#ifdef _DEBUG_
	printf("sm_Error\n");
#endif /* _DEBUG_ */
			count = 0;
			state = sm_Idle;
			break;
	}

	/* Return */
	return false;
}
//-----------------------------------------------------------------------------
/*
 *	Function: State machine of the [FrameDecode] module.
 *
 *	Input	: 	addr 	: Address of the device
 *				fnc 	: Mode of data
 *				num_data: Number bytes of content
 *				data 	: Content
 *
 *	Output	: 	num_out : Number bytes of output.
 *				output 	: Encoded frame
 */
void frameEncode
(uint8_t addr, uint8_t fnc, uint8_t num_data, uint8_t data[],
 uint16_t *num_out, uint8_t output[])
{
	/* Declare */
	int i = 0, count;

	/* Header bytes */
	output[i++] = START1;
	output[i++] = START2;

	/* Address */
	output[i++] = addr;

	/* Function */
	output[i++] = fnc;

	/* Number of data */
	output[i++] = num_data;

	/* Content of data */
	for(count = 0; count < num_data; count++)
		output[i++] = data[count];

	/* Ending bytes */
	output[i++] = END1;
	output[i++] = END2;

	/* Number bytes of the output */
	*num_out = i;
}
//-----------------------------------------------------------------------------
