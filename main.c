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
int main()
{

	//testDIO();
	// aim ();
	//LCD();

	lab4();

	return 0;

}
