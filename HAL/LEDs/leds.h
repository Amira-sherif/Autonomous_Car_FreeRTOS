/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware abstraction layer (HAL)                        */
/*                                                                            */
/* !Module          : LEDs                                                    */
/* !Description     : init and control the leds embedded in TM4C123GH6PM      */
/*                                                                            */
/* !File            : leds.h                                                  */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Robot Car @EME - EUI                                    */
/*                                                                            */
/* !Target          : TIVA-C TM4C123GH6PM                                     */
/*                                                                            */
/* !Compiler        : Code Composer Studio 8.3.1                              */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Designed by     : APPRAID TEAM                    !Date : OCT 9, 2023     */
/* !Coded by        : APPRAID TEAM                    !Date : OCT 9, 2023     */
/*                                                                            */
/* Ver 1.0    OCT 10, 2023     Initial release                                */
/******************************************************************************/

#ifndef HAL_LEDS_LEDS_H_
#define HAL_LEDS_LEDS_H_
/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include "MCAL/GPIO/GPIO.h"
/******************************************************************************/
/************************* DECODED COLORS DEFINITIONS *************************/
/******************************************************************************/
#define RED_LED     1
#define BLUE_LED    2
#define GREEN_LED   3
#define PURPLE_LED  4
#define WHITE_LED   5

/******************************************************************************/
/*! \Function name:LEDs_init                                                  */
/*! \Description  :init the GPIO_PORTF and the 3 pins associated with the LEDs*/
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void LEDs_init(void);
/******************************************************************************/
/*! \Function name:LED_turnOn                                                 */
/*! \Description  :Based on the provided decoded color set, clear some LEDs   */
/* and set others to achieve the requested color                              */
/*! \return      None                                                         */
/*! \arguments   uint8_t color                                                */
/******************************************************************************/
void LED_turnOn(uint8_t color);

#endif /* HAL_LEDS_LEDS_H_ */
