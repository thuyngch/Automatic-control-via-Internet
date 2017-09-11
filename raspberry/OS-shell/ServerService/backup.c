/*************************************************************
*	Date Created: 26-8-2017	                               *	
*	Date finished:							 *
*	Function:		Backup data from a server to another *
*	Input:		None 						 *
*	Output:		Not defined yet				 *
*************************************************************/

#include "backup.h"
/*void clearBuffer(uint8_t *buff, uint16_t len)
{
	for (int i = 0; i < len; ++i)
		buff[i] = 0;
}*/

void	backup(int connfd)
{
      uint8_t *buff;
      buff = (uint8_t*) malloc(BACKUP_BUFF_LEN);
      char account_path[BACKUP_BUFF_LEN] = "../../kernel/accounts/user/";

      *buff = num_of_file_in_folder(account_path);
      if (!*buff) exit(1);
      write(connfd, buff, BACKUP_BUFF_LEN);

      /*send file name and content of file in order*/
      struct dirent *dp;
	DIR *dir = opendir(account_path);

	if (dir == NULL) exit(1);
	while((dp = readdir(dir)) != NULL)
	{
		if (strcmp(dp -> d_name, ".") && strcmp(dp -> d_name, ".."))
		{
			strcpy(buff, dp -> d_name);
			write(connfd, buff, BACKUP_BUFF_LEN);
			char path[BACKUP_BUFF_LEN] = {0};
			strcpy(path, account_path);
			strcat(path, dp -> d_name);
			clearBuffer(buff, strlen(buff));
			readallfile(path, buff);

			write(connfd, buff, BACKUP_BUFF_LEN);
		}
	}	
	closedir(dir);

}