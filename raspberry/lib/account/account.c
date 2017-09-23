/*
 *	Date	: 10/09/2017.
 *	Content	: .
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "account.h"


/******************************************************************************
 *	Definition
 *****************************************************************************/
#define		ADMIN_NUM		1


/******************************************************************************
 *	Private
 *****************************************************************************/
/* Path of account-database */
static char path_account[] = "kernel/accounts/admin/";

/* Extension of account file */
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
 *	Function:
 *
 *	Input	: 	
 *
 *	Output	:	
 */
bool compareAdminAccount(char *usr, char *pass)
{
	/* Declare */
	int numfile = 0;
	char *listfile[ADMIN_NUM];
	bool ret;

	/* Adapt path */
	char *path_adapt = malloc(70);
	pathAdapt(path_account, path_adapt);

	/* Compare */
	numfile = getListOfFile(path_adapt, extension, listfile);
	ret = matching(usr, pass, path_adapt, numfile, listfile);

	/* Free cache */
	freeCache(listfile, numfile);
	free(path_adapt);

	/* Return */
	return ret;
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