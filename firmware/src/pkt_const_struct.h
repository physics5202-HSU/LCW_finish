/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Innolux

  @File Name
    pkt_const_struct.h

  @Summary
    Constants and structures for pkt_utils.h .c

  @Description
    Constants and structures for pkt_utils.h .c
 */
/* ************************************************************************** */

#ifndef _PKT_CONST_STRUCT_H    /* Guard against multiple inclusion */
#define _PKT_CONST_STRUCT_H


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

// Command key words
#define CMD_KEY_INFO    "INFO"
#define CMD_KEY_PWR     "PWD"   // YES! It's PWD but not PWR.
#define CMD_KEY_MUT     "MUT"
#define CMD_KEY_VOL     "VOL"
#define CMD_KEY_INP     "INP"
    
// Command value for power, mute
#define COMMAND_OFF 0
#define COMMAND_ON 1
#define COMMAND_TOGGLE 3
    
// Command value for volume
#define VOL_UP      "+"
#define VOL_DOWN    "-"
#define VOL_MIN     0
#define VOL_MAX     100

// Source input types
#define INP_HDMI1 1
#define INP_HDMI2 2
#define INP_HDMI3 3
#define INP_COMPONET 4
#define INP_AV_COMPOSITE 5
#define INP_USB_MEDIA 7
    
// Constants for SDDP message
#define SDDP_HOST       "Microchip"
#define SDDP_MAX_AGE    1800
#define SDDP_TYPE       "mc:PIC32"
#define SDDP_PRI_PROXY  "TV"
#define SDDP_PROXIES    "TV"
#define SDDP_MANUFACTURER   "Microchip"
#define SDDP_MODEL      "PIC32"
#define SDDP_DRIVER     "microchip_pic32.c4z"
    
// Constants for IP Control result
#define IP_CTRL_RESULT_FAIL_B       false
#define IP_CTRL_RESULT_SUCCESS_B    true
#define IP_CTRL_RESULT_SUCCESS  "SUCCESS"
#define IP_CTRL_RESULT_FAIL     "FAIL"

// Constants for IP Control info
#define IP_CTRL_INFO_FIRMWARE   "pic32 firmware"
#define IP_CTRL_INFO_MODEL      "PIC32MZ2048EF144"
#define IP_CTRL_INFO_SERIAL     "serial"
    
// Constants for IP Control state
#define IP_CTRL_STATE_UNMUTE    0
#define IP_CTRL_STATE_MUTE      1
#define IP_CTRL_STATE_PWR_OFF   0
#define IP_CTRL_STATE_PWR_ON    1

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** IP_COMMAND_TYPE

      @Summary
        Command tpyes of IP Control.
    
      @Description
        Used to indicated which command is received after parsing command.

      @Remarks
        CANNOT_BE_PARSE is assigned when the JSON format is invalid, 
        or "command" key is not found.
        <p>
        IP_CMD_INVALID is assigned when the value in "command" is invalid 
        (wrong value or type error).
        <p>
        IP_CMD_INFO is assigned when "INFO" command is received.
        <p>
        IP_CMD_POWER is assigned when "PWD" command is received.
        <p>
        IP_CMD_MUTE is assigned when "MUT" command is received.
        <p>
        IP_CMD_VLIMUE is assigned when "VOL" command is received.
        <p>
        IP_CMD_INPUT is assigned when "INP" command is received.
     */
    typedef enum {
        CANNOT_BE_PARSE, IP_CMD_INVALID, IP_CMD_INFO, IP_CMD_POWER, IP_CMD_MUTE, IP_CMD_VOLUME, IP_CMD_INPUT
    } IP_COMMAND_TYPE;
    
    /** IPCommand

      @Summary
        Structure of IP Command with neccesary variables.
    
      @Description
        The return value of function parseCommand(), which include the command tpye 
        and the command value (such like ON/OFF/TOGGLE).
        <p>
        It's useful to understand and access which command is submit.
    
      @Remark
        type indicates what kind of command is sent, and is represented as 
        enum IP_COMMAND_TYPE above.
        <p>
        use_i is set to true if int16_i in union Param is been used.
        There is the only two situations that use_i is set to false, 
        which are VOL:+ and VOL"-. Thus most of the time use_i is set to true.
     
     */
    typedef struct {
        IP_COMMAND_TYPE type;
        bool use_i;  // Use this variable to check which Param is been used.
        union {
            char parameter_c;
            int16_t parameter_i;
        } Param;
    }IPCommand;


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _PKT_CONST_STRUCT_H */

/* *****************************************************************************
 End of File
 */
