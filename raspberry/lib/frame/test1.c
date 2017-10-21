#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "frame.h"

int main(int argc, char const *argv[])
{
	uint8_t input, addr, fnc, num_data, data_in[256];
	int num_out;
	uint8_t data_out[256];
	num_data = 7;
	sprintf(data_in, "%s %s", "789", "987");
	data_in[3] = 0;


	for (int i = 0; i < num_data; ++i)
	{
		fprintf(stderr, "%d ", data_in[i]);
	}

	fprintf(stderr, "%s\n", "encoded");

	frameEncode(1,1,num_data, data_in, &num_out, data_out);
	//fprintf(stderr, "%s\n", data);
	for (int i = 0; i < num_data + 7; ++i)
	{
		fprintf(stderr, "%d ", data_out[i]);
	}

	for (int i = 0; i < 14; ++i)
	{
		frameDecode(data_out[i], &addr, &fnc, &num_data, data_in);
	}

	fprintf(stderr, "%s\n", "after decoded");
	for (int i = 0; i < 7; ++i)
	{
		fprintf(stderr, "%d ", data_in[i]);
	}

	return 0;
}