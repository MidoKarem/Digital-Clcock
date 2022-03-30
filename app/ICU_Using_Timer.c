/*
 * ICU_Using_Timer.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */

#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"
#include"../MCAL/TIMER/TIMER_interface.h"
#include"../MCAL/EXTI/EXTI_interface.h"


#include"../MCAL/EXTI/EXTI_register.h"
#include"../HAL/LCD_driver/LCD_interface.h"
#include "../HAL/LCD_driver/Log_interface.h"
#define F_CPU 8000000UL
#include<util\delay.h>
//void LED_Toggle(void);
u8 ONFunction=0;
u16 TON=0;
u16 TOFF=0;
u16 Frequency=0;
u16 DutyCycle=0;
void ICU(void)
{
	/* first time on function  -->  start timer1 to calculate Ton, EXTI  next timefalling edge  */
	  /* initalize Timer 1, set value =0 */
		/* freq =0.95hz  time=1 s */
	if(ONFunction ==0)
		{ TIMER1_voidINST();
		//falling edge
		CLR_BIT(MCUCR,MCUCR_ISC00);
	    SET_BIT(MCUCR,MCUCR_ISC01);
	    ONFunction=1;
		}
	else if (ONFunction ==1)
		{
		TON=TIMER1_Value();
		TIMER1_voidINST();
		// rising edge
		CLR_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		ONFunction=2;

		}
	else if(ONFunction==2)
	{

		TOFF=TIMER1_Value();
		ONFunction=3;
	}

	}
void Test_ICU(void)
{
//DIO_voidsetpindirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
//TIMER_voidINST();
//GIE_voidEnable();
//TIMER_u8SetCallBack(&LED_Toggle);
//u8 local_u8counter;
//DIO_voidsetpindirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_OUTPUT);
//TIMER_voidINST();
//	while(1)
//{
//		for(local_u8counter=0;local_u8counter<255;local_u8counter++)
//		{
//			TIMER_voidSetCOMPAREMATCHvalue(local_u8counter);
//			_delay_ms(50);
//		}
//
//}
    /* LCD Initilaize */
	/* LCD Initializations */
	LCD_voidINST();


	 LCD_voidGoToXY(0,0);
	LCD_voidsendstring("Freq = ");
	 LCD_voidGoToXY(0,13);
	LCD_voidsendstring("Hz");

	 LCD_voidGoToXY(1,1);
	LCD_voidsendstring("Duty = ");
	 LCD_voidGoToXY(1,13);
	LCD_voidsendstring("%");



	/* out PWM signal With different duty cycle value*/
	DIO_voidsetpindirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_OUTPUT);
	TIMER_voidINST();
	u8 local_u8counter= 127;
	TIMER_voidSetCOMPAREMATCHvalue(local_u8counter);

	/*  duty cycle= 50%   ,frequency = 8Mhz/1024/256 =32hz  ---time=0.0125  s*/






	/* EXTI pin 0 rising edge enable INT0 */
	/*INT 0*/
		DIO_voidsetpindirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPUT);

		EXTI_voidINT0int();
		EXTI_u8SetCallBack(&ICU);
		GIE_voidENABLE();

		while(ONFunction!=3);
		Frequency=(TON+TOFF);

		DutyCycle=TON*100/(TON+TOFF);


		 LCD_voidGoToXY(0,8);
		Log_voidPrintNumber(Frequency);
		 LCD_voidGoToXY(1,8);
		Log_voidPrintNumber(DutyCycle);



while(1)
{


}


}
