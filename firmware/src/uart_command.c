/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    uart_command.c

  @Summary
    Brief description of the file.

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
#include <math.h>    
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "com_lib.h"
#include "uart_command.h"
#include "Judgeman.h"
#include "eeprom.h"
#include "tcpip/tcpip.h"
#include "tcpip/berkeley_api.h"
#include "tcpip/tcpip_manager.h"
#include "cJSON.h"
#include "system/console/sys_console.h"
#include "shared_settings.h"

unsigned char LCWCommandTab[LCW_CMD_NUM][LCW_CMD_LEN] = {                               //TOTAL SUPPORT LCW COMMAND TABLE
{"MODE"}, {"ALSX"}, {"ALLX"}, {"BDCH"}, {"GRUP"}, {"GPLV"}, {"COMP"}, {"REST"}, {"HMIX"}, {"SETG"},      //0~9
{"GPIO"}, {"RDIP"}, {"RDMA"}, {"RDAL"}, {"RDST"}, {"RDBT"}, {"DEBG"}, {"DEMO"}, {"USSV"}, {"USRL"},      //10~19
{"EEPR"}, {"ALMX"}, {"ALMN"}, {"TRGT"}, {"SETP"}, {"INVL"}, {"MODL"}, {"SERL"}, {"MOVR"}, {"MOVL"},      //20~29
{"MVIN"}, {"MVOU"}, {"RAWC"}, {"SHOW"}
};

uint8_t lcw_V_value[7]={138,147,150,154,161,177,248};
uint8_t lcw_inverce_value[7]={6,5,4,3,2,1,0};
char Als_read_Buf[6];
extern EEPROMData EEDataDefault;
EEPROMData EEData;
EEPROMData EEData_test;
//extern  uint16_t Als_max , Als_min , Als_read; //
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
/*
static int ExampleLocalFunction(int param1, int param2) {
    return 0;
}
*/

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
void LCW_parsingCommand_SERCOM0(uint8_t *RxBuffer, size_t RxBufSize)
{
    if (RxBufSize >= 8)// at least two Byte 0x24 0x24 0x24 + ____ + ____ + 0x23 0x23 0x23
    {  
        if ((RxBuffer[0] == UART_Start_Byte) && (RxBuffer[1] == UART_Start_Byte) && (RxBuffer[2] == UART_Start_Byte))
        {         
            size_t rx_size = 10;   //Command 4 byte + data 6 byte
            char RxCMDBuffer[rx_size];
            memset(RxCMDBuffer, 0, rx_size); 
            for (int i = 0; i < rx_size; i++)
            {
                RxCMDBuffer[i] = (char) RxBuffer[i+3];
            }
            if((RxBuffer[rx_size+3] == UART_End_Byte) && (RxBuffer[rx_size+4] == UART_End_Byte) && (RxBuffer[rx_size+5] == UART_End_Byte))
            {
                CheckLCW_Command(RxCMDBuffer,rx_size);
                //return msge;
            }else{
            //FEEDBACK_UART(FEEDBACKHMING);
            }
        }else{
            //FEEDBACK_UART(FEEDBACKHMING);
        }
    }    
    //return msge;
}
//percy
/* ************************************************************************** */
//unsigned char ParsingCommand(void)
void CheckLCW_Command(char *chkcmdString,size_t cmd_size)
{
unsigned char i,j,k;
char CMDDataBuffer[6];
memset(CMDDataBuffer, 0, 6);
//unsigned int ret;
		for(i = 0 ; i < LCW_CMD_NUM ; i++ ){
			for(j = 0 ; j < LCW_CMD_LEN ; j++ ){
				if(chkcmdString[j] != LCWCommandTab[i][j]){					//character not match the command table will be thrown
                    break;
				}
			}
			if(j == LCW_CMD_LEN ){						    //TVWALLCommandTab[i] matched!
				//ret = ExecuteCommand(i);
                for(k=0;k<6;k++)
                {
                CMDDataBuffer[k] = chkcmdString[k+4];
                }
                ExecuteCommand(CMDDataBuffer,i);
				break;
			}
		}
	//return ret;
}

unsigned char ExecuteCommand(char *cmddataString,unsigned char n)
{
    unsigned char ret;
    int i,j;
    uint8_t brl_Buf;
    uint8_t brl_Buf_BB;
    uint8_t brl_Buf_CC;
    uint8_t brl_Buf_LL;
    uint8_t gup_Buf_GG;
    uint8_t gup_Buf_BB;
    uint8_t gup_Buf_CC;
    uint8_t gup_Buf_NUM;
    uint8_t gup_Buf_GUPbyte;
    uint8_t gup_Buf_GUPbit;
    uint8_t boardnum;
    uint8_t MVIN_L;
    uint8_t MVIN_R;
    uint8_t MVOU_L;
    uint8_t MVOU_R;
    //uint8_t EECount;
    uint8_t EELCW_NUM;
    //uint8_t BB,CC;
    char DataBuffer[4];
    //uint8_t datatmp[6];
    memset(DataBuffer, 0, 4);
    //EEPROMData EEData;
    //EEPROMData EEData_test;
    //uint16_t test_sum = 0x03B2;
    //uint16_t test[test_sum];    //EEPROM test
    uint8_t test[15];    //EEPROM test
		switch(n){
            case INX_MODE:
                if(cmddataString[5]=='1')
                {
                    flagALS = true;
                    flagALS_TAR = false;
                    flagADC = false;
                    flagGPIO = false;
                    //Als_Crlon = 1;
                    //ALS_AutoRun();
                    //FEEDBACK_UART(FEEDBACKHMIOK);
                }
                else if(cmddataString[5]=='2')
                {
                     flagALS = false;
                     flagALS_TAR = false;
                     flagADC = false;
                     flagGPIO = false;
                     //FEEDBACK_UART(FEEDBACKHMIOK);
                }
                else if(cmddataString[5]=='3')
                {
                     flagALS = false;
                     flagALS_TAR = false;
                     flagADC = false;
                     flagGPIO = false;
                     GPIO_PC23_Clear();
                     for (uint32_t i = 0; i < 100000; i++);//1ns*200000=20ms
                     FEEDBACK_UART(FEEDBACKMANUALNEWLEVEL);
                     //FEEDBACK_UART(FEEDBACKHMIOK);
                }
                else if(cmddataString[5]=='5')
                {
                    flagALS = false;
                    flagALS_TAR = false;
                    flagADC = true;
                    flagGPIO = false;
                    //FEEDBACK_UART(FEEDBACKHMIOK);
                }
                else if(cmddataString[5]=='6')
                {
                    flagALS = false;
                    flagALS_TAR = false;
                    flagADC = false;                   
                    flagGPIO = true;
                    //FEEDBACK_UART(FEEDBACKHMIOK);
                }
                else if(cmddataString[5]=='7')
                {
                    flagALS = false;
                    flagALS_TAR = true;
                    flagADC = false;                   
                    flagGPIO = false;
                    //FEEDBACK_UART(FEEDBACKHMIOK);
                }                
                else{
                    FEEDBACK_UART(FEEDBACKNG);
                }
                //SYS_CONSOLE_PRINT("INX_MODE: %x\r\n", cmddataString[4]);
                //SYS_CONSOLE_PRINT("INX_MODE: %x\r\n", cmddataString[5]);
                //GPIO_PB00_Set();
                //EEPROM_Write_LCW(0x0000,6);
                //EEPROM_Write(EEPROM_1_CTRL_ADDR);
                //for (uint32_t i = 0; i < 20000; i++);//1ns*20000=2ms
                //EEPROM_Read(EEPROM_1_CTRL_ADDR);
                //GPIO_PB00_Clear();  //WC disable
                //EEPROM_Read_LCW(0x0000,datatmp,8);
                //GPIO_PB00_Set();    //WC enable 
                //GPIO_PB00_Clear();
                break;
            case INX_DEMO:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif
#if 0               
                if(cmddataString[4]=='0' && cmddataString[5]=='1')
                {
                   Als_Demo01 = 1;
                   Als_Demo02 = 0;
                }
                else if(cmddataString[4]=='0' && cmddataString[5]=='2')
                {
                   Als_Demo01 = 0;
                   Als_Demo02 = 1;
                }else{
                    FEEDBACK_UART(FEEDBACKNG);
                }
#endif                
                break;                
            case INX_ALSX:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
#if 0               
                if(cmddataString[1]=='0')
                {
                  for(i=0;i<4;i++)
                  {
                    DataBuffer[i] = cmddataString[i+2]; 
                  }
                  Als_min = (cmddataString[1]-0x30)*10000 + (cmddataString[2]-0x30)*1000 + (cmddataString[3]-0x30)*100 + (cmddataString[4]-0x30)*10 + (cmddataString[5]-0x30);
                  //Als_min = Command_HexToDec(4, DataBuffer);
                  SYS_CONSOLE_PRINT("Als_min = %x\r\n", Als_min);
                  //SYS_CONSOLE_PRINT("Als_min = %d\r\n", Als_min);
                }    
                if(cmddataString[1]=='1')
                {
                  for(i=0;i<4;i++)
                  {
                    DataBuffer[i] = cmddataString[i+2]; 
                  }
                  Als_max = (cmddataString[1]-0x30)*10000 + (cmddataString[2]-0x30)*1000 + (cmddataString[3]-0x30)*100 + (cmddataString[4]-0x30)*10 + (cmddataString[5]-0x30);
                  //Als_max = Command_HexToDec(4, DataBuffer);
                  SYS_CONSOLE_PRINT("Als_max = %x\r\n", Als_max);
                  //SYS_CONSOLE_PRINT("Als_max = %d\r\n", Als_max);
                }
#endif                
                break;
            case INX_ALMX:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                Als_max = (cmddataString[1]-0x30)*10000 + (cmddataString[2]-0x30)*1000 + (cmddataString[3]-0x30)*100 + (cmddataString[4]-0x30)*10 + (cmddataString[5]-0x30);
                //SYS_CONSOLE_PRINT("Als_max = %d\r\n", Als_max);
                EEData.Als_max = Als_max;
                //FEEDBACK_UART(FEEDBACKHMIOK);
                break;
            case INX_ALMN:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif               
                Als_min = (cmddataString[1]-0x30)*10000 + (cmddataString[2]-0x30)*1000 + (cmddataString[3]-0x30)*100 + (cmddataString[4]-0x30)*10 + (cmddataString[5]-0x30);
                //SYS_CONSOLE_PRINT("Als_min = %d\r\n", Als_min);
                EEData.Als_min = Als_min;
                //FEEDBACK_UART(FEEDBACKHMIOK);
                break;                
            case INX_ALLX:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                brl_Buf = (cmddataString[4]-0x30)*10 + (cmddataString[5]-0x30);
                for(i=0;i<EEData.drbo_NUM;i++)  //14
                {
                    for(j=0;j<8;j++)
                    {
                        //LCW_LevelData[j][i] = brl_Buf;
                        EEData.DATA[8*i+j].level = brl_Buf;
                    }
                }
                for(i=0;i<EEData.drbo_NUM;i++)   //14
                {    
                   //LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[LCW_LevelData[0][i]],lcw_V_value[LCW_LevelData[1][i]],lcw_V_value[LCW_LevelData[2][i]],lcw_V_value[LCW_LevelData[3][i]],lcw_V_value[LCW_LevelData[4][i]],lcw_V_value[LCW_LevelData[5][i]],lcw_V_value[LCW_LevelData[6][i]],lcw_V_value[LCW_LevelData[7][i]]);
                   LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[EEData.DATA[8*i+0].level],lcw_V_value[EEData.DATA[8*i+1].level],lcw_V_value[EEData.DATA[8*i+2].level],lcw_V_value[EEData.DATA[8*i+3].level],lcw_V_value[EEData.DATA[8*i+4].level],lcw_V_value[EEData.DATA[8*i+5].level],lcw_V_value[EEData.DATA[8*i+6].level],lcw_V_value[EEData.DATA[8*i+7].level]);
                   //for (uint32_t z = 0; z < 40000; z++);//1ns*20000=2ms
                }
                //FEEDBACK_UART(FEEDBACKHMIOK);
                break;
            case INX_BDCH:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                brl_Buf_BB = (cmddataString[0]-0x30)*10 + (cmddataString[1]-0x30);
                brl_Buf_CC = (cmddataString[2]-0x30)*10 + (cmddataString[3]-0x30);
                brl_Buf_LL = (cmddataString[4]-0x30)*10 + (cmddataString[5]-0x30);
                LCW_LevelData[brl_Buf_CC-1][brl_Buf_BB-1] = brl_Buf_LL;                
                ////EEData.DATA[8*(brl_Buf_BB-1)+brl_Buf_CC].level = brl_Buf_LL;
                EEData.DATA[8*(brl_Buf_BB-1)+(brl_Buf_CC-1)].level = brl_Buf_LL;
                //LCW_8Channel(Driving_Board_1_CTRL_ADDR + brl_Buf_BB -1,lcw_V_value[LCW_LevelData[0][brl_Buf_BB-1]],lcw_V_value[LCW_LevelData[1][brl_Buf_BB-1]],lcw_V_value[LCW_LevelData[2][brl_Buf_BB-1]],lcw_V_value[LCW_LevelData[3][brl_Buf_BB-1]],lcw_V_value[LCW_LevelData[4][brl_Buf_BB-1]],lcw_V_value[LCW_LevelData[5][brl_Buf_BB-1]],lcw_V_value[LCW_LevelData[6][brl_Buf_BB-1]],lcw_V_value[LCW_LevelData[7][brl_Buf_BB-1]]); 
                ////LCW_8Channel(Driving_Board_1_CTRL_ADDR + brl_Buf_BB -1,lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+1].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+2].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+3].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+4].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+5].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+6].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+7].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+8].level]);
                LCW_8Channel(Driving_Board_1_CTRL_ADDR + brl_Buf_BB -1,lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+1].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+2].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+3].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+4].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+5].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+6].level],lcw_V_value[EEData.DATA[8*(brl_Buf_BB-1)+7].level]);
                //FEEDBACK_UART(FEEDBACKHMIOK);
                break;
            case INX_GRUP:                
                gup_Buf_GG = (cmddataString[0]-0x30)*10 + (cmddataString[1]-0x30);
                gup_Buf_BB = (cmddataString[2]-0x30)*10 + (cmddataString[3]-0x30);
                gup_Buf_CC = (cmddataString[4]-0x30)*10 + (cmddataString[5]-0x30);
                gup_Buf_NUM = (((gup_Buf_BB-1) * 8) + gup_Buf_CC)-1;
                gup_Buf_GUPbyte = (gup_Buf_GG-1) >> 3;//gup_Buf_GG / 8;
                gup_Buf_GUPbit = gup_Buf_GG & 0x07;//gup_Buf_GG % 8;
                if(gup_Buf_GUPbit != 0)      
                {
                        EEData.DATA[gup_Buf_NUM].group[gup_Buf_GUPbyte] = ((0x01<<(8-gup_Buf_GUPbit))&0xff)|(EEData.DATA[gup_Buf_NUM].group[gup_Buf_GUPbyte]);
                }else{
                        EEData.DATA[gup_Buf_NUM].group[gup_Buf_GUPbyte] = 0x01|EEData.DATA[gup_Buf_NUM].group[gup_Buf_GUPbyte];    
                }
                //FEEDBACK_UART(FEEDBACKHMIOK);
                //SYS_CONSOLE_PRINT("GG = %x,BB = %x,CC = %x,NUM = %x,gup_Buf_GUPbyte = %x,EEData.DATA = %x\r\n",gup_Buf_GG,gup_Buf_BB,gup_Buf_CC,gup_Buf_NUM,gup_Buf_GUPbyte,EEData.DATA[gup_Buf_NUM].group[gup_Buf_GUPbyte]);
                //SYS_CONSOLE_PRINT("UART TEST\r\n");
                break;
            case INX_GPLV:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                gup_Buf_GG = (cmddataString[0]-0x30)*10 + (cmddataString[1]-0x30);
                brl_Buf_LL = (cmddataString[4]-0x30)*10 + (cmddataString[5]-0x30);
                gup_Buf_GUPbyte = (gup_Buf_GG-1) >> 3;//gup_Buf_GG / 8;
                gup_Buf_GUPbit = gup_Buf_GG & 0x07;//gup_Buf_GG % 8;                
                for(int i=0;i<(EEData.drbo_NUM*8);i++)     //112  //8
                {   
                    if(gup_Buf_GUPbit != 0)
                    {
                        if((EEData.DATA[i].group[gup_Buf_GUPbyte] & ((0x01<<(8-gup_Buf_GUPbit))&0xff))!=0x00)
                        {
                            EEData.DATA[i].level = brl_Buf_LL;
#if 0                            
                            BB = (i>>3);
                            CC = i & 0x07;
                            if(CC!=0)
                            {
                                LCW_8Channel(Driving_Board_1_CTRL_ADDR + BB,lcw_V_value[EEData.DATA[BB*8].level],lcw_V_value[EEData.DATA[BB*8+1].level],lcw_V_value[EEData.DATA[BB*8+2].level],lcw_V_value[EEData.DATA[BB*8+3].level],lcw_V_value[EEData.DATA[BB*8+4].level],lcw_V_value[EEData.DATA[BB*8+5].level],lcw_V_value[EEData.DATA[BB*8+6].level],lcw_V_value[EEData.DATA[BB*8+7].level]);                     
                            }else{
                                LCW_8Channel(Driving_Board_1_CTRL_ADDR + BB-1,lcw_V_value[EEData.DATA[BB*8].level],lcw_V_value[EEData.DATA[BB*8+1].level],lcw_V_value[EEData.DATA[BB*8+2].level],lcw_V_value[EEData.DATA[BB*8+3].level],lcw_V_value[EEData.DATA[BB*8+4].level],lcw_V_value[EEData.DATA[BB*8+5].level],lcw_V_value[EEData.DATA[BB*8+6].level],lcw_V_value[EEData.DATA[BB*8+7].level]);                              
                            }
#endif
                        }
                    }else{
                        if((EEData.DATA[i].group[gup_Buf_GUPbyte] & 0x01)!=0x00)
                        {
                            EEData.DATA[i].level = brl_Buf_LL;
#if 0                            
                            BB = (i>>3);
                            CC = i & 0x07;
                            if(CC!=0)
                            {
                                LCW_8Channel(Driving_Board_1_CTRL_ADDR + BB,lcw_V_value[EEData.DATA[BB*8].level],lcw_V_value[EEData.DATA[BB*8+1].level],lcw_V_value[EEData.DATA[BB*8+2].level],lcw_V_value[EEData.DATA[BB*8+3].level],lcw_V_value[EEData.DATA[BB*8+4].level],lcw_V_value[EEData.DATA[BB*8+5].level],lcw_V_value[EEData.DATA[BB*8+6].level],lcw_V_value[EEData.DATA[BB*8+7].level]);                     
                            }else{
                                LCW_8Channel(Driving_Board_1_CTRL_ADDR + BB-1,lcw_V_value[EEData.DATA[BB*8].level],lcw_V_value[EEData.DATA[BB*8+1].level],lcw_V_value[EEData.DATA[BB*8+2].level],lcw_V_value[EEData.DATA[BB*8+3].level],lcw_V_value[EEData.DATA[BB*8+4].level],lcw_V_value[EEData.DATA[BB*8+5].level],lcw_V_value[EEData.DATA[BB*8+6].level],lcw_V_value[EEData.DATA[BB*8+7].level]);                              
                            }
#endif                            
                        }                        
                    }
                }
                for(i=0;i<EEData.drbo_NUM;i++)    //14
                {    
                   //LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[LCW_LevelData[0][i]],lcw_V_value[LCW_LevelData[1][i]],lcw_V_value[LCW_LevelData[2][i]],lcw_V_value[LCW_LevelData[3][i]],lcw_V_value[LCW_LevelData[4][i]],lcw_V_value[LCW_LevelData[5][i]],lcw_V_value[LCW_LevelData[6][i]],lcw_V_value[LCW_LevelData[7][i]]);
                   LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[EEData.DATA[8*i+0].level],lcw_V_value[EEData.DATA[8*i+1].level],lcw_V_value[EEData.DATA[8*i+2].level],lcw_V_value[EEData.DATA[8*i+3].level],lcw_V_value[EEData.DATA[8*i+4].level],lcw_V_value[EEData.DATA[8*i+5].level],lcw_V_value[EEData.DATA[8*i+6].level],lcw_V_value[EEData.DATA[8*i+7].level]);
                   //for (uint32_t z = 0; z < 40000; z++);//1ns*20000=2ms
                }                
                //FEEDBACK_UART(FEEDBACKHMIOK);
                break;
            case INX_COMP:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                break;
            case INX_REST:               
                EEPROM_Read_Data(EEPROM_FACDATA_ADDR,&EEData);
                for (uint32_t i = 0; i < 100000; i++);//1ns*20000=2ms
                EEPROM_Write_Data(EEPROM_USERDATA_ADDR1,&EEData);
#if 0               
                memset(LCW_LevelData, 0, sizeof(LCW_LevelData[0][0]) * 14 * 8);
                for(i=0;i<14;i++)
                {    
                   LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[LCW_LevelData[0][i]],lcw_V_value[LCW_LevelData[1][i]],lcw_V_value[LCW_LevelData[2][i]],lcw_V_value[LCW_LevelData[3][i]],lcw_V_value[LCW_LevelData[4][i]],lcw_V_value[LCW_LevelData[5][i]],lcw_V_value[LCW_LevelData[6][i]],lcw_V_value[LCW_LevelData[7][i]]);
                }                
#endif
                break;
            case INX_HMIX:               
                if(cmddataString[5]== '1')
                {
                  flagHMI = true;
                  type_judge = Judge_HMI;
                  //GPIO_PC23_Set();
				  FEEDBACK_UART(FEEDBACKENABLEHMI);
                  //GPIO_PC23_Clear();
                }                
                break;
            case INX_SETG:                
                EEData.drbo_NUM = (cmddataString[1]-0x30)*10 + (cmddataString[2]-0x30);
                EEData.LCW_NUM = (cmddataString[3]-0x30)*100 + (cmddataString[4]-0x30)*10 + (cmddataString[5]-0x30);
                break;
            case INX_GPIO:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                SYS_CONSOLE_PRINT("UART TEST\r\n");
                //EEData = EEDataDefault;
                //EEPROM_Write_Data(EEPROM_USERDATA_ADDR1,&EEData);
// EEPROM test  
#if 0                 
                //EEData = EEDataDefault;
                //EEData.DATA[0].level=0x05;
                //EEData.DATA[0].group[0]=0x16;
                //EEData.DATA[0].group[1]=0x25;
                //EEData.Als_table[7]=0x0504;
                //EEData.DATA[111].resv2=0x55;
                //EEData.ucSN[0]=0x38;
                //EEData.ucSN[1]=0x53;
                //EEPROM_Write_Data(EEPROM_USERDATA_ADDR1,&EEData);
    //            for (uint32_t i = 0; i < 20000; i++);//1ns*20000=2ms
               
                EEPROM_Read_Data(EEPROM_USERDATA_ADDR1,&EEData_test);
    //            for (uint32_t i = 0; i < 20000; i++);//1ns*20000=2ms

                test[0] = EEData_test.DATA[0].group[0];
                test[1] = EEData_test.DATA[1].group[0];
                test[2] = EEData_test.DATA[2].group[0];
                test[3] = EEData_test.DATA[3].group[0];
                test[4] = EEData_test.DATA[4].group[0];
                test[5] = EEData_test.DATA[5].group[0];
                test[6] = EEData_test.ucSN[0];
                test[7] = EEData_test.ucSN[1];
                test[8] = (uint8_t)((EEData_test.Als_table[7] & 0xFF00) >> 8);
                test[9] = (uint8_t)(EEData_test.Als_table[7] & 0x00FF);                
                SERCOM0_USART_Write(&test[0], 10);
#endif                
                break;
            case INX_RDIP:
                break;
            case INX_RDMA:
                break;
            case INX_RDAL:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                if(cmddataString[5] == '1')
                {
                	FEEDBACK_UART(FEEDBACKRDAL);
                }
                break;
            case INX_RDST:
                break;
            case INX_RDBT:
                break;
            case INX_DEBG:
                break;
            case INX_USSV:
                //EEData = EEDataDefault;
                //EEData.DATA[0].level=0x06;
                //EEData.DATA[0].group[0]=0x16;
                //EEData.DATA[0].group[1]=0x18;
                //EEData.Als_table[7]=0x0304;
                //EEData.DATA[111].resv2=0x33;
                //EEData.ucSN[0]=0x38;
                //EEData.ucSN[1]=0x52;                
                if(cmddataString[5] == '1')
                {                
                    EEPROM_Write_Data(EEPROM_USERDATA_ADDR1,&EEData);              
                }
                if(cmddataString[5] == '2')
                {                
                    EEPROM_Write_Data(EEPROM_USERDATA_ADDR2,&EEData);
                }
                if(cmddataString[5] == '3')
                {                
                    EEPROM_Write_Data(EEPROM_USERDATA_ADDR3,&EEData);
                }
                //for (uint32_t i = 0; i < 100000; i++);//1ns*20000=2ms
                FEEDBACK_UART(FEEDBACKDEMOGROUPINITOK);                
                break; 
            case INX_USRL:
                //EEData_test = EEDataDefault;
                if(cmddataString[5] == '1')
                {
                    EEPROM_Read_Data(EEPROM_USERDATA_ADDR1,&EEData_test);                     
                }
                if(cmddataString[5] == '2')
                {
                    EEPROM_Read_Data(EEPROM_USERDATA_ADDR2,&EEData_test);                    
                }
                if(cmddataString[5] == '3')
                {
                    EEPROM_Read_Data(EEPROM_USERDATA_ADDR3,&EEData_test);                    
                }
                //test[0] = EEData_test.DATA[0].level;
                //test[1] = EEData_test.DATA[0].group[0];
                //test[2] = EEData_test.DATA[0].group[1];
                //test[3] = EEData_test.DATA[0].group[2];
                //test[4] = EEData_test.DATA[0].group[3];
                //test[5] = EEData_test.DATA[111].resv2;
                //test[6] = EEData_test.ucSN[0];
                //test[7] = EEData_test.ucSN[1];
                //test[8] = (uint8_t)((EEData_test.Als_table[7] & 0xFF00) >> 8);
                //test[9] = (uint8_t)(EEData_test.Als_table[7] & 0x00FF);
#if 0               
                //test[0] = EEData_test.DATA[0].group[0];
                //test[1] = EEData_test.DATA[1].group[0];
                //test[2] = EEData_test.DATA[2].group[0];
                //test[3] = EEData_test.DATA[3].group[0];
                //test[4] = EEData_test.DATA[4].group[0];
                //test[5] = EEData_test.DATA[5].group[0];
                //SERCOM0_USART_Write(&test[0], 6);
                
                //test[0] = EEData_test.drbo_NUM;
                //SERCOM0_USART_Write(&test[0], 1);
                //test[0] = EEData_test.LCW_NUM;
                //SERCOM0_USART_Write(&test[0], 1);                 
#else  
                EELCW_NUM = EEData_test.LCW_NUM;
                //test[0] = EELCW_NUM;
                //SERCOM0_USART_Write(&test[0], 1);                
                if(cmddataString[2] == '1')
                {
                    for(i = 0; i < EELCW_NUM ; i++)
                    {
                    test[0] = EEData_test.DATA[i].level;
                    test[1] = EEData_test.DATA[i].group[0];
                    test[2] = EEData_test.DATA[i].group[1];
                    test[3] = EEData_test.DATA[i].group[2];
                    test[4] = EEData_test.DATA[i].group[3];
                    test[5] = EEData_test.DATA[i].compensation;
                    test[6] = EEData_test.DATA[i].resv1;
                    test[7] = EEData_test.DATA[i].resv2;
                    SERCOM0_USART_Write(&test[0], 8);
                    for (j = 0; j < 40000; j++); //25nsx40000=1000us for delay to next command.
                    }
                }
                if(cmddataString[2] == '2')
                {                
                    for(i = 0; i < 15 ; i++)
                    {                
                    test[i] = EEData_test.ucSN[i];
                    SERCOM0_USART_Write(&test[0], 1);
                    }
                }
                if(cmddataString[2] == '3')
                {                
                    for(i = 0; i < 15 ; i++)
                    {                
                    test[i] = EEData_test.ucModelnm[i];
                    SERCOM0_USART_Write(&test[0], 1);
                    }
                }
                if(cmddataString[2] == '4')
                {                
                    test[0] = EEData_test.drbo_NUM;
                    SERCOM0_USART_Write(&test[0], 1);
                }
                if(cmddataString[2] == '5')
                {                
                    test[0] = EEData_test.LCW_NUM;
                    SERCOM0_USART_Write(&test[0], 1);
                }
                if(cmddataString[2] == '6')
                {                
                    test[0] = (uint8_t)((EEData_test.Als_max & 0xFF00) >> 8);
                    test[1] = (uint8_t)(EEData_test.Als_max & 0x00FF);
                    SERCOM0_USART_Write(&test[0], 2);
                }
                if(cmddataString[2] == '7')
                {                
                    test[0] = (uint8_t)((EEData_test.Als_min & 0xFF00) >> 8);
                    test[1] = (uint8_t)(EEData_test.Als_min & 0x00FF);
                    SERCOM0_USART_Write(&test[0], 2);
                }
                if(cmddataString[2] == '8')
                {                
                    for(i = 0; i < 8 ; i++)
                    {
                    test[0] = (uint8_t)((EEData_test.Als_table[i] & 0xFF00) >> 8);
                    test[1] = (uint8_t)(EEData_test.Als_table[i] & 0x00FF);
                    SERCOM0_USART_Write(&test[0], 2);
                    }
                }
                if(cmddataString[2] == '9')
                {                
                    test[0] = (uint8_t)((EEData_test.Als_target & 0xFF00) >> 8);
                    test[1] = (uint8_t)(EEData_test.Als_target & 0x00FF);
                    SERCOM0_USART_Write(&test[0], 2);
                }
                //SERCOM0_USART_Write(&test[0], EECount+1);
#endif                
                break; 
            case INX_EEPR:
                if(cmddataString[5] == '1')
                {
                    //EEData = EEDataDefault;
                    EEPROM_Write_Data(EEPROM_FACDATA_ADDR,&EEData);
                }
#if 1               
                else if(cmddataString[5] == '0'){
                    EEData = EEDataDefault;
                    EEPROM_Write_Data(EEPROM_FACDATA_ADDR,&EEData);
                }
                EEPROM_Read_Data(EEPROM_FACDATA_ADDR,&EEData_test);
#endif
                //test[0] = EEData_test.DATA[0].level;
                //test[1] = EEData_test.DATA[0].group[0];
                //test[2] = EEData_test.DATA[0].group[1];
                //test[3] = EEData_test.DATA[0].group[2];
                //test[4] = EEData_test.DATA[0].group[3];
                //test[5] = EEData_test.DATA[111].resv2;
                //test[6] = EEData_test.ucSN[0];
                //test[7] = EEData_test.ucSN[1];
                //test[8] = (uint8_t)((EEData_test.Als_table[7] & 0xFF00) >> 8);
                //test[9] = (uint8_t)(EEData_test.Als_table[7] & 0x00FF);                
                //SERCOM0_USART_Write(&test[0], 10);                
                break;
            case INX_TRGT:
                EEData.Als_target = (cmddataString[1]-0x30)*10000 + (cmddataString[2]-0x30)*1000 + (cmddataString[3]-0x30)*100 + (cmddataString[4]-0x30)*10 + (cmddataString[5]-0x30);               
                break;
            case INX_SETP:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                if(cmddataString[5]=='1')
                {
                    flagALS_Read = true;
                    flagALS_TAR = false;
                }                
                if(cmddataString[5]=='2')
                {
                    flagALS_Read = true;
                }
                if(cmddataString[5]=='3')
                {
                    flagALS_Read = false;
                }
                break;
            case INX_INVL:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                for(i=0;i<EEData.drbo_NUM;i++)  //14
                {
                    for(j=0;j<8;j++)
                    {
                        EEData.DATA[8*i+j].level = lcw_inverce_value[EEData.DATA[8*i+j].level];
                    }
                }
                for(i=0;i<EEData.drbo_NUM;i++)   //14
                {    
                   LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[EEData.DATA[8*i+0].level],lcw_V_value[EEData.DATA[8*i+1].level],lcw_V_value[EEData.DATA[8*i+2].level],lcw_V_value[EEData.DATA[8*i+3].level],lcw_V_value[EEData.DATA[8*i+4].level],lcw_V_value[EEData.DATA[8*i+5].level],lcw_V_value[EEData.DATA[8*i+6].level],lcw_V_value[EEData.DATA[8*i+7].level]);
                   //for (uint32_t z = 0; z < 40000; z++);//1ns*20000=2ms
                }                
                break;
            case INX_MODL:
                if(cmddataString[0]=='1')
                {
                 EEData.ucModelnm[0] = cmddataString[1];
                 EEData.ucModelnm[1] = cmddataString[2];
                 EEData.ucModelnm[2] = cmddataString[3];
                 EEData.ucModelnm[3] = cmddataString[4];
                 EEData.ucModelnm[4] = cmddataString[5];
                 
                }else if(cmddataString[0]=='2')
                {
                 EEData.ucModelnm[5] = cmddataString[1];
                 EEData.ucModelnm[6] = cmddataString[2];
                 EEData.ucModelnm[7] = cmddataString[3];
                 EEData.ucModelnm[8] = cmddataString[4];
                 EEData.ucModelnm[9] = cmddataString[5];                    
                }else if(cmddataString[0]=='3')
                {
                 EEData.ucModelnm[10] = cmddataString[1];
                 EEData.ucModelnm[11] = cmddataString[2];
                 EEData.ucModelnm[12] = cmddataString[3];
                 EEData.ucModelnm[13] = cmddataString[4];
                 EEData.ucModelnm[14] = cmddataString[5];                    
                }else if(cmddataString[0]=='0' && cmddataString[5]=='1')
                {
                     FEEDBACK_UART(FEEDBACKMODL);
                }
                break;                
            case INX_SERL:
                if(cmddataString[0]=='1')
                {
                 EEData.ucSN[0] = cmddataString[1];
                 EEData.ucSN[1] = cmddataString[2];
                 EEData.ucSN[2] = cmddataString[3];
                 EEData.ucSN[3] = cmddataString[4];
                 EEData.ucSN[4] = cmddataString[5];
                 
                }else if(cmddataString[0]=='2')
                {
                 EEData.ucSN[5] = cmddataString[1];
                 EEData.ucSN[6] = cmddataString[2];
                 EEData.ucSN[7] = cmddataString[3];
                 EEData.ucSN[8] = cmddataString[4];
                 EEData.ucSN[9] = cmddataString[5];                    
                }else if(cmddataString[0]=='3')
                {
                 EEData.ucSN[10] = cmddataString[1];
                 EEData.ucSN[11] = cmddataString[2];
                 EEData.ucSN[12] = cmddataString[3];
                 EEData.ucSN[13] = cmddataString[4];
                 EEData.ucSN[14] = cmddataString[5];                    
                }else if(cmddataString[0]=='0' && cmddataString[5]=='1')
                {
                     FEEDBACK_UART(FEEDBACKSERL);
                }                
                break;
            case INX_MOVR:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                for(i=EEData.LCW_NUM-1;i>0;i--)     //23pcs LCW   for(i=22;i>0;i--)
                {
                   EEData.DATA[i].level = EEData.DATA[i-1].level;
                }
                   EEData.DATA[0].level = cmddataString[5] - 0x30;
                for(i=0;i<EEData.drbo_NUM;i++)   //14
                {    
                   LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[EEData.DATA[8*i+0].level],lcw_V_value[EEData.DATA[8*i+1].level],lcw_V_value[EEData.DATA[8*i+2].level],lcw_V_value[EEData.DATA[8*i+3].level],lcw_V_value[EEData.DATA[8*i+4].level],lcw_V_value[EEData.DATA[8*i+5].level],lcw_V_value[EEData.DATA[8*i+6].level],lcw_V_value[EEData.DATA[8*i+7].level]);
                   //for (uint32_t z = 0; z < 40000; z++);//1ns*20000=2ms
                }                   
                break;
            case INX_MOVL:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif               
                for(i=0;i<(EEData.LCW_NUM-1);i++)     //23pcs LCW   for(i=0;i<22;i++)
                {
                   EEData.DATA[i].level = EEData.DATA[i+1].level;
                }
                   EEData.DATA[EEData.LCW_NUM-1].level = cmddataString[5] - 0x30;      //EEData.DATA[22].level
                for(i=0;i<EEData.drbo_NUM;i++)   //14
                {    
                   LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[EEData.DATA[8*i+0].level],lcw_V_value[EEData.DATA[8*i+1].level],lcw_V_value[EEData.DATA[8*i+2].level],lcw_V_value[EEData.DATA[8*i+3].level],lcw_V_value[EEData.DATA[8*i+4].level],lcw_V_value[EEData.DATA[8*i+5].level],lcw_V_value[EEData.DATA[8*i+6].level],lcw_V_value[EEData.DATA[8*i+7].level]);
                   //for (uint32_t z = 0; z < 40000; z++);//1ns*20000=2ms
                }                   
                break;
            case INX_MVIN:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                if((EEData.LCW_NUM%2) > 0)                   //odd
                {     
                    MVIN_L = ((EEData.LCW_NUM-1)/2) - 1;
                    MVIN_R = ((EEData.LCW_NUM-1)/2) + 1;
                }else{                                       //even
                    MVIN_L = (EEData.LCW_NUM/2) - 1;
                    MVIN_R = EEData.LCW_NUM/2;
                }                
                for(i=MVIN_L;i>0;i--)     //23pcs LCW    for(i=10;i>0;i--)
                {
                   EEData.DATA[i].level = EEData.DATA[i-1].level;
                }
                   EEData.DATA[0].level = cmddataString[1] - 0x30;
                for(i=MVIN_R;i<(EEData.LCW_NUM-1);i++)     //23pcs LCW   for(i=12;i<22;i++)
                {
                   EEData.DATA[i].level = EEData.DATA[i+1].level;
                }
                   EEData.DATA[(EEData.LCW_NUM-1)].level = cmddataString[3] - 0x30;         //EEData.DATA[22].level
                if((EEData.LCW_NUM%2) > 0)                   //odd
                {                   
                   EEData.DATA[(EEData.LCW_NUM-1)/2].level = cmddataString[5] - 0x30;        //EEData.DATA[11].level
                }

                for(i=0;i<EEData.drbo_NUM;i++)   //14
                {    
                   LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[EEData.DATA[8*i+0].level],lcw_V_value[EEData.DATA[8*i+1].level],lcw_V_value[EEData.DATA[8*i+2].level],lcw_V_value[EEData.DATA[8*i+3].level],lcw_V_value[EEData.DATA[8*i+4].level],lcw_V_value[EEData.DATA[8*i+5].level],lcw_V_value[EEData.DATA[8*i+6].level],lcw_V_value[EEData.DATA[8*i+7].level]);
                   //for (uint32_t z = 0; z < 40000; z++);//1ns*20000=2ms
                }                   
                break;
            case INX_MVOU:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                if((EEData.LCW_NUM%2) > 0)                   //odd
                {                 
                    MVOU_L = ((EEData.LCW_NUM-1)/2) - 1;
                    MVOU_R = ((EEData.LCW_NUM-1)/2) + 1;
                }else{                                       //even
                    MVOU_L = (EEData.LCW_NUM/2) - 1;
                    MVOU_R = EEData.LCW_NUM/2;
                }                
                for(i=EEData.LCW_NUM-1;i>MVOU_R;i--)     //23pcs LCW     for(i=22;i>12;i--)
                {
                   EEData.DATA[i].level = EEData.DATA[i-1].level;
                }
                   EEData.DATA[MVOU_R].level = cmddataString[1] - 0x30;
                for(i=0;i<MVOU_L;i++)     //23pcs LCW     for(i=0;i<10;i++)
                {
                   EEData.DATA[i].level = EEData.DATA[i+1].level;
                }
                   EEData.DATA[MVOU_L].level = cmddataString[3] - 0x30;
                if((EEData.LCW_NUM%2) > 0)                   //odd
                {                   
                   EEData.DATA[(EEData.LCW_NUM-1)/2].level = cmddataString[5] - 0x30;
                }
                for(i=0;i<EEData.drbo_NUM;i++)   //14
                {    
                   LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[EEData.DATA[8*i+0].level],lcw_V_value[EEData.DATA[8*i+1].level],lcw_V_value[EEData.DATA[8*i+2].level],lcw_V_value[EEData.DATA[8*i+3].level],lcw_V_value[EEData.DATA[8*i+4].level],lcw_V_value[EEData.DATA[8*i+5].level],lcw_V_value[EEData.DATA[8*i+6].level],lcw_V_value[EEData.DATA[8*i+7].level]);
                   //for (uint32_t z = 0; z < 40000; z++);//1ns*20000=2ms
                }                   
                break;
            case INX_RAWC:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif                
                boardnum = (cmddataString[0]-0x30)*10+(cmddataString[1]-0x30);
                EEData.DATA[(boardnum-1)*8].level = (cmddataString[2] & 0xf0) >> 4;
                EEData.DATA[(boardnum-1)*8+1].level = cmddataString[2] & 0x0f;
                EEData.DATA[(boardnum-1)*8+2].level = (cmddataString[3] & 0xf0) >> 4;
                EEData.DATA[(boardnum-1)*8+3].level = cmddataString[3] & 0x0f;
                EEData.DATA[(boardnum-1)*8+4].level = (cmddataString[4] & 0xf0) >> 4;
                EEData.DATA[(boardnum-1)*8+5].level = cmddataString[4] & 0x0f;
                EEData.DATA[(boardnum-1)*8+6].level = (cmddataString[5] & 0xf0) >> 4;
                EEData.DATA[(boardnum-1)*8+7].level = cmddataString[5] & 0x0f;
                break;
            case INX_SHOW:
#if 0               
                if(flagALS == true || flagALS_TAR == true)
                {
                    flagALS = false;
                    flagALS_TAR = false;
                }
#endif               
                if(cmddataString[5]=='1')
                {                
                    for(i=0;i<EEData.drbo_NUM;i++)   //14
                    {    
                       LCW_8Channel(Driving_Board_1_CTRL_ADDR + i,lcw_V_value[EEData.DATA[8*i+0].level],lcw_V_value[EEData.DATA[8*i+1].level],lcw_V_value[EEData.DATA[8*i+2].level],lcw_V_value[EEData.DATA[8*i+3].level],lcw_V_value[EEData.DATA[8*i+4].level],lcw_V_value[EEData.DATA[8*i+5].level],lcw_V_value[EEData.DATA[8*i+6].level],lcw_V_value[EEData.DATA[8*i+7].level]);
                       //for (uint32_t z = 0; z < 40000; z++);//1ns*20000=2ms
                    }
                }
                break;                
        }
        ret = 0;
     return ret;        
}

uint16_t Command_HexToDec(int num, char *buffer)
{
    uint8_t Als_buf[num];
    uint16_t Als_sum = 0;
    int i,j;
    memset(Als_buf, 0, num);
    
for(i=0;i<num;i++)
{
    if((buffer[i] > 0x60) && (buffer[i] < 0x67)) {
    Als_buf[i] = buffer[i]-0x61 + 0x0a;   
    }else if((buffer[i] > 0x40) && (buffer[i] < 0x47)){
    Als_buf[i] = buffer[i]-0x41 + 0x0a; 
    }else{
    Als_buf[i] = buffer[i] - 0x30;
    }
    //SYS_CONSOLE_PRINT("Als_buf = %x\r\n", Als_buf[i]);
}
    //Als_sum = Als_buf[0]*16*16*16 + Als_buf[1]*16*16 + Als_buf[2]*16 + Als_buf[3];
for(j=0;j<num-1;j++)
{    
    //Als_sum = Als_buf[0]*16*16*16 + Als_buf[1]*16*16 + Als_buf[2]*16 + Als_buf[3];
    Als_sum = Als_sum + Als_buf[j]*pow(16,num-1-j);
    //SYS_CONSOLE_PRINT("Als_sum = %x\r\n", Als_buf[j]*lcw_pow(16,num-1-j));
}
    Als_sum = Als_sum + Als_buf[num-1];
    //SYS_CONSOLE_PRINT("Als_sum = %x\r\n", Als_sum);
    return Als_sum;
}

uint16_t lcw_pow(uint16_t x,uint16_t n)
{
    int y;
    int s = x;
    for(y=0;y<(n-1);y++){
    s=x*s;
    }
    return s;
}

void FEEDBACK_UART(unsigned char n)
{
	//uint8_t TXCMD[40];
    uint8_t *TXCMD = calloc(40, sizeof(uint8_t *));
	uint8_t	TXBufSize;
    char Als_read_Buf[6];
	switch(n){
				case FEEDBACKOK:
					 TXBufSize = 5;
                     TXCMD[0]=(char) 'O';
                     TXCMD[1]=(char) 'K';
                     for (int k = TXBufSize-3; k < TXBufSize; k++)
                     {
                       TXCMD[k] = HMI_End_Byte;
                     }
                     SERCOM0_USART_Write(TXCMD, TXBufSize);                     
					break;
				case FEEDBACKNG:
					 TXBufSize = 5;
                     TXCMD[0]=(char) 'N';
                     TXCMD[1]=(char) 'G';
                     for (int k = TXBufSize-3; k < TXBufSize; k++)
                     {
                       TXCMD[k] = HMI_End_Byte;
                     }
                     SERCOM0_USART_Write(TXCMD, TXBufSize);                     
					break;
				case FEEDBACKENABLEHMI:
					 TXBufSize = 9;
                     TXCMD[0]=(char) 's';
                     TXCMD[1]=(char) 'y';
                     TXCMD[2]=(char) 's';
                     TXCMD[3]=(char) '0';
                     TXCMD[4]=(char) '=';
                     TXCMD[5]=(char) '0';                    
#if 0                   
					 TXBufSize = 13;
                     TXCMD[0]=(char) 'c';
                     TXCMD[1]=(char) 'h';
                     TXCMD[2]=(char) 'e';
                     TXCMD[3]=(char) 'c';
                     TXCMD[4]=(char) 'k';
                     TXCMD[5]=(char) '.';
                     TXCMD[6]=(char) 'e';  
                     TXCMD[7]=(char) 'n';
                     TXCMD[8]=(char) '=';
                     TXCMD[9]=(char) '0';     
#endif                     
                     //SYS_CONSOLE_MESSAGE("\r\n");
                     for (int k = TXBufSize-3; k < TXBufSize; k++)
                     {
                       TXCMD[k] = HMI_End_Byte;
                     }
                     SERCOM0_USART_Write(TXCMD, TXBufSize);
					break;
			    case FEEDBACKRDAL:
				
					//TXBufSize = 9;
					Als_read = ALS_Read(ALS_1_CTRL_ADDR);
					HexToDec(Als_read, Als_read_Buf);
                    MCU_TX_HMI(Als_read_Buf);
#if	0                    
				    for (int i = 0; i < (TXBufSize-3); i++)
				    {
				        TXCMD[i] = (char) Als_read_Buf[i];
				    }
				    //SYS_CONSOLE_MESSAGE("\r\n");
				    for (int k = TXBufSize-3; k < TXBufSize; k++)
				    {
				        TXCMD[k] = HMI_End_Byte;
				    }	
#endif					
					break;
                case FEEDBACKHMIOK:
                     TXBufSize = 13;
                     TXCMD[0]=(char) 'g';
                     TXCMD[1]=(char) 'r';
                     TXCMD[2]=(char) 'e';
                     TXCMD[3]=(char) 'e';
                     TXCMD[4]=(char) 'n';
                     TXCMD[5]=(char) '.';
                     TXCMD[6]=(char) 'e';  
                     TXCMD[7]=(char) 'n';
                     TXCMD[8]=(char) '=';
                     TXCMD[9]=(char) '1';     
                     //SYS_CONSOLE_MESSAGE("\r\n");
                     for (int k = TXBufSize-3; k < TXBufSize; k++)
                     {
                       TXCMD[k] = HMI_End_Byte;
                     }
                     SERCOM0_USART_Write(TXCMD, TXBufSize);
                    break;
                case FEEDBACKHMING:
                     TXBufSize = 11;
                     TXCMD[0]=(char) 'r';
                     TXCMD[1]=(char) 'e';
                     TXCMD[2]=(char) 'd';
                     TXCMD[3]=(char) '.';
                     TXCMD[4]=(char) 'e';
                     TXCMD[5]=(char) 'n';
                     TXCMD[6]=(char) '=';  
                     TXCMD[7]=(char) '1';    
                     //SYS_CONSOLE_MESSAGE("\r\n");
                     for (int k = TXBufSize-3; k < TXBufSize; k++)
                     {
                       TXCMD[k] = HMI_End_Byte;
                     }
                     SERCOM0_USART_Write(TXCMD, TXBufSize);
                    break;
                case FEEDBACKDEMOGROUPINITOK:
					 TXBufSize = 9;
                     TXCMD[0]=(char) 's';
                     TXCMD[1]=(char) 'y';
                     TXCMD[2]=(char) 's';
                     TXCMD[3]=(char) '1';
                     TXCMD[4]=(char) '=';
                     TXCMD[5]=(char) '1';                                        
                     //SYS_CONSOLE_MESSAGE("\r\n");
                     for (int k = TXBufSize-3; k < TXBufSize; k++)
                     {
                       TXCMD[k] = HMI_End_Byte;
                     }
                     SERCOM0_USART_Write(TXCMD, TXBufSize);                    
                    break;
                case FEEDBACKMANUALNEWLEVEL:
					 TXBufSize = 18;
                     TXCMD[0]=(char) 'c';
                     TXCMD[1]=(char) 'l';
                     TXCMD[2]=(char) 'i';
                     TXCMD[3]=(char) 'c';
                     TXCMD[4]=(char) 'k';
                     TXCMD[5]=(char) ' ';
                     TXCMD[6]=(char) 'l';
                     TXCMD[7]=(char) 'e';
                     TXCMD[8]=(char) 'v';
                     TXCMD[9]=(char) 'e';
                     TXCMD[10]=(char) 'l';
                     TXCMD[11]=(char) '_';
                     TXCMD[12]=(char) (EEData.DATA[0].level+0x30);
                     TXCMD[13]=(char) ',';
                     TXCMD[14]=(char) '1';
                     //SYS_CONSOLE_MESSAGE("\r\n");
                     for (int k = TXBufSize-3; k < TXBufSize; k++)
                     {
                       TXCMD[k] = HMI_End_Byte;
                     }
                     SERCOM0_USART_Write(TXCMD, TXBufSize);                     
                    break;
                case FEEDBACKMODL:
					 TXBufSize = 34;
                     TXCMD[0]=(char) 'm';
                     TXCMD[1]=(char) 'o';
                     TXCMD[2]=(char) 'd';
                     TXCMD[3]=(char) 'l';
                     TXCMD[4]=(char) '_';
                     TXCMD[5]=(char) 'n';
                     TXCMD[6]=(char) 'a';
                     TXCMD[7]=(char) 'm';
                     TXCMD[8]=(char) 'e';
                     TXCMD[9]=(char) '.';
                     TXCMD[10]=(char) 't';
                     TXCMD[11]=(char) 'x';
                     TXCMD[12]=(char) 't';
                     TXCMD[13]=(char) '=';
                     
                     TXCMD[14]=(char) '"';
                     for (int k = 0; k < 15; k++)
                     {
                     TXCMD[k+15]=(char) (EEData.ucModelnm[k]);
                     }
                     TXCMD[30]=(char) '"';
#if 1                    
                     for (int k = TXBufSize-3; k < TXBufSize; k++)
                     {
                       TXCMD[k] = HMI_End_Byte;
                     }
#endif                     
                     SERCOM0_USART_Write(TXCMD, TXBufSize);
                    break;
                case FEEDBACKSERL:
					 TXBufSize = 34;
                     TXCMD[0]=(char) 's';
                     TXCMD[1]=(char) 'e';
                     TXCMD[2]=(char) 'r';
                     TXCMD[3]=(char) 'l';
                     TXCMD[4]=(char) '_';
                     TXCMD[5]=(char) 'n';
                     TXCMD[6]=(char) 'a';
                     TXCMD[7]=(char) 'm';
                     TXCMD[8]=(char) 'e';
                     TXCMD[9]=(char) '.';
                     TXCMD[10]=(char) 't';
                     TXCMD[11]=(char) 'x';
                     TXCMD[12]=(char) 't';
                     TXCMD[13]=(char) '=';
                     TXCMD[14]=(char) '"';
                     for (int k = 0; k < 15; k++)
                     {
                     TXCMD[k+15]=(char) (EEData.ucSN[k]);
                     }
                     TXCMD[30]=(char) '"';
#if 1                     
                     for (int k = TXBufSize-3; k < TXBufSize; k++)
                     {
                       TXCMD[k] = HMI_End_Byte;
                     }
#endif                     
                     SERCOM0_USART_Write(TXCMD, TXBufSize);                     
                    break;                    
	       	}
	        //SERCOM0_USART_Write(TXCMD, TXBufSize);
free(TXCMD);
}

/* ************************************************************************** */
// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
/*
int ExampleInterfaceFunction(int param1, int param2) {
    return 0;
}
*/

/* *****************************************************************************
 End of File
 */
