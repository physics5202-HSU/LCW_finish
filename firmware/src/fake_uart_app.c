/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    fake_uart_app.c

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

#include "fake_uart_app.h"

#include <errno.h>
#include <sys/errno.h>

#include "com_lib.h"

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
    This structure should be initialized by the FAKE_UART_APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

FAKE_UART_APP_DATA fake_uart_appData;
extern xQueueHandle queue_UART_IP;
extern xQueueHandle queue_IP_UART;

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
    void FAKE_UART_APP_Initialize ( void )

  Remarks:
    See prototype in fake_uart_app.h.
 */

void FAKE_UART_APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    fake_uart_appData.state = FAKE_UART_APP_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void FAKE_UART_APP_Tasks ( void )

  Remarks:
    See prototype in fake_uart_app.h.
 */

void FAKE_UART_APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( fake_uart_appData.state )
    {
        /* Application's initial state. */
        case FAKE_UART_APP_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                fake_uart_appData.state = FAKE_UART_APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case FAKE_UART_APP_STATE_SERVICE_TASKS:
        {
            Message msg;
            if (xQueueReceive(queue_IP_UART, &msg, (TickType_t) 0) == pdTRUE) {
                if (xQueueSend(queue_UART_IP, &msg, ( TickType_t ) 10 ) == pdPASS) {
                    SYS_CONSOLE_PRINT(" UART -> IP: Success...\r\n");
                } else {
                    // message didn't pass to uart task successfully
                    SYS_CONSOLE_PRINT(" UART -> IP: Failed...\r\n");
                }
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
