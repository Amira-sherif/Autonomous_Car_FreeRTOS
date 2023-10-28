/******************************************************************************/
/*                                                                            */
/* !Layer           : Application layer (APP)                                 */
/*                                                                            */
/* !Module          : Display                                                 */
/* !Description     : Receives messages from other modules and displays them  */
/*                    on the LCD                                              */
/*                                                                            */
/* !File            : display.c                                               */
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
#include "display.h"

/******************************************************************************/
/*! \Task name : Display_task                                                 */
/*! \Description : checks the received messages on the displaying queue and   */
/*  based on the ID of the msg displays it on its predefined position         */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void Display_task(void *pvParameters)
{
    Sensor_msg_t recieved_msg; /*sensor msg strut for holding and processing received messages to the displaying queue  */
    while (1)
    {
        xQueueReceive(Displaying_Q,&recieved_msg,0);/*get the received messages from the queue*/
        if((recieved_msg.id == DISTANCE_MESSAGE_ID)) /*check if the received message is message of the measured distance*/
        {
            /*display distance msg at its specified location*/
            LCD_moveCursor(0, 9);
            LCD_vidWriteNumber(recieved_msg.reading);
            LCD_vidWriteString("     ");
        }
        else if(recieved_msg.id == SECONDS_MESSAGE_ID )/*check if the received message is message of the current seconds' count*/
        {
            /*display timer msg at its specified location*/
            LCD_moveCursor(1, 6);
            LCD_vidWriteNumber(recieved_msg.reading);
        }

    }
}
/******************************************************************************/
/*! \Function name : Display_init                                             */
/*! \Description : display a fixed strings at the beginning of the system     */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void Display_init(void)
{
    LCD_moveCursor(0,0);
    LCD_vidWriteString("DISTANCE:");
    LCD_moveCursor(1,0);
    LCD_vidWriteString("TIME:");

}



