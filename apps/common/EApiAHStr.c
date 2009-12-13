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
 *I Description: Auto Created for EApiAHStr.c
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiAHStr.c
 *I  File Location        : apps\common
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EApiApp.h>
typedef struct ErrorLookupTbl_S{
  const uint32_t StatusCode;
  const TCHAR *const  ErrorString;
}ErrorLookupTbl_t;

#define KUXE_INVALID_STRLEN ((size_t )-1)

const ErrorLookupTbl_t ErrorLookup[]={
  {EAPI_STATUS_NOT_INITIALIZED        , TEXT("EAPI_STATUS_NOT_INITIALIZED"          )},
  {EAPI_STATUS_INITIALIZED            , TEXT("EAPI_STATUS_INITIALIZED"              )},
  {EAPI_STATUS_ALLOC_ERROR            , TEXT("EAPI_STATUS_ALLOC_ERROR"              )},
  {EAPI_STATUS_DRIVER_TIMEOUT         , TEXT("EAPI_STATUS_DRIVER_TIMEOUT"           )},
  {EAPI_STATUS_INVALID_PARAMETER      , TEXT("EAPI_STATUS_INVALID_PARAMETER"        )},
  {EAPI_STATUS_INVALID_BLOCK_ALIGNMENT, TEXT("EAPI_STATUS_INVALID_BLOCK_ALIGNMENT"  )},
  {EAPI_STATUS_INVALID_BLOCK_LENGTH   , TEXT("EAPI_STATUS_INVALID_BLOCK_LENGTH"     )},
  {EAPI_STATUS_INVALID_DIRECTION      , TEXT("EAPI_STATUS_INVALID_DIRECTION"        )},
  {EAPI_STATUS_INVALID_BITMASK        , TEXT("EAPI_STATUS_INVALID_BITMASK"          )},
  {EAPI_STATUS_RUNNING                , TEXT("EAPI_STATUS_RUNNING"                  )},
  {EAPI_STATUS_UNSUPPORTED            , TEXT("EAPI_STATUS_UNSUPPORTED"              )},
  {EAPI_STATUS_NOT_FOUND              , TEXT("EAPI_STATUS_NOT_FOUND"                )},
  {EAPI_STATUS_TIMEOUT                , TEXT("EAPI_STATUS_TIMEOUT"                  )},
  {EAPI_STATUS_BUSY_COLLISION         , TEXT("EAPI_STATUS_BUSY_COLLISION"           )},
  {EAPI_STATUS_READ_ERROR             , TEXT("EAPI_STATUS_READ_ERROR"               )},
  {EAPI_STATUS_WRITE_ERROR            , TEXT("EAPI_STATUS_WRITE_ERROR"              )},
  {EAPI_STATUS_MORE_DATA              , TEXT("EAPI_STATUS_MORE_DATA"                )},
  {EAPI_STATUS_ERROR                  , TEXT("EAPI_STATUS_ERROR"                    )},
  {EAPI_STATUS_SUCCESS                , TEXT("EAPI_STATUS_SUCCESS"                  )},
};
#define UNKNOWN_ERR_LEN sizeof("UNKNOWN ERROR(0x00000000)")
size_t EApiAHCreateErrorString(
    __IN uint32_t         StatusCode  ,
    __OUT TCHAR *const    pString     , 
    __IN const size_t     StrBufLen 
    )
{
  unsigned i;

  EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateErrorString, KUXE_INVALID_STRLEN, pString);
  EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateErrorString, KUXE_INVALID_STRLEN, StrBufLen);

  for(i=0; i<ARRAY_SIZE(ErrorLookup);i++)
  {
    if(ErrorLookup[i].StatusCode==StatusCode){

      if(pString!=NULL){
        EApiStrCpy(pString, StrBufLen, ErrorLookup[i].ErrorString);
        return EAPI_strlen (pString);
      }
      return KUXE_INVALID_STRLEN;
    }
  }
  if(pString!=NULL){
    EApiSprintf(pString, StrBufLen, 
      TEXT("UNKNOWN ERROR(0x%08")TEXT(PRIX32)TEXT(")"), 
      StatusCode
      );
    return EAPI_strlen (pString);
  }
  return KUXE_INVALID_STRLEN;
}
uint32_t
EApiAHCreateErrorStringAlloc(
  __IN uint32_t         StatusCode  ,
  __OUT TCHAR * *const  pString 
  )
{
  unsigned i;
  size_t StrLen;

  EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateErrorStringAlloc, EAPI_STATUS_INVALID_PARAMETER, pString);

  for(i=0; i<ARRAY_SIZE(ErrorLookup);i++)
  {
    if(ErrorLookup[i].StatusCode==StatusCode){
      StrLen=EAPI_strlen(ErrorLookup[i].ErrorString)+1;
      *pString=malloc(StrLen*sizeof(TCHAR));
      if(*pString!=NULL)
        EApiStrCpy(*pString, StrLen, ErrorLookup[i].ErrorString);
      return EAPI_STATUS_SUCCESS;
    }
  }
  *pString=malloc(UNKNOWN_ERR_LEN*sizeof(TCHAR));
  if(*pString!=NULL)
    EApiSprintf(*pString, 
      UNKNOWN_ERR_LEN, 
      TEXT("UNKNOWN ERROR(0x%08")TEXT(PRIX32)TEXT(")"), 
      StatusCode
      );
  return StatusCode;
}

size_t 
EApiAHGetString(
    __IN  uint32_t        StringID  , /* EApi String ID */
    __OUT TCHAR *         pString   , /* Pointer To String pBuffer */
    __IN  size_t          StrBufLen   /* String pBuffer Length */
    )
{
  uint32_t ReturnValue;
  uint32_t StringLenLcl=(uint32_t)StrBufLen;
  size_t StringBufferLenBck=StrBufLen;
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHGetString, KUXE_INVALID_STRLEN, pString);
  EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHGetString, KUXE_INVALID_STRLEN, StrBufLen);

  ReturnValue=EApiBoardGetString(StringID, pString, &StringLenLcl);
  if(ReturnValue!=EAPI_STATUS_SUCCESS)
      StringLenLcl=(uint32_t)EApiAHCreateErrorString(ReturnValue, pString, StringBufferLenBck);
#if (STRICT_VALIDATION>0)
  EAPI_APP_RETURN_ERROR_IF(
      EApiAHGetStringAlloc, 
      (StringLenLcl>StringBufferLenBck), 
      KUXE_INVALID_STRLEN, 
      TEXT("Interface Returning Different String Lengths")
      );
  if(EApiStrLen(pString, StringBufferLenBck)==StringBufferLenBck)
  {
     EAPI_FORMATED_MES(E, 
         EApiAHGetString, 
         KUXE_INVALID_STRLEN, 
         TEXT("Returned String Missing Terminating \\0 Character." )
         );
    pString[StringBufferLenBck-1]=TEXT('\0');
  }
#endif
  return StringLenLcl;
}

uint32_t 
EApiAHGetStringAlloc(
    __IN  uint32_t        StringID, /* EApi String ID */
    __OUT TCHAR * *const  pString   /* Pointer to where string 
                                     * pointer should be stored 
                                     */
    )
{
  uint32_t StringLen=0;
  uint32_t StringBufferLenBck=0;
  uint32_t ReturnValue;
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHGetString, EAPI_STATUS_INVALID_PARAMETER, pString);
  *pString=NULL;
  ReturnValue=EApiBoardGetString(StringID, *pString, &StringLen);
  switch(ReturnValue){
    case EAPI_STATUS_MORE_DATA:
      StringBufferLenBck=StringLen;
      *pString=malloc(StringLen*sizeof(TCHAR));

      EAPI_APP_RETURN_ERROR_IF(
          EApiAHGetStringAlloc, 
          (*pString==NULL), 
          EAPI_STATUS_ALLOC_ERROR, 
          TEXT("Memory Allocation Error")
          );

      ReturnValue=EApiBoardGetString(StringID, *pString, &StringLen);
#if (STRICT_VALIDATION>0)
      EAPI_APP_RETURN_ERROR_IF(
          EApiAHGetStringAlloc, 
          (StringLen>StringBufferLenBck), 
          EAPI_STATUS_ERROR, 
          TEXT("Interface Returning Different String Lengths")
          );
      if(EApiStrLen(*pString, StringBufferLenBck)==StringBufferLenBck)
      {
        EAPI_FORMATED_MES(E, 
            EApiAHGetStringAlloc, 
            EAPI_STATUS_ERROR, 
            TEXT("Returned String Missing Terminating \\0 Character." )
            );
        (*pString)[StringBufferLenBck-1]=TEXT('\0');
      }
#endif
      break;
    default:
      EApiAHCreateErrorStringAlloc(ReturnValue, pString);
      break;
  }
  return ReturnValue;
}
int
EApiAHCreateDecimalString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateDecimalString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateDecimalString, -1, StrBufLen);
    return EApiSprintf(pString, StrBufLen, TEXT("%lu"), Value);
}
int
EApiAHCreateHexString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateDecimalString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateDecimalString, -1, StrBufLen);
    return EApiSprintf(pString, StrBufLen, TEXT("0x%08")TEXT(PRIX32), Value);
}
int
EApiAHCreateVoltageString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateDecimalString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateDecimalString, -1, StrBufLen);
    Value/=10;
    return EApiSprintf(pString, StrBufLen, TEXT("%lu.%02lu Volts"), Value/100, Value%100);
}
int
EApiAHCreateRotationsString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateDecimalString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateDecimalString, -1, StrBufLen);
    return EApiSprintf(pString, StrBufLen, TEXT("%lu RPM"), Value);
}
int
EApiAHCreateTempString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateDecimalString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateDecimalString, -1, StrBufLen);
    Value-=EAPI_KELVINS_OFFSET;
    return EApiSprintf(pString, StrBufLen, TEXT("% li.%lu Celcius"), ((int32_t)Value)/10, Value%10);
}
int
EApiAHCreateTimeString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    int StrLength=0;
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateTimeString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateTimeString, -1, StrBufLen);
    if(Value/365/24/60)
      StrLength+=EApiSprintf(&pString[StrLength], StrBufLen-StrLength, TEXT("%lu Years "), Value/365/24/60   );
    if(StrLength||((Value/24/60)%365))
      StrLength+=EApiSprintf(&pString[StrLength], StrBufLen-StrLength, TEXT("%lu Days " ), (Value/24/60)%365 );
    if(StrLength||((Value/60)%24))
      StrLength+=EApiSprintf(&pString[StrLength], StrBufLen-StrLength, TEXT("%lu Hours "), (Value/60)%24     );
      StrLength+=EApiSprintf(&pString[StrLength], StrBufLen-StrLength, TEXT("%lu Mins"  ), (Value)%60        );
    return StrLength;
}


int
EApiAHCreateSVersionString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    /* 255.255 */
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateSVersionString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateSVersionString, -1, StrBufLen);
    return EApiSprintf(pString, StrBufLen, TEXT("%u.%u"), EAPI_VER_GET_VER(Value), EAPI_VER_GET_REV(Value) );
}
int 
EApiAHCreateVersionString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    /* 255.255.65535 */
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateVersionString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateVersionString, -1, StrBufLen);
    return EApiSprintf(pString, StrBufLen, TEXT("%u.%u.%u"), EAPI_VER_GET_VER(Value), EAPI_VER_GET_REV(Value), EAPI_VER_GET_BUILD(Value) );
}


TCHAR CompressedAsciiLookup[]={
  TEXT(' '), TEXT('A'), TEXT('B'), TEXT('C'),
  TEXT('D'), TEXT('E'), TEXT('F'), TEXT('G'),
  TEXT('H'), TEXT('I'), TEXT('J'), TEXT('K'),
  TEXT('L'), TEXT('M'), TEXT('N'), TEXT('O'),
  TEXT('P'), TEXT('Q'), TEXT('R'), TEXT('S'),
  TEXT('T'), TEXT('U'), TEXT('V'), TEXT('W'),
  TEXT('X'), TEXT('Y'), TEXT('Z'),
  /* Invalid Values */
#ifdef DEGUG
  TEXT('0'), TEXT('1'), TEXT('2'), TEXT('3'), TEXT('4')
#else
  TEXT('*'), TEXT('*'), TEXT('*'), TEXT('*'), TEXT('*')
#endif
};

int 
EApiAHCreatePNPIDString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
  int cnt;
  unsigned short PNPID=(unsigned short)BYTE_SWAP_W(Value);
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreatePNPIDString, -1, pString);
  if(StrBufLen<4){
    EAPI_APP_RETURN_ERROR(EApiAHCreatePNPIDString, -1, "pBuffer Too Short");
  }
  if(PNPID&(1<<15)){
    return -1;
  }
  for(cnt=0; cnt < 3; cnt++){
    pString[2 - cnt]=CompressedAsciiLookup[(PNPID>>(cnt*5))&0x1F];
  }
  pString[cnt]=0;
  return 3;
}

#ifdef UNICODE
uint32_t 
EApiAHBoardGetStringW(
    __IN      uint32_t  Id      , /* Name Id */
    __OUT     wchar_t  *pBuffer , /* Destination pBuffer */
    __INOUT   uint32_t *pBufLen   /* pBuffer Length */
    )
{
  char *pBufferPtr=NULL;
  uint32_t ReturnValue;
  if(pBuffer!=NULL && pBufLen!=NULL && *pBufLen)
  {
    pBufferPtr=(char *)malloc(*pBufLen*sizeof(char));
    EAPI_APP_RETURN_ERROR_IF(
      EApiAHBoardGetStringW, 
      pBufferPtr==NULL,
      EAPI_STATUS_ALLOC_ERROR, 
      TEXT("Allocating ASCII Buffer")
      );
  }

  ReturnValue=EApiBoardGetStringA(Id, pBufferPtr, pBufLen);

  if(pBufferPtr!=NULL)
  {
    mbstowcs(pBuffer, pBufferPtr, *pBufLen);
    free(pBufferPtr);
  }

  return ReturnValue;
}
#endif
/****************************************************************************
 * Standard C String Wrappers
 *  Basically to improve Security, Ensures that No pBuffer overruns happen
 *  
 *  EApiStrLen  is equivalent to strnlen  , wcsnlen (Not present in older libraries)
 *  EApiStrCpy  is equivalent to strcpy_s , Terminates String if pBuffer too short
 *  EApiSprintf is equivalent to sprintf_s, Terminates String if pBuffer too short
 *
 ****************************************************************************/
size_t 
EApiStrLen  ( 
    __IN const TCHAR *pBuffer    ,
    __IN size_t       BufferLen
    )
{
  uint32_t i;
#if 0
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiStrLen, 0, pBuffer);
  EAPI_APP_ASSERT_PARAMATER_ZERO(EApiStrLen, 0, BufferLen);
#else
  if(pBuffer   ==NULL) return 0;
  if(BufferLen==0   ) return 0;
#endif

  for(i=0; i<BufferLen; i++)
    if(pBuffer[i]==TEXT('\0'))
      break;
  return i;
}
TCHAR * 
EApiStrCpy(
    __OUT TCHAR *const      StringDest   ,
    __IN size_t             StrBufLen    , 
    __IN const TCHAR *const StringSource
    )
{
#if 0
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiStrCpy, StringDest, StringDest);
  EAPI_APP_ASSERT_PARAMATER_ZERO(EApiStrCpy, StringDest, StrBufLen);
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiStrCpy, StringDest, StringSource);
#else
  if(StringDest  ==NULL) return StringDest;
  if(StringSource==NULL) return StringDest;
  if(StrBufLen==0   ) return StringDest;
#endif

  EAPI_strncpy(StringDest, StringSource, StrBufLen);
  StringDest[StrBufLen-1]=TEXT('\0');
  return StringDest;
}
int 
__cdecl 
EApiSprintf ( 
    __IN TCHAR *const       pBuffer   ,
    __IN const size_t       BufferLen ,
    __IN const TCHAR *const fmt       ,
    ...
    )
{
  int ReturnValue;
  va_list arg;
#if 0
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiSprintf, -1, pBuffer);
  EAPI_APP_ASSERT_PARAMATER_ZERO(EApiSprintf, -1, BufferLen);
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiSprintf, -1, fmt);
#else
  if(pBuffer  ==NULL) return -1;
  if(fmt      ==NULL) return -1;
  if(BufferLen==0   ) return -1;
#endif

  va_start(arg, fmt);
  ReturnValue=EAPI_vsnprintf(pBuffer, BufferLen, fmt, arg);
  pBuffer[BufferLen-1]=TEXT('\0');
  va_end(arg);
  return ReturnValue;
}


