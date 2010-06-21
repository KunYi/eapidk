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
      PrintCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pCfgBDesc
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      PrintCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      stCfgBDescElements
    );
  while(stCfgBDescElements--){
    CfgElementDesc_t *pCurElement=pCfgBDesc->Elements.pIndx;
    i=pCfgBDesc->Elements.stUsedCnt;
    fprintf(OutStream, "%s[%s]\n", (pCfgBDesc->cuiRequired?"":"#"), pCfgBDesc->pszBlockName);
    while(i--){
      fprintf(OutStream, "###################################################\n");
      fprintf(OutStream, "##  %s\n", pCurElement->pcszElementName);
      fprintf(OutStream, "###################################################\n");
      fprintf(OutStream, 
          "##\t\t %s\n", 
          (pCurElement->cuiRequired?"Required Element":"Optional Element")
        );
      fprintf(OutStream, 
          "##\t\t Allowed Maximum of %lu times in block\n", 
          (unsigned long)pCurElement->Instances.stTotalCnt
        );
      DO(pCurElement->pHandlers->Help(
            pCurElement, 
            OutStream, 
            "##\t\t"
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
EAPI_APP_ASSERT_EXIT
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
      CleanBlock,
      EAPI_STATUS_INVALID_PARAMETER,
      pCurElement
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      CleanBlock,
      EAPI_STATUS_INVALID_PARAMETER,
      stElementCount
    );
    while(stElementCount--){
      while(pCurElement->Instances.stUsedCnt--){
        DO(pCurElement->pHandlers->Clean(
              pCurElement,
              EAPI_CREATE_PTR(
                  pCurElement->Instances.pIndx, 
                  pCurElement->Instances.stElementSize*(pCurElement->Instances.stUsedCnt), 
                  void*
                )
            ));
      }
      pCurElement->Instances.stUsedCnt=0;
      pCurElement++;
    }
EAPI_APP_ASSERT_EXIT
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
      CleanStruct,
      EAPI_STATUS_INVALID_PARAMETER,
      pCfgBDesc
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      CleanStruct,
      EAPI_STATUS_INVALID_PARAMETER,
      stCfgBDescElements
    );
  while(stCfgBDescElements --){
    pCfgBDesc->uiFound=0;
    DO(CleanBlock(pCfgBDesc->Elements.pIndx, pCfgBDesc->Elements.stUsedCnt));
    pCfgBDesc++;
  }
EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}
EApiStatusCode_t
GetElementDesc(
    struct CfgBlockDesc_s *pDesc,
    CfgElementDesc_t     **ppElementsDesc,
    const char            *cszElementName
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_NOT_FOUND;
  CfgElementDesc_t     *pElementsDesc;
  int   i;

  EAPI_APP_ASSERT_PARAMATER_NULL(
        GetElementDesc,
        EAPI_STATUS_INVALID_PARAMETER,
        pDesc
      );
  EAPI_APP_ASSERT_PARAMATER_NULL(
        GetElementDesc,
        EAPI_STATUS_INVALID_PARAMETER,
        ppElementsDesc
      );
  EAPI_APP_ASSERT_PARAMATER_NULL(
        GetElementDesc,
        EAPI_STATUS_INVALID_PARAMETER,
        cszElementName
      );
  *ppElementsDesc=NULL;
  for(
      i=(int)pDesc->Elements.stUsedCnt,
      pElementsDesc=pDesc->Elements.pIndx;
      i--;
      pElementsDesc++
      )
  {
    if(!strcmp(cszElementName, pElementsDesc->pcszElementName)){
      *ppElementsDesc=pElementsDesc;
      EApiStatusCode=EAPI_STATUS_SUCCESS;
      break;
    }
  }

EAPI_APP_ASSERT_EXIT
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
  char LineBuffer[MAX_LINE_LEN];
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
#if TEST_EEPCFG
		siFormattedMessage_M2('L', __FILE__, "ParseCfgFile", __LINE__, "Raw",
        "(%04lu)%s\n", ulLineNum, LineBuffer);
#endif
    /*
     * Remove Comments And New Lines etc..
     */
    szName=strpbrk(LineBuffer, ";#\n\r");
    if(szName!=NULL)
      *szName='\0';
#if TEST_EEPCFG
		siFormattedMessage_M2('L', __FILE__, "ParseCfgFile", __LINE__, "Raw",
        "(%04lu)%s\n", ulLineNum, LineBuffer);
#endif
    if(LineBuffer[0]=='['){
      size_t stTokenLen;
      /*
       * Check Last Block Required
       */
      if(pCurBlockDesc!=NULL){
        for(
            i=pCurBlockDesc->Elements.stUsedCnt,
            pCurElement=pCurBlockDesc->Elements.pIndx; 
            i--; 
            pCurElement++
          )
        {
          if(pCurElement->cuiRequired>pCurElement->Instances.stUsedCnt){
						EApiStatusCode=EAPI_STATUS_ERROR;
						siFormattedMessage_SC('W', __FILE__, "ParseCfgFile", __LINE__, EApiStatusCode,
                "Missing Required Element '%s' in Block (%lu)'%s'", 
                pCurElement->pcszElementName, 
                ulBlockStartLine,
                pCurBlockDesc->pszBlockName
              );
							goto ErrorExit;
          }
        }
      }

#if TEST_EEPCFG
		siFormattedMessage_M2('L', __FILE__, "ParseCfgFile", __LINE__, "Block",
        "(%04lu)%s\n", ulLineNum, LineBuffer);
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
      szName=skipWhiteSpaces(LineBuffer);
      if(!strlen(szName)){
        /*Skip Empty Blank Lines */
        continue;
      }
      if(pCurBlockDesc==NULL){
					siFormattedMessage_M2('W', __FILE__, "ParseCfgFile", __LINE__, "Invalid Block",
            "(%04lu) : %s\n", 
            ulLineNum, 
            LineBuffer
							);
        continue;
      }
      szValue=strchr(szName, '=');
      if(szValue==NULL){
					siFormattedMessage_M2('W', __FILE__, "ParseCfgFile", __LINE__, "Invalid Line",
            "(%04lu) : %s\n", 
            ulLineNum, 
            LineBuffer
							);
        continue;
      }
      *szValue++='\0';
      stripWhiteSpaces(szName);
      szValue=skipWhiteSpaces(szValue);
#if TEST_EEPCFG
		  siFormattedMessage_M2('L', __FILE__, "ParseCfgFile", __LINE__, pCurBlockDesc->pszBlockName,
          "(%04lu)%-20s = %s", ulLineNum, szName, szValue);
#endif
      EApiStatusCode=GetElementDesc(pCurBlockDesc, &pCurElement, szName);

      switch(EApiStatusCode){
        case EAPI_STATUS_SUCCESS:
          EAPI_APP_RETURN_ERROR_IF_S(
              ParseCfgFile,
              (pCurElement->Instances.stUsedCnt+1>pCurElement->Instances.stTotalCnt),
              EAPI_STATUS_ERROR
            );
          EApiStatusCode=pCurElement->pHandlers->Handler(
                pCurElement, 
                EAPI_CREATE_PTR(
                    pCurElement->Instances.pIndx,
                    pCurElement->Instances.stElementSize*pCurElement->Instances.stUsedCnt, 
                    void*
                  ),
                szValue
              );
          if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
            siFormattedMessage_SC(
                'E', __FILE__, "ParseCfgFile", __LINE__, EApiStatusCode,
                "ERROR Parsing Line %li, %s\n", ulLineNum, szValue
            );
            goto ErrorExit;
          }
          pCurElement->Instances.stUsedCnt++;
          FoundElement++;
          break;
        case EAPI_STATUS_NOT_FOUND:
          siFormattedMessage_SC(
                'E', __FILE__, "ParseCfgFile", __LINE__, EApiStatusCode,
                "Unknown Block Element on line %li, '%s'\n", ulLineNum, szName
          );
          break;
        default:
          goto ErrorExit;
          break;
      }
    }
  }
  pCurBlockDesc=pCfgBDesc;
  for(i=stCfgBDescElements;i;i--){
    if(pCurBlockDesc->cuiRequired>pCurBlockDesc->uiFound){
      EApiStatusCode=EAPI_STATUS_ERROR;
		  siFormattedMessage_SC('W', __FILE__, "ParseCfgFile", __LINE__, EApiStatusCode,
          "Missing Required Block '%s'\n", 
          pCurBlockDesc->pszBlockName
        );
	    goto ErrorExit;
    }
    pCurBlockDesc++;
  }

  fclose(pCfgFile);
  

ErrorExit:
EAPI_APP_ASSERT_EXIT 

  return EApiStatusCode;
}



