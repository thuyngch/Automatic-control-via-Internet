/************************************
* Date created: 	10-8-2017
* Date finished: 	
* Editor: Sublime Text 3
* Author: Le Van Hoang Phuong
* Description: 
*************************************/
#include "admin_login.h"

#define INFO_LEN		16

bool admin_login(int *connfd, uint8_t addr)
{
	fprintf(stderr, "%s\n\n", "> admin_login starting ...");

	uint8_t usr[INFO_LEN], psw[INFO_LEN];
	fprintf(stderr, "%s", "> username: ");
	/*get username*/
	fgets(usr, INFO_LEN, stdin);
	fprintf(stderr, "%s", "> password: ");
	/*get password*/
	fgets(psw, INFO_LEN, stdin);

	uint8_t data_in[2*INFO_LEN + 7];
	uint8_t data_out[2*INFO_LEN + 7];
	int num_data_out, num_data_in;
	sprintf(data_in, "%s%s", usr, psw);

	num_data_in = strlen(usr) + strlen(psw) - 1;
	data_in[strlen(usr) - 1] = 0;
	data_in[num_data_in] = 0;

	/*print username-password*/
	// fprintf(stderr, "%s", "username-password:       ");
	// for (int i = 0; i < num_data_in; ++i)
	// {
	// 	fprintf(stderr, "%d ", data_in[i]);
	// }
	// fprintf(stderr, "%s\n", "");

	/*encode*/
	frameEncode(addr, 0, num_data_in, data_in, &num_data_out, data_out);

	/*print ecoded data*/
	// fprintf(stderr, "%s", "encoded frame: ");
	// for (int i = 0; i < num_data_out; ++i)
	// {
	// 	fprintf(stderr, "%d ", data_out[i]);
	// }
	// fprintf(stderr, "%s\n", "");

	/*send to server*/
	if(send(*connfd, data_out, num_data_out, 0) == -1) {perror("send failed: "); return 0;}

	/*recv result*/
	data_in[5] = 0;
	recv(*connfd, data_in, 8, 0);

	/*print result*/
	(data_in[5]) ? fprintf(stderr, "%s%d%s\n\n", "admin [", addr, "] login succeeded !"): fprintf(stderr, "%s\n\n", " [admin login failed !]");

	/*exit*/
	fprintf(stderr, "%s\n", "> admin_login finished ...");
	return (int)data_in[5];
}
