#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <dirent.h>


bool isEmptyFolder(const char *folderDir)
{
	struct dirent *dp;
	DIR *dir = opendir(folderDir);
	if (dir == NULL) { return true; }

	int nof = 0;
	while((dp = readdir(dir)) != NULL) ++nof;
	closedir(dir);
	return (nof > 2) ? false : true;
}

uint8_t num_of_file_in_folder(const char *folderDir)
{
	if (isEmptyFolder(folderDir)) return 0;
	struct dirent *dp;
	DIR *dir = opendir(folderDir);
	if (dir == NULL) { return true; }
	uint8_t num_of_file;
	while((dp = readdir(dir)) != NULL)
	{
		if (strcmp(dp -> d_name, ".") && strcmp(dp -> d_name, "..")) num_of_file++;
	}	
	closedir(dir);
	return num_of_file;
}

int main(int argc, char const *argv[])
{
	char folderDir[64] = "./user/";
	fprintf(stderr, "%d\n",(uint8_t) num_of_file_in_folder(folderDir));


	return 0;
}