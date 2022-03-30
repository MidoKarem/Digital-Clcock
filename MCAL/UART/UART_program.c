/*
 * UART_program.c
 *
 *  Created on: Dec 31, 2021
 *      Author: mohamed karem
 */

#ifndef UART_PROGRAM_C_
#define UART_PROGRAM_C_
#include "../../library/bitmath.h"
#include "../../library/STD_types.h"
#include"UART_config.h"
#include"UART_interface.h"
#include"UART_private.h"
#include"UART_register.h"


void UART_voidINST(void)
{
	u8 local_u8UCSRC=0;
	/* setting bit number 7 to configure UCSRC register*/
	SET_BIT(local_u8UCSRC,7);
	/*choose 8 bit data size*/
	CLR_BIT(UCSRB,UCSRB_USCZ2);
	SET_BIT(local_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(local_u8UCSRC,UCSRC_UCSZ0);
	/*disable parity*/
	CLR_BIT(local_u8UCSRC,UCSRC_UPM0);
	CLR_BIT(local_u8UCSRC,UCSRC_UPM1);
	/*stop enable*/
	CLR_BIT(local_u8UCSRC,UCSRC_USBS);
	UCSRC=local_u8UCSRC;
	/*set baud rate to 9600*/
	UBRRL=51;
	/*receiver enable*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	/*transmitter enable*/
	SET_BIT(UCSRB,UCSRB_TXEN);

}

void UART_voidSend(u8 copy_u8Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);
	UDR=copy_u8Data;
}
u8 UART_u8Recieve(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;
}

#endif /* UART_PROGRAM_C_ */
