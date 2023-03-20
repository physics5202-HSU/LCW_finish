#include "lcw.h"

void LCW_Brightness_HMI(uint8_t i2c2_ctrl_addr,uint8_t v_ch1_value,uint8_t v_ch2_value)
{
    if (EDBG)
        SYS_CONSOLE_PRINT("LCW_Brightness [address:0x%02x][ch1 brightness:0x%02x][ch2 brightness:0x%02x]  ",i2c2_ctrl_addr,v_ch1_value,v_ch2_value);
    volatile I2C2_TRANSFER_STATUS transferStatusCmd = I2C2_TRANSFER_STATUS_ERROR;
    SERCOM3_I2C_CallbackRegister( I2C2_Callback, (uintptr_t)&transferStatusCmd );
    transferStatusCmd = I2C2_TRANSFER_STATUS_IN_PROGRESS;
    uint8_t v_brightness[9];
    v_brightness[0] = 0x02;
    v_brightness[1] = v_ch1_value;
    v_brightness[2] = v_ch2_value;
    v_brightness[3] = v_ch1_value;    
    v_brightness[4] = v_ch2_value;
    v_brightness[5] = v_ch1_value;
    v_brightness[6] = v_ch2_value;
    v_brightness[7] = v_ch1_value;
    v_brightness[8] = v_ch2_value;     
    SERCOM3_I2C_Write(i2c2_ctrl_addr, &v_brightness[0], 9);
    int count=0;
    while (transferStatusCmd != I2C2_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
}
void LCW_Brightness(uint8_t i2c2_ctrl_addr,uint8_t v_value)
{
    if (EDBG)
        SYS_CONSOLE_PRINT("LCW_Brightness [address:0x%02x][brightness:0x%02x]  ",i2c2_ctrl_addr,v_value);
    volatile I2C2_TRANSFER_STATUS transferStatusCmd = I2C2_TRANSFER_STATUS_ERROR;
    SERCOM3_I2C_CallbackRegister( I2C2_Callback, (uintptr_t)&transferStatusCmd );
    transferStatusCmd = I2C2_TRANSFER_STATUS_IN_PROGRESS;
    uint8_t v_brightness[9];
    v_brightness[0] = 0x02;
    v_brightness[1] = v_value;
    v_brightness[2] = v_value;
    v_brightness[3] = v_value;    
    v_brightness[4] = v_value;
    v_brightness[5] = v_value;
    v_brightness[6] = v_value;
    v_brightness[7] = v_value;
    v_brightness[8] = v_value;     
    SERCOM3_I2C_Write(i2c2_ctrl_addr, &v_brightness[0], 9);
    int count=0;
    while (transferStatusCmd != I2C2_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
}
void LCW_Demo(uint8_t i2c2_ctrl_addr)
{
    volatile I2C2_TRANSFER_STATUS transferStatusCmd = I2C2_TRANSFER_STATUS_ERROR;
    SERCOM3_I2C_CallbackRegister( I2C2_Callback, (uintptr_t)&transferStatusCmd );
    transferStatusCmd = I2C2_TRANSFER_STATUS_IN_PROGRESS;
    uint8_t v_brightness[9];
    v_brightness[0] = 0x01;
    v_brightness[1] = 0x02;
    v_brightness[2] = 0x02;
    v_brightness[3] = 0x00;    
    v_brightness[4] = 0x00;
    v_brightness[5] = 0x00;
    v_brightness[6] = 0x00;
    v_brightness[7] = 0x00;
    v_brightness[8] = 0x00;        
    SERCOM3_I2C_Write(i2c2_ctrl_addr, &v_brightness[0], 9);
    int count=0;
    while (transferStatusCmd != I2C2_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
}
void LCW_Manual(uint8_t i2c2_ctrl_addr)
{
    volatile I2C2_TRANSFER_STATUS transferStatusCmd = I2C2_TRANSFER_STATUS_ERROR;
    SERCOM3_I2C_CallbackRegister( I2C2_Callback, (uintptr_t)&transferStatusCmd );
    transferStatusCmd = I2C2_TRANSFER_STATUS_IN_PROGRESS;
    uint8_t v_brightness[9];
    v_brightness[0] = 0x00;
    v_brightness[1] = 0x00;
    v_brightness[2] = 0x00;
    v_brightness[3] = 0x00;    
    v_brightness[4] = 0x00;
    v_brightness[5] = 0x00;
    v_brightness[6] = 0x00;
    v_brightness[7] = 0x00;
    v_brightness[8] = 0x00;        
    SERCOM3_I2C_Write(i2c2_ctrl_addr, &v_brightness[0], 9);
    int count=0;
    while (transferStatusCmd != I2C2_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
}
void LCW_8Channel(uint8_t i2c2_ctrl_addr,uint8_t v_ch1_value,uint8_t v_ch2_value,uint8_t v_ch3_value,uint8_t v_ch4_value,uint8_t v_ch5_value,uint8_t v_ch6_value,uint8_t v_ch7_value,uint8_t v_ch8_value)
{
    volatile I2C2_TRANSFER_STATUS transferStatusCmd = I2C2_TRANSFER_STATUS_ERROR;
    SERCOM3_I2C_CallbackRegister( I2C2_Callback, (uintptr_t)&transferStatusCmd );
    transferStatusCmd = I2C2_TRANSFER_STATUS_IN_PROGRESS;
    uint8_t v_brightness[9];
    v_brightness[0] = 0x02;
    v_brightness[1] = v_ch1_value;
    v_brightness[2] = v_ch2_value;
    v_brightness[3] = v_ch3_value;    
    v_brightness[4] = v_ch4_value;
    v_brightness[5] = v_ch5_value;
    v_brightness[6] = v_ch6_value;
    v_brightness[7] = v_ch7_value;
    v_brightness[8] = v_ch8_value;       
    SERCOM3_I2C_Write(i2c2_ctrl_addr, &v_brightness[0], 9);
    int count=0;
    while (transferStatusCmd != I2C2_TRANSFER_STATUS_SUCCESS)
    {
        /*
        if(transferStatusCmd == I2C2_TRANSFER_STATUS_ERROR)
        {
            GPIO_PB09_High(false);
        }*/
        count++;
        if(count > I2C_Delay_ns)
        {
            //GPIO_PB09_High(false);
            break;
        }
    }
}