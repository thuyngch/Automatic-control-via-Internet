#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>  
#include <stdbool.h> 
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "../../../lib/frame/frame.h"

void configuration(int *connfd, uint8_t addr, uint8_t fnc);

#endif