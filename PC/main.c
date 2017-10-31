/************************************
* Date created: 	10-8-2017
* Date finished: 	
* Editor: Sublime Text 3
* Author: Le Van Hoang Phuong
* Description: PC main program
*************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <pthread.h>

#include "../raspberry/lib/fileproc/fileproc.h"
#include "../raspberry/lib/communication/communication.h"
#include "./adminService/backup/backup.h"
#include "./adminService/adminService.h"
#include "adminService/management/management.h"
#include "./serveAdmin/serveAdmin.h"


int main(int argc, char const *argv[])
{
	int connfd;
	/*create socket for admin*/
	connfd = createClientSocket(argv[1], atoi(argv[2]));	

	/*run admin Service control*/
	/*define admin addr here: ad_0, you can get addr each time from keyboard*/
	
	// adminService(&connfd, ad_1); 
	adminService(&connfd, ad_1);

	/*remove main.o*/
	unlink("main");

	/*return*/
	return 0;
}