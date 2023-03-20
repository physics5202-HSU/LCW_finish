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

#include "tcp_app.h"

#include "tcpip/tcpip.h"

#include <errno.h>
#include <sys/errno.h>
#include <com_lib.h>
#include "netapp_lib.h"
#include "shared_settings.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

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

TCP_APP_DATA tcpAppData;
extern xQueueHandle queue_IP_UART;
extern xQueueHandle queue_UART_IP;

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
int flag_addr=0;
int ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8=0;
uint8_t lcw_ch_value[7]={138,147,150,154,161,177,248};
uint8_t lcw_address[14]={Driving_Board_1_CTRL_ADDR,Driving_Board_2_CTRL_ADDR,Driving_Board_3_CTRL_ADDR,Driving_Board_4_CTRL_ADDR,
                         Driving_Board_5_CTRL_ADDR,Driving_Board_6_CTRL_ADDR,Driving_Board_7_CTRL_ADDR,Driving_Board_8_CTRL_ADDR,
                         Driving_Board_9_CTRL_ADDR,Driving_Board_10_CTRL_ADDR,Driving_Board_11_CTRL_ADDR,Driving_Board_12_CTRL_ADDR,
                         Driving_Board_13_CTRL_ADDR,Driving_Board_14_CTRL_ADDR};
void TCP_APP_Initialize( void ) {
    /* Place the App state machine in its initial state. */
    tcpAppData.state = TCP_APP_TCPIP_WAIT_INIT;

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

void TCP_APP_Tasks(void) {
    SYS_STATUS tcpipStat;
    const char *netName, *netBiosName;
    int i, nNets;
    TCPIP_NET_HANDLE netH;

    switch (tcpAppData.state) {
        case TCP_APP_TCPIP_WAIT_INIT:
            tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
            if (tcpipStat < 0) { // some error occurred
                SYS_CONSOLE_MESSAGE(" APP: TCP/IP stack initialization failed!\r\n");
                tcpAppData.state = TCP_APP_TCPIP_ERROR;
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

                tcpAppData.state = TCP_APP_TCPIP_WAIT_FOR_IP;
            }

            break;

        case TCP_APP_TCPIP_WAIT_FOR_IP:
            nNets = TCPIP_STACK_NumberOfNetworksGet();
            for (i = 0; i < nNets; i++) {
                netH = TCPIP_STACK_IndexToNet(i);
                if (!TCPIP_STACK_NetIsReady(netH)) {
                    return; // interface not ready yet!
                }
                IPV4_ADDR           ipAddr;
                ipAddr.Val = TCPIP_STACK_NetAddress(netH);
                SYS_CONSOLE_MESSAGE(TCPIP_STACK_NetNameGet(netH));
                SYS_CONSOLE_MESSAGE("[tcp_app] IP Address: ");
                SYS_CONSOLE_PRINT("%d.%d.%d.%d \r\n", ipAddr.v[0], ipAddr.v[1], ipAddr.v[2], ipAddr.v[3]);
            }
            // all interfaces ready. Could start transactions!!!
            tcpAppData.state = TCP_APP_BSD_INIT;
            //... etc.
            break;
        case TCP_APP_BSD_INIT:
        {
            // Initialize all client socket handles so that we don't process
            // them in the BSD_OPERATION state
            for (i = 0; i < MAX_CLIENT; i++)
                tcpAppData.ClientSock[i] = INVALID_SOCKET;
            tcpAppData.state = TCP_APP_BSD_CREATE_SOCKET;
        }
            break;

        case TCP_APP_BSD_CREATE_SOCKET:
        {
            // Create a socket for this server to listen and accept connections on
            SOCKET tcpSkt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            SYS_CONSOLE_PRINT("tcpSkt: %d, %p.\r\n", tcpSkt, &tcpSkt);
            if (tcpSkt == INVALID_SOCKET) {
                return;
            }
            tcpAppData.bsdServerSocket = (SOCKET) tcpSkt;
            tcpAppData.state = TCP_APP_BSD_BIND;
        }
            break;

        case TCP_APP_BSD_BIND:
        {
            // Bind socket to a local port
            struct sockaddr_in addr;
            int addrlen = sizeof (struct sockaddr_in);
            addr.sin_port = getIpCtrlRecvPortSS();
            addr.sin_addr.S_un.S_addr = IP_ADDR_ANY;

            if (bind(tcpAppData.bsdServerSocket, (struct sockaddr*) &addr, addrlen) == SOCKET_ERROR) {
                return;
            }
            tcpAppData.state = TCP_APP_BSD_LISTEN;
            // No break needed
        }
            break;

        case TCP_APP_BSD_LISTEN:
        {
            if (listen(tcpAppData.bsdServerSocket, MAX_CLIENT) == 0) {
                tcpAppData.state = TCP_APP_BSD_OPERATION;
                SYS_CONSOLE_PRINT("Waiting for Client Connection on port: %d\r\n", DEFAULT_SERVER_LISTEN_PORT);
            }
        }
            break;
        case TCP_APP_BSD_OPERATION:
        {
            // Receive message from queue between uart and ip
            Message msgUart;
            if (xQueueReceive(queue_UART_IP, &msgUart, (TickType_t) 0) == pdTRUE) {
                char * resBody = ip_ctrl_response_body(true);
                char * resHeader = ip_ctrl_response_header(strlen(resBody));

                // Combine the response header and body
                char * response = malloc(strlen(resHeader) + strlen(resBody) + 1);
                strcpy(response, resHeader);
                free(resHeader);
                strcat(response, resBody);
                free(resBody);
                strcat(response, "\0");
                
                for (i = 0; i < MAX_CLIENT; i++) {
                    if (tcpAppData.ClientSock[i] == INVALID_SOCKET)
                        continue;
                    SYS_CONSOLE_PRINT("UART->IP@tcp_app:success %d\r\n", i);
                    send(tcpAppData.ClientSock[i], response, strlen(response), 0);
                }
                free(response);
                break;
            }
            
            int length;
            struct sockaddr_in addRemote;
            int addrlen = sizeof (struct sockaddr_in);
            char bfr[512];
            
            for (i = 0; i < MAX_CLIENT; i++) {
                // Accept any pending connection requests, assuming we have a place to store the socket descriptor
                if (tcpAppData.ClientSock[i] == INVALID_SOCKET) {
                    tcpAppData.ClientSock[i] = accept(tcpAppData.bsdServerSocket, (struct sockaddr*) &addRemote, &addrlen);
                    setHostListByIndex(i, tcpAppData.ClientSock[i]);
                }
                
                // If this socket is not connected then no need to process anything
                if (tcpAppData.ClientSock[i] == INVALID_SOCKET)
                    continue;

                // For all connected sockets, receive and send back the data
                length = recv(tcpAppData.ClientSock[i], bfr, sizeof (bfr), 0);
                
                if (length > 0) 
                {
                    bfr[length] = '\0';         
                    if(EDBG)
                    {
                        SYS_CONSOLE_PRINT("[tcp_app] Recieved  size %d\r\n", length);
                        //SYS_CONSOLE_PRINT("[tcp_app] Recieved '%s' size %d\r\n", bfr, length);
                        /*
                        SYS_CONSOLE_PRINT("--------------------[ASCII]--------------------\r\n");
                        for (i = 0; i < length; i++)
                        {
                            SYS_CONSOLE_PRINT("0x%02x ", bfr[i]);
                            if (((i+1) % 10 == 0) || (i == length-1))
                                SYS_CONSOLE_PRINT("\r\n");
                        }
                        SYS_CONSOLE_PRINT("--------------------------------------------------\r\n");     
                        */           
                    }  
                    if(Ethernet_Protocol)//102
                    {
                        flag_addr=0;
                        //SYS_CONSOLE_PRINT("'%s'\r\n", bfr);
                        //for (i = 0+2; i < length-4; i++) 
                        for (i = 0+2; i < length-2; i++)
                        {                            
                            if ((i+6) % 8 == 0)
                                ch1=CharToInt(bfr[i]);
                            else if ((i+5) % 8 == 0)
                                ch2=CharToInt(bfr[i]);
                            else if ((i+4) % 8 == 0)
                                ch3=CharToInt(bfr[i]);
                            else if ((i+3) % 8 == 0)
                                ch4=CharToInt(bfr[i]);
                            else if ((i+2) % 8 == 0)
                                ch5=CharToInt(bfr[i]);
                            else if ((i+1) % 8 == 0)
                                ch6=CharToInt(bfr[i]);
                            else if ((i) % 8 == 0)
                                ch7=CharToInt(bfr[i]);
                            else if ((i+7) % 8 == 0)
                            {
                                ch8=CharToInt(bfr[i]);
                                if (EDBG)
                                    SYS_CONSOLE_PRINT("[0x%02x] =[0x%02x][0x%02x][0x%02x][0x%02x][0x%02x][0x%02x][0x%02x][0x%02x]\r\n ",flag_addr,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8);
                                else
                                {
                                    LCW_8Channel(lcw_address[flag_addr],lcw_ch_value[ch1],lcw_ch_value[ch2],lcw_ch_value[ch3],lcw_ch_value[ch4],lcw_ch_value[ch5],lcw_ch_value[ch6],lcw_ch_value[ch7],lcw_ch_value[ch8]);
                                }
                                flag_addr++;
                                ch1=0;ch2=0;ch3=0;ch4=0;ch5=0;ch6=0;ch7=0;ch8=0;
                            }
                        }
                    }
                    // Check HTTP method
                    if (strncmp(bfr, "POST", 4) != 0)
                        continue;          
                    // Get HTTP request body
                    char * reqBody = get_ip_request_body(bfr);
                    if (reqBody == NULL) 
                        continue;                    
                    // Parse command type
                    Message msg = ip_ctrl_request_to_message(reqBody);
                    // Handle command
                    if (msg.cmdType == CANNOT_BE_PARSE) {
                        // Do not resposne those what can't be parse
                        continue;
                    } else if (msg.cmdType == CMD_TYPE_INVALID || msg.valueType == VAL_TYPE_INVALID){
                        // Response to IP endpoint that the command type is invalid
                        char * resBody = ip_ctrl_response_body(false);
                        char * resHeader = ip_ctrl_response_header(strlen(resBody));
                        // Combine the response header and body
                        char * response = malloc(strlen(resHeader) + strlen(resBody) + 1);
                        strcpy(response, resHeader);
                        free(resHeader);
                        strcat(response, resBody);
                        free(resBody);
                        strcat(response, "\0");

                        send(tcpAppData.ClientSock[i], response, strlen(response), 0);
                        free(response);
                    } else {
                        // send to UART queue
                        if (xQueueSend(queue_IP_UART, &msg, ( TickType_t ) 10 ) != pdPASS) {
                            // message didn't pass to uart task successfully
                            SYS_CONSOLE_PRINT("IP -> UART: Failed...");
                        }
                    }              
                } else if (length == 0 || errno != EWOULDBLOCK) {
                    closesocket(tcpAppData.ClientSock[i]);
                    tcpAppData.ClientSock[i] = INVALID_SOCKET;
                    setHostListByIndex(i, tcpAppData.ClientSock[i]);
                }
            }
        }
            break;
        default:
            break;
    }
}
/*******************************************************************************
 End of File
 */
