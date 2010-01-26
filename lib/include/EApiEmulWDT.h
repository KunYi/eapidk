/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL$
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: All rights reserved. This program and the accompanying 
 *I              materials are licensed and made available under the 
 *I              terms and conditions of the BSD License which 
 *I              accompanies this distribution. The full text of the 
 *I              license may be found at 
 *I              http://opensource.org/licenses/bsd-license.php
 *I              
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
 *I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: Auto Created for EApiEmulWDT.h
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiEmulWDT.h
 *I  File Location        : lib\include
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
/* EAPI(Embedded Application Interface) */

#ifndef _EAPIEMULWDT_H_        
#define _EAPIEMULWDT_H_

#ifdef __cplusplus
extern "C" {
#endif

uint32_t 
EAPI_CALLTYPE
EApiWDogGetCapEmul(
    __OUTOPT uint32_t *pMaxDelay       ,/* Maximum Supported 
                                         * Delay in milliseconds
                                         */
    __OUTOPT uint32_t *pMaxEventTimeout,/* Maximum Supported 
                                         * Event Timeout in 
                                         * milliseconds
                                         * 0 == Unsupported
                                         */
    __OUTOPT uint32_t *pMaxResetTimeout /* Maximum Supported 
                                         * Reset Timeout in 
                                         * milliseconds
                                         */
    );
	
uint32_t 
EApiWDogStartEmul(
    __IN  uint32_t Delay       , /* Delay in milliseconds */
    __IN  uint32_t EventTimeout, /* Event Timeout in 
                                  * milliseconds 
                                  */
    __IN  uint32_t ResetTimeout  /* Reset Timeout in 
                                  * milliseconds 
                                  */
    );
uint32_t
EApiWDogTriggerEmul(void);
uint32_t 
EApiWDogStopEmul(void);


#ifdef __cplusplus
}
#endif

#endif /* _EAPIEMULWDT_H_ */



