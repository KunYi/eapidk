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

char *
skipWhiteSpaces(
        const char *cszStr
        )
{
  if(cszStr==NULL) return (char*)cszStr;
  while((!iseol(*cszStr))&&iswhitespace(*cszStr))
    cszStr++;
  return (char*)cszStr;
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

char * 
szFindStr(
    __IN     const char             *szStr,
    __IN     const StrDesc_t        *pDesc,
    __OUTOPT const StrDescElement_t**pElement
    )
{
  char * szPos1=NULL, *szPos2;
  size_t stNumStrs=pDesc->cuiCount;
  const StrDescElement_t *pcCurElement=pDesc->pcDesc;
  while(stNumStrs --){
    szPos2=strstr(szStr, pcCurElement->pcszSymbol);
    if((szPos2!=NULL)&&((szPos1==NULL)||(szPos2<szPos1))){
      szPos1=szPos2;
      if(pElement) *pElement=pcCurElement;
    }

    pcCurElement++;
  }
  return szPos1;
}


char *
strrstr(
    __IN const char *cszString,
    __IN const char *cszSearchString
    )
{
  char *szLclPtr;
  unsigned uiMatchFound=0;
  if(cszString==NULL) return NULL;
  if(cszSearchString==NULL) return NULL;
  szLclPtr=strstr(cszString, cszSearchString);
  while(szLclPtr!=NULL){
    cszString=  szLclPtr+1;
    szLclPtr=strstr(cszString, cszSearchString);
    uiMatchFound++;
  };
  return uiMatchFound?(char *)cszString -1:NULL;
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
  
  exit(0);
}
#endif

