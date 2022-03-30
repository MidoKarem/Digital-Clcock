/*
 * Test_EXTI.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */


#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"\
#include"../MCAL/EXTI/EXTI_interface.h"
#define F_CPU 8000000UL
#include<avr\delay.h>
void LED_ISR0(void)
{
	DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0,1);
	_delay_ms(1000);
	DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0,0);


}

void LED_ISR1(void)
{
	DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN1,1);
	_delay_ms(1000);
	DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN1,0);




}
void EXTI(void)
{/*INT 0*/
	DIO_voidsetpindirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPUT);
	DIO_voidsetpinvalue(DIO_u8PORTD,DIO_u8PIN2,1);
	DIO_voidsetpindirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	/*INT 1*/
		DIO_voidsetpindirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPUT);
		DIO_voidsetpinvalue(DIO_u8PORTD,DIO_u8PIN3,1);

	DIO_voidsetpindirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);

	EXTI_voidINT0int();

	EXTI_voidINT1int();
	GIE_voidENABLE();
	EXTI_u8SetCallBack(&LED_ISR0);
	EXTI1_u8SetCallBack(&LED_ISR1);



	while(1)
	{

	}
}




