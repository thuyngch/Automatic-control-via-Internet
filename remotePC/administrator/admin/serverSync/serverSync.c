#include "serverSync.h"
#define ACC_FILE_PATH_LEN		64
#define CACHE_FILE_PATH_LEN		64

void metadata_cache(const char *account_folder_dir, const char *cache_folder_dir)
{
	createFolder(cache_folder_dir);
	char cache_file_path[CACHE_FILE_PATH_LEN] = {};
	strcpy(cache_file_path, cache_folder_dir);
	strcat(cache_file_path, ".backup.cache");
	FILE *cache_file = fopen(cache_file_path, "w");

	struct dirent *dp;
	DIR *dir = opendir(account_folder_dir);
	if (dir == NULL) exit(1);
	while((dp = readdir(dir)) != NULL)
	{
		if (strcmp(dp -> d_name, ".") && strcmp(dp -> d_name, ".."))
		{
			char acc_file_path[ACC_FILE_PATH_LEN] = {};
			strcpy(acc_file_path, account_folder_dir);
			strcat(acc_file_path, dp->d_name);
			fprintf(cache_file, "%s", get_modify_time(acc_file_path));
			fflush(cache_file);
		}
	}
	fclose(cache_file);
}

void background_sync(int *connfd, bool *is_done)
{
	;
}	

void *foreground_sync(bool *is_done)
{
	fprintf(stderr, "%s\n", ">>> Done (yes/no) ?");
	char buff[8];
	fgets(buff, sizeof(buff), stdin);
	if (strcmp(buff, "no\n"))
	{
		*is_done = 1;
	}
	exitThread("foreground_sync exited");
}

void serverSync(int *connfd)
{
	bool is_done = 0;
	void *thread_exit;
	metadata_cache("../../../kernel/accounts/user/", "../../../kernel/accounts/.backup.cache/");
	background_sync(connfd, &is_done);

	pthread_t foreground_sync_thread;
	createThread(&foreground_sync_thread, foreground_sync, *is_done);
	pthread_join(foreground_sync_thread, thread_exit);	
}