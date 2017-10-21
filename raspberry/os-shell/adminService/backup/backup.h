#ifndef _BACKUP_H_
#define _BACKUP_H_ value


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>  
#include <stdbool.h> 
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "../../../lib/fileproc/fileproc.h"
#include "../../../lib/bufferproc/bufferproc.h"


void	backup(int *connfd, uint8_t addr, uint8_t fnc);

#endif
