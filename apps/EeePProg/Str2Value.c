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
  #include <ctype.h>

#define EAPI_STATUS_PARSE_ERROR EAPI_STATUS_ERROR
char *
ReturnEnvVar(
    const char *const VarName
    )
{
    char* libvar=NULL;

#if 0
    size_t requiredSize;
    getenv_s( &requiredSize, NULL, 0, VarName);
    if(requiredSize==0)
      return NULL;

    libvar = (char*) malloc(requiredSize * sizeof(char));
    if (!libvar)
    {
        printf("Failed to allocate memory!\n");
        return NULL;
    }

    // Get the value of the LIB environment variable.
    getenv_s( &requiredSize, libvar, requiredSize, VarName );
#else
    libvar=getenv(VarName);
    if(libvar==NULL) goto ErrorExit;
    libvar=_strdup(libvar);
#endif
    // 
ErrorExit:
    return libvar;
}

#if 0
unsigned long 
ulConvertStr2NumCEx(
    const char *  cszString, 
    char **const  pszEnd, 
    const char  * Indent
    )
  {
    unsigned long ReturnVal;
    int siRadix=10;
    cszString=skipWhiteSpaces(cszString);
    if(*cszString=='0'){
      cszString++;
      switch(*cszString){
        case 'x':
          cszString++;
          siRadix=16;
          break;
        default:
          siRadix=8;
          break;
      }
    }
    ReturnVal = strtoul(cszString, pszEnd, siRadix);
/*     VERBOSEL(2) */
#ifdef TEST_EQUPARSER
      siFormattedMessage_M2('D', __FILE__, "ulConvertStr2NumCEx", __LINE__, "",
                  "0x%lX(%ld)  \n", ReturnVal, ReturnVal );
#endif
    return ReturnVal;
  }
unsigned long 
ulConvertStr2NumAsmEx(
    const char *  cszString, 
    char **const  pszEnd, 
    const char  * Indent
    )
  {
    unsigned long ReturnVal=0;
    char *pszEndH;
    char *pszEndB;
    cszString=skipWhiteSpaces(cszString);
    strtoul(cszString, &pszEndH, 16);
    strtoul(cszString, &pszEndB,  2);
    /* 
     *  0ffh
     */
    if(isdigit(*cszString) && (toupper(*pszEndH)=='H') ){
        ReturnVal = strtoul(cszString, pszEnd, 16);
        (*pszEnd)++;
    /* 
     *  011b
     */
    }else if((*cszString >= '0' && *cszString <= '1') && (toupper(*pszEndB)=='B') ){
        ReturnVal = strtoul(cszString, pszEnd, 2);
        (*pszEnd)++;
    /* 
     *  099t
     */
    }else {
        ReturnVal = strtoul(cszString, pszEnd, 10);
        if(toupper(**pszEnd)=='T')++(*pszEnd);
    }
/*     VERBOSEL(2) */
#ifdef TEST_EQUPARSER
      siFormattedMessage_M2('D', __FILE__, "ulConvertStr2NumAsmEx", __LINE__, "",
                  "0x%lX(%ld)  \n", ReturnVal, ReturnVal );
#endif
    return ReturnVal;
  }
#endif
unsigned long 
ulConvertStr2NumEx(
    __IN  const char *  cszString, 
    __OUT char **       pszEnd
    )
  {
    unsigned long ReturnVal=0;
    char *pszEndH;
    char *pszEndB;
    if(pszEnd==NULL)pszEnd=&pszEndB;
    cszString=skipWhiteSpaces(cszString);
    strtoul(cszString, &pszEndH, 16);
    strtoul(cszString, &pszEndB,  2);
    /* 
     *  0xff
     */
    if( !memcmp( "0x", cszString , 2) ){
        ReturnVal = strtoul(cszString+2, pszEnd, 16);
    /* 
     *  0ffh
     */
    }else if(isdigit(*cszString) && (toupper(*pszEndH)=='H') ){
        ReturnVal = strtoul(cszString, pszEnd, 16);
        ++(*pszEnd);
    /* 
     *  011b
     */
    }else if(isbinary(*cszString) && (toupper(*pszEndB)=='B') ){
        ReturnVal = strtoul(cszString, pszEnd, 2);
        ++(*pszEnd);
    /* 
     *  099
     */
    }else {
        ReturnVal = strtoul(cszString, pszEnd, 10);
        if(toupper(**pszEnd)=='T')++(*pszEnd);
    }
/*     VERBOSEL(2) */
#ifdef TEST_EQUPARSER
      siFormattedMessage_M2('D', __FILE__, "ulConvertStr2NumEx", __LINE__, "0x0, 00h, 00b, 000",
                  "0x%lX(%ld)  \n", ReturnVal, ReturnVal );
#endif
    return ReturnVal;
  }
enum OperationTypes_e{
  Op_NoOperation            ,
  Op_LogicalEqual           ,
  Op_LogicalNotEqual        ,
  Op_LogicalOr              ,
  Op_LogicalAnd             ,
  Op_LogicalGreaterThan     ,
  Op_LogicalGreaterThanEqual,
  Op_LogicalLessThan        ,
  Op_LogicalLessThanEqual   ,
  Op_LogicalNot             ,
  Op_BitwiseAnd             ,
  Op_BitwiseOr              ,
  Op_BitwiseXor             ,
  Op_BitwiseNot             ,
  Op_Multiply               ,
  Op_Modulus                ,
  Op_Divide                 ,
  Op_Add                    ,
  Op_Subtract               ,
  Op_Negate                 ,
  Op_LeftShift              ,
  Op_RightShift
};
EApiStatusCode_t
DoOperation(
    __IN  unsigned int     siOperation,
    __OUT signed long long *psllValue ,
    __IN  signed long long sllValue
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  switch(siOperation){
    case Op_NoOperation:
      break;
    case Op_LogicalOr:
      *psllValue=*psllValue||sllValue;
      break;
    case Op_LogicalAnd:
      *psllValue=*psllValue&&sllValue;
      break;
    case Op_LogicalNot:
      *psllValue=!sllValue;
      break;
    case Op_LogicalGreaterThan:
      *psllValue=*psllValue>sllValue;
      break;
    case Op_LogicalGreaterThanEqual:
      *psllValue=*psllValue>=sllValue;
      break;
    case Op_LogicalLessThan:
      *psllValue=*psllValue<sllValue;
      break;
    case Op_LogicalLessThanEqual:
      *psllValue=*psllValue<=sllValue;
      break;
    case Op_BitwiseAnd:
      *psllValue&=sllValue;
      break;
    case Op_BitwiseXor:
      *psllValue^=sllValue;
      break;
    case Op_BitwiseOr:
      *psllValue|=sllValue;
      break;
    case Op_Negate:
      *psllValue=-sllValue;
      break;
    case Op_BitwiseNot:
      *psllValue=~sllValue;
      break;
    case Op_Multiply:
      *psllValue*=sllValue;
      break;
    case Op_Modulus:
      *psllValue%=sllValue;
      break;
    case Op_Divide:
      *psllValue/=sllValue;
      break;
    case Op_Add:
      *psllValue+=sllValue;
      break;
    case Op_Subtract:
      *psllValue-=sllValue;
      break;
    case Op_LeftShift:
      *psllValue<<=sllValue;
      break;
    case Op_RightShift:
      *psllValue>>=sllValue;
      break;
    case Op_LogicalNotEqual:
      *psllValue=*psllValue!=sllValue;
      break;
    case Op_LogicalEqual:
      *psllValue=*psllValue==sllValue;
      break;
    default:
      EAPI_APP_RETURN_ERROR(
          DoOperation, 
          EAPI_STATUS_PARSE_ERROR, 
          "Invalid Operation"
        );
      break;
  }
ErrorExit:
  return EApiStatusCode;
}
typedef struct BlockParser_s{
    const char       *szDesc;
    EApiStatusCode_t    (*pHandler)(void*, char* ,         signed long long*);
    EApiStatusCode_t    (*pParser )(void*, char**, char**, signed int      *);
    void             *pContext;
    const char       *szMsg2;
}BlockParser_t;

EApiStatusCode_t
ParserWrapper(
    __IN  BlockParser_t    *pContext,
    __IN  char             *szString,
    __IN  char             *szStringEnd,
    __OUT signed long long *psllValue

  )
{
  char SaveChar=0;
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  if(szStringEnd!=NULL){
    SaveChar=*szStringEnd;
    *szStringEnd='\0';
  }
  EApiStatusCode=pContext->pHandler(pContext+1, szString, psllValue);
  if(szStringEnd!=NULL){
    *szStringEnd=SaveChar;
  }
  return EApiStatusCode;
}
EApiStatusCode_t
ParseOpcodeTokensAscii(
    __IN  void       *pContext ,
    __IN  char      **pszString,
    __IN  char      **pszOpcode,
    __OUT signed int *psiOperationType
  )
{
  StrDescElement_t*pElement ;
  char *szPos=*pszString;
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  szPos=szFindStr(szPos, pContext, &pElement);
  *pszOpcode=szPos;
  if(szPos==NULL){
    *pszString=NULL;
    *psiOperationType=Op_NoOperation;
    return EApiStatusCode;
  }
  
  *psiOperationType=pElement->cuiValue;
  *pszString=szPos+strlen(pElement->pcszSymbol);
  return  EApiStatusCode;
}

EApiStatusCode_t
ParseAsciiEqu_13(
    __IN  void             *pContext,
    __IN  char             *szString,
    __OUT signed long long *psllValue

  )
{
    char *pszEnd;
    signed long long CurValue;
    EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
    szString=skipWhiteSpaces(szString);


    switch(*szString){
      case '!':
#ifdef TEST_EQUPARSER
        siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu_13", __LINE__, "!,~,-,+",
                "%s\n", szString );
#endif
        DO(ParseAsciiEqu_13(pContext, szString+1, &CurValue));
        DO(DoOperation(Op_LogicalNot, psllValue, CurValue));
        break;
      case '~':
#ifdef TEST_EQUPARSER
        siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu_13", __LINE__, "!,~,-,+",
                "%s\n", szString );
#endif
        DO(ParseAsciiEqu_13(pContext, szString+1, &CurValue));
        DO(DoOperation(Op_BitwiseNot, psllValue, CurValue));
        break;
      case '-':
#ifdef TEST_EQUPARSER
        siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu_13", __LINE__, "!,~,-,+",
                "%s\n", szString );
#endif
        DO(ParseAsciiEqu_13(pContext, szString+1, &CurValue));
        DO(DoOperation(Op_Negate, psllValue, CurValue));
        break;
      case '+':
#ifdef TEST_EQUPARSER
        siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu_13", __LINE__, "!,~,-,+",
                "%s\n", szString );
#endif
        DO(ParseAsciiEqu_13(pContext, szString+1, psllValue));
        break;
      default:
        *psllValue=ulConvertStr2NumEx(szString, &pszEnd);
        pszEnd=skipWhiteSpaces(pszEnd);
        if(*pszEnd!='\0'){
          siFormattedMessage_SC('E', __FILE__, "ParseAsciiEqu_13", __LINE__, EAPI_STATUS_PARSE_ERROR,
              "%s\n",  szString, pszEnd
            );
          siFormattedMessage_SC('E', __FILE__, "ParseAsciiEqu_13", __LINE__, EAPI_STATUS_PARSE_ERROR,
              "%*s%s\n", pszEnd - szString, "", "^ Here"
            );
          return EAPI_STATUS_PARSE_ERROR;
        }
        break;
    }
ErrorExit:
    return EApiStatusCode;
}




EApiStatusCode_t
ParseAsciiEqu_cmn(
    __IN  BlockParser_t    *pContext,
    __IN  char             *szString,
    __OUT signed long long *psllValue
  )
{
  char *szOpt,*szPos3,*szPos1,*szPos2=szString;
  signed OperationType=Op_NoOperation, LOperationType;
  signed long long CurValue;
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;

  szOpt=NULL;

  if(pContext->pParser){
    DO(pContext->pParser(pContext->pContext, &szPos2, &szOpt, &OperationType));
  }
  if(szOpt!=NULL){
#ifdef TEST_EQUPARSER
      siFormattedMessage_M2('D', __FILE__, pContext->szDesc, __LINE__, pContext->szMsg2,
              "%s\n", szString);
#endif
    DO(ParserWrapper(pContext, szString, szOpt, psllValue));

    do{
      LOperationType=OperationType;
      szPos1=skipWhiteSpaces(szPos2);
      do{
        szPos3=skipWhiteSpaces(szPos2);
        DO(pContext->pParser(pContext->pContext, &szPos2, &szOpt, &OperationType));
      }while(szPos3==szOpt);

      DO(ParserWrapper(pContext, szPos1, szOpt, &CurValue));

      DO(DoOperation(LOperationType, psllValue, CurValue));
    }while(szOpt!=NULL);
  }else{
    EApiStatusCode=pContext->pHandler(pContext+1, szString, psllValue);
  }
ErrorExit:
  return EApiStatusCode;
}

const StrDescElement_t cMultDiv[]={
  {"*",  Op_Multiply  },
  {"%",  Op_Modulus   },
  {"/",  Op_Divide    },
};
STR_DESC(cMultDiv_desc, cMultDiv);

const StrDescElement_t cAddSub []={
  {"+",  Op_Add       },
  {"-",  Op_Subtract  },
};
STR_DESC(cAddSub_desc, cAddSub);

const StrDescElement_t cBitShift[]={
  {"<<",  Op_LeftShift },
  {">>",  Op_RightShift},
};
STR_DESC(cBitShift_desc, cBitShift);

EApiStatusCode_t
ParseAscii_8(
    __IN  void       *pContext ,
    __IN  char      **pszString,
    __IN  char      **pszOpcode,
    __OUT signed int *psiOperationType
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  char *szGTLT=*pszString;
  char GTLT[]      = "<>";
  pContext=pContext;
  while((szGTLT=strpbrk(szGTLT, GTLT))!=NULL){
    if((szGTLT[1]=='<')||(szGTLT[1]=='>')){
      szGTLT+=2;
      continue;
    }
    break;
  }

  *pszOpcode=szGTLT;
  if(szGTLT==NULL){
    *pszString=NULL;
    *psiOperationType=Op_NoOperation;
    return EApiStatusCode;
  }
  switch(*szGTLT++) {
    case '<':
      if(*szGTLT=='='){
        *psiOperationType=Op_LogicalLessThanEqual;
        szGTLT++;
      }else{
        *psiOperationType=Op_LogicalLessThan;
      }
      break;
    case '>':
      if(*szGTLT=='='){
        *psiOperationType=Op_LogicalGreaterThanEqual;
        szGTLT++;
      }else{
        *psiOperationType=Op_LogicalGreaterThan;
      }
      break;
  }

  *pszString=szGTLT;
  return EApiStatusCode ;
}

const StrDescElement_t cCompare[]={
  {"==",  Op_LogicalEqual   },
  {"!=",  Op_LogicalNotEqual},
};
STR_DESC(cCompare_desc, cCompare);

const StrDescElement_t cBitwiseAnd[]={
  {"&",  Op_BitwiseAnd   },
};
STR_DESC(cBitwiseAnd_desc, cBitwiseAnd);

const StrDescElement_t cBitwiseXor[]={
  {"^",  Op_BitwiseXor   },
};
STR_DESC(cBitwiseXor_desc, cBitwiseXor);

const StrDescElement_t cBitwiseOr[]={
  {"|",  Op_BitwiseOr   },
};
STR_DESC(cBitwiseOr_desc, cBitwiseOr);

const StrDescElement_t cLogicalAnd[]={
  {"&&",  Op_LogicalAnd   },
};
STR_DESC(cLogicalAnd_desc, cLogicalAnd);

const StrDescElement_t cLogicalOr[]={
  {"||",  Op_LogicalOr    },
};
STR_DESC(cLogicalOr_desc, cLogicalOr);
/*
 * cond?vara:varb
 */
EApiStatusCode_t
ParseAsciiEqu_2(
    __IN  BlockParser_t    *pContext,
    __IN  char             *szString,
    __OUT signed long long *psllValue
  )
{
  char *szCondition;
  char *szSelBracket;
  signed long long Condition=0;
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  szCondition=strchr(szString, '?');
  if(szCondition!=NULL){
#ifdef TEST_EQUPARSER
    siFormattedMessage_M2('D', __FILE__, pContext->szDesc, __LINE__, pContext->szMsg2,
              "%s\n", szString);
#endif
    DO(ParserWrapper(pContext, szString, szCondition , &Condition));
    szSelBracket=strchr(szCondition, ':');
    if(szSelBracket==NULL) {
      EAPI_APP_RETURN_ERROR( ParseAsciiEqu_2, EAPI_STATUS_PARSE_ERROR, "Missing Right ':'");
    }

/*     siFormattedMessage_M2('D', __FILE__, pContext->szDesc, __LINE__, pContext->szMsg2, */
/*             "%s\n", szCondition+1); */
/*     siFormattedMessage_M2('D', __FILE__, pContext->szDesc, __LINE__, pContext->szMsg2, */
/*             "%s\n", szSelBracket+1); */
    if(Condition){
      DO(ParserWrapper(pContext, szCondition+1 , szSelBracket, psllValue));
    }else{
      DO(ParserWrapper(pContext - 1, szSelBracket+1, NULL, psllValue));
    }
  } else{
    EApiStatusCode=pContext->pHandler(pContext+1, szString, psllValue);
  }
ErrorExit:
  return EApiStatusCode;
}

BlockParser_t cAS[]={
{"ParseAsciiEqu_1" , ParseAsciiEqu_2  , NULL                  , NULL            , "()"        },
{"ParseAsciiEqu_2" , ParseAsciiEqu_cmn, NULL                  , NULL            , "cond?Vara:Varb"},
{"ParseAsciiEqu_3" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cLogicalOr_desc , "||"        },
{"ParseAsciiEqu_4" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cLogicalAnd_desc, "&&"        },
{"ParseAsciiEqu_5" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cBitwiseOr_desc , "|"         },
{"ParseAsciiEqu_6" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cBitwiseXor_desc, "^"         },
{"ParseAsciiEqu_7" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cBitwiseAnd_desc, "&"         },
{"ParseAsciiEqu_8" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cCompare_desc   , "==,!="     },
{"ParseAsciiEqu_9" , ParseAsciiEqu_cmn, ParseAscii_8          , NULL            , ">,>=,<,<=" },
{"ParseAsciiEqu_10", ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cBitShift_desc  , "<<,>>"     },
{"ParseAsciiEqu_11", ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cAddSub_desc    , "+,-"       },
{"ParseAsciiEqu_12", ParseAsciiEqu_13 , ParseOpcodeTokensAscii, cMultDiv_desc   , "*,/,%"     },
};
/*
 * ()
 */
EApiStatusCode_t
ParseAsciiEqu_1(
    __IN  char             *szString,
    __OUT signed long long *psllValue
  )
{
  char *szStartBracket;
  char *szEndBracket;
  size_t stSubLen;
  signed long long CurValue;
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  *psllValue=0;
  while((szStartBracket=strrchr(szString, '('))!=NULL){
#ifdef TEST_EQUPARSER
  siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu_1", __LINE__, "()",
              "%s\n", szString );
#endif
    szEndBracket=strchr(szStartBracket, ')');
    if(szEndBracket!=NULL)
    {
      *szEndBracket='\0';
      DO(ParseAsciiEqu_cmn(cAS, szStartBracket+1, &CurValue));
      stSubLen=szEndBracket - szStartBracket;
      EApiSprintfA( szStartBracket, stSubLen+1, "%*lld", stSubLen, CurValue);
      *szEndBracket=' ';
    }
    else
    {
      EAPI_APP_RETURN_ERROR(
          ParseAsciiEqu_1, 
          EAPI_STATUS_PARSE_ERROR, 
          "Missing Right ')'"
        );
    }
  }
  if(EAPI_STATUS_TEST_OK(EApiStatusCode))
    EApiStatusCode=ParseAsciiEqu_cmn(cAS, szString, psllValue);
ErrorExit:
  return EApiStatusCode;
}


const char cszEnvStartMarker[]="$(";
const char cszEnvEndMarker[]=")" ;
EApiStatusCode_t
ExpandEnviromentVariables(
    __IN  const char   *cszString,
    __OUT char        **pszExpStr
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  char *szVarPosS,*szVarPosE, *szLclBuf=NULL, *szLclBuf2=NULL, *szVarValue=NULL;
  size_t StrLen,ValLen;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ExpandEnviromentVariables, 
      EAPI_STATUS_INVALID_PARAMETER, 
      cszString
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ExpandEnviromentVariables, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pszExpStr
    );
  *pszExpStr=NULL;
  StrLen=strlen(cszString)+1;
  szLclBuf=malloc(StrLen);
  if(szLclBuf==NULL) goto ErrorExit;
  strcpy(szLclBuf, cszString);
  while((szVarPosS=strrstr(szLclBuf, cszEnvStartMarker))!=NULL){
#ifdef TEST_EQUPARSER
  siFormattedMessage_M2('D', __FILE__, "ExpandEnviromentVariables", __LINE__, "",
              "%s\n", szLclBuf );
#endif
    szVarPosE=strstr(szVarPosS, cszEnvEndMarker);
    if(szVarPosE==NULL){
      siFormattedMessage_SC('E', __FILE__, "ExpandEnviromentVariables", __LINE__, EAPI_STATUS_PARSE_ERROR,
          "Missing Right Bracket '%s'",  cszEnvEndMarker
          );
      goto ErrorExit;
    }
    *szVarPosS='\0';
    *szVarPosE='\0';
    szVarValue=ReturnEnvVar(szVarPosS+strlen(cszEnvStartMarker));
    if(szVarValue!=NULL) {
      ValLen=strlen(szVarValue);
    }else{
      ValLen=0;
    }
#ifdef TEST_EQUPARSER
/*   siFormattedMessage_M2('D', __FILE__, "ExpandEnviromentVariables", __LINE__, "", */
/*               "[%i][%i][%i]%s, %s, %s\n", StrLen, ValLen, StrLen+ValLen - (szVarPosE - szVarPosS + 1), szLclBuf, szVarPosS, szVarPosS+strlen(cszEnvStartMarker) ); */
#endif
    StrLen+= ValLen - (szVarPosE - szVarPosS + 1) ;
    szLclBuf2=malloc(StrLen);
    if(szLclBuf2==NULL) goto ErrorExit;
    strcpy(szLclBuf2, szLclBuf);
    if(szVarValue!=NULL) {
      strcat(szLclBuf2, szVarValue);
      free(szVarValue);
      szVarValue=NULL;
    }
    strcat(szLclBuf2, szVarPosE+strlen(cszEnvEndMarker));
    free(szLclBuf);
    szLclBuf=szLclBuf2;
    szLclBuf2=NULL;
  }


#ifdef TEST_EQUPARSER
/*   siFormattedMessage_M2('D', __FILE__, "ExpandEnviromentVariables", __LINE__, "", */
/*               "%s\n", szLclBuf ); */
#endif
  goto ExitSuccess;

ErrorExit:
  if(szLclBuf!=NULL)
    free(szLclBuf);
ExitSuccess:
  *pszExpStr=szLclBuf;
  if(szVarValue!=NULL)
    free(szVarValue);
  if(szLclBuf2!=NULL)
    free(szLclBuf2);


  return EApiStatusCode;
}
EApiStatusCode_t
ParseAsciiEqu(
    __IN  const char       *cszString,
    __OUT signed long long *psllValue
  )
{
  char *szEquation=NULL;
  EApiStatusCode_t EApiStatusCode;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu, 
      EAPI_STATUS_INVALID_PARAMETER, 
      cszString
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu, 
      EAPI_STATUS_INVALID_PARAMETER, 
      psllValue
    );
#if 1
  DO(ExpandEnviromentVariables(cszString, &szEquation));
#else
  szEquation=_strdup(cszString);
#endif
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu, 
      EAPI_STATUS_ALLOC_ERROR, 
      szEquation
    );
  *psllValue=0;
#ifdef TEST_EQUPARSER
/*   siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu", __LINE__, "", */
/*               "%s\n", szEquation ); */
#endif
  DO(ParseAsciiEqu_1(szEquation, psllValue));
ErrorExit:
  if(szEquation!=NULL) free(szEquation);
  return EApiStatusCode;
}
EApiStatusCode_t
ParseAsciiEqu_VA(
    __IN  const char       *cszString,
    __OUT void             *pvalue,
    __IN  signed int        siElementSize
  )
{
  signed long long sllValue;
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      cszString
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pvalue
    );
  memset(pvalue, 0x00, siElementSize);
  DO(ParseAsciiEqu(cszString, &sllValue));
  switch(siElementSize){
    case sizeof(unsigned long long):
      *(unsigned long long*)pvalue=(unsigned long long)sllValue;
      break;
    case sizeof(unsigned long):
      if(sllValue>0 && ((unsigned long long)sllValue)>(sizeof(unsigned long)*256)){
        EAPI_APP_RETURN_ERROR(
            ParseAsciiEqu_VA,
            EAPI_STATUS_ERROR,
            "Value Too Large for unsigned long"
          );
      }
      *(unsigned long*)pvalue=(unsigned long)sllValue;
      break;
/* #if (sizeof(unsigned long) != sizeof(unsigned int)) */
/*     case sizeof(unsigned int): */
/*       *(unsigned int*)pvalue=(unsigned int)sllValue; */
/*       break; */
/* #endif */
    case sizeof(unsigned short):
      if(sllValue>0 && ((unsigned long long)sllValue)>(sizeof(unsigned short)*256)){
        EAPI_APP_RETURN_ERROR(
            ParseAsciiEqu_VA,
            EAPI_STATUS_ERROR,
            "Value Too Large for unsigned short"
          );
      }
      *(unsigned short*)pvalue=(unsigned short)sllValue;
      break;
    case sizeof(unsigned char):
      if(sllValue>0 && ((unsigned long long)sllValue)>(sizeof(unsigned char)*256)){
        EAPI_APP_RETURN_ERROR(
            ParseAsciiEqu_VA,
            EAPI_STATUS_ERROR,
            "Value Too Large for unsigned char"
          );
      }
      *(unsigned char*)pvalue=(unsigned char)sllValue;
      break;
    default:
      EAPI_APP_RETURN_ERROR(
          ParseAsciiEqu_VA,
          EAPI_STATUS_ERROR,
          "Invalid Variable Lenght"
        );
      break;
  }

ErrorExit:
  return EApiStatusCode;
}

#ifdef TEST_EQUPARSER
typedef struct TestCase_s{
  const char *cszEquation;
  signed long long sllValue;
}TestCase_t;
#define TEST_CASE(x) {#x, x},

TestCase_t TestCasesEquates[]={
  TEST_CASE(1 + 1)
  TEST_CASE(1 + 1 + 3 + 4 - 3)
  TEST_CASE(0x00123)
  TEST_CASE(123)
  TEST_CASE(1 - 1)
  TEST_CASE(2*2+1)
  TEST_CASE(456%45+3*23/4+1)
  TEST_CASE(((2*2)+1))
  TEST_CASE((2*((2)+(1))))
  TEST_CASE((2*((2)+(1)))==0)
  TEST_CASE((2*((2)+(1)))!=0)
  TEST_CASE((2*((2)+(1)))>=0)
  TEST_CASE((2*((2)+(1)))<=0)
  TEST_CASE((2*((2)+(1)))&&0)
  TEST_CASE((2*((2)+(1)))||0)
  TEST_CASE(0x505050|   0x0A0A0A0|0x0000000)
  TEST_CASE(0x505050&   0x0A0A0A0|0x0000000)
  TEST_CASE(0x505050&   0x0A0A0A0&0x0000000)
  TEST_CASE(0x505050&  ~0x0A0A0A0|0x0000000)
  TEST_CASE(0x505050&~~~0x0A0A0A0|0x0000000)
  TEST_CASE(0x505050& ~~0x0A0A0A0|0x0000000)
  TEST_CASE(0x505050^   0x0A0A0A0|0x0000000)
  TEST_CASE(0x505050^   0x0A0A0A0^0x0000000)
  TEST_CASE(1<<5)
  TEST_CASE(5>>1)
  TEST_CASE(5>>1>=0)
  TEST_CASE(5>>1>=5>>2)
  TEST_CASE(5>>1<=5>>2)
  TEST_CASE(-1)
  TEST_CASE(!0)
  TEST_CASE(~0)
  TEST_CASE(1?1:0)
  TEST_CASE((1?1:0)?0:1)
  TEST_CASE(1?0:1?2:3)
  TEST_CASE(0?0:1?2:3)
  TEST_CASE(0?1:0?2:3)
  TEST_CASE(5- -1)
  TEST_CASE(5- - -1)
  TEST_CASE(5- - - -1)
  TEST_CASE(5- + -1)
  TEST_CASE(5- - + -1)
  TEST_CASE(5-(-1))
};
TestCase_t TestCasesEnv[]={
  {"$(NUMBER_OF_PROCESSORS)>=1", 1},
  {"0x$(PROCESSOR_REVISION)", 0},
  {"$(PROCESSOR_REVISION)", 0},
};
const char *pszTestStatus[]={
  "FAIL",
  "PASS"
};
#include <crtdbg.h>
/* #include <signal.h> */
/* void (*prev_terminateFunc)(int); */
/* void terminateFunc(int Arg1) */
/* { */
/*   siFormattedMessage_M2('D', __FILE__, "terminateFunc", __LINE__, "", */
/*               "[%i]\n", Arg1 ); */
/*  */
/* } */

int __cdecl main(
    const char *const *const argv, 
    const signed int argc, 
    const char *const *const envp 
    )
{
  EApiStatusCode_t EApiStatusCode;
  TestCase_t *pCurTestCase;
  int CasesLeft, TestCount=0, PassCount=0;
  signed long long sllLclValue;

/*   prev_terminateFunc = signal (SIGTERM ,terminateFunc); */
/*   if(prev_terminateFunc==SIG_ERR) */
/*     siFormattedMessage_M2('D', __FILE__, "main", __LINE__, "", */
/*               "%p\n", prev_terminateFunc ); */
/*  */
/*   prev_terminateFunc = signal (SIGBREAK,terminateFunc); */
/*   if(prev_terminateFunc==SIG_ERR) */
/*     siFormattedMessage_M2('D', __FILE__, "main", __LINE__, "", */
/*               "%p\n", prev_terminateFunc ); */
/*  */
/*   prev_terminateFunc = signal (SIGABRT ,terminateFunc); */
/*   if(prev_terminateFunc==SIG_ERR) */
/*     siFormattedMessage_M2('D', __FILE__, "main", __LINE__, "", */
/*               "%p\n", prev_terminateFunc ); */

/*   const char*const* pcszEnv;  */
/*   argv=argv; */
/*   argc=argc; */
/*   envp=envp; */

/*    _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG|_CRTDBG_LEAK_CHECK_DF|_CRTDBG_CHECK_EVERY_16_DF); */
/*   for (pcszEnv=envp;*pcszEnv!=NULL;pcszEnv++){ */
/*     siFormattedMessage_M2('D', __FILE__, "main", __LINE__, "", */
/*               "%s\n", *pcszEnv ); */
/*   } */
/*   for (pcszEnv=environ;*pcszEnv!=NULL;pcszEnv++){ */
/*     siFormattedMessage_M2('D', __FILE__, "main", __LINE__, "", */
/*               "%s\n", *pcszEnv ); */
/*   } */
  for(CasesLeft=ARRAY_SIZE(TestCasesEquates),
      pCurTestCase=TestCasesEquates;
      CasesLeft --;
      pCurTestCase ++
      )
  {
    TestCount++;
    EApiStatusCode=ParseAsciiEqu(pCurTestCase->cszEquation, &sllLclValue);
    if(!EAPI_TEST_SUCCESS(EApiStatusCode)){
      break;
    }
    printf(
        "[%04s]%30s | %8lli(0x%08llX), %8lli(0x%08llX)\n", 
        pszTestStatus[sllLclValue==pCurTestCase->sllValue], 
        pCurTestCase->cszEquation, 
        sllLclValue, sllLclValue, 
        pCurTestCase->sllValue, pCurTestCase->sllValue
      );
    if(sllLclValue==pCurTestCase->sllValue){
      PassCount++;
    }
  }
  for(CasesLeft=ARRAY_SIZE(TestCasesEnv),
      pCurTestCase=TestCasesEnv;
      CasesLeft --;
      pCurTestCase ++
      )
  {
    TestCount++;
    EApiStatusCode=ParseAsciiEqu(pCurTestCase->cszEquation, &sllLclValue);
/*     if(!EAPI_TEST_SUCCESS(EApiStatusCode)){ */
/*       break; */
/*     } */
    printf(
        "[%04s]%20s | %8lli(0x%08llX), %8lli(0x%08llX)\n", 
        pszTestStatus[sllLclValue==pCurTestCase->sllValue], 
        pCurTestCase->cszEquation, 
        sllLclValue, sllLclValue, 
        pCurTestCase->sllValue, pCurTestCase->sllValue
      );
/*     if(sllLclValue==pCurTestCase->sllValue){ */
    /*
     * Currently No Check
     */
      PassCount++;
/*     } */
  }
  printf(
      "Test Status\n"
      "  Total Tests : %i\n"
      "  Pass Count  : %i\n",
      TestCount,
      PassCount
    );
  return 0;
/*   exit(EAPI_STATUS_SUCCESS); */
}
#endif

