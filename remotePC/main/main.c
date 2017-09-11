#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <pthread.h> //multi-threads


/*common private lib*/
//#include "../lib/hplib/strproc.h"
#include "../lib/hplib/filesystem.h"
// #include "../lib/fileproc/fileproc.h"
#include "../lib/communication/communication.h"
//#include "../lib/frame/frame.h"
// #include "../lib/json/json.h"
#include "../lib/platform/thread.h"
#include "../os-shell/os_shell.h"
#include "platform.h"


int main(int argc, char const *argv[])
{
	/*platform thread: control os_shell_thread & embedded_shell_thread*/
	void *thread_exit; 		//message when thread cancelled
	pthread_t platform_thread; 	//declare thread name

	if(!createThread(&platform_thread, platform, thread_exit)) exit(1);
	pthread_join(platform_thread, &thread_exit);
	fprintf(stderr, "%s\n", (char *) thread_exit);

	unlink("main"); 			//remove main.o
	return 1;
}