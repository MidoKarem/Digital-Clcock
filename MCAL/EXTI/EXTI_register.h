/*
 * EXTI_register.h
 *
 *  Created on: Nov 20, 2021
 *      Author: mohamed karem
 */

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_
//enable INt 0,INT 1 ,2
#define GICR *((volatile u8*)0x5B)
#define GICR_INT1 7
#define GICR_INT0 6
#define GICR_INT2 5

//flag interrupt event hapened
#define GIFR *((volatile u8*)0x5A)
#define GIFR_INT1 7
#define GIFR_INT0 6
#define GIFR_INT2 5

#define MCUCR *((volatile u8*)0x55)
#define MCUCR_ISC11 3
#define MCUCR_ISC10 2
#define MCUCR_ISC01 1
#define MCUCR_ISC00 0

#define MCUCSR *((volatile u8*)0x54)
#define MCUCSR_ISC2 6
/*global interrupt enable*/
#define SREG *((volatile u8*)0x5F)
#define SREG_I 7

#endif /* EXTI_REGISTER_H_ */
