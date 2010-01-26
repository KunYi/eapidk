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
 *I  File Name            : EeePDB.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __EEPDB_H__
#define __EEPDB_H__

#ifdef __cplusplus
extern "C" {
#endif


typedef void * EeePHandel_t;

#define EEEP_INIT_INCLUDE_CRC EAPI_UINT32_C(1<<0)

#define EEEP_DIVIDE_RU(Dividend, Divisor)  (((Dividend)+Divisor -1)/Divisor)
#define EEEP_DIVIDE_RD(Dividend, Divisor)  ((Dividend)/Divisor)
#define EEEP_ALIGN_VALUE(Value, Alignment) (EEEP_DIVIDE_RU(Value, Alignment)*Alignment)
#define EEEP_ALIGN_VALUE_B(Value, Alignment) ((Value+ Alignment-1)&(~(Alignment-1)))

#define EEEP_SIZE_UNITS        2
#define EEEP_ALIGN_LENGTH(x)  EEEP_ALIGN_VALUE_B(x, EEEP_SIZE_UNITS)
#define EEEP_MIN_BLOCK_LENGTH EEEP_ALIGN_LENGTH(sizeof(DBlockIdHdr_t))
#define EEEP_CRC_BLOCK_LENGTH EEEP_ALIGN_LENGTH(sizeof(CRC16ChkBlock_t))


size_t 
EeePAdjLength(
    size_t Length
    );

size_t 
EeePAlignLength(
    size_t Length
    );

EApiStatusCode_t
SetBlockLength(
    EeePHandel_t BHandel,
    size_t       stBlockLength
    );

size_t 
GetBlockLength(
    const void * pcvBHandel
    );

DBlockIdHdr_t * 
GetNextBlock(
    DBlockIdHdr_t *pCurBlock
    );

EApiStatusCode_t
SetDynBlockHeader(
    void          *pCurBlock,
    uint8_t        u8BlockId,
    size_t         stBlockLength
    );

#define EEEP_RBL_REDUCE_TOP_DOWN  (1<<0)
EApiStatusCode_t
ReduceBlockLength(
    __IN     DBlockIdHdr_t**pvCurBlock,
    __IN     size_t         stReduceBy, 
    __OUTOPT DBlockIdHdr_t**pvNewBlock,
    __IN     unsigned int   uiFlags
    );

EApiStatusCode_t
EeePGetFirstDB(
    EeePHandel_t     BHandel,
    DBlockIdHdr_t ** pFirstDB
    );

EApiStatusCode_t
EeePCreateNewBuffer(
    EeePHandel_t *pBHandel,
    size_t   stBufferSize ,
    size_t   stHeaderSize ,
    uint32_t u32Flags
    );

EApiStatusCode_t
EeePFreeBuffer(
    EeePHandel_t *pBHandel
    );

typedef struct EeePBufferMap_s{
  EeePCmn_t       *pCmnHdr          ;
  DBlockIdHdr_t   *pEmptyBlock      ;
  CRC16ChkBlock_t *pEeePCRCBlock    ;
}EeePBufferMap_t;


EApiStatusCode_t
EeePMapBuffer(
    EeePHandel_t     BHandel,
    EeePBufferMap_t *pBufMap
    );

#define EEEP_ADDBLK_IN_CRC (1<<0)
EApiStatusCode_t
EeePAddBlock(
    EeePHandel_t   BHandel ,
    const void    *pcvBlock , 
          void   **pvIBlock , 
    const unsigned cuiFlags    
    );

EApiStatusCode_t
EeePSetCRC(
    EeePHandel_t BHandel
    );

EApiStatusCode_t
EeePCheckCRC(
    EeePHandel_t BHandel
    );

EApiStatusCode_t
EeePFindBlock(
    __IN  EeePHandel_t   BHandel,
    __IN  uint8_t        BlockId,
    __IN  signed int     Instance,
    __OUT void         **pvFBlock
    );

EApiStatusCode_t
EeePWriteBufferToFile(
    __IN  EeePHandel_t   BHandel,
    __IN  char          *pszFilename
    );

EApiStatusCode_t
EeePWriteBufferToEEP(
    __IN  EeePHandel_t   BHandel,
    __IN  unsigned       u16DeviceBus ,
    __IN  uint16_t       u16DeviceAddr 
    );

EApiStatusCode_t
EeePReadBufferFromFile(
    __OUT EeePHandel_t  *pBHandel,
    __IN  char          *pszFilename
    );

#ifdef __cplusplus
}
#endif
#endif /* __EEPDB_H__ */
