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
	char *path;
	path = (char*) malloc(ACCOUNT_PATH_LEN);
	strcpy(path, rootPath);
	strcat(path, absolutePath);
	clearBuffer(absolutePath, (uint16_t) strlen(absolutePath));
	strcpy(absolutePath, path);
	free(path);
}


void backup(int *connfd)
{
	uint8_t *buff = (uint8_t*) malloc(ADMIN_BUFF_LEN);
	read(*connfd, buff, ADMIN_BUFF_LEN);
	//char buff[ADMIN_BUFF_LEN];
	//recv(*connfd, buff, ADMIN_BUFF_LEN, 0);
	
	uint8_t num_of_file = *buff;  //num of file in database
	fprintf(stderr, "num_of_file: %d\n", num_of_file);
	

	/*create an empty folder on admin PCto store databases*/
	char account_path[ACCOUNT_PATH_LEN] = "../../kernel/accounts/user/";
	emptyFolder(account_path);	//remove all existing files in accounts/

	/*write info to each file*/
	for (int i = 0; i < num_of_file; ++i)
	{
		read(*connfd, buff, ADMIN_BUFF_LEN);
		fprintf(stderr, "%s\n", buff);

		adaptPath(account_path, buff);
		FILE *file = fopen(buff, "w");
		read(*connfd, buff, ADMIN_BUFF_LEN);
		fprintf(stderr, "%s\n", buff);
		fputs(buff, file);
		fflush(file);
		fclose(file);
	}
	free(buff);
}