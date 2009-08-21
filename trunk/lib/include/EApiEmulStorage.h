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
 *I Description: Auto Created for EApiEmulStorage.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiEmulStorage.h
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

#ifndef _EAPIEMULSTORAGE_H_        
#define _EAPIEMULSTORAGE_H_

#ifdef __cplusplus
extern "C" {
#endif

uint32_t 
EApiStorageAreaWriteEmul(
    __IN uint32_t Id      , 
    __IN uint32_t Offset  , 
    __IN    void *pBuffer , 
    __IN uint32_t ByteCnt
    );
uint32_t 
EApiStorageAreaReadEmul(
    __IN uint32_t Id      , 
    __IN uint32_t Offset  , 
    __OUT   void *pBuffer , 
    __IN uint32_t ByteCnt
    );
uint32_t 
EApiStorageCapEmul (
    __IN     uint32_t  Id           , 
    __OUTOPT uint32_t *pStorageSize , 
    __OUTOPT uint32_t *pBlockLength
    );


#ifdef __cplusplus
}
#endif

#endif /* _EAPIEMULSTORAGE_H_ */



