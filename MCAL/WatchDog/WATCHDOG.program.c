/*
 * WATCHDOG.program.c
 *
 *  Created on: Dec 24, 2021
 *      Author: mohamed karem
 */

#include "../../library/bitmath.h"
#include "../../library/STD_types.h"

#include"WATCHDOG_interface.h"
#include"WATCHDOG_register.h"
void WGT_voidEnable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}
void WGT_voiddisable(void)
{
	WDTCR|=0b00011000;

	/*write logic 0 on WDE*/
	CLR_BIT(WDTCR,WDTCR_WDE);
}

void WGT_voidSleep(u8 copy_u8Time)
{
	/*bit masking*/
	WDTCR&=0b11111000;
	/*set time value*/
	WDTCR |= copy_u8Time;
}
