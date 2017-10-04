/******************************************************************************
 *	Author		: Thuy Nguyen-Chinh
 *	Date		: dd MM yyyy
 *
 *	IDE			: xxxxx
 *
 *	Description	: xxxxxxxxxx
 *
 *	Input		: xxxxx
 *	Output		: xxxxx
 *****************************************************************************/
#include "account.h"

int main(int argc, char const *argv[])
{
	/* Declare */
	char usrname[] = "642751";

	/* Check the validity */
	if(accPreCheck(usrname))
		printf("%s\n", "\r\n>>> Correct value\r\n");
	else
		printf("%s\n", "\r\n>>> Wrong value\r\n");

	/* Return */
	return 0;
}