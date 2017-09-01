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


#endif /* FILEPROC_H_ */

