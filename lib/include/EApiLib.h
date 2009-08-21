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
 *I Description: Auto Created for EApiLib.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiLib.h
 *I  File Location        : lib\include
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef _EAPILIB_H_        
#define _EAPILIB_H_

#ifdef __cplusplus
#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS
#define __STDC_FORMAT_MACROS
#endif
#define EAPI_BUILDING_LIB

#include <stdlib.h>
#include <EApiOs.h>
#include <EApi.h>
#include <EApiCommon.h>
#include <LibVer.h>

#define EAPI_PLATFORM_COM0 1
#define EAPI_PLATFORM_ETX  2
#define EAPI_PLATFORM_Q7   3
#define EAPI_PLATFORM_TCA  4
#if !defined EAPI_PLATFORM
#  define EAPI_PLATFORM EAPI_PLATFORM_COM0
#endif 

#include <EApiEmulI2C.h>
#include <EApiEmulGPIO.h>
#include <EApiInitLib.h>
#include <EApiEmulStorage.h>
#include <EApiEmulWDT.h>
#include <EApiEmulBacklight.h>
#include <EApiEmulBoardInfo.h>


#ifndef EAPI_EMUL_DELAY_NS
#   define EAPI_EMUL_DELAY_NS(x)
#endif

#ifndef EAPI_LIB_MSG_OUT
#  include <stdio.h>
#  if 0
#    define EAPI_LIB_MSG_OUT(...) printf("E " ## __VA_ARGS__)
#  else
#    define EAPI_LIB_MSG_OUT(x)  printf x 
#  endif
#endif

#ifndef EAPI_LIB_ERR_OUT
#  include <stdio.h>
#  if 0
#    define EAPI_LIB_ERR_OUT(...) printf("O " ## __VA_ARGS__)
#  else
#    define EAPI_LIB_ERR_OUT(x)   printf x 
#  endif
#endif

#if (STRICT_VALIDATION>1)
#define EAPI_FORMATED_MES(type, func, err, desc) \
    EAPI_LIB_ERR_OUT((#type "%04u %-30s : %-30s : %s\n", __LINE__, #func, #err, desc ))
#else
#define EAPI_FORMATED_MES(type, func, err, desc)
#endif

#define EAPI_LIB_RETURN_SUCCESS(func, desc)  \
  EAPI_FORMATED_MES(E, func, EAPI_STATUS_SUCCESS, desc );\
  return EAPI_STATUS_SUCCESS

#define EAPI_LIB_RETURN_ERROR(func, err, desc)  \
  EAPI_FORMATED_MES(O, func, err, desc );\
  return err

#define EAPI_LIB_RETURN_ERROR_IF(func, exp, err, desc)  \
  if(exp)\
  {\
    /* assert(!(exp)); */ \
    EAPI_LIB_RETURN_ERROR(func, err, desc );\
  }

#if (STRICT_VALIDATION>1)
#  define EAPI_LIB_ASSERT_PARAMATER_CHECK(func, exp, desc)  \
  EAPI_LIB_RETURN_ERROR_IF(func, exp, EAPI_STATUS_INVALID_PARAMETER, desc)
#else
#  define EAPI_LIB_ASSERT_PARAMATER_CHECK(func, exp, desc)
#endif


#define EAPI_LIB_ASSERT_PARAMATER_ZERO(func, val)  \
  EAPI_LIB_ASSERT_PARAMATER_CHECK(func, (val==0), #val" is ZERO")

#define EAPI_LIB_ASSERT_PARAMATER_NULL(func, val)  \
  EAPI_LIB_ASSERT_PARAMATER_CHECK(func, (val==NULL), #val" is NULL")


#define EAPI_LIB_PREVENT_BUF_OVERFLOW(func, x, y)  \
  if(x>y)\
  {\
    EAPI_FORMATED_MES(E, func, EAPI_STATUS_MORE_DATA, " pBuffer Overflow Prevented" #x ">" #y );\
    x=y;\
    ErrorCode=EAPI_STATUS_MORE_DATA;\
  }

#endif /* _EAPILIB_H_ */

