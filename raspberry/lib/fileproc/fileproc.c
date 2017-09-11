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

/************************************************************************************************
*	FUNCTION: READ ALL CONTENTS OF A FILE 									*
*	Input: File dir, char pointer to store content of file 						*
*	Output: content of file 											*
************************************************************************************************/
void readallfile(char *filedir, char *retstr)
{
	char text[128]; 
	strcpy(retstr, ""); // init "" to make sure strcat work properly
	FILE *file = fopen(filedir, "r");
	while (fgets(text, sizeof(text), file) != NULL) strcat(retstr, text);
}


/************************************************************************************************
*	FUNCTION: CREATE JSON STRUCTURE FILE									
*	Input:  6 arguments												
*	Output: json file 	 											
*	Additional requires: 												
************************************************************************************************/
void json_create(char *fold_dir, const char *extension, char *key_1, char *val_string_1,
			char *key_2,  char *val_string_2)
			//("exampledir", ".acc", "account", "123", "password", "123")
{
	char *path;
	strcpy(path, fold_dir);
	strcat(path, val_string_1); 
	strcat(path, extension);
	FILE *fjson =  fopen(path, "w"); //create username_extension

	char text[128] = ""; 
	strcat(text, "{\n      \""); 
	strcat(text, key_1); 
	strcat(text, "\": \""); 
	strcat(text, val_string_1);
	strcat(text, "\",\n      \""); 
	strcat(text, key_2); 
	strcat(text, "\": \"");
	strcat(text, val_string_2);
	strcat(text, "\"\n}");
	fputs(text, fjson);

	fflush(fjson);
}


/************************************************************************************************
*	FUNCTION: CREATE A NEW EMPTY FOLDER											*
*	Input: folder dir													*
*	Output: a folder if it's not existed									*
*	Additional requires: 												*
************************************************************************************************/
void createFolder(char *path)
{
	struct stat folinfo;
	if ( stat(path, &folinfo) == -1 ) { mkdir(path, 0700); }
}

bool createNewFile(char *folderpath, char *filename, const char *extension, const char *ifany_path)
{
	switch (*ifany_path)
	{
		case 0:
		{
			char path[64];
			strcpy(path, folderpath);
			strcat(path, filename);
			strcat(path, extension);
			FILE *fNew = fopen(path, "w");
			if (fNew) { fclose(fNew); return true; }
			fclose(fNew);
			return false;
			break;
		}
		default:
		{
			FILE *fNew = fopen(ifany_path, "w");
			if (fNew) { fclose(fNew); return true; }
			fclose(fNew);
			return false;
		}
	}
}

/************************************************************************************************
*	FUNCTION: 									
*	Input:  												
*	Output: 	 											
*	Additional requires: 												
************************************************************************************************/
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

/************************************************************************************************
*	FUNCTION: 									
*	Input:  												
*	Output: 	 											
*	Additional requires: 												
************************************************************************************************/
bool emptyFolder(const char *folderDir)
{
	if (isEmptyFolder(folderDir)) return true;
	struct dirent *dp;
	DIR *dir = opendir(folderDir);
	if (dir == NULL) { return true; }
	while((dp = readdir(dir)) != NULL)
	{
		if (strcmp(dp -> d_name, ".") && strcmp(dp -> d_name, ".."))
		{
			char filepath[64];
			strcpy(filepath, folderDir);
			strcat(filepath, dp -> d_name);
			fprintf(stderr, "%s\n", filepath);
			unlink(filepath);
		}
	}	
	closedir(dir);
	return true;
}

/************************************************************************************************
*	FUNCTION: 									
*	Input:  												
*	Output: 	 											
*	Additional requires: 												
************************************************************************************************/
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