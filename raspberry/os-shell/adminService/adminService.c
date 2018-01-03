/************************************
* Date created: 	10-8-2017
* Date finished: 	
* Editor: Sublime Text 3
* Author: Le Van Hoang Phuong
* Description: 
*************************************/
#include "adminService.h"

uint8_t frame_len(uint8_t frame[])
{
	for (int i = 0; i < 128; ++i)
	{
		if ( (frame[i] == 0) && (frame[i+1] == 0) && (frame[i+2] == 0) ) 
			return (uint8_t)i;
		break;
	}
}

/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Function: manage and deploy service for admin
 *
 *	Input	: 	
 *
 *	Output	:	
 */
void serverService(int *connfd, uint8_t root_addr, uint8_t num_data_in, uint8_t data_in[])
{
	uint8_t curr_addr, fnc;
	/*return of login*/
	uint8_t login_result_out[BUFF_LEN];
	uint8_t num_data_out;

	/*login is not a service, this is a must*/
	login(connfd, num_data_in, data_in, &num_data_out, login_result_out);
	answerAdmin(*connfd, root_addr, num_data_out, login_result_out);
	/*must login to use other service*/
	while (login_result_out[0])
	{
		/*recv service required*/
		uint8_t buff[32];
		uint8_t data_out[8];
		fprintf(stderr, "\n%s\n\n", "> waiting for service desired ...");
		if(!recv(*connfd, buff, 32, 0)) 
		{
			fprintf(stderr, "%s%d%s\n", "> admin [", root_addr, "] logged out"); 
			return;
		}
		/*decode and callback*/
		for (int i = 0; i < 8; ++i)
		{
			if(frameDecode(buff[i], &curr_addr, &fnc, &num_data_out, data_out))
			{
				/*check addr ?= login-addr*/
				if (root_addr != curr_addr) break;
				/*callback function*/
				fprintf(stderr, "%s: %d\n", "fnc is", fnc);
				serveAdmin(connfd, curr_addr, fnc);
				break;
			}
		}		
	}
}

/*
 *	Function: Server serves for Admin.
 *	Input	: 	
 *	Output	:	
 */
void serveAdmin(int *connfd, uint8_t addr, uint8_t fnc)
{
	/* Declare */
	int num_serv = sizeof(sAdminService) / sizeof(t_admin_service);
	int serv_idx;
	uint8_t num_out;
	uint8_t out[BUFF_LEN];

	/* Verify the correct of Admin service */
	if(!verifyAdminService(addr, fnc, num_serv, sAdminService, &serv_idx))
		return;
	/* Serve for Admin */
	sAdminService[serv_idx].callback(connfd, addr, fnc);
}
//-----------------------------------------------------------------------------
/*
 *	Function: Verify the validity of a specific Admin service.
 *
 *	Input	: 	
 *
 *	Output	:	
 */
bool verifyAdminService(uint8_t addr, uint8_t fnc, int num_serv, 
				t_admin_service *sAdminService, int *serv_idx)
{
	/* Trace the validity of service */
	for(int i = 0; i < num_serv; i++)
		if((sAdminService[i].addr == addr) && (sAdminService[i].fnc == fnc))
		{
			*serv_idx = i;
			return true;
		}
	/* Return */
	return false;
}
//-----------------------------------------------------------------------------
/*
 *	Function: Answer to the Admin.
 *
 *	Input	: 	
 *
 *	Output	:	
 */
void answerAdmin(int connfd, uint8_t addr, uint8_t num, uint8_t data[])
{
	fprintf(stderr, "%s\n", "--------------------------------------------------------------------------------");
	/* Create buffer */
	uint8_t ans_data[BUFF_LEN];
	int num_ans;
	frameEncode(addr, fnc_answer, num, data, &num_ans, ans_data);

	/* Print to the screen */
	printf("> [OS_login]: {addr=%x, result=%d}\n", addr, ans_data[5]);

	/* Send the result to the Admin */
	sendDataSocket(connfd, ans_data, num_ans);
}
//-----------------------------------------------------------------------------
