/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Innolux

  @File Name
    shared_settings.h

  @Summary
    Holds and manages shared settings across the whole system.

  @Description
    This library supplies operations of shared setting used in control board
    and mother board.
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
#include "shared_settings.h"
#include "com_lib.h"
#include "uart_command.h"
#include "Judgeman.h"
#include "eeprom.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** SHARED_SETTINGS sharedSettings

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
SHARED_SETTINGS sharedSettings;


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
//static int ExampleLocalFunction(int param1, int param2) {
//    return 0;
//}


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
     * @Function
     *  void initialSharedSettings()
     * 
     * @Summary
     *  Initialize the shared settings
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     */
    void initialSharedSettings() {

        sharedSettings.firmware = INFO_FIRMWARE;
        sharedSettings.serialNum = INFO_SERIAL;
        sharedSettings.modelName = INFO_MODEL;
        sharedSettings.runtime = INFO_RUNTIME;

        // Networks
    //    sharedSettings.macAddr;
    //    sharedSettings.dhcpEnable;
    //    sharedSettings.localIPAddr;
    //    sharedSettings.localIPmask;
    //    sharedSettings.gateway;
    //    sharedSettings.dnsServer;
    //    sharedSettings.hostList;
        for (int i = 0; i < MAX_CLIENTS; i ++)
            sharedSettings.hostList[i] = INVALID_SOCKET;
        sharedSettings.ipCtrlRecvPort = DEFAULT_SERVER_LISTEN_PORT;
        sharedSettings.sddpSrhListenPort = DEFAULT_SDDP_LISTENING_PORT;
        sharedSettings.sddpNtfyDstPort = DEFAULT_SDDP_MULTICAST_PORT;

        // Operable TV state
        sharedSettings.power = CMD_VALUE_OFF_B;
        sharedSettings.input = INP_HDMI1;
        sharedSettings.volume = 50;
        sharedSettings.mute = CMD_VALUE_OFF_B;
        sharedSettings.channel[0] = 12;
        sharedSettings.channel[1] = 34;
        
        sharedSettings.sddpNtfyPridMin = DEFAULT_SDDP_NOTIFY_ALIVE_PERIOD_MIN;
        sharedSettings.timeElapsed  = 0;
    }

    /***********************
     * @Function
     *  void setFirmware(char * firmware)
     * 
     * @Summary
     *  Store firmware version in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details
    *********************/
    void setFirmware(char * firmware) {
        if (sharedSettings.firmware != NULL)
            free(sharedSettings.firmware);
        
        sharedSettings.firmware = calloc(strlen(firmware), sizeof(char));
        strcpy(sharedSettings.firmware, firmware);
    }

    /***********************
    * @Function
    *  char * getFirmware()
    * 
    * @Summary
    *  Get firmware version from shared settings.
    * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details
    * 
    *********************/
    char * getFirmware() {
        return sharedSettings.firmware;
    }

    /***********************
    * @Function
    *  void setSerialNum(char * serialNum)
    * 
    * @Summary
    *  Store serial number in shared settings.
    * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details
    * 
    *********************/
    void setSerialNum(char * serialNum) {
        if (sharedSettings.serialNum != NULL)
            free(sharedSettings.serialNum);
        
        sharedSettings.serialNum = calloc(strlen(serialNum), sizeof(char));
        strcpy(sharedSettings.serialNum, serialNum);
    }

    /***********************
    * @Function
    *  char * getSerialNum()
    * 
    * @Summary
    *  Get serial number from shared settings.
    * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details
    * 
    *********************/
    char * getSerialNum() {
        return sharedSettings.serialNum;
    }

    /***********************
    * @Function
    *  void setModelName(char * modelName)
    * 
    * @Summary
    *  Store model name in shared settings.
    * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details
    * 
    *********************/
    void setModelName(char * modelName) {
        if (sharedSettings.modelName != NULL)
            free(sharedSettings.modelName);
        
        sharedSettings.modelName = calloc(strlen(modelName), sizeof(char));
        strcpy(sharedSettings.modelName, modelName);
    }

    /***********************
    * @Function
    *  char * getModelName()
    * 
    * @Summary
    *  Get model name from shared settings.
    * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details
    * 
    *********************/
    char * getModelName() {
        return sharedSettings.modelName;
    }

    /***********************
    * @Function
    *  void setRumtime(char * runtime)
    * 
    * @Summary
    *  Store runtime in shared settings.
    * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details
    * 
    *********************/
    void setRumtime(char * runtime) {
        sharedSettings.runtime = runtime;
    }

    /***********************
    * @Function
    *  char * getRuntime()
    * 
    * @Summary
    *  Get runtime from shared settings.
    * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details
    * 
    *********************/
    char * getRuntime() {
        return sharedSettings.runtime;
    }

    /***********************
     * @Function
     *  void setMacAddressSS(uint8_t * macAddr)
     * 
     * @Summary
     *  Store MAC address in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    void setMacAddressSS(uint8_t * macAddr) {
        for (int i = 0; i < 6; i++) {
            sharedSettings.macAddr[i] = macAddr[i];
        }
    }
    
    /***********************
     * @Function
     *  uint8_t * getMacAddressSS()
     * 
     * @Summary
     *  Get MAC address from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    uint8_t * getMacAddressSS() {
        return sharedSettings.macAddr;
    }
    
    /***********************
     * @Function
     *  void setDhcpSS(bool isEnable)
     * 
     * @Summary
     *  Store DHCP state in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    void setDhcpSS(bool isEnable) {
        sharedSettings.dhcpEnable = isEnable;
    }

    /***********************
     * @Function
     *  bool getDhcpSS()
     * 
     * @Summary
     *  Get DHCP state from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    bool getDhcpSS() {
        return sharedSettings.dhcpEnable;
    }

    /***********************
     * @Function
     *  void setIPAddressSS(uint32_t ipAddr)
     * 
     * @Summary
     *  Store IP address in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    void setIpAddressSS(uint8_t * ipAddr) {
        for (int i = 0; i < 4; i++) {
            sharedSettings.localIPAddr[i] = ipAddr[i];
        }
    }
    
    /***********************
     * @Function
     *  uint8_t * getIPAddressSS()
     * 
     * @Summary
     *  Get IP address from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    uint8_t * getIpAddressSS() {
        return sharedSettings.localIPAddr;
    }
    
    /***********************
     * @Function
     *  void setIPAddressSS(uint32_t ipAddr)
     * 
     * @Summary
     *  Store IP address in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    void setSubMaskSS(uint8_t * mask) {
        for (int i = 0; i < 4; i++) {
            sharedSettings.subMask[i] = mask[i];
        }
    }
    
    /***********************
     * @Function
     *  uint8_t * getIPAddressSS()
     * 
     * @Summary
     *  Get IP address from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    uint8_t * getSubMaskSS() {
        return sharedSettings.subMask;
    }

    /***********************
     * @Function
     *  void setGatewayAddrSS(uint8_t * gatewayAddr)
     * 
     * @Summary
     *  Store gateway address in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     * 
     *********************/
    void setGatewayAddrSS(uint8_t * gatewayAddr) {
        for (int i = 0; i < 4; i++) {
            sharedSettings.gateway[i] = gatewayAddr[i];
        }
    }
    
    /***********************
     * @Function
     *  uint8_t * getGatewayAddrSS()
     * 
     * @Summary
     *  Get gateway address from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     * 
     *********************/
    uint8_t * getGatewayAddrSS() {
        return sharedSettings.gateway;
    }
    
    /***********************
     * @Function
     *  void setDnsAddrSS(uint8_t * dnsAddr)
     * 
     * @Summary
     *  Store dns server address in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     * 
     *********************/
    void setDnsAddrSS(uint8_t * dnsAddr) {
        for (int i = 0; i < 4; i++) {
            sharedSettings.dnsServer[i] = dnsAddr[i];
        }
    }
    
    /***********************
     * @Function
     *  uint8_t * getDnsAddrSS()
     * 
     * @Summary
     *  Get dns server address from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     * 
     *********************/
    uint8_t * getDnsAddrSS() {
        return sharedSettings.dnsServer;
    }
    
    
    void setHostListByIndex(int index, SOCKET socket) {
        sharedSettings.hostList[index] = socket;
    }
    
    SOCKET * getHostList() {
        return sharedSettings.hostList;
    }
    
    /***********************
     * @Function
     *  void setIpCtrlRecvPortSS(uint16_t port)
     * 
     * @Summary
     *  Store the port for receiving IP control command in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     * 
     *********************/
    void setIpCtrlRecvPortSS(uint16_t port) {
        sharedSettings.ipCtrlRecvPort = port;
    }
    
    /***********************
     * @Function
     *  uint16_t getIpCtrlRecvPortSS()
     * 
     * @Summary
     *  Get the port of ip control command receiving port from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     * 
     *********************/
    uint16_t getIpCtrlRecvPortSS() {
        return sharedSettings.ipCtrlRecvPort;
    }
    
    /***********************
     * @Function
     *  void setSddpSrhListenPortSS(uint16_t port)
     * 
     * @Summary
     *  Store the port for listening SDDP search message in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     * 
     *********************/
    void setSddpSrhListenPortSS(uint16_t port) {
        sharedSettings.sddpSrhListenPort = port;
    }
    
    /***********************
     * @Function
     *  uint16_t getSddpSrhListenPortSS()
     * 
     * @Summary
     *  Get the port of SDDP search listening port from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     * 
     *********************/
    uint16_t getSddpSrhListenPortSS() {
        return sharedSettings.sddpSrhListenPort;
    }
    
    /***********************
     * @Function
     *  void setSddpNtfyDstPortSS(uint16_t port)
     * 
     * @Summary
     *  Store the port for multicasting SDDP notify alive message in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     * 
     *********************/
    void setSddpNtfyDstPortSS(uint16_t port) {
        sharedSettings.sddpNtfyDstPort = port;
    }
    
    /***********************
     * @Function
     *  uint16_t getSddpNtfyDstPortSS()
     * 
     * @Summary
     *  Get the port of multicasting sddp notify alive from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     * 
     *********************/
    uint16_t getSddpNtfyDstPortSS() {
        return sharedSettings.sddpNtfyDstPort;
    }
    
    /***********************
     * @Function
     *  void setPower(bool power)
     * 
     * @Summary
     *  Store TV power state in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    void setPower(bool power) {
        sharedSettings.power = power;
    }

    /***********************
     * @Function
     *  bool getPower()
     * 
     * @Summary
     *  Get TV power state from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    bool getPower() {
        return sharedSettings.power;
    }

    /***********************
     * @Function
     *  void setInput(uint8_t input)
     * 
     * @Summary
     *  Store TV input in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    void setInput(uint8_t input) {
        sharedSettings.input = input;
    }

    /***********************
     * @Function
     *  uint8_t getInput()
     * 
     * @Summary
     *  Get TV input from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    uint8_t getInput() {
        return sharedSettings.input;
    }

    /***********************
     * @Function
     *  void setVolume(uint8_t volume)
     * 
     * @Summary
     *  Store TV volume in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    void setVolume(uint8_t volume) {
        sharedSettings.volume = volume;
    }

    /***********************
     * @Function
     *  bool getVolume()
     * 
     * @Summary
     *  Get TV volume from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    uint8_t getVolume() {
        return sharedSettings.volume;
    }

    /***********************
     * @Function
     *  void setMute(bool mute)
     * 
     * @Summary
     *  Store TV muting state in shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    void setMute(bool mute) {
        sharedSettings.mute = mute;
    }

    /***********************
     * @Function
     *  bool getMute()
     * 
     * @Summary
     *  Get TV muting state from shared settings.
     * 
     * @Remarks
     *  Refer to the shared_settings.h interface header for function usage details.
     *********************/
    bool getMute() {
        return sharedSettings.mute;
    }

    /***********************
    * @Function
    *  void setChannel(uint8_t * chanel)
    * 
    * @Summary
    *  Store TV channel in shared settings.
    * 
    * @Remarks
    *  Refer to the shared_settings.h interface header for function usage details.
    *********************/
    void setChannel(uint8_t * channel) {
        sharedSettings.channel[0] = channel[0];
        sharedSettings.channel[1] = channel[1];
    }

    /***********************
    * @Function
    *  uint8_t * getChannel()
    * 
    * @Summary
    *  Get TV channel from shared settings.
    * 
    * @Remarks
    *  Refer to the shared_settings.h interface header for function usage details.
    *********************/
    uint8_t * getChannel() {
        return sharedSettings.channel;
    }
    
    /***********************
    * @Function
    *  void setSddpNtfyAlivePeriod(uint8_t period)
    * 
    * @Summary
    *  Store TV channel in shared settings.
    * 
    * @Remarks
    *  Refer to the shared_settings.h interface header for function usage details.
    *********************/
    void setSddpNtfyAlivePeriod(uint8_t period) {
        sharedSettings.sddpNtfyPridMin = period;
    }

   /***********************
    * @Function
    *  uint8_t getSddpNtfyAlivePeriod()
    * 
    * @Summary
    *  Get SDDP notify alive period from shared settings.
    * 
    * @Remarks
    *  Refer to the shared_settings.h interface header for function usage details.
    *********************/
    uint8_t getSddpNtfyAlivePeriod() {
        return sharedSettings.sddpNtfyPridMin;
    }
    
    /***********************
    * @Function
    *  void timeElapsedOneSec()
    * 
    * @Summary
    *  Used by RTC period 7 interrupt.
    * 
    * @Remarks
    *  Refer to the shared_settings.h interface header for function usage details.
    *********************/
    void timeElapsedOneSec() {
        sharedSettings.timeElapsed++;
    }

   /***********************
    * @Function
    *  uint32_t getTimeElapsedSec()
    * 
    * @Summary
    *  Get elapsed time represented in second.
    * 
    * @Remarks
    *  Refer to the shared_settings.h interface header for function usage details.
    *********************/
    uint32_t getTimeElapsedSec() {
        return sharedSettings.timeElapsed;
    }


/* *****************************************************************************
 End of File
 */
