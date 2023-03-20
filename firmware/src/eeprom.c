/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

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
#include <math.h>    
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "com_lib.h"
#include "uart_command.h"
#include "Judgeman.h"
#include "eeprom.h"
#include "tcpip/tcpip.h"
#include "tcpip/berkeley_api.h"
#include "tcpip/tcpip_manager.h"
#include "cJSON.h"
#include "system/console/sys_console.h"
#include "shared_settings.h"
/* TODO:  Include other files here if needed. */
EEPROMData Userdata;
//code NvramUserData UserDataDefault = {
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
GroupData GroupDataDefault = {
    .level = 0x00,
    .group[0] = 0x00,
    .group[1] = 0x00,
    .group[2] = 0x00,
    .group[3] = 0x00,
    .compensation = 0x00,
    .resv1 = 0x00,
    .resv2 = 0x00    
};


EEPROMData EEDataDefault = {
    .DATA[0].level = 0x00, .DATA[0].group[0] = 0x00, .DATA[0].group[1] = 0x00, .DATA[0].group[2] = 0x00, .DATA[0].group[3] = 0x00, .DATA[0].compensation = 0x00, .DATA[0].resv1 = 0x00, .DATA[0].resv2 = 0x00,
    .DATA[1].level = 0x00, .DATA[1].group[0] = 0x00, .DATA[1].group[1] = 0x00, .DATA[1].group[2] = 0x00, .DATA[1].group[3] = 0x00, .DATA[1].compensation = 0x00, .DATA[1].resv1 = 0x00, .DATA[1].resv2 = 0x00,
    .DATA[2].level = 0x00, .DATA[2].group[0] = 0x00, .DATA[2].group[1] = 0x00, .DATA[2].group[2] = 0x00, .DATA[2].group[3] = 0x00, .DATA[2].compensation = 0x00, .DATA[2].resv1 = 0x00, .DATA[2].resv2 = 0x00,
    .DATA[3].level = 0x00, .DATA[3].group[0] = 0x00, .DATA[3].group[1] = 0x00, .DATA[3].group[2] = 0x00, .DATA[3].group[3] = 0x00, .DATA[3].compensation = 0x00, .DATA[3].resv1 = 0x00, .DATA[3].resv2 = 0x00,
    .DATA[4].level = 0x00, .DATA[4].group[0] = 0x00, .DATA[4].group[1] = 0x00, .DATA[4].group[2] = 0x00, .DATA[4].group[3] = 0x00, .DATA[4].compensation = 0x00, .DATA[4].resv1 = 0x00, .DATA[4].resv2 = 0x00,
    .DATA[5].level = 0x00, .DATA[5].group[0] = 0x00, .DATA[5].group[1] = 0x00, .DATA[5].group[2] = 0x00, .DATA[5].group[3] = 0x00, .DATA[5].compensation = 0x00, .DATA[5].resv1 = 0x00, .DATA[5].resv2 = 0x00,
    .DATA[6].level = 0x00, .DATA[6].group[0] = 0x00, .DATA[6].group[1] = 0x00, .DATA[6].group[2] = 0x00, .DATA[6].group[3] = 0x00, .DATA[6].compensation = 0x00, .DATA[6].resv1 = 0x00, .DATA[6].resv2 = 0x00,
    .DATA[7].level = 0x00, .DATA[7].group[0] = 0x00, .DATA[7].group[1] = 0x00, .DATA[7].group[2] = 0x00, .DATA[7].group[3] = 0x00, .DATA[7].compensation = 0x00, .DATA[7].resv1 = 0x00, .DATA[7].resv2 = 0x00,
    .DATA[8].level = 0x00, .DATA[8].group[0] = 0x00, .DATA[8].group[1] = 0x00, .DATA[8].group[2] = 0x00, .DATA[8].group[3] = 0x00, .DATA[8].compensation = 0x00, .DATA[8].resv1 = 0x00, .DATA[8].resv2 = 0x00,
    .DATA[9].level = 0x00, .DATA[9].group[0] = 0x00, .DATA[9].group[1] = 0x00, .DATA[9].group[2] = 0x00, .DATA[9].group[3] = 0x00, .DATA[9].compensation = 0x00, .DATA[9].resv1 = 0x00, .DATA[9].resv2 = 0x00,

    .DATA[10].level = 0x00, .DATA[10].group[0] = 0x00, .DATA[10].group[1] = 0x00, .DATA[10].group[2] = 0x00, .DATA[10].group[3] = 0x00, .DATA[10].compensation = 0x00, .DATA[10].resv1 = 0x00, .DATA[10].resv2 = 0x00,
    .DATA[11].level = 0x00, .DATA[11].group[0] = 0x00, .DATA[11].group[1] = 0x00, .DATA[11].group[2] = 0x00, .DATA[11].group[3] = 0x00, .DATA[11].compensation = 0x00, .DATA[11].resv1 = 0x00, .DATA[11].resv2 = 0x00,
    .DATA[12].level = 0x00, .DATA[12].group[0] = 0x00, .DATA[12].group[1] = 0x00, .DATA[12].group[2] = 0x00, .DATA[12].group[3] = 0x00, .DATA[12].compensation = 0x00, .DATA[12].resv1 = 0x00, .DATA[12].resv2 = 0x00,
    .DATA[13].level = 0x00, .DATA[13].group[0] = 0x00, .DATA[13].group[1] = 0x00, .DATA[13].group[2] = 0x00, .DATA[13].group[3] = 0x00, .DATA[13].compensation = 0x00, .DATA[13].resv1 = 0x00, .DATA[13].resv2 = 0x00,
    .DATA[14].level = 0x00, .DATA[14].group[0] = 0x00, .DATA[14].group[1] = 0x00, .DATA[14].group[2] = 0x00, .DATA[14].group[3] = 0x00, .DATA[14].compensation = 0x00, .DATA[14].resv1 = 0x00, .DATA[14].resv2 = 0x00,
    .DATA[15].level = 0x00, .DATA[15].group[0] = 0x00, .DATA[15].group[1] = 0x00, .DATA[15].group[2] = 0x00, .DATA[15].group[3] = 0x00, .DATA[15].compensation = 0x00, .DATA[15].resv1 = 0x00, .DATA[15].resv2 = 0x00,
    .DATA[16].level = 0x00, .DATA[16].group[0] = 0x00, .DATA[16].group[1] = 0x00, .DATA[16].group[2] = 0x00, .DATA[16].group[3] = 0x00, .DATA[16].compensation = 0x00, .DATA[16].resv1 = 0x00, .DATA[16].resv2 = 0x00,
    .DATA[17].level = 0x00, .DATA[17].group[0] = 0x00, .DATA[17].group[1] = 0x00, .DATA[17].group[2] = 0x00, .DATA[17].group[3] = 0x00, .DATA[17].compensation = 0x00, .DATA[17].resv1 = 0x00, .DATA[17].resv2 = 0x00,
    .DATA[18].level = 0x00, .DATA[18].group[0] = 0x00, .DATA[18].group[1] = 0x00, .DATA[18].group[2] = 0x00, .DATA[18].group[3] = 0x00, .DATA[18].compensation = 0x00, .DATA[18].resv1 = 0x00, .DATA[18].resv2 = 0x00,
    .DATA[19].level = 0x00, .DATA[19].group[0] = 0x00, .DATA[19].group[1] = 0x00, .DATA[19].group[2] = 0x00, .DATA[19].group[3] = 0x00, .DATA[19].compensation = 0x00, .DATA[19].resv1 = 0x00, .DATA[19].resv2 = 0x00,

    .DATA[20].level = 0x00, .DATA[20].group[0] = 0x00, .DATA[20].group[1] = 0x00, .DATA[20].group[2] = 0x00, .DATA[20].group[3] = 0x00, .DATA[20].compensation = 0x00, .DATA[20].resv1 = 0x00, .DATA[20].resv2 = 0x00,
    .DATA[21].level = 0x00, .DATA[21].group[0] = 0x00, .DATA[21].group[1] = 0x00, .DATA[21].group[2] = 0x00, .DATA[21].group[3] = 0x00, .DATA[21].compensation = 0x00, .DATA[21].resv1 = 0x00, .DATA[21].resv2 = 0x00,
    .DATA[22].level = 0x00, .DATA[22].group[0] = 0x00, .DATA[22].group[1] = 0x00, .DATA[22].group[2] = 0x00, .DATA[22].group[3] = 0x00, .DATA[22].compensation = 0x00, .DATA[22].resv1 = 0x00, .DATA[22].resv2 = 0x00,
    .DATA[23].level = 0x00, .DATA[23].group[0] = 0x00, .DATA[23].group[1] = 0x00, .DATA[23].group[2] = 0x00, .DATA[23].group[3] = 0x00, .DATA[23].compensation = 0x00, .DATA[23].resv1 = 0x00, .DATA[23].resv2 = 0x00,
    .DATA[24].level = 0x00, .DATA[24].group[0] = 0x00, .DATA[24].group[1] = 0x00, .DATA[24].group[2] = 0x00, .DATA[24].group[3] = 0x00, .DATA[24].compensation = 0x00, .DATA[24].resv1 = 0x00, .DATA[24].resv2 = 0x00,
    .DATA[25].level = 0x00, .DATA[25].group[0] = 0x00, .DATA[25].group[1] = 0x00, .DATA[25].group[2] = 0x00, .DATA[25].group[3] = 0x00, .DATA[25].compensation = 0x00, .DATA[25].resv1 = 0x00, .DATA[25].resv2 = 0x00,
    .DATA[26].level = 0x00, .DATA[26].group[0] = 0x00, .DATA[26].group[1] = 0x00, .DATA[26].group[2] = 0x00, .DATA[26].group[3] = 0x00, .DATA[26].compensation = 0x00, .DATA[26].resv1 = 0x00, .DATA[26].resv2 = 0x00,
    .DATA[27].level = 0x00, .DATA[27].group[0] = 0x00, .DATA[27].group[1] = 0x00, .DATA[27].group[2] = 0x00, .DATA[27].group[3] = 0x00, .DATA[27].compensation = 0x00, .DATA[27].resv1 = 0x00, .DATA[27].resv2 = 0x00,
    .DATA[28].level = 0x00, .DATA[28].group[0] = 0x00, .DATA[28].group[1] = 0x00, .DATA[28].group[2] = 0x00, .DATA[28].group[3] = 0x00, .DATA[28].compensation = 0x00, .DATA[28].resv1 = 0x00, .DATA[28].resv2 = 0x00,
    .DATA[29].level = 0x00, .DATA[29].group[0] = 0x00, .DATA[29].group[1] = 0x00, .DATA[29].group[2] = 0x00, .DATA[29].group[3] = 0x00, .DATA[29].compensation = 0x00, .DATA[29].resv1 = 0x00, .DATA[29].resv2 = 0x00,

    .DATA[30].level = 0x00, .DATA[30].group[0] = 0x00, .DATA[30].group[1] = 0x00, .DATA[30].group[2] = 0x00, .DATA[30].group[3] = 0x00, .DATA[30].compensation = 0x00, .DATA[30].resv1 = 0x00, .DATA[30].resv2 = 0x00,
    .DATA[31].level = 0x00, .DATA[31].group[0] = 0x00, .DATA[31].group[1] = 0x00, .DATA[31].group[2] = 0x00, .DATA[31].group[3] = 0x00, .DATA[31].compensation = 0x00, .DATA[31].resv1 = 0x00, .DATA[31].resv2 = 0x00,
    .DATA[32].level = 0x00, .DATA[32].group[0] = 0x00, .DATA[32].group[1] = 0x00, .DATA[32].group[2] = 0x00, .DATA[32].group[3] = 0x00, .DATA[32].compensation = 0x00, .DATA[32].resv1 = 0x00, .DATA[32].resv2 = 0x00,
    .DATA[33].level = 0x00, .DATA[33].group[0] = 0x00, .DATA[33].group[1] = 0x00, .DATA[33].group[2] = 0x00, .DATA[33].group[3] = 0x00, .DATA[33].compensation = 0x00, .DATA[33].resv1 = 0x00, .DATA[33].resv2 = 0x00,
    .DATA[34].level = 0x00, .DATA[34].group[0] = 0x00, .DATA[34].group[1] = 0x00, .DATA[34].group[2] = 0x00, .DATA[34].group[3] = 0x00, .DATA[34].compensation = 0x00, .DATA[34].resv1 = 0x00, .DATA[34].resv2 = 0x00,
    .DATA[35].level = 0x00, .DATA[35].group[0] = 0x00, .DATA[35].group[1] = 0x00, .DATA[35].group[2] = 0x00, .DATA[35].group[3] = 0x00, .DATA[35].compensation = 0x00, .DATA[35].resv1 = 0x00, .DATA[35].resv2 = 0x00,
    .DATA[36].level = 0x00, .DATA[36].group[0] = 0x00, .DATA[36].group[1] = 0x00, .DATA[36].group[2] = 0x00, .DATA[36].group[3] = 0x00, .DATA[36].compensation = 0x00, .DATA[36].resv1 = 0x00, .DATA[36].resv2 = 0x00,
    .DATA[37].level = 0x00, .DATA[37].group[0] = 0x00, .DATA[37].group[1] = 0x00, .DATA[37].group[2] = 0x00, .DATA[37].group[3] = 0x00, .DATA[37].compensation = 0x00, .DATA[37].resv1 = 0x00, .DATA[37].resv2 = 0x00,
    .DATA[38].level = 0x00, .DATA[38].group[0] = 0x00, .DATA[38].group[1] = 0x00, .DATA[38].group[2] = 0x00, .DATA[38].group[3] = 0x00, .DATA[38].compensation = 0x00, .DATA[38].resv1 = 0x00, .DATA[38].resv2 = 0x00,
    .DATA[39].level = 0x00, .DATA[39].group[0] = 0x00, .DATA[39].group[1] = 0x00, .DATA[39].group[2] = 0x00, .DATA[39].group[3] = 0x00, .DATA[39].compensation = 0x00, .DATA[39].resv1 = 0x00, .DATA[39].resv2 = 0x00,

    .DATA[40].level = 0x00, .DATA[40].group[0] = 0x00, .DATA[40].group[1] = 0x00, .DATA[40].group[2] = 0x00, .DATA[40].group[3] = 0x00, .DATA[40].compensation = 0x00, .DATA[40].resv1 = 0x00, .DATA[40].resv2 = 0x00,
    .DATA[41].level = 0x00, .DATA[41].group[0] = 0x00, .DATA[41].group[1] = 0x00, .DATA[41].group[2] = 0x00, .DATA[41].group[3] = 0x00, .DATA[41].compensation = 0x00, .DATA[41].resv1 = 0x00, .DATA[41].resv2 = 0x00,
    .DATA[42].level = 0x00, .DATA[42].group[0] = 0x00, .DATA[42].group[1] = 0x00, .DATA[42].group[2] = 0x00, .DATA[42].group[3] = 0x00, .DATA[42].compensation = 0x00, .DATA[42].resv1 = 0x00, .DATA[42].resv2 = 0x00,
    .DATA[43].level = 0x00, .DATA[43].group[0] = 0x00, .DATA[43].group[1] = 0x00, .DATA[43].group[2] = 0x00, .DATA[43].group[3] = 0x00, .DATA[43].compensation = 0x00, .DATA[43].resv1 = 0x00, .DATA[43].resv2 = 0x00,
    .DATA[44].level = 0x00, .DATA[44].group[0] = 0x00, .DATA[44].group[1] = 0x00, .DATA[44].group[2] = 0x00, .DATA[44].group[3] = 0x00, .DATA[44].compensation = 0x00, .DATA[44].resv1 = 0x00, .DATA[44].resv2 = 0x00,
    .DATA[45].level = 0x00, .DATA[45].group[0] = 0x00, .DATA[45].group[1] = 0x00, .DATA[45].group[2] = 0x00, .DATA[45].group[3] = 0x00, .DATA[45].compensation = 0x00, .DATA[45].resv1 = 0x00, .DATA[45].resv2 = 0x00,
    .DATA[46].level = 0x00, .DATA[46].group[0] = 0x00, .DATA[46].group[1] = 0x00, .DATA[46].group[2] = 0x00, .DATA[46].group[3] = 0x00, .DATA[46].compensation = 0x00, .DATA[46].resv1 = 0x00, .DATA[46].resv2 = 0x00,
    .DATA[47].level = 0x00, .DATA[47].group[0] = 0x00, .DATA[47].group[1] = 0x00, .DATA[47].group[2] = 0x00, .DATA[47].group[3] = 0x00, .DATA[47].compensation = 0x00, .DATA[47].resv1 = 0x00, .DATA[47].resv2 = 0x00,
    .DATA[48].level = 0x00, .DATA[48].group[0] = 0x00, .DATA[48].group[1] = 0x00, .DATA[48].group[2] = 0x00, .DATA[48].group[3] = 0x00, .DATA[48].compensation = 0x00, .DATA[48].resv1 = 0x00, .DATA[48].resv2 = 0x00,
    .DATA[49].level = 0x00, .DATA[49].group[0] = 0x00, .DATA[49].group[1] = 0x00, .DATA[49].group[2] = 0x00, .DATA[49].group[3] = 0x00, .DATA[49].compensation = 0x00, .DATA[49].resv1 = 0x00, .DATA[49].resv2 = 0x00,

    .DATA[50].level = 0x00, .DATA[50].group[0] = 0x00, .DATA[50].group[1] = 0x00, .DATA[50].group[2] = 0x00, .DATA[50].group[3] = 0x00, .DATA[50].compensation = 0x00, .DATA[50].resv1 = 0x00, .DATA[50].resv2 = 0x00,
    .DATA[51].level = 0x00, .DATA[51].group[0] = 0x00, .DATA[51].group[1] = 0x00, .DATA[51].group[2] = 0x00, .DATA[51].group[3] = 0x00, .DATA[51].compensation = 0x00, .DATA[51].resv1 = 0x00, .DATA[51].resv2 = 0x00,
    .DATA[52].level = 0x00, .DATA[52].group[0] = 0x00, .DATA[52].group[1] = 0x00, .DATA[52].group[2] = 0x00, .DATA[52].group[3] = 0x00, .DATA[52].compensation = 0x00, .DATA[52].resv1 = 0x00, .DATA[52].resv2 = 0x00,
    .DATA[53].level = 0x00, .DATA[53].group[0] = 0x00, .DATA[53].group[1] = 0x00, .DATA[53].group[2] = 0x00, .DATA[53].group[3] = 0x00, .DATA[53].compensation = 0x00, .DATA[53].resv1 = 0x00, .DATA[53].resv2 = 0x00,
    .DATA[54].level = 0x00, .DATA[54].group[0] = 0x00, .DATA[54].group[1] = 0x00, .DATA[54].group[2] = 0x00, .DATA[54].group[3] = 0x00, .DATA[54].compensation = 0x00, .DATA[54].resv1 = 0x00, .DATA[54].resv2 = 0x00,
    .DATA[55].level = 0x00, .DATA[55].group[0] = 0x00, .DATA[55].group[1] = 0x00, .DATA[55].group[2] = 0x00, .DATA[55].group[3] = 0x00, .DATA[55].compensation = 0x00, .DATA[55].resv1 = 0x00, .DATA[55].resv2 = 0x00,
    .DATA[56].level = 0x00, .DATA[56].group[0] = 0x00, .DATA[56].group[1] = 0x00, .DATA[56].group[2] = 0x00, .DATA[56].group[3] = 0x00, .DATA[56].compensation = 0x00, .DATA[56].resv1 = 0x00, .DATA[56].resv2 = 0x00,
    .DATA[57].level = 0x00, .DATA[57].group[0] = 0x00, .DATA[57].group[1] = 0x00, .DATA[57].group[2] = 0x00, .DATA[57].group[3] = 0x00, .DATA[57].compensation = 0x00, .DATA[57].resv1 = 0x00, .DATA[57].resv2 = 0x00,
    .DATA[58].level = 0x00, .DATA[58].group[0] = 0x00, .DATA[58].group[1] = 0x00, .DATA[58].group[2] = 0x00, .DATA[58].group[3] = 0x00, .DATA[58].compensation = 0x00, .DATA[58].resv1 = 0x00, .DATA[58].resv2 = 0x00,
    .DATA[59].level = 0x00, .DATA[59].group[0] = 0x00, .DATA[59].group[1] = 0x00, .DATA[59].group[2] = 0x00, .DATA[59].group[3] = 0x00, .DATA[59].compensation = 0x00, .DATA[59].resv1 = 0x00, .DATA[59].resv2 = 0x00,    

    .DATA[60].level = 0x00, .DATA[60].group[0] = 0x00, .DATA[60].group[1] = 0x00, .DATA[60].group[2] = 0x00, .DATA[60].group[3] = 0x00, .DATA[60].compensation = 0x00, .DATA[60].resv1 = 0x00, .DATA[60].resv2 = 0x00,
    .DATA[61].level = 0x00, .DATA[61].group[0] = 0x00, .DATA[61].group[1] = 0x00, .DATA[61].group[2] = 0x00, .DATA[61].group[3] = 0x00, .DATA[61].compensation = 0x00, .DATA[61].resv1 = 0x00, .DATA[61].resv2 = 0x00,
    .DATA[62].level = 0x00, .DATA[62].group[0] = 0x00, .DATA[62].group[1] = 0x00, .DATA[62].group[2] = 0x00, .DATA[62].group[3] = 0x00, .DATA[62].compensation = 0x00, .DATA[62].resv1 = 0x00, .DATA[62].resv2 = 0x00,
    .DATA[63].level = 0x00, .DATA[63].group[0] = 0x00, .DATA[63].group[1] = 0x00, .DATA[63].group[2] = 0x00, .DATA[63].group[3] = 0x00, .DATA[63].compensation = 0x00, .DATA[63].resv1 = 0x00, .DATA[63].resv2 = 0x00,
    .DATA[64].level = 0x00, .DATA[64].group[0] = 0x00, .DATA[64].group[1] = 0x00, .DATA[64].group[2] = 0x00, .DATA[64].group[3] = 0x00, .DATA[64].compensation = 0x00, .DATA[64].resv1 = 0x00, .DATA[64].resv2 = 0x00,
    .DATA[65].level = 0x00, .DATA[65].group[0] = 0x00, .DATA[65].group[1] = 0x00, .DATA[65].group[2] = 0x00, .DATA[65].group[3] = 0x00, .DATA[65].compensation = 0x00, .DATA[65].resv1 = 0x00, .DATA[65].resv2 = 0x00,
    .DATA[66].level = 0x00, .DATA[66].group[0] = 0x00, .DATA[66].group[1] = 0x00, .DATA[66].group[2] = 0x00, .DATA[66].group[3] = 0x00, .DATA[66].compensation = 0x00, .DATA[66].resv1 = 0x00, .DATA[66].resv2 = 0x00,
    .DATA[67].level = 0x00, .DATA[67].group[0] = 0x00, .DATA[67].group[1] = 0x00, .DATA[67].group[2] = 0x00, .DATA[67].group[3] = 0x00, .DATA[67].compensation = 0x00, .DATA[67].resv1 = 0x00, .DATA[67].resv2 = 0x00,
    .DATA[68].level = 0x00, .DATA[68].group[0] = 0x00, .DATA[68].group[1] = 0x00, .DATA[68].group[2] = 0x00, .DATA[68].group[3] = 0x00, .DATA[68].compensation = 0x00, .DATA[68].resv1 = 0x00, .DATA[68].resv2 = 0x00,
    .DATA[69].level = 0x00, .DATA[69].group[0] = 0x00, .DATA[69].group[1] = 0x00, .DATA[69].group[2] = 0x00, .DATA[69].group[3] = 0x00, .DATA[69].compensation = 0x00, .DATA[69].resv1 = 0x00, .DATA[69].resv2 = 0x00,

    .DATA[70].level = 0x00, .DATA[70].group[0] = 0x00, .DATA[70].group[1] = 0x00, .DATA[70].group[2] = 0x00, .DATA[70].group[3] = 0x00, .DATA[70].compensation = 0x00, .DATA[70].resv1 = 0x00, .DATA[70].resv2 = 0x00,
    .DATA[71].level = 0x00, .DATA[71].group[0] = 0x00, .DATA[71].group[1] = 0x00, .DATA[71].group[2] = 0x00, .DATA[71].group[3] = 0x00, .DATA[71].compensation = 0x00, .DATA[71].resv1 = 0x00, .DATA[71].resv2 = 0x00,
    .DATA[72].level = 0x00, .DATA[72].group[0] = 0x00, .DATA[72].group[1] = 0x00, .DATA[72].group[2] = 0x00, .DATA[72].group[3] = 0x00, .DATA[72].compensation = 0x00, .DATA[72].resv1 = 0x00, .DATA[72].resv2 = 0x00,
    .DATA[73].level = 0x00, .DATA[73].group[0] = 0x00, .DATA[73].group[1] = 0x00, .DATA[73].group[2] = 0x00, .DATA[73].group[3] = 0x00, .DATA[73].compensation = 0x00, .DATA[73].resv1 = 0x00, .DATA[73].resv2 = 0x00,
    .DATA[74].level = 0x00, .DATA[74].group[0] = 0x00, .DATA[74].group[1] = 0x00, .DATA[74].group[2] = 0x00, .DATA[74].group[3] = 0x00, .DATA[74].compensation = 0x00, .DATA[74].resv1 = 0x00, .DATA[74].resv2 = 0x00,
    .DATA[75].level = 0x00, .DATA[75].group[0] = 0x00, .DATA[75].group[1] = 0x00, .DATA[75].group[2] = 0x00, .DATA[75].group[3] = 0x00, .DATA[75].compensation = 0x00, .DATA[75].resv1 = 0x00, .DATA[75].resv2 = 0x00,
    .DATA[76].level = 0x00, .DATA[76].group[0] = 0x00, .DATA[76].group[1] = 0x00, .DATA[76].group[2] = 0x00, .DATA[76].group[3] = 0x00, .DATA[76].compensation = 0x00, .DATA[76].resv1 = 0x00, .DATA[76].resv2 = 0x00,
    .DATA[77].level = 0x00, .DATA[77].group[0] = 0x00, .DATA[77].group[1] = 0x00, .DATA[77].group[2] = 0x00, .DATA[77].group[3] = 0x00, .DATA[77].compensation = 0x00, .DATA[77].resv1 = 0x00, .DATA[77].resv2 = 0x00,
    .DATA[78].level = 0x00, .DATA[78].group[0] = 0x00, .DATA[78].group[1] = 0x00, .DATA[78].group[2] = 0x00, .DATA[78].group[3] = 0x00, .DATA[78].compensation = 0x00, .DATA[78].resv1 = 0x00, .DATA[78].resv2 = 0x00,
    .DATA[79].level = 0x00, .DATA[79].group[0] = 0x00, .DATA[79].group[1] = 0x00, .DATA[79].group[2] = 0x00, .DATA[79].group[3] = 0x00, .DATA[79].compensation = 0x00, .DATA[79].resv1 = 0x00, .DATA[79].resv2 = 0x00,

    .DATA[80].level = 0x00, .DATA[80].group[0] = 0x00, .DATA[80].group[1] = 0x00, .DATA[80].group[2] = 0x00, .DATA[80].group[3] = 0x00, .DATA[80].compensation = 0x00, .DATA[80].resv1 = 0x00, .DATA[80].resv2 = 0x00,
    .DATA[81].level = 0x00, .DATA[81].group[0] = 0x00, .DATA[81].group[1] = 0x00, .DATA[81].group[2] = 0x00, .DATA[81].group[3] = 0x00, .DATA[81].compensation = 0x00, .DATA[81].resv1 = 0x00, .DATA[81].resv2 = 0x00,
    .DATA[82].level = 0x00, .DATA[82].group[0] = 0x00, .DATA[82].group[1] = 0x00, .DATA[82].group[2] = 0x00, .DATA[82].group[3] = 0x00, .DATA[82].compensation = 0x00, .DATA[82].resv1 = 0x00, .DATA[82].resv2 = 0x00,
    .DATA[83].level = 0x00, .DATA[83].group[0] = 0x00, .DATA[83].group[1] = 0x00, .DATA[83].group[2] = 0x00, .DATA[83].group[3] = 0x00, .DATA[83].compensation = 0x00, .DATA[83].resv1 = 0x00, .DATA[83].resv2 = 0x00,
    .DATA[84].level = 0x00, .DATA[84].group[0] = 0x00, .DATA[84].group[1] = 0x00, .DATA[84].group[2] = 0x00, .DATA[84].group[3] = 0x00, .DATA[84].compensation = 0x00, .DATA[84].resv1 = 0x00, .DATA[84].resv2 = 0x00,
    .DATA[85].level = 0x00, .DATA[85].group[0] = 0x00, .DATA[85].group[1] = 0x00, .DATA[85].group[2] = 0x00, .DATA[85].group[3] = 0x00, .DATA[85].compensation = 0x00, .DATA[85].resv1 = 0x00, .DATA[85].resv2 = 0x00,
    .DATA[86].level = 0x00, .DATA[86].group[0] = 0x00, .DATA[86].group[1] = 0x00, .DATA[86].group[2] = 0x00, .DATA[86].group[3] = 0x00, .DATA[86].compensation = 0x00, .DATA[86].resv1 = 0x00, .DATA[86].resv2 = 0x00,
    .DATA[87].level = 0x00, .DATA[87].group[0] = 0x00, .DATA[87].group[1] = 0x00, .DATA[87].group[2] = 0x00, .DATA[87].group[3] = 0x00, .DATA[87].compensation = 0x00, .DATA[87].resv1 = 0x00, .DATA[87].resv2 = 0x00,
    .DATA[88].level = 0x00, .DATA[88].group[0] = 0x00, .DATA[88].group[1] = 0x00, .DATA[88].group[2] = 0x00, .DATA[88].group[3] = 0x00, .DATA[88].compensation = 0x00, .DATA[88].resv1 = 0x00, .DATA[88].resv2 = 0x00,
    .DATA[89].level = 0x00, .DATA[89].group[0] = 0x00, .DATA[89].group[1] = 0x00, .DATA[89].group[2] = 0x00, .DATA[89].group[3] = 0x00, .DATA[89].compensation = 0x00, .DATA[89].resv1 = 0x00, .DATA[89].resv2 = 0x00,

    .DATA[90].level = 0x00, .DATA[90].group[0] = 0x00, .DATA[90].group[1] = 0x00, .DATA[90].group[2] = 0x00, .DATA[90].group[3] = 0x00, .DATA[90].compensation = 0x00, .DATA[90].resv1 = 0x00, .DATA[90].resv2 = 0x00,
    .DATA[91].level = 0x00, .DATA[91].group[0] = 0x00, .DATA[91].group[1] = 0x00, .DATA[91].group[2] = 0x00, .DATA[91].group[3] = 0x00, .DATA[91].compensation = 0x00, .DATA[91].resv1 = 0x00, .DATA[91].resv2 = 0x00,
    .DATA[92].level = 0x00, .DATA[92].group[0] = 0x00, .DATA[92].group[1] = 0x00, .DATA[92].group[2] = 0x00, .DATA[92].group[3] = 0x00, .DATA[92].compensation = 0x00, .DATA[92].resv1 = 0x00, .DATA[92].resv2 = 0x00,
    .DATA[93].level = 0x00, .DATA[93].group[0] = 0x00, .DATA[93].group[1] = 0x00, .DATA[93].group[2] = 0x00, .DATA[93].group[3] = 0x00, .DATA[93].compensation = 0x00, .DATA[93].resv1 = 0x00, .DATA[93].resv2 = 0x00,
    .DATA[94].level = 0x00, .DATA[94].group[0] = 0x00, .DATA[94].group[1] = 0x00, .DATA[94].group[2] = 0x00, .DATA[94].group[3] = 0x00, .DATA[94].compensation = 0x00, .DATA[94].resv1 = 0x00, .DATA[94].resv2 = 0x00,
    .DATA[95].level = 0x00, .DATA[95].group[0] = 0x00, .DATA[95].group[1] = 0x00, .DATA[95].group[2] = 0x00, .DATA[95].group[3] = 0x00, .DATA[95].compensation = 0x00, .DATA[95].resv1 = 0x00, .DATA[95].resv2 = 0x00,
    .DATA[96].level = 0x00, .DATA[96].group[0] = 0x00, .DATA[96].group[1] = 0x00, .DATA[96].group[2] = 0x00, .DATA[96].group[3] = 0x00, .DATA[96].compensation = 0x00, .DATA[96].resv1 = 0x00, .DATA[96].resv2 = 0x00,
    .DATA[97].level = 0x00, .DATA[97].group[0] = 0x00, .DATA[97].group[1] = 0x00, .DATA[97].group[2] = 0x00, .DATA[97].group[3] = 0x00, .DATA[97].compensation = 0x00, .DATA[97].resv1 = 0x00, .DATA[97].resv2 = 0x00,
    .DATA[98].level = 0x00, .DATA[98].group[0] = 0x00, .DATA[98].group[1] = 0x00, .DATA[98].group[2] = 0x00, .DATA[98].group[3] = 0x00, .DATA[98].compensation = 0x00, .DATA[98].resv1 = 0x00, .DATA[98].resv2 = 0x00,
    .DATA[99].level = 0x00, .DATA[99].group[0] = 0x00, .DATA[99].group[1] = 0x00, .DATA[99].group[2] = 0x00, .DATA[99].group[3] = 0x00, .DATA[99].compensation = 0x00, .DATA[99].resv1 = 0x00, .DATA[99].resv2 = 0x00,

    .DATA[100].level = 0x00, .DATA[100].group[0] = 0x00, .DATA[100].group[1] = 0x00, .DATA[100].group[2] = 0x00, .DATA[100].group[3] = 0x00, .DATA[100].compensation = 0x00, .DATA[100].resv1 = 0x00, .DATA[100].resv2 = 0x00,
    .DATA[101].level = 0x00, .DATA[101].group[0] = 0x00, .DATA[101].group[1] = 0x00, .DATA[101].group[2] = 0x00, .DATA[101].group[3] = 0x00, .DATA[101].compensation = 0x00, .DATA[101].resv1 = 0x00, .DATA[101].resv2 = 0x00,
    .DATA[102].level = 0x00, .DATA[102].group[0] = 0x00, .DATA[102].group[1] = 0x00, .DATA[102].group[2] = 0x00, .DATA[102].group[3] = 0x00, .DATA[102].compensation = 0x00, .DATA[102].resv1 = 0x00, .DATA[102].resv2 = 0x00,
    .DATA[103].level = 0x00, .DATA[103].group[0] = 0x00, .DATA[103].group[1] = 0x00, .DATA[103].group[2] = 0x00, .DATA[103].group[3] = 0x00, .DATA[103].compensation = 0x00, .DATA[103].resv1 = 0x00, .DATA[103].resv2 = 0x00,
    .DATA[104].level = 0x00, .DATA[104].group[0] = 0x00, .DATA[104].group[1] = 0x00, .DATA[104].group[2] = 0x00, .DATA[104].group[3] = 0x00, .DATA[104].compensation = 0x00, .DATA[104].resv1 = 0x00, .DATA[104].resv2 = 0x00,
    .DATA[105].level = 0x00, .DATA[105].group[0] = 0x00, .DATA[105].group[1] = 0x00, .DATA[105].group[2] = 0x00, .DATA[105].group[3] = 0x00, .DATA[105].compensation = 0x00, .DATA[105].resv1 = 0x00, .DATA[105].resv2 = 0x00,
    .DATA[106].level = 0x00, .DATA[106].group[0] = 0x00, .DATA[106].group[1] = 0x00, .DATA[106].group[2] = 0x00, .DATA[106].group[3] = 0x00, .DATA[106].compensation = 0x00, .DATA[106].resv1 = 0x00, .DATA[106].resv2 = 0x00,
    .DATA[107].level = 0x00, .DATA[107].group[0] = 0x00, .DATA[107].group[1] = 0x00, .DATA[107].group[2] = 0x00, .DATA[107].group[3] = 0x00, .DATA[107].compensation = 0x00, .DATA[107].resv1 = 0x00, .DATA[107].resv2 = 0x00,
    .DATA[108].level = 0x00, .DATA[108].group[0] = 0x00, .DATA[108].group[1] = 0x00, .DATA[108].group[2] = 0x00, .DATA[108].group[3] = 0x00, .DATA[108].compensation = 0x00, .DATA[108].resv1 = 0x00, .DATA[108].resv2 = 0x00,
    .DATA[109].level = 0x00, .DATA[109].group[0] = 0x00, .DATA[109].group[1] = 0x00, .DATA[109].group[2] = 0x00, .DATA[108].group[3] = 0x00, .DATA[109].compensation = 0x00, .DATA[109].resv1 = 0x00, .DATA[109].resv2 = 0x00,

    .DATA[110].level = 0x00, .DATA[110].group[0] = 0x00, .DATA[110].group[1] = 0x00, .DATA[110].group[2] = 0x00, .DATA[110].group[3] = 0x00, .DATA[110].compensation = 0x00, .DATA[110].resv1 = 0x00, .DATA[110].resv2 = 0x00,
    .DATA[111].level = 0x00, .DATA[111].group[0] = 0x00, .DATA[111].group[1] = 0x00, .DATA[111].group[2] = 0x00, .DATA[111].group[3] = 0x00, .DATA[111].compensation = 0x00, .DATA[111].resv1 = 0x00, .DATA[111].resv2 = 0x00,

    .ucSN[0] = 0x00, .ucSN[1] = 0x00, .ucSN[2] = 0x00, .ucSN[3] = 0x00, .ucSN[4] = 0x00, .ucSN[5] = 0x00, .ucSN[6] = 0x00, .ucSN[7] = 0x00, .ucSN[8] = 0x00, .ucSN[9] = 0x00, .ucSN[10] = 0x00, .ucSN[11] = 0x00, .ucSN[12] = 0x00, .ucSN[13] = 0x00, .ucSN[14] = 0x00,
    .ucModelnm[0] = 0x00, .ucModelnm[1] = 0x00, .ucModelnm[2] = 0x00, .ucModelnm[3] = 0x00, .ucModelnm[4] = 0x00, .ucModelnm[5] = 0x00, .ucModelnm[6] = 0x00, .ucModelnm[7] = 0x00, .ucModelnm[8] = 0x00, .ucModelnm[9] = 0x00, .ucModelnm[10] = 0x00, .ucModelnm[11] = 0x00, .ucModelnm[12] = 0x00, .ucModelnm[13] = 0x00, .ucModelnm[14] = 0x00,   
    .drbo_NUM = 0x01,
    .LCW_NUM = 0x01,
    .Als_max = 0x0000,
    .Als_min = 0x0000,
    .Als_table[0] = 0x0000, .Als_table[1] = 0x0000, .Als_table[2] = 0x0000, .Als_table[3] = 0x0000, .Als_table[4] = 0x0000, .Als_table[5] = 0x0000, .Als_table[6] = 0x0000, .Als_table[7] = 0x0000,
    .Als_target = 0x0000
#if 0
    .Als_max_data.ALSMAX_MSB = 0x00, .Als_max_data.ALSMAX_LSB = 0x00,
    .Als_min_data.ALSMIN_MSB = 0x00, .Als_min_data.ALSMIN_LSB = 0x00,
    .Als_table_data[0].ALSTABLE_MSB = 0x00, .Als_table_data[0].ALSTABLE_LSB = 0x00,
    .Als_table_data[1].ALSTABLE_MSB = 0x00, .Als_table_data[1].ALSTABLE_LSB = 0x00,
    .Als_table_data[2].ALSTABLE_MSB = 0x00, .Als_table_data[2].ALSTABLE_LSB = 0x00,
    .Als_table_data[3].ALSTABLE_MSB = 0x00, .Als_table_data[3].ALSTABLE_LSB = 0x00,
    .Als_table_data[4].ALSTABLE_MSB = 0x00, .Als_table_data[4].ALSTABLE_LSB = 0x00,
    .Als_table_data[5].ALSTABLE_MSB = 0x00, .Als_table_data[5].ALSTABLE_LSB = 0x00,
    .Als_table_data[6].ALSTABLE_MSB = 0x00, .Als_table_data[6].ALSTABLE_LSB = 0x00,
    .Als_table_data[7].ALSTABLE_MSB = 0x00, .Als_table_data[7].ALSTABLE_LSB = 0x00 
#endif            
};

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
uint16_t EEPROM_Read(uint8_t i2c1_ctrl_addr)
{    
    volatile I2C1_TRANSFER_STATUS transferStatusCmd = I2C1_TRANSFER_STATUS_ERROR;
    int count=0;
    SERCOM7_I2C_CallbackRegister( I2C1_Callback, (uintptr_t)&transferStatusCmd );
    //------------power on--------------

    //------------One Time Measure 4Lx, 16ms--------------

    //------------Get(Read) Data--------------
    uint8_t myData[2];
    myData[0]=0;
    myData[1]=0;
    //myData[2]=0;
    //uint8_t *myData_1 = calloc(2, sizeof (uint8_t));    
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;
    SERCOM7_I2C_Read(i2c1_ctrl_addr, &myData[0], 2);
#if 0    
    if(!SERCOM7_I2C_Read(i2c1_ctrl_addr, &myData[0], 3))
    //if(!SERCOM7_I2C_Read(i2c1_ctrl_addr, myData_1, 2))    
	{
		return 0xFFFF;
	}
#endif    
    count=0;
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
    //for (uint32_t i = 0; i < 20000; i++);//1ns*20000=2ms
   //uint16_t p_value = (uint16_t)myData[0];     //((uint16_t)myData[0] << 8) | myData[1];
    //SYS_CONSOLE_PRINT("ALS LX = 0x%02x  %d\r\n",myData[0],p_value);
    SERCOM0_USART_Write(myData, 2);
    //free(myData_1);
    return 0;//p_value;    
}

uint16_t EEPROM_Write(uint8_t i2c1_ctrl_addr)
{
    volatile I2C1_TRANSFER_STATUS transferStatusCmd = I2C1_TRANSFER_STATUS_ERROR;
    SERCOM7_I2C_CallbackRegister( I2C1_Callback, (uintptr_t)&transferStatusCmd );
    uint8_t myData[3];
    //uint8_t *myData_1 = calloc(2, sizeof (uint8_t));
    //myData_1[0]=0x55;
    //myData_1[1]=0x33;
    myData[0]=0x33;
    myData[1]=0x55;
   myData[2]=0x38;
    //myData[3]=0x44;
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;
    //GPIO_PB00_Clear();
    SERCOM7_I2C_Write(i2c1_ctrl_addr, &myData[1], 2);
    //GPIO_PB00_Set();
    int count=0;
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
    //free(myData_1);
    return 0; 
}

uint32_t  EEPROM_Read_LCW(uint16_t i2c1_ctrl_addr,uint8_t *pdata,size_t size)
{
    int count=0;
    volatile I2C1_TRANSFER_STATUS transferStatusCmd = I2C1_TRANSFER_STATUS_ERROR;
    SERCOM7_I2C_CallbackRegister( I2C1_Callback, (uintptr_t)&transferStatusCmd );
    uint32_t ret;
    //------------Get(Read) Data--------------
    uint8_t myData_lcw[8];
    uint8_t datareadaddr[2];
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;
    datareadaddr[0] = (uint8_t)((i2c1_ctrl_addr & 0xFF00) >> 8);  //MSB
    datareadaddr[1] = (uint8_t)(i2c1_ctrl_addr & 0x00FF);   //LSB
    //GPIO_PB00_Set();
    ret = SERCOM7_I2C_Write(EEPROM_1_CTRL_ADDR, datareadaddr, 2);
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
    //GPIO_PB00_Clear();
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;    
    myData_lcw[0]=0x00;
    myData_lcw[1]=0x00;
    myData_lcw[2]=0x00;
    myData_lcw[3]=0x00;
    myData_lcw[4]=0x00;
    myData_lcw[5]=0x00;
    myData_lcw[6]=0x00;
    myData_lcw[7]=0x00;
    //GPIO_PB00_Set();
    ret = SERCOM7_I2C_Read(EEPROM_1_CTRL_ADDR,myData_lcw,size);
    count=0;
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
    //GPIO_PB00_Clear();
    SERCOM0_USART_Write(&myData_lcw[0], size);
    return ret;    
}

void EEPROM_Write_LCW(uint16_t i2c1_ctrl_addr,size_t size)
{
    int count=0;
    uint8_t datatmp[8];
    volatile I2C1_TRANSFER_STATUS transferStatusCmd = I2C1_TRANSFER_STATUS_ERROR;
    SERCOM7_I2C_CallbackRegister( I2C1_Callback, (uintptr_t)&transferStatusCmd );
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;    
     datatmp[0] = (uint8_t)((i2c1_ctrl_addr & 0xFF00) >> 8);  //MSB
     datatmp[1] = (uint8_t)(i2c1_ctrl_addr & 0x00FF);   //LSB
     datatmp[2] = 0x22;
     datatmp[3] = 0x22;
     datatmp[4] = 0x33;
     datatmp[5] = 0x55;
     datatmp[6] = 0x55;
     datatmp[7] = 0x37;
    //GPIO_PB00_Set();
    GPIO_PB00_Clear(); //WC disable
    SERCOM7_I2C_Write(EEPROM_1_CTRL_ADDR,datatmp,size+2);
    //SERCOM7_I2C_Write(EEPROM_1_CTRL_ADDR,datatmp,size+2);
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
    GPIO_PB00_Set();  //WC enable
    //GPIO_PB00_Clear();   
}

uint32_t  EEPROM_Read_Data(uint16_t i2c1_ctrl_addr,EEPROMData *pdata)
{
    int count=0;
    uint16_t pageaddr_reg;
    uint16_t remainder;
    volatile I2C1_TRANSFER_STATUS transferStatusCmd = I2C1_TRANSFER_STATUS_ERROR;
    SERCOM7_I2C_CallbackRegister( I2C1_Callback, (uintptr_t)&transferStatusCmd );
    uint32_t ret;
    //------------Get(Read) Data--------------
    uint16_t datasize = sizeof(EEPROMData);
    //uint8_t myData_lcw[datasize];
    uint8_t *myData_lcw = calloc(datasize, sizeof(uint8_t *));
    uint8_t *myData_lcw_EEPage = calloc(128, sizeof(uint8_t *)); 
    uint8_t datareadaddr[2];
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;
    datareadaddr[0] = (uint8_t)((i2c1_ctrl_addr & 0xFF00) >> 8);  //MSB
    datareadaddr[1] = (uint8_t)(i2c1_ctrl_addr & 0x00FF);   //LSB
    pageaddr_reg = i2c1_ctrl_addr;
    remainder = 0;
//////////////////////////////////////////////////////////////////////////// 
if(datasize > 0x7F){
         remainder = datasize/128 + 1;
        //if((datasize%128) != 0){
            //remainder++;
        //}
        for(int i=0;i<remainder;i++)
        {
            transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;
            ret = SERCOM7_I2C_Write(EEPROM_1_CTRL_ADDR, datareadaddr, 2);
            for (uint32_t i = 0; i < 20000; i++);//1ns*20000=2ms
            while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
            {
                count++;
                if(count > I2C_Delay_ns)
                    break;
            }
            transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;    
            ret = SERCOM7_I2C_Read(EEPROM_1_CTRL_ADDR,myData_lcw_EEPage,128);
            for (uint32_t i = 0; i < 50000; i++);//1ns*20000=2ms
            count=0;
            while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
            {
                count++;
                if(count > I2C_Delay_ns)
                    break;
            }
            for(int j=0;j<128;j++)
            {            
                myData_lcw[j+(128*i)] = myData_lcw_EEPage[j];
            }
            //SERCOM0_USART_Write(&myData_lcw[0], 3);   //test
            //for (uint32_t i = 0; i < 20000; i++);//1ns*20000=2ms
           pageaddr_reg = pageaddr_reg +128;
           datareadaddr[0] = (uint8_t)((pageaddr_reg & 0xFF00) >> 8);  //MSB
           datareadaddr[1] = (uint8_t)(pageaddr_reg & 0x00FF);   //LSB            
        }
}else{
    ret = SERCOM7_I2C_Write(EEPROM_1_CTRL_ADDR, datareadaddr, 2);
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }   
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;    
    ret = SERCOM7_I2C_Read(EEPROM_1_CTRL_ADDR,myData_lcw,128);
    for (uint32_t i = 0; i < 50000; i++);//1ns*20000=2ms
    count=0;
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }    
}    
/////////////////////////////////////////////////////////////////////////////////////////    
    memcpy(pdata,myData_lcw,datasize);
    free(myData_lcw);
    free(myData_lcw_EEPage);
    return ret;    
}

void EEPROM_Write_Data(uint16_t i2c1_ctrl_addr,EEPROMData *ptr)
{
    int count=0;
    uint16_t remainder;
    uint16_t pageaddr_reg;
    uint16_t datasize = sizeof(EEPROMData);
    uint8_t *datatmp = calloc(datasize, sizeof(uint8_t *));
    uint8_t *datatmp_write = calloc(datasize+2, sizeof(uint8_t *));
    uint8_t *datatmp_1page = calloc(128+2, sizeof(uint8_t *));
    volatile I2C1_TRANSFER_STATUS transferStatusCmd = I2C1_TRANSFER_STATUS_ERROR;
    SERCOM7_I2C_CallbackRegister( I2C1_Callback, (uintptr_t)&transferStatusCmd );
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;    
    datatmp_write[0] = (uint8_t)((i2c1_ctrl_addr & 0xFF00) >> 8);  //MSB
    datatmp_write[1] = (uint8_t)(i2c1_ctrl_addr & 0x00FF);   //LSB
    //SYS_CONSOLE_PRINT("ptr = %x",ptr);    //address  200188c0   //  ptr+1    20018c72     =  200188c0 +3b2     
    //SYS_CONSOLE_PRINT("ptr = %x", ptr->DATA[0].group[1]);
    //datatmp = *(uint8_t *)ptr;
    memcpy(datatmp,ptr,datasize); 
    //SYS_CONSOLE_PRINT("ptr1 = %x\r\n", datatmp[0]);
    for(int i=2;i<(datasize+2);i++)
    {
      datatmp_write[i] = datatmp[i-2];
    }  
    SYS_CONSOLE_PRINT("ptr1 = %x\r\n", datatmp_write[0]);
    SYS_CONSOLE_PRINT("ptr1 = %x\r\n", datatmp_write[1]);     
    SYS_CONSOLE_PRINT("ptr1 = %x\r\n", datatmp_write[2]);
    SYS_CONSOLE_PRINT("ptr1 = %x\r\n", datatmp_write[3]);    
    GPIO_PB00_Clear(); //WC disable
    pageaddr_reg = i2c1_ctrl_addr;
    remainder = 0;
    
    if(datasize > 0x7F){
        remainder = datasize/128+1;
        //if((datasize%128) > 0){
           // remainder++;
       // }
        for(int i=0;i<remainder;i++)
        {
            transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;
               datatmp_1page[0] = datatmp_write[0];
               datatmp_1page[1] = datatmp_write[1];
               for(int j=2;j<130;j++)
                {
                    datatmp_1page[j] = datatmp_write[j+128*i];
                } 
           SERCOM7_I2C_Write(EEPROM_1_CTRL_ADDR,&datatmp_1page[0],128+2);
           for (uint32_t i = 0; i < 50000; i++);//1ns*20000=2ms
           while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
           {
            count++;
            if(count > I2C_Delay_ns)
            break;
            }
           //SERCOM0_USART_Write(&datatmp_1page[0], 3);   //test
           pageaddr_reg = pageaddr_reg +128;
           datatmp_write[0] = (uint8_t)((pageaddr_reg & 0xFF00) >> 8);  //MSB
           datatmp_write[1] = (uint8_t)(pageaddr_reg & 0x00FF);   //LSB
           
        }
        
    }else{
        SERCOM7_I2C_Write(EEPROM_1_CTRL_ADDR,datatmp_write,datasize+2);
        for (uint32_t i = 0; i < 20000; i++);//1ns*20000=2ms
    }
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)
            break;
    }
    GPIO_PB00_Set();  //WC enable   
    free(datatmp);
    free(datatmp_write);
}
/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

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
#if 0
static int ExampleLocalFunction(int param1, int param2) {
    return 0;
}
#endif

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
#if 0
int ExampleInterfaceFunction(int param1, int param2) {
    return 0;
}
#endif

/* *****************************************************************************
 End of File
 */
