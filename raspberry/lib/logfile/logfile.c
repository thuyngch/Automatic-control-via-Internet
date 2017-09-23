/*
 *	Date	: 27/08/2017.
 *	Content	: 
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "logfile.h"


/******************************************************************************
 *	Private
 *****************************************************************************/
/* Folder path */
static char path_history[] = "kernel/history/";

/* Prefix-name */
static char fname_prefix[] = "log";

/* Extension */
static char extension[] = ".log";

//-----------------------------------------------------------------------------
/*
 *	Function: 
 *
 *	Input	: 	
 *
 *	Output	:	
 */
static int getIDOfFile(char filename[])
{
	char num[3];
	strcpy(num, filename + strlen(fname_prefix));
	return atoi(num);
}
//-----------------------------------------------------------------------------
/*
 *	Function: 
 *
 *	Input	: 	
 *
 *	Output	:	
 */
static uint8_t findMax(uint8_t array[], uint8_t len, uint8_t *location)
{
	uint8_t maxVal = array[0];
	*location = 0;
	for(int i = 1; i < len; i++)
	{
	    if (array[i] > maxVal)
	    {
	       maxVal  = array[i];
	       *location = i;
	    }
	}
	return maxVal;
}
//-----------------------------------------------------------------------------
/*
 *	Function: 
 *
 *	Input	: 	
 *
 *	Output	:	
 */
static uint8_t getID4LogFile()
{
	/* Declare */
	uint8_t fileID;
	int numfile;
	char *listfile[LOGF_NUM];
	FILE *fp;
	char cwd[256];
	char filename[10];
	uint8_t *listID;
	uint8_t maxID, maxLoc;
	uint32_t filesz;

	/* Get simple information of log_file system */
	char *path_adapt = malloc(70);
	pathAdapt(path_history, path_adapt);
	numfile = getListOfFile(path_adapt, extension, listfile);
	getcwd(cwd, sizeof(cwd));
	chdir(path_adapt);
	free(path_adapt);

	/* Get ID for log_file */
	if(numfile)
	{
		/* Get list of ID corresponding to [listfile] */
		listID = malloc(numfile);
		for(int i = 0; i < numfile; i++)
			listID[i] = getIDOfFile(listfile[i]);

		/* Measure size of the file with [maxID] */
		maxID = findMax(listID, numfile, &maxLoc);
		free(listID);
		sprintf(filename, "%s%s", listfile[maxLoc], extension);
		filesz = getSizeOfFile(filename);

		/* Create a next new file */
		if((filesz > LOGF_LEN) && (maxID < LOGF_NUM))
		{
			sprintf(filename, "%s%.2d%s", fname_prefix, maxID+1, extension);
			createNewFile(filename);
			fileID = maxID+1;
		}

		/* Rearrange the log_file system and create a new file */
		else if ((filesz > LOGF_LEN) && (maxID == LOGF_NUM))
		{
			/* Copy backward files */
			char *filedest = malloc(10);
			for(int i = 0; i < numfile-1; i++)
			{
				sprintf(filedest, "%s%.2d%s", fname_prefix, i+1, extension);
				sprintf(filename, "%s%.2d%s", fname_prefix, i+2, extension);
				copyFile(filedest, filename);
			}
			free(filedest);

			/* Create new file */
			sprintf(filename, "%s%.2d%s", fname_prefix, maxID, extension);
			createNewFile(filename);
			fileID = maxID;
		}

		/* Use the file with [maxID] */
		else
			fileID = maxID;
	}
	else
	{
		/* Create a new file with label of "01" */
		sprintf(filename, "%s01%s", fname_prefix, extension);
		createNewFile(filename);
		fileID = 1;
	}

	/* Return */
	chdir(cwd);
	freeCache(listfile, numfile);
	return fileID;
}
//-----------------------------------------------------------------------------


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Function: 	Write information of login into file log system.
 *
 *	Input	: 	username	: Username of login.
 *				password	: Password of login.
 *				result 		: Result of login.
 *
 *	Output	:	(void).
 */
void writeLogFile(char username[], char password[], bool result)
{
	/* Declare */
	char buff[80];
	char filename[10];
	char cwd[256];
	time_t curtime;

	/* Get current time */
	curtime = time(NULL);
	strcpy(cwd, asctime(localtime(&curtime)));
	cwd[strlen(cwd)-1] = 0;
	sprintf(buff, "--- %s ---\n", cwd);

	/* Get ID for the file */
	uint8_t fileID = getID4LogFile();
	sprintf(filename, "%s%.2d%s", fname_prefix, fileID, extension);

	/* Write information into the file */
	getcwd(cwd, sizeof(cwd));

	char *path_adapt = malloc(70);
	pathAdapt(path_history, path_adapt);
	chdir(path_adapt);
	free(path_adapt);

	FILE *fp = fopen(filename, "a");
	fputs(buff, fp);
	sprintf(buff, "[\n\t{\"username\": \"%s\"},\n\t{\"password\": \"%s\"},\n",
														username, password);
	fputs(buff, fp);
	if(result)
		strcpy(buff, "\t{\"result\": \"true\"}\n]\n\n\n");
	else
		strcpy(buff, "\t{\"result\": \"false\"}\n]\n\n\n");
	fputs(buff, fp);
	
	fclose(fp);
	chdir(cwd);
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