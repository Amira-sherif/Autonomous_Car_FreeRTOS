/********************************************************************************/
/*                                                                              */
/* !Layer           : Application layer (APP)                                   */
/*                                                                              */
/* !Module          : APP types                                                 */
/* !Description     : Macros and types shared between the system's tasks        */
/*                                                                              */
/* !File            : APP_types.h                                               */
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

#ifndef APP_UTILITIES_APP_TYPES_H_
#define APP_UTILITIES_APP_TYPES_H_

/********************************************************************************/
/******************************* Includes ***************************************/
/********************************************************************************/
#include <APP/utilities/Shared_Res.h>

/********************************************************************************/
/************************** system's Event Flags ********************************/
/********************************************************************************/
#define LIGHT_DETECTED_EVENT_FLAG   ( 1 << 0 )
#define COLLISION_EVENT_FLAG        ( 1 << 1 )
#define NORMAL_EVENT_FLAG           ( 1 << 2 )
/********************************************************************************/
/***************************** Messages' IDs ************************************/
/********************************************************************************/
#define SECONDS_MESSAGE_ID          0xAA
#define DISTANCE_MESSAGE_ID         0xBB

/********************************************************************************/
/**************************** Tasks' handles ************************************/
/********************************************************************************/
#define LIGHT_DETECTION_TASK_HANDLE         LD_h
#define COLLISION_AVOIDANCE_TASK_HANDLE     CA_h
#define SYSTME_TIMER_TASK_HANDLE            sys_h
#define MOTION_CONTROL_TASK_HANDLE          motion_h
#define DISPLAY_TASK_HANDLE                 display_h
/********************************************************************************/
/**************************** Type definition ***********************************/
/********************************************************************************/
typedef struct
{
    uint32_t reading;
    uint8_t id;
}Sensor_msg_t;

#endif /* APP_UTILITIES_APP_TYPES_H_ */
