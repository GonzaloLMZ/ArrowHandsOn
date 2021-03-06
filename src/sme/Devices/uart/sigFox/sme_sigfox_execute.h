/*
* sme_sigfox_execute.h
*
* Created: 12/01/2015 20:43:40
*  Author: smkk
*
* This the file that execute  the command on sigfox component according with
* the information are present on the sigFoxT structure
*/


#ifndef SME_SIGFOX_EXECUTE_H_
#define SME_SIGFOX_EXECUTE_H_
#include <stdbool.h>
#include "../../../model/sme_model_sigfox.h"


bool executeCDCSigFox(const sigFoxT *msg);
#endif /* SME_SIGFOX_EXECUTE_H_ */
