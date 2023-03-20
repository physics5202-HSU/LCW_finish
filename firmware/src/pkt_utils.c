/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Innolux

  @File Name
    pkt_utils.c

  @Summary
 *  Utilities for SDDP message creation or IP Control related message parsing/creation.

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
#include <limits.h>
#include "pkt_utils.h"
#include "tcpip/berkeley_api.h"
#include "cJSON.h"

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


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    char * i_to_readable(uint32_t ipVal)

  @Summary
    Turn the uint32 to readable string of IP address.

  @Description
    Turn the ip address which is represented in unsigned integer to readable 
    string like 10.43.100.5.
    <p>
    

  @Parameters
    @ipVal The IP address represented in 32-bits unsigned integer.

  @Returns
    A char pointer which points to the string of IP address.

  @Remark
    IMPORTANT: The return value must be freed.
 */

char * i_to_readable(uint32_t ipVal)
{
    uint8_t BUFFER_SIZE = 16;   // Count from max ip string "xxx.xxx.xxx.xxx\0" = 16 chars
    char * addr = malloc(BUFFER_SIZE);
    snprintf(addr, BUFFER_SIZE, "%d.%d.%d.%d",
            (int) ipVal & 0xFF, 
            (int) ((ipVal >> 8) & 0xFF), 
            (int) ((ipVal >> 16) & 0xFF),
            (int) ((ipVal >> 24) & 0xFF));
    return addr;
}


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/******************************************************************************
  @Function
    char * sddp_search_response_msg(uint32_t addr, uint16_t port)

  @Summary
    Creation for SDDP search response message.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 ***************************************************************************/
char * sddp_search_response_msg(uint32_t addr, uint16_t port) {
    char * ipAddr = i_to_readable(addr);
    
    uint8_t STR_BUFFER_SIZE = 255;
    char *res = malloc(STR_BUFFER_SIZE);
    snprintf(res, STR_BUFFER_SIZE, "SDDP/1.0 200 OK\r\n"
            "From: \"%s:%d\"\r\n"
            "Host: \"%s\"\r\n"
            "Max-Age: %d\r\n"
            "Type: \"%s\"\r\n"
            "Primary-Proxy: \"%s\"\r\n"
            "Proxies: \"%s\"\r\n"
            "Manufacturer: \"%s\"\r\n"
            "Model: \"%s\"\r\n"
            "Driver: \"%s\"\r\n",
            ipAddr, port, SDDP_HOST, SDDP_MAX_AGE, SDDP_TYPE, SDDP_PRI_PROXY, SDDP_PROXIES, 
            SDDP_MANUFACTURER, SDDP_MODEL, SDDP_DRIVER);
    free(ipAddr);
    
    return res;
}

/******************************************************************************
  @Function
    char * sddp_notify_alive_msg(uint32_t addr, uint16_t port)

  @Summary
    Creation for SDDP NOTIFY ALIVE message.

  @Remarks
    Refer to the pkt_utils.h interface header for function usage details.
 ***************************************************************************/
char * sddp_notify_alive_msg(uint32_t addr, uint16_t port) {
    char * ipAddr = i_to_readable(addr);
    
    uint8_t STR_BUFFER_SIZE = 255;
    char *res = malloc(STR_BUFFER_SIZE);
    snprintf(res, STR_BUFFER_SIZE, "NOTIFY ALIVE SDDP/1.0\r\n"
            "From: \"%s:%d\"\r\n"
            "Host: \"%s\"\r\n"
            "Max-Age: %d\r\n"
            "Type: \"%s\"\r\n"
            "Primary-Proxy: \"%s\"\r\n"
            "Proxies: \"%s\"\r\n"
            "Manufacturer: \"%s\"\r\n"
            "Model: \"%s\"\r\n"
            "Driver: \"%s\"\r\n",
            ipAddr, port, SDDP_HOST, SDDP_MAX_AGE, SDDP_TYPE, SDDP_PRI_PROXY, SDDP_PROXIES, 
            SDDP_MANUFACTURER, SDDP_MODEL, SDDP_DRIVER);
    free(ipAddr);
    
    return res;
}

/******************************************************************************
  @Function
    char * get_request_body(char * requestMsg)

  @Summary
    HTTP request seperator for seperating request body.

  @Remarks
    Refer to the pkt_utils.h interface header for function usage details.
 ***************************************************************************/
char * get_request_body(char * requestMsg) {
    char *token = strstr(requestMsg, "\r\n\r\n");
    while (NULL != token) {
        token += 4; // Shift 4 bytes (\r\n\r\n)

        if (*token == '{') {
            return token;
        } else {
            token = strstr(token, "\r\n\r\n");
        }
    }
    return NULL;
}

/******************************************************************************
  @Function
    IPCommand parseCommand(char *reqBody)

  @Summary
    The function to parse command in order to know which command is submitted.

  @Remarks
    Refer to the pkt_utils.h interface header for function usage details.
 ***************************************************************************/
IPCommand parseCommand(char *reqBody) {
    
    // Initial for return value
    IPCommand cmd;
    cmd.type = IP_CMD_INVALID;
    cmd.use_i = true;
    
    cJSON *body_json = cJSON_Parse(reqBody);
    if (body_json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
//            SYS_CONSOLE_PRINT("%s\r\n", error_ptr);   // TODO print error msg
        }
        cmd.type = CANNOT_BE_PARSE;
        goto end;
    }
    
    cJSON *command_json = cJSON_GetObjectItemCaseSensitive(body_json, "command");
    if (!cJSON_IsString(command_json) ||  command_json->valuestring == NULL) {
        // TODO print error msg
        cmd.type = CANNOT_BE_PARSE;
        goto end;
    }
    
    // Get cmd type
    char *cmdType = strtok(command_json->valuestring, ":");
    if (strcmp(cmdType, CMD_KEY_INFO) == 0) {
        
        cmd.type = IP_CMD_INFO;
    } else if (strcmp(cmdType, CMD_KEY_INP) == 0) {
        
        int tmpVal = atoi(strtok(NULL, ":"));
        if (tmpVal == INP_HDMI1 || tmpVal == INP_HDMI2 || tmpVal == INP_HDMI3 ||
                tmpVal == INP_COMPONET || tmpVal == INP_AV_COMPOSITE || tmpVal == INP_USB_MEDIA) {
            cmd.type = IP_CMD_INPUT;
            cmd.Param.parameter_i = tmpVal;
        }
    } else if (strcmp(cmdType, CMD_KEY_VOL) == 0) {
        
        char *tmpVal = strtok(NULL, ":");
        if (strcmp(tmpVal, VOL_UP) == 0 || strcmp(tmpVal, VOL_DOWN) == 0) {
            cmd.type = IP_CMD_VOLUME;
            cmd.Param.parameter_c = *tmpVal;
            cmd.use_i = false;
        } else {
            long tmpl;
            char *end_ptr;
            
            tmpl = strtol(tmpVal, &end_ptr, 10);  // Convert string to number
            if (end_ptr == tmpVal)  // The value can't be converted to number
                goto end;
            
            // Check if the value of vloume is valid, adjust it if not.
            if (tmpl < VOL_MIN) {
                cmd.Param.parameter_i = 0;
            } else if (tmpl > VOL_MAX) {
                cmd.Param.parameter_i = 100;
            } else {
                cmd.Param.parameter_i = (int) tmpl;
            }
            cmd.type = IP_CMD_VOLUME;
        }
    } else if (strcmp(cmdType, CMD_KEY_PWR) == 0) {

        int tmpVal = atoi(strtok(NULL, ":"));
        if (tmpVal == COMMAND_OFF || tmpVal == COMMAND_ON || tmpVal == COMMAND_TOGGLE) {
            cmd.type = IP_CMD_POWER;
            cmd.Param.parameter_i = tmpVal;
        }
    } else if (strcmp(cmdType, CMD_KEY_MUT) == 0) {
        
        int tmpVal = atoi(strtok(NULL, ":"));
        if (tmpVal == COMMAND_OFF || tmpVal == COMMAND_ON || tmpVal == COMMAND_TOGGLE) {
            cmd.type = IP_CMD_MUTE;
            cmd.Param.parameter_i = tmpVal;
        }
    }
    
    end:
    cJSON_Delete(body_json);
    return cmd;
}
/******************************************************************************
  @Function
    char * ip_ctrl_response_header(uint16_t content_len)

  @Summary
    Create the reponse header of IP Control.

  @Remarks
    Refer to the pkt_utils.h interface header for function usage details.
 ***************************************************************************/
char * ip_ctrl_response_header(uint16_t content_len) {
    const uint8_t MAX_HEADER_BUFFER_SIZE = 127;
    
    char * header = malloc(MAX_HEADER_BUFFER_SIZE);
    snprintf(header, MAX_HEADER_BUFFER_SIZE, "HTTP/1.1 200 OK\r\n"
            "Content-length: %d\r\n"
            "Content-Type: application/json;charset=utf-8\r\n"
            "Connection: close\r\n\r\n",
            content_len);
    return header;
}

/******************************************************************************
  @Function
    char * ip_ctrl_response_body(bool cmd_result, uint8_t stat_input, uint8_t stat_mute, 
        uint8_t stat_power, uint8_t stat_volume, char *stat_channel)

  @Summary
    Create the reponse body of IP Control.

  @Remarks
    Refer to the pkt_utils.h interface header for function usage details.
 ***************************************************************************/
char * ip_ctrl_response_body(bool cmd_result, uint8_t stat_input, uint8_t stat_mute, 
        uint8_t stat_power, uint8_t stat_volume, char *stat_channel) {

    cJSON *response = cJSON_CreateObject();
    
    // "result":SUCCESS,
    cJSON *result = cJSON_CreateString(cmd_result ? IP_CTRL_RESULT_SUCCESS : IP_CTRL_RESULT_FAIL);
    cJSON_AddItemToObject(response, "result", result);
    
    /*  "info": {
     *      "firmware": IP_CTRL_INFO_FIRMWARE,
     *      "model": IP_CTRL_INFO_MODEL,
     *      "serial": "",
     *      "runtime": "1 Day 40 Hour 10 Min"
     * },
     */
    cJSON *info = cJSON_CreateObject();
    cJSON_AddItemToObject(response, "info", info);
    
    cJSON *firmware = cJSON_CreateString(IP_CTRL_INFO_FIRMWARE);
    cJSON_AddItemToObject(info, "firmware", firmware);
    
    cJSON *model = cJSON_CreateString(IP_CTRL_INFO_MODEL);
    cJSON_AddItemToObject(info, "model", model);
    
    cJSON *serial = cJSON_CreateString(IP_CTRL_INFO_SERIAL);
    cJSON_AddItemToObject(info, "serial", serial);
    
    cJSON *runtime = cJSON_CreateString("10 Min");
    cJSON_AddItemToObject(info, "runtime", runtime);
    
    /*  "state": {
     *      "input": 1,
     *      "mute":  0,
     *      "power": 1,
     *      "volume": 0,
     *      "channel": "0"
     *  } 
     */
    cJSON *state = cJSON_CreateObject();
    cJSON_AddItemToObject(response, "state", state);
    
    cJSON *input = cJSON_CreateNumber(stat_input);
    cJSON_AddItemToObject(state, "input", input);
    
    cJSON *mute = cJSON_CreateNumber(stat_mute);
    cJSON_AddItemToObject(state, "mute", mute);
    
    cJSON *power = cJSON_CreateNumber(stat_power);
    cJSON_AddItemToObject(state, "power", power);
    
    cJSON *volume = cJSON_CreateNumber(stat_volume);
    cJSON_AddItemToObject(state, "volume", volume);
    
    cJSON *channel = cJSON_CreateString(stat_channel);
    cJSON_AddItemToObject(state, "channel", channel);
    
    // Create string and release memory
    char * resBody = cJSON_Print(response);
    cJSON_Delete(response);
    
    return resBody;
}

/* *****************************************************************************
 End of File
 */
