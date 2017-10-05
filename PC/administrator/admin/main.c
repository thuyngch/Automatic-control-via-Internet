#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <pthread.h>

#include "../../lib/fileproc/fileproc.h"
#include "../../lib/communication/communication.h"
#include "./adminService/backup/backup.h"
#include "./adminService/adminService.h"
#include "adminService/management/management.h"
#include "./serveAdmin/serveAdmin.h"


int main(int argc, char const *argv[])
{
	int connfd;
	connfd = createClientSocket(argv[1], atoi(argv[2]));	
	adminService(&connfd, ad_0); /*define admin addr here*/
	unlink("main");
	return 0;
}