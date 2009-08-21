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
 *I Description: Auto Created for EApiAHStr.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiAHStr.h
 *I  File Location        : apps\include
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
/* EAPI(Embedded Application Interface) */

#ifndef _EAPIAPPHLPR_H_        
#define _EAPIAPPHLPR_H_

#include <string.h>
#ifdef UNICODE
#  ifdef __cplusplus
   extern "C" {
#  endif
#    include <wchar.h>
#  ifdef __cplusplus
}
#  endif
#endif

#ifdef __cplusplus
extern "C" {
#endif


#ifndef TEXT
#  ifdef UNICODE
#    define TEXT(x) L##x
#  else
#    define TEXT(x) x
#  endif
#endif
#ifndef TCHAR
#  ifdef UNICODE
#    define TCHAR wchar_t
#  else
#    define TCHAR char
#  endif
#endif

size_t 
EApiStrLen  ( 
    __IN const TCHAR *pBuffer    ,
    __IN size_t       BufferLen
    );
TCHAR * 
EApiStrCpy(
    __OUT TCHAR *const      StringDest   ,
    __IN size_t             StrBufLen    , 
    __IN const TCHAR *const StringSource
    );
size_t 
__cdecl 
EApiSprintf ( 
    __IN TCHAR *const       pBuffer   ,
    __IN const size_t       BufferLen ,
    __IN const TCHAR *const fmt       ,
    ...
    );


/****************************************************************************/
/* Common pBuffer usage Model */

typedef 
size_t 
CreateStringFunction(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    );

CreateStringFunction EApiAHCreateVersionString  ;
CreateStringFunction EApiAHCreateTimeString     ;
CreateStringFunction EApiAHCreateDecimalString  ;
CreateStringFunction EApiAHCreateHexString      ;
CreateStringFunction EApiAHCreatePNPIDString    ;
CreateStringFunction EApiAHCreateTempString     ;
CreateStringFunction EApiAHCreateVoltageString  ;
CreateStringFunction EApiAHCreateRotationsString;
CreateStringFunction EApiAHCreateSVersionString ;


size_t 
EApiAHGetString(
    __IN  uint32_t        StringID  , /* EApi String ID */
    __OUT TCHAR *         pString   , /* Pointer To String pBuffer */
    __IN  size_t          StrBufLen   /* String pBuffer Length */
    );

size_t 
EApiAHCreateErrorString(
    __IN  uint32_t        StatusCode  ,
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const size_t    StrBufLen   /* String pBuffer Length */
    );

/* Dynamic pBuffer Allocation */


void 
EApiAHGetStringAlloc(
    __IN  uint32_t        StringID, /* EApi String ID */
    __OUT TCHAR * *const  pString   /* Pointer to where string pointer should be stored */
    );

void 
EApiAHCreateErrorStringAlloc(
    __IN  uint32_t        StatusCode  ,
    __OUT TCHAR * *const   pString  /* Pointer to where string pointer should be stored */
    );


#ifdef UNICODE
uint32_t 
EApiAHBoardGetStringW(
    __IN      uint32_t  Id      , /* Name Id */
    __OUT     wchar_t  *pBuffer , /* Destination pBuffer */
    __INOUT   uint32_t *pBufLen   /* pBuffer Length */
    );
#endif

#ifdef UNICODE
#  define EApiBoardGetString EApiAHBoardGetStringW
#else
#  define EApiBoardGetString EApiBoardGetStringA
#endif

#ifdef __cplusplus
}
#endif




#endif /* _EAPIAPPHLPR_H_ */


