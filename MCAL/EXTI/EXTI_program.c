/*
  * EXTI_program.c
 *
 *  Created on: Nov 20, 2021
 *      Author: mohamed karem
 */

#include"../../library/STD_types.h"
#include"../../library/bitmath.h"
#include"EXTI_interface.h"
#include"EXTI_private.h"
#include"EXTI_register.h"
#include"EXTI_config.h"

void (*EXTI_INT0func)(void)=Null;
void (*EXTI_INT1func)(void)=Null;
void EXTI_voidINT0int(void)
{
	/*enable INT0 (PIE)*/
#if INT0_STATE==ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INT0_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error"wrong INT0_STATE choice"
#endif

#if INT0_SENSE_CONTROL ==LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_SENSE_CONTROL==ON_CHANGE
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_SENSE_CONTROL==FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE_CONTROL==RISING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#else
#error "wrong INT0_SENSE_CONTROL choice"
#endif


}
void __vector_1(void) __attribute__((signal));
	void __vector_1(void)
	{
	// 	DIO_voidsetpinvalue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);

		EXTI_INT0func();
	}

void __vector_2(void) __attribute__((signal));
    void __vector_2(void)
		{
		// 	DIO_voidsetpinvalue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);

			EXTI_INT1func();
		}

void GIE_voidENABLE(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDISABLE(void)
{
	CLR_BIT(SREG,SREG_I);
}



/*void EXTI_voidINT0int(void){
	// set INT0 Falling edge

	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);

	//enable INT0
	SET_BIT( GICR,GICR_INT0);


}
*/
void EXTI_voidINT1int(void){
	// set INT1 Rising edge

	   SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);

		//enable INT1
		SET_BIT( GICR,GICR_INT1);

}
void EXTI_voidINT2int(void){
	// set INT2 Rising edge

		   SET_BIT(MCUCSR,MCUCSR_ISC2);

			//enable INT2
			SET_BIT( GICR,GICR_INT2);


}


u8 EXTI_u8SetCallBack(void (*copy_pulsefunc)(void))
{
	EXTI_INT0func=copy_pulsefunc;
	return 1;
}



u8 EXTI1_u8SetCallBack(void (*copy_pulsefunc)(void))
		{
	EXTI_INT1func=copy_pulsefunc;
		return 1;
		}
