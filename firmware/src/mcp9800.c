/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Innolux

  @File Name
    mcp9800.c

  @Summary
 *  Common library for message creation and parsing.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "mcp9800.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */
//int global_data;

/***************************************************************************
MCP9800 User Initial()
 **************************************************************************/
void MCP9800UserInit(void)
{
    int ts1_alert_temp, ts2_alert_temp;
    int ts1_alert_off_temp, ts2_alert_off_temp;

    ts1_alert_temp = MCP9800_LIMIT_TSET_TS1_DEFAULT;
    ts2_alert_temp = MCP9800_LIMIT_TSET_TS2_DEFAULT;

    ts1_alert_off_temp = MCP9800_HYST_TS1_DEFAULT;
    ts2_alert_off_temp = MCP9800_HYST_TS2_DEFAULT;

    // MCP9800 TS1 CONFIG registers
    MCP9800I2c1ConfigRegWrite(MCP9800_CONFIG_REG, MCP9800_CONFIG_TS1_DEFAULT);
    // Set TS1 alert temperature
    MCP9800ProgramAlertTS1(ts1_alert_temp);
    // Set TS1 hysteresis temperature
    MCP9800ProgramHystTS1(ts1_alert_off_temp);


    // MCP9800 TS2 CONFIG registers
    MCP9800I2c2ConfigRegWrite(MCP9800_CONFIG_REG, MCP9800_CONFIG_TS2_DEFAULT);
    // Set TS2 alert temperature
    MCP9800ProgramAlertTS2(ts2_alert_temp);
    // Set TS1 hysteresis temperature
    MCP9800ProgramHystTS2(ts2_alert_off_temp);

}

/***************************************************************************
I2C1 Master MCP9800 CONFIG register write
 **************************************************************************/
uint8_t MCP9800I2c1ConfigRegWrite(uint8_t i2c1_reg_addr, uint8_t i2c1_reg_data)
{
	uint8_t i2c1_config_write_buf[2];

	i2c1_config_write_buf[0] = i2c1_reg_addr;

	i2c1_config_write_buf[1] = i2c1_reg_data;

	if(!SERCOM7_I2C_Write(MCP9800_CTRL_ADDR, &i2c1_config_write_buf[0], 0x02))
	{
		return false;
	}

	return true;
}

uint8_t MCP9800I2c1ConfigRegRead(uint8_t i2c1_reg_addr, uint8_t *i2c1_pData)
{
    uint8_t i2c1_config_read_buf;
	i2c1_config_read_buf = 0x01;   
 	//if(!SERCOM7_I2C_Read(MCP9800_CTRL_ADDR, i2c1_reg_addr, i2c1_pData, 0x01))
    SERCOM7_I2C_Write(MCP9800_CTRL_ADDR, &i2c1_config_read_buf , 0x01);
    if(!SERCOM7_I2C_Read(i2c1_reg_addr, i2c1_pData, 0x01))    
	{
		return false;
	}

	return true;
}

/******************************************************************************
 * Function:        MCP9800ProgramAlertTS1(int Alert)
 *
 * PreCondition:    Alert temperature known from Pot.
 *
 * Input:           Alert temp.
 *
 * Output:          None
 *
 * Overview:        Config MCP9800 Alert Temp and Hysteresis using i2c
 *
 * Side Effects:    None
 ******************************************************************************/
void MCP9800ProgramAlertTS1(int Alert1)
{
    // MCP9800 TS1 Limit Temp Set registers
    MCP9800I2c1Write(MCP9800_LIMIT_TSET_REG, Alert1);
}

void MCP9800ProgramHystTS1(int Thyst1)
{
    // MCP9800 TS1 Temperature Hysteresis Register
    MCP9800I2c1Write(MCP9800_THYST_REG, Thyst1);
}

/***************************************************************************
I2C1 Master write
 **************************************************************************/
uint8_t MCP9800I2c1Write(uint8_t i2c1_reg_addr, uint16_t i2c1_reg_data)
{
	uint8_t i2c1_write_buf[3];

	i2c1_write_buf[0] = i2c1_reg_addr;

	i2c1_write_buf[1] = (uint8_t)i2c1_reg_data;

	i2c1_write_buf[2] = 0x00;

	if(!SERCOM7_I2C_Write(MCP9800_CTRL_ADDR, &i2c1_write_buf[0], 0x03))
	{
		return false;
	}

	return true;
}


/***************************************************************************
I2C1 Master read
 **************************************************************************/
uint8_t MCP9800I2c1Read(uint8_t i2c1_reg_addr, uint8_t *i2c1_pData)
{
    uint8_t i2c1_Write_wdata[1];
#if 0    
	//uint8_t i2c1_Read_buf[3];
    uint8_t i2c1_Write_buf;
	//i2c1_Read_buf[0] = 0x00;
    //i2c1_Read_buf[0] = 0x00;
    //i2c1_Read_buf[0] = 0x00;
    i2c1_Write_buf = 0x00;
    
	//if(!SERCOM7_I2C_Read(MCP9800_CTRL_ADDR, i2c1_reg_addr, i2c1_pData, 0x02))
    SERCOM7_I2C_Write(MCP9800_CTRL_ADDR, &i2c1_Write_buf, 0x01);
    //SERCOM7_I2C_Write(MCP9800_CTRL_ADDR, &i2c1_reg_addr, 0x01);
    if(!SERCOM7_I2C_Read(MCP9800_CTRL_ADDR, i2c1_pData, 0x01))    
	{
		return false;
	}
#endif
    
    i2c1_Write_wdata[0] = 0x00;    
    if(!SERCOM7_I2C_WriteRead(i2c1_reg_addr, &i2c1_Write_wdata[0], 0x01, i2c1_pData, 0x02))
	{
		return false;
	}
	return true;
}


/***************************************************************************
I2C1 Get temperature 1
 **************************************************************************/
void MCP9800GetTemperatureTS1(float *TempC_Abs, uint8_t *negative)
{
	uint8_t ts1_read_buf[2];
	int16_t ts1_upper_byte, ts1_lower_byte;
	int16_t ts1_temperature;
	//uint8_t ts1_upper_byte= 0, ts1_lower_byte=0;   
    float   RawTempAbs;

    *negative = 0;

	//MCP9800I2c1Read(MCP9800_TA_REG, &ts1_read_buf[0]);
    
    MCP9800I2c1Read(MCP9800_CTRL_ADDR, &ts1_read_buf[0]);        

	ts1_upper_byte = ts1_read_buf[0];
	ts1_lower_byte = ts1_read_buf[1];

    // move 'ts1_lower_byte' to lower 4 bits
    ts1_lower_byte = ts1_lower_byte / 16;

    // move 'ts1_upper_byte' to 12 bits and add 'ts1_lower_byte' to lowest 4 bits
    ts1_temperature = (ts1_upper_byte * 16) + ts1_lower_byte;

    // Save 12 bit value as a float so division by 16 will give decimal value
    RawTempAbs = (float)ts1_temperature;

    if(ts1_upper_byte > 127)    // If upper 8 bytes were greater than 127, value is
    {                           // actually negative so set sign bit and get abs value of temp
        *negative = 1;
        RawTempAbs = RawTempAbs / 16;
        RawTempAbs = 256 - RawTempAbs;
    }
    else                        // Temp is positive so get decimal value
    {
        RawTempAbs = RawTempAbs / 16;
    }

    *TempC_Abs = RawTempAbs;    // Save final value in pointer back to ProcessIO

}

/***************************************************************************
I2C2 Master MCP9800 CONFIG register write
 **************************************************************************/
uint8_t MCP9800I2c2ConfigRegWrite(uint8_t i2c2_reg_addr, uint8_t i2c2_reg_data)
{
	uint8_t i2c2_config_write_buf[2];

	i2c2_config_write_buf[0] = i2c2_reg_addr;

	i2c2_config_write_buf[1] = i2c2_reg_data;

	if(!SERCOM3_I2C_Write(MCP9800_CTRL_ADDR, &i2c2_config_write_buf[0], 0x02))
	{
		return false;
	}

	return true;
}

uint8_t MCP9800I2c2ConfigRegRead(uint8_t i2c2_reg_addr, uint8_t *i2c2_pData)
{
    //if(!SERCOM3_I2C_Read(MCP9800_CTRL_ADDR, i2c2_reg_addr, i2c2_pData, 0x01))
	if(!SERCOM3_I2C_Read(i2c2_reg_addr, i2c2_pData, 0x01))
	{
		return false;
	}

	return true;
}

/******************************************************************************
 * Function:        MCP9800ProgramAlertTS2(int Alert)
 *
 * PreCondition:    Alert temperature known from Pot.
 *
 * Input:           Alert temp.
 *
 * Output:          None
 *
 * Overview:        Config MCP9800 Alert Temp and Hysteresis using i2c
 *
 * Side Effects:    None
 ******************************************************************************/
void MCP9800ProgramAlertTS2(int Alert2)
{
    // MCP9800 TS1 Limit Temp Set registers
    MCP9800I2c2Write(MCP9800_LIMIT_TSET_REG, Alert2);
}

void MCP9800ProgramHystTS2(int Thyst2)
{
    // MCP9800 TS1 Temperature Hysteresis Register
    MCP9800I2c2Write(MCP9800_THYST_REG, Thyst2);
}

/***************************************************************************
I2C2 Master write
 **************************************************************************/
uint8_t MCP9800I2c2Write(uint8_t i2c2_reg_addr, uint16_t i2c2_reg_data)
{
	uint8_t i2c2_write_buf[3];

	i2c2_write_buf[0] = i2c2_reg_addr;

	i2c2_write_buf[1] = (uint8_t)i2c2_reg_data;

	i2c2_write_buf[2] = 0x00;

	if(!SERCOM3_I2C_Write(MCP9800_CTRL_ADDR, &i2c2_write_buf[0], 0x03))
	{
		return false;
	}

	return true;
}


/***************************************************************************
I2C2 Master read
 **************************************************************************/
uint8_t MCP9800I2c2Read(uint8_t i2c2_reg_addr, uint8_t *i2c2_pData)
{
    //if(!SERCOM3_I2C_Read(MCP9800_CTRL_ADDR, i2c2_reg_addr, i2c2_pData, 0x02))
	if(!SERCOM3_I2C_Read(i2c2_reg_addr, i2c2_pData, 0x02))
	{
		return false;
	}

	return true;
}


/***************************************************************************
I2C2 Get temperature 2
 **************************************************************************/
void MCP9800GetTemperatureTS2(float *TempC_Abs, uint8_t *negative)
{
    uint8_t ts2_read_buf[2];
    int16_t ts2_upper_byte, ts2_lower_byte;
    int16_t ts2_temperature;
    float   RawTempAbs;

    *negative = 0;

    MCP9800I2c2Read(MCP9800_TA_REG, &ts2_read_buf[0]);

    ts2_upper_byte = ts2_read_buf[0];
    ts2_lower_byte = ts2_read_buf[1];

    // move 'ts2_lower_byte' to lower 4 bits
    ts2_lower_byte = ts2_lower_byte / 16;

    // move 'ts2_upper_byte' to 12 bits and add 'ts2_lower_byte' to lowest 4 bits
    ts2_temperature = (ts2_upper_byte * 16) + ts2_lower_byte;

    // Save 12 bit value as a float so division by 16 will give decimal value
    RawTempAbs = ts2_temperature;

    if(ts2_upper_byte > 127)    // If upper 8 bytes were greater than 127, value is
    {                           // actually negative so set sign bit and get abs value of temp
        *negative = 1;
        RawTempAbs = RawTempAbs / 16;
        RawTempAbs = 256 - RawTempAbs;
    }
    else                        // Temp is positive so get decimal value
    {
        RawTempAbs = RawTempAbs / 16;
    }

    *TempC_Abs = RawTempAbs;    // Save final value in pointer back to ProcessIO

}
/* *****************************************************************************
 End of File
 */
