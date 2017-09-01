/*
 *	Date	: 26/08/2017.
 *	Content	: 
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "clientService.h"


/******************************************************************************
 *	Private
 *****************************************************************************/
/* Client services */
static t_client_service sClientService[] = {
	{0x00, fnc_login, login},
	{0x00, fnc_answer, login},
	{0x01, fnc_login, login},
};


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Function: Server serves for Client.
 *
 *	Input	: 	
 *
 *	Output	:	
 */
void serveClient(uint8_t addr, uint8_t fnc, uint8_t num, uint8_t data[])
{
	/* Declare */
	int num_serv = sizeof(sClientService) / sizeof(t_client_service);
	int serv_idx;
	uint8_t num_out;
	uint8_t out[BUFF_LEN];

	/* Verify the correct of client service */
	if(!verifyClientService(addr, fnc, num_serv, sClientService, &serv_idx))
		return;

	/* Serve for client */
	sClientService[serv_idx].callback(num, data, &num_out, out);

	/* Answer the result for client */
	answerClient(addr, num_out, out);
}
//-----------------------------------------------------------------------------
/*
 *	Function: Verify the validity of a specific client service.
 *
 *	Input	: 	
 *
 *	Output	:	
 */
bool verifyClientService(uint8_t addr, uint8_t fnc,
						 int num_serv, t_client_service *sClientService,
						 int *serv_idx)
{
	/* Trace the validity of service */
	for(int i = 0; i < num_serv; i++)
		if((sClientService[i].addr == addr) && (sClientService[i].fnc == fnc))
		{
			*serv_idx = i;
			return true;
		}

	/* Return */
	return false;
}
//-----------------------------------------------------------------------------
/*
 *	Function: Answer to the client.
 *
 *	Input	: 	
 *
 *	Output	:	
 */
void answerClient(uint8_t addr, uint8_t num, uint8_t data[])
{
	/* Create buffer */
	uint8_t out[BUFF_LEN];
	int num_out;
	frameEncode(addr, fnc_answer, num, data, &num_out, out);

	/* Send to the client */
	printf("Number of bytes of the answer: %d\n", num_out);
	for(int i = 0; i < num_out; i++)
		printf("[%d] - %c\n", out[i], out[i]);
}
//-----------------------------------------------------------------------------