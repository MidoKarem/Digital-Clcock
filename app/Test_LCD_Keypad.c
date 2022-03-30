/*
 * Test_LCD_Keypad.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */
#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include"../HAL/LCD_driver/LCD_config.h"
#include"../HAL/LCD_driver/LCD_interface.h"

#include"../MCAL/DIO_driver/DIO_interface.h"

#include"../HAL/Keypad_driver/keypad_interface.h"
#include"../HAL/Keypad_driver/keypad_config.h"
#define F_CPU 8000000UL
#include<util\delay.h>
void GetButtonKeyppad_PresentLCD(void)
{
	LCD_voidINST();
	keypad_voidInit();
	u8 pressed=0;

	while(1){
	LCD_voidGoToXY(0,0);
	LCD_voidsendstring("enter number");
	_delay_ms(1000);
	/*Clear display command */
	LCD_voidsendcommand(0b0000001);


	l1:pressed=keypad_u8GetPressedkey();
	if(pressed == 0) { goto l1;}

	else
	{
    LCD_voidGoToXY(0,0);
	LCD_voidsendstring("number_pressed=");
	LCD_voidGoToXY(1,6);
	 LCD_voidsendDATA(pressed);
	_delay_ms(2000);
		/*Clear display command */
	LCD_voidsendcommand(0b0000001);
	pressed=0;}

	}

}
