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

#include <TokenFunc.h>
#include <RangeFunc.h>

typedef struct CfgElementDesc_s{
  const char * pcszElementName;
  size_t stElementCount;
  const unsigned int  cuiRequired;
#define ELEMENT_OPTIONAL    0
#define ELEMENT_REQUIRED    1
  const size_t cstElementMax  ;
  const size_t cstBitOffset   ;
  const size_t cstBitLength   ;
  const size_t cstElementSize ;
  struct Handlers_s{
  EApiStatusCode_t (*Handler)(struct CfgElementDesc_s *pElementDesc, void *pvElement, char *Value);
  EApiStatusCode_t (*Clean  )(struct CfgElementDesc_s *pElementDesc, void *pvElement);
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
#define ELEMENT_DESC(Name, Array, Type, Tokens, Required) {Name, 0, Required, ARRAY_SIZE(Array), 0, 8*sizeof(Array[0]), sizeof(Array[0]), Type, {Array} , Tokens},
#define ELEMENT_BDESC(Name, Array, BO, BL, Type, Tokens, Required) {Name, 0, Required, ARRAY_SIZE(Array), BO, BL, sizeof(Array[0]), Type, {Array} , Tokens},

typedef struct Handlers_s Handlers_t;

typedef struct StringDesc_s{
  unsigned int uiMinLength;
  unsigned int uiMaxLength;
  unsigned int uiPreserveTrailingSpaces;
}StringDesc_t;

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
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __INOUT void  *pvElement
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
extern Handlers_t  TokenNum_Element_funcs;
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
ElementHandler_t TokenNum_Element;
ElementHandler_t Token_Element;
ElementHandler_t SpecRev_Element;
ElementHandler_t PNPID_Element;
ElementHandler_t I2C_EEPROM_Addr;
ElementHandler_t GUID_Element;


ElementCleaner_t Dealloc_Element;
ElementCleaner_t GenClear_Element;

ElementHelpTxt_t String_Help;
ElementHelpTxt_t Token_List_Help;
ElementHelpTxt_t TokenNum_List_Help;
ElementHelpTxt_t Range_List_Help;
ElementHelpTxt_t SpecRev_Help;
ElementHelpTxt_t PNPID_Help;
ElementHelpTxt_t I2C_EEPROM_Help;
ElementHelpTxt_t GUID_Help;

ElementDefaultTxt_t No_Default_Txt;
ElementDefaultTxt_t Token_List_Default;
ElementDefaultTxt_t TokenNum_List_Default;
ElementDefaultTxt_t Range_Default_Txt;
ElementDefaultTxt_t GUID_Default;

extern StringDesc_t PreserveTrailingSpaces;
extern StringDesc_t DeleteTrailingSpaces;

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



#ifdef __cplusplus
}
#endif
#endif /* __CFGPARSE_H__ */
