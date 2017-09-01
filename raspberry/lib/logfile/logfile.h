/*
 *	Date	: 27/08/2017.
 *	Content	: 
 */
#ifndef LOGFILE_H_
#define LOGFILE_H_
/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../fileproc/fileproc.h"


/******************************************************************************
 *	Define
 *****************************************************************************/
#define LOGF_NUM		10
#define LOGF_LEN		1100


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Write information of login into file log system.
 */
void
writeLogFile
(char username[], char password[], bool result);

// void
// readLogFile
// ();


#endif /* LOGFILE_H_ */
