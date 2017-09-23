/*
 *	Date	: 26/08/2017.
 *	Content	: Test the function of the [Frame] module.
 */
/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>

#include <string.h>

#include "frame.h"


/******************************************************************************
 *	Main
 *****************************************************************************/
int main(int argc, char *argv[])
{
	/* Declare */
	uint8_t input, addr, fnc, num_data, data[256];
	int num_out;

	/* Test the input arguments of main function */
	// printf("\nNumber of arguments: %d\n", argc);
	// for(int i=0; i<argc; i++)
	// {
	// 	printf("%s\n", argv[i]);
	// }

	/* Testbench */
	if(~strcmp(argv[1], "encode"))
	{
		/* Testbench of frameEncode */
		addr = argv[2][0] - '0';
		fnc = argv[3][0] - '0';
		num_data = argv[4][0] - '0';

		frameEncode(addr, fnc, num_data, argv[5], &num_out, data);
		
		printf("Number bytes of output frame: %d\n", num_out);
		for(int i = 0; i < num_out; i++)
			printf("%d ", data[i]);
		printf("\n");
	}

	else if(~strcmp(argv[1], "decode"))
	{
		/* Testbench of frameDecode */
		for(int count = 2; count < argc; count++)
		{
			input = argv[count][0] - '0';
			printf("%d, ", input);
			if(frameDecode(input, &addr, &fnc, &num_data, data))
			{
				printf("\n[Address]: %d\n", addr);
				printf("[function]: %d\n", fnc);
				printf("[numData]: %d\n", num_data);
				printf("[Data]: ");
				for(int i = 0; i < num_data; i++)
				printf("%c", data[i]+'0');
				printf("\n");
			}
		}
	}

	/* Return */
	return 0;
}

