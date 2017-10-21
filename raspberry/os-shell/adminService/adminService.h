/*
 *	Date	: 26/08/2017.
 *	Content	: 
 */
#ifndef _ADMINSERVICE_H_
#define _ADMINSERVICE_H_
/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#include "../../lib/frame/frame.h"
#include "../../lib/communication/communication.h"
#include "../login/login.h"
#include "backup/backup.h"
#include "management/management.h"
#include "history_viewer/history.h"
#include "configuration/configuration.h"



/******************************************************************************
 *	Define
 *****************************************************************************/
/* Types of function of data */
typedef enum
{
	fnc_backup			,//0
	fnc_management		,//1
	fnc_configuration	,//2
	fnc_history			,//3
	fnc_answer			,//4
} t_fnc;

<<<<<<< HEAD
/* admin service */
=======
/* Client service */
>>>>>>> 54c690b6c141ea37d5ffcfb07b91188db302b08e
typedef struct 
{
	uint8_t		addr;
	t_fnc 		fnc;
	void			(*callback)(int*, uint8_t, uint8_t);
								/*num  , addr, fnc*/
} t_admin_service;

static t_admin_service sAdminService[] = {
	/*ad_0*/
	{0x00, fnc_backup, backup},
	{0x00, fnc_management, management},
	{0x00, fnc_configuration, configuration},
	{0x00, fnc_history, history},

	/*ad_1*/
	{0x01, fnc_backup, backup},
	{0x01, fnc_management, management},
	{0x01, fnc_configuration, configuration},
	{0x01, fnc_history, history},
};


/******************************************************************************
 *	Function
 *****************************************************************************/
/* Admin service */
void
serveAdmin
(int *connfd, uint8_t addr, uint8_t fnc);

bool
verifyAdminService
(uint8_t addr, uint8_t fnc, int num_serv, t_admin_service sAdminService[], int *serv_idx);

void
answerAdmin
(int connfd, uint8_t addr, uint8_t num, uint8_t data[]);

void 
serverService
(int *connfd, uint8_t root_addr, uint8_t num_data_in, uint8_t data_in[]);

#endif /* ADMINSERVICE_H_ */