/*
 *	Date	: 07/09/2017.
 *	Content	: 
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "embedded_shell.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "clientService/clientService.h"

#include "../lib/frame/frame.h"
#include "../lib/logfile/logfile.h"
#include "../lib/fileproc/fileproc.h"
#include "../lib/json/json.h"
#include "../lib/communication/communication.h"
#include "../lib/platform/thread.h"
#include "../lib/bufferproc/bufferproc.h"


/******************************************************************************
 *	Definition
 *****************************************************************************/
#define		EMBEDDED_BUFF_LEN			256
#define 	EMBEDDED_PORT 				8000
#define 	EMBEDDED_NUM_CLIENT			5



/******************************************************************************
 *	Main
 *****************************************************************************/
void *embedded_shell(void *thread_exit)
{
	fprintf(stderr, "%s\n", "--------------------------------------------------------------------------------");
	fprintf(stderr, "%s\n", "> Embedded_shell set up ...");
	
	/* Declare */
	uint8_t buff[EMBEDDED_BUFF_LEN];

	uint8_t addr, fnc, num;
	uint8_t data[EMBEDDED_BUFF_LEN];

	int listenfd, connfd;

	//-----------------------------------------------------------------------------
	/* Setup */
	listenfd = createServerSocket(EMBEDDED_PORT, EMBEDDED_NUM_CLIENT);
	getIPAddr(buff);
	printf(">>> Server for users is established on: {IP: %s, Port: %d}\n\n", buff, getPort(listenfd));
	clearBuffer(buff, EMBEDDED_BUFF_LEN);

	//-----------------------------------------------------------------------------
	/* Wait for serving clients */
	while(connfd = accept(listenfd, (struct sockaddr*)NULL, (socklen_t*)NULL))
	{
		printf("thuy\n");
		//-Get data-//
		read(connfd, buff, EMBEDDED_BUFF_LEN);
		puts(">");

		//-Decode frame and serve for client-//
		for(int i = 0; i < 20; i++)
		{
			if(frameDecode(buff[i], &addr, &fnc, &num, data))
			{
				serveClient(connfd, addr, fnc, num, data);
				break;
			}
		}

		//-Clear buffer-//
		clearBuffer(buff, EMBEDDED_BUFF_LEN);
	}
	exitThread(">>> embedded_shell exited ...");
}

