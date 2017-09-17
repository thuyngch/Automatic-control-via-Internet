#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "serverSync.h"



#define NUM_ACC 		32
#define BUFF_LEN		64


int main(int argc, char const *argv[])
{
	int connfd = 2;
	serverSync(&connfd);
	fprintf(stderr, "%s\n", get_modify_time("test.c"));
	return 0;
}