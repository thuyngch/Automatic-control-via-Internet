/*
 *	Date	: 26/08/2017.
 *	Content	: .
 */
#include "login.h"


/******************************************************************************
 *	Define
 *****************************************************************************/
/* Length of username and password */
#define ADMIN_LEN	256


/******************************************************************************
 *	Private
 *****************************************************************************/
/* Path of account-database */
static char path_account[] = "kernel/accounts/admin/";

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
	FILE *fp;
	int i;
	char 	tag_out[JSON_LEN][LOGIN_LEN],
			val_out[JSON_LEN][LOGIN_LEN];
	uint8_t num;

	/* Scan for username */
	bool isCorrect = false;
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
		/* Open the file matched with [username] */
		char *path = malloc(80);
		sprintf(path, "%s%s.acc", path_account, listfile[i]);
		if((fp = fopen(path, "r")) == NULL)
		{
			fprintf(stderr, "Cannot open file: %s\n", path);
			return 0;
		}
		free(path);

		/* Read content of file into a buffer */
		fseek(fp, 0, SEEK_END);
		uint32_t fsize = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		
		char *buffer = malloc(fsize + 1);
		fread(buffer, fsize, 1, fp);
		buffer[fsize] = 0;
		fclose(fp);

		/* Analyze the structure of JSON-file */
		json_t *root = load_json(buffer);
		free(buffer);
		print_json(root, tag_out, val_out, &num);
		json_decref(root);

		/* Compare the password */
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
void login(int *connfd, uint8_t num, uint8_t data[], uint8_t *num_out, uint8_t out[])
{
	fprintf(stderr, "\n%s\n", "> admin_login starting ...");
	
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
	fprintf(stderr, "username: %s\n", username);
	password[num-j-1] = 0;
	fprintf(stderr, "password: %s\n\n", password);

	/* Search for the result */
	int numfile = 0;
	char *listfile[ADMIN_LEN];

	char *path_adapt = malloc(70);
	pathAdapt(path_account, path_adapt);

	numfile = getListOfFile(path_adapt, extension, listfile);
	out[0] = (uint8_t)matching(username, password, path_adapt, numfile, listfile);
	*num_out = 1;

	/* Free cache */
	freeCache(listfile, numfile);
	free(path_adapt);

	/* Save information into [log_file] */
	// writeLogFile(username, password, out[0]);
}
//-----------------------------------------------------------------------------