#ifndef _MANAGEMENT_H_
#define _MANAGEMENT_H_ 

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include "../backup/backup.h"

void management(int *connfd, uint8_t addr, uint8_t fnc);

#endif