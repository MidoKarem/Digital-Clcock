/*
 * Test_UART.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */



#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"

void UART_SENDReceive_DATA(void)
{
	u8 local_u8Data;
	/*set pin 0 in port D as input(RX)*/
	DIO_voidsetpindirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_INPUT);
	/*set pin 1 in port D as output TX*/
	DIO_voidsetpindirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_OUTPUT);

	DIO_voidsetpindirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	UART_voidINST();
	while(1)
	{
		local_u8Data=UART_u8Recieve();
		if (local_u8Data=='1')
		{
			DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);

		}
		else if(local_u8Data=='2')
		{
			DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		}
		UART_voidSend('D');
	}
}
