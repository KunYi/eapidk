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
          "#\t\t Allowed Maximum of %u times in block\n", 
          pCurElement->cstElementMax
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
                  pCurElement->cstElementSize*(pCurElement->stElementCount-1), 
                  void*
                ),
              pCurElement->cstElementSize
            ));
      }
      pCurElement->stElementCount=0;
      pCurElement++;
    }
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
  return EApiStatusCode;

}
EApiStatusCode_t
ParseCfgFile(
    __IN    const char *pcszCfgFileName       ,
    __INOUT CfgBlockDesc_t *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements
    )
{
  FILE *pCfgFile;
  char LineBuffer[1024];
  char ErrorBuffer[1324];
  EApiStatusCode_t EApiStatusCode;
  char *pszName;
  char *pszValue;
  size_t i;
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
  while(!feof(pCfgFile)){
    pszName=fgets(LineBuffer, ARRAY_SIZE(LineBuffer), pCfgFile);
    /*
     * Remove Comments And New Lines etc..
     */
    i=strcspn(LineBuffer, "#\n\r");
    LineBuffer[i]='\0';
    if(LineBuffer[0]=='['){
      size_t stTokenLen;
      /*
       * Check Last Block Required
       */
      if(pCurBlockDesc!=NULL){
        for(i=pCurBlockDesc->stElementCount, pCurElement=pCurBlockDesc->pElementsDesc; i; i--, pCurElement++){
          if(pCurElement->cuiRequired>pCurElement->stElementCount){
            sprintf(ErrorBuffer, 
                "ERROR: Missing Required Element '%s' in Block '%s'\n", 
                pCurElement->pcszElementName, 
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
/*       EAPI_FORMATED_MES( L, ParseCfgFile, 0, ErrorBuffer); */
#endif
      pCurBlockDesc=NULL;
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
      pszName=LineBuffer;
      skipWhiteSpaces(&pszName);
      if(!strlen(pszName)){
        /*Skip Empty Blank Lines */
        continue;
      }
      if(pCurBlockDesc==NULL){
        sprintf(ErrorBuffer, "%-15s : %s", "Invalid Block", LineBuffer);
        EAPI_FORMATED_MES( W, ParseCfgFile, 0, ErrorBuffer);
        continue;
      }
      pszValue=strchr(pszName, '=');
      if(pszValue==NULL){
        sprintf(ErrorBuffer, "%-15s : %s", "Invalid line", LineBuffer);
        EAPI_FORMATED_MES( W, ParseCfgFile, 0, ErrorBuffer);
        continue;
      }
      *pszValue++='\0';
      stripWhiteSpaces(pszName);
      skipWhiteSpaces(&pszValue);
#if TEST_EEPCFG
/*       sprintf(ErrorBuffer, "%-15s : %-20s = %s", pCurBlockDesc->pszBlockName, pszName, pszValue); */
/*       EAPI_FORMATED_MES( L, ParseCfgFile, 0, ErrorBuffer); */
#endif
      for(i=pCurBlockDesc->stElementCount, pCurElement=pCurBlockDesc->pElementsDesc; i; i--, pCurElement++){
        if(!strcmp(pszName, pCurElement->pcszElementName)){
          EAPI_APP_RETURN_ERROR_IF_S(
              ParseCfgFile,
              (pCurElement->stElementCount+1>pCurElement->cstElementMax),
              EAPI_STATUS_ERROR
            );
          DO(pCurElement->pHandlers->Handler(
                pCurElement, 
                EAPI_CREATE_PTR(pCurElement->Elements.pv, pCurElement->cstElementSize*pCurElement->stElementCount, void*),
                pszValue
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
      char ErrorBuffer[50];
      sprintf(ErrorBuffer, "ERROR: Missing Required Block '%s'\n", pCurBlockDesc->pszBlockName);
      EAPI_APP_RETURN_ERROR(
          ParseCfgFile,
          EAPI_STATUS_ERROR,
          ErrorBuffer
        );
    }
    pCurBlockDesc++;
  }

  fclose(pCfgFile);
  

  return EAPI_STATUS_SUCCESS;
}

