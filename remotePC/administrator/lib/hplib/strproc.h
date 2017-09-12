#ifndef STRPROC_H
#define STRPROC_H

/*Include essential library*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>

void clearstr(char *buf);
void substr(char *str, const char *substr);
void fflushstdin();

#endif