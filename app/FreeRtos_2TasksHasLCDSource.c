/*
 * lab2.c
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
#include "../FREE_RTOS/FreeRTOSConfig.h"

#include <util/delay.h>


 void LCD_Task1_ (void*pvParamter);
 void LCD_Task2_ (void*pvParamter);

void lab2(void)
{



	LCD_voidINST();


	 xTaskCreate(LCD_Task1_,NULL,configMINIMAL_STACK_SIZE,NULL,3,NULL);
	 xTaskCreate(LCD_Task2_,NULL,configMINIMAL_STACK_SIZE,NULL,4,NULL);




	 vTaskStartScheduler( );





}


void LCD_Task1_ (void*pvParamter)
{

for ( ; ; )
{
    LCD_voidsendcommand(0x01);

	LCD_voidsendstring("I am task 1");
	//_delay_ms(500);// During this delay the task is running
	vTaskDelay( 3000);

}


}


void LCD_Task2_ (void*pvParamter)
{

for ( ; ; )
{
	LCD_voidsendcommand(0x01);

	LCD_voidsendstring("I am task 2");

	vTaskDelay( 3000);

}


}
