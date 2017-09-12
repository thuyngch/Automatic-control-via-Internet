#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <pthread.h>

#include "../lib/fileproc/fileproc.h"
#include "../lib/hplib/filesystem.h"
#include "../lib/communication/communication.h"
#include "./backup/backup.h"
#include "./adminService/adminService.h"
#include "./serveAdmin/serveAdmin.h"


int main(int argc, char const *argv[])
{
	int connfd;
	connfd = createClientSocket(argv[1], atoi(argv[2]));
	fprintf(stderr, "%d\n", connfd);
	adminService(&connfd);

	unlink("main");
	return 0;
}