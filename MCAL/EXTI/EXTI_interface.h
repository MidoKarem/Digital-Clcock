/*
 * EXTI_interface.h
 *
 *  Created on: Nov 20, 2021
 *      Author: mohamed karem
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
void EXTI_voidINT0int(void);
void EXTI_voidINT1int(void);
void EXTI_voidINT2int(void);


void GIE_voidENABLE(void);
void GIE_voidDISABLE(void);


u8 EXTI_u8SetCallBack(void (*copy_pulse_func)(void));


u8 EXTI1_u8SetCallBack(void (*copy_pulsefunc)(void));

#endif /* EXTI_INTERFACE_H_ */
