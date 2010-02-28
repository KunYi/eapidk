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
 *I  File Name            : TokenFunc.c
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


EApiStatusCode_t
GetTokenFlags(
    __OUT   char               *szStrBuf   ,
    __INOUT signed int         *psiStrBufLen,
    __IN  const char           *cszFirstLine,
    __IN  const char           *cszOtherLines,
    __IN  const char           *cszName      ,
    __IN  const TokenListDesc_t*pcTokenDesc,
    __IN  size_t                stValue
    )
{
  const TokenDesc_t *pcTokenList=pcTokenDesc->pTokenList;
  size_t             stTokenList=pcTokenDesc->uiTokenCount;
  unsigned int siStrLen=0;
  for(;stTokenList --;pcTokenList++){
    if(stValue&pcTokenList->ulTokenValue){
      if(siStrLen){
        siStrLen+=EApiSprintfA(
            szStrBuf+siStrLen     ,
            *psiStrBufLen-siStrLen ,
            cszOtherLines, 
            pcTokenList->pszTokenList 
        );
      }else{
        siStrLen+=EApiSprintfA(
            szStrBuf+siStrLen     ,
            *psiStrBufLen-siStrLen ,
            cszFirstLine, 
            cszName, 
            pcTokenList->pszTokenList 
        );
      }
    }
  }
  if(!siStrLen)
        siStrLen+=EApiSprintfA(
            szStrBuf+siStrLen     ,
            *psiStrBufLen-siStrLen ,
            cszFirstLine, 
            cszName, 
            "" 
        );
  *psiStrBufLen=siStrLen;
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
GetValueToken(
    __OUT char                 *pszBuffer,
    __IN  size_t                stBufLen  ,
    __IN  const TokenListDesc_t*pcTokenDesc,
    __IN  size_t                stValue
    )
{
  const TokenDesc_t *pcTokenList=pcTokenDesc->pTokenList;
  size_t             stTokenList=pcTokenDesc->uiTokenCount;
  for(;stTokenList --;pcTokenList++){
    if(stValue==pcTokenList->ulTokenValue){
      EApiSprintfA(pszBuffer, stBufLen, "%s", pcTokenList->pszTokenList);
      return EAPI_STATUS_SUCCESS;
    }
  }
  EApiSprintfA(pszBuffer, stBufLen, "UNKNOWN VALUE(0x%08lX)", (unsigned long)stValue);
  return EAPI_STATUS_ERROR;
}

EApiStatusCode_t
GetTokenValue(
    __IN  const TokenListDesc_t*pcTokenDesc,
    __IN  const char   *szValue  ,
    __OUT unsigned long*pulValue
  )
{ 
  const TokenDesc_t *pcTokenList=pcTokenDesc->pTokenList;
  size_t             stTokenList=pcTokenDesc->uiTokenCount;
  *pulValue=0;
  for(;stTokenList --;pcTokenList++){
    if(!strcmp(pcTokenList->pszTokenList, szValue)){
      *pulValue=pcTokenList->ulTokenValue;
      return EAPI_STATUS_SUCCESS;
    }
  }
  return EAPI_STATUS_ERROR;

}

EApiStatusCode_t
GetTokenValueStrip(
    __IN  const TokenListDesc_t*pcTokenDesc,
    __IN  char   *szValue  ,
    __OUT unsigned long*pulValue
    )
{
  szValue=skipWhiteSpaces(szValue);
  stripWhiteSpaces(szValue);
  return GetTokenValue(pcTokenDesc, szValue, pulValue);
}
#if TEST_TOKEN_FUNC

EApiStatusCode_t
main(void)
{
/*   EApiStatusCode_t EApiStatusCode; */

  exit(EAPI_STATUS_SUCCESS);
}
#endif

