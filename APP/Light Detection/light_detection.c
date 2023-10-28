/******************************************************************************/
/*                                                                            */
/* !Layer           : Application layer (APP)                                 */
/*                                                                            */
/* !Module          :Light Detection                                          */
/* !Description     : Detection of the highest intensity of light and update  */
/*                    the motor's state.                                      */
/* !File            : light_detection.c                                       */
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

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include "light_detection.h"
/*******************************************************************************/
/*! \Task name : light_detection_task                                          */
/*! \Description : detects the light and update the motors' state to follow it */
/*! \return      None                                                          */
/*! \arguments   None                                                          */
/*******************************************************************************/
void light_detection_task(void *pvParameters)
{
    uint32_t diff=0; /*var for holding a light intensity difference through the car's sides*/
    TickType_t LD_prev_running = xTaskGetTickCount();/*var for holding the previous running ticks count of this task */
    uint16_t light_intensity_first_side= 0;/*var for the first side LDR readings */
    uint16_t light_intensity_second_side = 0;/*var for the other side LDR readings */
    while (1)
    {

        LDR_vidGetLeftBright(&light_intensity_first_side);/*update first side LDR readings using LDR module*/
        LDR_vidGetRightBright(&light_intensity_second_side);/*update the second side LDR readings */
        if (light_intensity_first_side > light_intensity_second_side)
        {
            diff=light_intensity_first_side-light_intensity_second_side;/*get the difference between the two sides readings*/
            if (diff > LIGHT_INTENSITY_DIFF_THRISHOLD) /*check if the left side has higher light intensity */
            {
                motor_state=TURN_LEFT; /*update motor state*/
                xEventGroupSetBits(events, LIGHT_DETECTED_EVENT_FLAG);  /*set higher side light intensity event  */
                xEventGroupClearBits(events, NORMAL_EVENT_FLAG ); /*clear normal event flag */
            }
            else
            {
                motor_state = STRAIGHT;/*update motor state*/
                xEventGroupSetBits(events, NORMAL_EVENT_FLAG );/*set normal event flag in case of no intense light detected*/
            }
        }
        else
        {
            diff=light_intensity_second_side-light_intensity_first_side;
            if (diff > LIGHT_INTENSITY_DIFF_THRISHOLD)/*check if the right side has higher light intensity */
            {
                motor_state=TURN_RIGHT;/*update motor state*/
                xEventGroupSetBits(events, LIGHT_DETECTED_EVENT_FLAG);/*set higher side light intensity event  */
                xEventGroupClearBits(events, NORMAL_EVENT_FLAG );
            }
            else
            {
                motor_state = STRAIGHT;/*update motor state*/
                xEventGroupSetBits(events, NORMAL_EVENT_FLAG );/*set normal event flag in case of no intense light detected*/
            }
        }
        vTaskDelayUntil(&LD_prev_running, pdMS_TO_TICKS(LIGHT_DETECTION_TASK_PERIODICITY_MILLI_SEC));
    }
}
