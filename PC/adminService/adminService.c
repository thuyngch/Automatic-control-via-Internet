/************************************
* Date created: 	10-8-2017
* Date finished: 	
* Editor: Sublime Text 3
* Author: Le Van Hoang Phuong
* Description: 
*************************************/
#include 	"adminService.h"
#define 	ESC 		27

void disp_fnc_menu()
{
	fprintf(stderr, "\n%s\n", "[Admin Function List]");
	for (int i = 0; i < (int)(sizeof(fnc_menu)/sizeof(menu)); ++i)
	{
		fprintf(stderr, "{%s : %d}\n", fnc_menu[i].str, fnc_menu[i].fnc);
	}
	fprintf(stderr, "%s\n", "");
}

void print_frame(uint8_t frame[], uint8_t frame_size)
{
	fprintf(stderr, "\n%s", "frame: ");
	for (int i = 0; i < frame_size; ++i)
	{
		fprintf(stderr, "%d ", frame[i]);
	}
	fprintf(stderr, "%s\n", "");
}

uint8_t frame_len(uint8_t frame[])
{
	for (int i = 0; i < 128; ++i)
	{
		if ( (frame[i] == 0) && (frame[i+1] == 0) && (frame[i+2] == 0) ) return (uint8_t)i;
		break;
	}
}


void adminService(int *connfd, ad_addr_list addr)
{
	if(!admin_login(connfd, addr)) return;
	char readkey[8];
	int num_data_out;
	uint8_t data_out[8];
	uint8_t data_in[8];


	/*get fnc number, if ESC: exit*/
	while(disp_fnc_menu(), fprintf(stderr, "%s", "> which service: "), 
		fgets(readkey, 32, stdin), *readkey != ESC)
	{
		for (int i = 0; i < (int)(sizeof(admin_service_menu)/sizeof(admin_service_struct)); ++i)
		{
			if((uint8_t)(readkey[0] - 48) == admin_service_menu[i].fnc) 
			{
				data_in[0] = 0;
				frameEncode(addr, (uint8_t)(readkey[0] - 48), 1, data_in, &num_data_out, data_out);
				/*print frame to screen*/
				// print_frame(data_out, num_data_out);
				send(*connfd, data_out, num_data_out, 0);
				serveAdmin(connfd, i, addr, (uint8_t)(readkey[0] - 48));
					/*socket, serv_order, addr, fnc*/
				break;
			}
		}

	}
}

