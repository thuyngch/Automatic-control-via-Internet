#include "configuration.h"
#define 	CONFG_BUFF_LEN 	64

void configuration(int *connfd, uint8_t addr, uint8_t fnc)
{
	fprintf(stderr, "\n%s\n", "> Configuring server starting ...");
	/*recv result from server*/
	uint8_t data_in_out[CONFG_BUFF_LEN];
	recv(*connfd, data_in_out, 8, 0);

	/*decode frame into data_in_out*/
	uint8_t num_out, addr_out, fnc_out;
	for (int i = 0; i < CONFG_BUFF_LEN; ++i)
	{
		frameDecode(data_in_out[i], &addr_out, &fnc_out, &num_out, data_in_out);
	}

	fprintf(stderr, "[ RESULT : %d ]\n", data_in_out[0]);
	fprintf(stderr, "%s\n", "> Configuring server stopped ");
	exit(1);
}

