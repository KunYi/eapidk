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
 *I Description: Auto Created for EApiInitLib.h
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiInitLib.h
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

#ifndef _EAPIINITLIB_H_
#define _EAPIINITLIB_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EAPI_DBG_USE_OUTPUT_FILE
#  define EAPI_DBG_USE_OUTPUT_FILE 1
#endif

void
__cdecl
DebugMsg(
    __IN const char *const fmt,
    ...
    );

uint32_t
EApiInitLib(void);

uint32_t
EApiUninitLib(void);


#ifndef EAPI_LIB_MSG_OUT
#  if 0
#    define EAPI_LIB_MSG_OUT(...) DebugMsg("E " ## __VA_ARGS__)
#  else
#    define EAPI_LIB_MSG_OUT(x)   DebugMsg x
#  endif
#endif

#ifndef EAPI_LIB_ERR_OUT
#  if 0
#    define EAPI_LIB_ERR_OUT(...) DebugMsg("O " ## __VA_ARGS__)
#  else
#    define EAPI_LIB_ERR_OUT(x)   DebugMsg x
#  endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* _EAPIINITLIB_H_ */



