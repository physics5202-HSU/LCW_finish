/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    uart_command.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _UART_COMMAND_H    /* Guard against multiple inclusion */
#define _UART_COMMAND_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


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
//#define EXAMPLE_CONSTANT 0
    
#define LCW_CMD_NUM 34				
#define LCW_CMD_LEN 4 

#define UART_Start_Byte 0x24     //$$$
#define UART_End_Byte 0x23       //###
    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */
//extern EEPROMData EEData;    
int LCW_LevelData[8][14];    //driving board 14 ch 8     
enum {		    //RS232 Command Execute
	INX_MODE=0, //Interface Mode
	INX_ALSX,	//set ALS min/max
	INX_ALLX,   //set all lcw
	INX_BDCH,   //set one lcw
    INX_GRUP,   //add one lcw to group
    INX_GPLV,   //set lcw group level
    INX_COMP,   //gain -/+
    INX_REST,   //reset data 
    INX_HMIX,   //use HMI
    INX_SETG,   //set MCU num
    INX_GPIO,   //set GPIO
    
    INX_RDIP,   //read IP address
    INX_RDMA,   //read MAC address
    INX_RDAL,   //read ALS value
    INX_RDST,   //read MCU status
    INX_RDBT,   //read BT Mesh point num
    INX_DEBG,   //read input control
    INX_DEMO,   //demo mode
    INX_USSV,   //save user data
    INX_USRL,   //reset user data
    INX_EEPR,   //save factory data
    INX_ALMX,   //set ALS max
    INX_ALMN,   //set ALS min
    INX_TRGT,   //set ALS target value
    INX_SETP,   //switch ALS control page
    INX_INVL,   //Level inverse
    INX_MODL,   //
    INX_SERL,   //
    INX_MOVR,   //
    INX_MOVL,   //
    INX_MVIN,   //
    INX_MVOU,   //
    INX_RAWC,   //
    INX_SHOW,   //
};

enum {
	FEEDBACKOK=0,
	FEEDBACKNG,
	FEEDBACKENABLEHMI,
	FEEDBACKRDAL,
    FEEDBACKHMIOK,
    FEEDBACKHMING,
    FEEDBACKDEMOGROUPINITOK,
    FEEDBACKMANUALNEWLEVEL,
    FEEDBACKMODL,
    FEEDBACKSERL,
};


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
#if 0
    typedef struct _example_struct_t {
        /* Describe structure member. */
        int some_number;

        /* Describe structure member. */
        bool some_flag;

    } example_struct_t;
#endif

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
        int ExampleFunctionName ( int param1, int param2 ) 

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
   // int ExampleFunction(int param1, int param2);
void LCW_parsingCommand_SERCOM0(uint8_t *RxBuffer, size_t RxBufSize);    
void CheckLCW_Command(char *chkcmdString,size_t cmd_size);
unsigned char ExecuteCommand(char *cmddataString,unsigned char n);
uint16_t Command_HexToDec(int num, char *buffer);
uint16_t lcw_pow(uint16_t x,uint16_t n);
void FEEDBACK_UART(unsigned char n);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
