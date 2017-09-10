#include "thread.h"

/*
*	FUNCTION: 	create a new thread
*	Input:	Thread, callback, return buffer
*	Output: 	Thread created
*/

bool 
createThread(pthread_t *thread,  void *(*start_routine) (void *), void *thread_exit)
{
	if(pthread_create(thread, NULL, start_routine, thread_exit)) return false;
	return true;
}

