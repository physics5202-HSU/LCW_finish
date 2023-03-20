#include "BH1750FVI.h"

//bool ALS_Read(uint8_t i2c1_ctrl_addr, uint16_t *i2c1_pData)
uint16_t ALS_Read(uint8_t i2c1_ctrl_addr)
{    
    SYS_CONSOLE_PRINT("ALS_Read [address:0x%02x]  \r\n",i2c1_ctrl_addr);
    volatile I2C1_TRANSFER_STATUS transferStatusCmd = I2C1_TRANSFER_STATUS_ERROR;
    int count=0;
    SERCOM7_I2C_CallbackRegister( I2C1_Callback, (uintptr_t)&transferStatusCmd );
    //------------power on--------------
    uint8_t pwron[1];
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;
    pwron[0] = 0x01;
    SERCOM7_I2C_Write(i2c1_ctrl_addr, &pwron[0], 1);
    count=0;
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
    //------------One Time Measure 4Lx, 16ms--------------
    uint8_t onetimemeasure[1];
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;
    onetimemeasure[0] = 0x23;
    SERCOM7_I2C_Write(i2c1_ctrl_addr, &onetimemeasure[0], 1);
    count=0;
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
    //------------Get(Read) Data--------------
    uint8_t myData [2];    
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;
    if(!SERCOM7_I2C_Read(i2c1_ctrl_addr, &myData[0], 2))
	{
		return 0xFFFF;
	}
    count=0;
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
    uint16_t p_value = ((uint16_t)myData[0] << 8) | myData[1];
    SYS_CONSOLE_PRINT("ALS LX = 0x%02x%02x  %d\r\n",myData[0],myData[1],p_value);   
    return p_value;
}