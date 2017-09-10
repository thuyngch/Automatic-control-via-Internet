#ifndef FILESYSTEM_H
#define FILESYSTEM_H

/*Include essential library*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <json/json.h>
#include <stdbool.h>
#include <dirent.h>

void readallfile(char *filedir, char *retstr);
// void json_parse(char *text, int *val_int,char *val_string);
void json_create( char *fold_dir, const char *extension, 
				  char *key_1, char *val_string_1, char *key_2,  char *val_string_2);
void createFolder(char *path);
bool createNewFile(char *folderpath, char *filename, const char *extension, const char *ifany_path);
bool isEmptyFolder(const char *folderDir);
bool emptyFolder(const char *folderDir);

#endif