#include "management.h"
#define 	ADMIN_BUFF_LEN 			64
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
		fprintf(stderr, "%s\n", "> sync_form_PC failed"); 
		return;
	}
	uint8_t num_of_file = *buff;  //num of file in database

	/*create an empty folder on admin PC to store databases*/
	emptyFolder(account_folder_dir);	//remove all existing files in accounts/
	/*write info to each file*/
	for (int i = 0; i < num_of_file; ++i)
	{
		/*recv file name*/
		read(*connfd, buff, ADMIN_BUFF_LEN);
		// fprintf(stderr, "%s\n", buff);
		adaptPath(account_folder_dir, buff);
		FILE *file = fopen(buff, "w");
		/*recv content of file from PC*/
		read(*connfd, buff, ADMIN_BUFF_LEN);
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
	fprintf(stderr, "> database mng for ad[%d] starting ...\n", addr);
	backup(connfd, addr, fnc);
	sync_form_PC(connfd, account_folder_dir);
}
