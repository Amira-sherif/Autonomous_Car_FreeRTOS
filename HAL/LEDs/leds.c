/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware abstraction layer (HAL)                        */
/*                                                                            */
/* !Module          : LEDs                                                    */
/* !Description     : init and control the leds embedded in TM4C123GH6PM      */
/*                                                                            */
/* !File            : leds.c                                                  */
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

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include "leds.h"

/******************************************************************************/
/*! \Function name:LEDs_init                                                  */
/*! \Description  :init the GPIO_PORTF and the 3 pins associated with the LEDs*/
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void LEDs_init(void)
{
    GPIO_vidInitPort(GPIO_PORTF);
    GPIO_vidOutputPin(GPIO_PORTF, 1);
    GPIO_vidOutputPin(GPIO_PORTF, 2);
    GPIO_vidOutputPin(GPIO_PORTF, 3);
}
/******************************************************************************/
/*! \Function name:LED_turnOn                                                 */
/*! \Description  :Based on the provided decoded color set, clear some LEDs   */
/* and set others to achieve the requested color                              */
/*! \return      None                                                         */
/*! \arguments   uint8_t color                                                */
/******************************************************************************/
void LED_turnOn(uint8_t color)
{
    switch(color)
    {
    case RED_LED :
        GPIO_vidWritePin(GPIO_PORTF, PIN1, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN2, OUTPUT_LOW);
        GPIO_vidWritePin(GPIO_PORTF, PIN3, OUTPUT_LOW);
        break;
    case BLUE_LED:
        GPIO_vidWritePin(GPIO_PORTF, PIN1, OUTPUT_LOW);
        GPIO_vidWritePin(GPIO_PORTF, PIN2, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN3, OUTPUT_LOW);
        break;
    case GREEN_LED :
        GPIO_vidWritePin(GPIO_PORTF, PIN1, OUTPUT_LOW);
        GPIO_vidWritePin(GPIO_PORTF, PIN2, OUTPUT_LOW);
        GPIO_vidWritePin(GPIO_PORTF, PIN3, OUTPUT_HIGH);
        break;
    case PURPLE_LED:
        GPIO_vidWritePin(GPIO_PORTF, PIN1, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN2, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN3, OUTPUT_LOW);

        break;
    case WHITE_LED :
        GPIO_vidWritePin(GPIO_PORTF, PIN1, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN2, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN3, OUTPUT_HIGH);
        break;

    }

}


