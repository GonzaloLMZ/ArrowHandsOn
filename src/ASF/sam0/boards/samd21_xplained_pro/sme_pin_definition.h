/*
* sme_pin_definition.h
*
* Created: 2/14/2015 7:09:37 PM
*  Author: smkk
*/


#ifndef SME_PIN_DEFINITION_H_
#define SME_PIN_DEFINITION_H_


/** Name string macro */
#define BOARD_NAME                "SmartEverithing"


#define LED_ACTIVE                     false
#define LED_INACTIVE                   !LED_ACTIVE

#define SME_LED_Y1_PIN                 PIN_PB01
#define SME_LED_Y1_NAME                "LED1 (yellow)"
#define SME_LED_Y1_ACTIVE              LED_ACTIVE
#define SME_LED_Y1_INACTIVE            LED_INACTIVE
#define SME_LED_Y1_GPIO                SME_LED_Y1_PIN
#define SME_LED_Y1                     SME_LED_Y1_PIN

#define SME_LED_Y2_PIN                 PIN_PB03
#define SME_LED_Y2_NAME                "LED2 (yellow)"
#define SME_LED_Y2_ACTIVE              LED_ACTIVE
#define SME_LED_Y2_INACTIVE            LED_INACTIVE
#define SME_LED_Y2_GPIO                SME_LED_Y2_PIN
#define SME_LED_Y2                     SME_LED_Y2_PIN


// pin definition for I_O Expander */
#define SME_RESET_IOEXT_PIN            PIN_PA13
#define SME_RESET_IOEXT_NAME           "LED2 (yellow)"
#define SME_RESET_IOEXT_ACTIVE         LED_ACTIVE
#define SME_RESET_IOEXT_INACTIVE       LED_INACTIVE
#define SME_RESET_IOEXT_GPIO           SME_RESET_IOEXT_PIN
#define SME_RESET_IOEXT                SME_RESET_IOEXT_PIN

#define SME_INT_IOEXT_HW_PIN           PIN_PB06
#define SME_INT_IOEXT_ACTIVE           false
#define SME_INT_IOEXT_INACTIVE         !SME_INT_IOEXT_ACTIVE
#define SME_INT_IOEXT_PIN              PIN_PB06A_EIC_EXTINT6
#define SME_INT_IOEXT_MUX              MUX_PB06A_EIC_EXTINT6
#define SME_INT_IOEXT_EIC_PINMUX       PINMUX_PB06A_EIC_EXTINT6
#define SME_INT_IOEXT_EIC_LINE         6

// END pin definition for I_O Expander */

/** \name Embedded debugger I2C interface definitions
* @{
*/
#define SME_I2C_MODULE              SERCOM3
#define SME_I2C_SERCOM_PINMUX_PAD0  PINMUX_PA22C_SERCOM3_PAD0
#define SME_I2C_SERCOM_PINMUX_PAD1  PINMUX_PA23C_SERCOM3_PAD1
#define SME_I2C_SERCOM_DMAC_ID_TX   SERCOM3_DMAC_ID_TX
#define SME_I2C_SERCOM_DMAC_ID_RX   SERCOM3_DMAC_ID_RX
#define SME_SDA_PIN                 PIN_PA22
#define SME_SCL_PIN                 PIN_PA23

/** @} */


/** \name Embedded debugger CDC Gateway USART interface definitions
* @{
*/
#define SME_CDC_MODULE              SERCOM2
#define SME_CDC_SERCOM_MUX_SETTING  USART_RX_3_TX_2_XCK_3
#define SME_CDC_SERCOM_PINMUX_PAD0  PINMUX_PA10D_SERCOM2_PAD2   
#define SME_CDC_SERCOM_PINMUX_PAD1  PINMUX_PA11D_SERCOM2_PAD3
#define SME_CDC_SERCOM_PINMUX_PAD2  PINMUX_UNUSED
#define SME_CDC_SERCOM_PINMUX_PAD3  PINMUX_UNUSED
#define SME_CDC_SERCOM_DMAC_ID_TX   SERCOM2_DMAC_ID_TX
#define SME_CDC_SERCOM_DMAC_ID_RX   SERCOM2_DMAC_ID_RX 

#define SME_CDC_SERCOM_BAUDRATE 115200
/** @} */

/** \name Embedded SIGFOX UART interface definitions
* @{
*/
#define SME_SIGFOX_SERCOM_MUX_SETTING  USART_RX_1_TX_0_XCK_1
#define SME_SIGFOX_MODULE              SERCOM4
#define SME_SIGFOX_SERCOM_PINMUX_PAD0  PINMUX_PB12C_SERCOM4_PAD0
#define SME_SIGFOX_SERCOM_PINMUX_PAD1  PINMUX_PB13C_SERCOM4_PAD1
#define SME_SIGFOX_SERCOM_PINMUX_PAD2  PINMUX_UNUSED
#define SME_SIGFOX_SERCOM_PINMUX_PAD3  PINMUX_UNUSED
#define SME_SIGFOX_SERCOM_DMAC_ID_TX   SERCOM4_DMAC_ID_TX
#define SME_SIGFOX_SERCOM_DMAC_ID_RX   SERCOM4_DMAC_ID_RX

#define SME_SIGFOX_RTS_PIN                 PIN_PB14
#define SME_SIGFOX_RTS_IOEXT_NAME         "RTS (SFX)"
#define SME_SIGFOX_RTS_IOEXT_ACTIVE       LED_ACTIVE
#define SME_SIGFOX_RTS_IOEXT_INACTIVE     LED_INACTIVE
#define SME_SIGFOX_RTS_IOEXT_GPIO         SME_SIGFOX_RTS_PIN
#define SME_SIGFOX_RTS_IOEXT              SME_SIGFOX_RTS_PIN

#define SME_SIGFOX_BAUDRATE			   19200
/** @} */


/** \name Embedded GPS UART interface definitions
* @{
*/
#define SME_GPS_MODULE              SERCOM0
#define SME_GPS_SERCOM_MUX_SETTING  USART_RX_1_TX_0_XCK_1
#define SME_GPS_SERCOM_PINMUX_PAD0  PINMUX_PA08C_SERCOM0_PAD0
#define SME_GPS_SERCOM_PINMUX_PAD1  PINMUX_PA09C_SERCOM0_PAD1
#define SME_GPS_SERCOM_PINMUX_PAD2  PINMUX_UNUSED
#define SME_GPS_SERCOM_PINMUX_PAD3  PINMUX_UNUSED
#define SME_GPS_SERCOM_DMAC_ID_TX   SERCOM0_DMAC_ID_TX
#define SME_GPS_SERCOM_DMAC_ID_RX   SERCOM0_DMAC_ID_RX

#define SME_GPS_BAUDRATE		    9600
/* @} */



/** \name Embedded RGB I/O interface definitions
* @{
*/
#define SME_PWM_RGB_MODULE  TCC0

#define SME_PWM_B_OUT_PIN PIN_PB10F_TCC0_WO4
#define SME_PWM_B_OUT_MUX MUX_PB10F_TCC0_WO4
#define SME_CC_B_REGISTER 0
#define SME_WO_B_REGISTER 4

#define SME_PWM_G_OUT_PIN PIN_PB11F_TCC0_WO5
#define SME_PWM_G_OUT_MUX MUX_PB11F_TCC0_WO5
#define SME_CC_G_REGISTER 1
#define SME_WO_G_REGISTER 5

#define SME_PWM_R_OUT_PIN PIN_PA12F_TCC0_WO6
#define SME_PWM_R_OUT_MUX MUX_PA12F_TCC0_WO6
#define SME_CC_R_REGISTER 2
#define SME_WO_R_REGISTER 6
/* @} */

#define STEP_UP_PIN_POUT                PIN_PB05
#define EXT_POW_PIN_PIN                 PIN_PB04




// INTERRUPT
/** \name INT15 definitions */
#define SME_BUTTON1_PIN                 PIN_PB00
#define INT_BUTTON1__ACTIVE             false
#define INT_BUTTON1__INACTIVE           !INT_BUTTON1__ACTIVE
#define INT_BUTTON1_PIN                 PIN_PB00A_EIC_EXTINT0
#define INT_BUTTON1_MUX                 MUX_PB00A_EIC_EXTINT0
#define INT_BUTTON1_EIC_PINMUX          PINMUX_PB00A_EIC_EXTINT0
#define INT_BUTTON1_EIC_LINE            0

#define SME_BUTTON2_PIN                 PIN_PA27
#define INT_BUTTON2__ACTIVE             false
#define INT_BUTTON2__INACTIVE           !INT_BUTTON2__ACTIVE
#define INT_BUTTON2_PIN                 PIN_PA27A_EIC_EXTINT15
#define INT_BUTTON2_MUX                 MUX_PA27A_EIC_EXTINT15
#define INT_BUTTON2_EIC_PINMUX          PINMUX_PA27A_EIC_EXTINT15
#define INT_BUTTON2_EIC_LINE            15


/** \name INT0 definitions  */
#define INT0_PIN                        PIN_PA16
#define INT0_ACTIVE                     false
#define INT0_INACTIVE                   !INT0_ACTIVE
#define INT0_EIC_PIN                    PIN_PA16A_EIC_EXTINT0
#define INT0_EIC_MUX                    MUX_PA16A_EIC_EXTINT0
#define INT0_EIC_PINMUX                 PINMUX_PA16A_EIC_EXTINT0
#define INT0_EIC_LINE                   0




/**
 * \brief Turns off the specified LEDs.
 *
 * \param led_gpio LED to turn off (LEDx_GPIO).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_Off(led_gpio)     port_pin_set_output_level(led_gpio, LED_ACTIVE)

/**
 * \brief Turns on the specified LEDs.
 *
 * \param led_gpio LED to turn on (LEDx_GPIO).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_On(led_gpio)      port_pin_set_output_level(led_gpio, LED_INACTIVE)

/**
 * \brief Toggles the specified LEDs.
 *
 * \param led_gpio LED to toggle (LEDx_GPIO).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_Toggle(led_gpio)  port_pin_toggle_output_level(led_gpio)


#endif /* SME_PIN_DEFINITION_H_ */
