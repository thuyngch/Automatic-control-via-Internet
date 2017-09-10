/*************************************************************
*	Date Created: 26-8-2017						 *	
*	Date finished:							 *
*	Function:								 *
*	Input:		None 						 *
*	Output:		Not defined yet				 *
*************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <json/json.h>
#include <stdbool.h>
#include <dirent.h>

/*common private lib*/
#include "../../lib/hplib/strproc.h"
#include "../../lib/hplib/filesystem.h"
#include "../../lib/fileproc/fileproc.h"
#include "../../lib/communication/communication.h"
#include "../../lib/frame/frame.h"
#include "../../lib/json/json.h"


int main(int argc, char const *argv[])
{
	int ssockfd = createSocket(atoi(argv[2]), 1);



	return 0;
}