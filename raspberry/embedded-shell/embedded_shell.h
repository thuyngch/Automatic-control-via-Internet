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

/*
*
*/
void *embedded_shell(void *thread_exit);