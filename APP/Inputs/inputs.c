/******************************************************************************/
/*                                                                            */
/* !Layer           : Application layer (APP)                                 */
/*                                                                            */
/* !Module          : Inputs Handling                                         */
/* !Description     : detection of the user's input through the push buttons  */
/*                    and handling it.                                        */
/*                                                                            */
/* !File            : inputs.c                                                */
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
#include "inputs.h"

/******************************************************************************/
/*! \Task name   : input_handling_task                                        */
/*! \Description :checks if :                                                 */
/*                          button 0 is pressed --> START the system          */
/*                          button 1 is pressed --> STOP the system           */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void input_handling_task(void *pvParameters)
{
    TickType_t ip_handling_prev_running = xTaskGetTickCount();/*var for holding the previous running ticks count of this task */
    /*suspend the main tasks of our system till the user starts it*/
    vTaskSuspend(COLLISION_AVOIDANCE_TASK_HANDLE);
    vTaskSuspend(LIGHT_DETECTION_TASK_HANDLE);
    vTaskSuspend(MOTION_CONTROL_TASK_HANDLE);

    while (1)
    {
        if(Button_vidGetButtonValue(BUTTON_PORT, BUTTON_0) == Button_High) /*check if the start button (switch 0) is pressed*/
        {
            while (Button_vidGetButtonValue(BUTTON_PORT, BUTTON_0) == Button_High){};/*to avoid the debouncing effect*/
            xTaskCreate(System_timer_task, "Timer", configMINIMAL_STACK_SIZE, NULL, SYSTEM_TIMER_TASK_PRIORITY_LEVEL, &SYSTME_TIMER_TASK_HANDLE);/*create the timer task to calc the seconds count from this moment*/
            /*Resume the execution of the system's tasks*/
            vTaskResume(COLLISION_AVOIDANCE_TASK_HANDLE);
            vTaskResume(LIGHT_DETECTION_TASK_HANDLE);
            vTaskResume(MOTION_CONTROL_TASK_HANDLE);
        }

        if(Button_vidGetButtonValue(BUTTON_PORT, BUTTON_1) == Button_High)/*check if the stop button (switch 1) is pressed*/
        {
            while (Button_vidGetButtonValue(BUTTON_PORT, BUTTON_1) == Button_High){};/*to avoid the debouncing effect*/
            vTaskDelete(SYSTME_TIMER_TASK_HANDLE);/*kill the timer task*/
            /*suspend the execution of the system's tasks*/
            vTaskSuspend(COLLISION_AVOIDANCE_TASK_HANDLE);
            vTaskSuspend(LIGHT_DETECTION_TASK_HANDLE);
            vTaskSuspend(MOTION_CONTROL_TASK_HANDLE);
            current_direction(STOP);/*stop the motion*/
        }
        vTaskDelayUntil(&ip_handling_prev_running, pdMS_TO_TICKS(INPUT_HANDLING_TASK_PERIODICITY_MILLI_SEC));
    }

}
