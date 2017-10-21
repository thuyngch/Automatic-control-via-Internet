#ifndef ADMINSERVICE_H_
#define ADMINSERVICE_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "../serveAdmin/serveAdmin.h"
#include "./login/admin_login.h"
#include "./history_viewer/history.h"
#include "configuration/configuration.h"


typedef enum 
{
	ad_0,		//0
	ad_1,		//1
	ad_2, 	//2
} ad_addr_list;

typedef enum
{
	fnc_backup			,//0
	fnc_management		,//1
	fnc_configuration	,//2
	fnc_history			,//3
} ad_fnc;

/*call back struct*/

typedef struct 
{
	ad_fnc			fnc;
	void 			(*callback)(int*, uint8_t, uint8_t);				
					/*socket, addr, fnc*/
} admin_service_struct;	

static admin_service_struct admin_service_menu[] =
{
	{fnc_backup, backup},
	{fnc_management, management},
	{fnc_configuration, configuration},
	{fnc_history, history},
};


/*Menu struct*/
typedef struct 
{
	const char*	str;
	ad_fnc 	fnc;
} menu;

static menu fnc_menu[] = 
{
	{"fnc_backup", fnc_backup},
	{"fnc_management", fnc_management},
	{"fnc_configuration", fnc_configuration},
	{"fnc_history", fnc_history},
};


void adminService(int *connfd, ad_addr_list addr);

#endif