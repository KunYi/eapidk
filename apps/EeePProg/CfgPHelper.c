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
Handlers_t  Number_Element_funcs  ={ Number_Element  , GenClear_Element , Range_List_Help, No_Default_Txt};
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
EApiStatusCode_t                                    
String_Help(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream,
    const char *Indent
  )
{ 
  pElementDesc=pElementDesc;
  fprintf(stream, "%s %s\n", Indent, "Generic String");
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
    char   *pszValue
  )
{ 
  pElementDesc=pElementDesc;
  *(char **)pCurElement=strdup(pszValue);
#if TEST_EEPCFG
/*   printf("\tString_Element = %s, %s\n", *(char**)pCurElement, pszValue); */
#endif
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
GUID_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void    *pCurElement, 
    char   *pszValue
  )
{ 
  unsigned int i;
  char    *pszEnd;
  uint32_t Part1;
  uint16_t Part2[2];
  char     Short[3];
  pElementDesc=pElementDesc;
  skipWhiteSpaces(&pszValue);
  stripWhiteSpaces(pszValue);
  /*0000000000111111111122222222223333333333
   *0123456789012345678901234567890123456789
   *F9168C5E-CEB2-4faa-B6BF-329BF39FA1E4
   */
  if( *(pszValue+8)!='-'||
      *(pszValue+13)!='-'||
      *(pszValue+18)!='-'||
      *(pszValue+23)!='-'||
      *(pszValue+36)!='\0'
    )
  {
    printf("\tString_Element = Invalid Format, %s\n", pszValue);
    return EAPI_STATUS_ERROR;
  }
  Part1=strtoul(pszValue+0, &pszEnd, 16);
  Part2[0]=(uint16_t)strtoul(pszValue+9, &pszEnd, 16);
  Part2[1]=(uint16_t)strtoul(pszValue+14, &pszEnd, 16);
  EeeP_Set32BitValue_BE(((uint8_t*)pCurElement)+0, Part1);
  EeeP_Set16BitValue_BE(((uint8_t*)pCurElement)+4, Part2[0]);
  EeeP_Set16BitValue_BE(((uint8_t*)pCurElement)+6, Part2[1]);
  for(i=19;i<22;i+=2){
    memcpy(Short, pszValue+i, 2);
    Short[2]='\0';
    ((uint8_t*)pCurElement)[8+((i-19)/2)]=(uint8_t)strtoul(Short, &pszEnd, 16);
  }
  for(i=24;i<35;i+=2){
    memcpy(Short, pszValue+i, 2);
    Short[2]='\0';
    ((uint8_t*)pCurElement)[10+(i/2)-12]=(uint8_t)strtoul(Short, &pszEnd, 16);
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
RangeCheck(
    NumberRange_t  *pNumRange ,
    size_t        stRangeCnt,
    unsigned long ulValue
  )
{ 
  while(stRangeCnt--){
/*     printf("%04lX - %04lX - %04lX\n", pNumRange->uiLowerLimit, ulValue, pNumRange->uiUpperLimit); */
    switch(pNumRange->uiType){
      case RANGE_INCLUSIVE:
        if(((ulValue>=pNumRange->uiLowerLimit)&&(ulValue<=pNumRange->uiUpperLimit))){
          return EAPI_STATUS_SUCCESS;
        }
        break;
      case RANGE_EXCLUSIVE:
        if(((ulValue<pNumRange->uiLowerLimit)||(ulValue>pNumRange->uiUpperLimit))){
          return EAPI_STATUS_SUCCESS;
        }
        break;
      case RANGE_MASK_SET:
        if((ulValue&pNumRange->uiLowerLimit)){
          return EAPI_STATUS_SUCCESS;
        }
        break;
      case RANGE_MASK_UNSET:
        if(!(ulValue&pNumRange->uiLowerLimit)){
          return EAPI_STATUS_SUCCESS;
        }
        break;
      default:
        break;
    }
    pNumRange++;
  }
  return EAPI_STATUS_ERROR;

}

EApiStatusCode_t
Number_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *pszValue
  )
{ 
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  *(unsigned long*)pCurElement=ulConvertStr2Num(pszValue, NULL);
  
  if(pElementDesc->pExtraInfo!=NULL){
    EApiStatusCode=RangeCheck(
        ((NumberRangeDesc_t*)pElementDesc->pExtraInfo)->pNumberRange, 
        ((NumberRangeDesc_t*)pElementDesc->pExtraInfo)->stRangeCount, 
        *(unsigned long*)pCurElement
      );
  }
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
    printf("\tNumber_Element = Outside Range, %s\n", pszValue);
/*   }else{ */
/*     printf("\tNumber_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, pszValue); */
  }
  return EApiStatusCode;
}

EApiStatusCode_t
I2C_EEPROM_Addr(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *pszValue
  )
{ 
  pElementDesc=pElementDesc;
  *(unsigned long*)pCurElement=ulConvertStr2Num(pszValue, NULL);
  if((*(unsigned long*)pCurElement<=0xAE)&&(*(unsigned long*)pCurElement>=0xA0)&&!(*(unsigned long*)pCurElement&1)){
/*     printf("\tI2C_EEPROM_Addr = 0x%02lX, %s\n", *pCurElement, pszValue); */
    return EAPI_STATUS_SUCCESS;
  }
  printf("\tI2C_EEPROM_Addr = Invalid Address 0x%02lX, %s\n", *(unsigned long*)pCurElement, pszValue);
  return EAPI_STATUS_ERROR;
}

EApiStatusCode_t
GetTokenValue(
    TokenDesc_t  *pTokens   ,
    size_t        stTokencnt,
          char   *pszValue  ,
    unsigned long*pulValue
  )
{ 
  *pulValue=0;
  skipWhiteSpaces(&pszValue);
  stripWhiteSpaces(pszValue);
  while(stTokencnt--){
    if(!strcmp(pTokens->pszTokenList, pszValue)){
      *pulValue=pTokens->ulTokenValue;
      return EAPI_STATUS_SUCCESS;
    }
    pTokens++;
  }
  return EAPI_STATUS_ERROR;

}

EApiStatusCode_t
Token_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *pszValue
  )
{ 
  EApiStatusCode_t EApiStatusCode;
  EApiStatusCode=GetTokenValue(
      ((TokenListDesc_t*)pElementDesc->pExtraInfo)->pTokenList, 
      ((TokenListDesc_t*)pElementDesc->pExtraInfo)->uiTokenCount, 
      pszValue, 
      pCurElement
    );
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
    printf("\tToken_Element = Unknown Token, %s\n", pszValue);
/*   }else{ */
/*     printf("\tToken_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, pszValue); */
  }
  return EApiStatusCode;
}

EApiStatusCode_t
SpecRev_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void     *pCurElement,
    char   *pszValue
  )
{ 
  char *pszEnd;
  pElementDesc=pElementDesc;
  *(unsigned long*)pCurElement=(ulConvertStr2Num(pszValue, &pszEnd)&0xF)<<4;
  EAPI_APP_RETURN_ERROR_IF_S(
      SpecRev_Element,
      (*pszEnd!='.'),
      EAPI_STATUS_ERROR
      );
  *(unsigned long*)pCurElement|=ulConvertStr2Num(pszEnd+1, &pszEnd)&0xF;
/*   printf("\tSpecRev_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, pszValue); */
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
PNPID_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void          *pCurElement,
    char          *pszValue
  )
{ 
  unsigned int i=3;
  char CurChar;
  pElementDesc=pElementDesc;
  *(unsigned long*)pCurElement=0;
  stripWhiteSpaces(pszValue);
  EAPI_APP_RETURN_ERROR_IF_S(
      PNPID_Element,
      (strlen(pszValue)!=3),
      EAPI_STATUS_ERROR
      );
  while(i--){
    CurChar=(char)toupper(*pszValue++);
    EAPI_APP_RETURN_ERROR_IF_S(
        PNPID_Element,
        (CurChar<'A'||CurChar>'Z'),
        EAPI_STATUS_ERROR
      );
    *(unsigned long*)pCurElement<<=5;
    *(unsigned long*)pCurElement|=CurChar-'A'+1;
  }
/*   printf("\tPNPID_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, pszValue); */
  return EAPI_STATUS_SUCCESS;
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

