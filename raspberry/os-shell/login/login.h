#ifndef _LOGIN_H_
#define _LOGIN_H_

/******************************************************************************
 *	Include
 *****************************************************************************/
#include <stdlib.h>

#include "../adminService/adminService.h"

#include <jansson.h>
#include "../../lib/json/json.h"

#include "../../lib/frame/frame.h"
#include "../../lib/logfile/logfile.h"
#include "../../lib/fileproc/fileproc.h"

/*declare*/
void 
login
(int *connfd, uint8_t num, uint8_t data[], uint8_t *num_out, uint8_t out[]);


#endif