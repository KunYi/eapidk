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
 *I Description: Auto Created for EApiAHStr.c
 *I
 *+-------------------------------------------------------------------------
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
  const EApiStatusCode_t StatusCode;
  const TCHAR *const  ErrorString;
}ErrorLookupTbl_t;

#define EAPI_INVALID_STRLEN ((size_t )-1)

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
    __IN EApiStatusCode_t StatusCode  ,
    __OUT TCHAR *const    pString     , 
    __IN const size_t     StrBufLen 
    )
{
  size_t EApiStatusCode=EAPI_INVALID_STRLEN;
  unsigned i;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      EApiAHCreateErrorString, 
      EAPI_INVALID_STRLEN, 
      pString
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      EApiAHCreateErrorString, 
      EAPI_INVALID_STRLEN, 
      StrBufLen
    );

  for(i=0; i<ARRAY_SIZE(ErrorLookup);i++)
  {
    if(ErrorLookup[i].StatusCode==StatusCode){

      if(pString!=NULL){
        EApiStrCpy(pString, StrBufLen, ErrorLookup[i].ErrorString);
        EApiStatusCode= EAPI_strlen (pString);
        goto ExitSuccess;
      }
      EApiStatusCode= EAPI_INVALID_STRLEN;
      goto ExitSuccess;
    }
  }
  if(pString!=NULL){
    EApiSprintf(pString, StrBufLen, 
      TEXT("UNKNOWN ERROR(0x%08")TEXT(PRIX32)TEXT(")"), 
      StatusCode
      );
    EApiStatusCode=EAPI_strlen (pString);
    goto ExitSuccess;
  }
  EApiStatusCode=EAPI_INVALID_STRLEN;
ErrorExit:
ExitSuccess:
  return EApiStatusCode;
}
EApiStatusCode_t
EApiAHCreateErrorStringAlloc(
  __IN uint32_t         StatusCode  ,
  __OUT TCHAR * *const  pString 
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
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
      EApiStatusCode=EAPI_STATUS_SUCCESS;
      goto SuccessExit;
    }
  }
  *pString=malloc(UNKNOWN_ERR_LEN*sizeof(TCHAR));
  if(*pString!=NULL)
    EApiSprintf(*pString, 
      UNKNOWN_ERR_LEN, 
      TEXT("UNKNOWN ERROR(0x%08")TEXT(PRIX32)TEXT(")"), 
      StatusCode
      );
ErrorExit:
SuccessExit:
  return EApiStatusCode;
}

size_t 
EApiAHGetString(
    __IN  uint32_t        StringID  , /* EApi String ID */
    __OUT TCHAR *         pString   , /* Pointer To String pBuffer */
    __IN  size_t          StrBufLen   /* String pBuffer Length */
    )
{
  size_t EApiStatusCode=EAPI_INVALID_STRLEN;
  uint32_t StringLenLcl=(uint32_t)StrBufLen;
  size_t StringBufferLenBck=StrBufLen;
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHGetString, EAPI_INVALID_STRLEN, pString);
  EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHGetString, EAPI_INVALID_STRLEN, StrBufLen);

  EApiStatusCode=EApiBoardGetString(StringID, pString, &StringLenLcl);
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode))
      StringLenLcl=(uint32_t)EApiAHCreateErrorString(EApiStatusCode, pString, StringBufferLenBck);
#if (STRICT_VALIDATION>0)
  EAPI_APP_RETURN_ERROR_IF(
      EApiAHGetStringAlloc, 
      (StringLenLcl>StringBufferLenBck), 
      EAPI_INVALID_STRLEN, 
      "Interface Returning Different String Lengths"
      );
  if(EApiStrLen(pString, StringBufferLenBck)==StringBufferLenBck)
  {
     EAPI_FORMATED_MES('E', 
         EApiAHGetString, 
         EAPI_INVALID_STRLEN, 
         "Returned String Missing Terminating \\0 Character." 
         );
    pString[StringBufferLenBck-1]=TEXT('\0');
  }
#endif
  EApiStatusCode=StringLenLcl;
ErrorExit:
/* SuccessExit: */
  return EApiStatusCode;
}

EApiStatusCode_t 
EApiAHGetStringAlloc(
    __IN  uint32_t        StringID, /* EApi String ID */
    __OUT TCHAR * *const  pString   /* Pointer to where string 
                                     * pointer should be stored 
                                     */
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  uint32_t StringLen=0;
  uint32_t StringBufferLenBck=0;
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHGetString, EAPI_STATUS_INVALID_PARAMETER, pString);
  *pString=NULL;
  EApiStatusCode=EApiBoardGetString(StringID, *pString, &StringLen);
  switch(EApiStatusCode){
    case EAPI_STATUS_MORE_DATA:
      StringBufferLenBck=StringLen;
      *pString=malloc(StringLen*sizeof(TCHAR));

      EAPI_APP_RETURN_ERROR_IF(
          EApiAHGetStringAlloc, 
          (*pString==NULL), 
          EAPI_STATUS_ALLOC_ERROR, 
          "Memory Allocation Error"
          );

      EApiStatusCode=EApiBoardGetString(StringID, *pString, &StringLen);
#if (STRICT_VALIDATION>0)
      EAPI_APP_RETURN_ERROR_IF(
          EApiAHGetStringAlloc, 
          (StringLen>StringBufferLenBck), 
          EAPI_STATUS_ERROR, 
          "Interface Returning Different String Lengths"
          );
      if(EApiStrLen(*pString, StringBufferLenBck)==StringBufferLenBck)
      {
        EAPI_FORMATED_MES('E', 
            EApiAHGetStringAlloc, 
            EAPI_STATUS_ERROR, 
            "Returned String Missing Terminating \\0 Character." 
            );
        (*pString)[StringBufferLenBck-1]=TEXT('\0');
      }
#endif
      break;
    default:
      EApiAHCreateErrorStringAlloc(EApiStatusCode, pString);
      break;
  }
ErrorExit:
/* SuccessExit: */
  return EApiStatusCode;
}
int
EApiAHCreateDecimalString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
   int EApiStatusCode=0;
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateDecimalString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateDecimalString, -1, StrBufLen);
    EApiStatusCode=EApiSprintf(pString, StrBufLen, TEXT("%lu"), Value);
ErrorExit:
/* SuccessExit: */
    return EApiStatusCode;
}
int
EApiAHCreateHexString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
   int EApiStatusCode=0;
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateDecimalString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateDecimalString, -1, StrBufLen);
    EApiStatusCode=EApiSprintf(pString, StrBufLen, TEXT("0x%08")TEXT(PRIX32), Value);
ErrorExit:
/* SuccessExit: */
    return EApiStatusCode;
}
int
EApiAHCreateVoltageString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
   int EApiStatusCode=0;
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateDecimalString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateDecimalString, -1, StrBufLen);
    Value/=10;
    EApiStatusCode=EApiSprintf(pString, StrBufLen, TEXT("%lu.%02lu Volts"), Value/100, Value%100);

ErrorExit:
/* SuccessExit: */
    return EApiStatusCode;
}
int
EApiAHCreateRotationsString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    int EApiStatusCode;
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateDecimalString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateDecimalString, -1, StrBufLen);
    EApiStatusCode=EApiSprintf(pString, StrBufLen, TEXT("%lu RPM"), Value);

ErrorExit:
/* SuccessExit: */
    return EApiStatusCode;
}
int
EApiAHCreateTempString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    int EApiStatusCode;
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateDecimalString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateDecimalString, -1, StrBufLen);
    Value-=EAPI_KELVINS_OFFSET;
    EApiStatusCode=EApiSprintf(pString, StrBufLen, TEXT("% li.%lu Celcius"), ((int32_t)Value)/10, Value%10);

ErrorExit:
/* SuccessExit: */
    return EApiStatusCode;
}
int
EApiAHCreateTimeString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    int EApiStatusCode;
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
    EApiStatusCode=StrLength;

ErrorExit:
/* SuccessExit: */
    return EApiStatusCode;
}


int
EApiAHCreateSVersionString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
    int EApiStatusCode;
    /* 255.255 */
    EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateSVersionString, -1, pString);
    EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateSVersionString, -1, StrBufLen);
    EApiStatusCode=EApiSprintf(pString, StrBufLen, TEXT("%u.%u"), EAPI_VER_GET_VER(Value), EAPI_VER_GET_REV(Value) );

ErrorExit:
/* SuccessExit: */
    return EApiStatusCode;
}
int 
EApiAHCreateVersionString(
    __IN  uint32_t        Value     , /* Input Value to be interpreted */ 
    __OUT TCHAR * const   pString   , /* Pointer To String pBuffer */
    __IN  const uint32_t  StrBufLen   /* String pBuffer Length */
    )
{
  int EApiStatusCode;
  /* 255.255.65535 */
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreateVersionString, -1, pString);
  EAPI_APP_ASSERT_PARAMATER_ZERO(EApiAHCreateVersionString, -1, StrBufLen);
  EApiStatusCode=EApiSprintf(pString, StrBufLen, TEXT("%u.%u.%u"), EAPI_VER_GET_VER(Value), EAPI_VER_GET_REV(Value), EAPI_VER_GET_BUILD(Value) );

ErrorExit:
/* SuccessExit: */
    return EApiStatusCode;
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
  int EApiStatusCode;
  int cnt;
  unsigned short PNPID=(unsigned short)EAPI_BYTE_SWAP_W(Value);
  EAPI_APP_ASSERT_PARAMATER_NULL(EApiAHCreatePNPIDString, -1, pString);
  if(StrBufLen<4){
    EAPI_APP_RETURN_ERROR(EApiAHCreatePNPIDString, -1, "pBuffer Too Short");
  }
  if(PNPID&(1<<15)){
    EApiStatusCode = -1;
    goto ErrorExit;
  }
  for(cnt=0; cnt < 3; cnt++){
    pString[2 - cnt]=CompressedAsciiLookup[(PNPID>>(cnt*5))&0x1F];
  }
  pString[cnt]=0;
  EApiStatusCode=3;

ErrorExit:
/* SuccessExit: */
    return EApiStatusCode;
}

#ifdef UNICODE
EApiStatusCode_t
EApiAHBoardGetStringW(
    __IN      EApiId_t  Id      , /* Name Id */
    __OUT     wchar_t  *pBuffer , /* Destination pBuffer */
    __INOUT   uint32_t *pBufLen   /* pBuffer Length */
    )
{
  char *pBufferPtr=NULL;
  EApiStatusCode_t EApiStatusCode;
  if(pBuffer!=NULL && pBufLen!=NULL && *pBufLen)
  {
    pBufferPtr=(char *)malloc(*pBufLen*sizeof(char));
    EAPI_APP_RETURN_ERROR_IF(
      EApiAHBoardGetStringW, 
      pBufferPtr==NULL,
      EAPI_STATUS_ALLOC_ERROR, 
      "Allocating ASCII Buffer"
      );
  }

  EApiStatusCode=EApiBoardGetStringA(Id, pBufferPtr, pBufLen);

  if(pBufferPtr!=NULL)
  {
    mbstowcs(pBuffer, pBufferPtr, *pBufLen);
    free(pBufferPtr);
  }


ErrorExit:
/* SuccessExit: */
    return EApiStatusCode;
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
EApiStrLenA  ( 
    __IN const char  *pBuffer    ,
    __IN size_t       BufferLen
    )
{
  const char *pszCurChar;
  if(pBuffer   ==NULL) return 0;
  if(BufferLen==0   ) return 0;

  for(pszCurChar=pBuffer; BufferLen--; pszCurChar++)
    if(*pszCurChar=='\0')
      break;
  return pszCurChar - pBuffer;
}
char * 
EApiStrCpyA(
    __OUT char *const      StringDest   ,
    __IN size_t             StrBufLen    , 
    __IN const char *const StringSource
    )
{
  if(StringDest  ==NULL) return StringDest;
  if(StringSource==NULL) return StringDest;
  if(StrBufLen==0   ) return StringDest;

  EAPI_strncpyA(StringDest, StringSource, StrBufLen);
  StringDest[StrBufLen-1]=TEXT('\0');
  return StringDest;
}
int 
__cdecl 
EApiSprintfA ( 
    __IN char *const       pBuffer   ,
    __IN const size_t       BufferLen ,
    __IN const char *const fmt       ,
    ...
    )
{
  int ReturnValue;
  va_list arg;
  if(pBuffer  ==NULL) return -1;
  if(fmt      ==NULL) return -1;
  if(BufferLen==0   ) return -1;

  va_start(arg, fmt);
  ReturnValue=EAPI_vsnprintfA(pBuffer, BufferLen, fmt, arg);
  pBuffer[BufferLen-1]='\0';
  va_end(arg);
  return ReturnValue;
}
size_t 
EApiStrLen  ( 
    __IN const TCHAR *pBuffer    ,
    __IN size_t       BufferLen
    )
{
  const TCHAR *pszCurChar;
  if(pBuffer   ==NULL) return 0;
  if(BufferLen==0   ) return 0;

  for(pszCurChar=pBuffer; BufferLen--; pszCurChar++)
    if(*pszCurChar=='\0')
      break;
  return pszCurChar - pBuffer;
}

TCHAR * 
EApiStrCpy(
    __OUT TCHAR *const      StringDest   ,
    __IN size_t             StrBufLen    , 
    __IN const TCHAR *const StringSource
    )
{
  if(StringDest  ==NULL) return StringDest;
  if(StringSource==NULL) return StringDest;
  if(StrBufLen==0   ) return StringDest;

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
  if(pBuffer  ==NULL) return -1;
  if(fmt      ==NULL) return -1;
  if(BufferLen==0   ) return -1;

  va_start(arg, fmt);
  ReturnValue=EAPI_vsnprintf(pBuffer, BufferLen, fmt, arg);
  pBuffer[BufferLen-1]=TEXT('\0');
  va_end(arg);
  return ReturnValue;
}


