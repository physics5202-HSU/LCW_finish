/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    uart_app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "UART_APP_Initialize" and "UART_APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "UART_APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _UART_APP_H
#define _UART_APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"
#include "BH1750FVI.h"
#include "lcw.h"
#include "FreeRTOS.h"
#include "queue.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    UART_APP_STATE_INIT=0,
    UART_APP_STATE_SERVICE_TASKS,
    /* TODO: Define states used by the application state machine. */

} UART_APP_STATES;

typedef enum
{
    ADC0_TRANSFER_STATUS_ON,
    ADC0_TRANSFER_STATUS_LV_0,
    ADC0_TRANSFER_STATUS_LV_1,
    ADC0_TRANSFER_STATUS_LV_2,
    ADC0_TRANSFER_STATUS_LV_3,
    ADC0_TRANSFER_STATUS_LV_4,
    ADC0_TRANSFER_STATUS_LV_5,
    ADC0_TRANSFER_STATUS_LV_6,
    ADC0_TRANSFER_STATUS_OFF
} ADC0_STATUS;

enum 
{
    INX_MAC = 0,
    INX_SNW,
    INX_SNR,
    INX_MOD,
    INX_DCP,
    INX_LIP,
    INX_GAT,
    INX_MSK,
    INX_DNS,
    INX_HST,
    INX_HTS,
    INX_RMT,
    INX_SDP,
    INX_UDP,
    INX_PWD,
    INX_INP,
    INX_VOL,
    INX_MUT,
    INX_CHA,
    INX_SEN,
    INX_LTA,
    INX_LTB,
    INX_HOE,
    INX_HTP,
    INX_LTP,
};
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    UART_APP_STATES state;

    /* TODO: Define any additional data used by the application. */

} UART_APP_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void UART_APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    UART_APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    UART_APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void UART_APP_Initialize ( void );


/*******************************************************************************
  Function:
    void UART_APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    UART_APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void UART_APP_Tasks( void );



#endif /* _UART_APP_H */
void INX_UART2_Handler(void);
void INX_UART4_Handler(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

