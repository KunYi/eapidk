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
__stdcall
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
__stdcall
u16ChecksumBlock(
	const void * pcvBuffer, 
	size_t   	   stLength
	)
{
  return EEEP_LO_UINT16(u32ChecksumBlock(pcvBuffer, stLength));
}
uint8_t  
__stdcall
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
__stdcall
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
__stdcall
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
__stdcall
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
      EAPI_printf(TEXT("E%04x %-20s %s\n"), __LINE__, TEXT("PrintHexAsciiTableEx"), TEXT("pcvBuffer==(NULL)"));
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
      EAPI_printf(TEXT("\n\tOFFSET = 0x%08X, LENGTH = 0x%08X\n"), stOffset, stBufSize);

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
            EAPI_printf(TEXT("%0*X "), 2*stElementSize, stOffset);
          }
          if(cuiFlags&HEXTBL_ASCII_MASK){
            for(stOffset=0;stOffset<(stRowSize);stOffset++){
              EAPI_printf(TEXT("%1X"), stOffset&0xF);
            }
          }
          EAPI_printf(TEXT("\n"));
        }
        stOffset=pcu8Mem - (uint8_t*)pcvBase;
      }
      if(cuiFlags&HEXTBL_OFFSEt_BAR)
        EAPI_printf(TEXT("%08lX ") , stOffset);

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
          EAPI_printf(TEXT("%*s "), 2*stElementSize, TEXT(""));
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
__stdcall
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
  fwrite(pcvBuffer, stWriteBCnt, sizeof(uint8_t), LclFilePtr);
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

  fread(*pvBuffer, stFileLen, sizeof(uint8_t), LclFilePtr);
  fclose(LclFilePtr);
  *pstReadBCnt=stFileLen;

  return EAPI_STATUS_SUCCESS;
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

