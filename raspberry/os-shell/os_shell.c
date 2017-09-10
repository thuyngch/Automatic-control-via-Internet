#include "os_shell.h"

/*
*	FUNCTION: 	
*	Input:	
*	Output: 	
*/

#define	OS_BUFF_LEN			256
#define 	OS_PORT 			8000
#define 	OS_NUM_CLIENT		1


/******************************************************************************
 *	Function
 *****************************************************************************/
void clearBuffer(uint8_t *buff, uint16_t len)
{
	for (int i = 0; i < len; ++i) buff[i] = 0;
}


/******************************************************************************
 *	MAIN
 *****************************************************************************/
void 
*os_shell(void *thread_exit)
{
	/* Declare */
	uint8_t buff[OS_BUFF_LEN];
	uint8_t addr, fnc, num;
	uint8_t data[OS_BUFF_LEN];
	int listenfd; //server's listenning socket
	int connfd; //after client's connection accepted

	/* Setup */
	listenfd = createSocket(OS_PORT, OS_NUM_CLIENT);
	getIPAddr(buff);
	printf(">>> Server is established:{IP: %s, Port: %d}\n\n", buff, OS_PORT);
	clearBuffer(buff, OS_BUFF_LEN);

	while(1)
	{
		//-et data//
		connfd = waitDataSocket(listenfd, buff, EMBEDDED_BUFF_LEN);
		printf(">>> Received data: %s\n\n", buff);
		clearBuffer(buff, EMBEDDED_BUFF_LEN);

		//Decode frame and serve for admin//
		// for(int i = 0; i < numRec; i++)
		// {
		// 	if(frameDecode(buff[i], &addr, &fnc, &num, data))
		// 	{
		// 		serveClient(addr, fnc, num, data);
		// 		break;
		// 	}
		// }

		//Close the os-shell connection//
		closeConnection(connfd);
	}	
	/*cancel os-shell thread*/
	pthread_exit(">>> os_shell exited ...");
}

