/*
 *	Date	: 01/09/2017.
 *	Content	: 
 */
#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_
/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>


/******************************************************************************
 *	Define
 *****************************************************************************/


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Create a new socket.
 */
int createServerSocket(int port, uint8_t numClient);

/*
 *	Wait for reading a data package.
 */
int waitDataSocket(int listenfd, uint8_t *buffer, uint16_t len);

/*
 *	Send data through a socket.
 */
void sendDataSocket(int connfd, uint8_t *data, uint16_t len);

/*
 *	Close a connection (not close the socket).
 */
void closeConnection(int connfd);

/*
 *	Get IP address of socket.
 */
void getIPAddr(char *str);


#endif /* COMMUNICATION_H_ */

