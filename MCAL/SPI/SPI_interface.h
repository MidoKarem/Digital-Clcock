/*
 * SPI_interface.h
 *
 *  Created on: Jan 1, 2022
 *      Author: mohamed karem
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_u8SendRecieve(u8 copy_u8Data);


#endif /* SPI_INTERFACE_H_ */
