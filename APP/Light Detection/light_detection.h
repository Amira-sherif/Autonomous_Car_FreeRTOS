/******************************************************************************/
/*                                                                            */
/* !Layer           : Application layer (APP)                                 */
/*                                                                            */
/* !Module          :Light Detection                                          */
/* !Description     : Detection of the highest intensity of light and update  */
/*                    the motor's state.                                      */
/* !File            : light_detection.h                                       */
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
#ifndef APP_LIGHT_DETECTION_LIGHT_DETECTION_H_
#define APP_LIGHT_DETECTION_LIGHT_DETECTION_H_
/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include "../utilities/APP_types.h"
#include "HAL/LEDs/leds.h"
#include "HAL/Motors/Motors.h"
/******************************************************************************/
/**************************Task Configuration Macros **************************/
/******************************************************************************/
#define LIGHT_DETECTION_TASK_PERIODICITY_MILLI_SEC  100
#define LIGHT_DETECTION_TASK_PRIORITY_LEVEL         2U
#define LIGHT_INTENSITY_DIFF_THRISHOLD              150
/*******************************************************************************/
/*! \Task name : light_detection_task                                          */
/*! \Description : detects the light and update the motors' state to follow it */
/*! \return      None                                                          */
/*! \arguments   None                                                          */
/*******************************************************************************/
void light_detection_task(void *pvParameters);

#endif /* APP_LIGHT_DETECTION_LIGHT_DETECTION_H_ */
