#ifndef _ADMIN_LOGIN_H_
#define _ADMIN_LOGIN_H_

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include "../../../../lib/frame/frame.h"
#include "../../../../lib/bufferproc/bufferproc.h"

bool admin_login(int *connfd, uint8_t add);

#endif