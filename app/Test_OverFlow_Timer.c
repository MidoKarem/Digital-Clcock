/*
 * Test_OverFlow_Timer.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */

#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"
#include"../MCAL/TIMER/TIMER_interface.h"
#include"../MCAL/EXTI/EXTI_interface.h"


#define F_CPU 8000000UL
u16 num_overflow=0;
void LED_Toggle(void);
void LED_Toggle(void)
{   num_overflow++;
if( num_overflow== 125)
	{u8 status= DIO_u8getpinvalue(DIO_u8PORTB,DIO_u8PIN0);

	DIO_voidsetpinvalue(DIO_u8PORTB,DIO_u8PIN0,(status^ 1));
	num_overflow=0;}
}
void Timer_Overflow_1000msBlinkingLED(void)
{
DIO_voidsetpindirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
DIO_voidsetpinvalue(DIO_u8PORTB,DIO_u8PIN0,1);


TIMER_voidINST();
TIMER_u8SetCallBack(&LED_Toggle);
GIE_voidENABLE();

while(1)
{

}

}
