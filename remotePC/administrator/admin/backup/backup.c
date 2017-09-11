#include "backup.h"

#define ADMIN_BUFF_LEN 		256
#define ACCOUNT_PATH_LEN 	128

void clearBuffer(uint8_t *buff, uint16_t len)
{
	for (int i = 0; i < len; ++i)
		buff[i] = 0;
}

void adaptPath(char *rootPath, char *absolutePath)
{
	strcat(rootPath, absolutePath);
	clearBuffer(absolutePath, (uint16_t) strlen(absolutePath));
	strcpy(absolutePath, rootPath);
}


void backup(int connfd)
{
	uint8_t *buff = (uint8_t*) malloc(ADMIN_BUFF_LEN);
	read(connfd, buff, ADMIN_BUFF_LEN);

	
	uint8_t num_of_file = *buff;  //num of file in database

	// /*shift left one byte*/
	// for (int i = 0; i < strlen(buff) - 1; ++i)
	// {
	// 	buff[i] = buff[i+1];
	// 	if (i == (strlen(buff) - 2)) buff[strlen(buff)-1] = 0;
	// }

	/*create an empty folder on admin PCto store databases*/
	char account_path[ACCOUNT_PATH_LEN] = "../../kernel/accounts/user/";
	emptyFolder(account_path);	//remove all existing files in accounts/

	/*write info to each file*/
	for (int i = 0; i < num_of_file; ++i)
	{
		read(connfd, buff, ADMIN_BUFF_LEN);
		adaptPath(account_path, buff);
		FILE *file = fopen(buff, "w");
		read(connfd, buff, ADMIN_BUFF_LEN);
		fputs(buff, file);
		fflush(file);
		free(buff);
	}
}