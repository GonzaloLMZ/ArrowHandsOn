/*
 * sme_gps_behaviour.c
 *
 * Created: 3/1/2015 9:59:41 PM
 *  Author: mfontane
 */

#include "sme_sfx_behaviour.h"
#include "tasks\sme_controller.h"
#include "sme_FreeRTOS.h"
#include "Devices\IO\sme_rgb_led.h"
#include "Devices\uart\gps\sme_sl868v2_execute.h"
#include "model\sme_model_sl868v2.h"


 void sme_gps_button1_behaviour(void) {
  
      sme_led_blue_off();
       controllerQueueS gpsEvt;

    gpsEvt.intE = allSensorSend;
    xQueueSend(controllerQueue, (void *) &gpsEvt, NULL);
     
 }


void sme_gps_button2_behaviour(void) {
    
    controllerQueueS gpsEvt;

    gpsEvt.intE = gpsData;
    xQueueSend(controllerQueue, (void *) &gpsEvt, NULL);


    sme_led_blue_off();


    // set GPS in standby
    sendSl868v2Msg(SL868V2_SET_STDBY_CMD,
    sizeof(SL868V2_SET_STDBY_CMD));
}