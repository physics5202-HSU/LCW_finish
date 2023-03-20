/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    mcp9800.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _MCP9800_H    /* Guard against multiple inclusion */
#define _MCP9800_H
#include "definitions.h"
#define MCP9800_CTRL_ADDR		0x48

// Register
#define MCP9800_TA_REG          0x00    // Ambient Temperature Register (TA)
#define MCP9800_CONFIG_REG      0x01    // Sensor Configuration Register (CONFIG)
#define MCP9800_THYST_REG       0x02    // Temperature Hysteresis Register (THYST)
#define MCP9800_LIMIT_TSET_REG  0x03    // Temperature Limit-Set Register (TSET)

// Set
#define MCP9800_CONFIG_TS1_DEFAULT      0x60    // ALERT bit 2: 1 = Active-high, 0 = Active-low
#define MCP9800_CONFIG_TS2_DEFAULT      0x60    // ALERT bit 2: 1 = Active-high, 0 = Active-low
#define MCP9800_LIMIT_TSET_TS1_DEFAULT  80      // 80 degree
#define MCP9800_LIMIT_TSET_TS2_DEFAULT  80      // 80 degree
#define MCP9800_HYST_TS1_DEFAULT        75      // 75 degree
#define MCP9800_HYST_TS2_DEFAULT        75      // 75 degree

//--------------------------------------------------------------------------
// Prototypes
//--------------------------------------------------------------------------
// I2C1
void    MCP9800UserInit(void);
uint8_t MCP9800I2c1ConfigRegWrite(uint8_t i2c1_reg_addr, uint8_t i2c1_reg_data);
uint8_t MCP9800I2c1ConfigRegRead(uint8_t i2c1_reg_addr, uint8_t *i2c1_pData);
void    MCP9800ProgramAlertTS1(int Alert1);
void    MCP9800ProgramHystTS1(int Thyst1);

uint8_t MCP9800I2c1Write(uint8_t i2c1_reg_addr, uint16_t i2c1_reg_data);
uint8_t MCP9800I2c1Read(uint8_t i2c1_reg_addr, uint8_t *i2c1_pData);
void    MCP9800GetTemperatureTS1(float *TempC_Abs, uint8_t *negative);

// I2C2
uint8_t MCP9800I2c2ConfigRegWrite(uint8_t i2c2_reg_addr, uint8_t i2c2_reg_data);
uint8_t MCP9800I2c2ConfigRegRead(uint8_t i2c2_reg_addr, uint8_t *i2c2_pData);
void    MCP9800ProgramAlertTS2(int Alert2);
void    MCP9800ProgramHystTS2(int Thyst2);

uint8_t MCP9800I2c2Write(uint8_t i2c2_reg_addr, uint16_t i2c2_reg_data);
uint8_t MCP9800I2c2Read(uint8_t i2c2_reg_addr, uint8_t *i2c2_pData);
void MCP9800GetTemperatureTS2(float *TempC_Abs, uint8_t *negative);

#endif	/* _MCP9800_H_ */

/* *****************************************************************************
 End of File
 */
