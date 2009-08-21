/*
 *<KHeader>
 *+=========================================================================
 *I               EApiDK Embedded Application Development Kit
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
 *I Description: Auto Created for EApiEmulBoardInfo.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiEmulBoardInfo.h
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

#ifndef _EAPIEMULBOARDINFO_H_        
#define _EAPIEMULBOARDINFO_H_

#ifdef __cplusplus
extern "C" {
#endif

uint32_t 
EApiBoardGetValueEmul( 
      __IN  uint32_t Id     , 
      __OUT uint32_t *pValue
      );
uint32_t 
EApiBoardGetStringAEmul( 
    __IN    uint32_t  Id      , 
    __OUT   char     *pBuffer , 
    __INOUT uint32_t *pBufLen
    );


#ifdef __cplusplus
}
#endif

#endif /* _EAPIEMULBOARDINFO_H_ */



