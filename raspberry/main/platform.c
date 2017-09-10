/*************************************************************
*	Date Created: 26-8-2017						 *	
*	Date finished:							 *
*	Function:								 *
*	Input:		None 						 *
*	Output:		Not defined yet				 *
*************************************************************/

#include "platform.h"

void *platform(void *thread_exit)
{
	/*declare thread here*/
	pthread_t os_shell_thread;
	pthread_t embedded_shell_thread;

	/*create threads here*/
	if(createThread(&os_shell_thread, os_shell, thread_exit)) exit(1);
	if(createThread(&embedded_shell_thread, embedded_shell, thread_exit)) exit(1);

	/*cancel platform thread*/
	pthread_exit("Platform terminated");
}
