/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    eeprom.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _EEPROM_H    /* Guard against multiple inclusion */
#define _EEPROM_H

#include "config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom7_i2c_master.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"

#define EEPROM_1_CTRL_ADDR     0x50

#define EEPROM_USERDATA_ADDR1     0x0000      //0x03B2
#define EEPROM_USERDATA_ADDR2     0x0400
#define EEPROM_USERDATA_ADDR3     0x0800
#define EEPROM_FACDATA_ADDR     0x0c00

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */
#define EXAMPLE_CONSTANT 0


    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */
typedef struct _GROUP_DATA_ {
		uint8_t level;
		uint8_t group[4];       //?????group 0   //group[0] = 00000000 => G1 G2 G3 G4 G5 G6 G7 G8
                                                     //group[1] = 00000000 => G9 G10 G11 G12 G13 G14 G15 G16
                                                     //group[2] = 00000000 => G17 G18 G19 G20 G21 G22 G23 G24
                                                     //group[3] = 00000000 => G25 G26 G27 G28 G29 G30 G31 G32
		uint8_t compensation;   //????0
		uint8_t resv1;        //??
        uint8_t resv2;        //??
} GroupData;
#if 0
typedef struct _ALS_MAX_ {
    uint8_t ALSMAX_MSB;
    uint8_t ALSMAX_LSB;
}EEPAls_max;

typedef struct _ALS_MIN_ {
    uint8_t ALSMIN_MSB;
    uint8_t ALSMIN_LSB;
}EEPAls_min;

typedef struct _ALS_TABLE_ {
    uint8_t ALSTABLE_MSB;
    uint8_t ALSTABLE_LSB;
}EEPAls_table;
#endif
typedef struct _EEPROM_USER_DATA_ {
    GroupData DATA[112];
    uint8_t ucSN[15];
	uint8_t ucModelnm[15];
    uint8_t drbo_NUM;
    uint8_t LCW_NUM;
    uint16_t Als_max;
    uint16_t Als_min;
    uint16_t  Als_table[8];
    uint16_t Als_target;
    //EEPAls_max Als_max_data;
    //EEPAls_min Als_min_data;
    //EEPAls_table Als_table_data[8];
} EEPROMData;       // total 946 byte

//extern GroupData GroupDataDefault;
//extern EEPROMData EEDataDefault;
    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
#if 0   
    typedef struct _example_struct_t {
        /* Describe structure member. */
        int some_number;

        /* Describe structure member. */
        bool some_flag;

    } example_struct_t;
#endif

    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */
    //int ExampleFunction(int param1, int param2);
uint16_t EEPROM_Read(uint8_t i2c1_ctrl_addr);
uint16_t EEPROM_Write(uint8_t i2c1_ctrl_addr);
uint32_t  EEPROM_Read_LCW(uint16_t i2c1_ctrl_addr,uint8_t *pdata,size_t size);
void EEPROM_Write_LCW(uint16_t i2c1_ctrl_addr,size_t size);
uint32_t  EEPROM_Read_Data(uint16_t i2c1_ctrl_addr,EEPROMData *pdata);
void EEPROM_Write_Data(uint16_t i2c1_ctrl_addr,EEPROMData *ptr);
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
