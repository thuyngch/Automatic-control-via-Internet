#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <pthread.h>

#include "../../lib/fileproc/fileproc.h"
#include "../../lib/hplib/filesystem.h"

void backup(int connfd);