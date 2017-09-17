/*
 *	Date	: 28/08/2017.
 *	Content	: 
 */
#ifndef FILEPROC_H_
#define FILEPROC_H_
/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#include <time.h>


/******************************************************************************
 *	Define
 *****************************************************************************/


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Folder "raspberry" is refered as the home directory. Therefore, if path
 *	that wants to be correct, it must be adapted.
 */
void
pathAdapt
(char *path, char *adapt);

/*
 *	Find files with a specific extension in a directory.
 */
int
getListOfFile
(char *path, char *extension, char **listname);

/*
 *	Free dynamic string array with a number of bytes.
 */
void
freeCache
(char **cache, int numel);

/*
 *	Get size (bytes) of a file.
 */
uint32_t
getSizeOfFile
(char *path);

/*
 *	Create a new file in a directory.
 */
bool
createNewFile
(char *path);

/*
 *	Copy content from a source file to a destination file.
 */
void
copyFile
(char *filedest, char *filesrc);


void readallfile(char *filedir, char *retstr);
/*
 *	
 */
void json_create( char *fold_dir, const char *extension, 
				  char *key_1, char *val_string_1, char *key_2,  char *val_string_2);
/*
 *	
 */
void createFolder(const char *path);
/*
 *	
 */
bool isEmptyFolder(const char *folderDir);
/*
 *	
 */
bool emptyFolder(const char *folderDir);
/*
 *	
 */
uint8_t num_of_file_in_folder(const char *folderDir);
/*
 *	
 */
bool createNewFile_2_mode
(char *folderpath, char *filename, const char *extension, const char *ifany_path);

 /*
 *	
 */
char* get_modify_time (const char *filepath);

#endif /* FILEPROC_H_ */

