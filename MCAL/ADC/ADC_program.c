/*
 * ADC_program.c
 *
 *  Created on: Dec 4, 2021
 *      Author: mohamed karem
 */

#include "../../library/bitmath.h"
#include "../../library/STD_types.h"
#include"ADC_interface.h"
#include"ADC_config.h"
#include"ADC_private.h"
#include"ADC_register.h"

void ADC_voidINST(void)
{
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*enable left adjust*/
	SET_BIT(ADMUX,ADMUX_ADLAR);
	/*choose prescaler value as 128*/

	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	/*enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}


	u8 ADC_u8GetChannelRead(u8 copy_u8Channel)
	{
		/*Clear MUX bits*/
		ADMUX  &= 0b11100000;

		/*Set MUX bits with desired value*/
		ADMUX |= copy_u8Channel;

		/*Start Conversion*/

		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*wait until conversion*/
		while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);
		/*Flag Clear*/
		SET_BIT(ADCSRA,ADCSRA_ADIF);
		return ADCH;

	}

