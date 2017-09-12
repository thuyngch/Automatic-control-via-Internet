#ifndef EMBEDDED_SHELL_H_
#define EMBEDDED_SHELL_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "clientService/clientService.h"

#include "../lib/frame/frame.h"
#include "../lib/logfile/logfile.h"
#include "../lib/fileproc/fileproc.h"
//#include "../lib/json/json.h"
#include "../lib/communication/communication.h"
#include "../lib/platform/thread.h"
#include "../lib/bufferproc/bufferproc.h"

/*
*
*/
void *embedded_shell(void *thread_exit);


#endif