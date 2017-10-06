#include "configuration.h"
#define 	CFG_OUT_LEN 	8

void configuration(int *connfd, uint8_t addr, uint8_t fnc)
{
	uint8_t *cfg_data_out = (uint8_t*) malloc(CFG_OUT_LEN);
	int num_data_out;
	uint8_t cfg_data_in = 1;
	fprintf(stderr, "> Configuring server for ad[%d] starting ...\n", addr);
	frameEncode(addr, 2, 1, &cfg_data_in, &num_data_out, cfg_data_out);

	/*in case connection crashed*/
	if(send(*connfd, cfg_data_out, num_data_out, 0) == -1) 
	{
		fprintf(stderr, "%s\n", "> Configuring server failed ...");
		return;
	}
	else
	{	fprintf(stderr, "> Server stopped by admin [%d]\n", addr);
		exit(1);
	}
}