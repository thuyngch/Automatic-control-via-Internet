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


/******************************************************************************
 *	Define
 *****************************************************************************/


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Create a new socket.
 */
int
createSocket
(char *ip, int port, uint8_t numClient);

/*
 *	Send data through a socket.
 */
bool
sendSocket
(int socket_id, uint8_t data, int numData);


#endif /* COMMUNICATION_H_ */

