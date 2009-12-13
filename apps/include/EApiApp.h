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
 *I Description: Auto Created for EApiApp.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiApp.h
 *I  File Location        : apps\include
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
/* Windows NT Common Header */
#ifndef _EAPIAPP_H_    
#define _EAPIAPP_H_

#ifdef __cplusplus
#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS
#define __STDC_FORMAT_MACROS
#endif

#include <stdlib.h>
#include <stdio.h>
#include <EApiOs.h>	/* Os Specific Include File */
#include <EApi.h>
#include <EApiCommon.h>
#include <EApiAHStr.h>
#include <EApiAHI2C.h>
#include <EApiAHStorage.h>
#include <AppVer.h>


#ifndef EAPI_EMUL_DELAY_NS
#   define EAPI_EMUL_DELAY_NS(x)
#endif

#ifndef EAPI_MSG_OUT
#  ifdef UNICODE
#    define EAPI_MSG_OUT     wprintf
#  else
#    define EAPI_MSG_OUT     printf
#  endif
#endif

#ifndef EAPI_ERR_OUT
#  ifdef UNICODE
#    define EAPI_ERR_OUT     wprintf
#  else
#    define EAPI_ERR_OUT     printf
#  endif
#endif

#define KUXE_VOID_RETURN

#if (STRICT_VALIDATION>0)
#define EAPI_FORMATED_MES(type, func, err, desc) \
    EAPI_ERR_OUT(TEXT(#type) TEXT("%04u %-20s : %-20s : %s\n"), __LINE__, TEXT(#func), TEXT(#err), desc );
#else
#define EAPI_FORMATED_MES(type, func, err, desc)
#endif

#define EAPI_APP_RETURN_SUCCESS(func, desc)  \
  EAPI_FORMATED_MES(O, func, EAPI_RETURN_SUCCESS, desc );\
  return EAPI_RETURN_SUCCESS;

#define EAPI_APP_RETURN_ERROR(func, err, desc)  \
  EAPI_FORMATED_MES(E, func, err, desc );\
  return err;

#define EAPI_APP_RETURN_ERROR_IF(func, exp, err, desc)  \
  if(exp)\
  {\
    EAPI_APP_RETURN_ERROR(func, err, desc );\
  }


#if (STRICT_VALIDATION>0)
#  define EAPI_APP_ASSERT_PARAMATER_CHECK(func, ret, exp, desc)  \
  EAPI_APP_RETURN_ERROR_IF(func, exp, ret, desc)
#else
#  define EAPI_APP_ASSERT_PARAMATER_CHECK(func, ret, exp, desc)
#endif

#define EAPI_APP_ASSERT_PARAMATER_ZERO(func, ret, val)  \
  EAPI_APP_ASSERT_PARAMATER_CHECK(func, ret, (val==0), TEXT(#val) TEXT(" is ZERO"))

#define EAPI_APP_ASSERT_PARAMATER_NULL(func, ret, val)  \
  EAPI_APP_ASSERT_PARAMATER_CHECK(func, ret, (val==NULL), TEXT(#val) TEXT(" is NULL"))


#define EAPI_APP_PREVENT_BUF_OVERFLOW(func, x, y)  \
  if(x>y)\
  {\
    EAPI_FORMATED_MES(E, func,  EAPI_STATUS_MORE_DATA, TEXT(" pBuffer Overflow Prevented") TEXT(#x) TEXT(">") TEXT(#y));\
    x=y;\
  }

#endif /* _EAPIAPP_H_ */

