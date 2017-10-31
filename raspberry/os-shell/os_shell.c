/************************************
* Date created: 	10-8-2017
* Date finished: 	
* Editor: Sublime Text 3
* Author: Le Van Hoang Phuong
* Description: 
*************************************/
#include "os_shell.h"

#define	OS_BUFF_LEN			256
#define 	OS_PORT 			9000
#define 	OS_NUM_CLIENT		1
#define 	numRec 			24

/******************************************************************************
 *	MAIN
 *****************************************************************************/
void *os_shell(void *thread_exit)
{
	fprintf(stderr, "%s\n", "-----------------------------------------------------------------");
	fprintf(stderr, "%s\n", "> OS Shell set up ...");
	/* Declare */
	uint8_t buff[OS_BUFF_LEN];
	uint8_t addr, fnc, num;
	uint8_t data[OS_BUFF_LEN];
	int listenfd; //server's listenning socket
	int connfd; //after client's connection accepted

	struct sockaddr_in client_addr;

	/* Setup */
	listenfd = createServerSocket(OS_PORT, OS_NUM_CLIENT);
	getIPAddr(buff);
	printf("> Server for admins is established on: {IP: %s, Port: %d}\n\n", buff, OS_PORT);
	clearBuffer(buff, OS_BUFF_LEN);

	while(1)
	{
		uint32_t clen = sizeof(client_addr);
		connfd = waitDataSocket(listenfd, buff, OS_BUFF_LEN);
		
		// Decode frame and serve for admin//
		for(int i = 0; i < numRec; i++)
		{
			if(frameDecode(buff[i], &addr, &fnc, &num, data))
			{
				serverService(&connfd, buff[2], num, data);				
				break;
			}
		}
		//Close the os-shell connection//
		closeConnection(connfd);
	}	
	/*cancel os-shell thread*/
	exitThread("> OS Shell exited ...");
}

