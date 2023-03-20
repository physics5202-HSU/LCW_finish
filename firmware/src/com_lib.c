/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Innolux

  @File Name
    com_lib.c

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
int count_secom0=0;
int count_papapa=0;
int count_lcw=0;

int temp_hmi_l=0;
int temp_hmi_r=0;
int temp_D1C1=0;int temp_D1C2=0;int temp_D1C3=0;int temp_D1C4=0;int temp_D1C5=0;int temp_D1C6=0;int temp_D1C7=0;int temp_D1C8=0;
int temp_D2C1=0;int temp_D2C2=0;int temp_D2C3=0;int temp_D2C4=0;int temp_D2C5=0;int temp_D2C6=0;int temp_D2C7=0;int temp_D2C8=0;
int temp_D3C1=0;int temp_D3C2=0;int temp_D3C3=0;int temp_D3C4=0;int temp_D3C5=0;int temp_D3C6=0;int temp_D3C7=0;int temp_D3C8=0;
int temp_D4C1=0;int temp_D4C2=0;int temp_D4C3=0;int temp_D4C4=0;int temp_D4C5=0;int temp_D4C6=0;int temp_D4C7=0;int temp_D4C8=0;
int temp_D5C1=0;int temp_D5C2=0;int temp_D5C3=0;int temp_D5C4=0;int temp_D5C5=0;int temp_D5C6=0;int temp_D5C7=0;int temp_D5C8=0;
int temp_D6C1=0;int temp_D6C2=0;int temp_D6C3=0;int temp_D6C4=0;int temp_D6C5=0;int temp_D6C6=0;int temp_D6C7=0;int temp_D6C8=0;
int temp_D7C1=0;int temp_D7C2=0;int temp_D7C3=0;int temp_D7C4=0;int temp_D7C5=0;int temp_D7C6=0;int temp_D7C7=0;int temp_D7C8=0;
int temp_D8C1=0;int temp_D8C2=0;int temp_D8C3=0;int temp_D8C4=0;int temp_D8C5=0;int temp_D8C6=0;int temp_D8C7=0;int temp_D8C8=0;
int temp_D9C1=0;int temp_D9C2=0;int temp_D9C3=0;int temp_D9C4=0;int temp_D9C5=0;int temp_D9C6=0;int temp_D9C7=0;int temp_D9C8=0;
int temp_D10C1=0;int temp_D10C2=0;int temp_D10C3=0;int temp_D10C4=0;int temp_D10C5=0;int temp_D10C6=0;int temp_D10C7=0;int temp_D10C8=0;
int temp_D11C1=0;int temp_D11C2=0;int temp_D11C3=0;int temp_D11C4=0;int temp_D11C5=0;int temp_D11C6=0;int temp_D11C7=0;int temp_D11C8=0;
int temp_D12C1=0;int temp_D12C2=0;int temp_D12C3=0;int temp_D12C4=0;int temp_D12C5=0;int temp_D12C6=0;int temp_D12C7=0;int temp_D12C8=0;
int temp_D13C1=0;int temp_D13C2=0;int temp_D13C3=0;int temp_D13C4=0;int temp_D13C5=0;int temp_D13C6=0;int temp_D13C7=0;int temp_D13C8=0;
int temp_D14C1=0;int temp_D14C2=0;int temp_D14C3=0;int temp_D14C4=0;int temp_D14C5=0;int temp_D14C6=0;int temp_D14C7=0;int temp_D14C8=0;
int temp_PresentDrivingBoard=0;

char Als_read_Buf[6];   //20
uint16_t Als_read_Buf1;
uint8_t hmi_value_b[7]={138,147,150,154,161,177,248};

extern EEPROMData EEDataDefault;
extern EEPROMData EEData;
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

#define DEBUG false
#define RELEASE false

#define MAX_CMDSTRING_LENGTH 50

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/* ************************************************************************** */

/** 
 * @Function
 *  void parse_cmd_string(Message *msg, char *cmdString)
 * 
 * @Summary
 *  parse command string and save corresponding parameter into Message
 * 
 * @Description
 * 
 * 
 * @Parameters
 *  @msg Message structure pointer for saving cmd's parameters in.
 * 
 *  @cmdString raw string of command
 */

void parse_cmd_string(Message *msg, char *cmdString) {

    char command[MAX_CMDSTRING_LENGTH];
    char value[MAX_CMDSTRING_LENGTH];

    /* check 3 uppercase letter and seperate operator */
    if (!checkCmdStringFormat(msg, cmdString)) {
        msg->msgType = MSG_TYPE_INVALID;
        return;
    }

    if (!isValidMessageType(command, value, msg, cmdString)) {
        //printf("invalid message type\n");
        return;
    }

    /* can be ignored */
    /* if (!isCmdCharExactThree(command, msg)){
  //printf("command must be 3 word\n");
  return;
 } */

    /* can be ignored */
    /* if(value == NULL){
  msg->msgType = MSG_TYPE_INVALID;
  return;
 } */

    char cmdChar0 = command[0];
    char cmdChar1 = command[1];
    char cmdChar2 = command[2];

    switch (cmdChar0) {
        case 'A':
            switch (cmdChar1) {
                case 'L':
                    switch (cmdChar2) {
                        case 'P':
                            msg->cmdType = CMD_TYPE_ALP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, 1, 180);
                            break;
                        case 'S':
                            msg->cmdType = CMD_TYPE_ALS;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, 1, 180);
                            break;
                        case 'T':
                            msg->cmdType = CMD_TYPE_ALT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        case 'W':
                            msg->cmdType = CMD_TYPE_ALW;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, 1, 60);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'C':
            switch (cmdChar1) {
                case 'H':
                    switch (cmdChar2) {
                        case 'A':
                            msg->cmdType = CMD_TYPE_CHA;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x21, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'D':
            switch (cmdChar1) {
                case 'C':
                    switch (cmdChar2) {
                        case 'P':
                            msg->cmdType = CMD_TYPE_DCP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x60, 0, 3);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'I':
                    switch (cmdChar2) {
                        case 'P':
                            msg->cmdType = CMD_TYPE_DIP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x20, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'N':
                    switch (cmdChar2) {
                        case 'S':
                            msg->cmdType = CMD_TYPE_DNS;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x28, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'T':
                    switch (cmdChar2) {
                        case '1':
                            msg->cmdType = CMD_TYPE_DT1;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, 1, 20);
                            break;
                        case '2':
                            msg->cmdType = CMD_TYPE_DT2;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, 1, 20);
                            break;
                        case '3':
                            msg->cmdType = CMD_TYPE_DT3;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, 1, 20);
                            break;
                        case '4':
                            msg->cmdType = CMD_TYPE_DT4;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, 1, 20);
                            break;
                        case '5':
                            msg->cmdType = CMD_TYPE_DT5;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, 1, 20);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'F':
            switch (cmdChar1) {
                case 'A':
                    switch (cmdChar2) {
                        case 'A':
                            msg->cmdType = CMD_TYPE_FAA;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 0, 1);
                            break;
                        case 'N':
                            msg->cmdType = CMD_TYPE_FAN;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x20, 0, 0);
                            break;
                        case 'T':
                            msg->cmdType = CMD_TYPE_FAT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'G':
            switch (cmdChar1) {
                case 'A':
                    switch (cmdChar2) {
                        case 'T':
                            msg->cmdType = CMD_TYPE_GAT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x28, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'H':
            switch (cmdChar1) {
                case 'E':
                    switch (cmdChar2) {
                        case 'T':
                            msg->cmdType = CMD_TYPE_HET;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x20, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'O':
                    switch (cmdChar2) {
                        case 'E':
                            msg->cmdType = CMD_TYPE_HOE;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 0, 1);
                            break;
                        case 'T':
                            msg->cmdType = CMD_TYPE_HOT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 0, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'S':
                    switch (cmdChar2) {
                        case 'T':
                            msg->cmdType = CMD_TYPE_HST;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x28, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'T':
                    switch (cmdChar2) {
                        case 'P':
                            msg->cmdType = CMD_TYPE_HTP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, -64, 64);
                            break;
                        case 'R':
                            msg->cmdType = CMD_TYPE_HTR;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 60);
                            break;
                        case 'S':
                            msg->cmdType = CMD_TYPE_HTS;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x30, 1025, 65535);
                            break;
                        case 'T':
                            msg->cmdType = CMD_TYPE_HTT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        case 'W':
                            msg->cmdType = CMD_TYPE_HTW;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, 1, 60);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'I':
            switch (cmdChar1) {
                case 'N':
                    switch (cmdChar2) {
                        case 'F':
                            msg->cmdType = CMD_TYPE_INF;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x20, 0, 0);
                            break;
                        case 'P':
                            msg->cmdType = CMD_TYPE_INP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x70, 1, 10);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'P':
                    switch (cmdChar2) {
                        case 'T':
                            msg->cmdType = CMD_TYPE_IPT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'R':
                    switch (cmdChar2) {
                        case 'M':
                            msg->cmdType = CMD_TYPE_IRM;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 0, 1);
                            break;
                        case 'T':
                            msg->cmdType = CMD_TYPE_IRT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'L':
            switch (cmdChar1) {
                case 'I':
                    switch (cmdChar2) {
                        case 'P':
                            msg->cmdType = CMD_TYPE_LIP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x28, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'T':
                    switch (cmdChar2) {
                        case 'A':
                            msg->cmdType = CMD_TYPE_LTA;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, -64, 64);
                            break;
                        case 'B':
                            msg->cmdType = CMD_TYPE_LTB;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, -64, 64);
                            break;
                        case 'P':
                            msg->cmdType = CMD_TYPE_LTP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, -64, 64);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'M':
            switch (cmdChar1) {
                case 'A':
                    switch (cmdChar2) {
                        case 'C':
                            msg->cmdType = CMD_TYPE_MAC;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x24, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'O':
                    switch (cmdChar2) {
                        case 'D':
                            msg->cmdType = CMD_TYPE_MOD;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x22, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'S':
                    switch (cmdChar2) {
                        case 'K':
                            msg->cmdType = CMD_TYPE_MSK;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x28, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'U':
                    switch (cmdChar2) {
                        case 'T':
                            msg->cmdType = CMD_TYPE_MUT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x60, 0, 3);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'P':
            switch (cmdChar1) {
                case 'S':
                    switch (cmdChar2) {
                        case 'N':
                            msg->cmdType = CMD_TYPE_PSN;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x50, -64, 64);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'W':
                    switch (cmdChar2) {
                        case 'D':
                            msg->cmdType = CMD_TYPE_PWD;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x60, 0, 3);
                            break;
                        case 'T':
                            msg->cmdType = CMD_TYPE_PWT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'R':
            switch (cmdChar1) {
                case 'C':
                    switch (cmdChar2) {
                        case 'C':
                            msg->cmdType = CMD_TYPE_RCC;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'D':
                    switch (cmdChar2) {
                        case 'P':
                            msg->cmdType = CMD_TYPE_RDP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        case 'T':
                            msg->cmdType = CMD_TYPE_RDT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        case 'W':
                            msg->cmdType = CMD_TYPE_RDW;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'E':
                    switch (cmdChar2) {
                        case 'S':
                            msg->cmdType = CMD_TYPE_RES;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'L':
                    switch (cmdChar2) {
                        case 'F':
                            msg->cmdType = CMD_TYPE_RLF;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        case 'A':
                            msg->cmdType = CMD_TYPE_RLA;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'M':
                    switch (cmdChar2) {
                        case 'T':
                            msg->cmdType = CMD_TYPE_RMT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x30, 1025, 65535);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'N':
                    switch (cmdChar2) {
                        case 'U':
                            msg->cmdType = CMD_TYPE_RNU;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 0, 9);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'O':
                    switch (cmdChar2) {
                        case 'K':
                            msg->cmdType = CMD_TYPE_ROK;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'R':
                    switch (cmdChar2) {
                        case 'T':
                            msg->cmdType = CMD_TYPE_RRT;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'U':
                    switch (cmdChar2) {
                        case 'N':
                            msg->cmdType = CMD_TYPE_RUN;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x20, 0, 0);
                            break;
                        case 'P':
                            msg->cmdType = CMD_TYPE_RUP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 1);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'S':
            switch (cmdChar1) {
                case 'D':
                    switch (cmdChar2) {
                        case 'P':
                            msg->cmdType = CMD_TYPE_SDP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x30, 1025, 65535);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'E':
                    switch (cmdChar2) {
                        case 'N':
                            msg->cmdType = CMD_TYPE_SEN;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x20, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'N':
                    switch (cmdChar2) {
                        case 'R':
                            msg->cmdType = CMD_TYPE_SNR;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x22, 0, 0);
                            break;
                        case 'W':
                            msg->cmdType = CMD_TYPE_SNW;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x02, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'U':
            switch (cmdChar1) {
                case 'D':
                    switch (cmdChar2) {
                        case 'P':
                            msg->cmdType = CMD_TYPE_UDP;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x30, 1025, 65535);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'S':
                    switch (cmdChar2) {
                        case 'E':
                            msg->cmdType = CMD_TYPE_USE;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x40, 1, 3);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                default:
                    msg->cmdType = CMD_TYPE_INVALID;
                    return;
            } //char1
            break;
        case 'V':
            switch (cmdChar1) {
                case 'E':
                    switch (cmdChar2) {
                        case 'R':
                            msg->cmdType = CMD_TYPE_VER;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x20, 0, 0);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
                case 'O':
                    switch (cmdChar2) {
                        case 'L':
                            msg->cmdType = CMD_TYPE_VOL;
                            //printf("%d\n",msg->cmdType);
                            analysisValString(msg, value, 0x70, 0, 100);
                            break;
                        default:
                            msg->cmdType = CMD_TYPE_INVALID;
                            return;
                    } //char2
                    break;
            } //last char1
            break;
        default:
            msg->cmdType = CMD_TYPE_INVALID;
            return;
    } //char0
} //parse_cmd_string

uint8_t checkCmdStringFormat(Message *msg, char *cmdString) {

    if (cmdString == NULL)
        return 0;

    uint8_t cntUpCase = 0;
    uint8_t seperator;
    uint8_t seperator1 = 0, seperator2 = 0;
    char *ptr = cmdString;

    while (*ptr != '\0') {

        seperator = seperator1 | seperator2;

        if ((seperator == 0 && *ptr >= 'A' && *ptr <= 'Z') ||
                (seperator == 0 && *ptr >= '0' && *ptr <= '9')) {
            cntUpCase++;
            ptr++;
            continue;
        }

        if (*ptr == ':') {
            seperator1++;
            ptr++;
            continue;
        }

        if (*ptr == '(') {
            seperator2++;
            ptr++;
            continue;
        }

        if (*ptr == ')' && seperator2 != 0) {
            seperator2++;
            ptr++;
            continue;
        }

        if (seperator == 0)
            break;

        ptr++;
    }

    if (cntUpCase != 3)
        return 0;

    if (seperator1 == 1) {
        msg->msgType = MSG_TYPE_REQUEST;
        return 1;
    }

    if (seperator2 == 2) {
        msg->msgType = MSG_TYPE_RESPONSE;
        return 1;
    }

    return 0;
}

uint8_t isValidMessageType(char *command, char *value, Message *msg, char *cmdString) {
    char cmdStringCopy[MAX_CMDSTRING_LENGTH];
    int matchCharPos;
    char *cmdTemp, *valTemp;
    uint8_t success = 0;

    strcpy(cmdStringCopy, cmdString);

    /* analysis cmdString into command, value */
    cmdTemp = strtok(cmdStringCopy, ":");
    matchCharPos = strcmp(cmdTemp, cmdString);
    if (matchCharPos == 0) { //NOT FOUND ':'
        cmdTemp = strtok(cmdStringCopy, "(");
        matchCharPos = strcmp(cmdTemp, cmdString);
        if (matchCharPos == 0) { //STILL NOT FOUND '('
            msg->msgType = MSG_TYPE_INVALID;
            return 0;
        } else {
            msg->msgType = MSG_TYPE_RESPONSE;
            valTemp = strtok(NULL, ")");
            success = 1;
        }
    } else {
        msg->msgType = MSG_TYPE_REQUEST;
        valTemp = strtok(NULL, ":");
        success = 1;
    }

    /* avoid empty value strcpy error */
    if (valTemp == NULL) {
        msg->valueType = VAL_TYPE_INVALID;
        return 0;
    }

    if (!success)
        return 0;

    strcpy(command, cmdTemp); //avoid off-block reference
    strcpy(value, valTemp);
    return 1;
}

uint8_t isCmdCharExactThree(char *command, Message *msg) {
    if (strlen(command) != 3) {
        msg->cmdType = CMD_TYPE_INVALID;
        return 0;
    }
    return 1;
}

uint8_t analysisIP(uint8_t *addr, char *s) {

    int i;
    int n = strlen(s);
    int dotCount = 0;
    int numCount = 0;
    int digitCount = 0;
    int num = 0;
    int total_num = 0;
    int output_pos = 0;

    for (i = 0; i < n; i++) {
        if (s[i] == '.') {
            dotCount++;
            if (num >= 0 && num <= 255 && output_pos <= 2 && digitCount >= 1 && digitCount <= 3) {
                numCount++;
                addr[output_pos++] = num;
                total_num += num;
                num = 0;
                digitCount = 0;
                continue;
            }
        }
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            digitCount++;
            continue;
        }
        break;
    }

    addr[output_pos++] = num;
    total_num += num;

    if (i != n)
        return 0;

    if (num >= 0 && num <= 255 && total_num != 0 && numCount == 3 && dotCount == 3 && digitCount >= 1 && digitCount <= 3)
        return 1;

    return 0;
}

uint8_t analysisMAC(uint8_t *addr, char *s) {

    int i;
    int n = strlen(s);
    int dotCount = 0;
    int numCount = 0;
    int num = 0;
    int total_num = 0;
    int output_pos = 0;

    for (i = 0; i < n; i++) {
        if (s[i] == '.') {
            dotCount++;
            if (num >= 0 && num <= 255 && output_pos <= 4) {
                numCount++;
                addr[output_pos++] = num;
                total_num += num;
                num = 0;
                continue;
            }
        }
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 16 + (s[i] - '0');
            continue;
        }
        if (s[i] >= 'A' && s[i] <= 'F') {
            num = num * 16 + (s[i] - 'A' + 10);
            continue;
        }
        if (s[i] >= 'a' && s[i] <= 'f') {
            num = num * 16 + (s[i] - 'a' + 10);
            continue;
        }

        break;
    }

    addr[output_pos++] = num;
    total_num += num;

    if (i != n)
        return 0;

    if (num >= 0 && num <= 255 && numCount == 5 && dotCount == 5)
        return 1;

    return 0;
}

uint8_t analysisChannel(uint8_t *channel, char *s) {

    int i;
    int n = strlen(s);
    int dotCount = 0;
    int numCount = 0;
    int num = 0;
    int total_num = 0;
    int output_pos = 0;

    for (i = 0; i < n; i++) {
        if (s[i] == '.') {
            dotCount++;
            if (num >= 0 && num <= 255 && output_pos <= 1) { //????channel??d??
                numCount++;
                channel[output_pos++] = num;
                total_num += num;
                num = 0;
                continue;
            }
        }
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            continue;
        }

        break;
    }

    channel[output_pos++] = num;
    total_num += num;

    if (i != n)
        return 0;

    if (num >= 0 && num <= 255 && total_num != 0 && numCount == 1 && dotCount == 1)
        return 1;

    return 0;
}

uint8_t analysisValString(Message *msg,
        char *val,
        uint8_t mask,
        int min,
        int max) {

    uint8_t n = strlen(val);

    if (n == 0) {
        msg->valueType = VAL_TYPE_INVALID;
        return 0;
    }

    if (n == 1) {

        uint8_t isNumber = isNum(val); //0~9
        uint8_t bNum1 = mask & 0x40;
        uint8_t bChar = mask & 0x20;

        if (isNumber && bNum1) {
            int v = val[0] - '0';
            if (checkRange(v, min, max)) {
                msg->Value.value_n = v;
                msg->valueType = VAL_TYPE_NUM;
                return 1;
            }
        }

        if (!isNumber && bChar) {
            char c = val[0];
            if (isValidCharParam(c)) { //+,-,?
                msg->valueType = VAL_TYPE_CHAR;
                msg->Value.value_c = c;
                return 1;
            }
        }

        msg->valueType = VAL_TYPE_INVALID;
        return 0;
    } else {

        uint8_t bNumN = mask & 0x10;
        uint8_t bIP = mask & 0x08;
        uint8_t bMAC = mask & 0x04;
        uint8_t bString = mask & 0x02;
        uint8_t bChannel = mask & 0x01;

        if (isAllNums(val) && bNumN) { //??????r?????-??
            int v = atoi(val);
            if (checkRange(v, min, max)) {
                msg->Value.value_n = v;
                msg->valueType = VAL_TYPE_NUM;
                return 1;
            }
        }

        if (bIP) { //???RIP?é?????
            uint8_t *addr = (uint8_t *) calloc(4, sizeof (uint8_t));
            uint8_t b = analysisIP(addr, val);
            if (b) {
                msg->valueType = VAL_TYPE_IP_ADDR;
                for (int i = 0; i < 4; i++)
                    msg->Value.value_ip_addr[i] = addr[i];
                free(addr);
                return 1;
            }
            free(addr);
        }

        if (bMAC) { //???RMAC?é?????
            uint8_t *addr = (uint8_t *) calloc(6, sizeof (uint8_t));
            uint8_t b = analysisMAC(addr, val);
            if (b) {
                msg->valueType = VAL_TYPE_MAC_ADDR;
                for (int i = 0; i < 6; i++)
                    msg->Value.value_mac_addr[i] = addr[i];
                free(addr);
                return 1;
            }
            free(addr);
        }

        if (bChannel) { //???RMAC?é?????
            uint8_t *channel = (uint8_t *) calloc(2, sizeof (uint8_t));
            uint8_t b = analysisChannel(channel, val);
            if (b) {
                msg->valueType = VAL_TYPE_CHANNEL;
                for (int i = 0; i < 2; i++)
                    msg->Value.value_channel[i] = channel[i];
                free(channel);
                return 1;
            }
            free(channel);
        }

        if (bString) { //?@??r??
            msg->valueType = VAL_TYPE_STR;
            msg->Value.value_s = (char *) calloc(n + 1, sizeof (char));
            strncpy(msg->Value.value_s, val, n);
            return 1;
        }

        msg->valueType = VAL_TYPE_INVALID;
        return 0;
    }

    return 0;
}

uint8_t isNum(char *s) {
    return (s[0] >= '0' && s[0] <= '9') ? 1 : 0;
}

uint8_t checkRange(int val, int min, int max) {
    return (val >= min && val <= max) ? 1 : 0;
}

uint8_t isValidCharParam(char c) {
    if (c == '+' || c == '-' || c == '?')
        return 1;
    return 0;
}

uint8_t isAllNums(char *s) {
    int i = 0;
    int n = strlen(s);
    if (s[i] == '-')
        i++;
    for (; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            continue;
        break;
    }
    if (i != n)
        return 0;
    return 1;
}



void ipIntToArray(uint32_t ipInt, uint8_t *arr) {
    for (int i = 0; i < 4; i++)
        arr[i] = (ipInt >> (i * 8)) & 0xFF;
}

/***********************
 * @Function
 *  uint8_t countDigitsOfInt(int numberToBeCount)
 * 
 * @Summary
 *  Count for digits of the numberTobeCount
 * 
 * @Remarks
 *  Refer to the com_lib.h interface header for function usage details.
 *********************/
uint8_t countDigitsOfInt(int numberToBeCount) {
    uint8_t digits = 0;
    do {
        digits++;
        numberToBeCount /= 10;
    } while (numberToBeCount != 0);
    return digits;
}

/***********************
 * @Function
 *  bool setMacAddress(uint8_t addr[6])
 * 
 * @Summary
 *  Set new MAC address.
 * 
 * @Remarks
 *  Refer to the com_lib.h interface header for function usage details.
 *********************/
bool setMacAddress(uint8_t addr[6]) {
    TCPIP_MAC_ADDR newMacAddr;
    for (int i = 0; i < 6; i++) {
        newMacAddr.v[i] = addr[i];
    }

    TCPIP_NET_HANDLE netH;
    int nNets = TCPIP_STACK_NumberOfNetworksGet();
    bool isSuccess = true;

    for (int i = 0; i < nNets; i++) {
        netH = TCPIP_STACK_IndexToNet(i);

        TCPIP_DHCP_Disable(netH);
        isSuccess &= TCPIP_STACK_NetAddressMacSet(netH, &newMacAddr);
    }
    closeAndCreateSocketOfSddp();
    return isSuccess;
}

/***********************
 * @Function
 *  void enableDHCP()
 * 
 * @Summary
 *  Enable DHCP.
 * 
 * @Remarks
 *  Refer to the com_lib.h interface header for function usage details.
 *********************/
void enableDHCP() {
    TCPIP_NET_HANDLE netH;
    int nNets = TCPIP_STACK_NumberOfNetworksGet();

    for (int i = 0; i < nNets; i++) {
        netH = TCPIP_STACK_IndexToNet(i);
        TCPIP_DHCP_Enable(netH);
    }
    setDhcpSS(true); // TODO check if enable successfully
    closeAndCreateSocketOfSddp();
}

/***********************
 * @Function
 *  void diableDHCP()
 * 
 * @Summary
 *  Disable DHCP.
 * 
 * @Remarks
 *  Refer to the com_lib.h interface header for function usage details.
 *********************/
void disableDHCP() {
    TCPIP_NET_HANDLE netH;
    int nNets = TCPIP_STACK_NumberOfNetworksGet();

    for (int i = 0; i < nNets; i++) {
        netH = TCPIP_STACK_IndexToNet(i);
        TCPIP_DHCP_Disable(netH);
    }
    setDhcpSS(false); // TODO check if disable successfully
    closeAndCreateSocketOfSddp();
}

/***********************
 * @Function
 *  bool setIPAddress(uint8_t addr[4])
 * 
 * @Summary
 *  Set new IP address.
 * 
 * @Remarks
 *  Refer to the com_lib.h interface header for function usage details.
 *********************/
bool setIPAddress(uint8_t addr[4]) {
    IPV4_ADDR newAddr;
    for (int i = 0; i < 4; i++) {
        newAddr.v[i] = addr[i];
    }

    TCPIP_NET_HANDLE netH;
    int nNets = TCPIP_STACK_NumberOfNetworksGet();
    bool isSuccess = true;

    for (int i = 0; i < nNets; i++) {
        netH = TCPIP_STACK_IndexToNet(i);

        TCPIP_DHCP_Disable(netH);
        isSuccess &= TCPIP_STACK_NetAddressSet(netH, &newAddr, NULL, false);
    }
    closeAndCreateSocketOfSddp();
    return isSuccess;
}

/***********************
 * @Function
 *  bool setSubMask(uint8_t msk[4])
 * 
 * @Summary
 *  Set new address mask.
 * 
 * @Remarks
 *  Refer to the com_lib.h interface header for function usage details.
 *********************/
bool setSubMask(uint8_t msk[4]) {
    IPV4_ADDR newMsk;
    for (int i = 0; i < 4; i++) {
        newMsk.v[i] = msk[i];
    }

    TCPIP_NET_HANDLE netH;
    int nNets = TCPIP_STACK_NumberOfNetworksGet();
    bool isSuccess = true;

    for (int i = 0; i < nNets; i++) {
        netH = TCPIP_STACK_IndexToNet(i);

        TCPIP_DHCP_Disable(netH);
        isSuccess &= TCPIP_STACK_NetAddressSet(netH, NULL, &newMsk, false);
    }
    closeAndCreateSocketOfSddp();
    return isSuccess;
}

/***********************
 * @Function
 *  bool setGateway(uint8_t addr[4])
 * 
 * @Summary
 *  Set gate way IP address
 * 
 * @Remarks
 *  Refer to the com_lib.h interface header for function usage details.
 * 
 *********************/
bool setGateway(uint8_t addr[4]) {
    IPV4_ADDR mAddr;
    for (int i = 0; i < 4; i++) {
        mAddr.v[i] = addr[i];
    }

    TCPIP_NET_HANDLE netH;
    int nNets = TCPIP_STACK_NumberOfNetworksGet();
    bool isSuccess = true;

    for (int i = 0; i < nNets; i++) {
        netH = TCPIP_STACK_IndexToNet(i);

        TCPIP_DHCP_Disable(netH);
        isSuccess &= TCPIP_STACK_NetAddressGatewaySet(netH, &mAddr);
    }
    closeAndCreateSocketOfSddp();
    return isSuccess;
}

/***********************
 * @Function
 *  setDnsServer(uint8_t addr[4])
 * 
 * @Summary
 *  Set DNS server with specific address
 * 
 * @Remarks
 *  Refer to the com_lib.h interface header for function usage details.
 * 
 *********************/
bool setDnsServer(uint8_t addr[4]) {
    IPV4_ADDR mAddr;
    for (int i = 0; i < 4; i++) {
        mAddr.v[i] = addr[i];
    }

    TCPIP_NET_HANDLE netH;
    int nNets = TCPIP_STACK_NumberOfNetworksGet();
    bool isSuccess = true;

    for (int i = 0; i < nNets; i++) {
        netH = TCPIP_STACK_IndexToNet(i);

        TCPIP_DHCP_Disable(netH);
        isSuccess &= TCPIP_STACK_NetAddressDnsPrimarySet(netH, &mAddr);
    }
    closeAndCreateSocketOfSddp();
    return isSuccess;
}

Message parsingCommand(uint8_t *RS232RxBuffer, size_t RS232RxBufSize) {
    int i, j, k;
    Message msge;
    msge.cmdType = CANNOT_BE_PARSE;    
    if ((RS232RxBufSize >= 8) && (RS232RxBuffer[0] == HMI_Start_Byte) && (RS232RxBuffer[1] == HMI_Start_Byte) && (RS232RxBuffer[2] == HMI_Start_Byte))
    {
        if(EDBG)
        {
            SYS_CONSOLE_PRINT("SERCOM5_RX_ESP32: %s\r\n", RS232RxBuffer);
            SYS_CONSOLE_PRINT("--------------------RX [ASCII]--------------------\r\n");
            for(j=0;j<RS232RxBufSize;j++)
            {
                SYS_CONSOLE_PRINT("0x%02x ",RS232RxBuffer[j]);
                if (((j+1) % 10 == 0) || (j == RS232RxBufSize-1))
                    SYS_CONSOLE_PRINT("\r\n");
            }
            SYS_CONSOLE_PRINT("--------------------------------------------------\r\n"); 
        }
        size_t rx_size=(char) RS232RxBuffer[3];//Size of RX is at 4th dig
        if ((RS232RxBuffer[RS232RxBufSize-6] == 0xC3) && (RS232RxBuffer[RS232RxBufSize-5] == 0xBF) && (RS232RxBuffer[RS232RxBufSize-4] == 0xC3) && 
            (RS232RxBuffer[RS232RxBufSize-3] == 0xBF) && (RS232RxBuffer[RS232RxBufSize-2] == 0xC3) && (RS232RxBuffer[RS232RxBufSize-1] == 0xBF))
        {
            char RxCMDBuffer[rx_size];
            memset(RxCMDBuffer, 0, rx_size); 
            for (int i = 0; i < rx_size; i++)
            {
                RxCMDBuffer[i] = (char) RS232RxBuffer[i+4];
            }
            CheckESP32_Command(&msge, RxCMDBuffer,rx_size,false);
            return msge;
        }
    }
    else
    {
        SYS_CONSOLE_PRINT("RS232RxBuffer: %s\r\n", RS232RxBuffer);
        char RS232RxCMDBuffer[RS232RxBufSize];
        memset(RS232RxCMDBuffer, 0, RS232RxBufSize);
        for (i = 0; i < RS232RxBufSize; i++) 
        {
            if (RS232RxBuffer[i] == 0x02) {
                for (j = i + 1, k = 0; j < RS232RxBufSize; j++, k++) {
                    if (RS232RxBuffer[j] != 0x03) {
                        RS232RxCMDBuffer[k] = (char) RS232RxBuffer[j];
                        SYS_CONSOLE_PRINT("%c", RS232RxBuffer[j]);
                    }
                    if (RS232RxBuffer[j] == 0x03) {
                        RS232RxCMDBuffer[k] = '\0';

                        SYS_CONSOLE_PRINT("re232RxCMDBuffer: %s\r\n", RS232RxCMDBuffer);
                        parse_cmd_string(&msge, RS232RxCMDBuffer);
                        return msge;
                        //RS232RxCMDBuffer[k] = (char)RS232RxBuffer[j];
                    }
                }
            }
        }
        SYS_CONSOLE_PRINT("re232RxCMDBuffer_error: %s\r\n", RS232RxCMDBuffer);
    }
    return msge;
}
Message parsingCommand_SERCOM0_LCW(uint8_t *RxBuffer, size_t RxBufSize)
{
    SYS_CONSOLE_PRINT("[%d]", count_secom0);
    SYS_CONSOLE_PRINT("[%d][%d]", count_papapa,count_lcw);
    //SYS_CONSOLE_PRINT("\r\n");
    count_secom0++;
    Message msge;
    msge.cmdType = CANNOT_BE_PARSE;
    if(EDBG)
    {
        /*
        SYS_CONSOLE_PRINT("SERCOM0_RX: %s\r\n", RxBuffer);
        SYS_CONSOLE_PRINT("SERCOM0_RX_BufferSize: %d\r\n", RxBufSize);
        SYS_CONSOLE_PRINT("--------------------RX [ASCII]--------------------\r\n");
        for(int j=0;j<RxBufSize;j++)
        {
            SYS_CONSOLE_PRINT("0x%02x ",RxBuffer[j]);
            if (((j+1) % 10 == 0) || (j == RxBufSize-1))
                SYS_CONSOLE_PRINT("\r\n");
        }
        SYS_CONSOLE_PRINT("--------------------------------------------------\r\n");*/
    }
    int StartFlag=0;
    size_t rx_size=0;
    if (RxBuffer[0] == HMI_Start_Byte)
    {
        for(int j=1;j<RxBufSize;j++)
        {
            if(RxBuffer[j] != HMI_Start_Byte)
            {
                StartFlag=j;
                rx_size=(char) RxBuffer[j];//Size of RX is at 4th dig
                break;
            }
        }
        char RxCMDBuffer[rx_size];
        memset(RxCMDBuffer, 0, rx_size); 
        for(int i=0;i<rx_size;i++)
        {
            RxCMDBuffer[i]= (char) RxBuffer[i+StartFlag+1];
        }
        count_papapa++;
        CheckHMI_Command(&msge, RxCMDBuffer,rx_size);
        return msge;
    }
    return msge;
}
Message parsingCommand_SERCOM0(uint8_t *RxBuffer, size_t RxBufSize)
{
    SYS_CONSOLE_PRINT("[%d]", count_secom0);
    if(count_secom0 % 100 ==0)
    {
        SYS_CONSOLE_PRINT("[%d][%d]", count_papapa,count_lcw);
    }
    //SYS_CONSOLE_PRINT("\r\n");
    count_secom0++;
    Message msge;
    msge.cmdType = CANNOT_BE_PARSE;
    if(EDBG)
    {
        /*
        SYS_CONSOLE_PRINT("SERCOM0_RX: %s\r\n", RxBuffer);
        SYS_CONSOLE_PRINT("SERCOM0_RX_BufferSize: %d\r\n", RxBufSize);
        SYS_CONSOLE_PRINT("--------------------RX [ASCII]--------------------\r\n");
        for(int j=0;j<RxBufSize;j++)
        {
            SYS_CONSOLE_PRINT("0x%02x ",RxBuffer[j]);
            if (((j+1) % 10 == 0) || (j == RxBufSize-1))
                SYS_CONSOLE_PRINT("\r\n");
        }
        SYS_CONSOLE_PRINT("--------------------------------------------------\r\n"); */
        for(int j=0;j<RxBufSize;j++)
        {
            SYS_CONSOLE_PRINT("0x%02x ",RxBuffer[j]);
        }
    }
    if (RxBufSize >= 8)// at least two Byte 0x25 0x25 0x25 + ____ + ____ + 0xFF 0xFF 0xFF
    {   //ZZBai's HMI Panel via UART, communicate start at [%%%] 0x25 0x25 0x25 (first three byte) and end at 0xFF 0xFF 0xFF (last three byte)
        if ((RxBuffer[0] == HMI_Start_Byte) && (RxBuffer[1] == HMI_Start_Byte) && (RxBuffer[2] == HMI_Start_Byte))
        {  
            SYS_CONSOLE_PRINT("test");
            size_t rx_size=(char) RxBuffer[3];//Size of RX is at 4th dig
            char RxCMDBuffer[rx_size];
            memset(RxCMDBuffer, 0, rx_size); 
            for (int i = 0; i < rx_size; i++)
            {
                RxCMDBuffer[i] = (char) RxBuffer[i+4];
            }
            if((RxBuffer[rx_size+4] == HMI_End_Byte) && (RxBuffer[rx_size+5] == HMI_End_Byte) && (RxBuffer[rx_size+6] == HMI_End_Byte))
            {//-----------ZZ Bai's HMI Panel
                count_papapa++;
                CheckHMI_Command(&msge, RxCMDBuffer,rx_size);
                return msge;
            }
            /*
            else if((RxBuffer[RxBufSize-6] == 0xC3) && (RxBuffer[RxBufSize-5] == 0xBF) && (RxBuffer[RxBufSize-4] == 0xC3) && 
                    (RxBuffer[RxBufSize-3] == 0xBF) && (RxBuffer[RxBufSize-2] == 0xC3) && (RxBuffer[RxBufSize-1] == 0xBF))
            {//-----------Rafael Wu's MCU ESP32 
                CheckESP32_Command(&msge, RxCMDBuffer,rx_size,true); 
                return msge;
            }*/
        }
    }    
    return msge;
}
void CheckHMI_Command(Message *msg, char *chkcmdString,size_t cmd_size) 
{
    int temp_RxBufSize = 0;
    int pRxBufIndex = 0;
    int nRxBufIndex = 0;
    int brl_Buf = 0;
    //char *Als_read_buffer[4];
    //uint8_t Als_read_a;
    //uint8_t Als_read_b;
    //uint8_t Als_read_c;
    //uint8_t Als_read_d;
 //   char Als_read_buffer[5];
    //uint8_t Als_max_a,Als_min_a;
    //uint8_t Als_max_b,Als_min_b;
    //uint8_t Als_max_c,Als_min_c;
    //uint8_t Als_max_d,Als_min_d;
    
    //SYS_CONSOLE_PRINT("temp_RxBufSize: %x\r\n", cmd_size);
    //SYS_CONSOLE_PRINT("chkcmdString[1]: %x\r\n", chkcmdString[1]);
    //SYS_CONSOLE_PRINT("chkcmdString[cmd_size-1]: %x\r\n", chkcmdString[cmd_size-1]);
    //SYS_CONSOLE_PRINT("chkcmdString[cmd_size-2]: %x\r\n", chkcmdString[cmd_size-2]);    
    /*
    SYS_CONSOLE_PRINT("SERCOM0_RX_PAD_CMD: %s\r\n", chkcmdString);
    for(int i=0;i<cmd_size;i++)
    {
        SYS_CONSOLE_PRINT("PAD[%d]: %c [0x%02x] \r\n", i,chkcmdString[i],chkcmdString[i]);
    }*/
    //-----Demo Mode------
    if((chkcmdString[0]=='d') && (chkcmdString[1]=='e') && (chkcmdString[2]=='m') && (chkcmdString[3]=='o') && (chkcmdString[4]!='0'))
    {
        Als_Crlon = 0;
        Als_Demo01 = 0;
        Als_Demo02 = 0;        
        //msg->cmdType =CMD_HMI_Mode_Show;
    }
    //-----Demo01 Mode------
    if((chkcmdString[0]=='d') && (chkcmdString[1]=='e') && (chkcmdString[2]=='m') && (chkcmdString[3]=='o') && (chkcmdString[4]=='0') && (chkcmdString[5]=='1'))
    {
        Als_Crlon = 0;
        Als_Demo01 = 1;
        Als_Demo02 = 0;
        //msg->cmdType =CMD_HMI_Mode_Show1;
    }
    //-----Demo02 Mode------
    if((chkcmdString[0]=='d') && (chkcmdString[1]=='e') && (chkcmdString[2]=='m') && (chkcmdString[3]=='o') && (chkcmdString[4]=='0') && (chkcmdString[5]=='2'))
    {
        Als_Crlon = 0;
        Als_Demo01 = 0;
        Als_Demo02 = 1;
        //msg->cmdType =CMD_HMI_Mode_Show2;
    }    
    //-----Manual Mode------
    else if((chkcmdString[0]=='l') && (chkcmdString[1]=='c') && (chkcmdString[2]=='w'))
    {
        Als_Crlon = 0;
        Als_Demo01 = 0;
        Als_Demo02 = 0;
        //msg->cmdType =CMD_HMI_Mode_Manual;
        MCU_TX_HMI_EnterLCW();
    }
    //-----Als Mode------
    else if((chkcmdString[0]=='a') && (chkcmdString[1]=='l') && (chkcmdString[2]=='s') && (chkcmdString[3]!='m'))
    {
        Als_Crlon = 1;
        Als_Demo01 = 0;
        Als_Demo02 = 0;        
        SYS_CONSOLE_PRINT("Als_Crlon = %x\r\n", Als_Crlon);
        //msg->cmdType =CMD_HMI_Mode_Manual;
    }
    //-----Als max set------
    else if((chkcmdString[0]=='a') && (chkcmdString[1]=='l') && (chkcmdString[2]=='s') && (chkcmdString[3]=='m') && (chkcmdString[4]=='a') && (chkcmdString[5]=='x') && (chkcmdString[6]=='='))
    {
#if 1
        Als_max = (chkcmdString[7]-0x30)*10000 + (chkcmdString[8]-0x30)*1000 + (chkcmdString[9]-0x30)*100 + (chkcmdString[10]-0x30)*10 + (chkcmdString[11]-0x30);
#elif        
        if(chkcmdString[7] > 0x60) {
         Als_max_a = chkcmdString[7]-0x61 + 0x0a;   
        }else{
         Als_max_a = chkcmdString[7] - 0x30;
        }
       
        if(chkcmdString[8] > 0x60) {
         Als_max_b = chkcmdString[8]-0x61 + 0x0a;   
        }else{
         Als_max_b = chkcmdString[8] - 0x30;
        }
       
        if(chkcmdString[9] > 0x60) {
         Als_max_c = chkcmdString[9]-0x61 + 0x0a;   
        }else{
         Als_max_c = chkcmdString[9] - 0x30;
        }
       
        if(chkcmdString[10] > 0x60) {
         Als_max_d = chkcmdString[10]-0x61 + 0x0a;   
        }else{
         Als_max_d = chkcmdString[10] - 0x30;
        } 
       
         Als_max = Als_max_a*16*16*16 + Als_max_b*16*16 + Als_max_c*16 + Als_max_d;
#endif         
         SYS_CONSOLE_PRINT("Als_max = %x\r\n", Als_max);
        //Als_max = 1;
        //msg->cmdType =CMD_HMI_Mode_Manual;
    }
    //-----Als min set------
    else if((chkcmdString[0]=='a') && (chkcmdString[1]=='l') && (chkcmdString[2]=='s') && (chkcmdString[3]=='m') && (chkcmdString[4]=='i') && (chkcmdString[5]=='n') && (chkcmdString[6]=='='))
    {
#if 1
        Als_min = (chkcmdString[7]-0x30)*10000 + (chkcmdString[8]-0x30)*1000 + (chkcmdString[9]-0x30)*100 + (chkcmdString[10]-0x30)*10 + (chkcmdString[11]-0x30);
#elif        
        if(chkcmdString[7] > 0x60) {
         Als_min_a = chkcmdString[7]-0x61 + 0x0a;   
        }else{
         Als_min_a = chkcmdString[7] - 0x30;
        }
       
        if(chkcmdString[8] > 0x60) {
         Als_min_b = chkcmdString[8]-0x61 + 0x0a;   
        }else{
         Als_min_b = chkcmdString[8] - 0x30;
        }
       
        if(chkcmdString[9] > 0x60) {
         Als_min_c = chkcmdString[9]-0x61 + 0x0a;   
        }else{
         Als_min_c = chkcmdString[9] - 0x30;
        }
       
        if(chkcmdString[10] > 0x60) {
         Als_min_d = chkcmdString[10]-0x61 + 0x0a;   
        }else{
         Als_min_d = chkcmdString[10] - 0x30;
        } 
       
         Als_min = Als_min_a*16*16*16 + Als_min_b*16*16 + Als_min_c*16 + Als_min_d;
#endif         
         SYS_CONSOLE_PRINT("Als_min = %x\r\n", Als_min);        
        //Als_min = 1;
        //msg->cmdType =CMD_HMI_Mode_Manual;
    }
    //-----Als read------    
    else if((chkcmdString[0]=='r') && (chkcmdString[1]=='e') && (chkcmdString[2]=='a') && (chkcmdString[3]=='d') && (chkcmdString[4]=='a') && (chkcmdString[5]=='l') && (chkcmdString[6]=='s'))
    {
        Als_Crlon = 0;
        Als_Demo01 = 0;
        Als_Demo02 = 0;
        Als_read = ALS_Read(ALS_1_CTRL_ADDR);
        //Als_read = 0x3E7;    //999
        //Als_read = 0xffff;
        //SYS_CONSOLE_PRINT("Als_read = %x\r\n", Als_read);
        //SYS_CONSOLE_PRINT("Als_read = %d\r\n", Als_read);
        HexToDec(Als_read, Als_read_Buf);
        //IntToChar(Als_read,Als_read_Buf, 10);
        //SYS_CONSOLE_PRINT("Als_read = %x\r\n", Als_read_Buf);
        //SYS_CONSOLE_PRINT("Als_read = %s\r\n", Als_read_Buf);
/*
        Als_read_Buf1 = (((Als_read & 0xF000) >> 12) *16*16*16) + (((Als_read & 0x0F00) >> 8) *16*16) + (((Als_read & 0x00F0) >> 4) *16) + (Als_read & 0x000F);
        SYS_CONSOLE_PRINT("Als_read_Buf1 = %x\r\n", Als_read_Buf1);
        SYS_CONSOLE_PRINT("Als_read_Buf1 = %d\r\n", Als_read_Buf1);
        if(((Als_read_Buf1 & 0xF000) >> 12) > 0x0009) {
        Als_read_buffer[0] = (char)((((Als_read_Buf1 & 0xF000) >> 12) - 0x0009) + 0x60);    
        }else{
        Als_read_buffer[0] = (char)(((Als_read_Buf1 & 0xF000) >> 12) + 0x30);
        }
        SYS_CONSOLE_PRINT("Als_read 1 = %x\r\n", Als_read_buffer[0]);
        if(((Als_read_Buf1 & 0x0F00) >> 8) > 0x0009) {
        Als_read_buffer[1] = (char)((((Als_read_Buf1 & 0x0F00) >> 8) - 0x0009) + 0x60);    
        }else{        
        Als_read_buffer[1] = (char)(((Als_read_Buf1 & 0x0F00) >> 8) + 0x30);
        }
        SYS_CONSOLE_PRINT("Als_read 2 = %x\r\n", Als_read_buffer[1]);
        if(((Als_read_Buf1 & 0x00F0) >> 4) > 0x0009) {
        Als_read_buffer[2] = (char)((((Als_read_Buf1 & 0x00F0) >> 4) - 0x0009) + 0x60);    
        }else{        
        Als_read_buffer[2] = (char)(((Als_read_Buf1 & 0x00F0) >> 4) + 0x30);
        }
        SYS_CONSOLE_PRINT("Als_read 3 = %x\r\n", Als_read_buffer[2]);
        if((Als_read_Buf1 & 0x000F) > 0x0009) {
        Als_read_buffer[3] = (char)(((Als_read_Buf1 & 0x000F) - 0x0009) + 0x60);    
        }else{        
        Als_read_buffer[3] = (char)((Als_read_Buf1 & 0x000F) + 0x30);
        }
        SYS_CONSOLE_PRINT("Als_read 4 = %x\r\n", Als_read_buffer[3]);
*/
        //SYS_CONSOLE_PRINT("Als_read 0 = %x\r\n", Als_read_buffer[0]);
        //SYS_CONSOLE_PRINT("Als_read 1 = %x\r\n", Als_read_buffer[1]);
        //SYS_CONSOLE_PRINT("Als_read 2 = %x\r\n", Als_read_buffer[2]);
        //SYS_CONSOLE_PRINT("Als_read 3 = %x\r\n", Als_read_buffer[3]);
        //SYS_CONSOLE_PRINT("Als_read 4 = %x\r\n", Als_read_buffer[4]);
         MCU_TX_HMI(Als_read_Buf);
        //MCU_TX_HMI(Als_read_buffer);
        //Als_min = 1;
        //msg->cmdType =CMD_HMI_Mode_Manual;
        //strcat(v_cmd_h, IntToChar(_ALS,v_cmd, 10));
        //MCU_TX_PAD("green.en=1");
    }    
    //-----Reset Mode------
    else if((chkcmdString[0]=='r') && (chkcmdString[1]=='e') && (chkcmdString[2]=='s') && (chkcmdString[3]=='e') && (chkcmdString[4]=='t')) 
    {
        msg->cmdType =CMD_HMI_Mode_Reset;
    }
    else if ((chkcmdString[0]=='b') && (chkcmdString[1]=='o') && (chkcmdString[2]=='a') && (chkcmdString[3]=='r') && (chkcmdString[4]=='d'))
    {//begin board with first 5 bit 
        if ((chkcmdString[7]=='c') && (chkcmdString[8]=='h'))
        {// switch by single channel
            //if(HMI_Board && flagHMI)
            if(0)    
            {
                if((chkcmdString[9]=='0') && (chkcmdString[10]=='1') && (chkcmdString[11]=='=') && (chkcmdString[12]=='1') && (chkcmdString[13]=='0') && (chkcmdString[14]=='0')) {
                    msg->cmdType = CMD_L_Pannel_100; temp_hmi_l=6;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='1') && (chkcmdString[11]=='=') && (chkcmdString[12]=='8') && (chkcmdString[13]=='0')) {
                    msg->cmdType = CMD_L_Pannel_80;temp_hmi_l=5;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='1') && (chkcmdString[11]=='=') && (chkcmdString[12]=='6') && (chkcmdString[13]=='0')) {
                    msg->cmdType = CMD_L_Pannel_60;temp_hmi_l=4;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='1') && (chkcmdString[11]=='=') && (chkcmdString[12]=='4') && (chkcmdString[13]=='0')) {
                    msg->cmdType = CMD_L_Pannel_40;temp_hmi_l=3;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='1') && (chkcmdString[11]=='=') && (chkcmdString[12]=='2') && (chkcmdString[13]=='0')) {
                    msg->cmdType = CMD_L_Pannel_20;temp_hmi_l=2;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='1') && (chkcmdString[11]=='=') && (chkcmdString[12]=='0')) {
                    msg->cmdType = CMD_L_Pannel_0;temp_hmi_l=0;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='2') && (chkcmdString[11]=='=') && (chkcmdString[12]=='1') && (chkcmdString[13]=='0') && (chkcmdString[14]=='0')) {
                    msg->cmdType = CMD_R_Pannel_100;temp_hmi_r=6;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='2') && (chkcmdString[11]=='=') && (chkcmdString[12]=='8') && (chkcmdString[13]=='0')) {
                    msg->cmdType = CMD_R_Pannel_80;temp_hmi_r=5;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='2') && (chkcmdString[11]=='=') && (chkcmdString[12]=='6') && (chkcmdString[13]=='0')) {
                    msg->cmdType = CMD_R_Pannel_60;temp_hmi_r=4;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='2') && (chkcmdString[11]=='=') && (chkcmdString[12]=='4') && (chkcmdString[13]=='0')) {
                    msg->cmdType = CMD_R_Pannel_40;temp_hmi_r=3;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='2') && (chkcmdString[11]=='=') && (chkcmdString[12]=='2') && (chkcmdString[13]=='0')) {
                    msg->cmdType = CMD_R_Pannel_20;temp_hmi_r=2;}
                else if((chkcmdString[9]=='0') && (chkcmdString[10]=='2') && (chkcmdString[11]=='=') && (chkcmdString[12]=='0')) {
                    msg->cmdType = CMD_R_Pannel_0;temp_hmi_r=0;}

                msg->hmi_l_value=temp_hmi_l;
                msg->hmi_r_value=temp_hmi_r;
            }
            else
            {
                if((chkcmdString[5]=='0') &&  (chkcmdString[6]=='1'))
                {
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db1;
                    temp_PresentDrivingBoard=0;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D1C1=0;
                        else if(chkcmdString[12]=='1')  temp_D1C1=1;
                        else if(chkcmdString[12]=='2')  temp_D1C1=2;
                        else if(chkcmdString[12]=='3')  temp_D1C1=3;
                        else if(chkcmdString[12]=='4')  temp_D1C1=4;
                        else if(chkcmdString[12]=='5')  temp_D1C1=5;
                        else if(chkcmdString[12]=='6')  temp_D1C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D1C2=0;
                        else if(chkcmdString[12]=='1')  temp_D1C2=1;
                        else if(chkcmdString[12]=='2')  temp_D1C2=2;
                        else if(chkcmdString[12]=='3')  temp_D1C2=3;
                        else if(chkcmdString[12]=='4')  temp_D1C2=4;
                        else if(chkcmdString[12]=='5')  temp_D1C2=5;
                        else if(chkcmdString[12]=='6')  temp_D1C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D1C3=0;
                        else if(chkcmdString[12]=='1')  temp_D1C3=1;
                        else if(chkcmdString[12]=='2')  temp_D1C3=2;
                        else if(chkcmdString[12]=='3')  temp_D1C3=3;
                        else if(chkcmdString[12]=='4')  temp_D1C3=4;
                        else if(chkcmdString[12]=='5')  temp_D1C3=5;
                        else if(chkcmdString[12]=='6')  temp_D1C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D1C4=0;
                        else if(chkcmdString[12]=='1')  temp_D1C4=1;
                        else if(chkcmdString[12]=='2')  temp_D1C4=2;
                        else if(chkcmdString[12]=='3')  temp_D1C4=3;
                        else if(chkcmdString[12]=='4')  temp_D1C4=4;
                        else if(chkcmdString[12]=='5')  temp_D1C4=5;
                        else if(chkcmdString[12]=='6')  temp_D1C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D1C5=0;
                        else if(chkcmdString[12]=='1')  temp_D1C5=1;
                        else if(chkcmdString[12]=='2')  temp_D1C5=2;
                        else if(chkcmdString[12]=='3')  temp_D1C5=3;
                        else if(chkcmdString[12]=='4')  temp_D1C5=4;
                        else if(chkcmdString[12]=='5')  temp_D1C5=5;
                        else if(chkcmdString[12]=='6')  temp_D1C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D1C6=0;
                        else if(chkcmdString[12]=='1')  temp_D1C6=1;
                        else if(chkcmdString[12]=='2')  temp_D1C6=2;
                        else if(chkcmdString[12]=='3')  temp_D1C6=3;
                        else if(chkcmdString[12]=='4')  temp_D1C6=4;
                        else if(chkcmdString[12]=='5')  temp_D1C6=5;
                        else if(chkcmdString[12]=='6')  temp_D1C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D1C7=0;
                        else if(chkcmdString[12]=='1')  temp_D1C7=1;
                        else if(chkcmdString[12]=='2')  temp_D1C7=2;
                        else if(chkcmdString[12]=='3')  temp_D1C7=3;
                        else if(chkcmdString[12]=='4')  temp_D1C7=4;
                        else if(chkcmdString[12]=='5')  temp_D1C7=5;
                        else if(chkcmdString[12]=='6')  temp_D1C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D1C8=0;
                        else if(chkcmdString[12]=='1')  temp_D1C8=1;
                        else if(chkcmdString[12]=='2')  temp_D1C8=2;
                        else if(chkcmdString[12]=='3')  temp_D1C8=3;
                        else if(chkcmdString[12]=='4')  temp_D1C8=4;
                        else if(chkcmdString[12]=='5')  temp_D1C8=5;
                        else if(chkcmdString[12]=='6')  temp_D1C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='0') &&  (chkcmdString[6]=='2'))
                {
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db2;
                    temp_PresentDrivingBoard=1;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D2C1=0;
                        else if(chkcmdString[12]=='1')  temp_D2C1=1;
                        else if(chkcmdString[12]=='2')  temp_D2C1=2;
                        else if(chkcmdString[12]=='3')  temp_D2C1=3;
                        else if(chkcmdString[12]=='4')  temp_D2C1=4;
                        else if(chkcmdString[12]=='5')  temp_D2C1=5;
                        else if(chkcmdString[12]=='6')  temp_D2C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D2C2=0;
                        else if(chkcmdString[12]=='1')  temp_D2C2=1;
                        else if(chkcmdString[12]=='2')  temp_D2C2=2;
                        else if(chkcmdString[12]=='3')  temp_D2C2=3;
                        else if(chkcmdString[12]=='4')  temp_D2C2=4;
                        else if(chkcmdString[12]=='5')  temp_D2C2=5;
                        else if(chkcmdString[12]=='6')  temp_D2C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D2C3=0;
                        else if(chkcmdString[12]=='1')  temp_D2C3=1;
                        else if(chkcmdString[12]=='2')  temp_D2C3=2;
                        else if(chkcmdString[12]=='3')  temp_D2C3=3;
                        else if(chkcmdString[12]=='4')  temp_D2C3=4;
                        else if(chkcmdString[12]=='5')  temp_D2C3=5;
                        else if(chkcmdString[12]=='6')  temp_D2C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D2C4=0;
                        else if(chkcmdString[12]=='1')  temp_D2C4=1;
                        else if(chkcmdString[12]=='2')  temp_D2C4=2;
                        else if(chkcmdString[12]=='3')  temp_D2C4=3;
                        else if(chkcmdString[12]=='4')  temp_D2C4=4;
                        else if(chkcmdString[12]=='5')  temp_D2C4=5;
                        else if(chkcmdString[12]=='6')  temp_D2C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D2C5=0;
                        else if(chkcmdString[12]=='1')  temp_D2C5=1;
                        else if(chkcmdString[12]=='2')  temp_D2C5=2;
                        else if(chkcmdString[12]=='3')  temp_D2C5=3;
                        else if(chkcmdString[12]=='4')  temp_D2C5=4;
                        else if(chkcmdString[12]=='5')  temp_D2C5=5;
                        else if(chkcmdString[12]=='6')  temp_D2C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D2C6=0;
                        else if(chkcmdString[12]=='1')  temp_D2C6=1;
                        else if(chkcmdString[12]=='2')  temp_D2C6=2;
                        else if(chkcmdString[12]=='3')  temp_D2C6=3;
                        else if(chkcmdString[12]=='4')  temp_D2C6=4;
                        else if(chkcmdString[12]=='5')  temp_D2C6=5;
                        else if(chkcmdString[12]=='6')  temp_D2C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D2C7=0;
                        else if(chkcmdString[12]=='1')  temp_D2C7=1;
                        else if(chkcmdString[12]=='2')  temp_D2C7=2;
                        else if(chkcmdString[12]=='3')  temp_D2C7=3;
                        else if(chkcmdString[12]=='4')  temp_D2C7=4;
                        else if(chkcmdString[12]=='5')  temp_D2C7=5;
                        else if(chkcmdString[12]=='6')  temp_D2C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D2C8=0;
                        else if(chkcmdString[12]=='1')  temp_D2C8=1;
                        else if(chkcmdString[12]=='2')  temp_D2C8=2;
                        else if(chkcmdString[12]=='3')  temp_D2C8=3;
                        else if(chkcmdString[12]=='4')  temp_D2C8=4;
                        else if(chkcmdString[12]=='5')  temp_D2C8=5;
                        else if(chkcmdString[12]=='6')  temp_D2C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='0') &&  (chkcmdString[6]=='3')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db3;
                    temp_PresentDrivingBoard=2;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D3C1=0;
                        else if(chkcmdString[12]=='1')  temp_D3C1=1;
                        else if(chkcmdString[12]=='2')  temp_D3C1=2;
                        else if(chkcmdString[12]=='3')  temp_D3C1=3;
                        else if(chkcmdString[12]=='4')  temp_D3C1=4;
                        else if(chkcmdString[12]=='5')  temp_D3C1=5;
                        else if(chkcmdString[12]=='6')  temp_D3C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D3C2=0;
                        else if(chkcmdString[12]=='1')  temp_D3C2=1;
                        else if(chkcmdString[12]=='2')  temp_D3C2=2;
                        else if(chkcmdString[12]=='3')  temp_D3C2=3;
                        else if(chkcmdString[12]=='4')  temp_D3C2=4;
                        else if(chkcmdString[12]=='5')  temp_D3C2=5;
                        else if(chkcmdString[12]=='6')  temp_D3C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D3C3=0;
                        else if(chkcmdString[12]=='1')  temp_D3C3=1;
                        else if(chkcmdString[12]=='2')  temp_D3C3=2;
                        else if(chkcmdString[12]=='3')  temp_D3C3=3;
                        else if(chkcmdString[12]=='4')  temp_D3C3=4;
                        else if(chkcmdString[12]=='5')  temp_D3C3=5;
                        else if(chkcmdString[12]=='6')  temp_D3C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D3C4=0;
                        else if(chkcmdString[12]=='1')  temp_D3C4=1;
                        else if(chkcmdString[12]=='2')  temp_D3C4=2;
                        else if(chkcmdString[12]=='3')  temp_D3C4=3;
                        else if(chkcmdString[12]=='4')  temp_D3C4=4;
                        else if(chkcmdString[12]=='5')  temp_D3C4=5;
                        else if(chkcmdString[12]=='6')  temp_D3C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D3C5=0;
                        else if(chkcmdString[12]=='1')  temp_D3C5=1;
                        else if(chkcmdString[12]=='2')  temp_D3C5=2;
                        else if(chkcmdString[12]=='3')  temp_D3C5=3;
                        else if(chkcmdString[12]=='4')  temp_D3C5=4;
                        else if(chkcmdString[12]=='5')  temp_D3C5=5;
                        else if(chkcmdString[12]=='6')  temp_D3C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D3C6=0;
                        else if(chkcmdString[12]=='1')  temp_D3C6=1;
                        else if(chkcmdString[12]=='2')  temp_D3C6=2;
                        else if(chkcmdString[12]=='3')  temp_D3C6=3;
                        else if(chkcmdString[12]=='4')  temp_D3C6=4;
                        else if(chkcmdString[12]=='5')  temp_D3C6=5;
                        else if(chkcmdString[12]=='6')  temp_D3C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D3C7=0;
                        else if(chkcmdString[12]=='1')  temp_D3C7=1;
                        else if(chkcmdString[12]=='2')  temp_D3C7=2;
                        else if(chkcmdString[12]=='3')  temp_D3C7=3;
                        else if(chkcmdString[12]=='4')  temp_D3C7=4;
                        else if(chkcmdString[12]=='5')  temp_D3C7=5;
                        else if(chkcmdString[12]=='6')  temp_D3C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D3C8=0;
                        else if(chkcmdString[12]=='1')  temp_D3C8=1;
                        else if(chkcmdString[12]=='2')  temp_D3C8=2;
                        else if(chkcmdString[12]=='3')  temp_D3C8=3;
                        else if(chkcmdString[12]=='4')  temp_D3C8=4;
                        else if(chkcmdString[12]=='5')  temp_D3C8=5;
                        else if(chkcmdString[12]=='6')  temp_D3C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='0') &&  (chkcmdString[6]=='4')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db4;
                    temp_PresentDrivingBoard=3;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D4C1=0;
                        else if(chkcmdString[12]=='1')  temp_D4C1=1;
                        else if(chkcmdString[12]=='2')  temp_D4C1=2;
                        else if(chkcmdString[12]=='3')  temp_D4C1=3;
                        else if(chkcmdString[12]=='4')  temp_D4C1=4;
                        else if(chkcmdString[12]=='5')  temp_D4C1=5;
                        else if(chkcmdString[12]=='6')  temp_D4C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D4C2=0;
                        else if(chkcmdString[12]=='1')  temp_D4C2=1;
                        else if(chkcmdString[12]=='2')  temp_D4C2=2;
                        else if(chkcmdString[12]=='3')  temp_D4C2=3;
                        else if(chkcmdString[12]=='4')  temp_D4C2=4;
                        else if(chkcmdString[12]=='5')  temp_D4C2=5;
                        else if(chkcmdString[12]=='6')  temp_D4C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D4C3=0;
                        else if(chkcmdString[12]=='1')  temp_D4C3=1;
                        else if(chkcmdString[12]=='2')  temp_D4C3=2;
                        else if(chkcmdString[12]=='3')  temp_D4C3=3;
                        else if(chkcmdString[12]=='4')  temp_D4C3=4;
                        else if(chkcmdString[12]=='5')  temp_D4C3=5;
                        else if(chkcmdString[12]=='6')  temp_D4C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D4C4=0;
                        else if(chkcmdString[12]=='1')  temp_D4C4=1;
                        else if(chkcmdString[12]=='2')  temp_D4C4=2;
                        else if(chkcmdString[12]=='3')  temp_D4C4=3;
                        else if(chkcmdString[12]=='4')  temp_D4C4=4;
                        else if(chkcmdString[12]=='5')  temp_D4C4=5;
                        else if(chkcmdString[12]=='6')  temp_D4C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D4C5=0;
                        else if(chkcmdString[12]=='1')  temp_D4C5=1;
                        else if(chkcmdString[12]=='2')  temp_D4C5=2;
                        else if(chkcmdString[12]=='3')  temp_D4C5=3;
                        else if(chkcmdString[12]=='4')  temp_D4C5=4;
                        else if(chkcmdString[12]=='5')  temp_D4C5=5;
                        else if(chkcmdString[12]=='6')  temp_D4C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D4C6=0;
                        else if(chkcmdString[12]=='1')  temp_D4C6=1;
                        else if(chkcmdString[12]=='2')  temp_D4C6=2;
                        else if(chkcmdString[12]=='3')  temp_D4C6=3;
                        else if(chkcmdString[12]=='4')  temp_D4C6=4;
                        else if(chkcmdString[12]=='5')  temp_D4C6=5;
                        else if(chkcmdString[12]=='6')  temp_D4C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D4C7=0;
                        else if(chkcmdString[12]=='1')  temp_D4C7=1;
                        else if(chkcmdString[12]=='2')  temp_D4C7=2;
                        else if(chkcmdString[12]=='3')  temp_D4C7=3;
                        else if(chkcmdString[12]=='4')  temp_D4C7=4;
                        else if(chkcmdString[12]=='5')  temp_D4C7=5;
                        else if(chkcmdString[12]=='6')  temp_D4C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D4C8=0;
                        else if(chkcmdString[12]=='1')  temp_D4C8=1;
                        else if(chkcmdString[12]=='2')  temp_D4C8=2;
                        else if(chkcmdString[12]=='3')  temp_D4C8=3;
                        else if(chkcmdString[12]=='4')  temp_D4C8=4;
                        else if(chkcmdString[12]=='5')  temp_D4C8=5;
                        else if(chkcmdString[12]=='6')  temp_D4C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='0') &&  (chkcmdString[6]=='5')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db5;
                    temp_PresentDrivingBoard=4;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D5C1=0;
                        else if(chkcmdString[12]=='1')  temp_D5C1=1;
                        else if(chkcmdString[12]=='2')  temp_D5C1=2;
                        else if(chkcmdString[12]=='3')  temp_D5C1=3;
                        else if(chkcmdString[12]=='4')  temp_D5C1=4;
                        else if(chkcmdString[12]=='5')  temp_D5C1=5;
                        else if(chkcmdString[12]=='6')  temp_D5C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D5C2=0;
                        else if(chkcmdString[12]=='1')  temp_D5C2=1;
                        else if(chkcmdString[12]=='2')  temp_D5C2=2;
                        else if(chkcmdString[12]=='3')  temp_D5C2=3;
                        else if(chkcmdString[12]=='4')  temp_D5C2=4;
                        else if(chkcmdString[12]=='5')  temp_D5C2=5;
                        else if(chkcmdString[12]=='6')  temp_D5C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D5C3=0;
                        else if(chkcmdString[12]=='1')  temp_D5C3=1;
                        else if(chkcmdString[12]=='2')  temp_D5C3=2;
                        else if(chkcmdString[12]=='3')  temp_D5C3=3;
                        else if(chkcmdString[12]=='4')  temp_D5C3=4;
                        else if(chkcmdString[12]=='5')  temp_D5C3=5;
                        else if(chkcmdString[12]=='6')  temp_D5C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D5C4=0;
                        else if(chkcmdString[12]=='1')  temp_D5C4=1;
                        else if(chkcmdString[12]=='2')  temp_D5C4=2;
                        else if(chkcmdString[12]=='3')  temp_D5C4=3;
                        else if(chkcmdString[12]=='4')  temp_D5C4=4;
                        else if(chkcmdString[12]=='5')  temp_D5C4=5;
                        else if(chkcmdString[12]=='6')  temp_D5C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D5C5=0;
                        else if(chkcmdString[12]=='1')  temp_D5C5=1;
                        else if(chkcmdString[12]=='2')  temp_D5C5=2;
                        else if(chkcmdString[12]=='3')  temp_D5C5=3;
                        else if(chkcmdString[12]=='4')  temp_D5C5=4;
                        else if(chkcmdString[12]=='5')  temp_D5C5=5;
                        else if(chkcmdString[12]=='6')  temp_D5C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D5C6=0;
                        else if(chkcmdString[12]=='1')  temp_D5C6=1;
                        else if(chkcmdString[12]=='2')  temp_D5C6=2;
                        else if(chkcmdString[12]=='3')  temp_D5C6=3;
                        else if(chkcmdString[12]=='4')  temp_D5C6=4;
                        else if(chkcmdString[12]=='5')  temp_D5C6=5;
                        else if(chkcmdString[12]=='6')  temp_D5C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D5C7=0;
                        else if(chkcmdString[12]=='1')  temp_D5C7=1;
                        else if(chkcmdString[12]=='2')  temp_D5C7=2;
                        else if(chkcmdString[12]=='3')  temp_D5C7=3;
                        else if(chkcmdString[12]=='4')  temp_D5C7=4;
                        else if(chkcmdString[12]=='5')  temp_D5C7=5;
                        else if(chkcmdString[12]=='6')  temp_D5C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D5C8=0;
                        else if(chkcmdString[12]=='1')  temp_D5C8=1;
                        else if(chkcmdString[12]=='2')  temp_D5C8=2;
                        else if(chkcmdString[12]=='3')  temp_D5C8=3;
                        else if(chkcmdString[12]=='4')  temp_D5C8=4;
                        else if(chkcmdString[12]=='5')  temp_D5C8=5;
                        else if(chkcmdString[12]=='6')  temp_D5C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }        
                }
                else if((chkcmdString[5]=='0') &&  (chkcmdString[6]=='6')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db6;
                    temp_PresentDrivingBoard=5;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D6C1=0;
                        else if(chkcmdString[12]=='1')  temp_D6C1=1;
                        else if(chkcmdString[12]=='2')  temp_D6C1=2;
                        else if(chkcmdString[12]=='3')  temp_D6C1=3;
                        else if(chkcmdString[12]=='4')  temp_D6C1=4;
                        else if(chkcmdString[12]=='5')  temp_D6C1=5;
                        else if(chkcmdString[12]=='6')  temp_D6C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D6C2=0;
                        else if(chkcmdString[12]=='1')  temp_D6C2=1;
                        else if(chkcmdString[12]=='2')  temp_D6C2=2;
                        else if(chkcmdString[12]=='3')  temp_D6C2=3;
                        else if(chkcmdString[12]=='4')  temp_D6C2=4;
                        else if(chkcmdString[12]=='5')  temp_D6C2=5;
                        else if(chkcmdString[12]=='6')  temp_D6C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D6C3=0;
                        else if(chkcmdString[12]=='1')  temp_D6C3=1;
                        else if(chkcmdString[12]=='2')  temp_D6C3=2;
                        else if(chkcmdString[12]=='3')  temp_D6C3=3;
                        else if(chkcmdString[12]=='4')  temp_D6C3=4;
                        else if(chkcmdString[12]=='5')  temp_D6C3=5;
                        else if(chkcmdString[12]=='6')  temp_D6C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D6C4=0;
                        else if(chkcmdString[12]=='1')  temp_D6C4=1;
                        else if(chkcmdString[12]=='2')  temp_D6C4=2;
                        else if(chkcmdString[12]=='3')  temp_D6C4=3;
                        else if(chkcmdString[12]=='4')  temp_D6C4=4;
                        else if(chkcmdString[12]=='5')  temp_D6C4=5;
                        else if(chkcmdString[12]=='6')  temp_D6C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D6C5=0;
                        else if(chkcmdString[12]=='1')  temp_D6C5=1;
                        else if(chkcmdString[12]=='2')  temp_D6C5=2;
                        else if(chkcmdString[12]=='3')  temp_D6C5=3;
                        else if(chkcmdString[12]=='4')  temp_D6C5=4;
                        else if(chkcmdString[12]=='5')  temp_D6C5=5;
                        else if(chkcmdString[12]=='6')  temp_D6C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D6C6=0;
                        else if(chkcmdString[12]=='1')  temp_D6C6=1;
                        else if(chkcmdString[12]=='2')  temp_D6C6=2;
                        else if(chkcmdString[12]=='3')  temp_D6C6=3;
                        else if(chkcmdString[12]=='4')  temp_D6C6=4;
                        else if(chkcmdString[12]=='5')  temp_D6C6=5;
                        else if(chkcmdString[12]=='6')  temp_D6C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D6C7=0;
                        else if(chkcmdString[12]=='1')  temp_D6C7=1;
                        else if(chkcmdString[12]=='2')  temp_D6C7=2;
                        else if(chkcmdString[12]=='3')  temp_D6C7=3;
                        else if(chkcmdString[12]=='4')  temp_D6C7=4;
                        else if(chkcmdString[12]=='5')  temp_D6C7=5;
                        else if(chkcmdString[12]=='6')  temp_D6C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D6C8=0;
                        else if(chkcmdString[12]=='1')  temp_D6C8=1;
                        else if(chkcmdString[12]=='2')  temp_D6C8=2;
                        else if(chkcmdString[12]=='3')  temp_D6C8=3;
                        else if(chkcmdString[12]=='4')  temp_D6C8=4;
                        else if(chkcmdString[12]=='5')  temp_D6C8=5;
                        else if(chkcmdString[12]=='6')  temp_D6C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='0') &&  (chkcmdString[6]=='7')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db7;
                    temp_PresentDrivingBoard=6;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D7C1=0;
                        else if(chkcmdString[12]=='1')  temp_D7C1=1;
                        else if(chkcmdString[12]=='2')  temp_D7C1=2;
                        else if(chkcmdString[12]=='3')  temp_D7C1=3;
                        else if(chkcmdString[12]=='4')  temp_D7C1=4;
                        else if(chkcmdString[12]=='5')  temp_D7C1=5;
                        else if(chkcmdString[12]=='6')  temp_D7C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D7C2=0;
                        else if(chkcmdString[12]=='1')  temp_D7C2=1;
                        else if(chkcmdString[12]=='2')  temp_D7C2=2;
                        else if(chkcmdString[12]=='3')  temp_D7C2=3;
                        else if(chkcmdString[12]=='4')  temp_D7C2=4;
                        else if(chkcmdString[12]=='5')  temp_D7C2=5;
                        else if(chkcmdString[12]=='6')  temp_D7C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D7C3=0;
                        else if(chkcmdString[12]=='1')  temp_D7C3=1;
                        else if(chkcmdString[12]=='2')  temp_D7C3=2;
                        else if(chkcmdString[12]=='3')  temp_D7C3=3;
                        else if(chkcmdString[12]=='4')  temp_D7C3=4;
                        else if(chkcmdString[12]=='5')  temp_D7C3=5;
                        else if(chkcmdString[12]=='6')  temp_D7C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D7C4=0;
                        else if(chkcmdString[12]=='1')  temp_D7C4=1;
                        else if(chkcmdString[12]=='2')  temp_D7C4=2;
                        else if(chkcmdString[12]=='3')  temp_D7C4=3;
                        else if(chkcmdString[12]=='4')  temp_D7C4=4;
                        else if(chkcmdString[12]=='5')  temp_D7C4=5;
                        else if(chkcmdString[12]=='6')  temp_D7C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D7C5=0;
                        else if(chkcmdString[12]=='1')  temp_D7C5=1;
                        else if(chkcmdString[12]=='2')  temp_D7C5=2;
                        else if(chkcmdString[12]=='3')  temp_D7C5=3;
                        else if(chkcmdString[12]=='4')  temp_D7C5=4;
                        else if(chkcmdString[12]=='5')  temp_D7C5=5;
                        else if(chkcmdString[12]=='6')  temp_D7C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D7C6=0;
                        else if(chkcmdString[12]=='1')  temp_D7C6=1;
                        else if(chkcmdString[12]=='2')  temp_D7C6=2;
                        else if(chkcmdString[12]=='3')  temp_D7C6=3;
                        else if(chkcmdString[12]=='4')  temp_D7C6=4;
                        else if(chkcmdString[12]=='5')  temp_D7C6=5;
                        else if(chkcmdString[12]=='6')  temp_D7C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D7C7=0;
                        else if(chkcmdString[12]=='1')  temp_D7C7=1;
                        else if(chkcmdString[12]=='2')  temp_D7C7=2;
                        else if(chkcmdString[12]=='3')  temp_D7C7=3;
                        else if(chkcmdString[12]=='4')  temp_D7C7=4;
                        else if(chkcmdString[12]=='5')  temp_D7C7=5;
                        else if(chkcmdString[12]=='6')  temp_D7C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D7C8=0;
                        else if(chkcmdString[12]=='1')  temp_D7C8=1;
                        else if(chkcmdString[12]=='2')  temp_D7C8=2;
                        else if(chkcmdString[12]=='3')  temp_D7C8=3;
                        else if(chkcmdString[12]=='4')  temp_D7C8=4;
                        else if(chkcmdString[12]=='5')  temp_D7C8=5;
                        else if(chkcmdString[12]=='6')  temp_D7C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='0') &&  (chkcmdString[6]=='8')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db8;
                    temp_PresentDrivingBoard=7;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D8C1=0;
                        else if(chkcmdString[12]=='1')  temp_D8C1=1;
                        else if(chkcmdString[12]=='2')  temp_D8C1=2;
                        else if(chkcmdString[12]=='3')  temp_D8C1=3;
                        else if(chkcmdString[12]=='4')  temp_D8C1=4;
                        else if(chkcmdString[12]=='5')  temp_D8C1=5;
                        else if(chkcmdString[12]=='6')  temp_D8C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D8C2=0;
                        else if(chkcmdString[12]=='1')  temp_D8C2=1;
                        else if(chkcmdString[12]=='2')  temp_D8C2=2;
                        else if(chkcmdString[12]=='3')  temp_D8C2=3;
                        else if(chkcmdString[12]=='4')  temp_D8C2=4;
                        else if(chkcmdString[12]=='5')  temp_D8C2=5;
                        else if(chkcmdString[12]=='6')  temp_D8C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D8C3=0;
                        else if(chkcmdString[12]=='1')  temp_D8C3=1;
                        else if(chkcmdString[12]=='2')  temp_D8C3=2;
                        else if(chkcmdString[12]=='3')  temp_D8C3=3;
                        else if(chkcmdString[12]=='4')  temp_D8C3=4;
                        else if(chkcmdString[12]=='5')  temp_D8C3=5;
                        else if(chkcmdString[12]=='6')  temp_D8C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D8C4=0;
                        else if(chkcmdString[12]=='1')  temp_D8C4=1;
                        else if(chkcmdString[12]=='2')  temp_D8C4=2;
                        else if(chkcmdString[12]=='3')  temp_D8C4=3;
                        else if(chkcmdString[12]=='4')  temp_D8C4=4;
                        else if(chkcmdString[12]=='5')  temp_D8C4=5;
                        else if(chkcmdString[12]=='6')  temp_D8C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D8C5=0;
                        else if(chkcmdString[12]=='1')  temp_D8C5=1;
                        else if(chkcmdString[12]=='2')  temp_D8C5=2;
                        else if(chkcmdString[12]=='3')  temp_D8C5=3;
                        else if(chkcmdString[12]=='4')  temp_D8C5=4;
                        else if(chkcmdString[12]=='5')  temp_D8C5=5;
                        else if(chkcmdString[12]=='6')  temp_D8C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D8C6=0;
                        else if(chkcmdString[12]=='1')  temp_D8C6=1;
                        else if(chkcmdString[12]=='2')  temp_D8C6=2;
                        else if(chkcmdString[12]=='3')  temp_D8C6=3;
                        else if(chkcmdString[12]=='4')  temp_D8C6=4;
                        else if(chkcmdString[12]=='5')  temp_D8C6=5;
                        else if(chkcmdString[12]=='6')  temp_D8C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D8C7=0;
                        else if(chkcmdString[12]=='1')  temp_D8C7=1;
                        else if(chkcmdString[12]=='2')  temp_D8C7=2;
                        else if(chkcmdString[12]=='3')  temp_D8C7=3;
                        else if(chkcmdString[12]=='4')  temp_D8C7=4;
                        else if(chkcmdString[12]=='5')  temp_D8C7=5;
                        else if(chkcmdString[12]=='6')  temp_D8C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D8C8=0;
                        else if(chkcmdString[12]=='1')  temp_D8C8=1;
                        else if(chkcmdString[12]=='2')  temp_D8C8=2;
                        else if(chkcmdString[12]=='3')  temp_D8C8=3;
                        else if(chkcmdString[12]=='4')  temp_D8C8=4;
                        else if(chkcmdString[12]=='5')  temp_D8C8=5;
                        else if(chkcmdString[12]=='6')  temp_D8C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='0') &&  (chkcmdString[6]=='9')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db9;
                    temp_PresentDrivingBoard=8;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D9C1=0;
                        else if(chkcmdString[12]=='1')  temp_D9C1=1;
                        else if(chkcmdString[12]=='2')  temp_D9C1=2;
                        else if(chkcmdString[12]=='3')  temp_D9C1=3;
                        else if(chkcmdString[12]=='4')  temp_D9C1=4;
                        else if(chkcmdString[12]=='5')  temp_D9C1=5;
                        else if(chkcmdString[12]=='6')  temp_D9C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D9C2=0;
                        else if(chkcmdString[12]=='1')  temp_D9C2=1;
                        else if(chkcmdString[12]=='2')  temp_D9C2=2;
                        else if(chkcmdString[12]=='3')  temp_D9C2=3;
                        else if(chkcmdString[12]=='4')  temp_D9C2=4;
                        else if(chkcmdString[12]=='5')  temp_D9C2=5;
                        else if(chkcmdString[12]=='6')  temp_D9C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D9C3=0;
                        else if(chkcmdString[12]=='1')  temp_D9C3=1;
                        else if(chkcmdString[12]=='2')  temp_D9C3=2;
                        else if(chkcmdString[12]=='3')  temp_D9C3=3;
                        else if(chkcmdString[12]=='4')  temp_D9C3=4;
                        else if(chkcmdString[12]=='5')  temp_D9C3=5;
                        else if(chkcmdString[12]=='6')  temp_D9C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D9C4=0;
                        else if(chkcmdString[12]=='1')  temp_D9C4=1;
                        else if(chkcmdString[12]=='2')  temp_D9C4=2;
                        else if(chkcmdString[12]=='3')  temp_D9C4=3;
                        else if(chkcmdString[12]=='4')  temp_D9C4=4;
                        else if(chkcmdString[12]=='5')  temp_D9C4=5;
                        else if(chkcmdString[12]=='6')  temp_D9C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D9C5=0;
                        else if(chkcmdString[12]=='1')  temp_D9C5=1;
                        else if(chkcmdString[12]=='2')  temp_D9C5=2;
                        else if(chkcmdString[12]=='3')  temp_D9C5=3;
                        else if(chkcmdString[12]=='4')  temp_D9C5=4;
                        else if(chkcmdString[12]=='5')  temp_D9C5=5;
                        else if(chkcmdString[12]=='6')  temp_D9C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D9C6=0;
                        else if(chkcmdString[12]=='1')  temp_D9C6=1;
                        else if(chkcmdString[12]=='2')  temp_D9C6=2;
                        else if(chkcmdString[12]=='3')  temp_D9C6=3;
                        else if(chkcmdString[12]=='4')  temp_D9C6=4;
                        else if(chkcmdString[12]=='5')  temp_D9C6=5;
                        else if(chkcmdString[12]=='6')  temp_D9C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D9C7=0;
                        else if(chkcmdString[12]=='1')  temp_D9C7=1;
                        else if(chkcmdString[12]=='2')  temp_D9C7=2;
                        else if(chkcmdString[12]=='3')  temp_D9C7=3;
                        else if(chkcmdString[12]=='4')  temp_D9C7=4;
                        else if(chkcmdString[12]=='5')  temp_D9C7=5;
                        else if(chkcmdString[12]=='6')  temp_D9C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D9C8=0;
                        else if(chkcmdString[12]=='1')  temp_D9C8=1;
                        else if(chkcmdString[12]=='2')  temp_D9C8=2;
                        else if(chkcmdString[12]=='3')  temp_D9C8=3;
                        else if(chkcmdString[12]=='4')  temp_D9C8=4;
                        else if(chkcmdString[12]=='5')  temp_D9C8=5;
                        else if(chkcmdString[12]=='6')  temp_D9C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='1') &&  (chkcmdString[6]=='0')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db10;
                    temp_PresentDrivingBoard=9;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D10C1=0;
                        else if(chkcmdString[12]=='1')  temp_D10C1=1;
                        else if(chkcmdString[12]=='2')  temp_D10C1=2;
                        else if(chkcmdString[12]=='3')  temp_D10C1=3;
                        else if(chkcmdString[12]=='4')  temp_D10C1=4;
                        else if(chkcmdString[12]=='5')  temp_D10C1=5;
                        else if(chkcmdString[12]=='6')  temp_D10C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D10C2=0;
                        else if(chkcmdString[12]=='1')  temp_D10C2=1;
                        else if(chkcmdString[12]=='2')  temp_D10C2=2;
                        else if(chkcmdString[12]=='3')  temp_D10C2=3;
                        else if(chkcmdString[12]=='4')  temp_D10C2=4;
                        else if(chkcmdString[12]=='5')  temp_D10C2=5;
                        else if(chkcmdString[12]=='6')  temp_D10C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D10C3=0;
                        else if(chkcmdString[12]=='1')  temp_D10C3=1;
                        else if(chkcmdString[12]=='2')  temp_D10C3=2;
                        else if(chkcmdString[12]=='3')  temp_D10C3=3;
                        else if(chkcmdString[12]=='4')  temp_D10C3=4;
                        else if(chkcmdString[12]=='5')  temp_D10C3=5;
                        else if(chkcmdString[12]=='6')  temp_D10C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D10C4=0;
                        else if(chkcmdString[12]=='1')  temp_D10C4=1;
                        else if(chkcmdString[12]=='2')  temp_D10C4=2;
                        else if(chkcmdString[12]=='3')  temp_D10C4=3;
                        else if(chkcmdString[12]=='4')  temp_D10C4=4;
                        else if(chkcmdString[12]=='5')  temp_D10C4=5;
                        else if(chkcmdString[12]=='6')  temp_D10C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D10C5=0;
                        else if(chkcmdString[12]=='1')  temp_D10C5=1;
                        else if(chkcmdString[12]=='2')  temp_D10C5=2;
                        else if(chkcmdString[12]=='3')  temp_D10C5=3;
                        else if(chkcmdString[12]=='4')  temp_D10C5=4;
                        else if(chkcmdString[12]=='5')  temp_D10C5=5;
                        else if(chkcmdString[12]=='6')  temp_D10C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D10C6=0;
                        else if(chkcmdString[12]=='1')  temp_D10C6=1;
                        else if(chkcmdString[12]=='2')  temp_D10C6=2;
                        else if(chkcmdString[12]=='3')  temp_D10C6=3;
                        else if(chkcmdString[12]=='4')  temp_D10C6=4;
                        else if(chkcmdString[12]=='5')  temp_D10C6=5;
                        else if(chkcmdString[12]=='6')  temp_D10C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D10C7=0;
                        else if(chkcmdString[12]=='1')  temp_D10C7=1;
                        else if(chkcmdString[12]=='2')  temp_D10C7=2;
                        else if(chkcmdString[12]=='3')  temp_D10C7=3;
                        else if(chkcmdString[12]=='4')  temp_D10C7=4;
                        else if(chkcmdString[12]=='5')  temp_D10C7=5;
                        else if(chkcmdString[12]=='6')  temp_D10C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D10C8=0;
                        else if(chkcmdString[12]=='1')  temp_D10C8=1;
                        else if(chkcmdString[12]=='2')  temp_D10C8=2;
                        else if(chkcmdString[12]=='3')  temp_D10C8=3;
                        else if(chkcmdString[12]=='4')  temp_D10C8=4;
                        else if(chkcmdString[12]=='5')  temp_D10C8=5;
                        else if(chkcmdString[12]=='6')  temp_D10C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='1') &&  (chkcmdString[6]=='1')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db11;
                    temp_PresentDrivingBoard=10;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D11C1=0;
                        else if(chkcmdString[12]=='1')  temp_D11C1=1;
                        else if(chkcmdString[12]=='2')  temp_D11C1=2;
                        else if(chkcmdString[12]=='3')  temp_D11C1=3;
                        else if(chkcmdString[12]=='4')  temp_D11C1=4;
                        else if(chkcmdString[12]=='5')  temp_D11C1=5;
                        else if(chkcmdString[12]=='6')  temp_D11C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D10C2=0;
                        else if(chkcmdString[12]=='1')  temp_D11C2=1;
                        else if(chkcmdString[12]=='2')  temp_D11C2=2;
                        else if(chkcmdString[12]=='3')  temp_D11C2=3;
                        else if(chkcmdString[12]=='4')  temp_D11C2=4;
                        else if(chkcmdString[12]=='5')  temp_D11C2=5;
                        else if(chkcmdString[12]=='6')  temp_D11C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D11C3=0;
                        else if(chkcmdString[12]=='1')  temp_D11C3=1;
                        else if(chkcmdString[12]=='2')  temp_D11C3=2;
                        else if(chkcmdString[12]=='3')  temp_D11C3=3;
                        else if(chkcmdString[12]=='4')  temp_D11C3=4;
                        else if(chkcmdString[12]=='5')  temp_D11C3=5;
                        else if(chkcmdString[12]=='6')  temp_D11C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D11C4=0;
                        else if(chkcmdString[12]=='1')  temp_D11C4=1;
                        else if(chkcmdString[12]=='2')  temp_D11C4=2;
                        else if(chkcmdString[12]=='3')  temp_D11C4=3;
                        else if(chkcmdString[12]=='4')  temp_D11C4=4;
                        else if(chkcmdString[12]=='5')  temp_D11C4=5;
                        else if(chkcmdString[12]=='6')  temp_D11C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D11C5=0;
                        else if(chkcmdString[12]=='1')  temp_D11C5=1;
                        else if(chkcmdString[12]=='2')  temp_D11C5=2;
                        else if(chkcmdString[12]=='3')  temp_D11C5=3;
                        else if(chkcmdString[12]=='4')  temp_D11C5=4;
                        else if(chkcmdString[12]=='5')  temp_D11C5=5;
                        else if(chkcmdString[12]=='6')  temp_D11C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D11C6=0;
                        else if(chkcmdString[12]=='1')  temp_D11C6=1;
                        else if(chkcmdString[12]=='2')  temp_D11C6=2;
                        else if(chkcmdString[12]=='3')  temp_D11C6=3;
                        else if(chkcmdString[12]=='4')  temp_D11C6=4;
                        else if(chkcmdString[12]=='5')  temp_D11C6=5;
                        else if(chkcmdString[12]=='6')  temp_D11C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D11C7=0;
                        else if(chkcmdString[12]=='1')  temp_D11C7=1;
                        else if(chkcmdString[12]=='2')  temp_D11C7=2;
                        else if(chkcmdString[12]=='3')  temp_D11C7=3;
                        else if(chkcmdString[12]=='4')  temp_D11C7=4;
                        else if(chkcmdString[12]=='5')  temp_D11C7=5;
                        else if(chkcmdString[12]=='6')  temp_D11C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D11C8=0;
                        else if(chkcmdString[12]=='1')  temp_D11C8=1;
                        else if(chkcmdString[12]=='2')  temp_D11C8=2;
                        else if(chkcmdString[12]=='3')  temp_D11C8=3;
                        else if(chkcmdString[12]=='4')  temp_D11C8=4;
                        else if(chkcmdString[12]=='5')  temp_D11C8=5;
                        else if(chkcmdString[12]=='6')  temp_D11C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='1') &&  (chkcmdString[6]=='2')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db12;
                    temp_PresentDrivingBoard=11;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D12C1=0;
                        else if(chkcmdString[12]=='1')  temp_D12C1=1;
                        else if(chkcmdString[12]=='2')  temp_D12C1=2;
                        else if(chkcmdString[12]=='3')  temp_D12C1=3;
                        else if(chkcmdString[12]=='4')  temp_D12C1=4;
                        else if(chkcmdString[12]=='5')  temp_D12C1=5;
                        else if(chkcmdString[12]=='6')  temp_D12C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D12C2=0;
                        else if(chkcmdString[12]=='1')  temp_D12C2=1;
                        else if(chkcmdString[12]=='2')  temp_D12C2=2;
                        else if(chkcmdString[12]=='3')  temp_D12C2=3;
                        else if(chkcmdString[12]=='4')  temp_D12C2=4;
                        else if(chkcmdString[12]=='5')  temp_D12C2=5;
                        else if(chkcmdString[12]=='6')  temp_D12C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D12C3=0;
                        else if(chkcmdString[12]=='1')  temp_D12C3=1;
                        else if(chkcmdString[12]=='2')  temp_D12C3=2;
                        else if(chkcmdString[12]=='3')  temp_D12C3=3;
                        else if(chkcmdString[12]=='4')  temp_D12C3=4;
                        else if(chkcmdString[12]=='5')  temp_D12C3=5;
                        else if(chkcmdString[12]=='6')  temp_D12C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D12C4=0;
                        else if(chkcmdString[12]=='1')  temp_D12C4=1;
                        else if(chkcmdString[12]=='2')  temp_D12C4=2;
                        else if(chkcmdString[12]=='3')  temp_D12C4=3;
                        else if(chkcmdString[12]=='4')  temp_D12C4=4;
                        else if(chkcmdString[12]=='5')  temp_D12C4=5;
                        else if(chkcmdString[12]=='6')  temp_D12C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D12C5=0;
                        else if(chkcmdString[12]=='1')  temp_D12C5=1;
                        else if(chkcmdString[12]=='2')  temp_D12C5=2;
                        else if(chkcmdString[12]=='3')  temp_D12C5=3;
                        else if(chkcmdString[12]=='4')  temp_D12C5=4;
                        else if(chkcmdString[12]=='5')  temp_D12C5=5;
                        else if(chkcmdString[12]=='6')  temp_D12C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D12C6=0;
                        else if(chkcmdString[12]=='1')  temp_D12C6=1;
                        else if(chkcmdString[12]=='2')  temp_D12C6=2;
                        else if(chkcmdString[12]=='3')  temp_D12C6=3;
                        else if(chkcmdString[12]=='4')  temp_D12C6=4;
                        else if(chkcmdString[12]=='5')  temp_D12C6=5;
                        else if(chkcmdString[12]=='6')  temp_D12C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D12C7=0;
                        else if(chkcmdString[12]=='1')  temp_D12C7=1;
                        else if(chkcmdString[12]=='2')  temp_D12C7=2;
                        else if(chkcmdString[12]=='3')  temp_D12C7=3;
                        else if(chkcmdString[12]=='4')  temp_D12C7=4;
                        else if(chkcmdString[12]=='5')  temp_D12C7=5;
                        else if(chkcmdString[12]=='6')  temp_D12C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D12C8=0;
                        else if(chkcmdString[12]=='1')  temp_D12C8=1;
                        else if(chkcmdString[12]=='2')  temp_D12C8=2;
                        else if(chkcmdString[12]=='3')  temp_D12C8=3;
                        else if(chkcmdString[12]=='4')  temp_D12C8=4;
                        else if(chkcmdString[12]=='5')  temp_D12C8=5;
                        else if(chkcmdString[12]=='6')  temp_D12C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='1') &&  (chkcmdString[6]=='3')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db13;
                    temp_PresentDrivingBoard=12;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D13C1=0;
                        else if(chkcmdString[12]=='1')  temp_D13C1=1;
                        else if(chkcmdString[12]=='2')  temp_D13C1=2;
                        else if(chkcmdString[12]=='3')  temp_D13C1=3;
                        else if(chkcmdString[12]=='4')  temp_D13C1=4;
                        else if(chkcmdString[12]=='5')  temp_D13C1=5;
                        else if(chkcmdString[12]=='6')  temp_D13C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D13C2=0;
                        else if(chkcmdString[12]=='1')  temp_D13C2=1;
                        else if(chkcmdString[12]=='2')  temp_D13C2=2;
                        else if(chkcmdString[12]=='3')  temp_D13C2=3;
                        else if(chkcmdString[12]=='4')  temp_D13C2=4;
                        else if(chkcmdString[12]=='5')  temp_D13C2=5;
                        else if(chkcmdString[12]=='6')  temp_D13C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D13C3=0;
                        else if(chkcmdString[12]=='1')  temp_D13C3=1;
                        else if(chkcmdString[12]=='2')  temp_D13C3=2;
                        else if(chkcmdString[12]=='3')  temp_D13C3=3;
                        else if(chkcmdString[12]=='4')  temp_D13C3=4;
                        else if(chkcmdString[12]=='5')  temp_D13C3=5;
                        else if(chkcmdString[12]=='6')  temp_D13C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D13C4=0;
                        else if(chkcmdString[12]=='1')  temp_D13C4=1;
                        else if(chkcmdString[12]=='2')  temp_D13C4=2;
                        else if(chkcmdString[12]=='3')  temp_D13C4=3;
                        else if(chkcmdString[12]=='4')  temp_D13C4=4;
                        else if(chkcmdString[12]=='5')  temp_D13C4=5;
                        else if(chkcmdString[12]=='6')  temp_D13C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D13C5=0;
                        else if(chkcmdString[12]=='1')  temp_D13C5=1;
                        else if(chkcmdString[12]=='2')  temp_D13C5=2;
                        else if(chkcmdString[12]=='3')  temp_D13C5=3;
                        else if(chkcmdString[12]=='4')  temp_D13C5=4;
                        else if(chkcmdString[12]=='5')  temp_D13C5=5;
                        else if(chkcmdString[12]=='6')  temp_D13C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D13C6=0;
                        else if(chkcmdString[12]=='1')  temp_D13C6=1;
                        else if(chkcmdString[12]=='2')  temp_D13C6=2;
                        else if(chkcmdString[12]=='3')  temp_D13C6=3;
                        else if(chkcmdString[12]=='4')  temp_D13C6=4;
                        else if(chkcmdString[12]=='5')  temp_D13C6=5;
                        else if(chkcmdString[12]=='6')  temp_D13C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D13C7=0;
                        else if(chkcmdString[12]=='1')  temp_D13C7=1;
                        else if(chkcmdString[12]=='2')  temp_D13C7=2;
                        else if(chkcmdString[12]=='3')  temp_D13C7=3;
                        else if(chkcmdString[12]=='4')  temp_D13C7=4;
                        else if(chkcmdString[12]=='5')  temp_D13C7=5;
                        else if(chkcmdString[12]=='6')  temp_D13C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D13C8=0;
                        else if(chkcmdString[12]=='1')  temp_D13C8=1;
                        else if(chkcmdString[12]=='2')  temp_D13C8=2;
                        else if(chkcmdString[12]=='3')  temp_D13C8=3;
                        else if(chkcmdString[12]=='4')  temp_D13C8=4;
                        else if(chkcmdString[12]=='5')  temp_D13C8=5;
                        else if(chkcmdString[12]=='6')  temp_D13C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else if((chkcmdString[5]=='1') &&  (chkcmdString[6]=='4')){
                    msg->cmdType =CMD_LCW_Show;
                    //msg->_PresentDrivingBoard=db14;
                    temp_PresentDrivingBoard=13;
                    if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='1'))
                    {
                        if(chkcmdString[12]=='0')   temp_D14C1=0;
                        else if(chkcmdString[12]=='1')  temp_D14C1=1;
                        else if(chkcmdString[12]=='2')  temp_D14C1=2;
                        else if(chkcmdString[12]=='3')  temp_D14C1=3;
                        else if(chkcmdString[12]=='4')  temp_D14C1=4;
                        else if(chkcmdString[12]=='5')  temp_D14C1=5;
                        else if(chkcmdString[12]=='6')  temp_D14C1=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='2'))
                    {
                        if(chkcmdString[12]=='0')   temp_D14C2=0;
                        else if(chkcmdString[12]=='1')  temp_D14C2=1;
                        else if(chkcmdString[12]=='2')  temp_D14C2=2;
                        else if(chkcmdString[12]=='3')  temp_D14C2=3;
                        else if(chkcmdString[12]=='4')  temp_D14C2=4;
                        else if(chkcmdString[12]=='5')  temp_D14C2=5;
                        else if(chkcmdString[12]=='6')  temp_D14C2=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='3'))
                    {
                        if(chkcmdString[12]=='0')   temp_D14C3=0;
                        else if(chkcmdString[12]=='1')  temp_D14C3=1;
                        else if(chkcmdString[12]=='2')  temp_D14C3=2;
                        else if(chkcmdString[12]=='3')  temp_D14C3=3;
                        else if(chkcmdString[12]=='4')  temp_D14C3=4;
                        else if(chkcmdString[12]=='5')  temp_D14C3=5;
                        else if(chkcmdString[12]=='6')  temp_D14C3=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='4'))
                    {
                        if(chkcmdString[12]=='0')   temp_D14C4=0;
                        else if(chkcmdString[12]=='1')  temp_D14C4=1;
                        else if(chkcmdString[12]=='2')  temp_D14C4=2;
                        else if(chkcmdString[12]=='3')  temp_D14C4=3;
                        else if(chkcmdString[12]=='4')  temp_D14C4=4;
                        else if(chkcmdString[12]=='5')  temp_D14C4=5;
                        else if(chkcmdString[12]=='6')  temp_D14C4=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='5'))
                    {
                        if(chkcmdString[12]=='0')   temp_D14C5=0;
                        else if(chkcmdString[12]=='1')  temp_D14C5=1;
                        else if(chkcmdString[12]=='2')  temp_D14C5=2;
                        else if(chkcmdString[12]=='3')  temp_D14C5=3;
                        else if(chkcmdString[12]=='4')  temp_D14C5=4;
                        else if(chkcmdString[12]=='5')  temp_D14C5=5;
                        else if(chkcmdString[12]=='6')  temp_D14C5=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='6'))
                    {
                        if(chkcmdString[12]=='0')   temp_D14C6=0;
                        else if(chkcmdString[12]=='1')  temp_D14C6=1;
                        else if(chkcmdString[12]=='2')  temp_D14C6=2;
                        else if(chkcmdString[12]=='3')  temp_D14C6=3;
                        else if(chkcmdString[12]=='4')  temp_D14C6=4;
                        else if(chkcmdString[12]=='5')  temp_D14C6=5;
                        else if(chkcmdString[12]=='6')  temp_D14C6=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='7'))
                    {
                        if(chkcmdString[12]=='0')   temp_D14C7=0;
                        else if(chkcmdString[12]=='1')  temp_D14C7=1;
                        else if(chkcmdString[12]=='2')  temp_D14C7=2;
                        else if(chkcmdString[12]=='3')  temp_D14C7=3;
                        else if(chkcmdString[12]=='4')  temp_D14C7=4;
                        else if(chkcmdString[12]=='5')  temp_D14C7=5;
                        else if(chkcmdString[12]=='6')  temp_D14C7=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else if((chkcmdString[9]=='0') &&  (chkcmdString[10]=='8'))
                    {
                        if(chkcmdString[12]=='0')   temp_D14C8=0;
                        else if(chkcmdString[12]=='1')  temp_D14C8=1;
                        else if(chkcmdString[12]=='2')  temp_D14C8=2;
                        else if(chkcmdString[12]=='3')  temp_D14C8=3;
                        else if(chkcmdString[12]=='4')  temp_D14C8=4;
                        else if(chkcmdString[12]=='5')  temp_D14C8=5;
                        else if(chkcmdString[12]=='6')  temp_D14C8=6;
                        else    msg->cmdType = CMD_TYPE_INVALID;
                    }
                    else 
                    {
                        msg->cmdType = CMD_TYPE_INVALID;
                    }
                }
                else
                {
                    msg->cmdType = CMD_TYPE_INVALID;
                }
                msg->_PresentDrivingBoard=temp_PresentDrivingBoard;   
                msg->_D1C1=temp_D1C1;msg->_D1C2=temp_D1C2;msg->_D1C3=temp_D1C3;msg->_D1C4=temp_D1C4;msg->_D1C5=temp_D1C5;msg->_D1C6=temp_D1C6;msg->_D1C7=temp_D1C7;msg->_D1C8=temp_D1C8;
                msg->_D2C1=temp_D2C1;msg->_D2C2=temp_D2C2;msg->_D2C3=temp_D2C3;msg->_D2C4=temp_D2C4;msg->_D2C5=temp_D2C5;msg->_D2C6=temp_D2C6;msg->_D2C7=temp_D2C7;msg->_D2C8=temp_D2C8;
                msg->_D3C1=temp_D3C1;msg->_D3C2=temp_D3C2;msg->_D3C3=temp_D3C3;msg->_D3C4=temp_D3C4;msg->_D3C5=temp_D3C5;msg->_D3C6=temp_D3C6;msg->_D3C7=temp_D3C7;msg->_D3C8=temp_D3C8;
                msg->_D4C1=temp_D4C1;msg->_D4C2=temp_D4C2;msg->_D4C3=temp_D4C3;msg->_D4C4=temp_D4C4;msg->_D4C5=temp_D4C5;msg->_D4C6=temp_D4C6;msg->_D4C7=temp_D4C7;msg->_D4C8=temp_D4C8;
                msg->_D5C1=temp_D5C1;msg->_D5C2=temp_D5C2;msg->_D5C3=temp_D5C3;msg->_D5C4=temp_D5C4;msg->_D5C5=temp_D5C5;msg->_D5C6=temp_D5C6;msg->_D5C7=temp_D5C7;msg->_D5C8=temp_D5C8;
                msg->_D6C1=temp_D6C1;msg->_D6C2=temp_D6C2;msg->_D6C3=temp_D6C3;msg->_D6C4=temp_D6C4;msg->_D6C5=temp_D6C5;msg->_D6C6=temp_D6C6;msg->_D6C7=temp_D6C7;msg->_D6C8=temp_D6C8;
                msg->_D7C1=temp_D7C1;msg->_D7C2=temp_D7C2;msg->_D7C3=temp_D7C3;msg->_D7C4=temp_D7C4;msg->_D7C5=temp_D7C5;msg->_D7C6=temp_D7C6;msg->_D7C7=temp_D7C7;msg->_D7C8=temp_D7C8;
                msg->_D8C1=temp_D8C1;msg->_D8C2=temp_D8C2;msg->_D8C3=temp_D8C3;msg->_D8C4=temp_D8C4;msg->_D8C5=temp_D8C5;msg->_D8C6=temp_D8C6;msg->_D8C7=temp_D8C7;msg->_D8C8=temp_D8C8;
                msg->_D9C1=temp_D9C1;msg->_D9C2=temp_D9C2;msg->_D9C3=temp_D9C3;msg->_D9C4=temp_D9C4;msg->_D9C5=temp_D9C5;msg->_D9C6=temp_D9C6;msg->_D9C7=temp_D9C7;msg->_D9C8=temp_D9C8;
                msg->_D10C1=temp_D10C1;msg->_D10C2=temp_D10C2;msg->_D10C3=temp_D10C3;msg->_D10C4=temp_D10C4;msg->_D10C5=temp_D10C5;msg->_D10C6=temp_D10C6;msg->_D10C7=temp_D10C7;msg->_D10C8=temp_D10C8;
                msg->_D11C1=temp_D11C1;msg->_D11C2=temp_D11C2;msg->_D11C3=temp_D11C3;msg->_D11C4=temp_D11C4;msg->_D11C5=temp_D11C5;msg->_D11C6=temp_D11C6;msg->_D11C7=temp_D11C7;msg->_D11C8=temp_D11C8;
                msg->_D12C1=temp_D12C1;msg->_D12C2=temp_D12C2;msg->_D12C3=temp_D12C3;msg->_D12C4=temp_D12C4;msg->_D12C5=temp_D12C5;msg->_D12C6=temp_D12C6;msg->_D12C7=temp_D12C7;msg->_D12C8=temp_D12C8;
                msg->_D13C1=temp_D13C1;msg->_D13C2=temp_D13C2;msg->_D13C3=temp_D13C3;msg->_D13C4=temp_D13C4;msg->_D13C5=temp_D13C5;msg->_D13C6=temp_D13C6;msg->_D13C7=temp_D13C7;msg->_D13C8=temp_D13C8;
                msg->_D14C1=temp_D14C1;msg->_D14C2=temp_D14C2;msg->_D14C3=temp_D14C3;msg->_D14C4=temp_D14C4;msg->_D14C5=temp_D14C5;msg->_D14C6=temp_D14C6;msg->_D14C7=temp_D14C7;msg->_D14C8=temp_D14C8;    
                if(EDBG)
                {
                    SYS_CONSOLE_PRINT("[PresentDrivingBoard:0x%02x]\r\n ",msg->_PresentDrivingBoard);
                    SYS_CONSOLE_PRINT("0 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D1C1,temp_D1C2,temp_D1C3,temp_D1C4,temp_D1C5,temp_D1C6,temp_D1C7,temp_D1C8);
                    SYS_CONSOLE_PRINT("1 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D2C1,temp_D2C2,temp_D2C3,temp_D2C4,temp_D2C5,temp_D2C6,temp_D2C7,temp_D2C8);
                    SYS_CONSOLE_PRINT("2 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D3C1,temp_D3C2,temp_D3C3,temp_D3C4,temp_D3C5,temp_D3C6,temp_D3C7,temp_D3C8);
                    SYS_CONSOLE_PRINT("3 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D4C1,temp_D4C2,temp_D4C3,temp_D4C4,temp_D4C5,temp_D4C6,temp_D4C7,temp_D4C8);
                    SYS_CONSOLE_PRINT("4 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D5C1,temp_D5C2,temp_D5C3,temp_D5C4,temp_D5C5,temp_D5C6,temp_D5C7,temp_D5C8);
                    SYS_CONSOLE_PRINT("5 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D6C1,temp_D6C2,temp_D6C3,temp_D6C4,temp_D6C5,temp_D6C6,temp_D6C7,temp_D6C8);
                    SYS_CONSOLE_PRINT("6 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D7C1,temp_D7C2,temp_D7C3,temp_D7C4,temp_D7C5,temp_D7C6,temp_D7C7,temp_D7C8);
                    SYS_CONSOLE_PRINT("7 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D8C1,temp_D8C2,temp_D8C3,temp_D8C4,temp_D8C5,temp_D8C6,temp_D8C7,temp_D8C8);
                    SYS_CONSOLE_PRINT("8 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D9C1,temp_D9C2,temp_D9C3,temp_D9C4,temp_D9C5,temp_D9C6,temp_D9C7,temp_D9C8);
                    SYS_CONSOLE_PRINT("9 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D10C1,temp_D10C2,temp_D10C3,temp_D10C4,temp_D10C5,temp_D10C6,temp_D10C7,temp_D10C8);
                    SYS_CONSOLE_PRINT("10 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D11C1,temp_D11C2,temp_D11C3,temp_D11C4,temp_D11C5,temp_D11C6,temp_D11C7,temp_D11C8);
                    SYS_CONSOLE_PRINT("11 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D12C1,temp_D12C2,temp_D12C3,temp_D12C4,temp_D12C5,temp_D12C6,temp_D12C7,temp_D12C8);
                    SYS_CONSOLE_PRINT("12 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D13C1,temp_D13C2,temp_D13C3,temp_D13C4,temp_D13C5,temp_D13C6,temp_D13C7,temp_D13C8);
                    SYS_CONSOLE_PRINT("13 =[%d][%d][%d][%d][%d][%d][%d][%d]\r\n ",temp_D14C1,temp_D14C2,temp_D14C3,temp_D14C4,temp_D14C5,temp_D14C6,temp_D14C7,temp_D14C8);
                }
                if (msg->cmdType == CMD_LCW_Show)
                {
                    count_lcw++;
                }
            }
        }
        }
    //percy
    else if((chkcmdString[0]=='b') && (chkcmdString[1]=='o') && (chkcmdString[2]=='a') && (chkcmdString[3]=='r') && (chkcmdString[4]=='d') && (chkcmdString[cmd_size-2]=='='))
    {
          msg->cmdType =CMD_LCW_ShowAll;
          temp_RxBufSize = (cmd_size-7)/2;
          
          for(int j=0;j<14;j++){
          driv_board[j] = 0;
          }
          //SYS_CONSOLE_PRINT("temp_RxBufSize: %d\r\n", temp_RxBufSize);
          //SYS_CONSOLE_PRINT("chkcmdString[cmd_size-2]: %x\r\n", chkcmdString[cmd_size-2]);
          for(int i=0;i<temp_RxBufSize;i++)
          {
              pRxBufIndex = 5+(2*i);
              nRxBufIndex = 6+(2*i);
            if((chkcmdString[pRxBufIndex]=='0') &&  (chkcmdString[nRxBufIndex]=='1')){
                driv_board[0] = 1;
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D1C1 = brl_Buf; msg->_D1C2 = brl_Buf; msg->_D1C3 = brl_Buf; msg->_D1C4 = brl_Buf; msg->_D1C5 = brl_Buf; msg->_D1C6 = brl_Buf; msg->_D1C7 = brl_Buf; msg->_D1C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D1C4 = %x\r\n", msg->_D1C4);
            }else if((chkcmdString[pRxBufIndex]=='0') &&  (chkcmdString[nRxBufIndex]=='2')){
                driv_board[1] = 1;                
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D2C1 = brl_Buf; msg->_D2C2 = brl_Buf; msg->_D2C3 = brl_Buf; msg->_D2C4 = brl_Buf; msg->_D2C5 = brl_Buf; msg->_D2C6 = brl_Buf; msg->_D2C7 = brl_Buf; msg->_D2C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D2C4 = %x\r\n", msg->_D2C4);
            }else if((chkcmdString[pRxBufIndex]=='0') &&  (chkcmdString[nRxBufIndex]=='3')){
                driv_board[2] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D3C1 = brl_Buf; msg->_D3C2 = brl_Buf; msg->_D3C3 = brl_Buf; msg->_D3C4 = brl_Buf; msg->_D3C5 = brl_Buf; msg->_D3C6 = brl_Buf; msg->_D3C7 = brl_Buf; msg->_D3C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D3C4 = %x\r\n", msg->_D3C4);
            }else if((chkcmdString[pRxBufIndex]=='0') &&  (chkcmdString[nRxBufIndex]=='4')){
                driv_board[3] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D4C1 = brl_Buf; msg->_D4C2 = brl_Buf; msg->_D4C3 = brl_Buf; msg->_D4C4 = brl_Buf; msg->_D4C5 = brl_Buf; msg->_D4C6 = brl_Buf; msg->_D4C7 = brl_Buf; msg->_D4C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D4C4 = %x\r\n", msg->_D4C4);
            }else if((chkcmdString[pRxBufIndex]=='0') &&  (chkcmdString[nRxBufIndex]=='5')){
                driv_board[4] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D5C1 = brl_Buf; msg->_D5C2 = brl_Buf; msg->_D5C3 = brl_Buf; msg->_D5C4 = brl_Buf; msg->_D5C5 = brl_Buf; msg->_D5C6 = brl_Buf; msg->_D5C7 = brl_Buf; msg->_D5C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D5C4 = %x\r\n", msg->_D5C4);
            }else if((chkcmdString[pRxBufIndex]=='0') &&  (chkcmdString[nRxBufIndex]=='6')){
                driv_board[5] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D6C1 = brl_Buf; msg->_D6C2 = brl_Buf; msg->_D6C3 = brl_Buf; msg->_D6C4 = brl_Buf; msg->_D6C5 = brl_Buf; msg->_D6C6 = brl_Buf; msg->_D6C7 = brl_Buf; msg->_D6C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D6C4 = %x\r\n", msg->_D6C4);
            }else if((chkcmdString[pRxBufIndex]=='0') &&  (chkcmdString[nRxBufIndex]=='7')){ 
                driv_board[6] = 1;                
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D7C1 = brl_Buf; msg->_D7C2 = brl_Buf; msg->_D7C3 = brl_Buf; msg->_D7C4 = brl_Buf; msg->_D7C5 = brl_Buf; msg->_D7C6 = brl_Buf; msg->_D7C7 = brl_Buf; msg->_D7C8 = brl_Buf;
                SYS_CONSOLE_PRINT("msg->_D7C4 = %x\r\n", msg->_D7C4);
            }else if((chkcmdString[pRxBufIndex]=='0') &&  (chkcmdString[nRxBufIndex]=='8')){
                driv_board[7] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D8C1 = brl_Buf; msg->_D8C2 = brl_Buf; msg->_D8C3 = brl_Buf; msg->_D8C4 = brl_Buf; msg->_D8C5 = brl_Buf; msg->_D8C6 = brl_Buf; msg->_D8C7 = brl_Buf; msg->_D8C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D8C4 = %x\r\n", msg->_D8C4);
            }else if((chkcmdString[pRxBufIndex]=='0') &&  (chkcmdString[nRxBufIndex]=='9')){
                driv_board[8] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D9C1 = brl_Buf; msg->_D9C2 = brl_Buf; msg->_D9C3 = brl_Buf; msg->_D9C4 = brl_Buf; msg->_D9C5 = brl_Buf; msg->_D9C6 = brl_Buf; msg->_D9C7 = brl_Buf; msg->_D9C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D9C4 = %x\r\n", msg->_D9C4);
            }else if((chkcmdString[pRxBufIndex]=='1') &&  (chkcmdString[nRxBufIndex]=='0')){
                driv_board[9] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D10C1 = brl_Buf; msg->_D10C2 = brl_Buf; msg->_D10C3 = brl_Buf; msg->_D10C4 = brl_Buf; msg->_D10C5 = brl_Buf; msg->_D10C6 = brl_Buf; msg->_D10C7 = brl_Buf; msg->_D10C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D10C4 = %x\r\n", msg->_D10C4);
            }else if((chkcmdString[pRxBufIndex]=='1') &&  (chkcmdString[nRxBufIndex]=='1')){
                driv_board[10] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D11C1 = brl_Buf; msg->_D11C2 = brl_Buf; msg->_D11C3 = brl_Buf; msg->_D11C4 = brl_Buf; msg->_D11C5 = brl_Buf; msg->_D11C6 = brl_Buf; msg->_D11C7 = brl_Buf; msg->_D11C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D11C4 = %x\r\n", msg->_D11C4);
            }else if((chkcmdString[pRxBufIndex]=='1') &&  (chkcmdString[nRxBufIndex]=='2')){
                driv_board[11] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D12C1 = brl_Buf; msg->_D12C2 = brl_Buf; msg->_D12C3 = brl_Buf; msg->_D12C4 = brl_Buf; msg->_D12C5 = brl_Buf; msg->_D12C6 = brl_Buf; msg->_D12C7 = brl_Buf; msg->_D12C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D12C4 = %x\r\n", msg->_D12C4);
            }else if((chkcmdString[pRxBufIndex]=='1') &&  (chkcmdString[nRxBufIndex]=='3')){
                driv_board[12] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D13C1 = brl_Buf; msg->_D13C2 = brl_Buf; msg->_D13C3 = brl_Buf; msg->_D13C4 = brl_Buf; msg->_D13C5 = brl_Buf; msg->_D13C6 = brl_Buf; msg->_D13C7 = brl_Buf; msg->_D13C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D13C4 = %x\r\n", msg->_D13C4);
            }else if((chkcmdString[pRxBufIndex]=='1') &&  (chkcmdString[nRxBufIndex]=='4')){
                driv_board[13] = 1; 
                brl_Buf = chkcmdString[cmd_size-1]-0x30;
                msg->_D14C1 = brl_Buf; msg->_D14C2 = brl_Buf; msg->_D14C3 = brl_Buf; msg->_D14C4 = brl_Buf; msg->_D14C5 = brl_Buf; msg->_D14C6 = brl_Buf; msg->_D14C7 = brl_Buf; msg->_D14C8 = brl_Buf;
                //SYS_CONSOLE_PRINT("msg->_D14C4 = %x\r\n", msg->_D14C4);
            }    
                            
          }
    }  //percy 
    else
        msg->cmdType = CMD_TYPE_INVALID;
    return;
}
void CheckESP32_Command(Message *msg, char *chkcmdString,size_t cmd_size,bool sercom0_channel) 
{
    int symbol_equal=0;
    if (sercom0_channel)
        SYS_CONSOLE_PRINT("SERCOM0_RX_ESP32_CMD: %s\r\n", chkcmdString);
    else
        SYS_CONSOLE_PRINT("SERCOM5_RX_ESP32_CMD: %s\r\n", chkcmdString);
    for(int i=0;i<cmd_size;i++)
    {
        SYS_CONSOLE_PRINT("ESP32[%d]: %c [0x%02x] \r\n", i,chkcmdString[i],chkcmdString[i]);
        if (chkcmdString[i] == '=')
            symbol_equal=i;
    }
    if((chkcmdString[0] == 'A') && (chkcmdString[1] == 'L') && (chkcmdString[2] == 'S'))
    {
        uint16_t _ALS=ALS_Read(ALS_1_CTRL_ADDR);
        if ((_ALS != 0xFFFF) && (_ALS != 0x0000))
        {
            char v_cmd_h[20]="ALS=";
            char v_cmd[20];
            if (sercom0_channel)
                MCU_TX_ESP32(true,strcat(v_cmd_h, IntToChar(_ALS,v_cmd, 10)));
            else
                MCU_TX_ESP32(false,strcat(v_cmd_h, IntToChar(_ALS,v_cmd, 10)));
        }
    }
    else if(chkcmdString[0]=='b')
    {
        if(symbol_equal != 0)
        {
            size_t lcw_value_size= cmd_size-symbol_equal-1;
            char lcw_value[lcw_value_size];
            memset(lcw_value, 0, lcw_value_size); 
            for (int i = symbol_equal+1; i < cmd_size; i++)
            {
                lcw_value[i-symbol_equal-1] = (char) chkcmdString[i];
            }
            SYS_CONSOLE_PRINT("lcw_value: %s\r\n", lcw_value);
            LCW_Brightness(Driving_Board_1_CTRL_ADDR,CharToInt8(lcw_value));
        }
    }
        
    //msg->cmdType = CMD_HMI_RX_Error;
    //msg->cmdType = CMD_TYPE_INVALID;
    return;
}
size_t GetCharlen(const char *str)
{
    size_t i;
    for (i = 0; str[i]; i++);
    return i;
}
size_t GetUint8_len(const uint8_t *str)
{
    size_t i;
    for (i = 0; str[i]; i++);
    return i;
}
void MCU_TX_PAD(char *buffer)
{
    size_t TXBufSize=GetCharlen(buffer)+3;
    uint8_t TXCMD[TXBufSize];
    memset(TXCMD, 0, TXBufSize);
    SYS_CONSOLE_MESSAGE("SERCOM0_TX: ");
    for (int i = 0; i < TXBufSize-3; i++)
    //for (int i = 0; i < TXBufSize-3; i++)
    {
        TXCMD[i] = (char) buffer[i];
        SYS_CONSOLE_PRINT("%c", buffer[i]);
    }
    SYS_CONSOLE_MESSAGE("\r\n");
    TXCMD[TXBufSize-3]=HMI_End_Byte;    
    TXCMD[TXBufSize-2]=HMI_End_Byte;    
    TXCMD[TXBufSize-1]=HMI_End_Byte;
    SYS_CONSOLE_PRINT("SERCOM0_TX_PAD_CMD: %s\r\n", TXCMD);
    SYS_CONSOLE_PRINT("--------------------TX [ASCII]--------------------\r\n");
    for(int j=0;j<TXBufSize;j++)
    {
        SYS_CONSOLE_PRINT("0x%02x ",TXCMD[j]);
        if (((j+1) % 10 == 0) || (j == TXBufSize-1))
            SYS_CONSOLE_PRINT("\r\n");
    }
    SYS_CONSOLE_PRINT("--------------------------------------------------\r\n"); 
    if(SERCOM0_USART_Write(TXCMD, TXBufSize))
        SYS_CONSOLE_MESSAGE("SERCOM0_USART_Write [PAD] Success!\r\n");
    else
        SYS_CONSOLE_MESSAGE("SERCOM0_USART_Write [PAD] Error!\r\n");
}
void MCU_TX_ESP32(bool sercom0,char *buffer)//Rafael's MCU (Send UART to ESP32)
{
    size_t PreCheckWordSize=9;
    size_t TXBufSize=GetCharlen(buffer)+PreCheckWordSize;
    //size_t TXBufSize=GetUint8_len(buffer)+PreCheckWordSize;
    uint8_t TXCMD[TXBufSize];
    memset(TXCMD, 0, TXBufSize);
    TXCMD[0]=HMI_Start_Byte;    
    TXCMD[1]=HMI_Start_Byte;    
    TXCMD[2]=HMI_Start_Byte;
    TXCMD[3]=(char) 'E';
    TXCMD[4]=(char) 'S';
    TXCMD[5]=(char) 'P';
    TXCMD[6]=(char) '3';
    TXCMD[7]=(char) '2';
    TXCMD[8]=(char) ':';
    
    if(sercom0)
        SYS_CONSOLE_MESSAGE("SERCOM0_TX: ");
    else     
        SYS_CONSOLE_MESSAGE("SERCOM5_TX: ");
    for (int i = PreCheckWordSize; i < TXBufSize; i++)
    {
        TXCMD[i] = (char) buffer[i-PreCheckWordSize];
        SYS_CONSOLE_PRINT("%c", buffer[i-PreCheckWordSize]);
    }
    SYS_CONSOLE_MESSAGE("\r\n");
    if(sercom0)
        SYS_CONSOLE_PRINT("SERCOM0_TX_ESP32_CMD: %s\r\n", TXCMD); 
    else     
        SYS_CONSOLE_PRINT("SERCOM5_TX_ESP32_CMD: %s\r\n", TXCMD);   
    SYS_CONSOLE_PRINT("--------------------TX [ASCII]--------------------\r\n");
    for(int j=0;j<TXBufSize;j++)
    {
        SYS_CONSOLE_PRINT("0x%02x ",TXCMD[j]);
        if (((j+1) % 10 == 0) || (j == TXBufSize-1))
            SYS_CONSOLE_PRINT("\r\n");
    }
    SYS_CONSOLE_PRINT("--------------------------------------------------\r\n");    
    if(sercom0)
    {
        if(SERCOM0_USART_Write(TXCMD, TXBufSize))
            SYS_CONSOLE_MESSAGE("SERCOM0_USART_Write [ESP32] Success!\r\n");
        else
            SYS_CONSOLE_MESSAGE("SERCOM0_USART_Write [ESP32] Error!\r\n");            
    }
    else     
    {
        if(SERCOM5_USART_Write(TXCMD, TXBufSize))
            SYS_CONSOLE_MESSAGE("SERCOM5_USART_Write [ESP32] Success!\r\n");
        else
            SYS_CONSOLE_MESSAGE("SERCOM5_USART_Write [ESP32] Error!\r\n");
    }
}
uint8_t CharToInt8(char *v_buffer)
{
    return (uint8_t)atoi(v_buffer);
}
int CharToInt(char v_buffer)
{
    if (v_buffer==0x30)
        return 0;
    else if (v_buffer==0x31)
        return 1;
    else if (v_buffer==0x32)
        return 2;
    else if (v_buffer==0x33)
        return 3;
    else if (v_buffer==0x34)
        return 4;
    else if (v_buffer==0x35)
        return 5;
    else if (v_buffer==0x36)
        return 6;
    else
        return 0;
}
char* IntToChar(int num, char* buffer, int base)   
{   
    int current = 0;
    if (num == 0) 
    {  
        buffer[current++] = '0';  
        buffer[current] = '\0';  
        return buffer;  
    }
    int num_digits = 0;  
    if (num < 0) 
    {  
        if (base == 10) 
        {  
            num_digits ++;  
            buffer[current] = '-';  
            current ++;  
            num *= -1;  
        }  
        else  
        return NULL;  
    }  
    num_digits += (int)floor(log(num) / log(base)) + 1;  
    while (current < num_digits)   
    {  
        int base_val = (int) pow(base, num_digits-1-current);  
        int num_val = num / base_val;  
        char value = num_val + '0';  
        buffer[current] = value;  
        current ++;  
        num -= base_val * num_val;  
    }  
    buffer[current] = '\0';  
    return buffer;  
}  
void HMI_RX_Error()
{
    //MCU_TX_PAD("tm0.en=1");
}
void LCW_DefaultValue()
{
    temp_PresentDrivingBoard=0;
    temp_D1C1=0;temp_D1C2=0;temp_D1C3=0;temp_D1C4=0;temp_D1C5=0;temp_D1C6=0;temp_D1C7=0;temp_D1C8=0;
    temp_D2C1=0;temp_D2C2=0;temp_D2C3=0;temp_D2C4=0;temp_D2C5=0;temp_D2C6=0;temp_D2C7=0;temp_D2C8=0;
    temp_D3C1=0;temp_D3C2=0;temp_D3C3=0;temp_D3C4=0;temp_D3C5=0;temp_D3C6=0;temp_D3C7=0;temp_D3C8=0;
    temp_D4C1=0;temp_D4C2=0;temp_D4C3=0;temp_D4C4=0;temp_D4C5=0;temp_D4C6=0;temp_D4C7=0;temp_D4C8=0;
    temp_D5C1=0;temp_D5C2=0;temp_D5C3=0;temp_D5C4=0;temp_D5C5=0;temp_D5C6=0;temp_D5C7=0;temp_D5C8=0;
    temp_D6C1=0;temp_D6C2=0;temp_D6C3=0;temp_D6C4=0;temp_D6C5=0;temp_D6C6=0;temp_D6C7=0;temp_D6C8=0;
    temp_D7C1=0;temp_D7C2=0;temp_D7C3=0;temp_D7C4=0;temp_D7C5=0;temp_D7C6=0;temp_D7C7=0;temp_D7C8=0;
    temp_D8C1=0;temp_D8C2=0;temp_D8C3=0;temp_D8C4=0;temp_D8C5=0;temp_D8C6=0;temp_D8C7=0;temp_D8C8=0;
    temp_D9C1=0;temp_D9C2=0;temp_D9C3=0;temp_D9C4=0;temp_D9C5=0;temp_D9C6=0;temp_D9C7=0;temp_D9C8=0;
    temp_D10C1=0;temp_D10C2=0;temp_D10C3=0;temp_D10C4=0;temp_D10C5=0;temp_D10C6=0;temp_D10C7=0;temp_D10C8=0;
    temp_D11C1=0;temp_D11C2=0;temp_D11C3=0;temp_D11C4=0;temp_D11C5=0;temp_D11C6=0;temp_D11C7=0;temp_D11C8=0;
    temp_D12C1=0;temp_D12C2=0;temp_D12C3=0;temp_D12C4=0;temp_D12C5=0;temp_D12C6=0;temp_D12C7=0;temp_D12C8=0;
    temp_D13C1=0;temp_D13C2=0;temp_D13C3=0;temp_D13C4=0;temp_D13C5=0;temp_D13C6=0;temp_D13C7=0;temp_D13C8=0;
    temp_D14C1=0;temp_D14C2=0;temp_D14C3=0;temp_D14C4=0;temp_D14C5=0;temp_D14C6=0;temp_D14C7=0;temp_D14C8=0;
}
 void GPIO_PB09_High(bool v_flag)
 {
     //true: pull high; 
     //false: pull low
     if(v_flag)
     {
         if(GPIO_PB09_Get() == 0)
             GPIO_PB09_Set() ;
     }
     else
     {
         if(GPIO_PB09_Get() == 1)
             GPIO_PB09_Clear();
     }
 }
 
 void MCU_TX_HMI(char *buffer)       //MCU (Send UART to HMI)
{
    size_t PreCheckWordSize=13;//16;
    //size_t TXBufSize=GetCharlen(buffer)+PreCheckWordSize;
    size_t TXBufSize=sizeof(buffer)+1+PreCheckWordSize+3;
    //size_t TXBufSize=GetUint8_len(buffer)+PreCheckWordSize;
    uint8_t TXCMD[TXBufSize];
    SYS_CONSOLE_PRINT("TXBufSize = %d", TXBufSize);
    memset(TXCMD, 0, TXBufSize);
    //TXCMD[0]=HMI_Start_Byte;    
    //TXCMD[1]=HMI_Start_Byte;    
    //TXCMD[2]=HMI_Start_Byte;
    TXCMD[0]=(char) 'a';
    TXCMD[1]=(char) 'l';
    TXCMD[2]=(char) 's';
    TXCMD[3]=(char) 'v';
    TXCMD[4]=(char) 'a';
    TXCMD[5]=(char) 'l';
    TXCMD[6]=(char) 'u';
    TXCMD[7]=(char) 'e';
    TXCMD[8]=(char) '.';
    TXCMD[9]=(char) 'v';
    TXCMD[10]=(char) 'a';
    TXCMD[11]=(char) 'l';
    TXCMD[12]=(char) '=';
    //TXCMD[13]=(char) '"';

    for (int i = PreCheckWordSize; i < (TXBufSize-3); i++)
    {
        TXCMD[i] = (char) buffer[i-PreCheckWordSize];
        SYS_CONSOLE_PRINT("%c", buffer[i-PreCheckWordSize]);
    }
    //TXCMD[TXBufSize-4]=(char) '"';
    SYS_CONSOLE_MESSAGE("\r\n");
    for (int k = TXBufSize-3; k < TXBufSize; k++)
    {
        TXCMD[k] = HMI_End_Byte;
    }
#if 0    
    SYS_CONSOLE_PRINT("--------------------TX [ASCII]--------------------\r\n");
    for(int j=0;j<TXBufSize;j++)
    {
        SYS_CONSOLE_PRINT("0x%02x ",TXCMD[j]);
        if (((j+1) % 10 == 0) || (j == TXBufSize-1))
            SYS_CONSOLE_PRINT("\r\n");
    }
#endif    
    SERCOM0_USART_Write(TXCMD, TXBufSize);
}
 void ALS_AutoRun(void)
 {
  //uint8_t HMI_VALUE[8][14];
  uint8_t LCW_ID_index[7]={6,5,4,3,2,1,0};
  //uint16_t LCW_ID[7]={0xffff,0xd552,0xaaa8,0x7ffe,0x5554,0x2aaa,0x0000};   //bco
  uint8_t LCW_ID[7]={7,6,5,4,3,2,1};
  //uint8_t LCW_ID[7]={1,2,3,4,5,6,7};
  uint8_t Driving_Board_ADDR[14]={Driving_Board_1_CTRL_ADDR,Driving_Board_2_CTRL_ADDR,Driving_Board_3_CTRL_ADDR,Driving_Board_4_CTRL_ADDR,Driving_Board_5_CTRL_ADDR,Driving_Board_6_CTRL_ADDR,Driving_Board_7_CTRL_ADDR,Driving_Board_8_CTRL_ADDR,Driving_Board_9_CTRL_ADDR,Driving_Board_10_CTRL_ADDR,Driving_Board_11_CTRL_ADDR,Driving_Board_12_CTRL_ADDR,Driving_Board_13_CTRL_ADDR,Driving_Board_14_CTRL_ADDR};
  //uint8_t board_star = 1;
  //uint8_t board_stop = 1;//14;
  uint8_t value_step = 0;
  uint16_t ALS_step = 0;
  //char Als_read_GID[1];
  //char Als_read_GID[4];   //bco
  //char Als_read_GID[1];
  char Als_read_PICC[4];
  //int i,j;
  //int j;
  //int i,j,k;
  //memset(HMI_VALUE, 0, sizeof(HMI_VALUE[0][0]) * 14 * 8);
  ALS_step = (Als_max - Als_min)/6;
//Als_min + step*i;
  Als_read = ALS_Read(ALS_1_CTRL_ADDR);
  //Als_read = 0x3e7;
  //Als_read = 0x02db;
  //Als_read = 0x0888;
  //Als_read_B[0] = (char) Als_read;
  value_step = ((Als_read - Als_min)/ALS_step);
  //if((Als_read >= Als_min) && (Als_read <= Als_max))
  if((value_step > 0) && (value_step < 6))    
  {
   //value_step = ((Als_read - Als_min)/ALS_step);
   //ID[value_step];
   //memset(HMI_VALUE, LCW_ID[value_step], sizeof(HMI_VALUE[0][0]) * 14 * 8);
   //SYS_CONSOLE_PRINT("value_step = 0x%02x ",LCW_ID[value_step]);
   //IntToChar(Als_read,Als_read_PICC, 10);
   HexToDec(Als_read, Als_read_PICC);
   MCU_TX_HMI(Als_read_PICC);
   //IntToChar(LCW_ID[value_step],Als_read_GID, 10);
   //Als_read_GID[0] = (char)LCW_ID[value_step];
   //MCU_TX_HMI_PICC(Als_read_GID);
   MCU_TX_HMI_PICC(LCW_ID[value_step]);
   LCW_8Channel(Driving_Board_ADDR[0],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]]);   
#if 0   
   for(i=board_star-1;i<board_stop;i++)
   {
       LCW_8Channel(Driving_Board_ADDR[i],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]]);
    }   
#endif
   /*   
   for(j=board_star-1;j<board_stop;j++)
   {
     for(i=0;i<8;i++)
     {
       //LCW_8Channel(Driving_Board_ADDR[j],hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]));
       LCW_8Channel(Driving_Board_ADDR[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j]);
     }
    }
*/
//  }else if(Als_read < Als_min)   
  }else if(value_step <= 0)
  {
   //memset(HMI_VALUE, LCW_ID[0], sizeof(HMI_VALUE[0][0]) * 14 * 8);
   //SYS_CONSOLE_PRINT("<=min == 0x%02x ",LCW_ID[0]);
   //IntToChar(Als_read,Als_read_PICC, 10);
   HexToDec(Als_read, Als_read_PICC);
   MCU_TX_HMI(Als_read_PICC);
   //IntToChar(LCW_ID[0],Als_read_GID, 10);   
   //Als_read_GID[0] = (char)LCW_ID[0];
   //MCU_TX_HMI_PICC(Als_read_GID);
   MCU_TX_HMI_PICC(LCW_ID[0]);
   LCW_8Channel(Driving_Board_ADDR[0],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]]);   
#if 0
   for(j=board_star-1;j<board_stop;j++)
   {
       LCW_8Channel(Driving_Board_ADDR[j],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]],hmi_value_b[LCW_ID_index[0]]);
    }   
#endif
   /*   
   for(j=board_star-1;j<board_stop;j++)
   {
       LCW_8Channel(Driving_Board_ADDR[j],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]],hmi_value_b[LCW_ID_index[value_step]]);
    }
*/
/*   
   for(j=board_star-1;j<board_stop;j++)
   {
     for(i=0;i<8;i++)
     {
       //LCW_8Channel(Driving_Board_ADDR[j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j]);
       //LCW_8Channel(Driving_Board_ADDR[j],hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]));
     }
    }
*/
   }else{
    //memset(HMI_VALUE, LCW_ID[6], sizeof(HMI_VALUE[0][0]) * 14 * 8);
    //SYS_CONSOLE_PRINT(">=max == 0x%02x ",LCW_ID[6]);
    //IntToChar(Als_read,Als_read_PICC, 10);
    HexToDec(Als_read, Als_read_PICC);
    MCU_TX_HMI(Als_read_PICC);
    //IntToChar(LCW_ID[6],Als_read_GID, 10);    
    //Als_read_GID[0] = (char)LCW_ID[6];
    //MCU_TX_HMI_PICC(Als_read_GID);
    MCU_TX_HMI_PICC(LCW_ID[6]);
    LCW_8Channel(Driving_Board_ADDR[0],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]]);    
#if 0
    for(k=board_star-1;k<board_stop;k++)
   {
       LCW_8Channel(Driving_Board_ADDR[k],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]],hmi_value_b[LCW_ID_index[6]]);
    }    
#endif
    /*    
    for(j=board_star-1;j<board_stop;j++)
    {
      for(i=0;i<8;i++)
      {
        //LCW_8Channel(Driving_Board_ADDR[j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j]);
        //LCW_8Channel(Driving_Board_ADDR[j],hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]));
      }
     }
*/
   }
  //MCU_TX_HMI_ALSON(Als_read_B ,LCW_ID[6] );
  GPIO_PC23_Set();
 }
 
 void MCU_TX_HMI_PICC(uint8_t GID )       //MCU (Send UART to HMI) ALS ON
{
    size_t PreCheckWordSize=13;//11;//13;//15;         11: bco  12: picc
    //size_t TXBufSize=GetCharlen(buffer)+PreCheckWordSize;
    //size_t TXBufSize=sizeof(GID)+PreCheckWordSize+3;
    size_t TXBufSize=PreCheckWordSize+3;
    //size_t TXBufSize=GetUint8_len(buffer)+PreCheckWordSize;
    uint8_t TXCMD[TXBufSize];
    SYS_CONSOLE_PRINT("TXBufSize = %d", TXBufSize);
    memset(TXCMD, 0, TXBufSize);
    //TXCMD[0]=HMI_Start_Byte;    
    //TXCMD[1]=HMI_Start_Byte;    
    //TXCMD[2]=HMI_Start_Byte;
    TXCMD[0]=(char) 'a';
    TXCMD[1]=(char) 'l';
    TXCMD[2]=(char) 's';
    TXCMD[3]=(char) 'l';
    TXCMD[4]=(char) 'c';
    TXCMD[5]=(char) 'w';
    TXCMD[6]=(char) '.';
#if 1   
    TXCMD[7]=(char) 'p';
    TXCMD[8]=(char) 'i';
    TXCMD[9]=(char) 'c';
    TXCMD[10]=(char) 'c';
    TXCMD[11]=(char) '=';
    //TXCMD[12]=(char) '"';
    TXCMD[12]=(char) (GID+'0');
#else
    TXCMD[7]=(char) 'b';
    TXCMD[8]=(char) 'c';
    TXCMD[9]=(char) 'o';
    TXCMD[10]=(char) '=';
    //TXCMD[11]=(char) '"';    
#endif
#if 0           
    for (int i = PreCheckWordSize; i < (TXBufSize-3); i++)
    {
        TXCMD[i] = (char) GID[i-PreCheckWordSize];
        SYS_CONSOLE_PRINT("%c", GID[i-PreCheckWordSize]);
    }
#endif    
    //TXCMD[TXBufSize-4]=(char) '"';    
    SYS_CONSOLE_MESSAGE("\r\n");
    for (int k = TXBufSize-3; k < TXBufSize; k++)
    {
        TXCMD[k] = HMI_End_Byte;
    }
#if 0   
    SYS_CONSOLE_PRINT("--------------------TX [ASCII]--------------------\r\n");
    for(int j=0;j<TXBufSize;j++)
    {
        SYS_CONSOLE_PRINT("0x%02x ",TXCMD[j]);
        if (((j+1) % 10 == 0) || (j == TXBufSize-1))
            SYS_CONSOLE_PRINT("\r\n");
    }
#endif    
    SERCOM0_USART_Write(TXCMD, TXBufSize);
}

void ALS_RunDemo01(void)
 {
    //uint8_t HMI_VALUE[8][14];
    //uint8_t LCW_ID[7]={6,5,4,3,2,1,0};
    //uint8_t LCW_ID[2]={6,0};
    //uint8_t board_star = 1;
    //uint8_t board_stop = 1;//14;
    //int i,j,k;//,z;
    //int i_set,j_set,k_set;
    int count=0;
    uint8_t Driving_Board_ADDR[14]={Driving_Board_1_CTRL_ADDR,Driving_Board_2_CTRL_ADDR,Driving_Board_3_CTRL_ADDR,Driving_Board_4_CTRL_ADDR,Driving_Board_5_CTRL_ADDR,Driving_Board_6_CTRL_ADDR,Driving_Board_7_CTRL_ADDR,Driving_Board_8_CTRL_ADDR,Driving_Board_9_CTRL_ADDR,Driving_Board_10_CTRL_ADDR,Driving_Board_11_CTRL_ADDR,Driving_Board_12_CTRL_ADDR,Driving_Board_13_CTRL_ADDR,Driving_Board_14_CTRL_ADDR};
#if 1
    LCW_8Channel(Driving_Board_ADDR[0],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6]);
    while (count != Als_Delay_ns)
    {
        count++;
    }    
    LCW_8Channel(Driving_Board_ADDR[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0]);
    count = 0;
    while (count != Als_Delay_ns)
    {
        count++;
    }
#endif    
#if 0
    for(k=0;k < 2;j++)
    {
#if 1
    //memset(HMI_VALUE, LCW_ID[k], sizeof(HMI_VALUE[0][0]) * 14 * 8);
    //memset(HMI_VALUE, LCW_ID[k], sizeof(HMI_VALUE));
/*    //==========enter HMI_VALUE value=================================
    for(k_set=0;k_set < 2;k_set++)
    {
        for(j_set=board_star-1;j_set<board_stop;j_set++)
        {
            for(i_set=0;i_set<8;i_set++)
            {
                HMI_VALUE[i_set][j_set] = LCW_ID[k_set];
            }
        }
    }        
    //================================================================= */   
    for(j=board_star-1;j<board_stop;j++)
    {
      for(i=0;i<8;i++)
      {
        //LCW_8Channel(Driving_Board_ADDR[j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j]);
        //LCW_8Channel(Driving_Board_ADDR[j],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]]);
        LCW_8Channel(Driving_Board_ADDR[j],hmi_value_b[LCW_ID[k]],hmi_value_b[LCW_ID[k]],hmi_value_b[LCW_ID[k]],hmi_value_b[LCW_ID[k]],hmi_value_b[LCW_ID[k]],hmi_value_b[LCW_ID[k]],hmi_value_b[LCW_ID[k]],hmi_value_b[LCW_ID[k]]);
      }
     }
//for(z=0;z<100000;z++)
//{
  //  z=z;
//}
    while (count != Als_Delay_ns)
    {
        count++;
    }
    count = 0;
#else        
    memset(HMI_VALUE, LCW_ID[0], sizeof(HMI_VALUE[0][0]) * 14 * 8);
    for(j=board_star-1;j<board_stop;j++)
    {
      for(i=0;i<8;i++)
      {
        //LCW_8Channel(Driving_Board_ADDR[j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j]);
        LCW_8Channel(Driving_Board_ADDR[j],hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]));
      }
     }
        
    while (count != Als_Delay_ns)
    {
        count++;
    }
    
    memset(HMI_VALUE, LCW_ID[6], sizeof(HMI_VALUE[0][0]) * 14 * 8);
    for(j=board_star-1;j<board_stop;j++)
    {
      for(i=0;i<8;i++)
      {
        //LCW_8Channel(Driving_Board_ADDR[j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j]);
        LCW_8Channel(Driving_Board_ADDR[j],hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]));
      }
     }
#endif    
    }
#endif    
} 

void ALS_RunDemo02(void)
 {
    //uint8_t HMI_VALUE[8][14];
    //uint8_t LCW_ID[7]={6,5,4,3,2,1,0};
    //uint8_t LCW_ID[2]={6,0};
    //uint8_t board_star = 1;
    //uint8_t board_stop = 14;
    //int i,j,k;
    int i,j;
    int count=0;
    uint8_t Driving_Board_ADDR[14]={Driving_Board_1_CTRL_ADDR,Driving_Board_2_CTRL_ADDR,Driving_Board_3_CTRL_ADDR,Driving_Board_4_CTRL_ADDR,Driving_Board_5_CTRL_ADDR,Driving_Board_6_CTRL_ADDR,Driving_Board_7_CTRL_ADDR,Driving_Board_8_CTRL_ADDR,Driving_Board_9_CTRL_ADDR,Driving_Board_10_CTRL_ADDR,Driving_Board_11_CTRL_ADDR,Driving_Board_12_CTRL_ADDR,Driving_Board_13_CTRL_ADDR,Driving_Board_14_CTRL_ADDR};
#if 1
    for(i=0;i<1;i++)
    {
        for(j=0;j<7;j++)
        {
            LCW_8Channel(Driving_Board_ADDR[i],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j],hmi_value_b[j]);
            count = 0;
            while (count != Als_Delay_ns)
           {
             count++;
           }       
        }
    }
    
/*  ==============================================================//
    LCW_8Channel(Driving_Board_ADDR[0],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6],hmi_value_b[6]);
    while (count != Als_Delay_ns)
    {
        count++;
    }    
    LCW_8Channel(Driving_Board_ADDR[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0],hmi_value_b[0]);
    count = 0;
    while (count != Als_Delay_ns)
    {
        count++;
    }
//==============================================================    */
#endif
#if 0
    for(k=0;k < 7;j++)
    {
#if 1
    memset(HMI_VALUE, LCW_ID[k], sizeof(HMI_VALUE[0][0]) * 14 * 8);
    for(j=board_star-1;j<board_stop;j++)
    {
      for(i=0;i<8;i++)
      {
        //LCW_8Channel(Driving_Board_ADDR[j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j]);
        LCW_8Channel(Driving_Board_ADDR[j],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]],hmi_value_b[HMI_VALUE[i][j]]);
      }
     }
        
    while (count != Als_Delay_ns)
    {
        count++;
    }
#else        
    memset(HMI_VALUE, LCW_ID[0], sizeof(HMI_VALUE[0][0]) * 14 * 8);
    for(j=board_star-1;j<board_stop;j++)
    {
      for(i=0;i<8;i++)
      {
        //LCW_8Channel(Driving_Board_ADDR[j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j]);
        LCW_8Channel(Driving_Board_ADDR[j],hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]));
      }
     }
        
    while (count != Als_Delay_ns)
    {
        count++;
    }
    
    memset(HMI_VALUE, LCW_ID[6], sizeof(HMI_VALUE[0][0]) * 14 * 8);
    for(j=board_star-1;j<board_stop;j++)
    {
      for(i=0;i<8;i++)
      {
        //LCW_8Channel(Driving_Board_ADDR[j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j],HMI_VALUE[i][j]);
        LCW_8Channel(Driving_Board_ADDR[j],hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]),hmi_value(HMI_VALUE[i][j]));
      }
     }
#endif    
    }
#endif    
}

char* HexToDec(int num, char *buffer)
{
//char HexToDec_buffer[5];
    size_t TXBufSize=sizeof(buffer);
/*    
        Als_read_Buf1 = (((num & 0xF000) >> 12) *16*16*16) + (((num & 0x0F00) >> 8) *16*16) + (((num & 0x00F0) >> 4) *16) + (num & 0x000F);
        buffer[0] = (char)(Als_read_Buf1/10000) + '0';
        buffer[1] = (char)((Als_read_Buf1/1000)%10) + '0';
        buffer[2] = (char)((Als_read_Buf1/100)%10) + '0';
        buffer[3] = (char)((Als_read_Buf1/10)%10) + '0';
        buffer[4] = (char)(Als_read_Buf1%10) + '0';
*/        
        buffer[0] = (char)(num/10000) + '0';
        buffer[1] = (char)((num/1000)%10) + '0';
        buffer[2] = (char)((num/100)%10) + '0';
        buffer[3] = (char)((num/10)%10) + '0';
        buffer[4] = (char)(num%10) + '0';
        //size = sizeof(buffer);
        SYS_CONSOLE_PRINT("HexToDec_buffer[0] = %x\r\n", buffer[0]);
        SYS_CONSOLE_PRINT("HexToDec_buffer[1] = %x\r\n", buffer[1]);
        SYS_CONSOLE_PRINT("HexToDec_buffer[2] = %x\r\n", buffer[2]);
        SYS_CONSOLE_PRINT("HexToDec_buffer[3] = %x\r\n", buffer[3]);
        SYS_CONSOLE_PRINT("HexToDec_buffer[4] = %x\r\n", buffer[4]);
        SYS_CONSOLE_PRINT("HexToDec_buffer[4] = %x\r\n", TXBufSize);
        //SYS_CONSOLE_PRINT("Als_read_Buf1 = %x\r\n", Als_read_Buf1);
        //SYS_CONSOLE_PRINT("Als_read_Buf1 = %d\r\n", Als_read_Buf1);
/*       
        if(((Als_read_Buf1 & 0xF000) >> 12) > 0x0009) {
        Als_read_buffer[0] = (char)((((Als_read_Buf1 & 0xF000) >> 12) - 0x0009) + 0x60);    
        }else{
        Als_read_buffer[0] = (char)(((Als_read_Buf1 & 0xF000) >> 12) + 0x30);
        }
        SYS_CONSOLE_PRINT("Als_read 1 = %x\r\n", Als_read_buffer[0]);
        if(((Als_read_Buf1 & 0x0F00) >> 8) > 0x0009) {
        Als_read_buffer[1] = (char)((((Als_read_Buf1 & 0x0F00) >> 8) - 0x0009) + 0x60);    
        }else{        
        Als_read_buffer[1] = (char)(((Als_read_Buf1 & 0x0F00) >> 8) + 0x30);
        }
        SYS_CONSOLE_PRINT("Als_read 2 = %x\r\n", Als_read_buffer[1]);
        if(((Als_read_Buf1 & 0x00F0) >> 4) > 0x0009) {
        Als_read_buffer[2] = (char)((((Als_read_Buf1 & 0x00F0) >> 4) - 0x0009) + 0x60);    
        }else{        
        Als_read_buffer[2] = (char)(((Als_read_Buf1 & 0x00F0) >> 4) + 0x30);
        }
        SYS_CONSOLE_PRINT("Als_read 3 = %x\r\n", Als_read_buffer[2]);
        if((Als_read_Buf1 & 0x000F) > 0x0009) {
        Als_read_buffer[3] = (char)(((Als_read_Buf1 & 0x000F) - 0x0009) + 0x60);    
        }else{        
        Als_read_buffer[3] = (char)((Als_read_Buf1 & 0x000F) + 0x30);
        }
        SYS_CONSOLE_PRINT("Als_read 4 = %x\r\n", Als_read_buffer[3]);
*/ 
        return buffer;
}

//void MCU_TX_HMI_EnterLCW(char *GID )       //MCU (Send UART to HMI) Enter LCW mode reback
void MCU_TX_HMI_EnterLCW(void)
{
    //size_t PreCheckWordSize=12;//11;//13;//15;         11: bco  12: picc
    size_t PreCheckWordSize=15;
    //size_t TXBufSize=GetCharlen(buffer)+PreCheckWordSize;
    //size_t TXBufSize=sizeof(GID)+PreCheckWordSize+2+3;
    size_t TXBufSize=PreCheckWordSize+3;
    //size_t TXBufSize=GetUint8_len(buffer)+PreCheckWordSize;
    uint8_t TXCMD[TXBufSize];
    SYS_CONSOLE_PRINT("TXBufSize = %d", TXBufSize);
    memset(TXCMD, 0, TXBufSize);
    //TXCMD[0]=HMI_Start_Byte;    
    //TXCMD[1]=HMI_Start_Byte;    
    //TXCMD[2]=HMI_Start_Byte;
    TXCMD[0]=(char) 'c';
    TXCMD[1]=(char) 'l';
    TXCMD[2]=(char) 'i';
    TXCMD[3]=(char) 'c';
    TXCMD[4]=(char) 'k';
    TXCMD[5]=(char) ' ';
    TXCMD[6]=(char) 'l';  
    TXCMD[7]=(char) 'e';
    TXCMD[8]=(char) 'v';
    TXCMD[9]=(char) 'e';
    TXCMD[10]=(char) 'l';
    TXCMD[11]=(char) '_';
    //TXCMD[12]=(char) GID[0];
    TXCMD[12]=(char) '0';
    TXCMD[13]=(char) ',';
    TXCMD[14]=(char) '1';     
    SYS_CONSOLE_MESSAGE("\r\n");
    for (int k = TXBufSize-3; k < TXBufSize; k++)
    {
        TXCMD[k] = HMI_End_Byte;
    }
#if 0   
    SYS_CONSOLE_PRINT("--------------------TX [ASCII]--------------------\r\n");
    for(int j=0;j<TXBufSize;j++)
    {
        SYS_CONSOLE_PRINT("0x%02x ",TXCMD[j]);
        if (((j+1) % 10 == 0) || (j == TXBufSize-1))
            SYS_CONSOLE_PRINT("\r\n");
    }
#endif    
    SERCOM0_USART_Write(TXCMD, TXBufSize);
}

 void ALS_TargetRun(void)
 {
     uint8_t i;
     int Als_subtract;
     uint16_t Als_unit;
     //uint8_t value_stepL = 0;
     char Als_read_PICC[4];
     uint8_t LCW_ID[7]={0,1,2,3,4,5,6};
     uint8_t LCW_ID_PICC[7]={1,2,3,4,5,6,7};
     uint8_t Driving_Board_ADDR[14]={Driving_Board_1_CTRL_ADDR,Driving_Board_2_CTRL_ADDR,Driving_Board_3_CTRL_ADDR,Driving_Board_4_CTRL_ADDR,Driving_Board_5_CTRL_ADDR,Driving_Board_6_CTRL_ADDR,Driving_Board_7_CTRL_ADDR,Driving_Board_8_CTRL_ADDR,Driving_Board_9_CTRL_ADDR,Driving_Board_10_CTRL_ADDR,Driving_Board_11_CTRL_ADDR,Driving_Board_12_CTRL_ADDR,Driving_Board_13_CTRL_ADDR,Driving_Board_14_CTRL_ADDR};
     Als_read = ALS_Read(ALS_1_CTRL_ADDR);
     HexToDec(Als_read, Als_read_PICC);
     MCU_TX_HMI(Als_read_PICC);
     Als_subtract = abs(Als_read - EEData.Als_target);
     SYS_CONSOLE_PRINT("Als_subtract = 0x%02x ",Als_subtract);
     Als_unit = (EEData.Als_target/10)*2;   //20%
    
     
    if(Als_read < EEData.Als_target)
    {
        if(Als_subtract > Als_unit)
        {
            if(value_stepL < 6)
            {
               value_stepL++;
            }else{
               value_stepL = 6;
            }            
        }
    }else if(Als_read > EEData.Als_target)
    {
        if(Als_subtract > Als_unit)
        {
            if(value_stepL > 0)
            {         
               value_stepL--;
            }else{
               value_stepL = 0;
            }           
        }  
    }else{
        value_stepL = value_stepL;
    }
#if 0    
     if(Als_subtract < -Als_unit)
     {
         if(value_step < 6)
         {
            value_step++;
         }else{
            value_step = 6;
         }
     }else if(Als_subtract > Als_unit)    
     {
         if(value_step > 0)
         {         
            value_step--;
         }else{
            value_step = 0;
         }
     }else{
        value_step = value_step;
     }
#endif     
     MCU_TX_HMI_PICC(LCW_ID_PICC[value_stepL]);
     for(i=0;i<EEData.drbo_NUM;i++)   //14
     {         
     LCW_8Channel(Driving_Board_ADDR[i],hmi_value_b[LCW_ID[value_stepL]],hmi_value_b[LCW_ID[value_stepL]],hmi_value_b[LCW_ID[value_stepL]],hmi_value_b[LCW_ID[value_stepL]],hmi_value_b[LCW_ID[value_stepL]],hmi_value_b[LCW_ID[value_stepL]],hmi_value_b[LCW_ID[value_stepL]],hmi_value_b[LCW_ID[value_stepL]]);  
     //Als_pre = Als_subtract;
     }
  
  //GPIO_PC23_Set();
 }
 
  void ALS_ReadRun(void)
 {
    Als_read = ALS_Read(ALS_1_CTRL_ADDR);
    HexToDec(Als_read, Als_read_Buf);
    MCU_TX_HMI(Als_read_Buf);
  }
/* *****************************************************************************
 End of File
 */
