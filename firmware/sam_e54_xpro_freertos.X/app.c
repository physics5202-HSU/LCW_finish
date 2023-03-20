/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"

#include "tcpip/tcpip.h"

#include "pkt_utils.h"

#define SDDP_SERVER_PORT 1902
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define SDDP_MULTICAST_PORT 1902

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
 */

APP_DATA appData;
uint32_t startTick;
uint16_t sddp_notify_counter = 0;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
 */


// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
 */
void get_dst_addr(struct sockaddr_in *dst)
{
    dst->sin_family = AF_INET;
    dst->sin_port = SDDP_MULTICAST_PORT;
    memset(&(dst->sin_zero), '0', 8);

    // 239.255.255.250
    struct in_addr multicastAddr;
    multicastAddr.S_un.S_un_b.s_b1 = 0xef;
    multicastAddr.S_un.S_un_b.s_b2 = 0xff;
    multicastAddr.S_un.S_un_b.s_b3 = 0xff;
    multicastAddr.S_un.S_un_b.s_b4 = 0xfa;
    dst->sin_addr = multicastAddr;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize(void) {
    /* Place the App state machine in its initial state. */
    appData.state = APP_TCPIP_WAIT_INIT;

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
    
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks(void) {
    SYS_STATUS tcpipStat;
    const char *netName, *netBiosName;
    int i, nNets;
    TCPIP_NET_HANDLE netH;

    // Counter for SDDP notify alive, triggered per second.
    if(SYS_TMR_TickCountGet() - startTick >= SYS_TMR_TickCounterFrequencyGet())
    {
        startTick = SYS_TMR_TickCountGet();
        sddp_notify_counter++;
    }
    
    SYS_CMD_READY_TO_READ();
    switch (appData.state) {
        case APP_TCPIP_WAIT_INIT:
            tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
            if (tcpipStat < 0) { // some error occurred
                SYS_CONSOLE_MESSAGE(" APP: TCP/IP stack initialization failed!\r\n");
                appData.state = APP_TCPIP_ERROR;
            } else if (tcpipStat == SYS_STATUS_READY) {
                // now that the stack is ready we can check the 
                // available interfaces 
                nNets = TCPIP_STACK_NumberOfNetworksGet();
                for (i = 0; i < nNets; i++) {

                    netH = TCPIP_STACK_IndexToNet(i);
                    netName = TCPIP_STACK_NetNameGet(netH);
                    netBiosName = TCPIP_STACK_NetBIOSName(netH);

#if defined(TCPIP_STACK_USE_NBNS)
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS enabled\r\n", netName, netBiosName);
#else
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS disabled\r\n", netName, netBiosName);
#endif  // defined(TCPIP_STACK_USE_NBNS)

                }
                appData.state = APP_TCPIP_WAIT_FOR_IP;
                
            }
            break;


        case APP_TCPIP_WAIT_FOR_IP:
            nNets = TCPIP_STACK_NumberOfNetworksGet();
            for (i = 0; i < nNets; i++) {
                netH = TCPIP_STACK_IndexToNet(i);
                if (!TCPIP_STACK_NetIsReady(netH)) {
                    return; // interface not ready yet!
                }
                IPV4_ADDR           ipAddr;
                ipAddr.Val = TCPIP_STACK_NetAddress(netH);
                appData.addr = ipAddr.Val;
                SYS_CONSOLE_MESSAGE(TCPIP_STACK_NetNameGet(netH));
                SYS_CONSOLE_MESSAGE(" IP Address: ");
                SYS_CONSOLE_PRINT("%d.%d.%d.%d \r\n", ipAddr.v[0], ipAddr.v[1], ipAddr.v[2], ipAddr.v[3]); 
            }
            // all interfaces ready. Could start transactions!!!
            appData.state = APP_BSD_CREATE_SOCKET;
            //... etc.
            break;
        case APP_BSD_CREATE_SOCKET:
        {
            SOCKET udpSkt = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
            SYS_CONSOLE_PRINT("udpSkt: %d, %p.\r\n", udpSkt, &udpSkt);
            if (udpSkt == SOCKET_ERROR) {
                appData.state = APP_TCPIP_WAIT_FOR_IP;
                return;
            } else {
                appData.socket = (SOCKET) udpSkt;
                appData.state = APP_BSD_BIND;
            }
        }
            break;

        case APP_BSD_BIND:
        {
            struct sockaddr_in addr;
            int addrlen = sizeof (struct sockaddr_in);
            addr.sin_port = SDDP_SERVER_PORT;
            addr.sin_addr.S_un.S_addr = IP_ADDR_ANY;
            if (bind(appData.socket, (struct sockaddr*) &addr, addrlen) == SOCKET_ERROR) {
                closesocket(appData.socket);
                appData.state = APP_TCPIP_SERVING_CONNECTION;
            } else {
                appData.state = APP_TCPIP_SERVING_CONNECTION;
            }
        }
            break;

        case APP_TCPIP_SERVING_CONNECTION:
        {
            // Notify Alive is sent every 60 seconds
            if (sddp_notify_counter >= 60) {
                sddp_notify_counter = 0;
                
                struct sockaddr_in dst;
                get_dst_addr(&dst);

                char *resMsg = sddp_notify_alive_msg(appData.addr, SDDP_SERVER_PORT);
                sendto(appData.socket, resMsg, strlen(resMsg), 0, (struct sockaddr *) &dst, sizeof(dst));
                free(resMsg);
            }
            
            
            uint8_t AppBuffer[100];

            struct sockaddr_in clientaddr;
            int len = sizeof (struct sockaddr_in);

            // Figure out how many bytes have been received and how many we can transmit.
            int i = recvfrom(appData.socket, (char*) AppBuffer, sizeof (AppBuffer), 0, (struct sockaddr *) &clientaddr, &len);

            if (i <= 0) {
                break;
            }

            SYS_CONSOLE_PRINT("Recieved '%s' size %d\r\n", AppBuffer, i);
            
            char searchMsg[] = "SEARCH * SDDP/1.0";
            if (strncmp(searchMsg, (char*) AppBuffer, sizeof(searchMsg) - 1) == 0) {
                memset(AppBuffer, '0', 100);
                
                struct sockaddr_in dst;
                get_dst_addr(&dst);

                char *resMsg = sddp_search_response_msg(appData.addr, SDDP_SERVER_PORT);
                sendto(appData.socket, resMsg, strlen(resMsg), 0, (struct sockaddr *) &dst, sizeof(dst));
                free(resMsg);
            } 
//            appData.state = APP_TCPIP_CLOSING_CONNECTION;
        }
            break;
        case APP_TCPIP_CLOSING_CONNECTION:
        {
            SYS_CONSOLE_PRINT("APP_TCPIP_CLOSING_CONNECTION, socket: %d\r\n", appData.socket);
            closesocket(appData.socket);

            appData.state = APP_BSD_CREATE_SOCKET;
        }
            break;
        default:
            break;
    }
}


/*******************************************************************************
 End of File
 */
