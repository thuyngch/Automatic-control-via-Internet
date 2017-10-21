#ifndef OS_SHELL_H_
#define OS_SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
//#include <json/json.h>
#include <stdbool.h>
#include <dirent.h>
#include <pthread.h> //multi-threads

/*common private lib*/
#include "../lib/fileproc/fileproc.h"
#include "../lib/frame/frame.h"
#include "../lib/platform/thread.h"
#include "../lib/communication/communication.h"
#include "../lib/bufferproc/bufferproc.h"

#include "./adminService/management/management.h"
#include "./adminService/backup/backup.h"
#include "adminService/adminService.h"


/*
* os-shell
*/
void *os_shell(void *thread_exit);

#endif