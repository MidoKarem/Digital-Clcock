/*
 * Test_WD.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */



#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"

#include"../MCAL/WatchDog/WATCHDOG_interface.h"

#define F_CPU 8000000UL
#include<avr\delay.h>
void WatchDog_Reset(void)
{

	DIO_voidsetpindirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	_delay_ms(1000);
	DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
	 WGT_voidEnable();
	 WGT_voidSleep(6);
	 while(1)
	 {

	 }
}
