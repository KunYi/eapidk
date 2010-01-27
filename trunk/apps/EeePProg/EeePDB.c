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
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
 *I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: Auto Created for EApiValidateAPI.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EeePDB.c
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EeePApp.h>

typedef struct StringLookup_s{
  char *szString;
  const unsigned int cuiValue;
}StringLookup_t;

StringLookup_t BlockIdLookup[]={
  { "EEEP_BLOCK_ID_UNUSED"          , EEEP_BLOCK_ID_UNUSED          },
  { "EEEP_BLOCK_ID_VENDOR_SPECIFIC" , EEEP_BLOCK_ID_VENDOR_SPECIFIC },
  { "EEEP_BLOCK_ID_EXP_EEPROM"      , EEEP_BLOCK_ID_EXP_EEPROM      },
  { "EEEP_BLOCK_ID_SMBIOS"          , EEEP_BLOCK_ID_SMBIOS          },
  { "EEEP_BLOCK_ID_LFP"             , EEEP_BLOCK_ID_LFP             },
  { "EEEP_BLOCK_ID_CRC_CHK"         , EEEP_BLOCK_ID_CRC_CHK         },
  { "EEEP_BLOCK_ID_IGNORE"          , EEEP_BLOCK_ID_IGNORE          },
  { "EEEP_OFFSET_VALUE_EOL"         , EEEP_OFFSET_VALUE_EOL         },
  { "EEEP_OFFSET_VALUE_EOL_ALT"     , EEEP_OFFSET_VALUE_EOL_ALT     },

  { "COM0R20_BLOCK_ID_EXP_CARD_DESC", COM0R20_BLOCK_ID_EXP_CARD_DESC},
  { "COM0R20_BLOCK_ID_SERIO_DESC"   , COM0R20_BLOCK_ID_SERIO_DESC   },
  { NULL                            , 0                             },
};


EApiStatusCode_t 
GetString(
    __IN  StringLookup_t *pStrTbl,
    __OUT TCHAR *        pszString,
    __IN  size_t         stArrayLen,
    __IN  unsigned int   uiValue
    )
{
  for(;pStrTbl->szString!=NULL;pStrTbl++){
    if(pStrTbl->cuiValue==uiValue){
      EApiSprintf(pszString, stArrayLen, TEXT("%hs"), pStrTbl->szString);
      return EAPI_STATUS_SUCCESS;
    }
  }
  EApiSprintf(pszString, stArrayLen, TEXT("UNKNOWN ID"));
  return EAPI_STATUS_ERROR;
}


size_t 
EeePAdjLength(
    size_t Length
    )
{
  return EEEP_DIVIDE_RU(Length, EEEP_SIZE_UNITS);
}
size_t 
EeePAlignLength(
    size_t Length
    )
{
#if (EEEP_SIZE_UNITS&(EEEP_SIZE_UNITS-1))
  return EEEP_ALIGN_VALUE(Length, EEEP_SIZE_UNITS);
#else
  return EEEP_ALIGN_VALUE_B(Length, EEEP_SIZE_UNITS);
#endif
}

EApiStatusCode_t
SetBlockLength(
    EeePHandel_t BHandel,
    size_t       stBlockLength
    )
{
  EAPI_APP_ASSERT_PARAMATER_NULL(
      SetBlockLength,
      EAPI_STATUS_INVALID_PARAMETER,
      BHandel
    );
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
      SetBlockLength,
      EAPI_STATUS_INVALID_PARAMETER,
      (stBlockLength%EEEP_SIZE_UNITS)
    );
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
      SetBlockLength, 
      EAPI_STATUS_INVALID_PARAMETER, 
      (stBlockLength>(UINT16_MAX*EEEP_SIZE_UNITS))
    );

  EeeP_Set16BitValue_BE(
        ((DBlockIdHdr_t*)BHandel)->DBlockLength, 
        EEEP_LO_UINT16((stBlockLength)/EEEP_SIZE_UNITS)
      );
  return EAPI_STATUS_SUCCESS;
}
size_t 
GetBlockLength(
    const void * pcvBHandel
    )
{
  EAPI_APP_ASSERT_PARAMATER_NULL(
      GetBlockLength,
      0,
      pcvBHandel
    );
  return 
    EeeP_Get16BitValue_BE(((DBlockIdHdr_t*)pcvBHandel)->DBlockLength )*EEEP_SIZE_UNITS;
}
DBlockIdHdr_t * 
GetNextBlock(
    DBlockIdHdr_t *pCurBlock
    )
{
  size_t stBlockLength;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      GetNextBlock,
      NULL,
      pCurBlock
    );
  stBlockLength=GetBlockLength(pCurBlock);
  switch(stBlockLength){
    case EEEP_OFFSET_VALUE_EOL:
    case EEEP_OFFSET_VALUE_EOL_ALT:
      return NULL;
      break;
    default:
      return EAPI_CREATE_PTR(
          pCurBlock         ,
          stBlockLength     ,
          DBlockIdHdr_t *
        );
      break;
      }
}
EApiStatusCode_t
SetDynBlockHeader(
    void          *pCurBlock,
    uint8_t        u8BlockId,
    size_t         stBlockLength
    )
{
  EAPI_APP_ASSERT_PARAMATER_NULL(
      SetDynBlockInfo,
      EAPI_STATUS_INVALID_PARAMETER,
      pCurBlock
    );
  ((DBlockIdHdr_t *)pCurBlock)->DBlockId=u8BlockId;
  return SetBlockLength(pCurBlock, stBlockLength);
}
EApiStatusCode_t
ReduceBlockLength(
    __IN     DBlockIdHdr_t**pvCurBlock,
    __IN     size_t         stReduceBy, 
    __OUTOPT DBlockIdHdr_t**pvNewBlock,
    __IN     unsigned int   uiFlags
    )
{
  EApiStatusCode_t EApiStatusCode;
  DBlockIdHdr_t    *pTmpBlock   ;
  size_t NewLength;
  if(pvNewBlock!=NULL) *pvNewBlock=NULL;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      ReduceBlockLength             ,
      EAPI_STATUS_INVALID_PARAMETER ,
      pvCurBlock
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ReduceBlockLength             ,
      EAPI_STATUS_INVALID_PARAMETER ,
      *pvCurBlock
    );
#if TEST_EEEPDB
  EAPI_printf(TEXT("%08X, %08X, %08X\n"), GetBlockLength(*pvCurBlock), EeePAlignLength(stReduceBy), EEEP_MIN_BLOCK_LENGTH);
#endif
  EAPI_APP_RETURN_ERROR_IF_S(
      ReduceBlockLength                                                             ,
      GetBlockLength(*pvCurBlock)<(EeePAlignLength(stReduceBy)+EEEP_MIN_BLOCK_LENGTH),
      EAPI_STATUS_INVALID_PARAMETER
    );
  NewLength=GetBlockLength(*pvCurBlock)- EeePAlignLength(stReduceBy);
  if(uiFlags&EEEP_RBL_REDUCE_TOP_DOWN){
    pTmpBlock=*pvCurBlock;
  }else{
    pTmpBlock=EAPI_CREATE_PTR(*pvCurBlock, EeePAlignLength(stReduceBy), DBlockIdHdr_t *);
    memmove(pTmpBlock, *pvCurBlock, NewLength);
  }
  EApiStatusCode=SetBlockLength(
        pTmpBlock, 
        NewLength
      );
  if(uiFlags&EEEP_RBL_REDUCE_TOP_DOWN){
    if(pvNewBlock!=NULL)
      *pvNewBlock=GetNextBlock(pTmpBlock);
  }else{
    if(pvNewBlock!=NULL)
      *pvNewBlock=*pvCurBlock;
    *pvCurBlock=pTmpBlock;
  }
  return EApiStatusCode;
}

/*
 * Create and Handle Blocks 
 */
EApiStatusCode_t
EeePCreateNewBuffer(
    EeePHandel_t *pBHandel,
    size_t   stBufferSize ,
    size_t   stHeaderSize ,
    uint32_t u32Flags
    )
{
  EeePCmn_t     *pEeePCmnHdr; 
  DBlockIdHdr_t *pEeePEmptyBlock; 
  EApiStatusCode_t EApiStatusCode;
  DBlockIdHdr_t *pEeePTBlock; 
  
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
      EeePCreateNewBuffer, 
      EAPI_STATUS_INVALID_PARAMETER, 
      (stBufferSize<256)
    );
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
      EeePCreateNewBuffer, 
      EAPI_STATUS_INVALID_PARAMETER, 
      (stHeaderSize<sizeof(*pEeePCmnHdr))
    );

  pEeePCmnHdr=*pBHandel=(EeePHandel_t)malloc(stBufferSize);

  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePCreateNewBuffer,
      EAPI_STATUS_ALLOC_ERROR,
      *pBHandel
    );
  memset(pEeePCmnHdr, 0x00, stBufferSize);
  /*
   * Initialize Header
   */
  pEeePCmnHdr->DontCareByte=0;
  memcpy(
      pEeePCmnHdr->EepId        ,
      EEEP_EEPROM_MARKER        ,
      sizeof(EEEP_EEPROM_MARKER)-1
    );
  pEeePCmnHdr->SpecRev=EEEP_VERSION;
  pEeePCmnHdr->BlkOffset=(uint8_t)EeePAdjLength(stHeaderSize);
  pEeePCmnHdr->DeviceDesc=0;
  /*
   * Initialize Free Block
   */
  DO(EeePGetFirstDB(*pBHandel, &pEeePEmptyBlock));

  DO(SetDynBlockHeader(
        pEeePEmptyBlock, 
        EEEP_BLOCK_ID_UNUSED, 
        stBufferSize - (pEeePCmnHdr->BlkOffset*EEEP_SIZE_UNITS)
      ));
  /*
   * Termination Block
   */
  DO(ReduceBlockLength(
        &pEeePEmptyBlock        ,
        sizeof(*pEeePTBlock)    ,
        &pEeePTBlock            , 
        EEEP_RBL_REDUCE_TOP_DOWN
      ));

  /*
   * Initialise Termination Block Values
   */
  DO(SetDynBlockHeader(
        pEeePTBlock, 
        EEEP_BLOCK_ID_UNUSED, 
        EEEP_OFFSET_VALUE_EOL
      ));
  /*
   * Optional Create CRC Block
   */
  if(u32Flags&EEEP_INIT_INCLUDE_CRC){
    DBlockIdHdr_t   *plclEeePBlock; 
    CRC16ChkBlock_t *pEeePCRCBlock;
    /*
     * Allocate CRC BLOCK
     */
    DO(ReduceBlockLength(
          &pEeePEmptyBlock      ,
          sizeof(*pEeePCRCBlock),
          &plclEeePBlock,
          0
        ));
   pEeePCRCBlock=(CRC16ChkBlock_t*)plclEeePBlock;

    /*
     * Initialise CRC Block Values
     */
    DO(SetDynBlockHeader(
          pEeePCRCBlock         ,
          EEEP_BLOCK_ID_CRC_CHK ,
          sizeof(*pEeePCRCBlock)
        ));
    EeeP_Set16BitValue_BE( pEeePCRCBlock->CrC16, 0);
  }
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
EeePFreeBuffer(
    EeePHandel_t *pBHandel
    )
{

  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePFreeBuffer,
      EAPI_STATUS_INVALID_PARAMETER,
      *pBHandel
    );

  free(*pBHandel);
  *pBHandel=NULL;
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
EeePGetFirstDB(
    EeePHandel_t     BHandel,
    DBlockIdHdr_t ** pFirstDB
    )
{
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePGetFirstDB,
      EAPI_STATUS_INVALID_PARAMETER,
      BHandel
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePGetFirstDB,
      EAPI_STATUS_INVALID_PARAMETER,
      pFirstDB
    );
    
  *pFirstDB=NULL;

  EAPI_APP_RETURN_ERROR_IF(
      EeePGetFirstDB,
      memcmp(
          ((EeePCmn_t*)BHandel)->EepId, 
          EEEP_EEPROM_MARKER, 
          sizeof(EEEP_EEPROM_MARKER)-1
        ),
      EAPI_STATUS_ERROR,
      TEXT("Invalid EeeP Buffer")
    );


  /*
   * Check If Dynamic Blocks Present
   */
  if(!((EeePCmn_t*)BHandel)->BlkOffset) 
    return EAPI_STATUS_SUCCESS;

  *pFirstDB=EAPI_CREATE_PTR(
        BHandel         ,
        (((EeePCmn_t*)BHandel)->BlkOffset*EEEP_SIZE_UNITS),
        void *
      );
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
EeePMapBuffer(
    EeePHandel_t     BHandel,
    EeePBufferMap_t *pBufMap
    )
{
  DBlockIdHdr_t    *pCurBlock       ;
  EApiStatusCode_t EApiStatusCode;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePMapBuffer,
      EAPI_STATUS_INVALID_PARAMETER,
      BHandel
    );

  memset(pBufMap, 0x00, sizeof(*pBufMap));

  pBufMap->pCmnHdr=BHandel;

  EAPI_APP_RETURN_ERROR_IF(
      EeePMapBuffer,
      memcmp(
          pBufMap->pCmnHdr->EepId, 
          EEEP_EEPROM_MARKER, 
          sizeof(EEEP_EEPROM_MARKER)-1
        ),
      EAPI_STATUS_ERROR,
      TEXT("Invalid EeeP Buffer")
    );

  DO(EeePGetFirstDB(BHandel, &pCurBlock));

  for(;pCurBlock!=NULL;pCurBlock=GetNextBlock(pCurBlock))
  {
#if TEST_EEEPDB
    EAPI_MSG_OUT(
        TEXT("LOG: BLOCK ID  : 0x%02")TEXT(PRIX8)TEXT("\n")
        TEXT("LOG:   Length  : 0x%04X\n")
        TEXT("LOG:   Offset  : 0x%08X\n"),
        pCurBlock->DBlockId,
        GetBlockLength(pCurBlock),
        EAPI_GET_PTR_OFFSET(pCurBlock, BHandel)
      );
    PrintHexAsciiTable(pCurBlock, GetBlockLength(pCurBlock), BHandel, NULL);
#endif
    switch(pCurBlock->DBlockId){
      case EEEP_BLOCK_ID_UNUSED:
        if(GetNextBlock(pCurBlock)==NULL) break;
        EAPI_APP_RETURN_ERROR_IF(
            EeePMapBuffer,
            pBufMap->pEmptyBlock!=NULL,
            EAPI_STATUS_ERROR,
            TEXT("More than 1 Empty Block in CRC Not Supported")
          );
        pBufMap->pEmptyBlock=pCurBlock;
        break;
      case EEEP_BLOCK_ID_CRC_CHK:
        EAPI_APP_RETURN_ERROR_IF(
            EeePMapBuffer,
            pBufMap->pEeePCRCBlock!=NULL,
            EAPI_STATUS_ERROR,
            TEXT("More than 1 CRC Block Not Supported")
          );
        pBufMap->pEeePCRCBlock=(CRC16ChkBlock_t *)pCurBlock;
        break;
      case EEEP_BLOCK_ID_IGNORE:
        pCurBlock=NULL;
        break;
      default:
        break;
    }
  }

  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
EeePListBlocks(
    EeePHandel_t BHandel,
    unsigned int uiFlags
  )
{
  TCHAR BlockName[80];
  EeePCmn_t     *pEeePCmnHdr; 
  DBlockIdHdr_t    *pCurBlock       ;
  EApiStatusCode_t EApiStatusCode;
  uiFlags=uiFlags;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePListBlocks,
      EAPI_STATUS_INVALID_PARAMETER,
      BHandel
    );
  pEeePCmnHdr=BHandel;


  EAPI_APP_RETURN_ERROR_IF(
      EeePMapBuffer,
      memcmp(
          pEeePCmnHdr->EepId, 
          EEEP_EEPROM_MARKER, 
          sizeof(EEEP_EEPROM_MARKER)-1
        ),
      EAPI_STATUS_ERROR,
      TEXT("Invalid EeeP Buffer")
    );

  DO(EeePGetFirstDB(BHandel, &pCurBlock));
  EAPI_MSG_OUT(
      TEXT("LOG: Header Size: 0x%02lX\n"),
      (unsigned long)EAPI_GET_PTR_OFFSET(pCurBlock, BHandel)
      );
  PrintHexAsciiTable(
        BHandel, 
        sizeof(*pEeePCmnHdr), 
        BHandel, 
        TEXT("EeeP Common Header")
      );

  if(EAPI_GET_PTR_OFFSET(pCurBlock, BHandel) > sizeof(*pEeePCmnHdr)){
    PrintHexAsciiTable(
        EAPI_CREATE_PTR(BHandel, sizeof(*pEeePCmnHdr), void *), 
        EAPI_GET_PTR_OFFSET(pCurBlock, BHandel) - sizeof(*pEeePCmnHdr), 
        BHandel, 
        TEXT("EeeP Extended Header")
      );
  }

  for(;pCurBlock!=NULL;pCurBlock=GetNextBlock(pCurBlock))
  {
    GetString(BlockIdLookup, BlockName, ARRAY_SIZE(BlockName), pCurBlock->DBlockId);
    EAPI_MSG_OUT(
        TEXT("\n")
#ifdef _UNICODE
        TEXT("LOG: BLOCK ID  : %ls(0x%02")TEXT(PRIX8)TEXT(")\n")
#else
        TEXT("LOG: BLOCK ID  : %s(0x%02")TEXT(PRIX8)TEXT(")\n")
#endif
        TEXT("LOG:   Length  : 0x%04lX\n")
        TEXT("LOG:   Offset  : 0x%08lX\n"),
        BlockName,
        pCurBlock->DBlockId,
        (unsigned long)GetBlockLength(pCurBlock),
        (unsigned long)EAPI_GET_PTR_OFFSET(pCurBlock, BHandel)
      );
    if(GetNextBlock(pCurBlock)!=NULL){
      PrintHexAsciiTable(
            EAPI_CREATE_PTR(pCurBlock, sizeof(*pCurBlock), void *), 
            GetBlockLength(pCurBlock) - sizeof(*pCurBlock), 
            BHandel, 
            NULL
        );
    }
  }

  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
EeePSetCRC(
    EeePHandel_t BHandel
    )
{
  EeePBufferMap_t BufferMap;
  EApiStatusCode_t EApiStatusCode;
  uint16_t u16CRC;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePSetCRC,
      EAPI_STATUS_INVALID_PARAMETER,
      BHandel
    );
  DO(EeePMapBuffer(BHandel, &BufferMap));

  EAPI_APP_RETURN_ERROR_IF(
      EeePSetCRC,
      BufferMap.pEeePCRCBlock==NULL,
      EAPI_STATUS_ERROR,
      TEXT("No CRC Block Present")
    );
  u16CRC=u16CRC_CCITT(
        BufferMap.pCmnHdr, 
        EAPI_GET_PTR_OFFSET(BufferMap.pEeePCRCBlock, BufferMap.pCmnHdr)
      );

  EeeP_Set16BitValue_BE(
        BufferMap.pEeePCRCBlock->CrC16, 
        u16CRC
      );


  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
EeePCheckCRC(
    EeePHandel_t BHandel
    )
{
  EeePBufferMap_t BufferMap;
  EApiStatusCode_t EApiStatusCode;
  uint16_t u16CRC1, u16CRC2;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePCheckCRC,
      EAPI_STATUS_INVALID_PARAMETER,
      BHandel
    );
  DO(EeePMapBuffer(BHandel, &BufferMap));

  EAPI_APP_RETURN_ERROR_IF(
      EeePCheckCRC,
      BufferMap.pEeePCRCBlock==NULL,
      EAPI_STATUS_ERROR,
      TEXT("No CRC Block Present")
    );
  u16CRC1=u16CRC_CCITT(
        BufferMap.pCmnHdr, 
        EAPI_GET_PTR_OFFSET(BufferMap.pEeePCRCBlock, BufferMap.pCmnHdr)
      );

  u16CRC2=EeeP_Get16BitValue_BE(BufferMap.pEeePCRCBlock->CrC16);

  EAPI_APP_RETURN_ERROR_IF(
      EeePCheckCRC        ,
      u16CRC1!=u16CRC2    ,
      EAPI_STATUS_ERROR   ,
      TEXT("CRC Invalid")
    );

  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
EeePAddBlock(
    EeePHandel_t   BHandel ,
    const void    *pcvBlock , 
          void   **pvIBlock , 
    const unsigned cuiFlags    
    )
{
  EeePBufferMap_t BufferMap;
  EApiStatusCode_t EApiStatusCode;
  size_t RequestBlockSize;
  DBlockIdHdr_t    *pTmpBlock   ;
  DBlockIdHdr_t    *pvTmpBlock; 

  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePAddBlock,
      EAPI_STATUS_INVALID_PARAMETER,
      BHandel
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePAddBlock,
      EAPI_STATUS_INVALID_PARAMETER,
      pcvBlock
    );
  if(pvIBlock!=NULL) *pvIBlock=NULL;
  RequestBlockSize=GetBlockLength(pcvBlock);
  DO(EeePMapBuffer(BHandel, &BufferMap));

  EAPI_APP_RETURN_ERROR_IF(
      EeePAddBlock,
      (BufferMap.pEmptyBlock==NULL),
      EAPI_STATUS_ERROR,
      TEXT("No Empty Block Present")
    );
  EAPI_APP_RETURN_ERROR_IF_S(
      EeePAddBlock,
      (RequestBlockSize+EEEP_MIN_BLOCK_LENGTH>(GetBlockLength(BufferMap.pEmptyBlock))),
      EAPI_STATUS_ERROR
    );
  EAPI_APP_RETURN_ERROR_IF_S(
      EeePAddBlock,
      (cuiFlags&EEEP_ADDBLK_IN_CRC)&&(BufferMap.pEeePCRCBlock==NULL),
      EAPI_STATUS_ERROR
    );

  if(cuiFlags&EEEP_ADDBLK_IN_CRC){
    /*
     * Adjust Empty Block length
     */
    pvTmpBlock=(DBlockIdHdr_t*)BufferMap.pEeePCRCBlock;
    DO(ReduceBlockLength(&BufferMap.pEmptyBlock, RequestBlockSize, NULL, 0));
    /*
     * Move CRC Up
     */
    pTmpBlock=EAPI_CREATE_PTR(BufferMap.pEmptyBlock, -(signed)GetBlockLength(BufferMap.pEeePCRCBlock), void *);
#if TEST_EEEPDB
    EAPI_printf(TEXT("%08X - %08X - %08X - %08x \n")  ,
        EAPI_GET_PTR_OFFSET(BufferMap.pEmptyBlock   , BHandel), 
        EAPI_GET_PTR_OFFSET(pTmpBlock               , BHandel), 
        EAPI_GET_PTR_OFFSET(BufferMap.pEeePCRCBlock , BHandel), 
        GetBlockLength(BufferMap.pEeePCRCBlock)
      );
#endif
    memmove(pTmpBlock, BufferMap.pEeePCRCBlock, GetBlockLength(BufferMap.pEeePCRCBlock));
    memset(pvTmpBlock, 0x00, RequestBlockSize);
    /*
     * Reset CRC Pointer
     */
    BufferMap.pEmptyBlock=pTmpBlock;

  }else{
    DO(ReduceBlockLength(&BufferMap.pEmptyBlock, RequestBlockSize, &pvTmpBlock, EEEP_RBL_REDUCE_TOP_DOWN));
  }
  /*
   * Copy Content
   */
  memcpy(pvTmpBlock, pcvBlock, RequestBlockSize);
  if(pvIBlock!=NULL) *pvIBlock=pvTmpBlock;

  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
EeePFindBlock(
    __IN  EeePHandel_t   BHandel,
    __IN  uint8_t        BlockId,
    __IN  signed int     Instance,
    __OUT void         **pvFBlock
    )
{
  DBlockIdHdr_t    *pCurBlock;
  EApiStatusCode_t EApiStatusCode;
  signed            lclInstance=0;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePFindBlock,
      EAPI_STATUS_INVALID_PARAMETER,
      BHandel
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePFindBlock,
      EAPI_STATUS_INVALID_PARAMETER,
      pvFBlock
    );

  DO(EeePGetFirstDB(BHandel, &pCurBlock));
  for(;pCurBlock!=NULL;pCurBlock=GetNextBlock(pCurBlock)){
    if(pCurBlock->DBlockId==BlockId){
      if(++lclInstance==Instance){
        *pvFBlock=pCurBlock;
        return EAPI_STATUS_SUCCESS;
      }
    }
  }
  EAPI_APP_RETURN_ERROR(
      EeePFindBlock,
      EAPI_STATUS_ERROR,
      TEXT("Block Not Found")
    );


}


EApiStatusCode_t
EeePWriteBufferToFile(
    __IN  EeePHandel_t   BHandel,
    __IN  char          *pszFilename
    )
{
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePWriteBufferToFile,
      EAPI_STATUS_INVALID_PARAMETER,
      BHandel
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePWriteBufferToFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pszFilename
    );
  EAPI_APP_RETURN_ERROR_IF(
      EeePWriteBufferToFile,
      memcmp(
          ((EeePCmn_t*)BHandel)->EepId, 
          EEEP_EEPROM_MARKER, 
          sizeof(EEEP_EEPROM_MARKER)-1
        ),
      EAPI_STATUS_ERROR,
      TEXT("Invalid EeeP Buffer")
    );

  return WriteBinaryFile(
          pszFilename, 
          BHandel, 
          256<<(((EeePCmn_t*)BHandel)->DeviceDesc&EEEP_DEVICE_SIZE_MASK)
      );
}


EApiStatusCode_t
EeePReadBufferFromFile(
    __OUT EeePHandel_t  *pBHandel,
    __IN  char          *pszFilename
    )
{
  EApiStatusCode_t EApiStatusCode;
  size_t stFileSize;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePReadBufferFromFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pBHandel
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePReadBufferFromFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pszFilename
    );
  DO(ReadBinaryFile(
          pszFilename, 
          pBHandel, 
          &stFileSize
      ));

    EAPI_APP_RETURN_ERROR_IF_S(
        EeePReadBufferFromFile,
        (stFileSize!=(size_t)(256<<(((EeePCmn_t*)*pBHandel)->DeviceDesc&EEEP_DEVICE_SIZE_MASK))),
        EAPI_STATUS_ERROR
      );
  if(memcmp(
          ((EeePCmn_t*)*pBHandel)->EepId, 
          EEEP_EEPROM_MARKER, 
          sizeof(EEEP_EEPROM_MARKER)-1
        ))
  {
    EAPI_APP_RETURN_ERROR(
        EeePReadBufferFromFile,
        EAPI_STATUS_ERROR,
        TEXT("Invalid EeeP Buffer")
      );
  }

  return EAPI_STATUS_SUCCESS;
}

unsigned WriteSizes[]={ 1,8,16,32,64,128,256,512 };
EApiStatusCode_t
EeePSetI2CDeviceDesc(
    __OUT I2CDeviceDesc_t *pDDesc,
    __IN  EeePHandel_t     BHandel,
    __IN  uint16_t         WRecTimems ,
    __IN  uint16_t         u16DeviceAddr
    )
{
  EAPI_APP_ASSERT_PARAMATER_NULL(
      EeePWriteBufferToEEP,
      EAPI_STATUS_INVALID_PARAMETER,
      BHandel
    );
  EAPI_APP_RETURN_ERROR_IF(
      EeePWriteBufferToEEP,
      memcmp(
          ((EeePCmn_t*)BHandel)->EepId, 
          EEEP_EEPROM_MARKER, 
          sizeof(EEEP_EEPROM_MARKER)-1
        ),
      EAPI_STATUS_ERROR,
      TEXT("Invalid EeeP Buffer")
    );
  pDDesc->DeviceAddr=u16DeviceAddr;
  pDDesc->WRecTimems=WRecTimems;
  pDDesc->PageSize  =(uint16_t)WriteSizes[(((EeePCmn_t*)BHandel)->DeviceDesc>>EEEP_DEVICE_WRITE_LEN_OFFSET)];
  pDDesc->ExtIndx   =(uint16_t)((((EeePCmn_t*)BHandel)->DeviceDesc&EEEP_DEVICE_EXT_INDEX)?EApiAPI2CExtIndex:EApiAPI2CStdIndex);
  pDDesc->DevSize   =256<<(((EeePCmn_t*)BHandel)->DeviceDesc&EEEP_DEVICE_SIZE_MASK);

  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
EeePWriteBufferToEEP(
    __IN  EeePHandel_t   BHandel,
    __IN  unsigned       DeviceBus ,
    __IN  uint16_t       u16DeviceAddr 
    )
{
  EApiStatusCode_t EApiStatusCode;
  I2CDeviceDesc_t DDesc;
  DO(EeePSetI2CDeviceDesc(&DDesc, BHandel, 5, u16DeviceAddr));
  return EApiAHI2CWriteEeprom(
          DeviceBus, 
          &DDesc, 
          0,
          BHandel, 
          DDesc.DevSize
      );
}


EApiStatusCode_t
EeePReadBufferFromEEP(
    __IN  EeePHandel_t  *pBHandel,
    __IN  unsigned          DeviceBus ,
    __IN  uint16_t       u16DeviceAddr 
    )
{
  EApiStatusCode_t EApiStatusCode;
  I2CDeviceDesc_t DDesc;
  EeePCmn_t     EeePCmnHdr; 
  size_t        stEEPSize;
  EAPI_APP_ASSERT_PARAMATER_NULL(
        EeePReadBufferFromEEP,
        EAPI_STATUS_INVALID_PARAMETER,
        pBHandel
      );
  *pBHandel=NULL;
  DDesc.DeviceAddr=u16DeviceAddr;
  DDesc.WRecTimems=5;
  DDesc.PageSize  =1;
  DDesc.ExtIndx   =(uint16_t)EApiAPI2CExtIndex;
  DDesc.DevSize   =sizeof(EeePCmnHdr);
  DO(EApiAHI2CReadEeprom(
          DeviceBus, 
          &DDesc, 
          1,
          EeePCmnHdr.EepId, 
          sizeof(EeePCmnHdr)- 1,
          sizeof(EeePCmnHdr)- 1
      ));

  DO(EeePSetI2CDeviceDesc(&DDesc, &EeePCmnHdr, 5, u16DeviceAddr));

  stEEPSize=256<<(EeePCmnHdr.DeviceDesc&EEEP_DEVICE_SIZE_MASK);
  *pBHandel=malloc(stEEPSize);

  EAPI_APP_ASSERT_PARAMATER_NULL(
        EeePReadBufferFromEEP,
        EAPI_STATUS_ALLOC_ERROR,
        *pBHandel
      );
  EApiStatusCode=EApiAHI2CReadEeprom(
          DeviceBus, 
          &DDesc, 
          0,
          *pBHandel, 
          stEEPSize,
          stEEPSize
      );
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
    free(*pBHandel);
    *pBHandel=NULL;
  }
  return EApiStatusCode;
}



#if TEST_EEEPDB
#define DO_MAIN(x) \
  EAPI_printf(TEXT("#####\n")TEXT("#\t%s\n")TEXT("#####\n"), TEXT(#x));\
  EApiStatusCode=x;\
  if(!EAPI_STATUS_TEST_OK(EApiStatusCode)) \
    return EApiStatusCode

/*
 * Create Block Content
 */
int 
__cdecl 
main(void)
{
  EeePHandel_t BHandel;
  void *pvInsertedBlock;
  EApiStatusCode_t EApiStatusCode;
  unsigned int i;
  uint8_t DummyBlock[]={0xF0,0x00,0x04,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B};
  /*
   * Create Block Content
   */
  DO_MAIN(EeePCreateNewBuffer(&BHandel, 256, sizeof(EeePCmn_t), EEEP_INIT_INCLUDE_CRC));
  PrintHexAsciiTable(
      BHandel, 
      256, 
      BHandel, 
      TEXT("Initialized EeeP Buffer With CRC Block")
    );
  DO_MAIN(EeePSetCRC(BHandel));
  PrintHexAsciiTable(
      BHandel, 
      256, 
      BHandel, 
      TEXT("Initialized EeeP Buffer With Set CRC Block")
    );
  for(i=0;i<29;i++){
    DO_MAIN(EeePAddBlock(BHandel, DummyBlock, &pvInsertedBlock, (i%2?EEEP_ADDBLK_IN_CRC:0)));
    PrintHexAsciiTable(
        BHandel, 
        256, 
        BHandel, 
        TEXT("Added Dummy Block")
      );
  }
  DO_MAIN(EeePSetCRC(BHandel));
  DO_MAIN(EeePCheckCRC(BHandel));
  PrintHexAsciiTable(
      BHandel, 
      256, 
      BHandel, 
      TEXT("Set CRC After Block Add")
    );
  DO_MAIN(EeePFreeBuffer(&BHandel));

  /* 
   * Test With NO CRC
   */
  DO_MAIN(EeePCreateNewBuffer(&BHandel, 256, sizeof(EeePCmn_t), 0));
  PrintHexAsciiTable(
      BHandel, 
      256, 
      BHandel, 
      TEXT("Initialized EeeP Buffer")
    );
  EeePSetCRC(BHandel);
  PrintHexAsciiTable(
      BHandel, 
      256, 
      BHandel, 
      TEXT("Initialized EeeP Buffer")
    );
  EeePAddBlock(BHandel, DummyBlock, &pvInsertedBlock, EEEP_ADDBLK_IN_CRC);
  PrintHexAsciiTable(
      BHandel, 
      256, 
      BHandel, 
      TEXT("Added Dummy Block")
    );
  for(i=0;i<30;i++){
    DO_MAIN(EeePAddBlock(BHandel, DummyBlock, &pvInsertedBlock, 0));
    PrintHexAsciiTable(
        BHandel, 
        256, 
        BHandel, 
        TEXT("Added Dummy Block")
      );
  }
  DO_MAIN(EeePFreeBuffer(&BHandel));





  exit(0);

}

#endif
