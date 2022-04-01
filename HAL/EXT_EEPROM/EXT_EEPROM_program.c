/*
 * EXT_EEPROM_program.c
 *
 *  Created on: Feb 19, 2022
 *      Author: mohamed karem
 */
#include"../../library/STD_types.h"
#include"../../library/bitmath.h"
#include"../../MCAL/I2C/IIC_interface.h"

void EEPROM_Init(void){
	TWI_voidMasterINST(0b10100100);
}


void EEPROM_WriteData(u8 *array){
	 u8 i=0;
	    TWI_SendStartcondition();

		TWI_SendSlaveAddressWithWrite(  0xA0  );
		TWI_MasterSendDataByte(0x00);
		TWI_MasterSendDataByte(    array[i++]  );
//		TWI_MasterSendDataByte(   array[i++] );
//		TWI_MasterSendDataByte(   array[i++] );
//		TWI_MasterSendDataByte(   array[i++] );
//		TWI_MasterSendDataByte(    array[i++] );

		IIC_voidSendStopcondition();

}

u8   EEPROM_ReadData(void){



 u8 data;
		    TWI_SendStartcondition();

		    TWI_SendSlaveAddressWithWrite(  0xA0  );
			TWI_MasterSendDataByte(0x00);

			TWI_SendRepeatedStart();
			TWI_MasterSendDataByte(0xA1);


			TWI_MasterReceiveDataByte(&data);

			IIC_voidSendStopcondition();
return data;
}
