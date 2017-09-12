#ifndef THREAD_H_
#define THREAD_H_

#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <errno.h>

/*
*
*/
bool createThread(pthread_t *thread,  void *(*start_routine) (void *), void *thread_exit);
/*
*
*/
void exitThread(char const *message);

/*
*
*/


#endif