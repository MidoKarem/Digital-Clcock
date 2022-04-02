/*
 * TIMER.program.c
 *
 *  Created on: Dec 16, 2021
 *      Author: mohamed karem
 */

#include "../../library/bitmath.h"
#include "../../library/STD_types.h"


#include"TIMER_interface.h"
#include"TIMER_config.h"
#include"TIMER_private.h"
#include"TIMER_register.h"
/* Global pointer to function to hold user function address*/
void(*TIMER_pvGlobalCallBack)(void)=Null;
/* Global pointer to function to hold user function address*/
void(*Timer_pvCallBack)(void)=Null;
void TIMER_voidINST(void)
{
//
//#if TIMER_Mode== Compare_Match
//	Enable compare match mode
//	SET_BIT(TCCR0,TCCR0_WGM01);
//	CLR_BIT(TCCR0,TCCR0_WGM00);
//#elif TIMER_Mode == OVERFLOW
//	CLR_BIT(TCCR0,TCCR0_WGM01);
//	CLR_BIT(TCCR0,TCCR0_WGM00);
//#endif
//



//	/*enable fastPWM*/
//
//	SET_BIT(TCCR0,TCCR0_WGM01);
//	SET_BIT(TCCR0,TCCR0_WGM00);
//
//	/*set prescaler to divide by 8*/
//	SET_BIT(TCCR0,TCCR0_CS02);
//	CLR_BIT(TCCR0,TCCR0_CS01);
//	SET_BIT(TCCR0,TCCR0_CS00);
//	/* define oco pin behavior*/
//	SET_BIT(TCCR0,TCCR0_COM1);
//	SET_BIT(TCCR0,TCCR0_COM0);

#if TIMER_Mode== COMPARE_MATCH
	/*Enable compare match mode*/
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
#elif TIMER_Mode == OVERFLOW
	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
#endif
	/* Enable compare match interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
	/* Set compare match mode value*/
	OCR0=124;
	/*set prescaler to divide by 256*/
	SET_BIT(TCCR0,TCCR0_CS02);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS00);
}
void TIMER_voidSetCOMPAREMATCHvalue(u8 copy_u8signal)
{
	/*set compare match value in OCR0 register*/
	OCR0=copy_u8signal;
}

void TIMER1_voidINST(void)
{

	/*set wave generation mode as fast PWM with ICR1 register as top value
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	set fast PWM in non inverted mode (set on top, clear on compare match)
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	*/


	/*set prescaler value as divide by 64*/
	SET_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);

	/*set Timer1 mode to normal mode (overflow)*/
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		CLR_BIT(TCCR1A,TCCR1A_WGM11);
		CLR_BIT(TCCR1B,TCCR1B_WGM12);
		CLR_BIT(TCCR1B,TCCR1B_WGM13);

		TCNT1L=0x00;
		TCNT1H=0x00;
}
void TIMER1_voidSetTopValue(u16 copy_u16TopVal)
{
//	ICR1 = copy_u16TopVal;
}





void TIMER1_voidSetChannelACompareMatch(u16 copy_u16CompVal)
{
	//OCR1A =copy_u16CompVal;

}

u16 TIMER1_Value(void)
{
	u16 ReturnVal=0;
	ReturnVal=(u16)TCNT1L;
	ReturnVal=((u16)(TCNT1H<<8))+ReturnVal;


	return ReturnVal;
}



void ICU_voidINST(void)
{
	/*initialize ICU trigger as rising edge*/
//	SET_BIT(TCCR1B,TCCR1B_ICES1);
	/*Enable for ICU interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}





u16 ICU_u16ReadCapture(void)
{
	//return ICR1;
}





u8 ICU_voidEdgeSelect(u8 copy_u8Edge)
{
	u8 local_u8ErrorStatus = 0;
	if(copy_u8Edge == ICU_RISING_EDGE)
	{
		//SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(copy_u8Edge == ICU_FALLING_EDGE)
	{
		//CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else
	{
		local_u8ErrorStatus =1;
	}
	return local_u8ErrorStatus;
}
u8 TIMER_u8SetCallBack(void(*copy_pvCallBack)(void))
{
	u8 local_u8ErrorState= 0;
	if(copy_pvCallBack != Null)
	{
		Timer_pvCallBack= copy_pvCallBack;

	}
	else
	{
		local_u8ErrorState =1;

	}
	return local_u8ErrorState;
}















u8 ICU_u8SetCallBack(void (*copy_pvCallBack)(void))
{
	u8 local_u8ErrorState=0;
	if(copy_pvCallBack != Null)
	{
	//	ICU_pvGlobalCallBack = copy_pvCallBack;
	}
	else
	{
		local_u8ErrorState=1;
	}
	return local_u8ErrorState;
}

void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	Timer_pvCallBack();
}
/*
void __vector_6(void)__attribute__((signal));
void __vector_6(void)
{
	//ICU_pvGlobalCallBack();
}
*/
