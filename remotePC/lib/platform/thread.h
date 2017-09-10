#ifndef THREAD_H_
#define THREAD_H_

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

bool 
createThread(pthread_t *thread,  void *(*start_routine) (void *), void *thread_exit);

#endif