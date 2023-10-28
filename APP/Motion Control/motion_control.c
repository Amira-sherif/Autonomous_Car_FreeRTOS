/********************************************************************************/
/*                                                                              */
/* !Layer           : Application layer (APP)                                   */
/*                                                                              */
/* !Module          : Motion Control                                            */
/* !Description     :Updating motors direction based on the state provided by   */
/*                   the other modules(light detection and collision avoidance).*/
/*                                                                              */
/* !File            : motion_control.c                                          */
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

/********************************************************************************/
/******************************* Includes ***************************************/
/********************************************************************************/
#include "motion_control.h"
/********************************************************************************/
/*! \Task name   : motion_control_task                                          */
/*! \Description : event driven task which update the motors' direction when any*/
/*                 of the collision avoidance or light detection modules update */
/*                 the motors' state.                                           */
/*! \return      None                                                           */
/*! \arguments   None                                                           */
/********************************************************************************/
void motion_control_task(void *pvParameters)
{
    EventBits_t events_flags; /*var for holding the current event */
    while(1)
    {
        events_flags = xEventGroupWaitBits(events, NORMAL_EVENT_FLAG|COLLISION_EVENT_FLAG|LIGHT_DETECTED_EVENT_FLAG, 1, 0, portMAX_DELAY);/*wait until triggering one event from the three main events in our car: NORMAL, LIGHT DETECTED and COLLISION DETECTED*/
        if ((events_flags & COLLISION_EVENT_FLAG) == COLLISION_EVENT_FLAG) /*check if the triggered event is the collision detection event*/
        {
            LED_turnOn(PURPLE_LED);
            current_direction(BACKWARD);/*set the direction of the motors as backward*/
            vTaskDelay(pdMS_TO_TICKS(1000));
            current_direction(TURN_RIGHT);/*set the direction of the motors as right for a .5 sec after 1 sec as backward to achieve 90 degree rotation*/
            vTaskDelay(pdMS_TO_TICKS(500));
        }
        else
        {
            if ((events_flags & LIGHT_DETECTED_EVENT_FLAG) == LIGHT_DETECTED_EVENT_FLAG)/*check if the triggered event is the light detection event*/
            {
                LED_turnOn(GREEN_LED);
            }
            else if ((events_flags & NORMAL_EVENT_FLAG ) == NORMAL_EVENT_FLAG )/*check if the triggered event is normal movement event */
            {
                LED_turnOn(RED_LED);
            }
            current_direction(motor_state);/*update the current direction of the motors based on the light detected or normal conditions */
        }
    }
}
