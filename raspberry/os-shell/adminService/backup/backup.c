/************************************
* Date created: 	10-8-2017
* Date finished: 	
* Editor: Sublime Text 3
* Author: Le Van Hoang Phuong
* Description: 
*************************************/

#include "backup.h"

#define  acc_folder_dir "../kernel/accounts/user/"
#define BACKUP_BUFF_LEN 128

void	backup(int *connfd, uint8_t addr, uint8_t fnc) 
{
	fprintf(stderr, "> backup service for ad [%d] starting ...\n", addr);
	const char account_folder_dir[128] = acc_folder_dir;
      uint8_t *buff = (uint8_t*) malloc(BACKUP_BUFF_LEN);

      /*get total number of files in /user*/
     	*buff = real_num_of_file(account_folder_dir);
      if (!buff[0]) return;
      /*send num of file in /user to PC*/
      if(send(*connfd, buff, 1, 0) == -1) return;

      /*send file name and content of file in order*/
      struct dirent *dp;
	DIR *dir = opendir(account_folder_dir);
	if (dir == NULL) return;

	while((dp = readdir(dir)) != NULL) //get file name by file name
	{
		strcpy(buff, dp ->d_name);
		if (strcmp(buff, ".") && strcmp(buff, "..") && (buff[0] != '.') && (buff[1] != 'f'))
		{
			/*send file name to PC*/
			send(*connfd, buff, BACKUP_BUFF_LEN, 0);

			/*create file path*/
			char path[BACKUP_BUFF_LEN];
			strcpy(path, account_folder_dir);
			strcat(path, dp -> d_name);
			/*read whole content of file*/
			readallfile(path, buff);
			/*send content to PC*/
			send(*connfd, buff, BACKUP_BUFF_LEN, 0);
		}
	}	
	free(buff);
	closedir(dir);
	fprintf(stderr, "%s\n", "> backup service finished");
}