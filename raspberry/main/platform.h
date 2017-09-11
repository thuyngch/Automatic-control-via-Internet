#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdbool.h>

/*common private lib*/
#include "../lib/hplib/strproc.h"
#include "../lib/communication/communication.h"
// #include "../lib/json/json.h"
#include "../lib/platform/thread.h"
#include "../os-shell/os_shell.h"
#include "../embedded-shell/embedded_shell.h"
<<<<<<< HEAD
=======

>>>>>>> 83f486f8bdc12ca648a3a00c6881130a887e2ef6

/*
*	
*/
void *platform(void *thread_exit);

#endif