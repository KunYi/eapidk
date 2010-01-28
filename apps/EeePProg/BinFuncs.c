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
 *I Description: Auto Created for sEAPI_printf.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : BinFuncs.c
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

uint32_t 
u32ChecksumBlock(
	const void *pcvBuffer, 
	size_t  	  stLength
	)
{
  uint32_t ChkSum=0;
  while(stLength--){
    ChkSum+=(uint32_t)(*((uint8_t*)pcvBuffer));
    pcvBuffer=((uint8_t*)pcvBuffer)+1;
  }
  return ChkSum;
}
uint16_t 
u16ChecksumBlock(
	const void * pcvBuffer, 
	size_t   	   stLength
	)
{
  return EEEP_LO_UINT16(u32ChecksumBlock(pcvBuffer, stLength));
}
uint8_t  
u8ChecksumBlock (
	const void * pcvBuffer, 
	size_t   	   stLength
	)
{
  return EEEP_LO_UINT8(u32ChecksumBlock(pcvBuffer, stLength));
}

uint16_t
u16CRC_CCITT (
    __IN const void *pcvBuffer, /* Pointer to Buffer */
    __IN size_t      stCount    /* Num bytes to CRC */
  )
{ 
  const uint8_t *pcu8Buffer=pcvBuffer; 
  unsigned CRC=0; 
  unsigned i; 
  while (stCount --) { 
    CRC^= *pcu8Buffer++ << 8; 
    for (i = 8; i ; i --){ 
      if (CRC & 0x8000){ 
        CRC+=CRC; 
        CRC^=0x1021; 
      }else{ 
        CRC+=CRC; 
      }
    }
  }
  return EEEP_LO_UINT16(CRC);
}


TCHAR
cBin2Ascii(
    __IN  unsigned int uiValue
  )
{
  if(uiValue>=0x20&&uiValue<=0x7F){
    return (char)(uiValue);
  }else{
    return '.';
  }
}
signed int
siBin2Ascii(
    __OUT TCHAR          *pszString ,
    __IN  size_t          BufLength ,
    __IN  const uint8_t  *pcu8Value ,
    __IN  size_t          VarSize   ,
    __IN  const unsigned  cFlags
  )
{
    signed int StringPos=0;
    size_t Bufpos;
    for(Bufpos=0;Bufpos<VarSize;Bufpos++){
      if(cFlags&HEXTBL_BIG_ENDIAN){
        StringPos+=EApiSprintf(
            pszString+StringPos   ,
            BufLength - StringPos , 
            TEXT("%02X")                , 
            pcu8Value[VarSize - 1 - Bufpos]
          );
      }else{
        StringPos+=EApiSprintf(
            pszString+StringPos   , 
            BufLength - StringPos , 
            TEXT("%02X")                , 
            pcu8Value[Bufpos]
          );
      }
    }
    return StringPos;
}

void 
PrintHexAsciiTableEx(
	const void *   pcvBuffer	,
	const size_t   stBufSize	,
	const void *   pcvBase		,
	const TCHAR *  pcszDescription,
	const unsigned cuiFlags
	)
{
    
    size_t        stOffset;
    size_t        stOffsetBase;
    const uint8_t *pcu8Mem;
    const uint8_t *pcu8PageEnd;
    size_t        stElementSize;
    size_t        stElementCount;
    size_t        stRowSize;
    TCHAR  szAsciiBufer[100];


    if(pcvBuffer==NULL){
      EAPI_FORMATED_MES(E, PrintHexAsciiTableEx, EAPI_STATUS_INVALID_PARAMETER, TEXT("(pcvBuffer==NULL)"));
      return ;
    }
    if(pcvBase==NULL)
      pcvBase=pcvBuffer;

    pcu8Mem=pcvBase;

    stElementSize=1<<((cuiFlags&HEXTBL_WIDTH_MASK)>>12);
    stElementCount=cuiFlags&HEXTBL_COUNT_MASK;
    stRowSize=stElementCount*stElementSize;
    pcu8PageEnd=((const uint8_t *)pcvBuffer)+stBufSize;

    if(pcszDescription!=NULL)
      EAPI_printf(TEXT("\n%s\n"), pcszDescription);
    stOffset=((uint8_t*)pcvBuffer)- pcu8Mem;

    if(cuiFlags&HEXTBL_OFFSET_TITLE)
      EAPI_printf(TEXT("\n\tOFFSET = 0x%08lX, LENGTH = 0x%08lX\n"), (unsigned long)stOffset, (unsigned long)stBufSize);

    if(stBufSize==0) return ;

    pcu8Mem=((uint8_t*)pcvBuffer) - (stOffset%stRowSize);

    stOffsetBase=pcu8Mem - (uint8_t*)pcvBase;
    while(pcu8Mem<pcu8PageEnd)
    {
      stOffset=pcu8Mem - (uint8_t*)pcvBase;
      if(!((stOffset - stOffsetBase)%(stRowSize*16))){
        /*
         * Print Block Header
         */
        EAPI_printf(TEXT("\n"));
        if(cuiFlags&HEXTBL_OFFSEt_BAR)
          EAPI_printf(TEXT("         "));
        if(cuiFlags&HEXTBL_OFFSET_COUNT){
          for(stOffset=0;stOffset<stElementCount;stOffset++){
            EAPI_printf(TEXT("%0*lX "), (int)(2*stElementSize), (unsigned long)stOffset);
          }
          if(cuiFlags&HEXTBL_ASCII_MASK){
            for(stOffset=0;stOffset<(stRowSize);stOffset++){
              EAPI_printf(TEXT("%lX"), (((unsigned long)stOffset)&0xF));
            }
          }
          EAPI_printf(TEXT("\n"));
        }
        stOffset=pcu8Mem - (uint8_t*)pcvBase;
      }
      if(cuiFlags&HEXTBL_OFFSEt_BAR)
        EAPI_printf(TEXT("%08lX ") , (unsigned long)stOffset);

        /*
         * Print Binary Hex Data
         */
      for(stOffset=0; stOffset<stRowSize; stOffset+=stElementSize)
      {
        if((pcu8PageEnd>(pcu8Mem+stOffset))&&((stOffset+pcu8Mem)>=((uint8_t *)pcvBuffer))){
          siBin2Ascii(
              szAsciiBufer            , 
              ARRAY_SIZE(szAsciiBufer), 
              pcu8Mem+stOffset        , 
              stElementSize           , 
              cuiFlags
            );
          EAPI_printf(TEXT("%s "), szAsciiBufer);
        }else{
          EAPI_printf(TEXT("%*s "), (int)(2*stElementSize), TEXT(""));
        }
      }
      if(cuiFlags&HEXTBL_ASCII_MASK){
        /*
         * Print ASCII Characters
         */
        for(stOffset=0;stOffset<stRowSize;stOffset++)
        {
          if((pcu8PageEnd>(pcu8Mem+stOffset))&&((stOffset+pcu8Mem)>=((uint8_t *)pcvBuffer))){
            EAPI_printf(TEXT("%c"), cBin2Ascii(pcu8Mem[stOffset]));
          }else{
            EAPI_printf(TEXT(" "));
          }
        }
      }
      pcu8Mem+=stRowSize;
      EAPI_printf(TEXT("\n"));
    }
}

void 
PrintHexAsciiTable(
	const void *const pcvBuffer	,
	const size_t stBufSize		,
	const void *const pcvBase		,
	const TCHAR *const pcszDescription
	)
{
  PrintHexAsciiTableEx(
      pcvBuffer           ,
      stBufSize           ,
      pcvBase             ,
      pcszDescription     ,
      HEXTBL_NORM8_ATTRIB
    );
}



EApiStatusCode_t 
WriteBinaryFile(
    __IN const char *pcszFilename, 
    __IN const void *pcvBuffer   , 
    __IN size_t      stWriteBCnt
  )
{
  FILE *LclFilePtr;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      WriteBinaryFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pcszFilename
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      WriteBinaryFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pcvBuffer
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      WriteBinaryFile,
      EAPI_STATUS_INVALID_PARAMETER,
      stWriteBCnt
    );

  LclFilePtr=fopen(pcszFilename, "wb");
  EAPI_APP_ASSERT_PARAMATER_NULL(
      WriteBinaryFile,
      EAPI_STATUS_WRITE_ERROR,
      LclFilePtr
    );
  EAPI_APP_RETURN_ERROR_IF_S(
      ReadBinaryFile,
      (stWriteBCnt!=fwrite(pcvBuffer, sizeof(uint8_t), stWriteBCnt, LclFilePtr))*sizeof(uint8_t),
      EAPI_STATUS_WRITE_ERROR
    );
  fclose(LclFilePtr);
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
ReadBinaryFile(
    __IN  const char *pcszFilename, 
    __OUT void      **pvBuffer, 
    __OUT size_t     *pstReadBCnt
  )
{
  FILE *LclFilePtr;
  size_t stFileLen;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ReadBinaryFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pcszFilename
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ReadBinaryFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pvBuffer
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ReadBinaryFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pstReadBCnt
    );
  *pstReadBCnt=0;
  LclFilePtr=fopen(pcszFilename, "rb");
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ReadBinaryFile,
      EAPI_STATUS_READ_ERROR,
      LclFilePtr
    );

  fseek(LclFilePtr, 0, SEEK_END);
  stFileLen=ftell(LclFilePtr);
  rewind(LclFilePtr);
  *pvBuffer=malloc(stFileLen);
  EAPI_APP_ASSERT_PARAMATER_NULL(
      WriteBinaryFile,
      EAPI_STATUS_ALLOC_ERROR,
      *pvBuffer
    );

  if(stFileLen!=fread(*pvBuffer, sizeof(uint8_t), stFileLen, LclFilePtr)*sizeof(uint8_t)){
    free(*pvBuffer);
    *pvBuffer=NULL;
    EAPI_APP_RETURN_ERROR(
        ReadBinaryFile,
        EAPI_STATUS_READ_ERROR,
        TEXT("(stFileLen!=fread(*pvBuffer, sizeof(uint8_t), stFileLen, LclFilePtr)*sizeof(uint8_t))")
      );
  }
  *pstReadBCnt=stFileLen;
  fclose(LclFilePtr);

  return EAPI_STATUS_SUCCESS;
}


/*
 * CPU Independent Multi Byte 
 * Big Endian Memory Access
 */
void
EeeP_Set16BitValue_BE(
    uint8_t *pBuffer,
    uint16_t Value
     )
{
  pBuffer[1]=EEEP_LO_UINT8(Value   );
  pBuffer[0]=EEEP_LO_UINT8(Value>>(8*1));
}
uint16_t
EeeP_Get16BitValue_BE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[1]    ) |
         (pBuffer[0]<<(8*1)) ;
}
void
EeeP_Set32BitValue_BE(
    uint8_t *pBuffer,
    uint32_t Value
     )
{
  pBuffer[3]=EEEP_LO_UINT8(Value    );
  pBuffer[2]=EEEP_LO_UINT8(Value>>(8*1));
  pBuffer[1]=EEEP_LO_UINT8(Value>>(8*2));
  pBuffer[0]=EEEP_LO_UINT8(Value>>(8*3));
}
uint32_t
EeeP_Get32BitValue_BE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[3]    ) |
         (pBuffer[2]<<(8*1)) |
         (pBuffer[1]<<(8*2)) |
         (pBuffer[0]<<(8*3)) ;
}
void
EeeP_Set64BitValue_BE(
    uint8_t *pBuffer,
    uint64_t Value
     )
{
  pBuffer[7]=EEEP_LO_UINT8(Value       );
  pBuffer[6]=EEEP_LO_UINT8(Value>>(8*1));
  pBuffer[5]=EEEP_LO_UINT8(Value>>(8*2));
  pBuffer[4]=EEEP_LO_UINT8(Value>>(8*3));
  pBuffer[3]=EEEP_LO_UINT8(Value>>(8*4));
  pBuffer[2]=EEEP_LO_UINT8(Value>>(8*5));
  pBuffer[1]=EEEP_LO_UINT8(Value>>(8*6));
  pBuffer[0]=EEEP_LO_UINT8(Value>>(8*7));
}
uint64_t
EeeP_Get64BitValue_BE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[7]       ) |
         (pBuffer[6]<<(8*1)) |
         (pBuffer[5]<<(8*2)) |
         (pBuffer[4]<<(8*3)) |
         ((uint64_t)pBuffer[3]<<(8*4)) |
         ((uint64_t)pBuffer[2]<<(8*5)) |
         ((uint64_t)pBuffer[1]<<(8*6)) |
         ((uint64_t)pBuffer[0]<<(8*7)) ;
}
/*
 * CPU Independent Multi Byte 
 * Little Endian Memory Access
 */
void
EeeP_Set16BitValue_LE(
    uint8_t *pBuffer,
    uint16_t Value
     )
{
  pBuffer[0]=EEEP_LO_UINT8(Value       );
  pBuffer[1]=EEEP_LO_UINT8(Value>>(8*1));
}
uint16_t
EeeP_Get16BitValue_LE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[0]    ) |
         (pBuffer[1]<<(8*1)) ;
}
void
EeeP_Set32BitValue_LE(
    uint8_t *pBuffer,
    uint32_t Value
     )
{
  pBuffer[0]=EEEP_LO_UINT8(Value    );
  pBuffer[1]=EEEP_LO_UINT8(Value>>(8*1));
  pBuffer[2]=EEEP_LO_UINT8(Value>>(8*2));
  pBuffer[3]=EEEP_LO_UINT8(Value>>(8*3));
}
uint32_t
EeeP_Get32BitValue_LE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[0]    ) |
         (pBuffer[1]<<(8*1)) |
         (pBuffer[2]<<(8*2)) |
         (pBuffer[3]<<(8*3)) ;
}
void
EeeP_Set64BitValue_LE(
    uint8_t *pBuffer,
    uint64_t Value
     )
{
  pBuffer[0]=EEEP_LO_UINT8(Value       );
  pBuffer[1]=EEEP_LO_UINT8(Value>>(8*1));
  pBuffer[2]=EEEP_LO_UINT8(Value>>(8*2));
  pBuffer[3]=EEEP_LO_UINT8(Value>>(8*3));
  pBuffer[4]=EEEP_LO_UINT8(Value>>(8*4));
  pBuffer[5]=EEEP_LO_UINT8(Value>>(8*5));
  pBuffer[6]=EEEP_LO_UINT8(Value>>(8*6));
  pBuffer[7]=EEEP_LO_UINT8(Value>>(8*7));
}
uint64_t
EeeP_Get64BitValue_LE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[0]       ) |
         (pBuffer[1]<<(8*1)) |
         (pBuffer[2]<<(8*2)) |
         (pBuffer[3]<<(8*3)) |
         ((uint64_t)pBuffer[4]<<(8*4)) |
         ((uint64_t)pBuffer[5]<<(8*5)) |
         ((uint64_t)pBuffer[6]<<(8*6)) |
         ((uint64_t)pBuffer[7]<<(8*7)) ;
}





#if TEST_BINFUNC



void
main(void)
{
  uint8_t buffer[0x100]=
    {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
  PrintHexAsciiTableEx(buffer+2, 0x10, buffer, NULL, HEXTBL_8BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|15);
  PrintHexAsciiTableEx(buffer+3, 0x10, buffer, NULL, HEXTBL_NORM8_ATTRIB);
  PrintHexAsciiTableEx(buffer+4, 0x10, buffer, NULL, HEXTBL_8BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|17);

  PrintHexAsciiTableEx(buffer+2, 0x10, buffer, NULL, HEXTBL_16BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|7);
  PrintHexAsciiTableEx(buffer+3, 0x10, buffer, NULL, HEXTBL_NORM16_ATTRIB);
  PrintHexAsciiTableEx(buffer+4, 0x10, buffer, NULL, HEXTBL_16BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|9);

  PrintHexAsciiTableEx(buffer+2, 0x10, buffer, NULL, HEXTBL_32BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|3);
  PrintHexAsciiTableEx(buffer+4, 0x10, buffer, NULL, HEXTBL_NORM32_ATTRIB);
  PrintHexAsciiTableEx(buffer+5, 0x10, buffer, NULL, HEXTBL_32BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|5);

  PrintHexAsciiTableEx(buffer+2, 0x10, buffer, NULL, HEXTBL_64BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|1);
  PrintHexAsciiTableEx(buffer+4, 0x10, buffer, NULL, HEXTBL_NORM64_ATTRIB);
  PrintHexAsciiTableEx(buffer+6, 0x10, buffer, NULL, HEXTBL_64BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|3);

  EAPI_printf(TEXT("Checksum=%08")TEXT(PRIX32)TEXT("\n"), u32ChecksumBlock(buffer, ARRAY_SIZE(buffer)));

  PrintHexAsciiTable(buffer+3, 0x200, buffer, TEXT("Test 7"));
  
  PrintHexAsciiTableEx(buffer+2, 0x200, buffer, NULL, HEXTBL_8BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|24);
  
  exit(0);
}
#endif

