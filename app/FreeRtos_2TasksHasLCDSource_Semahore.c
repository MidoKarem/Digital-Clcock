/*
 * lab22.c
 *
 *  Created on: Mar 25, 2022
 *      Author: mohamed karem
 */


#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include"../HAL/LCD_driver/LCD_config.h"
#include"../HAL/LCD_driver/LCD_interface.h"
#include "../FREE_RTOS/FreeRTOS.h"
#include "../FREE_RTOS/task.h"
#include "../FREE_RTOS/semphr.h"
#include "../FREE_RTOS/FreeRTOSConfig.h"

#include <util/delay.h>


 void LCD_Task_1 (void*pvParamter);
 void LCD_Task_2 (void*pvParamter);

 xSemaphoreHandle  binarysemaphore= NULL;

void lab22(void)
{



	LCD_voidINST();


  vSemaphoreCreateBinary( binarysemaphore );
   xTaskCreate(LCD_Task_1,NULL,configMINIMAL_STACK_SIZE,NULL,3,NULL);
   xTaskCreate(LCD_Task_2,NULL,configMINIMAL_STACK_SIZE,NULL,3,NULL);




	 vTaskStartScheduler( );





}


void LCD_Task_1 (void*pvParamter)
{

for ( ; ; )
{

   if( xSemaphoreTake( binarysemaphore,( portTickType ) 500) ==1)
   {
	LCD_voidsendcommand(0x01);

	LCD_voidsendstring("I am task 1");
	//_delay_ms(500);// During this delay the task is running
	vTaskDelay( 1200);
	 xSemaphoreGive(binarysemaphore);

   }



}


}


void LCD_Task_2 (void*pvParamter)
{

for ( ; ; )
{
if( xSemaphoreTake( binarysemaphore,( portTickType ) 10) ==1)
{
	LCD_voidsendcommand(0x01);

	LCD_voidsendstring("I am task 2");

	vTaskDelay( 800);

	xSemaphoreGive(binarysemaphore);
}


}


}
