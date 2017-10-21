#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <pthread.h>

#include "../lib/fileproc/fileproc.h"
#include "../lib/communication/communication.h"
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
	/*define admin addr here: ad_0*/
	adminService(&connfd, ad_0); 

	/*remove main.o*/
	unlink("main");

	/*return*/
	return 0;
}