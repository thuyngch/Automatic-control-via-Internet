#ifndef _BACKUP_H_
#define _BACKUP_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "../../../raspberry/lib/fileproc/fileproc.h"
#include "../../../raspberry/lib/bufferproc/bufferproc.h"


void backup(int *connfd, uint8_t addr, uint8_t fnc);
void adaptPath(const char *rootPath, char *absolutePath);

#endif
