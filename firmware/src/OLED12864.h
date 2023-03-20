
#ifndef _OLED12864_H    /* Guard against multiple inclusion */
#define _OLED12864_H
#include "config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom3_i2c_master.h"
#include "definitions.h"
#define OLED_CTRL_ADDR     0x3c//0111 1000(0x78) --> 0011 1100(0x3c))
void OLEDInit(void);
void OLED_Show(void);
void OLED_Dark(void);


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif 




#ifndef _OLED12864_H    /* Guard against multiple inclusion */
#define _OLED12864_H
#include "MyI2C.h"
#define OLED_CTRL_ADDR     0x3c//0111 1000(0x78) --> 0011 1100(0x3c))
void OLEDInit(void);


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif 