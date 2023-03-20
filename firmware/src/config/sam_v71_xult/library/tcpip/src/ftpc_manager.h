/*******************************************************************************
  FTPC Manager Header file

  Company:
    Microchip Technology Inc.
    
  File Name:
    ftpc_manager.h

  Summary:
    FTPC manager interface file

  Description:
    This source file contains the stack internal FTPC manager API
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*****************************************************************************
 Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.

Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software 
and any derivatives exclusively with Microchip products. It is your 
responsibility to comply with third party license terms applicable to your 
use of third party software (including open source software) that may 
accompany Microchip software.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR 
PURPOSE.

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE 
FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN 
ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY, 
THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*****************************************************************************/
// DOM-IGNORE-END

#ifndef _FTPC_MANAGER_H_
#define _FTPC_MANAGER_H_


// stack private module API
//FTPC module initialization
bool        TCPIP_FTPC_Initialize(const TCPIP_STACK_MODULE_CTRL* const stackCtrl, const TCPIP_FTPC_MODULE_CONFIG_TYPE* pftpcConfig);
//FTPC de-initailize function
void        TCPIP_FTPC_Deinitialize(const TCPIP_STACK_MODULE_CTRL* const stackCtrl);

#endif  // _FTPC_MANAGER_H_

