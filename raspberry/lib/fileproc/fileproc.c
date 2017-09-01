/*
 *	Date	: 28/08/2017.
 *	Content	: 
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "fileproc.h"


/******************************************************************************
 *	Private
 *****************************************************************************/


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Function: 	Folder "raspberry" is refered as the home directory. Therefore,
 *				if paths that want to be correct, they must be adapted.
 *
 *	Input	: 	path 	: Original path.
 *
 *	Output	:	adapt 	: Adapted path.
 */
void pathAdapt(char *path, char *adapt)
{
	/* Get current directory */
	char cwd[256];
	getcwd(cwd, sizeof(cwd));

	/* Search for the relative position */
	char *rel_pos = strstr(cwd, "raspberry");
	int len = strlen(rel_pos);
	int pos = 0;
	for(int i = 0; i < len; i++)
		if((rel_pos[i] == '/') || (rel_pos[i] == '\\'))
			pos++;

	/* Adapt the path */
	adapt[0] = 0;
	for(int i = 0; i < pos; i++)
		strcat(adapt, "../");
	strcat(adapt, path);
}
//-----------------------------------------------------------------------------
/*
 *	Function: 	Find files with a specific extension in a directory.
 *
 *	Input	: 	path 		: Path of directory
 *				extension 	: The extension of files found.
 *
 *	Output	:	listname 	: Names of extension-matched files.
 */
int getListOfFile(char *path, char *extension, char **listname)
{
	/* Declare */
	int numfile = 0;
	int null_pos;
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	char cwd[256];

	/* Open folder and read files inside it */
	getcwd(cwd, sizeof(cwd));
	if((dp = opendir(path)) == NULL)
	{
		fprintf(stderr,"Cannot open directory: %s\n", path);
		return 0;
	}
	chdir(path);
	while((entry = readdir(dp)) != NULL)
	{
		if(entry->d_type == DT_REG)
		{
			char *ext = strrchr(entry->d_name,'.');
			if((!ext) || (ext == entry->d_name))
				continue;
			else
				if(strcmp(ext, extension) == 0)
				{
					listname[numfile] = malloc(strlen(entry->d_name) + 1);
					strcpy(listname[numfile], entry->d_name);
					null_pos = strlen(listname[numfile]) - strlen(extension);
					listname[numfile++][null_pos] = 0;
				}
		}
	}

	/* Return */
	closedir(dp);
	chdir(cwd);
	return numfile;
}
//-----------------------------------------------------------------------------
/*
 *	Function: 	Free dynamic string array with a number of bytes.
 *
 *	Input	: 	cache 	: String array.
 *
 *	Output	:	numel 	: Number of bytes.
 */
void freeCache(char **cache, int numel)
{
	for(int i = 0; i < numel; i++)
		free(cache[i]);
}
//-----------------------------------------------------------------------------
/*
 *	Function: 	Get size (bytes) of a file.
 *
 *	Input	: 	path 		: Path of file.
 *
 *	Output	:	(uint32_t)	: Number of bytes.
 */
uint32_t getSizeOfFile(char *path)
{
	FILE *fp = fopen(path, "r");
	fseek(fp, 0, SEEK_END);
	uint32_t filesz = ftell(fp);
	fclose(fp);
	return filesz;
}
//-----------------------------------------------------------------------------
/*
 *	Function: 	Create a new file in a directory.
 *
 *	Input	: 	path 	: Path of file.
 *
 *	Output	:	(bool)	: Successful or fail to create?
 */
bool createNewFile(char *path)
{
	FILE *fp = fopen(path, "w");
	if(fp == NULL)
	{
		fprintf(stderr, "Fail to create a new file!\n");
		return false;
	}
	fclose(fp);
	return true;
}
//-----------------------------------------------------------------------------
/*
 *	Function: 	Copy content from a source file to a destination file.
 *
 *	Input	: 	filedest	: Destination path.
 *				filesrc		: Source path.
 *
 *	Output	:	(void).
 */
void copyFile(char *filedest, char *filesrc)
{
	/* Declare */
	FILE *des, *src;
	char ch;

	/* Open files */
	des = fopen(filedest, "w");
	src = fopen(filesrc, "r");

	/* Copy content */
	while( ( ch = fgetc(src) ) != EOF )
		fputc(ch, des);

	/* Close files */
	fclose(des);
	fclose(src);
}
//-----------------------------------------------------------------------------
/*
 *	Function: 
 *
 *	Input	: 	
 *
 *	Output	:	
 */

//-----------------------------------------------------------------------------
/*
 *	Function: 
 *
 *	Input	: 	
 *
 *	Output	:	
 */

//-----------------------------------------------------------------------------