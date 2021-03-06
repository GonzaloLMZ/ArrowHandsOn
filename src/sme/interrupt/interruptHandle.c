/*
* interruptHandle.c
*
* Created: 1/21/2015 10:14:21 PM
*  Author: smkk
*/

#include "interruptHandle.h"
#include <stdint-gcc.h>
#include "..\Devices\I2C\IOExpander\tca6416a.h"
#include <stddef.h>
#include "extint.h"
#include "sme_pin_definition.h"
uint16_t portsValue;


// function pointer for the specific device interrupt handler function
//typedef void (*handleInt)(void); 

typedef int (*handleInt) (void* data, ...);

static handleInt isrFunct[MAX_EXTERN_INTERRUPT];


uint16_t interruptDetection(void) {
    uint16_t newValue;
    TCA6416a_input_ports_values(&newValue);
    
    uint16_t detection = newValue ^ portsValue;
    portsValue= newValue;

    // call a specific interrupt function if exists
    for(int i=0; i<MAX_EXTERN_INTERRUPT; i++) {
        if (detection & (1<<i)) {
        if (isrFunct[i] != NULL)
            isrFunct[i](NULL);
        }
    }

    //return the map of the interrupt detected
    return detection;
}

void interruptValueInitializzation(void) {
    TCA6416a_input_ports_values(&portsValue);
    // clear Interrupt
    extint_chan_clear_detected(SME_INT_IOEXT_EIC_LINE);
}

