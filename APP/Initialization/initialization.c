/******************************************************************************/
/*                                                                            */
/* !Layer           : Application layer (APP)                                 */
/*                                                                            */
/* !Module          : Initialization                                          */
/* !Description     : The initialization of the used HAL modules.             */
/*                                                                            */
/* !File            : initialization.c                                        */
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
#include "initialization.h"
/******************************************************************************/
/*! \Function name : tasks_modules_Init                                       */
/*! \Description : initializes the needed HAL modules for the system          */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void tasks_modules_Init(void)
{
    PLL_Init();
    LDR_vidInit();
    LCD_vidInit();
    Button_vidInit();
    LEDs_init();
    Ultrasonic_vidInit();
    motor_initialisation();
}

