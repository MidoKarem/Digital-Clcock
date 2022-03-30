/*
 * TIMER_interface.h
 *
 *  Created on: Dec 11, 2021
 *      Author: mohamed karem
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER_voidINST(void);
u8 TIMER_u8SetCallBack(void (*copy_pvCallBack)(void));
void TIMER_voidSetCOMPAREMATCHvalue(u8 copy_u8signal);

void TIMER1_voidINST(void);
void TIMER1_voidSetTopValue(u16 copy_u16TopVal);
void TIMER1_voidSetChannelACOMPAREMATCH(u16 copy_u16CompVal);
u16 TIMER1_Value(void);

void ICU_voidINST(void);
u16 ICU_u16ReadCapture(void);
u8 ICU_voidEdgeSelect(u8 copy_u8Edge);
void ICU_voidInterruptEnable(void);
void ICU_voidInterruptDisable(void);


#define ICU_RISING_EDGE       1
#define ICU_FALLING_EDGE      0

#endif /* TIMER_INTERFACE_H_ */
