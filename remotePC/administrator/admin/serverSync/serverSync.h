#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "../../lib/fileproc/fileproc.h"
#include <stdbool.h>
#include "../../lib/platform/thread.h"

void serverSync(int *connfd);
void metadata_cache(const char *account_folder_dir, const char *cache_folder_dir);
