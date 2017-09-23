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
#define LOGF_LEN		11000


/******************************************************************************
 *	Function
 *****************************************************************************/
/*
 *	Write information of login into file log system.
 */
void
writeLogFile
(char username[], char password[], bool result);

/*
 *	Read information of login accesses from log file system.
 */
void
readLogFile
(uint8_t logfile_id);


#endif /* LOGFILE_H_ */
