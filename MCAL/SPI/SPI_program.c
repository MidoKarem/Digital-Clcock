/*
 * SPI_program.c
 *
 *  Created on: Jan 1, 2022
 *      Author: mohamed karem
 */
#include "../../library/bitmath.h"
#include "../../library/STD_types.h"


#include"SPI_interface.h"
#include"SPI_config.h"
#include"SPI_register.h"
#include"SPI_private.h"

void SPI_voidMasterInit(void)
{
	/*enable master mode*/
	SET_BIT(SPCR,SPCR_MSTR);
	/* SPI enable*/
	SET_BIT(SPCR,SPCR_SPE);
	/*data order must be the same in master and slave*/
	/*DORD is 0 by default*/

	/*clock polarity must be the same in master and slave*/
	/*CPOL is 0 by default-->low while no communication*/

	/*clock phase must be the same in master and slave*/
	/*CPHA is 0 by default -->sample at leading edge and setup at trailing edge*/

	/*choose SCK frequency :divide by 8*/
	CLR_BIT(SPSR,SPSR_SPI2X);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);
}
void SPI_voidSlaveInit(void)
{
	/*enable slave mode*/
	CLR_BIT(SPCR,SPCR_MSTR);
	/*SPI enable*/
	SET_BIT(SPCR,SPCR_SPE);
}
u8 SPI_u8SendRecieve(u8 copy_u8Data)
{

  /*send Data*/
	SPDR= copy_u8Data;
	/*waiting until data transmitted*/
	while(GET_BIT(SPSR,SPSR_SPIF)==0);
	return SPDR;



}



