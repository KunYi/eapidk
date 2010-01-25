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
 *I Description: Generic Command Line Argument Parsing Routines
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : ArgParse.c
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
StringArg(
    struct ArgDesc_s  *pArgs, 
    void * cszCurArg          ,  
    const char *cszArg 
    )
{
  pArgs=pArgs;
  *(void**)cszCurArg=EAPI_strdup(cszArg);
  printf("StringArg: %s\n", *(char**)cszCurArg);
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t 
NumberArg(
    struct ArgDesc_s  *pArgs, 
    void* pvalue   ,  
    const char *cszArg 
    )
{
  pArgs=pArgs;
  *(unsigned long*)pvalue=ulConvertStr2Num(cszArg, NULL);
  printf("StringArg: %s(0x%lX)\n", cszArg, *(unsigned long*)pvalue);
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
StringBlock(
    const char *cszStr        ,
    size_t      stMaxBlockLen ,
    size_t     *pstLastPos
    )
{
  const char *cszLastPos;
  *pstLastPos=strlen(cszStr);
  if(*pstLastPos<stMaxBlockLen){
    return EAPI_STATUS_SUCCESS;
  } 
  cszLastPos=cszStr + stMaxBlockLen;
  *pstLastPos=stMaxBlockLen;
  while(stMaxBlockLen --){
    if(*cszLastPos==' '||*cszLastPos=='\t'){
      *pstLastPos=cszLastPos - cszStr+1;
      return EAPI_STATUS_MORE_DATA;
    }
    cszLastPos --;
  }
  return EAPI_STATUS_MORE_DATA;
}

EApiStatusCode_t
PrintStringBlock(
    FILE       *OutStream     ,
    const char *cszStr        ,
    size_t      stMaxBlockLen ,
    const char *cszLine1      ,
    const char *cszOLines
    )
{
  size_t stCurStrPos;
  StringBlock(cszStr, stMaxBlockLen, &stCurStrPos);
  fprintf(OutStream, cszLine1, stCurStrPos, cszStr );
  while(stCurStrPos){
    cszStr+=stCurStrPos  ;
    StringBlock(cszStr, stMaxBlockLen, &stCurStrPos);
    if(stCurStrPos)
      fprintf( OutStream, cszOLines, stCurStrPos, cszStr );
  };
  return EAPI_STATUS_SUCCESS;
}
const char cszHeader[]= 
  "+=============================================================================+\n"
  "| Usage                                                                       |\n"
  "+-----------------------------------------------------------------------------+\n"
;
const char cszFooter[]= 
  "+=============================================================================+\n"
  ;

EApiStatusCode_t
PrintUsage(
    FILE      *OutStream    , 
    CmdDesc_t *pCmdDesc     ,
    size_t    stArgDescCnt
    )
{
  ArgDesc_t *pArgDesc;
  size_t     stArgCount;
  fprintf(OutStream, cszHeader);
  while(stArgDescCnt --){
    /*
     *
     */
    if(pCmdDesc->cShort)
      fprintf(OutStream, "| -%c ", pCmdDesc->cShort );
    else
      fprintf(OutStream, "|    " );
    /*
     *
     */
    fprintf(OutStream, " --%-25s ", pCmdDesc->cszLong );
    /*
     *
     */
    PrintStringBlock(
        OutStream         ,
        pCmdDesc->cszHelp , 
        43                , 
        "%-43.*s |\n"     , 
        "|                                 %-43.*s |\n"
      );

    
    pArgDesc=pCmdDesc->pArgs;
    for(stArgCount=0; stArgCount< pCmdDesc->stArgs; stArgCount++){
      fprintf( OutStream, "|                                  Arg%lu ", (unsigned long)stArgCount);
      PrintStringBlock(
          OutStream         ,
          pArgDesc->cszHelp , 
          37                , 
          "%-37.*s |\n"     , 
          "|                                       %-37.*s |\n"
        );
      pArgDesc++;
    };
    if(pCmdDesc->pArgs){
      fprintf(
          OutStream, 
          "|                                                                             |\n" 
        );
    };

    pCmdDesc++;
  };
  fprintf(OutStream, cszFooter);
  return EAPI_STATUS_SUCCESS;
}


EApiStatusCode_t
ParseArgs(
    signed int siArgc,
    const char**pszArgv,
    CmdDesc_t *pCmdDesc,
    size_t    stArgDescCnt
    )
{
  EApiStatusCode_t EApiStatusCode;
  const char **pszCurArg=pszArgv;
  CmdDesc_t *pCurArgDesc;
  size_t stI;
  unsigned int uiValid;
  ArgDesc_t *pArgDesc;
  size_t     stArgCount;
  siArgc --;
  pszCurArg ++;
  while(siArgc --){
    uiValid=0;
/*     printf("DEBUG: Arg[%u] (%s)\n", siArgc, *pszCurArg); */
    stI=stArgDescCnt;
    pCurArgDesc=pCmdDesc;
    if(pszCurArg[0][0]=='-'){
      if(pszCurArg[0][1]=='-'){
        while(stI --){
          if(!strcmp(pszCurArg[0]+2, pCurArgDesc->cszLong)){
            printf("[%u][%lu]--%s==--%s\n", siArgc, (unsigned long)stI, pszCurArg[0]+2, pCurArgDesc->cszLong);
            ++uiValid;
            stI=0;
            continue;
          }
          ++pCurArgDesc;
        }
      }else{
        while(stI --){
          if(pszCurArg[0][1]==pCurArgDesc->cShort){
            printf("[%u][%lu]-%c==-%c\n", siArgc, (unsigned long)stI, pszCurArg[0][1], pCurArgDesc->cShort);
            ++uiValid;
            stI=0;
            continue;
          }
          ++pCurArgDesc;
        }
      }
    }
    if(!uiValid){
      printf("ERROR: Unknown Arg (%s)\n", *pszCurArg);
    }else{
      ++*pCurArgDesc->puiResult;
      stArgCount=pCurArgDesc->stArgs;
      pArgDesc=pCurArgDesc->pArgs;
      while(stArgCount -- ){
        if(!siArgc --){
          printf("ERROR: Missing Required Argument (%s)\n", pArgDesc->cszHelp);
          return EAPI_STATUS_ERROR;
        }
        ++pszCurArg;
        DO(pArgDesc->Handle(pArgDesc, pArgDesc->pValue, pszCurArg[0]));
        ++pArgDesc;
      }
    }
    ++pszCurArg;
  }
  return EAPI_STATUS_SUCCESS;
}
#if TEST_EEPCFG

typedef struct OptionsTest_s{
  unsigned int uiHelp;
  unsigned int uiVerbose;
  unsigned int uiCreateCOM0R20M_CFG;
  char  *szCOM0R20M_Cfg_File;
}OptionsTest_t;
OptionsTest_t CurOptionsTest;
ArgDesc_t  COM0R20M_Cfg[]={
  {
  &CurOptionsTest.szCOM0R20M_Cfg_File        ,
  sizeof(CurOptionsTest.szCOM0R20M_Cfg_File) ,
  "<Filename>  Destination File"         ,
  StringArg
  },
};

CmdDesc_t Args[]={
  {
    'h'                                             , 
    "help"                                          , 
    &CurOptionsTest.uiHelp                          , 
    "Print this usage message"                      , 
    NULL                                            ,
    0                          
  },
  {
    'v'                                             , 
    "verbose"                                       , 
    &CurOptionsTest.uiVerbose                       , 
    "Increases Verbosity Level"                     , 
    NULL                                            ,
    0                          
  },
  {
    0x00                                            , 
    "CREATE-COM0R20M-CFG"                           , 
    &CurOptionsTest.uiCreateCOM0R20M_CFG            , 
    "Create COM0 Module Config File Template"       , 
    COM0R20M_Cfg                                    ,
    ARRAY_SIZE(COM0R20M_Cfg)
  },
};
char *DummyArgs1[]={
  "Program Name",
  "-a",
  "-s",
  "-v",
  "-q",
  "--Arg1",
  "--Arg2",
  "--CREATE-COM0R20CB-CFG",
  "TestFile.cfg",
  "--Arg3",
};
#define DO_MAIN(x)  \
  EAPI_printf(        \
      TEXT("#####\n") \
      TEXT("#\t%s\n") \
      TEXT("#####\n"),\
      TEXT(#x)        \
    );                \
  EApiStatusCode=x;   \
  if(!EAPI_STATUS_TEST_OK(EApiStatusCode)) \
    return EApiStatusCode

/*
 * Create Block Content
 */
int 
__cdecl 
main(void)
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;

#ifdef _DEBUG
  _CrtSetDbgFlag( _CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag());
#endif

  PrintUsage(stderr, Args, ARRAY_SIZE(Args), cszHeader, cszFooter);
  ParseArgs(ARRAY_SIZE(DummyArgs1), DummyArgs1, Args, ARRAY_SIZE(Args));

  exit(EApiStatusCode);
}

#endif
