/*
 * UART_register.h
 *
 *  Created on: Dec 31, 2021
 *      Author: mohamed karem
 */

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_
#define  UDR   *((volatile u8*)0x2C)
#define UCSRA   *((volatile u8*)0x2B)
#define UCSRA_RXC  7
#define UCSRA_TXC  6
#define UCSRA_UDRE  5
#define UCSRA_FE    4
#define UCSRA_DDR    3
#define UCSRA_PE    2
#define UCSRA_I2X    1
#define UCSRA_MFCM   0
#define UCSRB    *((volatile u8*)0x2A)
#define UCSRB_RXCIE   7   //complete interrupt enable
#define UCSRB_TXCIE   6   //transmit interrupt enable
#define UCSRB_UDRIE   5   //data register empty interrupt enable
#define UCSRB_RXEN    4   //receiver enable
#define UCSRB_TXEN    3   //transmitter enable
#define UCSRB_USCZ2   2   //data size bit number 2,
#define UCSRB_RXB8    1   // receive data bit 8
#define UCSRB_TXB8    0   //transmit data bit 8
#define UCSRC    *((volatile u8*)0x40)
#define UCSRC_URSEL  7    //register select
#define UCSRC_UMSEL  6    //mode select
#define UCSRC_UPM1   5    //parity mode
#define UCSRC_UPM0   4    //parity mode
#define UCSRC_USBS   3    //stop bit select
#define UCSRC_UCSZ1  2    //character size
#define UCSRC_UCSZ0  1    //character size
#define UCSRC_UCPOL  0    //clock polarity
#define UBRRL    *((volatile u8*)0x29)

#endif /* UART_REGISTER_H_ */
