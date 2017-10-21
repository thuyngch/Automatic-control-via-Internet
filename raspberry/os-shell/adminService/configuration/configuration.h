#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_ 

/*built_in lib*/
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>  
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

/*private lib*/
#include "../../../lib/frame/frame.h"
// #include "../adminService.h"


void configuration(int *connfd, uint8_t addr, uint8_t fnc);

#endif