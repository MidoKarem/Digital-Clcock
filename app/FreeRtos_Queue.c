/*
 * FreeRtos_Queue.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */
#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include"../HAL/LCD_driver/LCD_config.h"
#include"../HAL/LCD_driver/LCD_interface.h"
#include"../HAL/Keypad_driver/keypad_interface.h"
#include"../HAL/Keypad_driver/keypad_config.h"
#include "../FREE_RTOS/FreeRTOS.h"
#include "../FREE_RTOS/task.h"

#include "../FREE_RTOS/queue.h"
#include "../FREE_RTOS/FreeRTOSConfig.h"

#include <util/delay.h>


 void LCD_Task_(void*pvParamter);
 void Keypad_Task (void*pvParamter);
 xQueueHandle buffer;

void lab4(void)
{



	LCD_voidINST();
	keypad_voidInit();
	 buffer=xQueueCreate(1,sizeof(char));
	 xTaskCreate( LCD_Task_,NULL,configMINIMAL_STACK_SIZE,NULL,3,NULL);
	 xTaskCreate(Keypad_Task,NULL,configMINIMAL_STACK_SIZE,NULL,3,NULL);




	 vTaskStartScheduler( );





}


void LCD_Task_(void*pvParamter)
{
	 u8 val=0xff;
	 u8 counter=0;
for ( ; ; )
{
	while(counter<6)
	{

   xQueueReceive(buffer,&val,0xff);

   if(val != 0xff)
   {
	   LCD_voidsendDATA(val);
		//_delay_ms(500);
		vTaskDelay( 1000);}
   counter++;
	}
	LCD_voidsendcommand(0b0000001);
	counter=0;
}


}


void Keypad_Task (void*pvParamter)
{ u8 val;

for ( ; ; )
{
val=	keypad_u8GetPressedkey();

if(val >='0'&&val<='9')
{
	xQueueSend(buffer,&val,0xff);


}
vTaskDelay( 50);
}


}


