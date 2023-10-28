/******************************************************************************/
/*                                                                            */
/* !Layer           : Application layer (APP)                                 */
/*                                                                            */
/* !Module          : Display                                                 */
/* !Description     : Receives messages from other modules and displays them  */
/*                    on the LCD                                              */
/*                                                                            */
/* !File            : display.h                                               */
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
#ifndef APP_DISPLAY_DISPLAY_H_
#define APP_DISPLAY_DISPLAY_H_

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include "../utilities/APP_types.h"
/******************************************************************************/
/*! \Task name : Display_task                                                 */
/*! \Description : checks the received messages on the displaying queue and   */
/*  based on the ID of the msg displays it on its predefined position         */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void Display_task(void *pvParameters);
/******************************************************************************/
/*! \Function name : Display_init                                             */
/*! \Description : display a fixed strings at the beginning of the system     */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void Display_init(void);
#endif /* APP_DISPLAY_DISPLAY_H_ */
