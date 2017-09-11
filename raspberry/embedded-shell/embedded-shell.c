/*
 *	Date	: 07/09/2017.
 *	Content	: 
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "embedded_shell.h"


/******************************************************************************
 *	Definition
 *****************************************************************************/
#define	EMBEDDED_BUFF_LEN			256
#define 	EMBEDDED_PORT 			8000
#define 	EMBEDDED_NUM_CLIENT		1


/******************************************************************************
 *	Function
 *****************************************************************************/
void clearBuffer(uint8_t *buff, uint16_t len)
{
	for (int i = 0; i < len; ++i)
		buff[i] = 0;
}


/******************************************************************************
 *	Main
 *****************************************************************************/
void *embedded_shell(void *thread_exit)
{
	/* Declare */
	uint8_t buff[EMBEDDED_BUFF_LEN];

	uint8_t addr, fnc, num;
	uint8_t data[EMBEDDED_BUFF_LEN];

	int listenfd, connfd;

	//-----------------------------------------------------------------------------
	/* Setup */
	listenfd = createServerSocket(EMBEDDED_PORT, EMBEDDED_NUM_CLIENT);
	getIPAddr(buff);
	printf(">>> Server is established:{IP: %s, Port: %d}\n\n", buff, EMBEDDED_PORT);
	clearBuffer(buff, EMBEDDED_BUFF_LEN);

//-----------------------------------------------------------------------------
	/* Wait for serving clients */
	while(1)
	{
		//-Get data-//
		connfd = waitDataSocket(listenfd, buff, EMBEDDED_BUFF_LEN);
		printf(">>> Received data: %s\n\n", buff);
		clearBuffer(buff, EMBEDDED_BUFF_LEN);

		//-Decode frame and serve for client-//
		// for(int i = 0; i < numRec; i++)
		// {
		// 	if(frameDecode(buff[i], &addr, &fnc, &num, data))
		// 	{
		// 		serveClient(addr, fnc, num, data);
		// 		break;
		// 	}
		// }

		//-Close the connection-//
		closeConnection(connfd);
	}
	exitThread(">>> embedded_shell exited ...");
}

