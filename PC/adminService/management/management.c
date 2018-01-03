/************************************
* Date created: 	10-8-2017
* Date finished: 	
* Editor: Sublime Text 3
* Author: Le Van Hoang Phuong
* Description: 
*************************************/
#include "management.h"

#define 	PATH_LEN 			128
#define 	BACKUP_BUFF_LEN 		128
static char account_folder_dir[] = "../raspberry/kernel/accounts/user/";

void sync_to_server(int *connfd, const char *account_folder_dir)
{
	fprintf(stderr, "%s\n", "> sync_to_server starting ...");
      uint8_t *buff;
      buff = (uint8_t*) malloc(BACKUP_BUFF_LEN);
      // *buff = num_of_file_in_folder(account_folder_dir);   
     	*buff = (uint8_t)real_num_of_file(account_folder_dir); //something wrong with this count function
     	fprintf(stderr, "%s : %d\n", "#file to sync", buff[0]);
      if (!buff[0]) return;
      send(*connfd, buff, BACKUP_BUFF_LEN, 0);
      /*send file name and content of file in order*/
      struct dirent *dp;
	DIR *dir = opendir(account_folder_dir);


	if (dir == NULL) return;
	while((dp = readdir(dir)) != NULL)
	{
		strcpy(buff, dp ->d_name);
		if (strcmp(dp -> d_name, ".") && strcmp(dp -> d_name, "..") && (buff[0] != '.') && (buff[1] != 'f'))
		{
			strcpy(buff, dp -> d_name);
			send(*connfd, buff, BACKUP_BUFF_LEN, 0);
			usleep(10000);
			char path[PATH_LEN];
			strcpy(path, account_folder_dir);			
			strcat(path, dp -> d_name);
			readallfile(path, buff);			
			send(*connfd, buff, BACKUP_BUFF_LEN, 0);

		}
	}	
	free(buff);
	closedir(dir);
	fprintf(stderr, "%s\n", "> sync_to_server finished");
}

void management(int *connfd, uint8_t addr, uint8_t fnc)
{
	backup(connfd, addr, fnc);
	char readkey[64];
	while(fprintf(stderr, "%s\n", "> managing done (yes/no)?"), fgets(readkey, sizeof(readkey), stdin), strcmp(readkey, "yes\n"));
	sync_to_server(connfd, account_folder_dir);
	
}
