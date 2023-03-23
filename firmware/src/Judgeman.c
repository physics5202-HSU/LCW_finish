/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    Judgeman.c

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
/* TODO:  Include other files here if needed. */
//int GPIO_PreStatus=1;
//bool GPIO_ButtonStatus = True;

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
//static int ExampleLocalFunction(int param1, int param2) {
   // return 0;
//}


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
#if 0
bool threadALS(void)
{
  #if 0  
    volatile I2C1_TRANSFER_STATUS transferStatusCmd = I2C1_TRANSFER_STATUS_ERROR;
    int count=0;
    bool data_judge = False;
    SERCOM7_I2C_CallbackRegister( I2C1_Callback, (uintptr_t)&transferStatusCmd );
    uint8_t pwron[1];
    transferStatusCmd = I2C1_TRANSFER_STATUS_IN_PROGRESS;
    pwron[0] = 0x01;
    SERCOM7_I2C_Write(ALS_1_CTRL_ADDR, &pwron[0], 1);
    count=0;
    
    while (transferStatusCmd != I2C1_TRANSFER_STATUS_SUCCESS)
    {
        count++;
        if(count > I2C_Delay_ns)    
        {
            data_judge = False;
            break;
        }
    }
    if(transferStatusCmd == I2C1_TRANSFER_STATUS_SUCCESS)
    {
      data_judge = True;
    }    
#else
    bool data_judge = False;
    Als_read = ALS_Read(ALS_1_CTRL_ADDR);
    if(Als_read < 0x2614 && Als_read != 0x0614)
    {
      data_judge = True;
    }else{
      data_judge = False;
    }
#endif    
 return data_judge;  
}        
bool threadGPIO(void)
{
    //GPIO_PreStatus=1;
    //GPIO_ButtonStatus = True;
    GPIO_Now=GPIO_PC22_Get();
    //bool data_judge = False;
    if (GPIO_PreStatus != GPIO_Now)
    {
        GPIO_PreStatus = GPIO_Now;

        if(GPIO_Now == 0)
        {//1-->0 Press button 
         //SYS_CONSOLE_PRINT("Do Nothing\r\n");
        }
        else
        {//0-->1 Complete button click
            if(GPIO_ButtonStatus == False)
            {//0-->1
             //SYS_CONSOLE_PRINT("0-->1\r\n");
             GPIO_ButtonStatus=True;
             //data_judge = GPIO_ButtonStatus;
            }else
            {//1-->0
             //SYS_CONSOLE_PRINT("1-->0\r\n");
             GPIO_ButtonStatus=False;
             //data_judge = GPIO_ButtonStatus;
            }
        }                    
    }
     return GPIO_ButtonStatus;    
}

bool threadADC(void)
{
    preADC_data = 0;
    bool data_judge = False;
    ADC0_Enable();
    ADC0_ConversionStart();
    //ADC0_EventHandler(&adc0_data);
    if(ADC0_ConversionStatusGet())
    {
      uint16_t v_adc=ADC0_ConversionResultGet();
      newADC_data = v_adc;
      if((newADC_data - preADC_data) < 3000)
      {
         data_judge = True;
      }
    }else{
    data_judge = False;
    } 
    return data_judge;
}

void threadJudgeman(void)
{
  flagALS = threadALS();
  if(flagALS == true)
  {
       //ALS_AutoRun();
      Als_Crlon = 1;
      flagADC = false;
      flagGPIO = false;
      flagHMI = false;
  }else{
      Als_Crlon = 0;
  }
  
  flagGPIO = threadGPIO();
  if(flagGPIO == true)
  {
      //GPIO_ButtonStatus=False;
      //Als_Crlon = 0;
      flagALS = false;
      flagADC = false;
      flagHMI = false;
  }
  
  flagADC = threadADC();
  if(flagADC == true)
  {
      //Als_Crlon = 0;
      flagALS = false;
      flagGPIO = false;
      flagHMI = false;
      
  }
  
  if(flagHMI == true)
  {
    flagALS = false;
    flagGPIO = false;
    flagADC = false;  
  } 
  
  switch(type_judge)
  {
      case Judge_ALS:
            flagADC = false;
            flagGPIO = false;
            flagHMI = false;
          break;
      case Judge_ADC:
            flagALS = false;
            flagGPIO = false;
            flagHMI = false;          
          break;
      case Judge_GPIO:
            flagALS = false;
            flagADC = false;
            flagHMI = false;          
          break;
      case Judge_HMI:
            flagALS = false;
            flagGPIO = false;
            flagADC = false;          
          break;          
  }
}
#else
void threadALS(void)
{
    //type_judge = Judge_HMI;
    Als_read = ALS_Read(ALS_1_CTRL_ADDR);
    //if(Als_read < 0x2614 && Als_read > 0x00 && Als_read != 0x0614)
    if(Als_read != 0x2614 && Als_read != 0x00 && Als_read != 0x0614)    
    {
      type_judge = Judge_ALS;
    }else{
      type_judge = Judge_NO;
    }   
}        
void threadGPIO(void)
{
    //GPIO_PreStatus=1;
    //GPIO_ButtonStatus = True;
    GPIO_Now=GPIO_PC22_Get();
    //bool data_judge = False;
    if (GPIO_PreStatus != GPIO_Now)
    {
        GPIO_PreStatus = GPIO_Now;

        if(GPIO_Now == 0)
        {//1-->0 Press button 
         //SYS_CONSOLE_PRINT("Do Nothing\r\n");
        }
        else
        {//0-->1 Complete button click
            if(GPIO_ButtonStatus == False)
            {//0-->1
             //SYS_CONSOLE_PRINT("0-->1\r\n");
             GPIO_ButtonStatus=True;
             type_judge = Judge_GPIO;
             //data_judge = GPIO_ButtonStatus;
            }else
            {//1-->0
             //SYS_CONSOLE_PRINT("1-->0\r\n");
             GPIO_ButtonStatus=False;
             //type_judge = Judge_NO;
             //data_judge = GPIO_ButtonStatus;
            }
        }                    
    }   
}

void threadADC(void)
{
#if 1
    preADC_data = 0;
    //bool data_judge = False;
    ADC0_Enable();
    ADC0_ConversionStart();
    //ADC0_EventHandler(&adc0_data);
    if(ADC0_ConversionStatusGet())
    {
      uint16_t v_adc=ADC0_ConversionResultGet();
      newADC_data = v_adc;
      //if((newADC_data - preADC_data) < 3000)
      if((newADC_data - preADC_data) < 0x10)
      {
         type_judge = Judge_ADC;
      }
    }else{
    //type_judge = Judge_NO;
    } 
#else
    //preADC_data = 0;
    //bool data_judge = False;
    ADC0_Enable();
    ADC0_ConversionStart();
    //ADC0_EventHandler(&adc0_data);
    if(ADC0_ConversionStatusGet())
    {
      uint16_t v_adc=ADC0_ConversionResultGet();
      newADC_data = v_adc;
      //if((newADC_data - preADC_data) < 3000)
      if((preADC_data - newADC_data) > 0x7FF)
      {
         type_judge = Judge_ADC;
      }
    }else{
        preADC_data = newADC_data;
        type_judge = Judge_NO;
    }    
#endif    
}

void threadUART(void)
{
    if (SERCOM0_USART_ReadCountGet() > 0) 
    {
        type_judge = Judge_UART;
    }else{
        //type_judge = Judge_NO;
    }
}
void threadJudgeman(void)
{
  //threadALS();
  threadGPIO();
  threadADC();
  threadUART();
  
  switch(type_judge)
  {
      case Judge_ALS:
            //flagALS = True;
            //flagADC = false;
            //flagGPIO = false;
            //flagHMI = false;
            //Als_Crlon = 1;
          break;
      case Judge_ADC:
            //flagALS = false;
            flagADC = True;
            flagGPIO = false;
            //flagHMI = false;         
          break;
      case Judge_GPIO:
            //flagALS = false;
            flagADC = false;
            //flagHMI = false;
            flagGPIO = True;              
          break;
      case Judge_HMI:
            //flagALS = false;
            //flagADC = false;
            //flagGPIO = false;
            //flagHMI = True;          
          break;
      case Judge_NO:
            //Als_Crlon = 0;
          break;
      case Judge_UART:
            //Als_Crlon = 0;
            //flagALS = false;
            flagADC = false;
            flagGPIO = false;
          break;          
  }
}
#endif
// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
//int ExampleInterfaceFunction(int param1, int param2) {
  //  return 0;
//}


/* *****************************************************************************
 End of File
 */
