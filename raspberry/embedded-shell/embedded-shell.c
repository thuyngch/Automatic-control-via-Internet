/*
 *	Date	: 07/09/2017.
 *	Content	: 
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
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


/******************************************************************************
 *	Definition
 *****************************************************************************/
#define		EMBEDDED_BUFF_LEN			255
#define 	EMBEDDED_PORT 				8000
#define 	EMBEDDED_NUM_CLIENT			5


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
int main(int argc, char *argv[])
{
/* Declare */
uint8_t buff[EMBEDDED_BUFF_LEN];

uint8_t addr, fnc, num;
uint8_t data[EMBEDDED_BUFF_LEN];

int listenfd, connfd;
int *new_sock;

//-----------------------------------------------------------------------------
/* Setup */
listenfd = createServerSocket(EMBEDDED_PORT, EMBEDDED_NUM_CLIENT);
getIPAddr(buff);
printf(">>> Server is established:{IP: %s, Port: %d}\n", buff, getPort(listenfd));
clearBuffer(buff, EMBEDDED_BUFF_LEN);

//-----------------------------------------------------------------------------
/* Wait for serving clients */
while(connfd = accept(listenfd, (struct sockaddr*)NULL, (socklen_t*)NULL))
{
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

//-----------------------------------------------------------------------------
/* Return */
return 0;
}

