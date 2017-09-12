#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>  
#include <stdbool.h> 
#include <stdlib.h>
#include <dirent.h>

#include "../../lib/fileproc/fileproc.h"
#include "../../embedded-shell/embedded_shell.h"

#define BACKUP_BUFF_LEN 256

void backup(int *connfd);

