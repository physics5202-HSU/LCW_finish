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

#ifndef _SHARED_SETTINGS_H    /* Guard against multiple inclusion */
#define _SHARED_SETTINGS_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include "tcpip/tcpip.h"
#include "tcpip/berkeley_api.h"
#include "tcpip/tcpip_manager.h"


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
#define DEFAULT_SERVER_LISTEN_PORT  3000
#define DEFAULT_SDDP_LISTENING_PORT 1902
#define DEFAULT_SDDP_MULTICAST_PORT 1902
#define DEFAULT_SDDP_NOTIFY_ALIVE_PERIOD_MIN 20
#define MAX_CLIENTS 3
    
// Constants for IP Control info
#define INFO_FIRMWARE   "same54 firmware"
#define INFO_MODEL      "ARSAME54P20A"
#define INFO_SERIAL     "serial_no"
#define INFO_RUNTIME    "1 Day 40 Hour 10 Min"



    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** SHARED_SETTINGS
     * 
     * @Summary
     * This is a data structure for infomations and settings about TV.
     * 
     * @Description
     *  Check the comment after each attribute for detail.
     * 
     * @Remarks
     *  This data should be only one instance, and need to be instantiate at boot.
     */
    typedef struct _shared_settings_t {
        // Basic Info
        char * firmware;
        char * serialNum;
        char * modelName;
        char * runtime;
        
        // Networks
        uint8_t macAddr[6];
        bool dhcpEnable;
        uint8_t localIPAddr[4];
        uint8_t subMask[4];
        uint8_t gateway[4];
        uint8_t dnsServer[4];
        SOCKET hostList[MAX_CLIENTS];
        uint16_t ipCtrlRecvPort;
        uint16_t sddpSrhListenPort;   // For SDDP search
        uint16_t sddpNtfyDstPort;   // For SDDP notify
        
        // Operable TV state
        bool power;
        uint8_t input;
        uint8_t volume;
        bool mute;
        uint8_t channel[2];
        
        // TODO
        uint8_t sddpNtfyPridMin;    // SDDP Notfy alive period in minute
        uint32_t    timeElapsed;
        // There are other attributes need to be included
        
    } SHARED_SETTINGS;


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        void initialSharedSettings()

      @Summary
        Initialize the shared settings.

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
    void initialSharedSettings();
    
    
    /***********************
     * @Function
     *  void setFirmware(char * firmware)
     * 
     * @Summary
     *  Store firmware version in shared settings.
     * 
     * @Description
     *  
     * 
     * @Parameters
     *  @firmware firmware version of MCU? SoC?
     * 
     *********************/
    void setFirmware(char * firmware);
    
    /***********************
     * @Function
     *  char * getFirmware()
     * 
     * @Summary
     *  Get firmware version from shared settings.
     * 
     * @Description
     *  
     * 
     * @Return
     *  firmware verion of MCU? SoC?
     * 
     *********************/
    char * getFirmware();
    
    /***********************
     * @Function
     *  void setSerialNum(char * serialNum)
     * 
     * @Summary
     *  Store serial number in shared settings.
     * 
     * @Description
     *  
     * 
     * @Parameters
     *  @serialNum serial number of MCU? SoC?
     * 
     *********************/
    void setSerialNum(char * serialNum);
    
    /***********************
     * @Function
     *  char * getSerialNum()
     * 
     * @Summary
     *  Get serial number from shared settings.
     * 
     * @Description
     *  
     * 
     * @Return
     *  serial number of MCU? SoC?
     * 
     *********************/
    char * getSerialNum();
    
    /***********************
     * @Function
     *  void setModelName(char * modelName)
     * 
     * @Summary
     *  Store model name in shared settings.
     * 
     * @Description
     *  
     * 
     * @Parameters
     *  @modelName model name of TV
     * 
     *********************/
    void setModelName(char * modelName);
    
    /***********************
     * @Function
     *  char * getModelName()
     * 
     * @Summary
     *  Get model name from shared settings.
     * 
     * @Description
     *  
     * 
     * @Return
     *  model name of TV
     * 
     *********************/
    char * getModelName();
    
    /***********************
     * @Function
     *  void setRumtime(char * runtime)
     * 
     * @Summary
     *  Store runtime in shared settings.
     * 
     * @Description
     *  
     * 
     * @Parameters
     *  @runtime the time passed since the last ON of TV
     * 
     *********************/
    void setRumtime(char * runtime);
    
    /***********************
     * @Function
     *  char * getRuntime()
     * 
     * @Summary
     *  Get runtime from shared settings.
     * 
     * @Description
     *  
     * 
     * @Return
     *  the time passed since the last ON of TV
     * 
     *********************/
    char * getRuntime();
    
    /***********************
     * @Function
     *  void setMacAddressSS(uint8_t * macAddr)
     * 
     * @Summary
     *  Store MAC address in shared settings.
     * 
     * @Description
     *  
     * 
     * @Parameters
     *  @macAddr the new MAC address to be stored.
     *********************/
    void setMacAddressSS(uint8_t * macAddr);
    
    /***********************
     * @Function
     *  uint8_t * getMacAddressSS()
     * 
     * @Summary
     *  Get MAC address from shared settings.
     * 
     * @Description
     *  
     * 
     * @Returns
     *  A uint8_t pointer point at the uint8_t array of MAC address
     * 
     *********************/
    uint8_t * getMacAddressSS();
    
    /***********************
     * @Function
     *  void setDhcpSS(bool isEnable)
     * 
     * @Summary
     *  Store DHCP state in shared settings.
     * 
     * @Description
     *  
     * 
     * @Parameters
     *  @isEnable the state of DHCP
     *********************/
    void setDhcpSS(bool isEnable);
    
    /***********************
     * @Function
     *  bool getDhcpSS()
     * 
     * @Summary
     *  Get DHCP state from shared settings.
     * 
     * @Description
     *  
     * 
     * @Returns
     *  true    DHCP is enable
     *  false   DHCP is diable
     * 
     *********************/
    bool getDhcpSS();
    
    /***********************
     * @Function
     *  void setIPAddressSS(uint32_t ipAddr)
     * 
     * @Summary
     *  Store IP address in shared settings.
     * 
     * @Description
     *  
     * 
     * @Parameters
     *  @ipAddr the new IP address to be stored.
     *********************/
    void setIpAddressSS(uint8_t * ipAddr);
    
    /***********************
     * @Function
     *  uint8_t * getIpAddressSS()
     * 
     * @Summary
     *  Get local IP address from shared settings.
     * 
     * @Description
     *  
     * 
     * @Returns
     *  A uint8_t pointer point at the uint8_t array of IP address
     * 
     *********************/
    uint8_t * getIpAddressSS();
    
    /***********************
     * @Function
     *  void setSubMaskSS(uint8_t * mask);
     * 
     * @Summary
     *  Store subnet mask in shared settings.
     * 
     * @Description
     *  
     * 
     * @Parameters
     *  @mask the new mask to be stored.
     * 
     *********************/
    void setSubMaskSS(uint8_t * mask);
    
    /***********************
     * @Function
     *  uint8_t * getSubMaskSS()
     * 
     * @Summary
     *  Get subnet mask from shared settings.
     * 
     * @Description
     *  
     * 
     * @Returns
     *  A uint8_t pointer point at the uint8_t array of subnet mask
     * 
     *********************/
    uint8_t * getSubMaskSS();
    
    /***********************
     * @Function
     *  void setGatewayAddrSS(uint8_t * gatewayAddr)
     * 
     * @Summary
     *  Store gateway address in shared settings.
     * 
     * @Description
     *  
     * 
     * @Parameters
     *  @gatewayAddr the gateway address to be stored.
     * 
     *********************/
    void setGatewayAddrSS(uint8_t * gatewayAddr);
    
    /***********************
     * @Function
     *  uint8_t * getGatewayAddrSS()
     * 
     * @Summary
     *  Get gateway address from shared settings.
     * 
     * @Description
     *  
     * 
     * @Returns
     *  A uint8_t pointer point at the uint8_t array of gateway address
     * 
     *********************/
    uint8_t * getGatewayAddrSS();
    
    /***********************
     * @Function
     *  void setDnsAddrSS(uint8_t * dnsAddr)
     * 
     * @Summary
     *  Store dns server address in shared settings.
     * 
     * @Description
     *  
     * 
     * @Parameters
     *  @dnsAddr the dns server address to be stored.
     * 
     *********************/
    void setDnsAddrSS(uint8_t * dnsAddr);
    
    /***********************
     * @Function
     *  uint8_t * getDnsAddrSS()
     * 
     * @Summary
     *  Get dns server address from shared settings.
     * 
     * @Description
     *  
     * 
     * @Returns
     *  A uint8_t pointer point at the uint8_t array of dns server address
     * 
     *********************/
    uint8_t * getDnsAddrSS();
    
    void setHostListByIndex(int index, SOCKET socket);
    
    SOCKET * getHostList();
    
    /***********************
     * @Function
     *  void setIpCtrlRecvPortSS(uint16_t port)
     * 
     * @Summary
     *  Store the port for listening IP control messages in shared settings.
     * 
     * @Parameters
     *  @port the port for listening IP control messages.
     * 
     *********************/
    void setIpCtrlRecvPortSS(uint16_t port);
    
    /***********************
     * @Function
     *  uint16_t getIpCtrlRecvPortSS()
     * 
     * @Summary
     *  Get the port for listening IP control command from shared settings.
     * 
     * @Returns
     *  The IP control command listening port
     * 
     *********************/
    uint16_t getIpCtrlRecvPortSS();
    
    /***********************
     * @Function
     *  void setSddpSrhListenPortSS(uint16_t port)
     * 
     * @Summary
     *  Store the port for listening SDDP search messages in shared settings.
     * 
     * @Parameters
     *  @port the port for listening SDDP search messages.
     * 
     *********************/
    void setSddpSrhListenPortSS(uint16_t port);
    
    /***********************
     * @Function
     *  uint16_t getSddpSrhListenPortSS()
     * 
     * @Summary
     *  Get the port for listening SDDP search message from shared settings.
     * 
     * @Returns
     *  The port for listening SDDP search message
     * 
     *********************/
    uint16_t getSddpSrhListenPortSS();
    
    /***********************
     * @Function
     *  void setSddpNtfyDstPortSS(uint16_t port)
     * 
     * @Summary
     *  Store the port for multicasting SDDP notify alive messages in shared settings.
     * 
     * @Parameters
     *  @port the port for multicasting SDDP notify alive messages.
     * 
     *********************/
    void setSddpNtfyDstPortSS(uint16_t port);
    
    /***********************
     * @Function
     *  uint16_t getSddpNtfyDstPortSS()
     * 
     * @Summary
     *  Get the port for multicasting SDDP notify alive message from shared settings.
     * 
     * @Returns
     *  The port for multicasting SDDP notify alive message
     * 
     *********************/
    uint16_t getSddpNtfyDstPortSS();
    

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
    void setPower(bool power);

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
    bool getPower();

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
    void setInput(uint8_t input);

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
    uint8_t getInput();

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
    void setVolume(uint8_t volume);

   /***********************
    * @Function
    *  uint8_t getVolume()
    * 
    * @Summary
    *  Get TV volume from shared settings.
    * 
    * @Remarks
    *  Refer to the shared_settings.h interface header for function usage details.
    *********************/
    uint8_t getVolume();
    
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
    void setMute(bool mute);

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
    bool getMute();
    
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
    void setChannel(uint8_t * channel);

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
    uint8_t * getChannel();
    
    /***********************
    * @Function
    *  void setSddpNtfyAlivePeriod(uint8_t period)
    * 
    * @Summary
    *  Store SDDP notify alive period in shared settings.
    * 
    * @Parameters
    *  @period the period of multicasting SDDP notify alive messages in minutes.
    * 
    *********************/
    void setSddpNtfyAlivePeriod(uint8_t period);

   /***********************
    * @Function
    *  uint8_t getSddpNtfyAlivePeriod()
    * 
    * @Summary
    *  Get SDDP notify alive period from shared settings.
    * 
    * @Returns
    *  The period of multicasting SDDP notify alive message in minutes.
    *********************/
    uint8_t getSddpNtfyAlivePeriod();
    
    /***********************
    * @Function
    *  void timeElapsedOneSec()
    * 
    * @Summary
    *  Used by RTC period 7 interrupt.
    *********************/
    void timeElapsedOneSec();

   /***********************
    * @Function
    *  uint32_t getTimeElapsedSec()
    * 
    * @Summary
    *  Get elapsed time represented in second
    * 
    * @Returns
    *  time elapsed in second
    *********************/
    uint32_t getTimeElapsedSec();

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _SHARED_SETTINGS_H */

/* *****************************************************************************
 End of File
 */
