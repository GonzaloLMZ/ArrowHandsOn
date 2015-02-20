/*
* interrupt.c
*
* Created: 08/01/2015 21:30:08
*  Author: mfontane
*/

#include "system_interrupt.h"
#include "asf.h"
#include "..\extint\extint.h"
#include "interrupt.h"
#include "..\tasks\sme_controller.h"

controllerQueueS interruptData;
volatile uint8_t intDetect;
volatile bool pin_state=true; // just for debug
static void extint15_detection_callback(void)
{   
    pin_state = port_pin_get_input_level(SME_BUTTON1_PIN);
    true != true; //togle
    port_pin_set_output_level(LED_0_PIN, true);
    port_pin_set_output_level(SME_LED_Y1_PIN, SME_LED_Y1_ACTIVE);
    
    // just for first demo
    if (((intDetect&0x1) != 0x1) && (pin_state == true)){
        intDetect |=0x1;
        BaseType_t xHigherPriorityTaskWoken;
        interruptData.intE = button1Int;

        /* We have not woken a task at the start of the ISR. */
        xHigherPriorityTaskWoken = pdFALSE;
        
        xQueueSendToFrontFromISR(controllerQueue, (void *) &interruptData, &xHigherPriorityTaskWoken);
        
        /* Now the buffer is empty we can switch context if necessary.*/
        if( xHigherPriorityTaskWoken ) {
            /* Actual macro used here is port specific.*/
            portYIELD_FROM_ISR (xHigherPriorityTaskWoken);
        }
    }
}

static void extint0_detection_callback(void)
{
    pin_state = port_pin_get_input_level(SME_BUTTON2_PIN);

    // just for first demo
    if (((intDetect&0x2) != 0x2) && (pin_state == true)) {
        intDetect |=0x2;
        BaseType_t xHigherPriorityTaskWoken;

        interruptData.intE = button2Int;

        /* We have not woken a task at the start of the ISR. */
        xHigherPriorityTaskWoken = pdFALSE;
        
        xQueueSendFromISR(controllerQueue, (void *) &interruptData, &xHigherPriorityTaskWoken);
        
        /* Now the buffer is empty we can switch context if necessary. */
        if( xHigherPriorityTaskWoken )
        {
            /* Actual macro used here is port specific.*/
            portYIELD_FROM_ISR (xHigherPriorityTaskWoken);
        }
    }
}

static void configure_extint_channel(void)
{
    struct extint_chan_conf config_extint_chan;
    extint_chan_get_config_defaults(&config_extint_chan);
    
    //configure INT15
    config_extint_chan.gpio_pin = INT_BUTTON1_PIN;
    config_extint_chan.gpio_pin_mux = INT_BUTTON1_MUX;
    config_extint_chan.gpio_pin_pull = EXTINT_PULL_UP;
    config_extint_chan.detection_criteria = EXTINT_DETECT_BOTH;
    extint_chan_set_config(INT_BUTTON1_EIC_LINE, &config_extint_chan);
    
    //configure INT0
    //config_extint_chan.gpio_pin = INT0_EIC_PIN;
    //config_extint_chan.gpio_pin_mux = INT0_EIC_MUX;
    //config_extint_chan.gpio_pin_pull = EXTINT_PULL_DOWN;
    //config_extint_chan.detection_criteria = EXTINT_DETECT_RISING;
    //extint_chan_set_config(INT0_EIC_LINE, &config_extint_chan);
    //configure INT15
    config_extint_chan.gpio_pin = INT_BUTTON2_PIN;
    config_extint_chan.gpio_pin_mux = INT_BUTTON2_MUX;
    config_extint_chan.gpio_pin_pull = EXTINT_PULL_UP;
    config_extint_chan.detection_criteria = EXTINT_DETECT_BOTH;
    extint_chan_set_config(INT_BUTTON2_EIC_LINE, &config_extint_chan);
}

static void configure_extint_callbacks(void)
{
    //register INT15
    extint_register_callback(extint15_detection_callback, INT_BUTTON1_EIC_LINE, EXTINT_CALLBACK_TYPE_DETECT);
    extint_chan_enable_callback(INT_BUTTON1_EIC_LINE,	EXTINT_CALLBACK_TYPE_DETECT);
    
    //register INT0
    //extint_register_callback(extint0_detection_callback, INT0_EIC_LINE, EXTINT_CALLBACK_TYPE_DETECT);
    //extint_chan_enable_callback(INT0_EIC_LINE,	EXTINT_CALLBACK_TYPE_DETECT);
    extint_register_callback(extint0_detection_callback, INT_BUTTON2_EIC_LINE, EXTINT_CALLBACK_TYPE_DETECT);
    extint_chan_enable_callback(INT_BUTTON2_EIC_LINE,	EXTINT_CALLBACK_TYPE_DETECT);
}

void sme_init_isr_global(void) {
    configure_extint_channel();
    configure_extint_callbacks();
    system_interrupt_enable_global();
}

void clearInt(eventE interrupt) {
    switch( interrupt) {
        case button1Int:
        intDetect &= ~0x1;
        break;

        case button2Int:
        intDetect &= ~0x2;
        break;

        default:
        case externalInt:
        case nfcInt:
        case bteInt:
        break;
    }
}