/******************************************************************************/
/*                                                                            */
/* !Layer           : Application layer (APP)                                 */
/*                                                                            */
/* !Module          : Collision Avoidance                                     */
/* !Description     : detection of potential collisions and taking the        */
/*                    decision to avoid them.                                 */
/*                                                                            */
/* !File            : collision_avoidance.h                                   */
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


#ifndef APP_COLLISION_AVOIDANCE_COLLISION_AVOIDANCE_H_
#define APP_COLLISION_AVOIDANCE_COLLISION_AVOIDANCE_H_

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include "HAL/Ultrasonic/Ultrasonic.h"
#include "../utilities/APP_types.h"

/******************************************************************************/
/**************************Task Configuration Macros **************************/
/******************************************************************************/
#define COLLISION_AVOIDANCE_TASK_PERIODICITY_MILLI_SEC    60U
#define COLLISION_AVOIDANCE_TASK_PRIORITY_LEVEL           2U
#define COLLISION_DISTANCE_CM                             10U

/******************************************************************************/
/*! \Task name   : collisionAvoidance_task                                    */
/*! \Description :periodic task which detects the potential collisions        */
/*                (objects closer than the collision distance ), returns back */
/*                and rotate 90 degree to avoid it.                           */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void collisionAvoidance_task(void *pvParameters);
#endif /* APP_COLLISION_AVOIDANCE_COLLISION_AVOIDANCE_H_ */
