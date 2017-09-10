#ifndef PLATFORM_H
#define PLATFORM_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <json/json.h>
#include <stdbool.h>
#include <dirent.h>

/*common private lib*/
#include "../lib/hplib/strproc.h"
#include "../lib/hplib/filesystem.h"
//#include "../../lib/fileproc/fileproc.h"
#include "../lib/communication/communication.h"
#include "../lib/frame/frame.h"
// #include "../lib/json/json.h"
#include "../os-shell/os_shell.h"
#include "../lib/platform/thread.h"

void *platform(void *thread_exit);

#endif