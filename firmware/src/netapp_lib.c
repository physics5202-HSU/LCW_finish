/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    netapp_lib.c

  @Summary
    This library is all about functionalities in app.c (SDDP) and tcp_app.c (IPctrl).

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

/* TODO:  Include other files here if needed. */
#include <stdio.h>
#include <string.h>
#include "cJSON.h"
#include "com_lib.h"
#include "uart_command.h"
#include "Judgeman.h"
#include "eeprom.h"
#include "shared_settings.h"
#include "netapp_lib.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */


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
 * 
 * @Function
 * char * i_to_readable(uint32_t ipVal)
 *
 * @Summary
 *  Turn the uint32 to readable string of IP address.
 * 
 * @Description
 *  Turn the ip address which is represented in unsigned integer to readable 
 *  string like 10.43.100.5.
 * <p>
 * 
 * @Parameters
 *  @ipVal The IP address represented in 32-bits unsigned integer.
 * 
 * @Returns
 * A char pointer which points to the string of IP address.
 * 
 * @Remark
 * IMPORTANT: The return value must be freed.
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

/**
 * 
 * @Function
 * uint32_t readable_to_i(uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3)
 *
 * @Summary
 *  Turn the readable string to uint32_t of IP address.
 * 
 * @Description
 *  Turn the ip address which is represented in string to uint32_t.
 * <p>
 * 
 * @Parameters
 *  @n0 The top two bytes of IP address.
 *  
 *  @n1 The second two bytes of IP address.
 * 
 *  @n2 The third two bytes of IP address.
 * 
 *  @n3 The last two bytes of IP address.
 * 
 *  For example: 192.168.0.100 -> n0 = 192, n1 = 168, n3 = 0, n4 = 100
 * 
 * @Returns
 *  An IP address representing in uint32_t.
 * 
 */

uint32_t readable_to_i(uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3)
{
    return (n0 << 24) + (n1 << 16) + (n2 << 8) + n3;
}


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/******************************************************************************
  @Function
    char * sddp_search_response_msg(uint32_t addr, uint16_t port)

  @Summary
    Creation for SDDP search response message.

  @Remarks
    Refer to the netapp_lib.h interface header for function usage details.
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
    Refer to the netapp_lib.h interface header for function usage details.
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
    char * sddp_identify_msg(uint32_t addr, uint16_t port)

  @Summary
    Creation for SDDP IDENTIFY message.

  @Remarks
    Refer to the netapp_lib.h interface header for function usage details.
 ***************************************************************************/
char * sddp_identify_msg(uint32_t addr, uint16_t port) {
    char * ipAddr = i_to_readable(addr);
    
    uint8_t STR_BUFFER_SIZE = 255;
    char *res = malloc(STR_BUFFER_SIZE);
    snprintf(res, STR_BUFFER_SIZE, "NOTIFY IDENTIFY SDDP/1.0\r\n"
            "From: \"%s:%d\"\r\n"
            "Host: \"%s\"\r\n"
            "Type: \"%s\"\r\n"
            "Primary-Proxy: \"%s\"\r\n"
            "Proxies: \"%s\"\r\n"
            "Manufacturer: \"%s\"\r\n"
            "Model: \"%s\"\r\n"
            "Driver: \"%s\"\r\n",
            ipAddr, port, SDDP_HOST, SDDP_TYPE, SDDP_PRI_PROXY, SDDP_PROXIES, 
            SDDP_MANUFACTURER, SDDP_MODEL, SDDP_DRIVER);
    free(ipAddr);
    
    return res;
}

/******************************************************************************
  @Function
    char * get_ip_request_body(char * requestMsg)

  @Summary
    HTTP request seperator for seperating request body.

  @Remarks
    Refer to the netapp_lib.h interface header for function usage details.
 ***************************************************************************/
char * get_ip_request_body(char * requestMsg) {
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
    Message ip_ctrl_request_to_message(char *reqBody)

  @Summary
    The function to parse command in order to know which command is submitted.

  @Remarks
    Refer to the netapp_lib.h interface header for function usage details.
 ***************************************************************************/
Message ip_ctrl_request_to_message(char *reqBody) {
    
    // Initial for return value
    Message msg;
    msg.msgType = MSG_TYPE_REQUEST;
    msg.cmdType = CMD_TYPE_INVALID;
    msg.valueType = VAL_TYPE_NUM;
    
    cJSON *body_json = cJSON_Parse(reqBody);
    if (body_json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            // TODO print error msg
        }
        msg.cmdType = CANNOT_BE_PARSE;
        goto end;
    }
    
    cJSON *command_json = cJSON_GetObjectItemCaseSensitive(body_json, "command");
    if (!cJSON_IsString(command_json) ||  command_json->valuestring == NULL) {
        // TODO print error msg
        msg.cmdType = CANNOT_BE_PARSE;
    } else {
        parse_cmd_string(&msg, command_json->valuestring);
    }

    end:
    cJSON_Delete(body_json);
    return msg;
}

/******************************************************************************
  @Function
    char * ip_ctrl_response_header(uint16_t content_len)

  @Summary
    Create the reponse header of IP Control.

  @Remarks
    Refer to the netapp_lib.h interface header for function usage details.
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
    Refer to the netapp_lib.h interface header for function usage details.
 ***************************************************************************/
char * ip_ctrl_response_body(bool cmd_result) {
    cJSON *response = cJSON_CreateObject();
    
    // "result":SUCCESS,
    cJSON *result = cJSON_CreateString(cmd_result ? "SUCCESS" : "FAIL");
    cJSON_AddItemToObject(response, "result", result);
    
    /*  "info": {
     *      "firmware": INFO_FIRMWARE,
     *      "model": INFO_MODEL,
     *      "serial": INFO_SERIAL,
     *      "runtime": "1 Day 40 Hour 10 Min"
     * },
     */
    cJSON *info = cJSON_CreateObject();
    cJSON_AddItemToObject(response, "info", info);
    
    cJSON *firmware = cJSON_CreateString(getFirmware());
    cJSON_AddItemToObject(info, "firmware", firmware);
    
    cJSON *model = cJSON_CreateString(getModelName());
    cJSON_AddItemToObject(info, "model", model);
    
    cJSON *serial = cJSON_CreateString(getSerialNum());
    cJSON_AddItemToObject(info, "serial", serial);
    
    cJSON *runtime = cJSON_CreateString(getRuntime());
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
    
    cJSON *input = cJSON_CreateNumber(getInput());
    cJSON_AddItemToObject(state, "input", input);
    
    cJSON *mute = cJSON_CreateNumber(getMute());
    cJSON_AddItemToObject(state, "mute", mute);
    
    cJSON *power = cJSON_CreateNumber(getPower());
    cJSON_AddItemToObject(state, "power", power);
    
    cJSON *volume = cJSON_CreateNumber(getVolume());
    cJSON_AddItemToObject(state, "volume", volume);
    
    uint8_t *ptrChannel = getChannel();
    char * channelStr = calloc(countDigitsOfInt(ptrChannel[0]) + countDigitsOfInt(ptrChannel[1]) + 2, sizeof(char));
    sprintf(channelStr, "%d.%d", ptrChannel[0], ptrChannel[1]);
    cJSON *channel = cJSON_CreateString(channelStr);
    cJSON_AddItemToObject(state, "channel", channel);
    free(channelStr);
    
    // Create string and release memory
    char * resBody = cJSON_Print(response);
    cJSON_Delete(response);
    
    return resBody;
}


/* *****************************************************************************
 End of File
 */
