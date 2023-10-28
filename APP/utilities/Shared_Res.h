
/******************************************************************************/
/*                                                                            */
/* !Layer           : Application layer (APP)                                 */
/*                                                                            */
/* !Module          : main                                                    */
/* !Description     : tasks creation, event groups and queues declaration     */
/*                                                                            */
/* !File            : main.c                                                  */
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
#ifndef APP_UTILITIES_SHARED_RES_H_
#define APP_UTILITIES_SHARED_RES_H_
/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include "include/FreeRTOS.h"
#include "include/task.h"
#include "include/semphr.h"
#include "include/event_groups.h"

#include "HAL/RCC/RCC.h"
#include "HAL/Ultrasonic/Ultrasonic.h"
#include "HAL/Motors/Motors.h"
#include "HAL/LDR/LDR.h"
#include "HAL/LCD/LCD.h"
#include "HAL/Button/Button.h"
#include "HAL/LEDs/leds.h"

/******************************************************************************/
/******************************* Externs **************************************/
/******************************************************************************/
extern TaskHandle_t CA_h;
extern TaskHandle_t LD_h;
extern TaskHandle_t dispay_h;
extern TaskHandle_t motion_h;
extern TaskHandle_t sys_h;
extern QueueHandle_t Displaying_Q;
extern EventGroupHandle_t events;
extern uint8_t motor_state ;



#endif /* APP_UTILITIES_SHARED_RES_H_ */
