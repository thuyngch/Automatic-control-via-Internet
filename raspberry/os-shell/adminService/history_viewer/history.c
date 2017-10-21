#include "history.h"

#define  acc_folder_dir "../kernel/history/"
#define HIS_BUFF_LEN	4096

void history(int *connfd, uint8_t addr, uint8_t fnc)
{
	fprintf(stderr, "> history service for ad[%d] starting ...\n", addr);
	const char account_folder_dir[64] = acc_folder_dir;
      uint8_t *buff;
      buff = (uint8_t*) malloc(HIS_BUFF_LEN);
      /*get total number of files in /user*/
      *buff = num_of_file_in_folder(account_folder_dir);   
      if (!buff[0]) exit(1);
      /*send num of file in /user to PC*/
      if(send(*connfd, buff, 1, 0) == -1) return;

      /*send file name and content of file in order*/
      struct dirent *dp;
	DIR *dir = opendir(account_folder_dir);
	if (dir == NULL) exit(1);

	while((dp = readdir(dir)) != NULL) //get file name by file name
	{
		if (strcmp(dp -> d_name, ".") && strcmp(dp -> d_name, ".."))
		{
			/*send file name to PC*/
			strcpy(buff, dp -> d_name);
			fprintf(stderr, "%s\n", buff);
			send(*connfd, buff, HIS_BUFF_LEN, 0);

			/*create file path*/
			char path[HIS_BUFF_LEN];
			strcpy(path, account_folder_dir);
			strcat(path, dp -> d_name);
			/*read whole content of file*/
			readallfile(path, buff);
			/*send content to PC*/
			send(*connfd, buff, HIS_BUFF_LEN, 0);
		}
	}	
	closedir(dir);
	fprintf(stderr, "%s\n", "> history service finished");
}