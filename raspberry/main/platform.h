#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdbool.h>

/*common private lib*/
#include "../lib/communication/communication.h"
// #include "../lib/json/json.h"
#include "../lib/platform/thread.h"
/*include shell*/
#include "../embedded-shell/embedded_shell.h"
#include "../os-shell/os_shell.h"

/*
*	
*/
void *platform(void *thread_exit);

#endif