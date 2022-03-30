/*
 * WATCHDOG_register.h
 *
 *  Created on: Dec 24, 2021
 *      Author: mohamed karem
 */

#ifndef WATCHDOG_REGISTER_H_
#define WATCHDOG_REGISTER_H_

#define WDTCR        *((volatile u8*)0x41)
#define WDTCR_WDTCE   4
#define WDTCR_WDE     3
#define WDTCR_WDP2    2
#define WDTCR_WDP     1
#define WDTCR_WDP0    0

#endif /* WATCHDOG_REGISTER_H_ */
