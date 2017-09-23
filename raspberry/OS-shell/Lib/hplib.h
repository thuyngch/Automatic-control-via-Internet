#ifndef _HPLIB_H
#define _HPLIB_H

/*Include essential library*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include "hplib.c"


void readallfile(char *filedir, char *retstr);
void json_parse(char *text, int *val_int,char *val_string);
void clearstr(char *buf);
void substr(char *str, const char *substr);
void fflushstdin();
void json_create(char *fold_dir, char *key_1, char *key_2, char *val_string, int *val_int);

#endif