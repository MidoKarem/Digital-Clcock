///*
// * main.c
// *
// *  Created on: Nov 2, 2021
// *      Author: mohamed karem
// */
///*
//int main( void)
//{
//	//blinkled();
////	anim();
//
//return 0;
//}
//*/
///*
// * anims.c
// *
// *  Created on: Nov 6, 2021
// *      Author: mohamed karem
// */
//
//#include "library/bitmath.h"
//#include "library/STD_types.h"
//#include "MCAL/DIO_driver/DIO_interface.h"
//#define F_CPU 8000000UL
//#include<util/delay.h>
//int main (void)
//{
//	// define PORT to make animation
//	u8 PORTID=DIO_u8PORTA;
//
//
//
//
//	// Initialization
//	/*
//	 define PORT Direction
//	 clear PORT
//	 */
//	DIO_voidsetportdirection(PORTID, DIO_u8PORT_OUTPUT);
//	DIO_voidsetportvalue(PORTID,DIO_u8PORT_LOW);
//	u8 LedNum=0;
//	while(1)
//	{
//	//anim 1 move to right
//		LedNum=0;
//	for( ; LedNum  <8	;LedNum++)
//	{   DIO_voidsetportvalue(PORTID,DIO_u8PORT_LOW);
//		DIO_voidsetpinvalue(PORTID,LedNum, DIO_u8PIN_HIGH);
//		_delay_ms(1000);
//	}
//
//
//	DIO_voidsetportvalue(PORTID,DIO_u8PORT_LOW);
//	_delay_ms(1000);
//
//	//anim 2 move to left
//	 LedNum=7;
//		for(	; LedNum  >=0	;LedNum--)
//		{   DIO_voidsetportvalue(PORTID,DIO_u8PORT_LOW);
//			DIO_voidsetpinvalue(PORTID,LedNum, DIO_u8PIN_HIGH);
//			_delay_ms(1000);
//		}
//		DIO_voidsetportvalue(PORTID,DIO_u8PORT_LOW);
//			_delay_ms(1000);
//	    }
//
//
//
//
//
//
//
//return 0;
//}
//
//
//
//
#include "library/STD_Types.h"
#include "library/bitmath.h"
#include "MCAL/DIO_driver/DIO_interface.h"
#include "MCAL/TIMER/TIMER_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "HAL/LCD_driver/LCD_interface.h"
#include "HAL/LCD_driver/Log_interface.h"
#include<avr/delay.h>

#define F_CPU 8000000UL


#define SHIFT 0

/*Global variables*/
volatile u8 hour = 0;
volatile u8 min = 0;
volatile u16 sec = 0;
volatile u32 num_overflow = 0;
volatile u8 u8AlarmMin = 5;

/*Function prototypes*/
void vidCount(void);
void vidInitClock(void);
void vidIncrementHour(void);
void vidIncrementMinute(void);
void vidDecrementHour(void);
void vidDecrementMinute(void);

void vidModifyHour(void);
void vidModifyMinute(void);



void vidCount(void) {
	num_overflow++;
	if (num_overflow == 125) {

		num_overflow = 0;
		sec++;
		if (sec < 60) {
			/*Writing seconds*/
			LCD_voidGoToXY(0,6+SHIFT);
			LCD_voidsendDATA(sec/10+48);
			LCD_voidsendDATA(sec%10+48);

		}
		else {
			sec = 0;
			LCD_voidGoToXY(0,6+SHIFT);
			LCD_voidsendDATA(sec/10+48);
			LCD_voidsendDATA(sec%10+48);
			min++;

			if (min < 60) {
				/*Writing minutes*/
				LCD_voidGoToXY(0,3+SHIFT);
					LCD_voidsendDATA(min/10+48);
					LCD_voidsendDATA(min%10+48);

			}
			else  {
				min = 0;
				LCD_voidGoToXY(0,3+SHIFT);
					LCD_voidsendDATA(min/10+48);
					LCD_voidsendDATA(min%10+48);

				hour++;
				if (hour < 24) {
					/*Writing hours*/
					LCD_voidGoToXY(0,0+SHIFT);
						LCD_voidsendDATA(hour/10+48);
						LCD_voidsendDATA(hour%10+48);


				}
				else {
					hour = 0;
					LCD_voidGoToXY(0,0+SHIFT);
					LCD_voidsendDATA(hour/10+48);
					LCD_voidsendDATA(hour%10+48);

				}
			}
		}
	}
}


int main()
{
	/*Initialization*/
	    LCD_voidINST();
	    DIO_voidsetpindirection(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PIN_INPUT);
	    DIO_voidsetpinvalue(DIO_u8PORTD,DIO_u8PIN4,1);

	  DIO_voidsetpindirection(DIO_u8PORTD,DIO_u8PIN5,DIO_u8PIN_INPUT);
	   DIO_voidsetpinvalue(DIO_u8PORTD,DIO_u8PIN5,1);


		vidInitClock();

		/*Setting External Interrupt pin direction as Input*/
		/*INT 0*/
			DIO_voidsetpindirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPUT);
			DIO_voidsetpinvalue(DIO_u8PORTD,DIO_u8PIN2,1);

			/*INT 1*/
			DIO_voidsetpindirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPUT);
			DIO_voidsetpinvalue(DIO_u8PORTD,DIO_u8PIN3,1);



		/*Setting External Interrupt 0, used for incrementing hours*/
		EXTI_voidINT0int();



			EXTI_u8SetCallBack(vidModifyHour);





		/*Setting External Interrupt 1, used for incrementing minutes*/
		EXTI_voidINT1int();
		EXTI1_u8SetCallBack(vidModifyMinute);
		/*Setting Timer 0, used for counting*/
				TIMER_voidINST();
					/*Setting interrupt for Timer 0*/

				TIMER_u8SetCallBack(vidCount);

		/*Setting global interrupt flag*/
		GIE_voidENABLE();

		while(1) {
		}

	return 0;

}

void vidIncrementHour(void) {
	hour++;
	if (hour > 24) {
		hour = 0;
	}
	LCD_voidGoToXY(0,0+SHIFT);
	LCD_voidsendDATA(hour/10+48);
	LCD_voidsendDATA(hour%10+48);

}

void vidIncrementMinute(void) {
	min++;
	if (min > 59) {
		min = 0;
	}
	LCD_voidGoToXY(0,3+SHIFT);
	LCD_voidsendDATA(min/10+48);
	LCD_voidsendDATA(min%10+48);

}

void vidDecrementHour(void) {
	hour--;
	if (hour < 0) {
		hour = 24;
	}
	LCD_voidGoToXY(0,0+SHIFT);
	LCD_voidsendDATA(hour/10+48);
	LCD_voidsendDATA(hour%10+48);

}

void vidDecrementMinute(void) {
	min--;
	if (min < 0) {
		min = 59;
	}
	LCD_voidGoToXY(0,3+SHIFT);
	LCD_voidsendDATA(min/10+48);
	LCD_voidsendDATA(min%10+48);

}


void vidInitClock(void) {
	LCD_voidsendcommand(0x01);
	LCD_voidsendcommand(0x02);
	LCD_voidsendDATA(hour/10+48);
	LCD_voidsendDATA(hour%10+48);
	LCD_voidsendDATA(':');
	LCD_voidsendDATA(min/10+48);
	LCD_voidsendDATA(min%10+48);
	LCD_voidsendDATA(':');
	LCD_voidsendDATA(sec/10+48);
	LCD_voidsendDATA(sec%10+48);

}

void vidModifyHour(void){

	while( DIO_u8getpinvalue(DIO_u8PORTD,DIO_u8PIN4) != 0 &&  DIO_u8getpinvalue(DIO_u8PORTD,DIO_u8PIN5) !=0);

	if( DIO_u8getpinvalue(DIO_u8PORTD,DIO_u8PIN4)== 0)
		vidIncrementHour();

	if( DIO_u8getpinvalue(DIO_u8PORTD,DIO_u8PIN5)== 0)
		vidDecrementHour();


}
void vidModifyMinute(void){

	while( DIO_u8getpinvalue(DIO_u8PORTD,DIO_u8PIN4) != 0 &&  DIO_u8getpinvalue(DIO_u8PORTD,DIO_u8PIN5) !=0);
	if( DIO_u8getpinvalue(DIO_u8PORTD,DIO_u8PIN4)== 0)
		vidIncrementMinute();

	if( DIO_u8getpinvalue(DIO_u8PORTD,DIO_u8PIN5)== 0)
		vidDecrementMinute();



}
