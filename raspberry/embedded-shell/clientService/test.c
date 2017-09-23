/*
 *	Date	: 26/08/2017.
 *	Content	: 
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "clientService.h"

#include "../../lib/frame/frame.h"
#include "../../lib/logfile/logfile.h"
#include "../../lib/fileproc/fileproc.h"
#include "../../lib/json/json.h"


/******************************************************************************
 *	Main
 *****************************************************************************/
int main(int argc, char *argv[])
{
	/* Declare */
	uint8_t input, addr, fnc, num_data, data[256];
	uint8_t num_out, out[256];

	/* Test the input arguments of main function */
	// printf("\nNumber of arguments: %d\n", argc);
	// for(int i=0; i<argc; i++)
	// {
	// 	printf("%s\n", argv[i]);
	// }

	/* Receive input and decode it */
	// for(int i = 0; i < strlen(argv[1]); i++)
	// {
	// 	input = argv[1][i] - '0';
	// 	printf("%d, ", input);
	// 	if(frameDecode(input, &addr, &fnc, &num_data, data))
	// 	{
	// 		printf("\n[Address]: %d\n", addr);
	// 		printf("[function]: %d\n", fnc);
	// 		printf("[numData]: %d\n", num_data);
	// 		printf("[Data]: ");
	// 		for(int i = 0; i < num_data; i++)
	// 		printf("%c", data[i]+'0');
	// 		printf("\n");
	// 	}
	// }

	/* Test for [getListFile] */
	// char listname[256][11];
	// int numfile = getListFile("../accounts", listname);
	// printf("Number of files: %d\n", numfile);
	// for(int i = 0; i < numfile; i++)
	// 	printf("\t%s\n", listname[i]);

	/* Test for [JSON file] */
	// FILE *fp = fopen("../accounts/123.acc", "r");
	// fseek(fp, 0, SEEK_END);
	// uint32_t fsize = ftell(fp);
	// fseek(fp, 0, SEEK_SET);
	// char *buffer = malloc(fsize + 1);
	// fread(buffer, fsize, 1, fp);
	// buffer[fsize] = 0;
	// fclose(fp);

	// char key_out[10][11], val_out[10][11];
	// uint8_t num;
	// json_t *root = load_json(buffer);
	// if(root)
	// {
	// 	print_json(root, key_out, val_out, &num);
	// 	json_decref(root);
	// }
	// printf("Number of elements: %d\n", num);
	// for(int i = 0; i < num; i++)
	// 	printf("%s - %s\n", key_out[i], val_out[i]);

	/* Test for [cliserv_login] */
	// num_data = 7;
	// char usr[] = "234", pass[] = "234";
	// sprintf(data, "%s %s", usr, pass);
	// data[strlen(usr)] = '\0';
	// cliserv_login(num_data, data, &num_out, out);
	// for(int i = 0; i < num_out; i++)
	// 	printf("Matching result: %d ", out[i]);
	// printf("\n");

	/* Test [getListOfFile] */
	// char path[] = "../accounts/";
	// char *listfile[10];
	// int numfile = getListOfFile(path, ".acc", listfile);
	// printf("Number of files: %d\n", numfile);
	// for(int i = 0; i < numfile; i++)
	// 	printf("%s\n", listfile[i]);
	// freeCache(listfile, numfile);

	/* Test for [currTime] */
	// char buf[150];
	// time_t curtime;
	// struct tm *loc_time;
	// curtime = time(NULL);
	// loc_time = localtime (&curtime);
	// printf("%s", asctime (loc_time));

	/* Test for [serveClient] */
	num_data = 7;
	char usr[] = "123", pass[] = "234";
	sprintf(data, "%s %s", usr, pass);
	data[strlen(usr)] = '\0';
	serveClient(0x01, fnc_login, num_data, data);

	/* Return */
	return 0;
}

