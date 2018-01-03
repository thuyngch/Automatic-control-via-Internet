/************************************
* Date created: 	10-8-2017
* Date finished: 	
* Editor: Sublime Text 3
* Author: Le Van Hoang Phuong
* Description: 
*************************************/
#include "management.h"
#define 	ADMIN_BUFF_LEN 			128
#define 	ACCOUNT_PATH_LEN 			128

void adaptPath(const char *rootPath, char *absolutePath)
{
	char *path;
	path = (char*) malloc(ACCOUNT_PATH_LEN);
	strcpy(path, rootPath);
	strcat(path, absolutePath);
	clearBuffer(absolutePath, (uint16_t) strlen(absolutePath));
	strcpy(absolutePath, path);
	free(path);
}

void sync_form_PC(int *connfd, const char *account_folder_dir)
{

	fprintf(stderr, "%s\n", "> sync_form_PC starting ...");
	uint8_t *buff = (uint8_t*) malloc(ADMIN_BUFF_LEN);
	if(!recv(*connfd, buff, ADMIN_BUFF_LEN, 0))
	{
		fprintf(stderr, "%s\n", "> Backup from server failed");
		return;
	}	
	uint8_t num_of_file = *buff;  //num of file in database

	/*create an empty folder on admin PCto store databases*/
	emptyFolder(account_folder_dir);	//remove all existing files in accounts/

	/*write info to each file*/
	for (int i = 0; i < num_of_file; ++i)
	{
		/*file name*/
		if(!recv(*connfd, buff, ADMIN_BUFF_LEN, 0)) return;
		// fprintf(stderr, "%s\n", buff);

		/*create file path*/
		adaptPath(account_folder_dir, buff);
		FILE *file = fopen(buff, "w");
		recv(*connfd, buff, ADMIN_BUFF_LEN, 0);
		
		/*write content to file*/
		fputs(buff, file);
		fflush(file);
		fclose(file);
	}
	free(buff);
	fprintf(stderr, "%s\n", "> sync_form_PC succeeded");
}


void management(int *connfd, uint8_t addr, uint8_t fnc)
{
	const char account_folder_dir[] = "../kernel/accounts/user/";

	/*starting*/
	fprintf(stderr, "> database mng for ad [%d] starting ...\n", addr);
	backup(connfd, addr, fnc);
	sync_form_PC(connfd, account_folder_dir);
}
