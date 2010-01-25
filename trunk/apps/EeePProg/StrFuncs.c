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
 *I  File Name            : StrFuncs.c
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

void 
skipWhiteSpaces(
        const char **const pcszStr
        )
{
  const char * pcszStart;
  if(pcszStr==NULL) return ;
  if(*pcszStr==NULL) return ;
  pcszStart=*pcszStr;
  while((!iseol(*pcszStart))&&iswhitespace(*pcszStart))
    pcszStart++;
  *pcszStr=pcszStart;
}

void 
stripWhiteSpaces(
        char *const pszStr
        )
{
  char * pszEnd;
  if(pszStr==NULL) return ;
  pszEnd=pszStr+strlen(pszStr) - 1;
  while(iswhitespace(*pszEnd))
    pszEnd--;
  *(pszEnd+1)='\0';
}

/* char *_strdup( */
/*     __IN const char *pcszStr */
/*     ) */
/* { */
/*   char *pszDup; */
/*   if(pcszStr==NULL) return NULL; */
/*   pszDup=malloc(strlen(pcszStr)+1); */
/*   if(pszDup==NULL) return NULL; */
/*   strcpy(pszDup, pcszStr); */
/*   return pszDup; */
/* } */


unsigned long 
ulConvertStr2Num(
    const char *  pcszStr, 
    char **       pcszEnd
    )
  {
    unsigned long ulReturnVal;
    char *pcszEndH;
    char *pcszEndB;
    char *pcszDummy;
    if(pcszStr==NULL) return 0;
    if(pcszEnd==NULL) pcszEnd=&pcszDummy ;
    skipWhiteSpaces(&pcszStr);
    strtoul(pcszStr, &pcszEndH, 16);
    strtoul(pcszStr, &pcszEndB,  2);
    /* 
     *  0xff
     */
    if( !memcmp( "0x", pcszStr , 2) ){
        ulReturnVal = strtoul(pcszStr+2, pcszEnd, 16);
    /* 
     *  0ffh
     */
    }else if(isdecimal(pcszStr[0]) && (toupper(pcszEndH[0])=='H') ){
        ulReturnVal = strtoul(pcszStr, pcszEnd, 16);
        (*pcszEnd)++;
    /* 
     *  011b
     */
    }else if(isbinary(pcszStr[0]) && (toupper(pcszEndB[0])=='B') ){
        ulReturnVal = strtoul(pcszStr, pcszEnd, 2);
        (*pcszEnd)++;
    /* 
     *  099
     */
    }else {
        ulReturnVal = strtoul(pcszStr, pcszEnd, 10);
    }
    skipWhiteSpaces(pcszEnd);
    return ulReturnVal;
  }




#ifdef _MSC_VER 
#       if ( _MSC_VER < MSVC_2005 )

int cdecl 
sprintf_s (
  __IN    char *const             Buffer        , 
  __IN    const size_t            BufferLen     , 
  __IN    const char *const       fmt           , 
  ...
  )
{
  int ReturnValue;
  va_list arg;
  va_start(arg, fmt);
  ReturnValue=_vsnprintf(Buffer, BufferLen, fmt, arg);
  Buffer[BufferLen-1]='\0';
  va_end(arg);
  return ReturnValue;
}
int cdecl 
fopen_s (
  __OUT   FILE **                 instream      , 
  __IN    const char *const       fname         , 
  __IN    const char *const       ReadType
  )
{
  *instream=fopen(fname, ReadType);
  return (*instream==NULL?1:0);
}
char * 
strcpy_s(
  __OUT   char *const             StringDest    , 
  __IN    size_t                  StringBufLen  , 
  __IN    const char *const       StringSource
  )
{
  strncpy(StringDest, StringSource, StringBufLen);
  StringDest[StringBufLen-1]=TEXT('\0');
  return StringDest;
}

#       endif
#endif

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

