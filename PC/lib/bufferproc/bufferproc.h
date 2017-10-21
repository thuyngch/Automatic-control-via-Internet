#ifndef BUFFERPROC_H_
#define BUFFERPROC_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

/*
*	
*/
void clearBuffer(uint8_t *buff, uint16_t len);
/*
*	
*/
void clearstr(char *buf);
/*
*	
*/
void substr(char *str, const char *substr);
/*
*	
*/
void fflushstdin();
/*
*	
*/

#endif