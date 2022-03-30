/*
 * lcd.c
 *
 *  Created on: Dec 1, 2021
 *      Author: mohamed karem
 */

#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include"../HAL/LCD_driver/LCD_config.h"
#include"../HAL/LCD_driver/LCD_interface.h"

#include <util/delay.h>

void LCD(void)
{


	LCD_voidINST();

	LCD_voidsendDATA('H');
	LCD_voidsendDATA('E');
	LCD_voidsendDATA('L');
	LCD_voidsendDATA('L');
	LCD_voidsendDATA('o');

	LCD_voidsendDATA('2');
	LCD_voidsendDATA('0');
	LCD_voidsendDATA('2');
	LCD_voidsendDATA('2');

	LCD_voidsendDATA(0x23);

	 _delay_ms(1000);
	 LCD_voidsendcommand(0x01);
}


