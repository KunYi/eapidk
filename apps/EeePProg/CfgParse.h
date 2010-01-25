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
 *I Description: Auto Created for sprintf.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : CfgParse.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __CFGPARSE_H__
#define __CFGPARSE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TokenDesc_s{
  char          *pszTokenList;
  unsigned long  ulTokenValue;
}TokenDesc_t;
typedef struct TokenListDesc_s{
  unsigned int uiTokenCount;
  TokenDesc_t *pTokenList;
}TokenListDesc_t;


typedef struct CfgElementDesc_s{
  const char * pcszElementName;
  size_t stElementCount;
  const unsigned int  cuiRequired;
#define ELEMENT_OPTIONAL    0
#define ELEMENT_REQUIRED    1
  const size_t cstElementMax  ;
  const size_t cstElementSize ;
  struct Handlers_s{
  EApiStatusCode_t (*Handler)(struct CfgElementDesc_s *pElementDesc, void *pvElement, char *Value);
  EApiStatusCode_t (*Clean  )(void *pvElement, size_t stElementSize);
  EApiStatusCode_t (*Help   )(struct CfgElementDesc_s *pElementDesc, FILE * stream, const char *Indent );
  EApiStatusCode_t (*Default)(struct CfgElementDesc_s *pElementDesc, FILE * stream, unsigned int uiCount );
  } *pHandlers;
  union {
    void *pv;
    char **psz;
    unsigned long *pul;
  }Elements;
  void            *pExtraInfo;
}CfgElementDesc_t;
#define ELEMENT_DESC(Name, Array, Type, Tokens, Required) {Name, 0, Required, ARRAY_SIZE(Array), sizeof(Array[0]), Type, {Array} , Tokens},

typedef struct Handlers_s Handlers_t;

typedef struct NumberRange_s{
  unsigned int uiLowerLimit;
  unsigned int uiUpperLimit;
  unsigned int uiType;
#define  RANGE_EXCLUSIVE  0
#define  RANGE_INCLUSIVE  1
#define  RANGE_MASK_SET   2
#define  RANGE_MASK_UNSET 3
}NumberRange_t;
typedef struct NumberRangeDesc_s{
  size_t         stRangeCount;
  NumberRange_t *pNumberRange;
}NumberRangeDesc_t;


typedef 
EApiStatusCode_t 
ElementHandler_t(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT void *pvElement, 
    __IN  char *Value
  );
typedef 
EApiStatusCode_t 
ElementCleaner_t(
    __INOUT void  *pvElement   ,
    __IN    size_t stElementSize 
  );
typedef 
EApiStatusCode_t 
ElementHelpTxt_t(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT FILE * stream, 
    __IN  const char *Indent 
  );
typedef 
EApiStatusCode_t 
ElementDefaultTxt_t(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT FILE * stream,
    __IN  unsigned int uiCount
  );

extern Handlers_t  String_Element_funcs  ;
extern Handlers_t  Number_Element_funcs  ;
extern Handlers_t  Token_Element_funcs   ;
extern Handlers_t  SpecRev_Element_funcs ;
extern Handlers_t  PNPID_Element_funcs   ;
extern Handlers_t  I2C_EEPROM_Addr_funcs ;
extern Handlers_t  COM0PCIe_Element_funcs;
extern Handlers_t  GUID_Element_funcs    ;


extern NumberRangeDesc_t  UINT8RangeDesc;
extern NumberRangeDesc_t  UINT16RangeDesc;
extern NumberRangeDesc_t  UINT32RangeDesc;

extern TokenListDesc_t  InsideCrcTL;

typedef struct CfgBlockDesc_s{
  char *              pszBlockName;
  unsigned int        uiFound;
#define BLOCK_FOUND (unsigned)-1
  const unsigned int  cuiRequired;
#define BLOCK_OPTIONAL    0
#define BLOCK_REQUIRED    (unsigned)-1
  size_t              stElementCount;
  CfgElementDesc_t   *pElementsDesc;
  void *              pDataContainer;
  EApiStatusCode_t   (*Handler)(struct CfgBlockDesc_s *pDesc, void *pvExecContext);
}CfgBlockDesc_t;

typedef 
EApiStatusCode_t 
BlockHandler_t(
    __IN  struct CfgBlockDesc_s *pDesc, 
    __IN  void *pvExecContext
  );

#define BLOCK_DESC(Name, Array, DataContainer, Handler, Required) {Name, 0, Required, ARRAY_SIZE(Array), Array, DataContainer, Handler},


ElementHandler_t String_Element;
ElementHandler_t Number_Element;
ElementHandler_t Token_Element;
ElementHandler_t SpecRev_Element;
ElementHandler_t PNPID_Element;
ElementHandler_t I2C_EEPROM_Addr;
ElementHandler_t GUID_Element;


ElementCleaner_t Dealloc_Element;
ElementCleaner_t GenClear_Element;

ElementHelpTxt_t String_Help;
ElementHelpTxt_t Token_List_Help;
ElementHelpTxt_t Range_List_Help;
ElementHelpTxt_t SpecRev_Help;
ElementHelpTxt_t PNPID_Help;
ElementHelpTxt_t I2C_EEPROM_Help;
ElementHelpTxt_t GUID_Help;

ElementDefaultTxt_t No_Default_Txt;
ElementDefaultTxt_t Token_List_Default;
ElementDefaultTxt_t GUID_Default;

EApiStatusCode_t
GetTokenValue(
    TokenDesc_t  *pTokens   ,
    size_t        stTokencnt,
          char   *pszValue  ,
    unsigned long*pulValue
  );

EApiStatusCode_t
PrintCfgFile(
    __IN    CfgBlockDesc_t *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements ,
    __OUT   FILE *         OutStream            
    );

EApiStatusCode_t
CleanStruct(
    __IN    CfgBlockDesc_t *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements
    );

EApiStatusCode_t
ParseCfgFile(
    __IN    const char *pcszCfgFileName       ,
    __INOUT CfgBlockDesc_t *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements
    );

#define PCFG_TOKEN_LIST_DESC(TLName, TokenList) \
TokenListDesc_t TLName={ \
  ARRAY_SIZE(TokenList), TokenList \
}

#define PCFG_RANGE_LIST_DESC(RLName, RangeList) \
NumberRangeDesc_t RLName={ \
  ARRAY_SIZE(RangeList), RangeList \
}


#ifdef __cplusplus
}
#endif
#endif /* __CFGPARSE_H__ */
