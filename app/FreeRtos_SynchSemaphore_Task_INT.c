/*
 * lab3.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */
#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"
#include "../MCAL/DIO_driver/DIO_register.h"

#include"../MCAL/EXTI/EXTI_interface.h"
#include"../HAL/LCD_driver/LCD_config.h"
#include"../HAL/LCD_driver/LCD_interface.h"

#define F_CPU 8000000UL
#include<avr\delay.h>
#include "../FREE_RTOS/macros.h"
#include "../FREE_RTOS/FreeRTOS.h"
#include "../FREE_RTOS/task.h"

#include "../FREE_RTOS/semphr.h"
#include "../FREE_RTOS/FreeRTOSConfig.h"
xSemaphoreHandle  Binarysemaphore = NULL;
xTaskHandle taskinit;
void LCD_Task (void*pvParamter);
void SWCheck_INT (void);
void INIT_Task (void*pvParamter);




void init_EXTI(void)
{

	/*INT 1*/
		DIO_voidsetpindirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPUT);
		DIO_voidsetpinvalue(DIO_u8PORTD,DIO_u8PIN3,1);


		EXTI_voidINT1int();

		GIE_voidENABLE();
	    EXTI1_u8SetCallBack(SWCheck_INT);

}







void lab3(void)
{


	init_EXTI();
	LCD_voidINST();
	 vSemaphoreCreateBinary( Binarysemaphore );

	 xTaskCreate(LCD_Task,NULL,70,NULL,2,NULL);

	 xTaskCreate(INIT_Task,NULL,70,NULL,3,&taskinit);


	 vTaskStartScheduler( );





}

void INIT_Task (void*pvParamter)
{

	 xSemaphoreTake( Binarysemaphore,( portTickType ) 10);
	 vTaskDelete(taskinit);
}
void LCD_Task (void*pvParamter)
{

for ( ; ; )
{
	if( xSemaphoreTake( Binarysemaphore,( portTickType ) 10) ==1)
	{
		LCD_voidsendcommand(0x01);

	    LCD_voidsendstring("Button is Pressed");

	    vTaskDelay( 500);
		LCD_voidsendcommand(0x01);


}


	}
}

void SWCheck_INT (void)
{

	xSemaphoreGiveFromISR(Binarysemaphore ,NULL);

}
