#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

typedef enum
{
	fnc_answer 		= 0,
	fnc_login 		= 1,
} t_fnc;

typedef struct 
{
	uint8_t		addr;
	t_fnc 		fnc;
	void		(*callback)(uint8_t);
} t_client_service;

void login(uint8_t num)
{
	fprintf(stderr, "%d\n", num);
	fprintf(stderr, "%s\n", "fnc_login started");
}

static t_client_service sClientService[] = {
	{0x01, fnc_login, login},
};


int main(int argc, char const *argv[])
{
	int num = 5;
	sClientService[0].callback(num);
	//login("hello HP");
	return 0;
}