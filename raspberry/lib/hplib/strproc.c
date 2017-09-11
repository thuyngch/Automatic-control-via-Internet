#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <stdint.h>
#include "strproc.h"


/************************************************************************************************
*	FUNCTION: CLEAR A STRING VARIABLE 										*
*	Input: string variable 												*
*	Output: empty string												*
*	Additional requires: no												*
************************************************************************************************/
void clearstr(char *buf)
{int nochar = strlen(buf); for (int i = 0; i < nochar; i++) {buf[i] = '\0';}}


/************************************************************************************************
*	FUNCTION: REMOVE A PHRASE FROM A STRING									*
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

