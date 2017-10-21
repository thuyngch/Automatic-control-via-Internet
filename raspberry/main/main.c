/************************************
* Date created: 	6-8-2017
* Date finished: 	
* Editor: Sublime Text 3
* Author: Le Van Hoang Phuong
* Description: raspberry main program
*************************************/
#include <stdio.h>
#include <string.h>	
#include <stdlib.h>	
#include <stdbool.h>	//boolean
#include <dirent.h>  	//folder proc
#include <pthread.h> 	//multi-threads

/*common private lib*/
#include "../lib/fileproc/fileproc.h"
#include "../lib/communication/communication.h"
#include "../lib/frame/frame.h"
#include "../lib/json/json.h"
#include "../lib/platform/thread.h"
#include "../lib/bufferproc/bufferproc.h"

<<<<<<< HEAD
/*include platform for shells*/
=======
/*include platform for shell*/
>>>>>>> 54c690b6c141ea37d5ffcfb07b91188db302b08e
#include "platform.h"

/*include shell*/
#include "../os-shell/os_shell.h"
#include "../embedded-shell/embedded_shell.h"


int main(int argc, char const *argv[])
{
	/*platform thread: control os_shell_thread & embedded_shell_thread*/
	void *thread_exit; 		//message when thread cancelled
	pthread_t platform_thread; 	//declare thread name

	/*run platform in parallel with main*/
	/*this platform will run os_shell & embedded_shell*/
	if(!createThread(&platform_thread, platform, thread_exit)) exit(1);
	/*force main to hang to wait for platform exited first*/
	pthread_join(platform_thread, &thread_exit);

	/*print the result as platform exited*/
	fprintf(stderr, "%s\n", (char *)thread_exit);

	/*remove main.o*/
	unlink("main"); 

	/*return*/
	return 1;
}