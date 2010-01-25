/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL$
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Auto Created for sprintf.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EeePApp.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __EEPAPP_H__
#define __EEPAPP_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <EApiApp.h>
  typedef uint32_t EApiStatusCode_t;

#include <BinFuncs.h>
#include <ArgParse.h>
#include <CfgParse.h>
#include <EeeP.h>
#include <EeePDB.h>
#include <StrFuncs.h>
#include <EeePCfg.h>
#include <EeePArg.h>

#define DO(x) \
  EApiStatusCode=x;\
  if(!EAPI_STATUS_TEST_OK(EApiStatusCode)){ \
    return EApiStatusCode;\
  }

/*
 * CPU Independent Multi Byte 
 * Big Endian Memory Access
 */
void
EeeP_Set16BitValue_BE(
    uint8_t *pBuffer,
    uint16_t Value
     );
uint16_t
EeeP_Get16BitValue_BE(
    const uint8_t *pBuffer
     );
void
EeeP_Set32BitValue_BE(
    uint8_t *pBuffer,
    uint32_t Value
     );
uint32_t
EeeP_Get32BitValue_BE(
    const uint8_t *pBuffer
     );
/*
 * CPU Independent Multi Byte 
 * Little Endian Memory Access
 */
void
EeeP_Set16BitValue_LE(
    uint8_t *pBuffer,
    uint16_t Value
     );
uint16_t
EeeP_Get16BitValue_LE(
    const uint8_t *pBuffer
     );
void
EeeP_Set32BitValue_LE(
    uint8_t *pBuffer,
    uint32_t Value
     );
uint32_t
EeeP_Get32BitValue_LE(
    const uint8_t *pBuffer
     );



#ifdef __cplusplus
}
#endif
#endif /* __EEPAPP_H__ */
