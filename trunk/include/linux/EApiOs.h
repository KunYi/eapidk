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
 *I Description: Auto Created for EApiOs.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiOs.h
 *I  File Location        : include\linux
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
/* Windows NT Common Header */
#ifndef _EAPIOS_H_        
#define _EAPIOS_H_

#ifndef __IN
#  define __IN
#endif
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <wchar.h>
#include <ctype.h>


#if defined _WIN32 || defined __CYGWIN__
  #ifdef EAPI_BUILDING_LIB
    #ifdef __GNUC__
      #define EAPI_CALLTYPE __attribute__((dllexport))
    #else
      #define EAPI_CALLTYPE __declspec(dllexport) /* Note: actually gcc seems to also supports this syntax. */
    #endif
  #else
    #ifdef __GNUC__
      #define EAPI_CALLTYPE __attribute__((dllimport))
    #else
      #define EAPI_CALLTYPE __declspec(dllimport) /* Note: actually gcc seems to also supports this syntax. */
    #endif
  #endif
#else
  #if __GNUC__ >= 4
    #define EAPI_CALLTYPE __attribute__ ((visibility("default")))
  #else
    #define EAPI_CALLTYPE
  #endif
  #define __cdecl
#endif

/* int usleep( long   usec); */
#define EAPI_EMUL_DELAY_NS(x) usleep(x/1000)

#ifndef EApiSleep
#  define EApiSleep(x) sleep(x)
#endif

#ifdef UNICODE
#  define TEXT(x) Lx
#  define EAPI_strlen         wcslen
#  define EAPI_strnlen        wcsnlen
#  define EAPI_strncpy        wcsncpy
#  define EAPI_vsnprintf      vsnwprintf
#  define EAPI_fprintf        fwprintf
#  define EAPI_fopen          _wfopen
#else
#  define TEXT(x) x
#  define EAPI_strlen         strlen
#  define EAPI_strnlen        strnlen
#  define EAPI_strncpy        strncpy
#  define EAPI_vsnprintf      vsnprintf
#  define EAPI_fprintf        fprintf
#  define EAPI_fopen          fopen
#endif

#endif /* _EAPIOS_H_ */


