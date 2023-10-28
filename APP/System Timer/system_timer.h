
/********************************************************************************/
/*                                                                              */
/* !Layer           : Application layer (APP)                                   */
/*                                                                              */
/* !Module          : System Timer                                              */
/* !Description     : Counting the time that the system is on through it.       */
/*                                                                              */
/* !File            : system_timer.c                                            */
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
#ifndef APP_SYSTEM_TIMER_SYSTEM_TIMER_H_
#define APP_SYSTEM_TIMER_SYSTEM_TIMER_H_


/********************************************************************************/
/******************************* Includes ***************************************/
/********************************************************************************/
#include <APP/utilities/Shared_Res.h>
#include "../utilities/APP_types.h"
#include "HAL/Motors/Motors.h"
/********************************************************************************/
/**************************Task Configuration Macros ****************************/
/********************************************************************************/
#define SYSTEM_TIMER_TASK_PERIODICITY_MILLI_SEC    1000U
#define SYSTEM_TIMER_TASK_PRIORITY_LEVEL           5U
#define TOTAL_SYS_RUNNING_TIME_IN_SEC              60U


/********************************************************************************/
/*! \Task name   : System_timer_task                                            */
/*! \Description :Task with a 1 second periodicity counts the number of seconds */
/*                that the system is ON through it and check it if exceeds the  */
/*                predefined value of total execution time of the system stop it*/
/*! \return      None                                                           */
/*! \arguments   None                                                           */
/********************************************************************************/
void System_timer_task(void *pvParameters);

#endif /* APP_SYSTEM_TIMER_SYSTEM_TIMER_H_ */
