/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Innolux

  @File Name
    pkt_utils.h

  @Summary
    Utilities for SDDP message creation or IP Control related message parsing / creation.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _PKT_UTILS_H    /* Guard against multiple inclusion */
#define _PKT_UTILS_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include "pkt_const_struct.h"


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    /**************************************************************************
      @Function
        char * sddp_search_response_msg(uint32_t ipVal, uint16_t port)

      @Summary
        Creation for SDDP search response message.

      @Description
        This is the function for creating SDDP search response message.
        While listening on UDP port 1902, if a SDDP SEARCH message is passed in,
        then MCU response a SEARCH RESPONSE message.

      @Parameters
        @ipVal The ip that is represented in 32-bits unsigned integer.
    
        @port The port that SEARCH RESPONSE sent to. It should be 1902 which is defined in SDDP standard.

      @Returns
        A char pointer which points to the string of SDDP SEARCH RESPONSE header.
      
      @Remark
        IMPORTANT: The return value must be freed.

     ***************************************************************************/
    char * sddp_search_response_msg(uint32_t ipVal, uint16_t port);
    
    
    /**************************************************************************
      @Function
        char * sddp_notify_alive_msg(uint32_t addr, uint16_t port)

      @Summary
        Creation for SDDP NOTIFY ALIVE message.

      @Description
        The SDDP NOTIFY ALIVE message must be sent periodically.
        This functon helps to create the header of SDDP NOTIFY ALIVE.

      @Parameters
        @ipVal The ip that is represented in 32-bits unsigned integer.
    
        @port The port that SEARCH RESPONSE sent to. It should be 1902 which is defined in SDDP standard.

      @Returns
        A char pointer which points to the string of SDDP NOTIFY ALIVE header.

      @Remarks
        IMPORTANT: The return value must be freed.

     ***************************************************************************/
    char * sddp_notify_alive_msg(uint32_t addr, uint16_t port);
    
    
    /**************************************************************************
      @Function
        char * get_request_body(char * requestMsg)

      @Summary
        HTTP request seperator for seperating request body.

      @Description
        When a TCP request is received, we don't know if it is a HTTP request with valid payload.
        Thus we can use this funtion to properly sperate HTTP header and body by '\r\n\r\n'.
        Then MCU can parse the content in the body.  

      @Parameters
        @requestMsg The whole received message from specific socket.

      @Returns
        Return a char pointer which points to the HTTP request body.
    
        If the received message is not a HTTP request or didn't contain a payload,
        then NULL will be return.
    
      @Remark
        IMPORTANT: The return value must be freed.
     
     ***************************************************************************/
    char * get_request_body(char * requestMsg);

    
    /**************************************************************************
      @Function
        IPCommand parseCommand(char *reqBody)

      @Summary
        The function to parse command in order to know which command is submitted.

      @Description
        This function can be used to understand which command is submitted by HTTP request.
        After the HTTP request(IP control) is sent and the request body is properly
        seperated, the requst body is passed into this function to know which command
        is submitted.
        Due to the IP control is represented in JSON format. We use cJSON.h .c to
        parse the JSON content.
        For more info about cJSON, please check https://github.com/DaveGamble/cJSON .

      @Parameters
        @reqBody The HTTP request body of IP Control.

      @Returns
        Return IPCommand which indicates what kind command is sent and the value 
        of command (such like ON/OFF/TOGGLE).
        <p>
        Return IPCommand with type "CANNOT_BE_PARSE" if the JSON format is invalid,
        or "command" column is wrong/typo error
        <p>
        Return IPCommand with type "IP_CMD_INVALID" if the string inside "command" 
        value has invalid command type or value.
    
     ***************************************************************************/
    IPCommand parseCommand(char *reqBody);

    
    /**************************************************************************
      @Function
        char * ip_ctrl_response_header(uint16_t content_len)

      @Summary
        Create the reponse header of IP Control.

      @Description
        In order to tell if the IP Control request is success or not.
        The reponse must be sent, which include two parts - header and body.
        This function deal with the creation of resposne header of IP Control response.

      @Parameters
        @content_len The length of reponse body.

      @Returns
        A char pointer which points to the string of response header.
    
     @Remark
        IMPORTANT: The return value must be freed.

     ***************************************************************************/
    char * ip_ctrl_response_header(uint16_t content_len);
    
    
    /**************************************************************************
      @Function
        char * ip_ctrl_response_body(bool cmd_result, uint8_t stat_input, uint8_t stat_mute, 
            uint8_t stat_power, uint8_t stat_volume, char *stat_channel)

      @Summary
        Create the reponse body of IP Control.

      @Description
        In order to tell if the IP Control request is success or not.
        The reponse must be sent, which include two parts - header and body.
        This function deal with the creation of resposne body of IP Control response.

      @Parameters
        @cmd_result If the command is process properly or not.
    
        @stat_input The input source of TV.
    
        @stat_mute If the TV is muted or unmuted.

        @stat_power If the TV is on or off.
    
        @stat_volume The volume value of TV. 
    
        @stat_channel The current channel number of TV.
    
      @Returns
        A char pointer which points to the string of response body.
    
     @Remark
        IMPORTANT: The return value must be freed.
    
     ***************************************************************************/
    char * ip_ctrl_response_body(bool cmd_result, uint8_t stat_input, uint8_t stat_mute, 
        uint8_t stat_power, uint8_t stat_volume, char *stat_channel);

    
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _PKT_UTILS_H */

/* *****************************************************************************
 End of File
 */
