/*
 * Test_SPI.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */

#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include"../MCAL/SPI/SPI_interface.h"
void SPI(void)
{
	u8 Local_u8Data;
	/*master main*/
	/*MOSI*/
	DIO_voidsetpindirection(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PORT_OUTPUT);
	/*MISO*/
	DIO_voidsetpindirection(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_INPUT);
	/*SCK*/
	DIO_voidsetpindirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_OUTPUT);

	/*SS, */
	DIO_voidsetpindirection(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_OUTPUT);
	DIO_voidsetpinvalue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_HIGH);

	DIO_voidsetpindirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	SPI_voidMasterInit();
	DIO_voidsetpinvalue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_LOW);

u8 val=0;
	for(u8 counter =0;counter<10;counter++)
		{

			val= SPI_u8SendRecieve(counter+48);

			_delay_ms(1000);
		}
	if(val == 'A')
				{	DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0,1);
}

	while(1)
	{


//		if(Local_u8Data == '3')
//		{
//			DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
//		}
//		else if(Local_u8Data == '4')
//		{
//			DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
//		}

	}
}


