#include "../library/bitmath.h"
#include "../library/STD_types.h"
#include "../MCAL/DIO_driver/DIO_interface.h"
#include<util/delay.h>
void blinkled( void)
{

	 DIO_voidsetpindirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);



	 while(1)
	 {
		u8 i=0;
		 while(i<=10){
		i++;
		_delay_ms(1000);
		 }
		 DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0, DIO_u8PIN_HIGH);
		 DIO_voidsetpinvalue(DIO_u8PORTA,DIO_u8PIN0, DIO_u8PIN_LOW);
		 _delay_ms(1000);

	 }


}
