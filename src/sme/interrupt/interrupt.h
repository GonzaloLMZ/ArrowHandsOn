#include "..\tasks\sme_controller.h"
/*
* interrupt.h
*
* Created: 08/01/2015 21:30:22
*  Author: smkk
*/


#ifndef INTERRUPT0_H_
#define INTERRUPT0_H_

void sme_init_isr_global(void);
void clearInt(eventE interrupt);


extern bool nurembergSent;
#endif /* INTERRUPT0_H_ */
