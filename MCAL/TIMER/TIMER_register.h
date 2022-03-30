/*
 * TIMER_register.h
 *
 *  Created on: Dec 11, 2021
 *      Author: mohamed karem
 */

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


#define TCCR0    *((volatile u8*)0x53)
#define TCCR0_WGM00     6               //Waveform generation mode
#define TCCR0_COM1      5               //set compare match output mode
#define TCCR0_COM0      4               //set compare match output mode
#define TCCR0_WGM01     3               //Waveform generation mode
#define TCCR0_CS02      2               //prescaler
#define TCCR0_CS01      1               //prescaler
#define TCCR0_CS00      0               //prescaler

#define OCR0   *((volatile u8* )0x5C)   //output compare match register

#define TIMSK *((volatile u8*)0x59)
#define TIMSK_TICIE1    5               //ICU Interrupt enable
#define TIMSK_OCIE0     1               //compare match interrupt enable
#define TIMSK_TOIE0     0               //overflow interrupt enable


#define TCCR1A              *((volatile u8*)0x4F) //control register
#define TCCR1A_COM1A1        7                     //set OCR1 pin in non-PWM and in PWM-mode
#define TCCR1A_COM1A0       6                     //set OCR1 pin in non-PWM and in PWM-mode
#define TCCR1A_COM1B1       5                     //set OCR1 pin in non-PWM and in PWM-mode
#define TCCR1A_COM1B0       4                     //set OCR1 pin in non-PWM and in PWM-mode
#define TCCR1A_WGM11        1                     //wave generation mode
#define TCCR1A_WGM10        0                     //wave generation mode

#define TCCR1B       *((volatile u8*)0x4E)        //control register
#define TCCR1B_WGM13        4                     //wave generation mode
#define TCCR1B_WGM12        3                     //wave generation mode
#define TCCR1B_CS12         2                     //clock select
#define TCCR1B_CS11         1                     //clock select
#define TCCR1B_CS10         0                     //clock select



#define OCR1AL       *((volatile u8*)0x4A)
#define OCR1AH       *((volatile u8*)0x4B)
#define OCR1BL       *((volatile u8*)0x48)
#define OCR1BH       *((volatile u8*)0x49)

#define TCNT1L      *((volatile u8*)0x4C)
#define TCNT1H      *((volatile u8*)0x4D)
#endif /* TIMER_REGISTER_H_ */
