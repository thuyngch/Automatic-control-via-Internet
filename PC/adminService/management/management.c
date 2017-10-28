/*************************************************************
*	Date Created: 	                              
*	Date finished:							 
*	Function:		
*	Input:		None 						 
*	Output:		Not defined yet				 
*************************************************************/

#include "management.h"

#define 	PATH_LEN 			128
#define 	BACKUP_BUFF_LEN 		64
static char account_folder_dir[] = "../raspberry/kernel/accounts/user/";

void sync_to_server(int *connfd, const char *account_folder_dir)
{
	fprintf(stderr, "%s\n", "> sync_to_server starting ...");
      uint8_t *buff;
      buff = (uint8_t*) malloc(BACKUP_BUFF_LEN);
      *buff = num_of_file_in_folder(account_folder_dir);   
      if (!buff[0]) exit(1);
      // fprintf(stderr, "%s : %d\n", "num of file", buff[0]);

      send(*connfd, buff, 1, 0);
      /*send file name and content of file in order*/
      struct dirent *dp;
	DIR *dir = opendir(account_folder_dir);

	if (dir == NULL) exit(1);
	while((dp = readdir(dir)) != NULL)
	{
		if (strcmp(dp -> d_name, ".") && strcmp(dp -> d_name, ".."))
		{
			strcpy(buff, dp -> d_name);
			// fprintf(stderr, "%s\n", buff);
			send(*connfd, buff, BACKUP_BUFF_LEN, 0);
			char path[PATH_LEN];
			strcpy(path, account_folder_dir);
			strcat(path, dp -> d_name);
			readallfile(path, buff);
			send(*connfd, buff, BACKUP_BUFF_LEN, 0);
		}
	}	
	closedir(dir);
	fprintf(stderr, "%s\n", "> sync_to_server finished");
}

void management(int *connfd, uint8_t addr, uint8_t fnc)
{
	backup(connfd, addr, fnc);
	char readkey[32];
	while(fprintf(stderr, "%s\n", "> managing done (yes/no)?"), fgets(readkey, sizeof(readkey), stdin), strcmp(readkey, "yes\n"));
	sync_to_server(connfd, account_folder_dir);
	
}
