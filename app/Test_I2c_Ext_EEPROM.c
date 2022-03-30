/*
 * Test_I2c_Ext_EEPROM.c
 *
 *  Created on: Mar 26, 2022
 *      Author: mohamed karem
 */


#include"../MCAL/I2C/IIC_interface.h"
void I2C_EXT_EEPROM(void)
{

/*
	TWI_voidMasterINST(0x1010111);

	TWI_SendStartcondition();

	TWI_SendSlaveAddressWithWrite(  0xA0  );
	TWI_MasterSendDataByte(    'H'  );
	TWI_MasterSendDataByte(    'E'  );
	TWI_MasterSendDataByte(    'L'  );
	TWI_MasterSendDataByte(    'L'  );
	TWI_MasterSendDataByte(    'o'  );

	IIC_voidSendStopcondition();
*/

 EEPROM_Init();

	 EEPROM_WriteData("H");
	 EEPROM_ReadData();
	 //TWI_SendStartcondition();

	// TWI_SendSlaveAddressWithWrite(  0xA0  );
	// TWI_MasterSendDataByte(0x00);

//	 TWI_SendRepeatedStart();
	// TWI_SendSlaveAddressWithRead(0xA0);


	 //TWI_MasterReceiveDataByte(&data);

	// IIC_voidSendStopcondition();

//	for(u8 counter=0;counter<5;counter++)
//	{data[counter]=	EEPROM_ReadData();
//	}
}
