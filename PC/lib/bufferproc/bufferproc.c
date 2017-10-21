#include "bufferproc.h"

/************************************************************************************************
*	FUNCTION: CLEAR A BUFFER 										
*	Input: uint8_t buffer 											
*	Output: empty unint8_t buffer											
*	Additional requires: no												
************************************************************************************************/
void clearBuffer(uint8_t *buff, uint16_t len)
{
	for (int i = 0; i < len; ++i)
		buff[i] = 0;
}

/************************************************************************************************
*	FUNCTION: CLEAR A STRING VARIABLE 										
*	Input: string variable 												
*	Output: empty string												
*	Additional requires: no												
************************************************************************************************/
void clearstr(char *buf)
{int nochar = strlen(buf); for (int i = 0; i < nochar; i++) {buf[i] = '\0';}}


/************************************************************************************************
*	FUNCTION: REMOVE A PHRASE FROM A STRING									
*	Input: string															
*	Output: phrase-cut string											
*	Additional requires: no 											
************************************************************************************************/
void substr(char *str, const char *substr)
{for (int i = strlen(str)- strlen(substr); i < strlen(str); i++) { str[i] = '\0';}}


/************************************************************************************************
*	FUNCTION: REMOVE '\n' FROM stdin BUFFER									
*	Input: stdin													
*	Output: empty stdin buffer 											
*	Additional requires: no 											
************************************************************************************************/
void fflushstdin()
{char buf[8]; fgets(buf, sizeof(buf), stdin);}