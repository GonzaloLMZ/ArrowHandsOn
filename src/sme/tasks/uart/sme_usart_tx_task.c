/*
* sme_usart_tx_task.c
*
* Created: 10/01/2015 18:46:40
*  Author: mfontane
*/
#include "sme_usart_tx_task.h"
#include "samd21_xplained_pro.h"
#include "port.h"
#include "sme_cmn.h"
#include "sme\Devices\uart\sigFox\sme_sigfox_usart.h"
#include "sme\Devices\uart\sigFox\sme_sigfox_execute.h"
#include "sme\model\sme_model_sigfox.h"
#include "sme\Devices\uart\gps\sme_sl868v2_execute.h"

#define USART_TASK_DELAY     (1000 / portTICK_RATE_MS)

#define USART_TASK_NAME (const char *)"USART"
#define USART_STACK_SIZE (configMINIMAL_STACK_SIZE*2)
#define USART_TASK_PRIORITY  (tskIDLE_PRIORITY + 1)

xQueueHandle usartCommandQueue;

static void usartTxTask(void *params){
	usartQueueS current_message;
	for (;;) {

		if (xQueueReceive(usartCommandQueue, &current_message, USART_TASK_DELAY)) {
			switch (current_message.code){
				
				case sigFox:
				executeCDCSigFox(current_message.componentStruct);				
				break;

				case gps:
					executeSl868v2(current_message.componentStruct);
				break;			
				default:
				    print_err("Wrong USART msg code: %d\n", current_message.code);
				break;
			}
		}
	}
}

BaseType_t sme_usart_init(void){
	
	sigFoxInit();
    initSigFoxModel();
	
	// create the USART Queue
	usartCommandQueue = xQueueCreate(64, sizeof(usartQueueS));
	
	// create the USART Task
	return xTaskCreate(usartTxTask,
	USART_TASK_NAME,
	USART_STACK_SIZE,
	NULL,
	USART_TASK_PRIORITY,
	NULL);
}