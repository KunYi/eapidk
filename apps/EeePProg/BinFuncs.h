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
 *I     License: All rights reserved. This program and the accompanying 
 *I              materials are licensed and made available under the 
 *I              terms and conditions of the BSD License which 
 *I              accompanies this distribution. The full text of the 
 *I              license may be found at 
 *I              http://opensource.org/licenses/bsd-license.php
 *I              
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN '
 *I              AS IS' BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: /KHeader>
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : BinFuncs.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */

#ifndef __BINFUNCS_H__
#define __BINFUNCS_H__

#ifdef __cplusplus
extern "C" {
#endif

uint32_t 
u32ChecksumBlock(
    const void *pcvBuffer, 
    size_t      stLength
  );
uint16_t 
u16ChecksumBlock(
    const void *pcvBuffer, 
    size_t      stLength
  );
uint8_t  
u8ChecksumBlock (
    const void *pcvBuffer, 
    size_t      stLength
  );

uint16_t
u16CRC_CCITT (
    __IN const void *pcvBuffer, /* Pointer to Buffer */
    __IN size_t      stCount    /* Num bytes to CRC */
  );


#define HEXTBL_8BIT_ELEMENT   0x0000
#define HEXTBL_16BIT_ELEMENT  0x1000
#define HEXTBL_32BIT_ELEMENT  0x2000
#define HEXTBL_64BIT_ELEMENT  0x3000
#define HEXTBL_128BIT_ELEMENT 0x4000
#define HEXTBL_WIDTH_MASK     0x7000

#define HEXTBL_COUNT_MASK     0x003F

#define HEXTBL_BIG_ENDIAN     0x0100

#define HEXTBL_7Bit_ASCII     0x0200
#define HEXTBL_8Bit_ASCII     0x0400
#define HEXTBL_ASCII_MASK     0x0600

#define HEXTBL_OFFSEt_BAR     0x0800
#define HEXTBL_OFFSET_COUNT   0x0080
#define HEXTBL_OFFSET_TITLE   0x0040

#define HEXTBL_NORMAL_ATTRIB  (HEXTBL_OFFSEt_BAR|HEXTBL_BIG_ENDIAN|HEXTBL_7Bit_ASCII|HEXTBL_OFFSET_COUNT|HEXTBL_OFFSET_TITLE)
#define HEXTBL_NORM8_ATTRIB   (HEXTBL_NORMAL_ATTRIB|HEXTBL_8BIT_ELEMENT|16)
#define HEXTBL_NORM16_ATTRIB  (HEXTBL_NORMAL_ATTRIB|HEXTBL_16BIT_ELEMENT|8)
#define HEXTBL_NORM32_ATTRIB  (HEXTBL_NORMAL_ATTRIB|HEXTBL_32BIT_ELEMENT|4)
#define HEXTBL_NORM64_ATTRIB  (HEXTBL_NORMAL_ATTRIB|HEXTBL_64BIT_ELEMENT|2)
TCHAR
cBin2Ascii_c(
    __IN  unsigned  uiValue
  );
int
siBin2Ascii_s(
    __OUT TCHAR           *szString   ,
    __IN  size_t          stBufLength ,
    __IN  const uint8_t  *pcu8Value ,
    __IN  size_t          stVarSize   ,
    __IN  const unsigned  cuiFlags
  );


void 
PrintHexAsciiTableEx(
	__IN    const void *   pcvBuffer	,
	__IN    const size_t   stBufSize	,
	__IN    const void *   pcvBase		,
	__IN    const TCHAR *   pcszDescription,
  __IN    const unsigned cuiFlags
	);

void 
PrintHexAsciiTable(
	__IN    const void *const pcvBuffer	    ,
	__IN    const size_t      cu16BufSize		,
	__IN    const void *const pcvBase		    ,
	__IN    const TCHAR *const pcszDescription
	);

EApiStatusCode_t
ReadBinaryFile(
    __IN  const char *pcszFilename, 
    __OUT void      **pvBuffer, 
    __OUT size_t     *pstReadBCnt
  );

EApiStatusCode_t 
WriteBinaryFile(
    __IN const char *pcszFilename, 
    __IN const void *pcvBuffer   , 
    __IN size_t      stWriteBCnt
  );


#ifdef __cplusplus
}
#endif
#endif /* __BINFUNCS_H__ */