#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <stdint.h>


/************************************************************************************************
*	FUNCTION: READ ALL CONTENTS OF A FILE 											*
*	Input: File dir, char pointer to store content of file 						*
*	Output: content of file 											*
************************************************************************************************/
void readallfile(char *filedir, char *retstr)
{
	char *text[128]; 
	strcpy(retstr, ""); // init "" to make sure strcat work properly
	FILE *file = fopen(filedir, "r");
	while (fgets(text, sizeof(text), file) != NULL) strcat(retstr, text);
}

/************************************************************************************************
*	FUNCTION: PARSING JSON STRUCTURE: ONLY 2 KEYs 								*
*	Input: text/document, return var: val_int & val_string 							*
*	Output: val_int, val_string											*
*	Additional requires: no				*
************************************************************************************************/
void json_parse(char *text, int *val_int,char *val_string) 
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
				case json_type_object: 	jobj = json_object_object_get(jobj, key); parse(jobj); break; //recursive to browse objects
				case json_type_string: 	strcpy(val_string, json_object_get_string(val)); break;
				case json_type_array:	break;
				case json_type_null: 	break;
				case json_type_boolean: break;
				case json_type_double:  break;
			}
		}
	}
	parse(jobj);
}


/************************************************************************************************
*	FUNCTION: CLEAR A STRING VARIABLE 											*
*	Input: string variable 												*
*	Output: empty string												*
*	Additional requires: no												*
************************************************************************************************/
void clearstr(char *buf)
{int nochar = strlen(buf); for (int i = 0; i < nochar; i++) {buf[i] = '\0';}}


/************************************************************************************************
*	FUNCTION: REMOVE A PHRASE FROM A STRING											*
*	Input: string													*		
*	Output: phrase-cut string											*
*	Additional requires: no 											*
************************************************************************************************/
void substr(char *str, const char *substr)
{for (int i = strlen(str)- strlen(substr); i < strlen(str); i++) { str[i] = '\0';}}


/************************************************************************************************
*	FUNCTION: REMOVE '\n' FROM stdin BUFFER									*
*	Input: stdin													*
*	Output: empty stdin buffer 											*
*	Additional requires: no 											*
************************************************************************************************/
void fflushstdin()
{char buf[8]; fgets(buf, sizeof(buf), stdin);}


/************************************************************************************************
*	FUNCTION: REMOVE '\n' FROM stdin BUFFER									*
*	Input: stdin													*
*	Output: empty stdin buffer 											*
*	Additional requires: 												*
************************************************************************************************/
void json_create(char *fold_dir, char *key_1, char *key_2, char *val_string, int *val_int)
{
	strcat(fold_dir, val_string); 
	FILE *fjson =  fopen(fold_dir, "w");

	char text[128] = ""; 
	strcat(text, "{\n      \""); strcat(text, key_1); strcat(text, "\": \""); strcat(text, val_string);
	strcat(text, "\"\n      \""); strcat(text, key_2); strcat(text, "\": ");
	fputs(text, fjson);
	fflush(fjson);

	fprintf(fjson, "%d", *val_int);
	fputs("\n}", fjson);
	fflush(fjson);
}