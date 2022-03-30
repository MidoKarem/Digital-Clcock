/*
 * EXTI_config.h
 *
 *  Created on: Nov 20, 2021
 *      Author: mohamed karem
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
/*
 * options;
 * 1-ENaBLed
 * 2-DISABLEd
 */

#define INT0_STATE    ENABLED

/*
 * options;
 * 1-low level
 * 2-on change
 * 3-falling edge
 * 4-rising edge
 */
#define INT0_SENSE_CONTROL FALLING_EDGE

#endif /* EXTI_CONFIG_H_ */
