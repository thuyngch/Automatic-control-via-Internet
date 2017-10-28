#ifndef _MANAGEMENT_H_
#define _MANAGEMENT_H_ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "../backup/backup.h"

void management(int *connfd, uint8_t addr, uint8_t fnc);
void sync_to_server(int *connfd, const char *account_folder_dir);


#endif