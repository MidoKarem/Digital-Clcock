/*
 * anims.c
 *
 *  Created on: Nov 6, 2021
 *      Author: mohamed karem
 */
#define F_CPU 8000000UL
#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"

#include<avr/delay.h>
void anim (void)
{
	// define PORT to make animation
	u8 PORTID=DIO_u8PORTA;




	// intialization
	/*
	 define PORT Direction
	 clear PORT
	 */
	DIO_voidsetportdirection(PORTID, DIO_u8PORT_OUTPUT);
	DIO_voidsetportvalue(PORTID,DIO_u8PORT_LOW);
	u8 arr[8]={0b00000001,0b00000010,0b000000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000};
    s8 LedNum1,LedNum2;
	while(1)
	{
	//anim 1 move to right
		 LedNum1=0 ;
	for(  ; LedNum1  <8	;LedNum1++)
	{
		DIO_voidsetportvalue(PORTID,arr[LedNum1]);
		 _delay_ms(1000);


	}


	DIO_voidsetportvalue(PORTID,DIO_u8PORT_LOW);
	 _delay_ms(1000);

	//anim 2 move to left
	 LedNum2  =7;
		for( 	; LedNum2  >=0	;LedNum2--)
		{  DIO_voidsetportvalue(PORTID,arr[LedNum2]);
			 _delay_ms(1000);
		}


		DIO_voidsetportvalue(PORTID,DIO_u8PORT_LOW);
			 _delay_ms(1000);


	}








}




