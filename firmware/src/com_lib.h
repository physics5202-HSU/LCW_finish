/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _COM_LIB_H    /* Guard against multiple inclusion */
#define _COM_LIB_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <lcw.h>


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

    // Constants for SDDP message
#include "configuration.h"
#include "definitions.h"
//**********************************************************************
#define EDBG false//debug only
#define KNOB false  //ADC For GIO Project
#define LCW_Assign false
#define LCW_Button_GPIO3 false
#define LCW_UART true  //false
#define HMI_Board false  //false
#define Ethernet_Protocol false
//**********************************************************************
#define SDDP_HOST       "Microchip"
#define SDDP_MAX_AGE    1800
#define SDDP_TYPE       "mc:SAME54"
#define SDDP_PRI_PROXY  "TV"
#define SDDP_PROXIES    "TV"
#define SDDP_MANUFACTURER   "Microchip"
#define SDDP_MODEL      "SAME54"
#define SDDP_DRIVER     "microchip_same_e54.c4z"

    // Command key words
#define CMD_KEY_ALP	"ALP"
#define CMD_KEY_ALS	"ALS"
#define CMD_KEY_ALT	"ALT"
#define CMD_KEY_ALW	"ALW"
#define CMD_KEY_CHA	"CHA"
#define CMD_KEY_DCP	"DCP"
#define CMD_KEY_DIP	"DIP"
#define CMD_KEY_DNS	"DNS"
#define CMD_KEY_DT1	"DT1"
#define CMD_KEY_DT2	"DT2"
#define CMD_KEY_DT3	"DT3"
#define CMD_KEY_DT4	"DT4"
#define CMD_KEY_DT5	"DT5"
#define CMD_KEY_FAA	"FAA"
#define CMD_KEY_FAN	"FAN"
#define CMD_KEY_FAT	"FAT"
#define CMD_KEY_GAT	"GAT"
#define CMD_KEY_HET	"HET"
#define CMD_KEY_HOE	"HOE"
#define CMD_KEY_HOT	"HOT"
#define CMD_KEY_HST	"HST"
#define CMD_KEY_HTP	"HTP"
#define CMD_KEY_HTR	"HTR"
#define CMD_KEY_HTS	"HTS"
#define CMD_KEY_HTT	"HTT"
#define CMD_KEY_HTW	"HTW"
#define CMD_KEY_INF	"INF"
#define CMD_KEY_INP	"INP"
#define CMD_KEY_IPT	"IPT"
#define CMD_KEY_IRM	"IRM"
#define CMD_KEY_IRT	"IRT"
#define CMD_KEY_LIP	"LIP"
#define CMD_KEY_LTA	"LTA"
#define CMD_KEY_LTB	"LTB"
#define CMD_KEY_LTP	"LTP"
#define CMD_KEY_MAC	"MAC"
#define CMD_KEY_MOD	"MOD"
#define CMD_KEY_MSK	"MSK"
#define CMD_KEY_MUT	"MUT"
#define CMD_KEY_PSN	"PSN"
#define CMD_KEY_PWD	"PWD"   // YES! It's PWD but not PWR.
#define CMD_KEY_PWT	"PWT"
#define CMD_KEY_RCC	"RCC"
#define CMD_KEY_RDP	"RDP"
#define CMD_KEY_RDT	"RDT"
#define CMD_KEY_RDW	"RDW"
#define CMD_KEY_RES	"RES"
#define CMD_KEY_RFL	"RFL"
#define CMD_KEY_RLA	"RLA"
#define CMD_KEY_RLF	"RLF"
#define CMD_KEY_RMT	"RMT"
#define CMD_KEY_RNU	"RNU"
#define CMD_KEY_ROK	"ROK"
#define CMD_KEY_RRT	"RRT"
#define CMD_KEY_RUN	"RUN"
#define CMD_KEY_RUP	"RUP"
#define CMD_KEY_SDP	"SDP"
#define CMD_KEY_SEN	"SEN"
#define CMD_KEY_SLP	"SLP"
#define CMD_KEY_SNR	"SNR"
#define CMD_KEY_SNW	"SNW"
#define CMD_KEY_UDP	"UDP"
#define CMD_KEY_USE	"USE"
#define CMD_KEY_VER	"VER"
#define CMD_KEY_VOL	"VOL"

#define CMD_VALUE_ON_B          true
#define CMD_VALUE_OFF_B         false
#define CMD_VALUE_ON_I          1
#define CMD_VALUE_OFF_I         0
#define CMD_VALUE_TOGGLE_I      3
#define CMD_VALUE_QUERY_C       "?"
#define CMD_VALUE_VOL_UP_C      "+"
#define CMD_VALUE_VOL_DOWN_C    "-"
#define CMD_VALUE_OK            "OK"

    // Source input types
#define INP_HDMI1 1
#define INP_HDMI2 2
#define INP_HDMI3 3
#define INP_COMPONET 4
#define INP_AV_COMPOSITE 5
#define INP_USB_MEDIA 7
    
#define HMI_Start_Byte 0x25
#define HMI_End_Byte 0xFF
    

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */
    typedef enum {
        MSG_TYPE_REQUEST, MSG_TYPE_RESPONSE, MSG_TYPE_INVALID
    } MSG_TYPE;

    typedef enum {
        VAL_TYPE_INVALID,
        VAL_TYPE_STR,
        VAL_TYPE_CHAR,
        VAL_TYPE_NUM,
        VAL_TYPE_IP_ADDR,
        VAL_TYPE_MAC_ADDR,
        VAL_TYPE_CHANNEL
    } VAL_TYPE;

    typedef enum {
        CANNOT_BE_PARSE = 0,
        CMD_TYPE_INVALID,

        CMD_TYPE_ALP,
        CMD_TYPE_ALS,
        CMD_TYPE_ALT,
        CMD_TYPE_ALW = 5,

        CMD_TYPE_CHA,

        CMD_TYPE_DCP,
        CMD_TYPE_DIP,
        CMD_TYPE_DNS,
        CMD_TYPE_DT1 = 10,
        CMD_TYPE_DT2,
        CMD_TYPE_DT3,
        CMD_TYPE_DT4,
        CMD_TYPE_DT5,

        CMD_TYPE_FAA = 15,
        CMD_TYPE_FAN,
        CMD_TYPE_FAT,

        CMD_TYPE_GAT,

        CMD_TYPE_HET,
        CMD_TYPE_HOE = 20,
        CMD_TYPE_HOT,
        CMD_TYPE_HST,
        CMD_TYPE_HTP,
        CMD_TYPE_HTR,
        CMD_TYPE_HTS = 25,
        CMD_TYPE_HTT,
        CMD_TYPE_HTW,

        CMD_TYPE_INF,
        CMD_TYPE_INP,
        CMD_TYPE_IPT = 30,
        CMD_TYPE_IRM,
        CMD_TYPE_IRT,

        CMD_TYPE_LIP,
        CMD_TYPE_LTA,
        CMD_TYPE_LTB = 35,
        CMD_TYPE_LTP,

        CMD_TYPE_MAC,
        CMD_TYPE_MOD,
        CMD_TYPE_MSK,
        CMD_TYPE_MUT = 40,

        CMD_TYPE_PSN,
        CMD_TYPE_PWD,
        CMD_TYPE_PWT,

        CMD_TYPE_RCC,
        CMD_TYPE_RDP = 45,
        CMD_TYPE_RDT,
        CMD_TYPE_RDW,
        CMD_TYPE_RES,
        CMD_TYPE_RFL,
        CMD_TYPE_RLA = 50,
        CMD_TYPE_RLF,
        CMD_TYPE_RMT,
        CMD_TYPE_RNU,
        CMD_TYPE_ROK,
        CMD_TYPE_RRT = 55,
        CMD_TYPE_RUN,
        CMD_TYPE_RUP,

        CMD_TYPE_SDP,
        CMD_TYPE_SEN,
        CMD_TYPE_SLP = 60,
        CMD_TYPE_SNR,
        CMD_TYPE_SNW,

        CMD_TYPE_UDP,
        CMD_TYPE_USE,

        CMD_TYPE_VER = 65,
        CMD_TYPE_VOL,
        //-----------add HMI Command by Rafael
        CMD_HMI_Mode_Show,      //[demo]
        CMD_HMI_Mode_ALS,       //[als]
        CMD_HMI_Mode_Manual,    //[lcw]
        CMD_HMI_RX_Error= 70,   //MCU Send Error message to HMI Board via TX
        CMD_L_Pannel_100,
        CMD_L_Pannel_80,
        CMD_L_Pannel_60,  
        CMD_L_Pannel_40,
        CMD_L_Pannel_20= 75, 
        CMD_L_Pannel_0,
        CMD_R_Pannel_100, 
        CMD_R_Pannel_80, 
        CMD_R_Pannel_60, 
        CMD_R_Pannel_40 =80,
        CMD_R_Pannel_20,
        CMD_R_Pannel_0,        
        CMD_ESP32_B,        //[todo] ESP32 temporary
        CMD_ESP32_C,        //[todo] ESP32 temporary
        CMD_ESP32_D=85,     //[todo] ESP32 temporary
        CMD_ESP32_E,        //[todo] ESP32 temporary
        CMD_ESP32_F,        //[todo] ESP32 temporary
        CMD_ESP32_G,        //[todo] ESP32 temporary
        CMD_ESP32_H,        //[todo] ESP32 temporary
        CMD_ESP32_I=90,     //[todo] ESP32 temporary
        CMD_ESP32_J,        //[todo] ESP32 temporary
        CMD_ESP32_K,        //[todo] ESP32 temporary
        CMD_ESP32_L,        //[todo] ESP32 temporary
        CMD_ESP32_M,        //[todo] ESP32 temporary
        CMD_ESP32_N=95,     //[todo] ESP32 temporary
        CMD_ESP32_O,        //[todo] ESP32 temporary
        CMD_ESP32_RX_ALS,        //[todo] Send als data to ESP32 via UART
        CMD_HMI_Mode_Reset,
        CMD_LCW_Show,
        CMD_LCW_ShowAll       
    } CMD_TYPE;
    typedef enum{
        L_0,
        L_10,
        L_20,
        L_40,
        L_60,
        L_80,
        L_100
    }HMI_Pannel_L;

    typedef enum{
        R_0,
        R_10,
        R_20,
        R_40,
        R_60,
        R_80,
        R_100,
    }HMI_Pannel_R;
    
    typedef enum{D1C1V0,D1C1V1,D1C1V2,D1C1V3,D1C1V4,D1C1V5,D1C1V6}D1C1;
    typedef enum{D1C2V0,D1C2V1,D1C2V2,D1C2V3,D1C2V4,D1C2V5,D1C2V6}D1C2;
    typedef enum{D1C3V0,D1C3V1,D1C3V2,D1C3V3,D1C3V4,D1C3V5,D1C3V6}D1C3;
    typedef enum{D1C4V0,D1C4V1,D1C4V2,D1C4V3,D1C4V4,D1C4V5,D1C4V6}D1C4;
    typedef enum{D1C5V0,D1C5V1,D1C5V2,D1C5V3,D1C5V4,D1C5V5,D1C5V6}D1C5;
    typedef enum{D1C6V0,D1C6V1,D1C6V2,D1C6V3,D1C6V4,D1C6V5,D1C6V6}D1C6;
    typedef enum{D1C7V0,D1C7V1,D1C7V2,D1C7V3,D1C7V4,D1C7V5,D1C7V6}D1C7;
    typedef enum{D1C8V0,D1C8V1,D1C8V2,D1C8V3,D1C8V4,D1C8V5,D1C8V6}D1C8;
    typedef enum{D2C1V0,D2C1V1,D2C1V2,D2C1V3,D2C1V4,D2C1V5,D2C1V6}D2C1;
    typedef enum{D2C2V0,D2C2V1,D2C2V2,D2C2V3,D2C2V4,D2C2V5,D2C2V6}D2C2;
    typedef enum{D2C3V0,D2C3V1,D2C3V2,D2C3V3,D2C3V4,D2C3V5,D2C3V6}D2C3;
    typedef enum{D2C4V0,D2C4V1,D2C4V2,D2C4V3,D2C4V4,D2C4V5,D2C4V6}D2C4;
    typedef enum{D2C5V0,D2C5V1,D2C5V2,D2C5V3,D2C5V4,D2C5V5,D2C5V6}D2C5;
    typedef enum{D2C6V0,D2C6V1,D2C6V2,D2C6V3,D2C6V4,D2C6V5,D2C6V6}D2C6;
    typedef enum{D2C7V0,D2C7V1,D2C7V2,D2C7V3,D2C7V4,D2C7V5,D2C7V6}D2C7;
    typedef enum{D2C8V0,D2C8V1,D2C8V2,D2C8V3,D2C8V4,D2C8V5,D2C8V6}D2C8;
    typedef enum{D3C1V0,D3C1V1,D3C1V2,D3C1V3,D3C1V4,D3C1V5,D3C1V6}D3C1;
    typedef enum{D3C2V0,D3C2V1,D3C2V2,D3C2V3,D3C2V4,D3C2V5,D3C2V6}D3C2;
    typedef enum{D3C3V0,D3C3V1,D3C3V2,D3C3V3,D3C3V4,D3C3V5,D3C3V6}D3C3;
    typedef enum{D3C4V0,D3C4V1,D3C4V2,D3C4V3,D3C4V4,D3C4V5,D3C4V6}D3C4;
    typedef enum{D3C5V0,D3C5V1,D3C5V2,D3C5V3,D3C5V4,D3C5V5,D3C5V6}D3C5;
    typedef enum{D3C6V0,D3C6V1,D3C6V2,D3C6V3,D3C6V4,D3C6V5,D3C6V6}D3C6;
    typedef enum{D3C7V0,D3C7V1,D3C7V2,D3C7V3,D3C7V4,D3C7V5,D3C7V6}D3C7;
    typedef enum{D3C8V0,D3C8V1,D3C8V2,D3C8V3,D3C8V4,D3C8V5,D3C8V6}D3C8;
    typedef enum{D4C1V0,D4C1V1,D4C1V2,D4C1V3,D4C1V4,D4C1V5,D4C1V6}D4C1;
    typedef enum{D4C2V0,D4C2V1,D4C2V2,D4C2V3,D4C2V4,D4C2V5,D4C2V6}D4C2;
    typedef enum{D4C3V0,D4C3V1,D4C3V2,D4C3V3,D4C3V4,D4C3V5,D4C3V6}D4C3;
    typedef enum{D4C4V0,D4C4V1,D4C4V2,D4C4V3,D4C4V4,D4C4V5,D4C4V6}D4C4;
    typedef enum{D4C5V0,D4C5V1,D4C5V2,D4C5V3,D4C5V4,D4C5V5,D4C5V6}D4C5;
    typedef enum{D4C6V0,D4C6V1,D4C6V2,D4C6V3,D4C6V4,D4C6V5,D4C6V6}D4C6;
    typedef enum{D4C7V0,D4C7V1,D4C7V2,D4C7V3,D4C7V4,D4C7V5,D4C7V6}D4C7;
    typedef enum{D4C8V0,D4C8V1,D4C8V2,D4C8V3,D4C8V4,D4C8V5,D4C8V6}D4C8;
    typedef enum{D5C1V0,D5C1V1,D5C1V2,D5C1V3,D5C1V4,D5C1V5,D5C1V6}D5C1;
    typedef enum{D5C2V0,D5C2V1,D5C2V2,D5C2V3,D5C2V4,D5C2V5,D5C2V6}D5C2;
    typedef enum{D5C3V0,D5C3V1,D5C3V2,D5C3V3,D5C3V4,D5C3V5,D5C3V6}D5C3;
    typedef enum{D5C4V0,D5C4V1,D5C4V2,D5C4V3,D5C4V4,D5C4V5,D5C4V6}D5C4;
    typedef enum{D5C5V0,D5C5V1,D5C5V2,D5C5V3,D5C5V4,D5C5V5,D5C5V6}D5C5;
    typedef enum{D5C6V0,D5C6V1,D5C6V2,D5C6V3,D5C6V4,D5C6V5,D5C6V6}D5C6;
    typedef enum{D5C7V0,D5C7V1,D5C7V2,D5C7V3,D5C7V4,D5C7V5,D5C7V6}D5C7;
    typedef enum{D5C8V0,D5C8V1,D5C8V2,D5C8V3,D5C8V4,D5C8V5,D5C8V6}D5C8;
    typedef enum{D6C1V0,D6C1V1,D6C1V2,D6C1V3,D6C1V4,D6C1V5,D6C1V6}D6C1;
    typedef enum{D6C2V0,D6C2V1,D6C2V2,D6C2V3,D6C2V4,D6C2V5,D6C2V6}D6C2;
    typedef enum{D6C3V0,D6C3V1,D6C3V2,D6C3V3,D6C3V4,D6C3V5,D6C3V6}D6C3;
    typedef enum{D6C4V0,D6C4V1,D6C4V2,D6C4V3,D6C4V4,D6C4V5,D6C4V6}D6C4;
    typedef enum{D6C5V0,D6C5V1,D6C5V2,D6C5V3,D6C5V4,D6C5V5,D6C5V6}D6C5;
    typedef enum{D6C6V0,D6C6V1,D6C6V2,D6C6V3,D6C6V4,D6C6V5,D6C6V6}D6C6;
    typedef enum{D6C7V0,D6C7V1,D6C7V2,D6C7V3,D6C7V4,D6C7V5,D6C7V6}D6C7;
    typedef enum{D6C8V0,D6C8V1,D6C8V2,D6C8V3,D6C8V4,D6C8V5,D6C8V6}D6C8;
    typedef enum{D7C1V0,D7C1V1,D7C1V2,D7C1V3,D7C1V4,D7C1V5,D7C1V6}D7C1;
    typedef enum{D7C2V0,D7C2V1,D7C2V2,D7C2V3,D7C2V4,D7C2V5,D7C2V6}D7C2;
    typedef enum{D7C3V0,D7C3V1,D7C3V2,D7C3V3,D7C3V4,D7C3V5,D7C3V6}D7C3;
    typedef enum{D7C4V0,D7C4V1,D7C4V2,D7C4V3,D7C4V4,D7C4V5,D7C4V6}D7C4;
    typedef enum{D7C5V0,D7C5V1,D7C5V2,D7C5V3,D7C5V4,D7C5V5,D7C5V6}D7C5;
    typedef enum{D7C6V0,D7C6V1,D7C6V2,D7C6V3,D7C6V4,D7C6V5,D7C6V6}D7C6;
    typedef enum{D7C7V0,D7C7V1,D7C7V2,D7C7V3,D7C7V4,D7C7V5,D7C7V6}D7C7;
    typedef enum{D7C8V0,D7C8V1,D7C8V2,D7C8V3,D7C8V4,D7C8V5,D7C8V6}D7C8;
    typedef enum{D8C1V0,D8C1V1,D8C1V2,D8C1V3,D8C1V4,D8C1V5,D8C1V6}D8C1;
    typedef enum{D8C2V0,D8C2V1,D8C2V2,D8C2V3,D8C2V4,D8C2V5,D8C2V6}D8C2;
    typedef enum{D8C3V0,D8C3V1,D8C3V2,D8C3V3,D8C3V4,D8C3V5,D8C3V6}D8C3;
    typedef enum{D8C4V0,D8C4V1,D8C4V2,D8C4V3,D8C4V4,D8C4V5,D8C4V6}D8C4;
    typedef enum{D8C5V0,D8C5V1,D8C5V2,D8C5V3,D8C5V4,D8C5V5,D8C5V6}D8C5;
    typedef enum{D8C6V0,D8C6V1,D8C6V2,D8C6V3,D8C6V4,D8C6V5,D8C6V6}D8C6;
    typedef enum{D8C7V0,D8C7V1,D8C7V2,D8C7V3,D8C7V4,D8C7V5,D8C7V6}D8C7;
    typedef enum{D8C8V0,D8C8V1,D8C8V2,D8C8V3,D8C8V4,D8C8V5,D8C8V6}D8C8;
    typedef enum{D9C1V0,D9C1V1,D9C1V2,D9C1V3,D9C1V4,D9C1V5,D9C1V6}D9C1;
    typedef enum{D9C2V0,D9C2V1,D9C2V2,D9C2V3,D9C2V4,D9C2V5,D9C2V6}D9C2;
    typedef enum{D9C3V0,D9C3V1,D9C3V2,D9C3V3,D9C3V4,D9C3V5,D9C3V6}D9C3;
    typedef enum{D9C4V0,D9C4V1,D9C4V2,D9C4V3,D9C4V4,D9C4V5,D9C4V6}D9C4;
    typedef enum{D9C5V0,D9C5V1,D9C5V2,D9C5V3,D9C5V4,D9C5V5,D9C5V6}D9C5;
    typedef enum{D9C6V0,D9C6V1,D9C6V2,D9C6V3,D9C6V4,D9C6V5,D9C6V6}D9C6;
    typedef enum{D9C7V0,D9C7V1,D9C7V2,D9C7V3,D9C7V4,D9C7V5,D9C7V6}D9C7;
    typedef enum{D9C8V0,D9C8V1,D9C8V2,D9C8V3,D9C8V4,D9C8V5,D9C8V6}D9C8;
    typedef enum{D10C1V0,D10C1V1,D10C1V2,D10C1V3,D10C1V4,D10C1V5,D10C1V6}D10C1;
    typedef enum{D10C2V0,D10C2V1,D10C2V2,D10C2V3,D10C2V4,D10C2V5,D10C2V6}D10C2;
    typedef enum{D10C3V0,D10C3V1,D10C3V2,D10C3V3,D10C3V4,D10C3V5,D10C3V6}D10C3;
    typedef enum{D10C4V0,D10C4V1,D10C4V2,D10C4V3,D10C4V4,D10C4V5,D10C4V6}D10C4;
    typedef enum{D10C5V0,D10C5V1,D10C5V2,D10C5V3,D10C5V4,D10C5V5,D10C5V6}D10C5;
    typedef enum{D10C6V0,D10C6V1,D10C6V2,D10C6V3,D10C6V4,D10C6V5,D10C6V6}D10C6;
    typedef enum{D10C7V0,D10C7V1,D10C7V2,D10C7V3,D10C7V4,D10C7V5,D10C7V6}D10C7;
    typedef enum{D10C8V0,D10C8V1,D10C8V2,D10C8V3,D10C8V4,D10C8V5,D10C8V6}D10C8;
    typedef enum{D11C1V0,D11C1V1,D11C1V2,D11C1V3,D11C1V4,D11C1V5,D11C1V6}D11C1;
    typedef enum{D11C2V0,D11C2V1,D11C2V2,D11C2V3,D11C2V4,D11C2V5,D11C2V6}D11C2;
    typedef enum{D11C3V0,D11C3V1,D11C3V2,D11C3V3,D11C3V4,D11C3V5,D11C3V6}D11C3;
    typedef enum{D11C4V0,D11C4V1,D11C4V2,D11C4V3,D11C4V4,D11C4V5,D11C4V6}D11C4;
    typedef enum{D11C5V0,D11C5V1,D11C5V2,D11C5V3,D11C5V4,D11C5V5,D11C5V6}D11C5;
    typedef enum{D11C6V0,D11C6V1,D11C6V2,D11C6V3,D11C6V4,D11C6V5,D11C6V6}D11C6;
    typedef enum{D11C7V0,D11C7V1,D11C7V2,D11C7V3,D11C7V4,D11C7V5,D11C7V6}D11C7;
    typedef enum{D11C8V0,D11C8V1,D11C8V2,D11C8V3,D11C8V4,D11C8V5,D11C8V6}D11C8;
    typedef enum{D12C1V0,D12C1V1,D12C1V2,D12C1V3,D12C1V4,D12C1V5,D12C1V6}D12C1;
    typedef enum{D12C2V0,D12C2V1,D12C2V2,D12C2V3,D12C2V4,D12C2V5,D12C2V6}D12C2;
    typedef enum{D12C3V0,D12C3V1,D12C3V2,D12C3V3,D12C3V4,D12C3V5,D12C3V6}D12C3;
    typedef enum{D12C4V0,D12C4V1,D12C4V2,D12C4V3,D12C4V4,D12C4V5,D12C4V6}D12C4;
    typedef enum{D12C5V0,D12C5V1,D12C5V2,D12C5V3,D12C5V4,D12C5V5,D12C5V6}D12C5;
    typedef enum{D12C6V0,D12C6V1,D12C6V2,D12C6V3,D12C6V4,D12C6V5,D12C6V6}D12C6;
    typedef enum{D12C7V0,D12C7V1,D12C7V2,D12C7V3,D12C7V4,D12C7V5,D12C7V6}D12C7;
    typedef enum{D12C8V0,D12C8V1,D12C8V2,D12C8V3,D12C8V4,D12C8V5,D12C8V6}D12C8;
    typedef enum{D13C1V0,D13C1V1,D13C1V2,D13C1V3,D13C1V4,D13C1V5,D13C1V6}D13C1;
    typedef enum{D13C2V0,D13C2V1,D13C2V2,D13C2V3,D13C2V4,D13C2V5,D13C2V6}D13C2;
    typedef enum{D13C3V0,D13C3V1,D13C3V2,D13C3V3,D13C3V4,D13C3V5,D13C3V6}D13C3;
    typedef enum{D13C4V0,D13C4V1,D13C4V2,D13C4V3,D13C4V4,D13C4V5,D13C4V6}D13C4;
    typedef enum{D13C5V0,D13C5V1,D13C5V2,D13C5V3,D13C5V4,D13C5V5,D13C5V6}D13C5;
    typedef enum{D13C6V0,D13C6V1,D13C6V2,D13C6V3,D13C6V4,D13C6V5,D13C6V6}D13C6;
    typedef enum{D13C7V0,D13C7V1,D13C7V2,D13C7V3,D13C7V4,D13C7V5,D13C7V6}D13C7;
    typedef enum{D13C8V0,D13C8V1,D13C8V2,D13C8V3,D13C8V4,D13C8V5,D13C8V6}D13C8;
    typedef enum{D14C1V0,D14C1V1,D14C1V2,D14C1V3,D14C1V4,D14C1V5,D14C1V6}D14C1;
    typedef enum{D14C2V0,D14C2V1,D14C2V2,D14C2V3,D14C2V4,D14C2V5,D14C2V6}D14C2;
    typedef enum{D14C3V0,D14C3V1,D14C3V2,D14C3V3,D14C3V4,D14C3V5,D14C3V6}D14C3;
    typedef enum{D14C4V0,D14C4V1,D14C4V2,D14C4V3,D14C4V4,D14C4V5,D14C4V6}D14C4;
    typedef enum{D14C5V0,D14C5V1,D14C5V2,D14C5V3,D14C5V4,D14C5V5,D14C5V6}D14C5;
    typedef enum{D14C6V0,D14C6V1,D14C6V2,D14C6V3,D14C6V4,D14C6V5,D14C6V6}D14C6;
    typedef enum{D14C7V0,D14C7V1,D14C7V2,D14C7V3,D14C7V4,D14C7V5,D14C7V6}D14C7;
    typedef enum{D14C8V0,D14C8V1,D14C8V2,D14C8V3,D14C8V4,D14C8V5,D14C8V6}D14C8;
    typedef enum{db1,db2,db3,db4,db5,db6,db7,db8,db9,db10,db11,db12,db13,db14}PresentDrivingBoard;



    typedef enum {
        MSG_SOURCE_RS232, MSG_SOURCE_IP, MSG_SOURCE_SOC
    } MSG_SOURCE;

    // *****************************************************************************

    /** Message

      @Summary
        Structure of Message for queue with neccesary variables.
    
      @Description
        The return value of function parseMessage(), which include the command tpye 
        and the command value (such like ON/OFF/TOGGLE).
        <p>
        It's easy to understand and access which command is submit.
    
      @Remark
        type indicates what kind of command is sent, and is represented as 
        enum CMD_TYPE above.
        <p>
        valueType is set as STR if value_s in Value is been used.
        valueType is set as CHAR if value_c in Value is been used.
        valueType is set as NUM if value_n in Value is been used.
     */
    typedef struct _message_struct {
        MSG_TYPE msgType;
        CMD_TYPE cmdType;
        VAL_TYPE valueType; // Use this variable to check which Value is been used.
        
        HMI_Pannel_R hmi_r_value;
        HMI_Pannel_L hmi_l_value;
        D1C1 _D1C1;D1C2 _D1C2;D1C3 _D1C3;D1C4 _D1C4;D1C5 _D1C5;D1C6 _D1C6;D1C7 _D1C7;D1C8 _D1C8;
        D2C1 _D2C1;D2C2 _D2C2;D2C3 _D2C3;D2C4 _D2C4;D2C5 _D2C5;D2C6 _D2C6;D2C7 _D2C7;D2C8 _D2C8;
        D3C1 _D3C1;D3C2 _D3C2;D3C3 _D3C3;D3C4 _D3C4;D3C5 _D3C5;D3C6 _D3C6;D3C7 _D3C7;D3C8 _D3C8;
        D4C1 _D4C1;D4C2 _D4C2;D4C3 _D4C3;D4C4 _D4C4;D4C5 _D4C5;D4C6 _D4C6;D4C7 _D4C7;D4C8 _D4C8;
        D5C1 _D5C1;D5C2 _D5C2;D5C3 _D5C3;D5C4 _D5C4;D5C5 _D5C5;D5C6 _D5C6;D5C7 _D5C7;D5C8 _D5C8;
        D6C1 _D6C1;D6C2 _D6C2;D6C3 _D6C3;D6C4 _D6C4;D6C5 _D6C5;D6C6 _D6C6;D6C7 _D6C7;D6C8 _D6C8;
        D7C1 _D7C1;D7C2 _D7C2;D7C3 _D7C3;D7C4 _D7C4;D7C5 _D7C5;D7C6 _D7C6;D7C7 _D7C7;D7C8 _D7C8;
        D8C1 _D8C1;D8C2 _D8C2;D8C3 _D8C3;D8C4 _D8C4;D8C5 _D8C5;D8C6 _D8C6;D8C7 _D8C7;D8C8 _D8C8;
        D9C1 _D9C1;D9C2 _D9C2;D9C3 _D9C3;D9C4 _D9C4;D9C5 _D9C5;D9C6 _D9C6;D9C7 _D9C7;D9C8 _D9C8;
        D10C1 _D10C1;D10C2 _D10C2;D10C3 _D10C3;D10C4 _D10C4;D10C5 _D10C5;D10C6 _D10C6;D10C7 _D10C7;D10C8 _D10C8;
        D11C1 _D11C1;D11C2 _D11C2;D11C3 _D11C3;D11C4 _D11C4;D11C5 _D11C5;D11C6 _D11C6;D11C7 _D11C7;D11C8 _D11C8;
        D12C1 _D12C1;D12C2 _D12C2;D12C3 _D12C3;D12C4 _D12C4;D12C5 _D12C5;D12C6 _D12C6;D12C7 _D12C7;D12C8 _D12C8;
        D13C1 _D13C1;D13C2 _D13C2;D13C3 _D13C3;D13C4 _D13C4;D13C5 _D13C5;D13C6 _D13C6;D13C7 _D13C7;D13C8 _D13C8;
        D14C1 _D14C1;D14C2 _D14C2;D14C3 _D14C3;D14C4 _D14C4;D14C5 _D14C5;D14C6 _D14C6;D14C7 _D14C7;D14C8 _D14C8;
        PresentDrivingBoard _PresentDrivingBoard;
        union {
            char * value_s;
            char value_c;
            int16_t value_n;
            uint8_t value_ip_addr[4];
            uint8_t value_mac_addr[6];
            uint8_t value_channel[2];
        } Value;
    } Message;
 
 uint8_t driv_board[14];
 uint8_t driv_board_ALS[14];
 uint8_t Als_Crlon,Als_Demo01,Als_Demo02;
 uint16_t Als_max , Als_min , Als_read , Als_count;
 //uint8_t drbo_NUM;
 uint8_t value_stepL;
    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    /***********************
     * @Function
     *  void parse_cmd_string(Message *msg, char *cmdString)
     * 
     * @Summary
     *  Parse command string and save corresponding parameter into Message
     * 
     * @Description
     *  You should pass a empty Message pointer and the rawstring into this 
     *  function.
     * 
     * @Parameters
     *  @msg Message structure pointer for saving cmd's parameters in
     * 
     *  @cmdString raw string of command
     *********************/
    void parse_cmd_string(Message * msg, char * cmdString);

    /***********************
     *  Generate by Excel
     *********************/
    uint8_t checkCmdStringFormat(Message *msg, char * cmdString);
    uint8_t isValidMessageType(char * command, char * value, Message * msg, char * cmdStringCopy);
    uint8_t isCmdCharExactThree(char * command, Message * msg);
    uint8_t analysisIP(uint8_t *addr, char* s);
    uint8_t analysisMAC(uint8_t *addr, char* s);
    uint8_t analysisChannel(uint8_t *channel, char *s);
    uint8_t analysisValString(Message *msg, char *val, uint8_t mask, int min, int max);
    uint8_t isNum(char *s);
    uint8_t checkRange(int val, int min, int max);
    uint8_t isValidCharParam(char c);
    uint8_t isAllNums(char *val);  
    void ipIntToArray(uint32_t ipInt, uint8_t *arr);
    
    /***********************
     * @Function
     *  uint8_t countDigitsOfInt(int numberToBeCount)
     * 
     * @Summary
     *  Count for digits of the numberTobeCount
     * 
     * @Parameters
     *  @numberToBeCount The target number which is be to be counted for digits.
     * 
     * @Return
     *  The number of digits
     * 
    *********************/
   uint8_t countDigitsOfInt(int numberToBeCount);

       /***********************
     * @Function
     *  bool setMacAddress(uint8_t addr[6])
     * 
     * @Summary
     *  Apply new MAC address.
     * 
     * @Description
     *  This function is used for setting the MAC address for SDDP & IP control.
     *  At the end of this function, closeAndCreateSocketOfSddp() will be call
     *  for applying new MAC to SDDP task.
     * 
     * @Parameters
     *  @addr The MAC address of new MAC address, where addr[0] is top byte.
     * 
     * @Return
     *  true    success
     *  false   fail
     *********************/
    bool setMacAddress(uint8_t addr[6]);
    
    /***********************
     * @Function
     *  void enableDHCP()
     * 
     * @Summary
     *  Enable DHCP.
     * 
     * @Description
     *  This function is used for enabling DHCP.
     * 
     *********************/
    void enableDHCP();

    /***********************
     * @Function
     *  void diableDHCP()
     * 
     * @Summary
     *  Disable DHCP.
     * 
     * @Description
     *  This function is used for disabling DHCP.
     * 
     *********************/
    void disableDHCP();

    /***********************
     * @Function
     *  bool setIPAddress(uint8_t addr[4])
     * 
     * @Summary
     *  Apply new IP address.
     * 
     * @Description
     *  This function is used for setting the IP address for SDDP & IP control.
     *  At the end of this function, closeAndCreateSocketOfSddp() will be call
     *  for applying new IP to SDDP task.
     * 
     * @Parameters
     *  @addr The IP address of new IP address, where addr[0] is top byte.
     *  For example: 192.168.0.100 -> addr[0] = 192, addr[1] = 168, addr[2] = 0, addr[3] = 100
     * 
     * @Return
     *  true    success
     *  false   fail
     *********************/
    bool setIPAddress(uint8_t addr[4]);
    
    /***********************
     * @Function
     *  bool setSubMask(uint8_t msk[4])
     * 
     * @Summary
     *  Apply new sub mask.
     * 
     * @Description
     *  This function is used for setting the network sub mask for SDDP & IP control.
     *  At the end of this function, closeAndCreateSocketOfSddp() will be call
     *  for applying new mask to SDDP task.
     * 
     * @Parameters
     *  @msk The new mask to assign
     * 
     * @Return
     *  true    success
     *  false   fail
     *********************/
    bool setSubMask(uint8_t msk[4]);

    /***********************
     * @Function
     *  bool setGateway(uint8_t addr[4])
     * 
     * @Summary
     *  Set gate way IP address
     * 
     * @Parameters
     *  @addr The IP address of gateway, where addr[0] is top byte.
     * 
     * @Description
     *  This function is used for setting the gateway's address.
     * 
     * @Return
     *  true    success
     *  false   fail
     * 
     *********************/
    bool setGateway(uint8_t addr[4]);
    
    /***********************
     * @Function
     *  bool setDnsServer(uint8_t addr[4])
     * 
     * @Summary
     *  Set new DNS server
     * 
     * @Parameters
     *  @addr The IP address of dns server, where addr[0] is top byte.
     * 
     * @Description
     *  This function is used for setting the DNS server address.
     * 
     * @Return
     *  true    success
     *  false   fail
     * 
     *********************/
    bool setDnsServer(uint8_t addr[4]);

    Message parsingCommand(uint8_t *re232RxBuffer, size_t RS232RxBufSize);
    Message parsingCommand_SERCOM0_LCW(uint8_t *RxBuffer, size_t RxBufSize);
    Message parsingCommand_SERCOM0(uint8_t *RxBuffer, size_t RxBufSize);
    void CheckHMI_Command(Message *msg, char *chkcmdString,size_t cmd_size);
    void CheckESP32_Command(Message *msg, char *chkcmdString,size_t cmd_size,bool sercom0_channel);
    size_t GetCharlen(const char *str);
    size_t GetUint8_len(const uint8_t *str);
    void MCU_TX_PAD(char *buffer);
    void MCU_TX_ESP32(bool sercom0,char *buffer);//Rafael's MCU (Send UART to ESP32)
    uint8_t CharToInt8(char *v_buffer);
    int CharToInt(char v_buffer);
    char* IntToChar(int num, char* buffer, int base);
    void HMI_RX_Error();
    void LCW_DefaultValue();
    void GPIO_PB09_High(bool v_flag);
    void MCU_TX_HMI(char *buffer);
    void MCU_TX_HMI_PICC(uint8_t GID );
    void ALS_AutoRun(void);
    void ALS_RunDemo01(void);
    void ALS_RunDemo02(void);
    char* HexToDec(int num, char *buffer);
    //void MCU_TX_HMI_EnterLCW(char *GID );
    void MCU_TX_HMI_EnterLCW(void);
    void ALS_TargetRun(void);
    void ALS_ReadRun(void);
    /**************************************************************************
      @Function
        void closeAndCreateSocketOfSddp()

      @Summary
        Close and recreate the UDP socket for SDDP protocol.

      @Description
        This function set the SDDP app task's (app.c) state machine to 
        APP_TCPIP_CLOSING_CONNECTION. Then the task will close current socket and
        step into next state APP_BSD_CREATE_SOCKET, which will create socket 
        using netH to get lasted network interface setting.
    
      @Remark
        This function should be call after the network settings are modified.

     ***************************************************************************/
    void closeAndCreateSocketOfSddp();



    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _COM_LIB_H */

/* *****************************************************************************
 End of File
 */
