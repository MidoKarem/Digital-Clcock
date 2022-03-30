/*
 * Test_ADC.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */


#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"
#include"../HAL/LCD_driver/LCD_interface.h"

#include"../MCAL/ADC/ADC_interface.h"

void ADC_Keypad(void)
{
	u8 local_u8ADCReading;
	u16 local_u16Millivolt;

	DIO_voidsetpindirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_INPUT);
	DIO_voidsetportdirection(DIO_u8PORTD,DIO_u8PORT_OUTPUT);
	ADC_voidINST();
	LCD_voidINST();
	while(1)
	{
		local_u8ADCReading= ADC_u8GetChannelRead(0);
		local_u16Millivolt=((u32)local_u8ADCReading*5000UL)/256UL;
		 LCD_voidsendDATA(local_u16Millivolt/10);
		LCD_voidsendstring("c");
		for(u16 i=0;i<70000;i++);
		LCD_voidsendcommand(0b00000001);






	}
}
