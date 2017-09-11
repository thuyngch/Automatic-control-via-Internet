#include "thread.h"

/*
*	FUNCTION: 	create a new thread
*	Input:		Thread, callback, return buffer
*	Output: 	Thread created
*/

bool 
createThread(pthread_t *thread,  void *(*start_routine) (void *), void *thread_exit)
{
	if(pthread_create(thread, NULL, start_routine, thread_exit)) {perror("created thread failed: "); return false;}
	return true;
}

/*
*	FUNCTION: 	exit thread and return a message
*	Input:		const message
*	Output: 	cancel thread, message->thread_exit variable
*/
void exitThread(char const *message)
{
	pthread_exit((void*)message);
}

