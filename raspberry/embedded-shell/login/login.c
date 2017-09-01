/*
 *	Date	: 26/08/2017.
 *	Content	: .
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "../clientService/clientService.h"

#include <jansson.h>
#include "../../lib/json/json.h"

#include "../../lib/frame/frame.h"
#include "../../lib/logfile/logfile.h"
#include "../../lib/fileproc/fileproc.h"


/******************************************************************************
 *	Define
 *****************************************************************************/
/* Length of username and password */
#define USER_LEN	256


/******************************************************************************
 *	Private
 *****************************************************************************/
/* Path of account-database */
static char path_account[] = "kernel/accounts/";

/* Extension */
static char extension[] = ".acc";

//-----------------------------------------------------------------------------
/*
 *	Function: 
 *
 *	Input	: 	
 *
 *	Output	:	
 */
static bool matching(char username[], char password[], char path_account[],
					 int numfile, char **listfile)
{
	/* Declare */
	bool isCorrect = false;
	FILE *fp;
	char path[80];
	int i;
	char key_out[JSON_LEN][LOGIN_LEN], val_out[JSON_LEN][LOGIN_LEN];
	uint8_t num;

	/* Scan for username */
	for(i = 0; i < numfile; i++)
	{
		if(!strcmp(username, listfile[i]))
		{
			isCorrect = true;
			break;
		}
	}

	/* Scan for password */
	if(isCorrect)
	{
		sprintf(path, "%s%s.acc", path_account, listfile[i]);
		if((fp = fopen(path, "r")) == NULL)
		{
			fprintf(stderr, "Cannot open file: %s\n", path);
			return 0;
		}

		fseek(fp, 0, SEEK_END);
		uint32_t fsize = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		
		char *buffer = malloc(fsize + 1);
		fread(buffer, fsize, 1, fp);
		buffer[fsize] = 0;
		fclose(fp);

		json_t *root = load_json(buffer);
		free(buffer);
		if(root)
		{
			print_json(root, key_out, val_out, &num);
			json_decref(root);
		}

		if(!strcmp(password, val_out[1]))
			isCorrect = true;
		else
			isCorrect = false;
	}

	/* Return */
	return isCorrect;
}
//-----------------------------------------------------------------------------


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Function: Service [Login].
 *
 *	Input	: 	
 *
 *	Output	:	
 */
void login(uint8_t num, uint8_t data[], uint8_t *num_out, uint8_t out[])
{
	/* Declare */
	char username[LOGIN_LEN], password[LOGIN_LEN];
	bool isUsrname = true;
	int j = 0;

	/* Get username and password */
	for(int i = 0; i < num; i++)
	{
		if(isUsrname && (data[i] !=  0))
			username[j++] = data[i];
		else
		{
			isUsrname = false;
			if(data[i] !=  0)
				password[i-j-1] = data[i];
		}
	}
	username[j] = 0;
	password[num-j-1] = 0;

	/* Search for the result */
	int numfile = 0;
	char *listfile[USER_LEN];

	char *path_adapt = malloc(70);
	pathAdapt(path_account, path_adapt);

	numfile = getListOfFile(path_adapt, extension, listfile);
	out[0] = (uint8_t)matching(username, password, path_adapt, numfile, listfile);
	*num_out = 1;

	/* Free cache */
	freeCache(listfile, numfile);
	free(path_adapt);

	/* Save information into [log_file] */
	writeLogFile(username, password, out[0]);
}
//-----------------------------------------------------------------------------