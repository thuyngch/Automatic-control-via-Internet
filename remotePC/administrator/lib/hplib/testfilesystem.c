#include <stdio.h>
#include "filesystem.h"
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char const *argv)
{
	/*char *path = "../database";
	createFolder(path);
	unlink("testcreateFolder");*/

	/**/
	/*char folderDir[128];
	strcpy(folderDir, "../../kernel/accounts/admins/");
	createFolder(folderDir);
	char *key_1 = "account";
	char *key_2 = "password";
	char *val_1 = "123";
	char *val_2 = "123";
	//strcat(folderDir, val_1);
	//strcat(folderDir, ".acc");
	fprintf(stderr, "%s\n", folderDir);
	//json_create(folderDir, ".acc", key_1, val_1, key_2, val_2);
	unlink("testfilesystem");
	rmdir("../../kernel/accounts/HP");*/


	/*char folderDir[64];
	strcpy(folderDir, "../");
	char *filename = "456";
	char *extension = ".acc";
	createNewFile(folderDir, filename, extension, filename);*/


	/*DIR *dir;
	struct dirent *dp;
	dir = opendir(".");
	while( (dp = readdir(dir)) != NULL) fprintf(stderr, "%s\n", dp-> d_name);
	closedir(dir);*/
	char path[64];
	strcpy(path, "./HP/");
	fprintf(stderr, "status: %d\n", isEmptyFolder(path));
	emptyFolder(path);

	unlink("testfilesystem");
	return 0;

}