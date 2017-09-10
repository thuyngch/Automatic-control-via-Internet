#include "filesystem.h"


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
*	FUNCTION: PARSING JSON STRUCTURE: ONLY 2 KEYs 								*
*	Input: text/document, return var: val_int & val_string 						*
*	Output: val_int, val_string											*
*	Additional requires: no												*
************************************************************************************************/
/*void json_parse(char *text, int *val_int,char *val_string) 
{
	json_object *jobj = json_tokener_parse(text); //divide text into tokens
	enum json_type type;
	void parse(json_object *jobj)
	{
		json_object_object_foreach(jobj, key, val) 
		{
			type = json_object_get_type(val);
			switch (type) 
			{
				case json_type_int: 	*val_int = json_object_get_int(val); break;
				case json_type_object: 	jobj = json_object_object_get_ex(jobj, key, NULL); parse(jobj); break; //recursive to browse objects
				case json_type_string: 	strcpy(val_string, json_object_get_string(val)); break;
				case json_type_array:	break;
				case json_type_null: 	break;
				case json_type_boolean: break;
				case json_type_double:  break;
			}
		}
	}
	parse(jobj);
}*/


/************************************************************************************************
*	FUNCTION: CREATE JSON STRUCTURE FILE									*
*	Input:  6 arguments													*
*	Output: json file 	 											*
*	Additional requires: 												*
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

	//fprintf(fjson, "%d", *val_int);
	//fputs("\n}", fjson);
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

bool emptyFolder(const char *folderDir)
{
	if (isEmptyFolder) return true;
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


