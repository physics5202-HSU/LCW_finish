/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    rs232_app.c

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
#include "string.h"
#include "rs232_app.h"
#include "configuration.h"
#include "peripheral/sercom/usart/plib_sercom5_usart.h"
#include "system/console/sys_console.h"
#include "com_lib.h"
#include "uart_command.h"
#include "Judgeman.h"
#include "eeprom.h"
#include "stdlib.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
//static idata UCHAR ucUART2TxOut;
//static idata UCHAR ucUART2TxIn;
//static idata UCHAR ucUART2RxOut;
//static idata UCHAR ucUART2RxIn;
//void *ucre232RxBuffer;
//void *ucrs232TxBuffer;
#define RS232_RX_BUFFER_SIZE 10

//uint8_t ucRS232RxBuffer[RS232_RX_BUFFER_SIZE];
//uint8_t ucre232RxCMDBuffer[re232RxBufferSize];
uint8_t* ucrs232TxBuffer;
extern xQueueHandle queue_RS232_UART;
extern xQueueHandle queue_UART_RS232;
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the RS232_APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

RS232_APP_DATA rs232_appData;
#if 0
unsigned char OutdoorCommandTab[Outdoor_CMD_NUM][Outdoor_CMD_LEN] = {                               //TOTAL SUPPORT TV WALL COMMAND TABLE
{"MAC"}, {"SNW"}, {"SNR"}, {"MOD"}, {"DCP"}, {"LIP"}, {"GAT"}, {"MSK"}, {"DNS"}, {"HST"},      //0~9
{"HTS"}, {"RMT"}, {"SDP"}, {"UDP"}, {"PWD"}, {"INP"}, {"VOL"}, {"MUT"}, {"CHA"}, {"SEN"},      //10~19
{"LTA"}, {"LTB"}, {"HOE"}, {"HTP"}, {"LTP"},                                                               //20~24
};
#endif
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
//void INX_UART_Handler(void)
//{
//    SERCOM5_USART_Read( void *buffer, const size_t size );
//}
void handleMsgFrom_MCU_ESP32(Message msg)
{
    switch (msg.cmdType) 
    {
        case CMD_HMI_RX_Error:
            HMI_RX_Error();
            //MCU_TX_PAD("tm0.en=1");
            //MCU_TX_PAD("r01l.bco=65535");
            uint16_t _ALS=ALS_Read(ALS_1_CTRL_ADDR);
            if ((_ALS != 0xFFFF) && (_ALS != 0x0000))
            {
                char v_cmd_h[20]="ALS=";
                char v_cmd[20];
                MCU_TX_ESP32(false,strcat(v_cmd_h, IntToChar(_ALS,v_cmd, 10)));
            }            
            break;
        case CMD_TYPE_ALP:
            break;
        default:
            break;
    }
}
void INX_RS232_Handler(void)
{
    SYS_CONSOLE_PRINT("INX_RS232_Handler\r\n");
    Message msg;
    Message msg1;
    uint8_t abc[3];
    size_t RS232RxBufferSize = SERCOM5_USART_ReadCountGet();
    uint8_t *ucRS232RxBuffer = calloc(RS232RxBufferSize , sizeof(size_t));
    SERCOM5_USART_Read( ucRS232RxBuffer, RS232RxBufferSize );    
    msg = parsingCommand(ucRS232RxBuffer,RS232RxBufferSize);
    SYS_CONSOLE_PRINT("ucre232RxBuffer0: %d\r\n", msg.cmdType);
    SYS_CONSOLE_PRINT("RS232RxBufferSize: %d\r\n", RS232RxBufferSize);    
    
    if(msg.cmdType >= 67)//do something from ESP32
    {
        handleMsgFrom_MCU_ESP32(msg);
    }    
    
    if (xQueueSend(queue_RS232_UART, &msg, ( TickType_t ) 10 ) != pdPASS) {
        // message didn't pass to uart task successfully
        SYS_CONSOLE_PRINT("RS232 -> UART: Failed...");
    } 
    if (xQueueReceive(queue_UART_RS232, &msg1, (TickType_t) 0) == pdTRUE) {
        abc[0] = 'o';
        abc[1] = 'k';
        abc[2] = '\0';
        SERCOM5_USART_Write(abc, 3 );
    }
    free(ucRS232RxBuffer);
}
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
    void RS232_APP_Initialize ( void )

  Remarks:
    See prototype in rs232_app.h.
 */

void RS232_APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    rs232_appData.state = RS232_APP_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void RS232_APP_Tasks ( void )

  Remarks:
    See prototype in rs232_app.h.
 */

void RS232_APP_Tasks ( void )
{
    /* Check the application's current state. */
    //SYS_CONSOLE_MESSAGE("RS232_APP_Tasks!\r\n");
    switch ( rs232_appData.state )
    {
        /* Application's initial state. */
        case RS232_APP_STATE_INIT:
        {
            bool appInitialized = true;
            if (appInitialized)
            {

                rs232_appData.state = RS232_APP_STATE_SERVICE_TASKS;
            }
            break;
        }
        case RS232_APP_STATE_SERVICE_TASKS:
        {
            if(SERCOM5_USART_ReadCountGet()>0)
            {    
                INX_RS232_Handler();
            }
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
