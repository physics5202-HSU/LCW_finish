#ifndef _LCW_H    /* Guard against multiple inclusion */
#define _LCW_H


#include "config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom3_i2c_master.h"
#include "configuration.h"
#include "definitions.h"

#define Driving_Board_1_CTRL_ADDR     0x28//0101 0000(0x50) --> 0010 1000(0x28)
#define Driving_Board_2_CTRL_ADDR     0x29//0101 0010(0x52) --> 0010 1001(0x29)
#define Driving_Board_3_CTRL_ADDR     0x2A//0101 0100(0x54) --> 0010 1010(0x2A)
#define Driving_Board_4_CTRL_ADDR     0x2B//0101 0110(0x56) --> 0010 1011(0x2B)
#define Driving_Board_5_CTRL_ADDR     0x2C//0101 1000(0x58) --> 0010 1100(0x2C)
#define Driving_Board_6_CTRL_ADDR     0x2D//0101 1010(0x5A) --> 0010 1101(0x2D)
#define Driving_Board_7_CTRL_ADDR     0x2E//0101 1100(0x5C) --> 0010 1110(0x2E)
#define Driving_Board_8_CTRL_ADDR     0x2F//0101 1110(0x5E) --> 0010 1111(0x2F) 
#define Driving_Board_9_CTRL_ADDR     0x30//0110 0000(0x60) --> 0011 0000(0x30) 
#define Driving_Board_10_CTRL_ADDR     0x31//0110 0010(0x62) --> 0011 0001(0x31)
#define Driving_Board_11_CTRL_ADDR     0x32//0110 0100(0x64) --> 0011 0010(0x32)  (Reserved)
#define Driving_Board_12_CTRL_ADDR     0x33//0110 0110(0x66) --> 0011 0011(0x33)  (Reserved) 
#define Driving_Board_13_CTRL_ADDR     0x34//0110 1000(0x68) --> 0011 0100(0x34)  (Reserved)
#define Driving_Board_14_CTRL_ADDR     0x35//0110 1010(0x6A) --> 0011 0101(0x35)  (Reserved)
//#define Driving_Board_15_CTRL_ADDR     0x36//0110 1100(0x6C) --> 0011 0110(0x36)  (Reserved)
//#define Driving_Board_16_CTRL_ADDR     0x37//0110 1110(0x6E) --> 0011 0111(0x37)  (Reserved)


//void LCW_Brightness(uint8_t i2c2_ctrl_addr,uint8_t ctrl_channel,uint8_t v_value);
void LCW_Brightness_HMI(uint8_t i2c2_ctrl_addr,uint8_t v_ch1_value,uint8_t v_ch2_value);
void LCW_Brightness(uint8_t i2c2_ctrl_addr,uint8_t v_value);

void LCW_Demo(uint8_t i2c2_ctrl_addr);
void LCW_Manual(uint8_t i2c2_ctrl_addr);
void LCW_8Channel(uint8_t i2c2_ctrl_addr,uint8_t v_ch1_value,uint8_t v_ch2_value,uint8_t v_ch3_value,uint8_t v_ch4_value,uint8_t v_ch5_value,uint8_t v_ch6_value,uint8_t v_ch7_value,uint8_t v_ch8_value);

#ifdef __cplusplus
extern "C" {
#endif



#define EXAMPLE_CONSTANT 0




#ifdef __cplusplus
}
#endif

#endif /* _LCW_H */

/* *****************************************************************************
 End of File
 */
