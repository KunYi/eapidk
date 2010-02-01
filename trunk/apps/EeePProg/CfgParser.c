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
 *I  File Name            : CfgParser.c
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

/*  */





EApiStatusCode_t
PrintCfgFile(
    __IN    CfgBlockDesc_t *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements ,
    __OUT   FILE *         OutStream
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  size_t i;
  unsigned int i2;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pCfgBDesc
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      stCfgBDescElements
    );
  while(stCfgBDescElements--){
    CfgElementDesc_t *pCurElement=pCfgBDesc->pElementsDesc;
    i=pCfgBDesc->stElementCount;
    fprintf(OutStream, "%s[%s]\n", (pCfgBDesc->cuiRequired?"":"#"), pCfgBDesc->pszBlockName);
    while(i--){
      fprintf(OutStream, "##################################################\n");
      fprintf(OutStream, "#  %s\n", pCurElement->pcszElementName);
      fprintf(OutStream, "##################################################\n");
      fprintf(OutStream, 
          "#\t\t %s\n", 
          (pCurElement->cuiRequired?"Required Element":"Optional Element")
        );
      fprintf(OutStream, 
          "#\t\t Allowed Maximum of %lu times in block\n", 
          (unsigned long)pCurElement->cstElementMax
        );
      DO(pCurElement->pHandlers->Help(
            pCurElement, 
            OutStream, 
            "#\t\t"
          ));
      i2=0;
      do{
        fprintf(OutStream, "%s  %s=", (pCfgBDesc->cuiRequired&pCurElement->cuiRequired?"":"#"), pCurElement->pcszElementName);
        DO(pCurElement->pHandlers->Default(
              pCurElement, 
              OutStream  ,
              i2
            ));
        fprintf(OutStream, "\n");
      }while(++i2<pCurElement->cuiRequired);
      fprintf(OutStream, "\n");
      pCurElement++;
    }
    pCfgBDesc++;
  }
ErrorExit:
  return EApiStatusCode;
}

EApiStatusCode_t
CleanBlock(
    __IN    CfgElementDesc_t *pCurElement         ,
    __IN    size_t           stElementCount
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      pCurElement,
      EAPI_STATUS_INVALID_PARAMETER,
      pCurElement
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      stElementCount
    );
    while(stElementCount--){
      while(pCurElement->stElementCount--){
        DO(pCurElement->pHandlers->Clean(
              EAPI_CREATE_PTR(
                  pCurElement->Elements.pv, 
                  pCurElement->cstElementSize*(pCurElement->stElementCount), 
                  void*
                ),
              pCurElement->cstElementSize
            ));
      }
      pCurElement->stElementCount=0;
      pCurElement++;
    }
ErrorExit:
  return EApiStatusCode;
}

EApiStatusCode_t
CleanStruct(
    __IN    CfgBlockDesc_t *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pCfgBDesc
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      stCfgBDescElements
    );
  while(stCfgBDescElements --){
    pCfgBDesc->uiFound=0;
    DO(CleanBlock(pCfgBDesc->pElementsDesc, pCfgBDesc->stElementCount));
    pCfgBDesc++;
  }
ErrorExit:
  return EApiStatusCode;
}
#define MAX_LINE_LEN 2048
EApiStatusCode_t
ParseCfgFile(
    __IN    const char *pcszCfgFileName       ,
    __INOUT CfgBlockDesc_t *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements
    )
{
  FILE *pCfgFile;
  char LineBuffer[1024];
  TCHAR ErrorBuffer[1324];
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  char *szName;
  char *szValue;
  size_t i;
  unsigned long ulLineNum, ulBlockStartLine;
  CfgBlockDesc_t *pCurBlockDesc=NULL;
  CfgElementDesc_t *pCurElement;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pcszCfgFileName
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pCfgBDesc
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      stCfgBDescElements
    );
  pCfgFile=fopen(pcszCfgFileName, "r");
  
  EAPI_APP_RETURN_ERROR_IF_S(
      ParseCfgFile,
      (pCfgFile==NULL),
      EAPI_STATUS_INVALID_PARAMETER
    );
  ulLineNum=0;
  ulBlockStartLine=0;
  while(!feof(pCfgFile)){
    szName=fgets(LineBuffer, ARRAY_SIZE(LineBuffer), pCfgFile);
    ulLineNum++;
    /*
     * Remove Comments And New Lines etc..
     */
    szName=strpbrk(LineBuffer, "#\n\r");
    if(szName!=NULL)
      *szName='\0';
    if(LineBuffer[0]=='['){
      size_t stTokenLen;
      /*
       * Check Last Block Required
       */
      if(pCurBlockDesc!=NULL){
        for(
            i=pCurBlockDesc->stElementCount,
            pCurElement=pCurBlockDesc->pElementsDesc; 
            i; 
            i--, 
            pCurElement++
          )
        {
          if(pCurElement->cuiRequired>pCurElement->stElementCount){
            EApiSprintf(
                ErrorBuffer, 
                ARRAY_SIZE(ErrorBuffer), 
                TEXT("Missing Required Element '%hs' in Block (%lu)'%hs'"), 
                pCurElement->pcszElementName, 
                ulBlockStartLine,
                pCurBlockDesc->pszBlockName
              );
            EAPI_APP_RETURN_ERROR(
                ParseCfgFile,
                EAPI_STATUS_ERROR,
                ErrorBuffer
              );
          }
        }
      }

#if TEST_EEPCFG
/*       sprintf(ErrorBuffer, "%-15s : %s", "Block", LineBuffer); */
/*       EAPI_FORMATED_MES( 'L', ParseCfgFile, 0, ErrorBuffer); */
#endif
      pCurBlockDesc=NULL;
      ulBlockStartLine=ulLineNum;
      for(i=0;i<stCfgBDescElements;i++){
        stTokenLen=strlen(pCfgBDesc[i].pszBlockName);
        if((LineBuffer[stTokenLen+1]==']')&&!memcmp(LineBuffer+1, pCfgBDesc[i].pszBlockName, stTokenLen)){
          pCfgBDesc[i].uiFound=BLOCK_FOUND;
          pCurBlockDesc=pCfgBDesc+i;
          break;
        }
      }
    }else{
      unsigned int FoundElement=0;
      szName=LineBuffer;
      skipWhiteSpaces(&szName);
      if(!strlen(szName)){
        /*Skip Empty Blank Lines */
        continue;
      }
      if(pCurBlockDesc==NULL){
        EApiSprintf(
            ErrorBuffer, 
            ARRAY_SIZE(ErrorBuffer),
            TEXT("(%04lu)%-15s : %hs"), 
            ulLineNum, 
            TEXT("Invalid Block"), 
            LineBuffer
          );
        EAPI_FORMATED_MES( 'W', ParseCfgFile, 0, ErrorBuffer);
        continue;
      }
      szValue=strchr(szName, '=');
      if(szValue==NULL){
        EApiSprintf(
            ErrorBuffer, 
            ARRAY_SIZE(ErrorBuffer), 
            TEXT("(%04lu)%-15s : %hs"), 
            ulLineNum, 
            TEXT("Invalid line"), 
            LineBuffer
          );
        EAPI_FORMATED_MES( 'W', ParseCfgFile, 0, ErrorBuffer);
        continue;
      }
      *szValue++='\0';
      stripWhiteSpaces(szName);
      skipWhiteSpaces(&szValue);
#if TEST_EEPCFG
/*       sprintf(ErrorBuffer, "%-15s : %-20s = %s", pCurBlockDesc->pszBlockName, szName, szValue); */
/*       EAPI_FORMATED_MES( 'L', ParseCfgFile, 0, ErrorBuffer); */
#endif
      for(i=pCurBlockDesc->stElementCount, pCurElement=pCurBlockDesc->pElementsDesc; i; i--, pCurElement++){
        if(!strcmp(szName, pCurElement->pcszElementName)){
          EAPI_APP_RETURN_ERROR_IF_S(
              ParseCfgFile,
              (pCurElement->stElementCount+1>pCurElement->cstElementMax),
              EAPI_STATUS_ERROR
            );
          DO(pCurElement->pHandlers->Handler(
                pCurElement, 
                EAPI_CREATE_PTR(
                    pCurElement->Elements.pv,
                    pCurElement->cstElementSize*pCurElement->stElementCount, 
                    void*
                  ),
                szValue
              ));
          pCurElement->stElementCount++;
          FoundElement++;
          break;
        }
      }
      EAPI_APP_RETURN_ERROR_IF_S(
          ParseCfgFile,
          !FoundElement,
          EAPI_STATUS_ERROR
        );
    }
  }
  pCurBlockDesc=pCfgBDesc;
  for(i=stCfgBDescElements;i;i--){
    if(pCurBlockDesc->cuiRequired>pCurBlockDesc->uiFound){
        EApiSprintf(
          ErrorBuffer, 
          ARRAY_SIZE(ErrorBuffer), 
          TEXT("Missing Required Block '%hs'\n"), 
          pCurBlockDesc->pszBlockName
        );
      EAPI_APP_RETURN_ERROR(
          ParseCfgFile,
          EAPI_STATUS_ERROR,
          ErrorBuffer
        );
    }
    pCurBlockDesc++;
  }

  fclose(pCfgFile);
  

ErrorExit:
  return EApiStatusCode;
}

