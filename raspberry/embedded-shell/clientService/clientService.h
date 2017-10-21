/*
 *	Date	: 26/08/2017.
 *	Content	: 
 */
#ifndef CLIENTSERVICE_H_
#define CLIENTSERVICE_H_
/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "../../lib/frame/frame.h"
#include "../../lib/communication/communication.h"


/******************************************************************************
 *	Define
 *****************************************************************************/
/* Types of function of data */
typedef enum
{
	fnc_answer 		= 0,
	fnc_login 		= 1,
} t_fnc;

/* Client service */
typedef struct 
{
	uint8_t		addr;
	t_fnc 		fnc;
	void		(*callback)(uint8_t, uint8_t*, uint8_t*, uint8_t*);
							/*num  , data    , num_out , out*/
} t_client_service;


/******************************************************************************
 *	Function
 *****************************************************************************/
/* Client service */
void
serveClient
(int connfd, uint8_t addr, uint8_t fnc, uint8_t num, uint8_t data[]);

bool
verifyClientService
(uint8_t addr, uint8_t fnc, int num_serv, t_client_service sClientService[], int *serv_idx);

void
answerClient
(int connfd, uint8_t addr, uint8_t num, uint8_t data[]);


/* Service [Login]*/
void
embedded_login
(uint8_t num, uint8_t data[], uint8_t *num_out, uint8_t out[]);


#endif /* CLIENTSERVICE_H_ */