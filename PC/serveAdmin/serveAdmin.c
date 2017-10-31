/************************************
* Date created: 	10-8-2017
* Date finished: 	
* Editor: Sublime Text 3
* Author: Le Van Hoang Phuong
* Description: 
*************************************/
#include "serveAdmin.h"
#include"../adminService/adminService.h"

#define account_folder_dir 	"../../kernel/accounts/user/"


void serveAdmin(int *connfd, uint8_t serv_x, uint8_t addr, uint8_t func)
{
	/*search position of service acordant to fnc*/
	fprintf(stderr, "\n%s: %d - function: %d\n", "> starting to serve Admin", (int)addr, (int)func);
	admin_service_menu[serv_x].callback(connfd, addr, func);
}
