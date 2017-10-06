/*
 *	Date	: 01/09/2017.
 *	Content	: 
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include "communication.h"


/******************************************************************************
 *	Private
 *****************************************************************************/


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Function: 
 *
 *	Input	: 	
 *
 *	Output	:	
 */
int createServerSocket(int port, uint8_t numClient)
{
        /* Declare */
        int listenfd;
        struct sockaddr_in serv_addr; 

        /* Create a socket */
        listenfd = socket(AF_INET, SOCK_STREAM, 0);
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(port); 

        /* Server bind */
        bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 
        listen(listenfd, numClient);

        /* Return */
        return listenfd;
}


/******************************************************************************
 *  Function
 *****************************************************************************/
/*
 *  Function: create a client socket
 *
 *  Input   :   
 *
 *  Output  :   client socket file descriptor
 */
int createClientSocket(const char *ip, int port)
{
        int connfd;
        struct sockaddr_in client_addr; 

        /* Create a socket */
        connfd = socket(AF_INET, SOCK_STREAM, 0);
        client_addr.sin_family= AF_INET;
        client_addr.sin_addr.s_addr= inet_addr(ip);
        client_addr.sin_port= htons(port);
        /*require connection to server*/
        if(connect(connfd, (struct sockaddr*) &client_addr, sizeof(client_addr))) {perror("connection failed: ") ; exit(1);}
        fprintf(stderr, "%s\n", "You are connected to Server");

        /*return*/
        return connfd;
}


//-----------------------------------------------------------------------------
/*
 *	Function: 
 *
 *	Input	: 	
 *
 *	Output	:	
 */
int waitDataSocket(int listenfd, uint8_t *buffer, uint16_t len)
{
	/* Declare */
	int connfd;

	/* Wait for an available data package */
	connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

	/* Read data package into buffer */

	//read(connfd, buffer, len);adhifsdafjaldfjsdalfjlfjalfjdalfjflajsldfjaslfjadlfjadflj

	/* Return */
	return connfd;
}
//-----------------------------------------------------------------------------
/*
 *	Function: 
 *
 *	Input	: 	
 *
 *	Output	:	
 */
void sendDataSocket(int connfd, uint8_t *data, uint16_t len)
{
	write(connfd, data, len);
}
//-----------------------------------------------------------------------------
/*
 *	Function: 
 *
 *	Input	: 	
 *
 *	Output	:	
 */
void closeConnection(int connfd)
{
	close(connfd);
}
//-----------------------------------------------------------------------------
/*
 *  Function: 
 *
 *  Input   :   
 *
 *  Output  :   
 */
void getIPAddr(char *str)
{
    /* Declare */
    int fd;
    struct ifreq ifr;
    char iface[] = "wlp6s0";

    /* Get the IP address */
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name , iface , IFNAMSIZ-1);
    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);

    /* Save it into the output */
    sprintf(str,"%s",inet_ntoa(((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr));
}
//-----------------------------------------------------------------------------
/*
 *  Function: 
 *
 *  Input   :   
 *
 *  Output  :   
 */

//-----------------------------------------------------------------------------