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

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include "APP/Initialization/initialization.h"

/******************************************************************************/
/*************************** global variables *********************************/
/******************************************************************************/
uint8_t motor_state = STRAIGHT;
TaskHandle_t CA_h;
TaskHandle_t LD_h;
TaskHandle_t display_h;
TaskHandle_t motion_h;
TaskHandle_t sys_h;
QueueHandle_t Displaying_Q;
EventGroupHandle_t events;

int main(void)
{

    tasks_modules_Init();
    Display_init();
    xTaskCreate(collisionAvoidance_task, "CA", configMINIMAL_STACK_SIZE, NULL, COLLISION_AVOIDANCE_TASK_PRIORITY_LEVEL, &COLLISION_AVOIDANCE_TASK_HANDLE);
    xTaskCreate(light_detection_task, "LD", configMINIMAL_STACK_SIZE, NULL, LIGHT_DETECTION_TASK_PRIORITY_LEVEL, &LIGHT_DETECTION_TASK_HANDLE);
    xTaskCreate(input_handling_task, "INPUTS", configMINIMAL_STACK_SIZE, NULL, INPUT_HANDLING_TASK_PRIORITY_LEVEL, NULL);
    xTaskCreate(motion_control_task, "MOTION", configMINIMAL_STACK_SIZE, NULL, MOTION_CONTROL_TASK_PRIORITY_LEVEL, &MOTION_CONTROL_TASK_HANDLE);
    xTaskCreate(Display_task, "DISPLAY", configMINIMAL_STACK_SIZE, NULL, 1, &DISPLAY_TASK_HANDLE);
    events = xEventGroupCreate();
    Displaying_Q = xQueueCreate(DISPLAY_QUEUE_SIZE,sizeof(Sensor_msg_t));
    vTaskStartScheduler();

    while (1)
    {
    }
}


