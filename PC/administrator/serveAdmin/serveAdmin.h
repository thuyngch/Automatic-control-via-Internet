#ifndef _SERVEADMIN_H_
#define _SERVEADMIN_H_


#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "../adminService/backup/backup.h"
#include "../adminService/management/management.h"
#include "../adminService/adminService.h"

#include "../../lib/fileproc/fileproc.h"
#include "../../lib/bufferproc/bufferproc.h"
#include "../../lib/frame/frame.h"


void serveAdmin(int *connfd, uint8_t serv_x, uint8_t addr, uint8_t func);

#endif