/******************************************************************************/
/*                                                                            */
/* !Layer           : Application layer (APP)                                 */
/*                                                                            */
/* !Module          : Inputs Handling                                         */
/* !Description     : detection of the user's input through the push buttons  */
/*                    and handling it.                                        */
/*                                                                            */
/* !File            : inputs.h                                                */
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
#ifndef APP_INPUTS_INPUTS_H_
#define APP_INPUTS_INPUTS_H_
/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include <APP/utilities/Shared_Res.h>
#include "../utilities/APP_types.h"
#include "HAL/Button/Button.h"
#include "APP/System Timer/system_timer.h"

/******************************************************************************/
/**************************Task Configuration Macros **************************/
/******************************************************************************/
#define INPUT_HANDLING_TASK_PERIODICITY_MILLI_SEC    300
#define INPUT_HANDLING_TASK_PRIORITY_LEVEL           3U
/******************************************************************************/
/*! \Task name   : input_handling_task                                        */
/*! \Description :checks if :                                                 */
/*                          button 0 is pressed --> START the system          */
/*                          button 1 is pressed --> STOP the system           */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void input_handling_task(void *pvParameters);
#endif /* APP_INPUTS_INPUTS_H_ */
