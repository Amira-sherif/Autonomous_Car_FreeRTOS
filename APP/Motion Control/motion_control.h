/********************************************************************************/
/*                                                                              */
/* !Layer           : Application layer (APP)                                   */
/*                                                                              */
/* !Module          : Motion Control                                            */
/* !Description     : Updating motors direction based on the state provided by  */
/*                    the other modules(light detection and collision avoidance)*/
/*                                                                              */
/* !File            : motion_control.h                                          */
/*                                                                              */
/* !Coding language : C                                                         */
/*                                                                              */
/* !Project         : Robot Car @EME - EUI                                      */
/*                                                                              */
/* !Target          : TIVA-C TM4C123GH6PM                                       */
/*                                                                              */
/* !Compiler        : Code Composer Studio 8.3.1                                */
/*                                                                              */
/*                                                                              */
/********************************************************************************/
/* MODIFICATION LOG :                                                           */
/********************************************************************************/
/*                                                                              */
/* !Designed by     : APPRAID TEAM                    !Date : OCT 9, 2023       */
/* !Coded by        : APPRAID TEAM                    !Date : OCT 9, 2023       */
/*                                                                              */
/* Ver 1.0    OCT 10, 2023     Initial release                                  */
/********************************************************************************/

#ifndef APP_MOTION_CONTROL_MOTION_CONTROL_H_
#define APP_MOTION_CONTROL_MOTION_CONTROL_H_
/********************************************************************************/
/******************************* Includes ***************************************/
/********************************************************************************/
#include "../utilities/APP_types.h"
#include "HAL/Motors/Motors.h"
#include "HAL/LEDs/leds.h"

/********************************************************************************/
/**************************Task Configuration Macros ****************************/
/********************************************************************************/
#define MOTION_CONTROL_TASK_PRIORITY_LEVEL           4U
/********************************************************************************/
/*! \Task name   : motion_control_task                                          */
/*! \Description : event driven task which update the motors' direction when any*/
/*                 of the collision avoidance or light detection modules update */
/*                 the motors' state.                                           */
/*! \return      None                                                           */
/*! \arguments   None                                                           */
/********************************************************************************/
void motion_control_task(void *pvParameters);


#endif /* APP_MOTION_CONTROL_MOTION_CONTROL_H_ */
