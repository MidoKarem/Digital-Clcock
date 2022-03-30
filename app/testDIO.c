/*
 * testDIO.c
 *
 *  Created on: Nov 18, 2021
 *      Author: mohamed karem
 */

/*
 * test first lecture to turn on led
 *  blinking led
 *  animation leds
 */
#define F_CPU 8000000
#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include<avr/io.h>
#include<util/delay.h>

//void testDIO(void)
//{
//	DDRA=0b00000001;
//	PORTA=0b00000001;

//DDRA=0b00000001;
//while(1){
//PORTA=0b00000001;
//_delay_ms(1000);
//PORTA=0b00000000;
//_delay_ms(1000);
//}

//DDRA=0b11111111;
//
//u8 counter=0;
//
//while(1)
//{
//for(counter=0;counter<8;counter++)
//{
//	PORTA=1<<counter;
//	_delay_ms(1000);
//
//}
//PORTA=0;
//_delay_ms(1000);
//for(counter=0;counter<7;counter++)
//{
//	PORTA=128>>counter;
//	_delay_ms(1000);
//
//}
//}
//
//
//}
//void testDIO(void)
//{
//  u8 arr[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
//	DDRA=0b11111111;
//	while(1)
//{
//
//
//
//for(u8 counter=0;counter<10;counter++)
//{
//  PORTA=arr[counter];
//  _delay_ms(1000);
//}
//}
//}


//void testDIO(void)
//{
//  DDRB=0b0000000;
//  PORTB=0b11111111;
//
//  DDRA=0xff;
//
//while(1)
//{
//  if( GET_BIT(PINB,0)==0)
//  {
//	  PORTA=0xff;
//	  _delay_ms(500);
//	 PORTA=0x00;
//	 _delay_ms(500);
//  }
//
//  else{
//	  PORTA=0x00;
//  }
//}



//
//
//void testDIO(void)
//{
//	DDRA=0b11111111;
//	PORTA=0b00000111;
//
//	u8 arr[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
//
//	u8 counter;
//	DDRB=0b11111111;
//	DDRC=0b11111111;
//	while(1)
//	{ // red led on
//	PORTA=0b00000001;
//
//	for(counter=10;counter>0;counter--)
//	{
//		if(counter==10)
//		{
//			PORTB=arr[0];
//			PORTC=arr[1];
//			_delay_ms(1000);
//
//
//		}
//		else
//		{
//
//			PORTB=arr[counter];
//			PORTC=arr[0];
//			_delay_ms(1000);
//
//	    }
//}
//	PORTA=0b00000000;
//	// yellow_led on
//	PORTA=0b00000010;
//
//
//	for(counter=3;counter>0;counter--)
//	{
//
//
//			PORTB=arr[counter];
//			PORTC=arr[0];
//			_delay_ms(1000);
//
//	    }
//
//	PORTA=0b00000000;
//
//	//  green led on
//	PORTA=0b00000100;
//
//	for(counter=10;counter>0;counter--)
//	{
//		if(counter==10)
//		{
//			PORTB=arr[0];
//			PORTC=arr[1];
//			_delay_ms(1000);
//
//
//		}
//		else
//		{
//
//			PORTB=arr[counter];
//			PORTC=arr[0];
//			_delay_ms(1000);
//
//	    }
//}
//	PORTA=0b00000000;
//	}
//
//
//
//
//
//}
//
//
//
//
//
//
//
//
//
//
//
//





















