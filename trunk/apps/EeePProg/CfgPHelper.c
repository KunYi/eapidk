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
 *I  File Name            : CfgPHelper.c
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

Handlers_t  String_Element_funcs  ={ String_Element  , Dealloc_Element  , String_Help    , No_Default_Txt};
Handlers_t  Number_Element_funcs  ={ Number_Element  , GenClear_Element , Range_List_Help, Range_Default_Txt};
Handlers_t  Token_Element_funcs   ={ Token_Element   , GenClear_Element , Token_List_Help, Token_List_Default};
Handlers_t  SpecRev_Element_funcs ={ SpecRev_Element , GenClear_Element , SpecRev_Help   , No_Default_Txt};
Handlers_t  PNPID_Element_funcs   ={ PNPID_Element   , GenClear_Element , PNPID_Help     , No_Default_Txt};
Handlers_t  I2C_EEPROM_Addr_funcs ={ I2C_EEPROM_Addr , GenClear_Element , I2C_EEPROM_Help, No_Default_Txt};
Handlers_t  GUID_Element_funcs    ={ GUID_Element    , GenClear_Element , GUID_Help      , GUID_Default};

/*
 *
 *  Default Text Functions
 *
 *
 */
EApiStatusCode_t                                    
No_Default_Txt(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream ,
    __IN  unsigned int uiCount
  )
{ 
  pElementDesc=pElementDesc;
  stream=stream;
  uiCount=uiCount;
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t                                    
Token_List_Default(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream ,
    __IN  unsigned int uiCount
  )
{ 
  TokenDesc_t *pTokens;
  uiCount=uiCount;
  pTokens=((TokenListDesc_t*)pElementDesc->pExtraInfo)->pTokenList; 
  fprintf(stream, "%s", pTokens->pszTokenList);
  return EAPI_STATUS_SUCCESS;
}


EApiStatusCode_t                                    
Range_Default_Txt(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream ,
    __IN  unsigned int uiCount
  )
{ 
  NumberRangeDesc_t *pRange=pElementDesc->pExtraInfo;
  uiCount=uiCount;
  fprintf(
      stream, 
      "0x%02X", 
      pRange->pNumberRange->uiLowerLimit
    );
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t                                    
GUID_Default(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream ,
    __IN  unsigned int uiCount
  )
{ 
  uiCount=uiCount;
  pElementDesc=pElementDesc;
  fprintf(stream, "FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF");
  return EAPI_STATUS_SUCCESS;
}

/*
 *
 *  HELP Functions
 *
 *
 */
const char *DeletePreserve[]={
  "Deleted",
  "Preserved"
};
EApiStatusCode_t                                    
String_Help(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream,
    const char *Indent
  )
{ 
  StringDesc_t *pStringDesc=pElementDesc->pExtraInfo; 
  fprintf(stream, "%s %s\n", Indent, "Generic String");
  if(pStringDesc!=NULL){
    if(pStringDesc->uiMaxLength){
      fprintf(stream, "%s   Max Length %u\n", Indent, pStringDesc->uiMaxLength);
    }
    if(pStringDesc->uiMinLength){
      fprintf(stream, "%s   Min Length %u\n", Indent, pStringDesc->uiMinLength);
    }
    fprintf(stream, "%s   Trailing spaces %s\n", Indent, DeletePreserve[pStringDesc->uiPreserveTrailingSpaces]);
  }
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
Range_List_Help(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream,
    const char *Indent
  )
{ 
  NumberRange_t *pNumRange;
  size_t stRangeCnt;
  fprintf(stream, "%s %s\n", Indent, "Generic Number");
  if(pElementDesc->pExtraInfo==NULL) return EAPI_STATUS_SUCCESS;
  pNumRange=((NumberRangeDesc_t*)pElementDesc->pExtraInfo)->pNumberRange; 
  stRangeCnt=((NumberRangeDesc_t*)pElementDesc->pExtraInfo)->stRangeCount; 
  if(stRangeCnt>1)
    fprintf(stream, "%s %s\n", Indent, "Meeting one of the following conditions");
  else
    fprintf(stream, "%s %s\n", Indent, "Meeting the following condition");
  while(stRangeCnt--){
    switch(pNumRange->uiType){
      case RANGE_INCLUSIVE:
        if(pNumRange->uiLowerLimit==pNumRange->uiUpperLimit)
          fprintf(stream, 
              "%s \t Number == %8u(0x%04X)\n",
              Indent, 
              pNumRange->uiLowerLimit, 
              pNumRange->uiLowerLimit 
            );
        else
          fprintf(stream, 
              "%s \t %8u(0x%04X) <= Number <= %8u(0x%04X)\n", 
              Indent, 
              pNumRange->uiLowerLimit, 
              pNumRange->uiLowerLimit, 
              pNumRange->uiUpperLimit, 
              pNumRange->uiUpperLimit
            );
        break;
      case RANGE_EXCLUSIVE:
        fprintf(stream, 
              "%s \t Number < %8u(0x%04X) || %8u(0x%04X) < Number\n",
              Indent, 
              pNumRange->uiLowerLimit, 
              pNumRange->uiLowerLimit, 
              pNumRange->uiUpperLimit, 
              pNumRange->uiUpperLimit
            );
        break;
      default:
        break;
    }
    pNumRange++;
  }
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
Token_List_Help(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream,
    const char *Indent
  )
{ 
  TokenDesc_t *pTokens;
  size_t stTokenCount;
  fprintf(stream, "%s %s\n", Indent, "Supported Options");
  pTokens=((TokenListDesc_t*)pElementDesc->pExtraInfo)->pTokenList; 
  stTokenCount=((TokenListDesc_t*)pElementDesc->pExtraInfo)->uiTokenCount; 
  while(stTokenCount--){
    fprintf(stream, "%s \t %s\n", Indent, pTokens->pszTokenList);
    pTokens++;
  }
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
GUID_Help(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream,
    const char *Indent
  )
{ 
  pElementDesc=pElementDesc;
  fprintf(stream, "%s %s\n", Indent, "GUID in the Format F9168C5E-CEB2-4faa-B6BF-329BF39FA1E4");
  fprintf(stream, "%s %s\n", Indent, "  Means Not Supported 00000000-0000-0000-0000-000000000000");
  fprintf(stream, "%s %s\n", Indent, "  Means Setable       FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF");
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
SpecRev_Help(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream,
    const char *Indent
  )
{ 
  pElementDesc=pElementDesc;
  fprintf(stream, "%s %s\n", Indent, "2.0");
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
PNPID_Help(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream,
    const char *Indent
  )
{ 
  pElementDesc=pElementDesc;
  fprintf(stream, "%s %s\n", Indent, "3 Letter PNPID e.g. PMG,KEM");
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
I2C_EEPROM_Help(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream,
    const char *Indent
  )
{ 
  pElementDesc=pElementDesc;
  fprintf(stream, "%s %s\n", Indent, "Encodded I2C EEPROM Device Selector Address 0xA0,0xA2,0xA4,0xA6,0xA8,0xAA,0xAC,0xAE");
  return EAPI_STATUS_SUCCESS;
}

/*
 *
 *  Clean Functions
 *
 *
 */
EApiStatusCode_t
Dealloc_Element(
    __INOUT void   *pCurElement,                   
    __IN   size_t   stElementSize
  )
{ 
  stElementSize=stElementSize;
  if(*(char**)pCurElement!=NULL){
    free(*(char**)pCurElement);
    *(char**)pCurElement=NULL;
  }
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
GenClear_Element(
    __OUT void    *pu8CurElement,                   
    __IN  size_t   stElementSize 
  )
{ 
  memset(pu8CurElement, 0x00, stElementSize);
  return EAPI_STATUS_SUCCESS;
}

/*
 *
 *  Parse Functions
 *
 *
 */
EApiStatusCode_t
String_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void  *pCurElement, 
    char   *szValue
  )
{ 
  StringDesc_t *pStringDesc=pElementDesc->pExtraInfo; 
  size_t stStrLength;
  if(pStringDesc!=NULL){
    if(!pStringDesc->uiPreserveTrailingSpaces){
      stripWhiteSpaces(szValue);
    }
    stStrLength=strlen(szValue);
    if(pStringDesc->uiMinLength){
      if(pStringDesc->uiMinLength>stStrLength){
        printf("\tString_Element = String Too Short, %s\n", szValue);
      }
    }
    if(pStringDesc->uiMaxLength){
      if(pStringDesc->uiMaxLength<stStrLength){
        printf("\tString_Element = String Too Long, %s\n", szValue);
      }
    }
  }
  *(char **)pCurElement=EAPI_strdup(szValue);
#if TEST_EEPCFG
/*   printf("\tString_Element = %s, %s\n", *(char**)pCurElement, szValue); */
#endif
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
GUID_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void    *pCurElement, 
    char   *szValue
  )
{ 
  unsigned int i;
  char    *szEnd;
  uint32_t Part1;
  uint16_t Part2[2];
  char     Short[3];
  pElementDesc=pElementDesc;
  szValue=skipWhiteSpaces(szValue);
  stripWhiteSpaces(szValue);
  /*0000000000111111111122222222223333333333
   *0123456789012345678901234567890123456789
   *F9168C5E-CEB2-4faa-B6BF-329BF39FA1E4
   */
  if( szValue[ 8]!='-'||
      szValue[13]!='-'||
      szValue[18]!='-'||
      szValue[23]!='-'||
      szValue[36]!='\0'
    )
  {
    printf("\tString_Element = Invalid Format, %s\n", szValue);
    return EAPI_STATUS_ERROR;
  }
  Part1=strtoul(szValue+0, &szEnd, 16);
  Part2[0]=(uint16_t)strtoul(szValue+9, &szEnd, 16);
  Part2[1]=(uint16_t)strtoul(szValue+14, &szEnd, 16);
  EeeP_Set32BitValue_BE(((uint8_t*)pCurElement)+0, Part1);
  EeeP_Set16BitValue_BE(((uint8_t*)pCurElement)+4, Part2[0]);
  EeeP_Set16BitValue_BE(((uint8_t*)pCurElement)+6, Part2[1]);
  for(i=19;i<22;i+=2){
    memcpy(Short, szValue+i, 2);
    Short[2]='\0';
    ((uint8_t*)pCurElement)[8+((i-19)/2)]=(uint8_t)strtoul(Short, &szEnd, 16);
  }
  for(i=24;i<35;i+=2){
    memcpy(Short, szValue+i, 2);
    Short[2]='\0';
    ((uint8_t*)pCurElement)[10+(i/2)-12]=(uint8_t)strtoul(Short, &szEnd, 16);
  }
#if TEST_EEPCFG
/*   printf("\tGUID_Element = "); */
/*   PrintHexAsciiTableEx( */
/*       pCurElement,  */
/*       16,  */
/*       pCurElement,  */
/*       NULL, */
/*       HEXTBL_8BIT_ELEMENT|16 */
/*     ); */
#endif
 
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
Number_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *szValue
  )
{ 
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  
  DO(ParseAsciiEqu_VA(szValue, pCurElement, (signed int)pElementDesc->cstElementSize));

  
  if(pElementDesc->pExtraInfo!=NULL){
    EApiStatusCode=RangeCheckAny(
        ((NumberRangeDesc_t*)pElementDesc->pExtraInfo), 
        *(unsigned long*)pCurElement
      );
  }
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
    printf("\tNumber_Element = Outside Range, %s\n", szValue);
/*   }else{ */
/*     printf("\tNumber_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, szValue); */
  }
EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}

EApiStatusCode_t
I2C_EEPROM_Addr(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *szValue
  )
{ 
  pElementDesc=pElementDesc;
  *(unsigned long*)pCurElement=ulConvertStr2NumEx(szValue, NULL);
  if((*(unsigned long*)pCurElement<=0xAE)&&(*(unsigned long*)pCurElement>=0xA0)&&!(*(unsigned long*)pCurElement&1)){
/*     printf("\tI2C_EEPROM_Addr = 0x%02lX, %s\n", *pCurElement, szValue); */
    return EAPI_STATUS_SUCCESS;
  }
  printf("\tI2C_EEPROM_Addr = Invalid Address 0x%02lX, %s\n", *(unsigned long*)pCurElement, szValue);
  return EAPI_STATUS_ERROR;
}

EApiStatusCode_t
Token_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *szValue
  )
{ 
  EApiStatusCode_t EApiStatusCode;
  szValue=skipWhiteSpaces(szValue);
  stripWhiteSpaces(szValue);
  EApiStatusCode=GetTokenValue(
      ((TokenListDesc_t*)pElementDesc->pExtraInfo), 
      szValue, 
      pCurElement
    );
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
    printf("\tToken_Element = Unknown Token, %s\n", szValue);
/*   }else{ */
/*     printf("\tToken_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, szValue); */
  }
  return EApiStatusCode;
}

EApiStatusCode_t
SpecRev_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void     *pCurElement,
    char   *szValue
  )
{ 
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  char *szEnd;
  pElementDesc=pElementDesc;
  *(unsigned long*)pCurElement=(ulConvertStr2NumEx(szValue, &szEnd)&0xF)<<4;
  EAPI_APP_RETURN_ERROR_IF_S(
      SpecRev_Element,
      (*szEnd!='.'),
      EAPI_STATUS_ERROR
      );
  *(unsigned long*)pCurElement|=ulConvertStr2NumEx(szEnd+1, &szEnd)&0xF;
/*   printf("\tSpecRev_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, szValue); */
EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}
EApiStatusCode_t
PNPID_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void          *pCurElement,
    char          *szValue
  )
{ 
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  unsigned int i=3;
  unsigned int uiCurChar;
  pElementDesc=pElementDesc;
  *(unsigned long*)pCurElement=0;
  stripWhiteSpaces(szValue);
  EAPI_APP_RETURN_ERROR_IF_S(
      PNPID_Element,
      (strlen(szValue)!=3),
      EAPI_STATUS_ERROR
      );
  while(i--){
    uiCurChar=toupper(*szValue++);
    EAPI_APP_RETURN_ERROR_IF_S(
        PNPID_Element,
        (uiCurChar<'A'||uiCurChar>'Z'),
        EAPI_STATUS_ERROR
      );
    *(unsigned long*)pCurElement<<=5;
    *(unsigned long*)pCurElement|=uiCurChar - 'A'+1;
  }
/*   printf("\tPNPID_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, szValue); */
EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}



NumberRange_t UINT8Range[]={
  {0x00, UINT8_MAX, RANGE_INCLUSIVE},
};
NumberRangeDesc_t  UINT8RangeDesc={
  ARRAY_SIZE(UINT8Range), UINT8Range
};
NumberRange_t UINT16Range[]={
  {0x00, UINT16_MAX, RANGE_INCLUSIVE},
};
NumberRangeDesc_t  UINT16RangeDesc={
  ARRAY_SIZE(UINT16Range), UINT16Range
};
NumberRange_t UINT32Range[]={
  {0x00, UINT32_MAX, RANGE_INCLUSIVE},
};
NumberRangeDesc_t  UINT32RangeDesc={
  ARRAY_SIZE(UINT32Range), UINT32Range
};

TokenDesc_t  InsideCrcTokens[]={
  {"InsideCRC"	, EEEP_ADDBLK_IN_CRC  },
  {"OutsideCRC"	, 0  },
};
PCFG_TOKEN_LIST_DESC(InsideCrcTL, InsideCrcTokens);

StringDesc_t PreserveTrailingSpaces={0,0,1};
StringDesc_t DeleteTrailingSpaces={0,0,0};
