/******************************************************************************/
/*                                                                            */
/* !Layer           : Application layer (APP)                                 */
/*                                                                            */
/* !Module          : Initialization                                          */
/* !Description     : The initialization of the used HAL modules.             */
/*                                                                            */
/* !File            : initialization.h                                        */
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
#ifndef APP_INITIALIZATION_INITIALIZATION_H_
#define APP_INITIALIZATION_INITIALIZATION_H_

/******************************************************************************/
/*************************** HAL Includes *************************************/
/******************************************************************************/
#include "HAL/RCC/RCC.h"
#include "HAL/Ultrasonic/Ultrasonic.h"
#include "HAL/Motors/Motors.h"
#include "HAL/LDR/LDR.h"
#include "HAL/LCD/LCD.h"
#include "HAL/Button/Button.h"
#include "HAL/LEDs/leds.h"

/******************************************************************************/
/*************************** TASKS Includes ***********************************/
/******************************************************************************/
#include "APP/Light Detection/light_detection.h"
#include "APP/Collision Avoidance/collision_avoidance.h"
#include "APP/Motion Control/motion_control.h"
#include "APP/System Timer/system_timer.h"
#include "APP/Inputs/inputs.h"
#include "APP/Display/display.h"
#include "APP/Initialization/initialization.h"

/******************************************************************************/
/*************************** QUEUE Configuration ******************************/
/******************************************************************************/
#define DISPLAY_QUEUE_SIZE              2
/******************************************************************************/
/*! \Function name : tasks_modules_Init                                       */
/*! \Description : initializes the needed HAL modules for the system          */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void tasks_modules_Init(void);


#endif /* APP_INITIALIZATION_INITIALIZATION_H_ */
