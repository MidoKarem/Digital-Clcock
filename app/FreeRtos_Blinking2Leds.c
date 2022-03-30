/*
 * lab1.c
 *
 *  Created on: Mar 25, 2022
 *      Author: mohamed karem
 */
#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"
#include "../MCAL/DIO_driver/DIO_register.h"
#include "../FREE_RTOS/FreeRTOS.h"
#include "../FREE_RTOS/task.h"
#include "../FREE_RTOS/FreeRTOSConfig.h"

 void init_DIOPins(void)
 {
	 DIO_voidsetpindirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	 DIO_voidsetpindirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);

	 DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	 DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);

 }


 void Blink_200ms_Task (void*pvParamter);
 void Blink_1000ms_Task (void*pvParamter);

void lab1(void)
{



	 init_DIOPins();

	 xTaskCreate(Blink_200ms_Task,NULL,70,NULL,2,NULL);
	 xTaskCreate(Blink_1000ms_Task,NULL,70,NULL,2,NULL);




	 vTaskStartScheduler( );





}


void Blink_200ms_Task (void*pvParamter)
{

for ( ; ; )
{

	DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0, DIO_u8getpinvalue(DIO_u8PORTA,DIO_u8PIN0)^ 1);
	vTaskDelay( 200);

}


}


void Blink_1000ms_Task (void*pvParamter)
{

for ( ; ; )
{

	DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN1, DIO_u8getpinvalue(DIO_u8PORTA,DIO_u8PIN1)^ 1);
	vTaskDelay( 1000);

}


}
