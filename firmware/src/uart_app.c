/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    uart_app.c

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

#include "uart_app.h"
#include "configuration.h"

#include "com_lib.h"
#include "uart_command.h"
#include "Judgeman.h"
#include "eeprom.h"
#include "mcp9800.h"
#include "OLED12864.h"
#include "adc.h"
uint8_t hmi_value[7]={138,147,150,154,161,177,248};
extern EEPROMData EEDataDefault;
extern EEPROMData EEData;
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
    This structure should be initialized by the UART_APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

UART_APP_DATA uart_appData;
ADC0_STATUS adc0_data;

extern xQueueHandle queue_UART_IP;
extern xQueueHandle queue_IP_UART;
extern xQueueHandle queue_RS232_UART;
extern xQueueHandle queue_UART_RS232;
#if 0
unsigned char OutdoorCommandTab[Outdoor_CMD_NUM][Outdoor_CMD_LEN] = {//TOTAL SUPPORT TV WALL COMMAND TABLE
    {"MAC"},
    {"SNW"},
    {"SNR"},
    {"MOD"},
    {"DCP"},
    {"LIP"},
    {"GAT"},
    {"MSK"},
    {"DNS"},
    {"HST"}, //0~9
    {"HTS"},
    {"RMT"},
    {"SDP"},
    {"UDP"},
    {"PWD"},
    {"INP"},
    {"VOL"},
    {"MUT"},
    {"CHA"},
    {"SEN"}, //10~19
    {"LTA"},
    {"LTB"},
    {"HOE"},
    {"HTP"},
    {"LTP"}, //20~24
};
#endif
float   TempC_ts1;
uint8_t neg_ts1 = 0;
int count_delay=0;
int count_check=0;
int GPIO_PC22_PreStatus=1;
int GPIO_PC22_ButtonStatus=0;
int *lcw_uart=0;
uint8_t v_bright[2]={138,248};
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

void INX_UART2_Handler(void) {
}

void INX_UART4_Handler(void) {
}

char * msgToCmdString(char * cmdTypeStr, Message msg) {

    // Turn value into string
    char *value;
    switch (msg.valueType) {
        case VAL_TYPE_STR:
            if ((value = calloc(strlen(msg.Value.value_s), sizeof (char))) != NULL)
                strcpy(value, msg.Value.value_s);
            else
                return NULL;
            break;
        case VAL_TYPE_CHAR:
            if ((value = calloc(2, sizeof (char))) != NULL) {
                value[0] = msg.Value.value_c;
                value[1] = '\0';
            } else {
                return NULL;
            }
            break;
        case VAL_TYPE_NUM:
            if ((value = calloc(countDigitsOfInt(msg.Value.value_n) + 1, sizeof (char))) != NULL)
                sprintf(value, "%d", msg.Value.value_n);
            else
                return NULL;
            break;
        case VAL_TYPE_IP_ADDR:
        {
            uint8_t strLength = countDigitsOfInt(msg.Value.value_ip_addr[0]) +
                    countDigitsOfInt(msg.Value.value_ip_addr[1]) +
                    countDigitsOfInt(msg.Value.value_ip_addr[2]) +
                    countDigitsOfInt(msg.Value.value_ip_addr[3]) + 4; // 3 dots and NUL = 4
            if ((value = calloc(strLength, sizeof (char))) != NULL)
                sprintf(value, "%d.%d.%d.%d", msg.Value.value_ip_addr[0],
                    msg.Value.value_ip_addr[1],
                    msg.Value.value_ip_addr[2],
                    msg.Value.value_ip_addr[3]);
            else
                return NULL;
            break;
        }
        case VAL_TYPE_MAC_ADDR:
            if ((value = calloc(18, sizeof (char))) != NULL) // 66.0D.9E.C9.4A.B9 and NUL = 18
                sprintf(value, "%x.%x.%x.%x.%x.%x", msg.Value.value_mac_addr[0],
                    msg.Value.value_mac_addr[1],
                    msg.Value.value_mac_addr[2],
                    msg.Value.value_mac_addr[3],
                    msg.Value.value_mac_addr[4],
                    msg.Value.value_mac_addr[5]);
            else
                return NULL;
            break;
        case VAL_TYPE_CHANNEL:
            if ((value = calloc(countDigitsOfInt(msg.Value.value_channel[0] + 1 +
                    msg.Value.value_channel[1]) + 1, sizeof (char))) != NULL)
                sprintf(value, "%d.%d", msg.Value.value_channel[0], msg.Value.value_channel[1]);
            else
                return NULL;
            break;
        default:
            return NULL;
    }

    // Concat command and value with necessary symbols
    char *result;
    if ((result = calloc(strlen(cmdTypeStr) + strlen(value) + 2, sizeof (char))) != NULL) { // ':' and NUL
        strcat(result, cmdTypeStr);
        strcat(result, ":");
        strcat(result, value);
    }
    free(value);
    return result;
}

void sendToQueueOf(MSG_SOURCE msgSrc, Message *msgTx) {
    if (msgSrc == MSG_SOURCE_RS232) {
        xQueueSend(queue_UART_RS232, msgTx, (TickType_t) 10);
    } else if (msgSrc == MSG_SOURCE_IP) {
        xQueueSend(queue_UART_IP, msgTx, (TickType_t) 10);
    }
}

void sendToSoCAndFreeIfNotNull(char * cmdStr) {
    if (cmdStr != NULL) {
        SERCOM0_USART_Write((uint8_t*) cmdStr, strlen(cmdStr));
        free(cmdStr);
    }
}

bool isResponseWithValueOne(Message *msg) {
    return msg->msgType == MSG_TYPE_RESPONSE 
            && msg->valueType == VAL_TYPE_NUM 
            && msg->Value.value_n == 1;
}

bool isRequestIpCmdWithValueOne(MSG_SOURCE msgSrc, Message *msg) {
    return msgSrc == MSG_SOURCE_IP
            && msg->msgType == MSG_TYPE_REQUEST
            && msg->valueType == VAL_TYPE_NUM 
            && msg->Value.value_n == 1;
}
void handleMsgFromSoC(Message msg) {
    if (msg.msgType == MSG_TYPE_INVALID){
        //SYS_CONSOLE_MESSAGE("MSG_TYPE_INVALID!\r\n");
        return;
    }
    if (msg.cmdType == CMD_TYPE_INVALID){
        if(EDBG)
            SYS_CONSOLE_MESSAGE("CMD_TYPE_INVALID!\r\n");
        return;
    }
    if (msg.cmdType == CANNOT_BE_PARSE){
        if(EDBG)
            SYS_CONSOLE_MESSAGE("CANNOT_BE_PARSE!\r\n");
        return;
    }
    if (msg.valueType == VAL_TYPE_INVALID){
        //SYS_CONSOLE_MESSAGE("VAL_TYPE_INVALID!\r\n");
        return;
    }
    switch (msg.cmdType) {
        case CMD_HMI_Mode_Show:
            LCW_DefaultValue();
            if(EDBG)
                SYS_CONSOLE_MESSAGE("CMD_HMI_Mode_Show!\r\n");
            else
            {
                LCW_Demo(Driving_Board_1_CTRL_ADDR);    LCW_Demo(Driving_Board_2_CTRL_ADDR);    LCW_Demo(Driving_Board_3_CTRL_ADDR);    LCW_Demo(Driving_Board_4_CTRL_ADDR);
                LCW_Demo(Driving_Board_5_CTRL_ADDR);    LCW_Demo(Driving_Board_6_CTRL_ADDR);    LCW_Demo(Driving_Board_7_CTRL_ADDR);    LCW_Demo(Driving_Board_8_CTRL_ADDR);
                LCW_Demo(Driving_Board_9_CTRL_ADDR);    LCW_Demo(Driving_Board_10_CTRL_ADDR);   LCW_Demo(Driving_Board_11_CTRL_ADDR);   LCW_Demo(Driving_Board_12_CTRL_ADDR);
                LCW_Demo(Driving_Board_13_CTRL_ADDR);   LCW_Demo(Driving_Board_14_CTRL_ADDR);
            }
            break;          
        case CMD_HMI_Mode_ALS:
            if(EDBG)
                SYS_CONSOLE_MESSAGE("CMD_HMI_Mode_ALS!\r\n");//ToDO
            break;
        case CMD_HMI_Mode_Manual:
            LCW_DefaultValue();
            if(EDBG)
                SYS_CONSOLE_MESSAGE("CMD_HMI_Mode_Manual!\r\n");
            else
            {
                LCW_Manual(Driving_Board_1_CTRL_ADDR);    LCW_Manual(Driving_Board_2_CTRL_ADDR);    LCW_Manual(Driving_Board_3_CTRL_ADDR);    LCW_Manual(Driving_Board_4_CTRL_ADDR);
                LCW_Manual(Driving_Board_5_CTRL_ADDR);    LCW_Manual(Driving_Board_6_CTRL_ADDR);    LCW_Manual(Driving_Board_7_CTRL_ADDR);    LCW_Manual(Driving_Board_8_CTRL_ADDR);
                LCW_Manual(Driving_Board_9_CTRL_ADDR);    LCW_Manual(Driving_Board_10_CTRL_ADDR);   LCW_Manual(Driving_Board_11_CTRL_ADDR);   LCW_Manual(Driving_Board_12_CTRL_ADDR);
                LCW_Manual(Driving_Board_13_CTRL_ADDR);   LCW_Manual(Driving_Board_14_CTRL_ADDR);
            }
            break;
        case CMD_LCW_Show:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_LCW_Show!\r\n");
            }
            else
            {
                if(msg._PresentDrivingBoard == db1)
                    LCW_8Channel(Driving_Board_1_CTRL_ADDR,hmi_value[msg._D1C1],hmi_value[msg._D1C2],hmi_value[msg._D1C3],hmi_value[msg._D1C4],hmi_value[msg._D1C5],hmi_value[msg._D1C6],hmi_value[msg._D1C7],hmi_value[msg._D1C8]);
                else if(msg._PresentDrivingBoard == db2)
                    LCW_8Channel(Driving_Board_2_CTRL_ADDR,hmi_value[msg._D2C1],hmi_value[msg._D2C2],hmi_value[msg._D2C3],hmi_value[msg._D2C4],hmi_value[msg._D2C5],hmi_value[msg._D2C6],hmi_value[msg._D2C7],hmi_value[msg._D2C8]);
                else if(msg._PresentDrivingBoard == db3)
                    LCW_8Channel(Driving_Board_3_CTRL_ADDR,hmi_value[msg._D3C1],hmi_value[msg._D3C2],hmi_value[msg._D3C3],hmi_value[msg._D3C4],hmi_value[msg._D3C5],hmi_value[msg._D3C6],hmi_value[msg._D3C7],hmi_value[msg._D3C8]);
                else if(msg._PresentDrivingBoard == db4)
                    LCW_8Channel(Driving_Board_4_CTRL_ADDR,hmi_value[msg._D4C1],hmi_value[msg._D4C2],hmi_value[msg._D4C3],hmi_value[msg._D4C4],hmi_value[msg._D4C5],hmi_value[msg._D4C6],hmi_value[msg._D4C7],hmi_value[msg._D4C8]);
                else if(msg._PresentDrivingBoard == db5)
                    LCW_8Channel(Driving_Board_5_CTRL_ADDR,hmi_value[msg._D5C1],hmi_value[msg._D5C2],hmi_value[msg._D5C3],hmi_value[msg._D5C4],hmi_value[msg._D5C5],hmi_value[msg._D5C6],hmi_value[msg._D5C7],hmi_value[msg._D5C8]);
                else if(msg._PresentDrivingBoard == db6)
                    LCW_8Channel(Driving_Board_6_CTRL_ADDR,hmi_value[msg._D6C1],hmi_value[msg._D6C2],hmi_value[msg._D6C3],hmi_value[msg._D6C4],hmi_value[msg._D6C5],hmi_value[msg._D6C6],hmi_value[msg._D6C7],hmi_value[msg._D6C8]);
                else if(msg._PresentDrivingBoard == db7)
                    LCW_8Channel(Driving_Board_7_CTRL_ADDR,hmi_value[msg._D7C1],hmi_value[msg._D7C2],hmi_value[msg._D7C3],hmi_value[msg._D7C4],hmi_value[msg._D7C5],hmi_value[msg._D7C6],hmi_value[msg._D7C7],hmi_value[msg._D7C8]);
                else if(msg._PresentDrivingBoard == db8)
                    LCW_8Channel(Driving_Board_8_CTRL_ADDR,hmi_value[msg._D8C1],hmi_value[msg._D8C2],hmi_value[msg._D8C3],hmi_value[msg._D8C4],hmi_value[msg._D8C5],hmi_value[msg._D8C6],hmi_value[msg._D8C7],hmi_value[msg._D8C8]);
                else if(msg._PresentDrivingBoard == db9)
                    LCW_8Channel(Driving_Board_9_CTRL_ADDR,hmi_value[msg._D9C1],hmi_value[msg._D9C2],hmi_value[msg._D9C3],hmi_value[msg._D9C4],hmi_value[msg._D9C5],hmi_value[msg._D9C6],hmi_value[msg._D9C7],hmi_value[msg._D9C8]);
                else if(msg._PresentDrivingBoard == db10)
                    LCW_8Channel(Driving_Board_10_CTRL_ADDR,hmi_value[msg._D10C1],hmi_value[msg._D10C2],hmi_value[msg._D10C3],hmi_value[msg._D10C4],hmi_value[msg._D10C5],hmi_value[msg._D10C6],hmi_value[msg._D10C7],hmi_value[msg._D10C8]);
                else if(msg._PresentDrivingBoard == db11)
                    LCW_8Channel(Driving_Board_11_CTRL_ADDR,hmi_value[msg._D11C1],hmi_value[msg._D11C2],hmi_value[msg._D11C3],hmi_value[msg._D11C4],hmi_value[msg._D11C5],hmi_value[msg._D11C6],hmi_value[msg._D11C7],hmi_value[msg._D11C8]);
                else if(msg._PresentDrivingBoard == db12)
                    LCW_8Channel(Driving_Board_12_CTRL_ADDR,hmi_value[msg._D12C1],hmi_value[msg._D12C2],hmi_value[msg._D12C3],hmi_value[msg._D12C4],hmi_value[msg._D12C5],hmi_value[msg._D12C6],hmi_value[msg._D12C7],hmi_value[msg._D12C8]);
                else if(msg._PresentDrivingBoard == db13)
                    LCW_8Channel(Driving_Board_13_CTRL_ADDR,hmi_value[msg._D13C1],hmi_value[msg._D13C2],hmi_value[msg._D13C3],hmi_value[msg._D13C4],hmi_value[msg._D13C5],hmi_value[msg._D13C6],hmi_value[msg._D13C7],hmi_value[msg._D13C8]);
                else if(msg._PresentDrivingBoard == db14)
                    LCW_8Channel(Driving_Board_14_CTRL_ADDR,hmi_value[msg._D14C1],hmi_value[msg._D14C2],hmi_value[msg._D14C3],hmi_value[msg._D14C4],hmi_value[msg._D14C5],hmi_value[msg._D14C6],hmi_value[msg._D14C7],hmi_value[msg._D14C8]);
            }
            break;
        case CMD_LCW_ShowAll:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_LCW_Show!\r\n");
            }
            else
            {
                if(driv_board[0] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[0] = %x\r\n", driv_board[0]);
                    LCW_8Channel(Driving_Board_1_CTRL_ADDR,hmi_value[msg._D1C1],hmi_value[msg._D1C2],hmi_value[msg._D1C3],hmi_value[msg._D1C4],hmi_value[msg._D1C5],hmi_value[msg._D1C6],hmi_value[msg._D1C7],hmi_value[msg._D1C8]);
                    driv_board[0] = 0;
                }
                if(driv_board[1] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[1] = %x\r\n", driv_board[1]);                
                    LCW_8Channel(Driving_Board_2_CTRL_ADDR,hmi_value[msg._D2C1],hmi_value[msg._D2C2],hmi_value[msg._D2C3],hmi_value[msg._D2C4],hmi_value[msg._D2C5],hmi_value[msg._D2C6],hmi_value[msg._D2C7],hmi_value[msg._D2C8]);
                    driv_board[1] = 0;
                }
                if(driv_board[2] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[2] = %x\r\n", driv_board[2]);                
                    LCW_8Channel(Driving_Board_3_CTRL_ADDR,hmi_value[msg._D3C1],hmi_value[msg._D3C2],hmi_value[msg._D3C3],hmi_value[msg._D3C4],hmi_value[msg._D3C5],hmi_value[msg._D3C6],hmi_value[msg._D3C7],hmi_value[msg._D3C8]);
                    driv_board[2] = 0;
                }
                if(driv_board[3] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[3] = %x\r\n", driv_board[3]);
                    LCW_8Channel(Driving_Board_4_CTRL_ADDR,hmi_value[msg._D4C1],hmi_value[msg._D4C2],hmi_value[msg._D4C3],hmi_value[msg._D4C4],hmi_value[msg._D4C5],hmi_value[msg._D4C6],hmi_value[msg._D4C7],hmi_value[msg._D4C8]);
                    driv_board[3] = 0;
                }
                if(driv_board[4] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[4] = %x\r\n", driv_board[4]);
                    LCW_8Channel(Driving_Board_5_CTRL_ADDR,hmi_value[msg._D5C1],hmi_value[msg._D5C2],hmi_value[msg._D5C3],hmi_value[msg._D5C4],hmi_value[msg._D5C5],hmi_value[msg._D5C6],hmi_value[msg._D5C7],hmi_value[msg._D5C8]);
                    driv_board[4] = 0;
                }
                if(driv_board[5] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[5] = %x\r\n", driv_board[5]);
                    LCW_8Channel(Driving_Board_6_CTRL_ADDR,hmi_value[msg._D6C1],hmi_value[msg._D6C2],hmi_value[msg._D6C3],hmi_value[msg._D6C4],hmi_value[msg._D6C5],hmi_value[msg._D6C6],hmi_value[msg._D6C7],hmi_value[msg._D6C8]);
                    driv_board[5] = 0;
                }
                if(driv_board[6] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[6] = %x\r\n", driv_board[6]);                    
                    LCW_8Channel(Driving_Board_7_CTRL_ADDR,hmi_value[msg._D7C1],hmi_value[msg._D7C2],hmi_value[msg._D7C3],hmi_value[msg._D7C4],hmi_value[msg._D7C5],hmi_value[msg._D7C6],hmi_value[msg._D7C7],hmi_value[msg._D7C8]);
                    driv_board[6] = 0;
                }
                if(driv_board[7] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[7] = %x\r\n", driv_board[7]);                    
                    LCW_8Channel(Driving_Board_8_CTRL_ADDR,hmi_value[msg._D8C1],hmi_value[msg._D8C2],hmi_value[msg._D8C3],hmi_value[msg._D8C4],hmi_value[msg._D8C5],hmi_value[msg._D8C6],hmi_value[msg._D8C7],hmi_value[msg._D8C8]);
                    driv_board[7] = 0;
                }
                if(driv_board[8] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[8] = %x\r\n", driv_board[8]);
                    LCW_8Channel(Driving_Board_9_CTRL_ADDR,hmi_value[msg._D9C1],hmi_value[msg._D9C2],hmi_value[msg._D9C3],hmi_value[msg._D9C4],hmi_value[msg._D9C5],hmi_value[msg._D9C6],hmi_value[msg._D9C7],hmi_value[msg._D9C8]);
                    driv_board[8] = 0;
                }
                if(driv_board[9] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[9] = %x\r\n", driv_board[9]);
                    LCW_8Channel(Driving_Board_10_CTRL_ADDR,hmi_value[msg._D10C1],hmi_value[msg._D10C2],hmi_value[msg._D10C3],hmi_value[msg._D10C4],hmi_value[msg._D10C5],hmi_value[msg._D10C6],hmi_value[msg._D10C7],hmi_value[msg._D10C8]);
                    driv_board[9] = 0;
                }
                if(driv_board[10] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[10] = %x\r\n", driv_board[10]);
                    LCW_8Channel(Driving_Board_11_CTRL_ADDR,hmi_value[msg._D11C1],hmi_value[msg._D11C2],hmi_value[msg._D11C3],hmi_value[msg._D11C4],hmi_value[msg._D11C5],hmi_value[msg._D11C6],hmi_value[msg._D11C7],hmi_value[msg._D11C8]);
                    driv_board[10] = 0;
                }
                if(driv_board[11] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[11] = %x\r\n", driv_board[11]);
                    LCW_8Channel(Driving_Board_12_CTRL_ADDR,hmi_value[msg._D12C1],hmi_value[msg._D12C2],hmi_value[msg._D12C3],hmi_value[msg._D12C4],hmi_value[msg._D12C5],hmi_value[msg._D12C6],hmi_value[msg._D12C7],hmi_value[msg._D12C8]);
                    driv_board[11] = 0;
                }
                if(driv_board[12] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[12] = %x\r\n", driv_board[12]);
                    LCW_8Channel(Driving_Board_13_CTRL_ADDR,hmi_value[msg._D13C1],hmi_value[msg._D13C2],hmi_value[msg._D13C3],hmi_value[msg._D13C4],hmi_value[msg._D13C5],hmi_value[msg._D13C6],hmi_value[msg._D13C7],hmi_value[msg._D13C8]);
                    driv_board[12] = 0;
                }
                if(driv_board[13] == 1){
                    //SYS_CONSOLE_PRINT("driv_board[13] = %x\r\n", driv_board[13]);
                    LCW_8Channel(Driving_Board_14_CTRL_ADDR,hmi_value[msg._D14C1],hmi_value[msg._D14C2],hmi_value[msg._D14C3],hmi_value[msg._D14C4],hmi_value[msg._D14C5],hmi_value[msg._D14C6],hmi_value[msg._D14C7],hmi_value[msg._D14C8]);
                    driv_board[13] = 0;
                    }
            }
            break;              
        case CMD_HMI_Mode_Reset:
            LCW_DefaultValue();
            if(EDBG)
                SYS_CONSOLE_MESSAGE("CMD_HMI_Mode_Reset!\r\n");
            else
            {
                LCW_Brightness(Driving_Board_1_CTRL_ADDR,hmi_value[0]);    LCW_Brightness(Driving_Board_2_CTRL_ADDR,hmi_value[0]);    
                LCW_Brightness(Driving_Board_3_CTRL_ADDR,hmi_value[0]);    LCW_Brightness(Driving_Board_4_CTRL_ADDR,hmi_value[0]);
                LCW_Brightness(Driving_Board_5_CTRL_ADDR,hmi_value[0]);    LCW_Brightness(Driving_Board_6_CTRL_ADDR,hmi_value[0]);    
                LCW_Brightness(Driving_Board_7_CTRL_ADDR,hmi_value[0]);    LCW_Brightness(Driving_Board_8_CTRL_ADDR,hmi_value[0]);
                LCW_Brightness(Driving_Board_9_CTRL_ADDR,hmi_value[0]);    LCW_Brightness(Driving_Board_10_CTRL_ADDR,hmi_value[0]);   
                LCW_Brightness(Driving_Board_11_CTRL_ADDR,hmi_value[0]);   LCW_Brightness(Driving_Board_12_CTRL_ADDR,hmi_value[0]);
                LCW_Brightness(Driving_Board_13_CTRL_ADDR,hmi_value[0]);   LCW_Brightness(Driving_Board_14_CTRL_ADDR,hmi_value[0]);  
                MCU_TX_PAD("green.en=1");
            }
            break;
        case CMD_TYPE_ALP:
            break;
        case CMD_TYPE_ALS:
            break;
        case CMD_TYPE_ALT:
            break;
        case CMD_TYPE_ALW:
            break;

        case CMD_TYPE_CHA:
            if (msg.msgType == MSG_TYPE_RESPONSE && msg.valueType == VAL_TYPE_CHANNEL) {
                xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
                xQueueSend(queue_UART_IP, &msg, (TickType_t) 10);
                setChannel(msg.Value.value_channel);
            }
            break;

        case CMD_TYPE_DCP:
            if (msg.valueType != VAL_TYPE_NUM)
                break;
            
            // Execute command
            if (msg.Value.value_n == 1)
                enableDHCP();
            else
                disableDHCP();
            
            setDhcpSS(msg.Value.value_n);
            
            if (msg.msgType == MSG_TYPE_RESPONSE) {
                // Reply to the source
                xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
            } else if (msg.msgType == MSG_TYPE_REQUEST) {
                // Reply to the SoC
                msg.msgType = MSG_TYPE_RESPONSE;
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_DCP, msg));
            }
            break;
        case CMD_TYPE_DIP:
            break;
        case CMD_TYPE_DNS:
            if (msg.valueType != VAL_TYPE_IP_ADDR)
                break;
            
            if (msg.msgType == MSG_TYPE_RESPONSE) {
                if (setDnsServer(msg.Value.value_ip_addr)) {
                    setDnsAddrSS(msg.Value.value_ip_addr);
                    // Reply to the source
                    xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
                }
            } else if (msg.msgType == MSG_TYPE_REQUEST) {
                setDnsAddrSS(msg.Value.value_ip_addr);
                // Reply to the SoC
                msg.msgType = MSG_TYPE_RESPONSE;
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_DNS, msg));
            }
            break;
        case CMD_TYPE_DT1:
            break;
        case CMD_TYPE_DT2:
            break;
        case CMD_TYPE_DT3:
            break;
        case CMD_TYPE_DT4:
            break;
        case CMD_TYPE_DT5:
            break;

        case CMD_TYPE_FAA:
            break;
        case CMD_TYPE_FAN:
            break;
        case CMD_TYPE_FAT:
            break;

        case CMD_TYPE_GAT:
            if (msg.valueType != VAL_TYPE_IP_ADDR)
                break;
            
            if (msg.msgType == MSG_TYPE_RESPONSE) {
                if (setGateway(msg.Value.value_ip_addr)) {
                    setGatewayAddrSS(msg.Value.value_ip_addr);
                    // Reply to the source
                    xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
                }
            } else if (msg.msgType == MSG_TYPE_REQUEST) {
                setGatewayAddrSS(msg.Value.value_ip_addr);
                // Reply to the SoC
                msg.msgType = MSG_TYPE_RESPONSE;
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_GAT, msg));
            }
            break;

        case CMD_TYPE_HET:
            break;
        case CMD_TYPE_HOE:
            break;
        case CMD_TYPE_HOT:
            break;
        case CMD_TYPE_HST:
            break;
        case CMD_TYPE_HTP:
            break;
        case CMD_TYPE_HTR:
            break;
        case CMD_TYPE_HTS:
            break;
        case CMD_TYPE_HTT:
            break;
        case CMD_TYPE_HTW:
            break;
        case CMD_TYPE_INF:
        {
            // shouldn't be run, no-op
            break;
        }
        case CMD_TYPE_INP:
            if (msg.msgType == MSG_TYPE_RESPONSE && msg.valueType == VAL_TYPE_NUM) {
                xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
                xQueueSend(queue_UART_IP, &msg, (TickType_t) 10);
                setInput(msg.Value.value_n);
            }
            break;
        case CMD_TYPE_IPT:
            break;
        case CMD_TYPE_IRM:
            break;
        case CMD_TYPE_IRT:
            break;

        case CMD_TYPE_LIP:
            if (msg.valueType != VAL_TYPE_IP_ADDR)
                break;
            
            if (msg.msgType == MSG_TYPE_RESPONSE) {
                if (setIPAddress(msg.Value.value_ip_addr)) {
                    setIpAddressSS(msg.Value.value_ip_addr);
                    // Reply to the source
                    xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
                }
            } else if (msg.msgType == MSG_TYPE_REQUEST) {
                setIpAddressSS(msg.Value.value_ip_addr);
                // Reply to the SoC
                msg.msgType = MSG_TYPE_RESPONSE;
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_LIP, msg));
            }
            break;
        case CMD_TYPE_LTA:
            break;
        case CMD_TYPE_LTB:
            break;
        case CMD_TYPE_LTP:
            break;

        case CMD_TYPE_MAC:
            if (msg.valueType != VAL_TYPE_MAC_ADDR)
                break;
            
            if (msg.msgType == MSG_TYPE_RESPONSE) {
                if (setMacAddress(msg.Value.value_mac_addr)) {
                    setMacAddressSS(msg.Value.value_mac_addr);
                    // Reply to the source
                    xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
                }
            } else if (msg.msgType == MSG_TYPE_REQUEST) {
                setMacAddressSS(msg.Value.value_mac_addr);
                // Reply to the SoC
                msg.msgType = MSG_TYPE_RESPONSE;
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_MAC, msg));
            }
            break;
        case CMD_TYPE_MOD:
            if (msg.msgType == MSG_TYPE_RESPONSE && msg.valueType == VAL_TYPE_STR) {
                setModelName(msg.Value.value_s);
                // Reply to the source
                xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
            }
            break;
        case CMD_TYPE_MSK:
            if (msg.valueType != VAL_TYPE_IP_ADDR)
                break;
            
            if (msg.msgType == MSG_TYPE_RESPONSE) {
                if (setSubMask(msg.Value.value_ip_addr)) {
                    setSubMaskSS(msg.Value.value_ip_addr);
                    // Reply to the source
                    xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
                }
            } else if (msg.msgType == MSG_TYPE_REQUEST) {
                setSubMaskSS(msg.Value.value_ip_addr);
                // Reply to the SoC
                msg.msgType = MSG_TYPE_RESPONSE;
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_MSK, msg));
            }
            break;
        case CMD_TYPE_MUT:
            if (msg.msgType == MSG_TYPE_RESPONSE && msg.valueType == VAL_TYPE_NUM) {
                xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
                xQueueSend(queue_UART_IP, &msg, (TickType_t) 10);
                setMute(msg.Value.value_n);
            }
            break;

        case CMD_TYPE_PSN:
            break;
        case CMD_TYPE_PWD:
            if (msg.msgType == MSG_TYPE_RESPONSE && msg.valueType == VAL_TYPE_NUM) {
                xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
                xQueueSend(queue_UART_IP, &msg, (TickType_t) 10);
                setPower(msg.Value.value_n);
            }
            break;
        case CMD_TYPE_PWT:
            break;
        case CMD_TYPE_RES:
            break;
        case CMD_TYPE_RFL:
            break;
        case CMD_TYPE_RMT:
            break;
        case CMD_TYPE_RNU:
            if (msg.msgType == MSG_TYPE_RESPONSE && msg.valueType == VAL_TYPE_NUM)
                xQueueSend(queue_UART_IP, &msg, (TickType_t) 10);
            break;
        case CMD_TYPE_RUN:
            break;
        case CMD_TYPE_RUP:
        case CMD_TYPE_RDW:
        case CMD_TYPE_RLF:
        case CMD_TYPE_RRT:
        case CMD_TYPE_ROK:
        case CMD_TYPE_RDP:
        case CMD_TYPE_RCC:
        case CMD_TYPE_RDT:
        case CMD_TYPE_RLA:
            if (isResponseWithValueOne(&msg))
                xQueueSend(queue_UART_IP, &msg, (TickType_t) 10);
            break;

        case CMD_TYPE_SDP:
            break;
        case CMD_TYPE_SEN:
            
            break;
        case CMD_TYPE_SLP:
            break;
        case CMD_TYPE_SNR:
        case CMD_TYPE_SNW:
            if (msg.msgType == MSG_TYPE_RESPONSE && msg.valueType == VAL_TYPE_STR) {
                setSerialNum(msg.Value.value_s);
                // Reply to the source
                xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
            }
            break;

        case CMD_TYPE_UDP:
            break;
        case CMD_TYPE_USE:
            break;

        case CMD_TYPE_VER:
            break;
        case CMD_TYPE_VOL:
            if (msg.msgType == MSG_TYPE_RESPONSE && msg.valueType == VAL_TYPE_NUM) {
                xQueueSend(queue_UART_RS232, &msg, (TickType_t) 10);
                xQueueSend(queue_UART_IP, &msg, (TickType_t) 10);
                setVolume(msg.Value.value_n);
            }
            break;
        case CMD_HMI_RX_Error:
            SYS_CONSOLE_MESSAGE("CMD_HMI_RX_Error!\r\n");//ToDO
            break;         
        case CMD_L_Pannel_100:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_L_Pannel_100!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n ",CMD_L_Pannel_100,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;
        case CMD_L_Pannel_80:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_L_Pannel_80!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n ",CMD_L_Pannel_80,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;
        case CMD_L_Pannel_60:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_L_Pannel_60!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n ",CMD_L_Pannel_60,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;
        case CMD_L_Pannel_40:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_L_Pannel_40!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n ",CMD_L_Pannel_40,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;
        case CMD_L_Pannel_20:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_L_Pannel_20!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n ",CMD_L_Pannel_20,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;
        case CMD_L_Pannel_0:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_L_Pannel_0!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n ",CMD_L_Pannel_0,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;                          
        case CMD_R_Pannel_100:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_R_Pannel_100!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n ",CMD_R_Pannel_100,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;
        case CMD_R_Pannel_80:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_R_Pannel_80!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n ",CMD_R_Pannel_80,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;
        case CMD_R_Pannel_60:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_R_Pannel_60!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n",CMD_R_Pannel_60,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;
        case CMD_R_Pannel_40:  
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_R_Pannel_40!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n",CMD_R_Pannel_40,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;
        case CMD_R_Pannel_20:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_R_Pannel_20!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n",CMD_R_Pannel_20,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;
        case CMD_R_Pannel_0:
            if(EDBG)
            {
                SYS_CONSOLE_MESSAGE("CMD_R_Pannel_0!\r\n");//ToDO
                SYS_CONSOLE_PRINT("LCW_Brightness [cmdType:0x%02x][hmi_l_value:0x%02x][hmi_r_value:0x%02x] \r\n",CMD_R_Pannel_0,msg.hmi_l_value,msg.hmi_r_value);
            }
            else
                LCW_Brightness_HMI(Driving_Board_1_CTRL_ADDR,hmi_value[msg.hmi_l_value],hmi_value[msg.hmi_r_value]);
            break;    
        default:
            break;
    }
}

void handleMsgFromOuterCtrl(MSG_SOURCE msgSource, Message msg) {

    if (msg.msgType == MSG_TYPE_INVALID)
        return;

    if (msg.cmdType == CMD_TYPE_INVALID){
        SYS_CONSOLE_MESSAGE("CMD_TYPE_INVALID!\r\n");
        return;
    }

    if (msg.valueType == VAL_TYPE_INVALID)
        return;

    switch (msg.cmdType) {
        case CMD_TYPE_ALP:
            break;
        case CMD_TYPE_ALS:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType != MSG_TYPE_REQUEST)
                return;
            
            if (msg.valueType == VAL_TYPE_NUM) {
                setSddpNtfyAlivePeriod(msg.Value.value_n);
                msg.msgType = MSG_TYPE_RESPONSE;
                sendToQueueOf(msgSource, &msg);
            }
            break;
        case CMD_TYPE_ALT:
            break;
        case CMD_TYPE_ALW:
            break;

        case CMD_TYPE_CHA:
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_CHA;
                    msgRes.valueType = VAL_TYPE_CHANNEL;
                    msgRes.Value.value_channel[0] = getInput();
                    msgRes.Value.value_channel[1] = getInput();
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_CHA, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232 or IP, but type is not request
                // Error handle
            }
            break;

        case CMD_TYPE_DCP:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_DCP;
                    msgRes.valueType = VAL_TYPE_NUM;
                    msgRes.Value.value_n = getDhcpSS() ? 1 : 0;
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_DCP, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_DIP:
            break;
        case CMD_TYPE_DNS:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_DNS;
                    msgRes.valueType = VAL_TYPE_IP_ADDR;
                    uint8_t *dnsAddr = getDnsAddrSS();
                    msgRes.Value.value_ip_addr[0] = dnsAddr[0];
                    msgRes.Value.value_ip_addr[1] = dnsAddr[1];
                    msgRes.Value.value_ip_addr[2] = dnsAddr[2];
                    msgRes.Value.value_ip_addr[3] = dnsAddr[3];
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_DNS, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_DT1:
            break;
        case CMD_TYPE_DT2:
            break;
        case CMD_TYPE_DT3:
            break;
        case CMD_TYPE_DT4:
            break;
        case CMD_TYPE_DT5:
            break;

        case CMD_TYPE_FAA:
            break;
        case CMD_TYPE_FAN:
            break;
        case CMD_TYPE_FAT:
            break;

        case CMD_TYPE_GAT:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_GAT;
                    msgRes.valueType = VAL_TYPE_IP_ADDR;
                    uint8_t *gatewayAddr = getGatewayAddrSS();
                    msgRes.Value.value_ip_addr[0] = gatewayAddr[0];
                    msgRes.Value.value_ip_addr[1] = gatewayAddr[1];
                    msgRes.Value.value_ip_addr[2] = gatewayAddr[2];
                    msgRes.Value.value_ip_addr[3] = gatewayAddr[3];
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_GAT, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;

        case CMD_TYPE_HET:
            break;
        case CMD_TYPE_HOE:
            break;
        case CMD_TYPE_HOT:
            break;
        case CMD_TYPE_HST:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                
                if (msg.valueType == VAL_TYPE_CHAR) {
                    SOCKET *hostList = getHostList();
                    for (int i = 0; i < MAX_CLIENTS; i++) {
                        if (hostList[i] == INVALID_SOCKET)
                            continue;
                        
                        Message msgRes;
                        msgRes.msgType = MSG_TYPE_RESPONSE;
                        msgRes.cmdType = CMD_TYPE_HST;
                        
                        struct sockaddr_in addr;
                        int addr_size = sizeof(struct sockaddr_in);
                        getsockname(hostList[i], (struct sockaddr *) &addr, (int *) sizeof(addr_size));
                        uint8_t ipAddr[4];
                        ipIntToArray(addr.sin_addr.S_un.S_addr, ipAddr);
                        
                        // Response the query message
                        msgRes.valueType = VAL_TYPE_IP_ADDR;
                        for (int j = 0; j < 4; j ++)
                            msgRes.Value.value_ip_addr[j] = ipAddr[j];
                        sendToQueueOf(msgSource, &msgRes);
                    }
                } else {
                    // This function is pending for more detail.
                    // TODO add host to host list and send OK back
//                    Message msgRes;
//                    msgRes.msgType = MSG_TYPE_RESPONSE;
//                    msgRes.cmdType = CMD_TYPE_UDP;
//                    msgRes.valueType = VAL_TYPE_STR;
//                    msgRes.Value.value_s = CMD_VALUE_OK;
//                    sendToQueueOf(msgSource, &msgRes);
                }
                
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_HTP:
            break;
        case CMD_TYPE_HTR:
            break;
        case CMD_TYPE_HTS:
            break;
        case CMD_TYPE_HTT:
            break;
        case CMD_TYPE_HTW:
            break;

        case CMD_TYPE_INF:
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_INF;
                    msgRes.valueType = VAL_TYPE_STR;
                    msgRes.Value.value_s = CMD_VALUE_OK;
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // Value type is not char, which means it's not '?'
                    // Error handle
                }
            } else {
                // Message source is RS232 or IP, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_INP:
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_INP;
                    msgRes.valueType = VAL_TYPE_NUM;
                    msgRes.Value.value_n = getInput();
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_INP, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232 or IP, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_IPT:
            break;
        case CMD_TYPE_IRM:
            break;
        case CMD_TYPE_IRT:
            break;

        case CMD_TYPE_LIP:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_LIP;
                    msgRes.valueType = VAL_TYPE_IP_ADDR;
                    uint8_t *ipAddr = getIpAddressSS();
                    msgRes.Value.value_ip_addr[0] = ipAddr[0];
                    msgRes.Value.value_ip_addr[1] = ipAddr[1];
                    msgRes.Value.value_ip_addr[2] = ipAddr[2];
                    msgRes.Value.value_ip_addr[3] = ipAddr[3];
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_LIP, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_LTA:
            break;
        case CMD_TYPE_LTB:
            break;
        case CMD_TYPE_LTP:
            break;

        case CMD_TYPE_MAC:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_MAC;
                    msgRes.valueType = VAL_TYPE_MAC_ADDR;
                    uint8_t *macAddr = getMacAddressSS();
                    msgRes.Value.value_mac_addr[0] = macAddr[0];
                    msgRes.Value.value_mac_addr[1] = macAddr[1];
                    msgRes.Value.value_mac_addr[2] = macAddr[2];
                    msgRes.Value.value_mac_addr[3] = macAddr[3];
                    msgRes.Value.value_mac_addr[4] = macAddr[4];
                    msgRes.Value.value_mac_addr[5] = macAddr[5];
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_MAC, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_MOD:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_MOD;
                    msgRes.valueType = VAL_TYPE_STR;
                    char *modelName = getModelName();
                    msgRes.Value.value_s = modelName;
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_MOD, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_MSK:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_MSK;
                    msgRes.valueType = VAL_TYPE_IP_ADDR;
                    uint8_t *subMask = getSubMaskSS();
                    msgRes.Value.value_ip_addr[0] = subMask[0];
                    msgRes.Value.value_ip_addr[1] = subMask[1];
                    msgRes.Value.value_ip_addr[2] = subMask[2];
                    msgRes.Value.value_ip_addr[3] = subMask[3];
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_MSK, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_MUT:
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_MUT;
                    msgRes.valueType = VAL_TYPE_NUM;
                    msgRes.Value.value_n = getMute() ? 1 : 0;
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_MUT, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232 or IP, but type is not request
                // Error handle
            }
            break;

        case CMD_TYPE_PSN:
            break;
        case CMD_TYPE_PWD:
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_PWD;
                    msgRes.valueType = VAL_TYPE_NUM;
                    msgRes.Value.value_n = getPower() ? 1 : 0;
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_PWD, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232 or IP, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_PWT:
            break;

        case CMD_TYPE_RCC:
            if (isRequestIpCmdWithValueOne(msgSource, &msg))
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_RCC, msg));
            break;
        case CMD_TYPE_RDP:
            if (isRequestIpCmdWithValueOne(msgSource, &msg))
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_RDP, msg));
            break;
        case CMD_TYPE_RDT:
            if (isRequestIpCmdWithValueOne(msgSource, &msg))
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_RDT, msg));
            break;
        case CMD_TYPE_RDW:
            if (isRequestIpCmdWithValueOne(msgSource, &msg))
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_RDW, msg));
            break;
        case CMD_TYPE_RES:
            break;
        case CMD_TYPE_RFL:
            break;
        case CMD_TYPE_RLA:
            if (isRequestIpCmdWithValueOne(msgSource, &msg))
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_RLA, msg));
            break;
        case CMD_TYPE_RLF:
            if (isRequestIpCmdWithValueOne(msgSource, &msg))
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_RLF, msg));
            break;
        case CMD_TYPE_RMT:
            break;
        case CMD_TYPE_RNU:
            if (msgSource == MSG_SOURCE_IP
                    && msg.msgType == MSG_TYPE_REQUEST
                    && msg.valueType == VAL_TYPE_NUM) {
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_RNU, msg));
            }
            break;
        case CMD_TYPE_ROK:
            if (isRequestIpCmdWithValueOne(msgSource, &msg))
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_ROK, msg));
            break;
        case CMD_TYPE_RRT:
            if (isRequestIpCmdWithValueOne(msgSource, &msg))
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_RRT, msg));
            break;
        case CMD_TYPE_RUN:
            break;
        case CMD_TYPE_RUP:
            if (isRequestIpCmdWithValueOne(msgSource, &msg))
                sendToSoCAndFreeIfNotNull(msgToCmdString(CMD_KEY_RUP, msg));
            break;

        case CMD_TYPE_SDP:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                Message msgRes;
                msgRes.msgType = MSG_TYPE_RESPONSE;
                msgRes.cmdType = CMD_TYPE_SDP;
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    msgRes.valueType = VAL_TYPE_NUM;
                    msgRes.Value.value_n = getSddpSrhListenPortSS();
                } else {
                    setSddpSrhListenPortSS(msg.Value.value_n);
                    closeAndCreateSocketOfSddp();
                    msgRes.valueType = VAL_TYPE_STR;
                    msgRes.Value.value_s = CMD_VALUE_OK;
                }
                sendToQueueOf(msgSource, &msgRes);
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_SEN:
            break;
        case CMD_TYPE_SLP:
            break;
        case CMD_TYPE_SNR:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    Message msgRes;
                    msgRes.msgType = MSG_TYPE_RESPONSE;
                    msgRes.cmdType = CMD_TYPE_SNR;
                    msgRes.valueType = VAL_TYPE_STR;
                    char *serialNum = getSerialNum();
                    msgRes.Value.value_s = serialNum;
                    sendToQueueOf(msgSource, &msgRes);
                } else {
                    // This command is query-only
                    // Error handle
                }
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_SNW:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_STR) {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_SNW, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;

        case CMD_TYPE_UDP:
            // Block IP Ctrl
            if (msgSource == MSG_SOURCE_IP)
                return;
            
            if (msg.msgType == MSG_TYPE_REQUEST) {
                Message msgRes;
                msgRes.msgType = MSG_TYPE_RESPONSE;
                msgRes.cmdType = CMD_TYPE_UDP;
                if (msg.valueType == VAL_TYPE_CHAR) {
                    // Response the query message
                    msgRes.valueType = VAL_TYPE_NUM;
                    msgRes.Value.value_n = getSddpNtfyDstPortSS();
                } else {
                    setSddpNtfyDstPortSS(msg.Value.value_n);
                    closeAndCreateSocketOfSddp();
                    msgRes.valueType = VAL_TYPE_STR;
                    msgRes.Value.value_s = CMD_VALUE_OK;
                }
                sendToQueueOf(msgSource, &msgRes);
            } else {
                // Message source is RS232, but type is not request
                // Error handle
            }
            break;
        case CMD_TYPE_USE:
            break;

        case CMD_TYPE_VER:
            break;
        case CMD_TYPE_VOL:
            if (msg.msgType == MSG_TYPE_REQUEST) {
                if (msg.valueType == VAL_TYPE_CHAR) {
                    if (msg.Value.value_c == '?') {
                        // Response the query message
                        Message msgRes;
                        msgRes.msgType = MSG_TYPE_RESPONSE;
                        msgRes.cmdType = CMD_TYPE_VOL;
                        msgRes.valueType = VAL_TYPE_NUM;
                        msgRes.Value.value_n = getVolume();
                        sendToQueueOf(msgSource, &msgRes);
                    } else if (msg.Value.value_c == '+' || msg.Value.value_c == '-') {
                        // send to SoC via UART
                        char *cmdStr = msgToCmdString(CMD_KEY_VOL, msg);
                        sendToSoCAndFreeIfNotNull(cmdStr);
                    }
                } else {
                    // send to SoC via UART
                    char *cmdStr = msgToCmdString(CMD_KEY_VOL, msg);
                    sendToSoCAndFreeIfNotNull(cmdStr);
                }
            } else {
                // Message source is RS232 or IP, but type is not request
                // Error handle
            }
            break;
        default:
            break;
    }
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void UART_APP_Initialize ( void )

  Remarks:
    See prototype in uart_app.h.
 */

void UART_APP_Initialize(void) {
    /* Place the App state machine in its initial state. */
    uart_appData.state = UART_APP_STATE_INIT;
    adc0_data=ADC0_TRANSFER_STATUS_OFF;
    //uart_appData.state = UART_APP_STATE_SERVICE_TASKS;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

/******************************************************************************
  Function:
    void UART_APP_Tasks ( void )

  Remarks:
    See prototype in uart_app.h.
 */

void UART_APP_Tasks(void) {
    //TCC0_PWM24bitCounterSet (2000);
    //TCC0_PWM24bitPeriodSet (1000);
    //TCC0_PWM24bitDutySet(TCC0_CHANNEL3,937+64);    //Compensation value 64
    //MCP9800GetTemperatureTS1(&TempC_ts1, &neg_ts1);

    /* Check the application's current state. */
    //SYS_CONSOLE_MESSAGE("UART_APP_Tasks!\r\n");
    switch (uart_appData.state) 
    {
        case UART_APP_STATE_INIT:
        {
            SYS_CONSOLE_MESSAGE("Start UART_APP_STATE_INIT!\r\n");
            GPIO_PC22_InputEnable();
            //ADC0_Initialize();
            //if(KNOB && flagADC)
            if(flagADC)
            //if(KNOB)                
            {
                adc0_data=ADC0_TRANSFER_STATUS_ON;
                ADC0_Enable();
                ADC0_ConversionStart();
            }
            uart_appData.state = UART_APP_STATE_SERVICE_TASKS;
            break;
        }
        case UART_APP_STATE_SERVICE_TASKS:
        {
            Message msgRx;
            // Handle messages sent from IP
            if (xQueueReceive(queue_IP_UART, &msgRx, (TickType_t) 0) == pdTRUE) {
                handleMsgFromOuterCtrl(MSG_SOURCE_IP, msgRx);
            }

            // Handle messages sent from RS232
            if (xQueueReceive(queue_RS232_UART, &msgRx, (TickType_t) 0) == pdTRUE) {
                handleMsgFromOuterCtrl(MSG_SOURCE_RS232, msgRx);
            }

            // Handle messages sent from Soc
            size_t bfrSize = 0;
            //if(KNOB && flagADC)
            if(flagADC)
            //if(KNOB)    
            {
                ADC0_EventHandler(&adc0_data);
            }
            else if(LCW_Assign)
            {
                //GPIO_PB09_High(true);
                count_delay++;
                if(count_delay < 1000)
                {
                    if(count_delay % 10 == 0)//0.5sec
                    {
                        count_check++;  
                        if (count_check % 2 == 0)
                        {
                            if(EDBG)
                            {
                                SYS_CONSOLE_PRINT("black white \r\n");
                            }
                            else
                            {
                                LCW_8Channel(Driving_Board_1_CTRL_ADDR,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8);
                                LCW_8Channel(Driving_Board_2_CTRL_ADDR,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8);
                                LCW_8Channel(Driving_Board_3_CTRL_ADDR,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8);
                                LCW_8Channel(Driving_Board_4_CTRL_ADDR,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8);
                                LCW_8Channel(Driving_Board_5_CTRL_ADDR,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8);
                                LCW_8Channel(Driving_Board_6_CTRL_ADDR,0x8a,0xf8,0x8a,0xf8,0x8a,0x8a,0x8a,0x8a);
                            }
                        }
                        else
                        {
                            if(EDBG)
                            {
                                SYS_CONSOLE_PRINT("white black\r\n");
                            }
                            else
                            {
                                LCW_8Channel(Driving_Board_1_CTRL_ADDR,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a);
                                LCW_8Channel(Driving_Board_2_CTRL_ADDR,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a);
                                LCW_8Channel(Driving_Board_3_CTRL_ADDR,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a);
                                LCW_8Channel(Driving_Board_4_CTRL_ADDR,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a);
                                LCW_8Channel(Driving_Board_5_CTRL_ADDR,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a);
                                LCW_8Channel(Driving_Board_6_CTRL_ADDR,0xf8,0x8a,0xf8,0x8a,0xf8,0x8a,0x8a,0x8a);
                            }
                        }
                    }
                }
                else if (count_delay == 1000 )
                {
                    count_check=0;
                    if(EDBG)
                    {
                        SYS_CONSOLE_PRINT("all black\r\n");
                    }
                    else
                    {
                        LCW_8Channel(Driving_Board_1_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_2_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_3_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_4_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_5_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_6_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                    }
                }
                else if ((count_delay >1000) && (count_delay < 2300))
                {
                    if(count_delay % 10 == 0)//0.5sec
                    {
                        count_check++;
                        if(EDBG)
                        {
                            SYS_CONSOLE_PRINT("turn off\r\n");
                        }
                        else
                        {
                            LCW_8Channel(Driving_Board_1_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                            LCW_8Channel(Driving_Board_2_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                            LCW_8Channel(Driving_Board_3_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                            LCW_8Channel(Driving_Board_4_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                            LCW_8Channel(Driving_Board_5_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                            LCW_8Channel(Driving_Board_6_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        }
                        if (count_check % 9 == 6)
                        {
                            if(EDBG)
                                SYS_CONSOLE_PRINT("turn on sec_6\r\n");
                            else
                            {
                                LCW_8Channel(Driving_Board_4_CTRL_ADDR,0x8a,0xf8,0xf8,0xf8,0xf8,0xf8,0x8a,0x8a);
                            }
                        }
                        else if (count_check % 9 == 7)
                        {
                            if(EDBG)
                                SYS_CONSOLE_PRINT("turn on sec_7\r\n");
                            else
                            {
                                LCW_8Channel(Driving_Board_4_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0xf8,0xf8);
                                LCW_8Channel(Driving_Board_5_CTRL_ADDR,0xf8,0xf8,0xf8,0x8a,0x8a,0x8a,0x8a,0x8a);
                            }
                        }
                        else if (count_check % 9 == 8)
                        {
                            if(EDBG)
                                SYS_CONSOLE_PRINT("turn on sec_8\r\n");
                            else
                            {
                                LCW_8Channel(Driving_Board_5_CTRL_ADDR,0x8a,0x8a,0x8a,0xf8,0xf8,0xf8,0xf8,0xf8);
                            }
                        }
                        else if (count_check % 9 == 0)
                        {
                            if(EDBG)
                                SYS_CONSOLE_PRINT("turn on sec_9\r\n");
                            else
                            {
                                LCW_8Channel(Driving_Board_6_CTRL_ADDR,0xf8,0xf8,0xf8,0xf8,0xf8,0x8a,0x8a,0x8a);
                            }
                        }
                        else if (count_check % 9 == 1)
                        {
                            if(EDBG)
                                SYS_CONSOLE_PRINT("turn on sec_1\r\n");
                            else
                            {
                                LCW_8Channel(Driving_Board_1_CTRL_ADDR,0xf8,0xf8,0xf8,0xf8,0xf8,0x8a,0x8a,0x8a);
                            }
                        }
                        else if (count_check % 9 == 2)
                        {
                            if(EDBG)
                                SYS_CONSOLE_PRINT("turn on sec_2\r\n");
                            else
                            {
                                LCW_8Channel(Driving_Board_1_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0xf8,0xf8,0xf8);
                                LCW_8Channel(Driving_Board_2_CTRL_ADDR,0xf8,0xf8,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                            }
                        }
                        else if (count_check % 9 == 3)
                        {
                            if(EDBG)
                                SYS_CONSOLE_PRINT("turn on sec_3\r\n");
                            else
                            {
                                LCW_8Channel(Driving_Board_2_CTRL_ADDR,0x8a,0x8a,0xf8,0xf8,0xf8,0xf8,0xf8,0x8a);
                            }
                        }
                        else if (count_check % 9 == 4)
                        {
                            if(EDBG)
                                SYS_CONSOLE_PRINT("turn on sec_4\r\n");
                            else
                            {
                                LCW_8Channel(Driving_Board_2_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0xf8);
                                LCW_8Channel(Driving_Board_3_CTRL_ADDR,0xf8,0xf8,0xf8,0xf8,0x8a,0x8a,0x8a,0x8a);
                            }
                        }
                        else if (count_check % 9 == 5)
                        {
                            if(EDBG)
                                SYS_CONSOLE_PRINT("turn on sec_5\r\n");
                            else
                            {
                                LCW_8Channel(Driving_Board_3_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0xf8,0xf8,0xf8,0xf8);
                                LCW_8Channel(Driving_Board_4_CTRL_ADDR,0xf8,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                            }
                        }
                    }
                }
                else if (count_delay == 2300)
                {
                    count_check=0;
                    if(EDBG)
                    {
                        SYS_CONSOLE_PRINT("all black\r\n");
                    }
                    else
                    {
                        LCW_8Channel(Driving_Board_1_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_2_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_3_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_4_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_5_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_6_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                    }
                }
                else if ((count_delay > 2000) && (count_delay < 4000))
                {
                    if(count_delay % 10 == 0)//0.5sec
                    {//rand() %
                        if(EDBG)
                            SYS_CONSOLE_PRINT("all random\r\n");
                        else
                        {
                            LCW_8Channel(Driving_Board_1_CTRL_ADDR,hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7]);
                            LCW_8Channel(Driving_Board_2_CTRL_ADDR,hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7]);
                            LCW_8Channel(Driving_Board_3_CTRL_ADDR,hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7]);
                            LCW_8Channel(Driving_Board_4_CTRL_ADDR,hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7]);
                            LCW_8Channel(Driving_Board_5_CTRL_ADDR,hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7]);
                            LCW_8Channel(Driving_Board_6_CTRL_ADDR,hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],hmi_value[rand() % 7],0x8a,0x8a,0x8a);
                        }
                    }
                }
                else
                {
                    count_check=0;
                    count_delay=0;
                    if(EDBG)
                    {
                        SYS_CONSOLE_PRINT("all black\r\n");
                        SYS_CONSOLE_PRINT("all reset\r\n");
                    }
                    else
                    {
                        LCW_8Channel(Driving_Board_1_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_2_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_3_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_4_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_5_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                        LCW_8Channel(Driving_Board_6_CTRL_ADDR,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a,0x8a);
                    }
                }
            }
            //else if(LCW_Button_GPIO3 && flagGPIO)
            else if(flagGPIO)
            //else if(LCW_Button_GPIO3)    
            {//GPIO_PC22_ButtonStatus
                int GPIO_PC22_Now=GPIO_PC22_Get();
                if (GPIO_PC22_PreStatus != GPIO_PC22_Now)
                {
                    GPIO_PC22_PreStatus = GPIO_PC22_Now;
                    if (EDBG)
                    {
                        SYS_CONSOLE_PRINT("GPIO_PC22_Get= %d\r\n", GPIO_PC22_Now);
                    }
                    else
                    {
                        if(GPIO_PC22_Now == 0)
                        {//1-->0 Press button 
                            //SYS_CONSOLE_PRINT("Do Nothing\r\n");
                        }
                        else
                        {//0-->1 Complete button click
                            if(GPIO_PC22_ButtonStatus ==0)
                            {//0-->1
                                //SYS_CONSOLE_PRINT("0-->1\r\n");
                                LCW_8Channel(Driving_Board_1_CTRL_ADDR,0xf8,0x8a,0xf7,0x8b,0xf6,0x8c,0xf5,0x8d);
                                LCW_8Channel(Driving_Board_2_CTRL_ADDR,0xf8,0x8a,0xf7,0x8b,0xf6,0x8c,0xf5,0x8d);
                                LCW_8Channel(Driving_Board_3_CTRL_ADDR,0xf8,0x8a,0xf7,0x8b,0xf6,0x8c,0xf5,0x8d);
                                LCW_8Channel(Driving_Board_4_CTRL_ADDR,0xf8,0x8a,0xf7,0x8b,0xf6,0x8c,0xf5,0x8d);
                                LCW_8Channel(Driving_Board_5_CTRL_ADDR,0xf8,0x8a,0xf7,0x8b,0xf6,0x8c,0xf5,0x8d);
                                LCW_8Channel(Driving_Board_6_CTRL_ADDR,0xf8,0x8a,0xf7,0x8b,0xf6,0x8c,0xf5,0x8d);
                                LCW_8Channel(Driving_Board_7_CTRL_ADDR,0xf8,0x8a,0xf7,0x8b,0xf6,0x8c,0xf5,0x8d);
                                LCW_8Channel(Driving_Board_8_CTRL_ADDR,0xf8,0x8a,0xf7,0x8b,0xf6,0x8c,0xf5,0x8d);
                                GPIO_PC22_ButtonStatus=1;
                            }
                            else
                            {//1-->0
                                //SYS_CONSOLE_PRINT("1-->0\r\n");
                                LCW_8Channel(Driving_Board_1_CTRL_ADDR,0x8a,0xf8,0x8b,0xf7,0x8c,0xf6,0x8d,0xf5);
                                LCW_8Channel(Driving_Board_2_CTRL_ADDR,0x8a,0xf8,0x8b,0xf7,0x8c,0xf6,0x8d,0xf5);
                                LCW_8Channel(Driving_Board_3_CTRL_ADDR,0x8a,0xf8,0x8b,0xf7,0x8c,0xf6,0x8d,0xf5);
                                LCW_8Channel(Driving_Board_4_CTRL_ADDR,0x8a,0xf8,0x8b,0xf7,0x8c,0xf6,0x8d,0xf5);
                                LCW_8Channel(Driving_Board_5_CTRL_ADDR,0x8a,0xf8,0x8b,0xf7,0x8c,0xf6,0x8d,0xf5);
                                LCW_8Channel(Driving_Board_6_CTRL_ADDR,0x8a,0xf8,0x8b,0xf7,0x8c,0xf6,0x8d,0xf5);
                                LCW_8Channel(Driving_Board_7_CTRL_ADDR,0x8a,0xf8,0x8b,0xf7,0x8c,0xf6,0x8d,0xf5);
                                LCW_8Channel(Driving_Board_8_CTRL_ADDR,0x8a,0xf8,0x8b,0xf7,0x8c,0xf6,0x8d,0xf5);
                                GPIO_PC22_ButtonStatus=0;
                            }
                        }
                    }
                }
            }
            else if(LCW_UART)
            {//special protocal for lcw by using 0x25 0x25 0x25 + cmd + 0xFF 0xFF 0xFF
                //SYS_CONSOLE_PRINT("LCW_UART\r\n");
                //for (uint32_t i = 0; i < 100000; i++);//1ns*20000=2ms
                if ((bfrSize = SERCOM0_USART_ReadCountGet()) > 0) 
                {
                    //SYS_CONSOLE_PRINT("LCW_UART_0\r\n");
                    //ShowUART_Buffer();
                    uint8_t *socRxBfr = calloc(bfrSize+20, sizeof (uint8_t)); 
                    for (uint32_t i = 0; i < 20000; i++);//1ns*20000=2ms
                    SERCOM0_USART_Read(socRxBfr, bfrSize+20);
                    //LCW_parsingCommand_SERCOM0(socRxBfr, bfrSize+20);     //perrcy
                    for (uint32_t i = 0; i < 20000; i++);//1ns*20000=2ms
                    LCW_parsingCommand_SERCOM0(socRxBfr, bfrSize+20);     //perrcy
                    Message msgSoc = parsingCommand_SERCOM0_LCW(socRxBfr, bfrSize+20);
                    handleMsgFromSoC(msgSoc);
                    free(socRxBfr);
                }
            }
            else
            {
//                if(Als_Crlon == 1)
//                {
//                   ALS_AutoRun();
//                   Als_Crlon = 0;
//                }
                for (uint32_t i = 0; i < 50000; i++);//1ns*20000=2ms
                if ((bfrSize = SERCOM0_USART_ReadCountGet()) > 0) 
                {
                    SYS_CONSOLE_PRINT("bfrSize = %x\r\n",bfrSize);
                    //SYS_CONSOLE_PRINT("LCW_UART_1\r\n");
                    uint8_t *socRxBfr = calloc(bfrSize, sizeof (uint8_t));
                    //for (uint32_t i = 0; i < 30000; i++);//1ns*20000=2ms
                    //SYS_CONSOLE_PRINT("FRE READ\r\n");
                    SERCOM0_USART_Read(socRxBfr, bfrSize);
                    //SYS_CONSOLE_PRINT("BAC READ\r\n");
                    //SYS_CONSOLE_PRINT("bfrSize = %x\r\n",bfrSize);
                    //SYS_CONSOLE_PRINT("bfrSize = %d\r\n",bfrSize);
                    //Message msgSoc = parsingCommand(socRxBfr, bfrSize);
                    //SYS_CONSOLE_MESSAGE("\r\n");                   
                    LCW_parsingCommand_SERCOM0(socRxBfr, bfrSize);       //perrcy
                    //for (uint32_t i = 0; i < 30000; i++);//1ns*20000=2ms
                    Message msgSoc = parsingCommand_SERCOM0(socRxBfr, bfrSize);
                    //SYS_CONSOLE_MESSAGE("\r\n");
                    handleMsgFromSoC(msgSoc);
                    free(socRxBfr);
                }  
            }
        if(flagReadEEPROM == true){
        EEPROM_Read_Data(EEPROM_USERDATA_ADDR1,&EEData);
        flagReadEEPROM = false;
            //if(EEData.drbo_NUM > 14)
            //{
               //EEData.drbo_NUM = 1;
            //}            
        }
        if(flagALS_Read == true)
        {
           ALS_ReadRun();
        }
        if((Als_Crlon == 1) || (flagALS == true))
        {
            Als_count++;
            for (uint32_t i = 0; i < 10000; i++);//1ns*10000=1ms
            if(Als_count == 5)      // 0.5s 
            {    Als_count = 0;
                ALS_AutoRun();
            //Als_Crlon = 0;
            }
        }
        if(flagALS_TAR == true)
        {
            Als_count++;
            for (uint32_t i = 0; i < 10000; i++);//1ns*10000=1ms
            if(Als_count == 5)      // 0.5s 
            {    Als_count = 0;
                ALS_TargetRun();
            //Als_Crlon = 0;
            }            
            
        }        
        if(Als_Demo01 == 1)
        {
            ALS_RunDemo01();
            //Als_Crlon = 0;
        }
        if(Als_Demo02 == 1)
        {
            ALS_RunDemo02();
            //Als_Crlon = 0;
        }            
            break;
        }
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
