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
/*   printf("StringArg: %s\n", *(char**)cszCurArg); */
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t 
NumberArg(
    struct ArgDesc_s  *pArgs, 
    void* pvalue   ,  
    const char *cszArg 
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  
  DO(ParseAsciiEqu_VA(cszArg, pvalue, (signed int)pArgs->stValueSize));

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}

EApiStatusCode_t
StringBlock(
    const char *cszStr        ,
    size_t      stMaxBlockLen ,
    size_t     *pstLastPos
    )
{
  const char *cszLastPos=cszStr;
  *pstLastPos=0;
/*   printf("D%04u %s\n", __LINE__, cszLastPos); */

  if(*cszLastPos=='\n')
    cszLastPos++;
  while(stMaxBlockLen --){
/*   printf("%c", *cszLastPos); */
    switch(*cszLastPos++){
      case '\t':
        if(stMaxBlockLen>=7)
          stMaxBlockLen -=7;
        else
          stMaxBlockLen=0;
      case ' ':
        *pstLastPos=cszLastPos - cszStr;
        break;
      case '\0':
        *pstLastPos=cszLastPos - cszStr -1;
        return EAPI_STATUS_SUCCESS;
      case '\n':
        *pstLastPos=cszLastPos - cszStr -1;
        return EAPI_STATUS_MORE_DATA;
      default:
        break;
    }
  }
/*   printf("D%04u %s\n", __LINE__, cszLastPos); */
  if(!*cszLastPos){
    *pstLastPos=cszLastPos - cszStr;
    return EAPI_STATUS_SUCCESS;
  } else if(!*pstLastPos) {
    *pstLastPos=cszLastPos - cszStr;
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
  fprintf(OutStream, cszLine1, stMaxBlockLen, stCurStrPos, cszStr );
  while(stCurStrPos){
    cszStr+=stCurStrPos;
    if(*cszStr!='\0')
      cszStr++;
    StringBlock(cszStr, stMaxBlockLen, &stCurStrPos);
    if(stCurStrPos)
      fprintf( OutStream, cszOLines, stMaxBlockLen, stCurStrPos, cszStr );
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
    if(pCmdDesc->cszLong!=NULL)
      fprintf(OutStream, " --%-25s ", pCmdDesc->cszLong );
    else
      fprintf(OutStream, "                             ");
    /*
     *
     */
    PrintStringBlock(
        OutStream         ,
        pCmdDesc->cszHelp , 
        43                , 
        "%-*.*s |\n"     , 
        "|                                 %-*.*s |\n"
      );

    
    pArgDesc=pCmdDesc->pArgs;
    for(stArgCount=0; stArgCount< pCmdDesc->stArgs; stArgCount++){
      fprintf( OutStream, "|                                  Arg%lu ", (unsigned long)stArgCount);
      PrintStringBlock(
          OutStream         ,
          pArgDesc->cszHelp ,
          37                ,
          "%-*.*s |\n"      ,
          "|                                       %-*.*s |\n"
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
ParseArgsBuffer(
    const char *szCmdLine, 
    char      **pszArgv, 
    char       *szArgs, 
    signed int *psiArgc, 
    signed int *psiCharc 
  )
{
  signed int siInString;
  signed int siCopyChar;
  signed int siSlashesCnt;
  *psiArgc =0;
  *psiCharc=0;
  siInString=0;
  for(;;){
    while(*(szCmdLine)==' '||*(szCmdLine)=='\t'||*(szCmdLine)=='\n'){ ++(szCmdLine); }
    if(*szCmdLine=='\0')
      break;
    if(pszArgv!=NULL)
      *pszArgv++=szArgs;
    ++*psiArgc;
    for(;;){
      siCopyChar=1;

      siSlashesCnt=0;
      while(*szCmdLine=='\\'){
        szCmdLine++;
        siSlashesCnt++;
      }
      if(*szCmdLine=='\"'){
        if(!(siSlashesCnt%2)){
          if(siInString && szCmdLine[1]=='\"'){
            szCmdLine++;
          }else{
            siCopyChar=0;
            siInString=!siInString;
          }
        }
        siSlashesCnt/=2;
      }
      *psiCharc+=siSlashesCnt;
      if(szArgs!=NULL){
        while(siSlashesCnt --){
          *szArgs++='\\'; 
        }
      }
      if(*szCmdLine=='\0'||*szCmdLine=='\n'||(!siInString&&(*szCmdLine==' '||*szCmdLine=='\t')))
        break;
      if(siCopyChar){
        if(szArgs!=NULL)
          *szArgs++=*szCmdLine; 
        ++*psiCharc;
      }
      ++szCmdLine;
    }
    if(szArgs!=NULL)
      *szArgs++='\0'; 
    ++*psiCharc;
  }
  if(pszArgv!=NULL)
    *pszArgv++=NULL;
  ++*psiArgc;
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
CreateArgvArgcBuffer(
    const char *szCmdLine, 
    char      ***pszArgv, 
    signed int *psiArgc 
  )
{
  EApiStatusCode_t EApiStatusCode;
  signed int siCharCnt;
  DO(ParseArgsBuffer(szCmdLine, NULL, NULL, psiArgc, &siCharCnt));
  *pszArgv=(char**)malloc(((*psiArgc)*sizeof(char*))+(siCharCnt*sizeof(char)));
  EAPI_APP_ASSERT_PARAMATER_NULL(
      CreateArgvArgcBuffer,
      EAPI_STATUS_ALLOC_ERROR,
      *pszArgv
    );
  (*psiArgc) --;
  EApiStatusCode=ParseArgsBuffer(
          szCmdLine, 
          *pszArgv, 
          (char *)((*pszArgv)+(*psiArgc)), 
          psiArgc, 
          &siCharCnt
        );
EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}

EApiStatusCode_t
ParseArgsFile(
    const char*szFilename,
    CmdDesc_t *pCmdDesc,
    size_t    stArgDescCnt
    )
{
  EApiStatusCode_t EApiStatusCode;
  signed int siArgc;
  char**pszArgv=NULL;
  void *pvFileBuffer;
  char *szFileBuffer;
  size_t stFileSize;
  char ErrBuffer[200];
  EApiStatusCode=ReadTextFile(szFilename, &pvFileBuffer, &stFileSize);
  szFileBuffer=pvFileBuffer;

  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
    EApiSprintfA(
        ErrBuffer, ARRAY_SIZE(ErrBuffer),
        "Error Reading %s", szFilename
        );
    EAPI_APP_RETURN_ERROR(
        ParseArgs,
        EApiStatusCode,
        ErrBuffer
      );
  }
  DO(CreateArgvArgcBuffer(szFileBuffer, &pszArgv, &siArgc));
  if(szFileBuffer!=NULL) free(szFileBuffer);
  szFileBuffer=NULL;

  DO(ParseArgs(siArgc - 1, (const char **)pszArgv, pCmdDesc, stArgDescCnt));

EAPI_APP_ASSERT_EXIT
  if(pszArgv  !=NULL) free(pszArgv  );
  pszArgv=NULL;
  return EApiStatusCode;
}


EApiStatusCode_t
ParseSubArgs(
      signed int *psiArgc    ,
      const char***ppszArgv  ,
      size_t     stArgCount,
      ArgDesc_t *pArgDesc  
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  while(stArgCount -- ){
    if(!(*psiArgc)--){
      printf("ERROR: Missing Required Argument (%s)\n", pArgDesc->cszHelp);
      return EAPI_STATUS_ERROR;
    }
    ++(*ppszArgv);
    DO(pArgDesc->Handle(pArgDesc, pArgDesc->pValue, **ppszArgv));
    ++pArgDesc;
  }
EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}


EApiStatusCode_t
ParseArgs(
    signed int siArgc,
    const char**pszArgv,
    CmdDesc_t *pCmdDesc,
    size_t    stArgDescCnt
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  const char **pszCurArg=pszArgv;
  CmdDesc_t *pCurArgDesc;
  size_t stI;
  unsigned int uiValid,uiSyntaxError;
  const char *szCurOption;
  uiSyntaxError=0;
  while(siArgc -- && *pszCurArg!=NULL){
/*     printf("DEBUG: Arg[%u] (%s)\n", siArgc, *pszCurArg); */
    uiValid=0;
    szCurOption=*pszCurArg;
    switch(*szCurOption++){
      case '@':
        DO(ParseArgsFile(szCurOption, pCmdDesc, stArgDescCnt));
        ++uiValid;
        break;
      case '-':
        if(*szCurOption=='-'){
          ++szCurOption;
          /*
          * Parse Long Commands
          */
          stI=stArgDescCnt;
          pCurArgDesc=pCmdDesc;
          while(stI --){
            if( pCurArgDesc->cszLong!=NULL&&
                !strcmp(szCurOption, pCurArgDesc->cszLong)
                )
            {
              if(pCurArgDesc->puiResult!=NULL){
                ++*pCurArgDesc->puiResult;
              }
              DO(ParseSubArgs(&siArgc, &pszCurArg, pCurArgDesc->stArgs, pCurArgDesc->pArgs));
              ++uiValid;
              if(pCurArgDesc->handler!=NULL){
                DO(pCurArgDesc->handler(pCurArgDesc->pArgData));
              }
              break;
            }
            ++pCurArgDesc;
          }
        }else {
          /*
          * Parse Short Commands
          */
          while(*szCurOption){
            stI=stArgDescCnt;
            pCurArgDesc=pCmdDesc;
            uiValid=0;
            while(stI --){
              if(*szCurOption==pCurArgDesc->cShort){
                if(pCurArgDesc->puiResult!=NULL){
                  ++*pCurArgDesc->puiResult;
                }
                DO(ParseSubArgs(&siArgc, &pszCurArg, pCurArgDesc->stArgs, pCurArgDesc->pArgs));
                ++uiValid;
                if(pCurArgDesc->handler!=NULL){
                  DO(pCurArgDesc->handler(pCurArgDesc->pArgData));
                }
                break;
              }
              ++pCurArgDesc;
            }
            if(!uiValid){
              ++uiSyntaxError;
              printf("ERROR: Unknown Arg [%c] in (%s)\n", *szCurOption, *pszCurArg);
              uiValid=0;
            }
            ++szCurOption;
          }
        }
        break;
      default:
        break;
    }
    if(!uiValid){
      uiSyntaxError++;
      printf("ERROR: Unknown Arg (%s)\n", *pszCurArg);
    }
    ++pszCurArg;
  }

  if(uiSyntaxError)
  EApiStatusCode=EAPI_STATUS_INVALID_PARAMETER;
EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}
#if TEST_EEPARG

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

CmdDesc_t ArgsDesc[]={
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
    "Increases Verbosity Level\n"
    "      1\n"
    "    2\n"
    "  3\n"                                         , 
    NULL                                            ,
    0                          
  },
  {
    0x00                                            , 
    "CREATE-COM0R20M-CFG"                           , 
    &CurOptionsTest.uiCreateCOM0R20M_CFG            , 
    "Create COM0 Module Config File Template\n\tTest Me "       , 
    COM0R20M_Cfg                                    ,
    ARRAY_SIZE(COM0R20M_Cfg)
  },
};
char szCmdLine[]={
    "--CREATE-COM0R20CB-CFG\ttest -d -f -g\n"
    "--CREATE-COM0R20CB-CFG\ttest -dsdfgh -f -g\n"
    "--CREATE-COM0R20CB-CFG\\\"st -d -f -g\n"
    "--\\\\\\\\\"\\\\\\\"FG\ttest -d -f -g\n"
    "@Test.log\n"
};
char *DummyArgs1[]={
  "Program Name",
  "-a",
  "-s",
  "-v",
  "-q",
  "--Arg1",
  "--Arg2",
  "--CREATE-COM0R20M-CFG", "TestFile.cfg",
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
main(
    signed int siArgc, 
    const char *pszArgv[]
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  signed int  siArgcTest;
  char     **pszArgvTest;

#ifdef _DEBUG
  _CrtSetDbgFlag( _CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag());
#endif

  PrintUsage(stderr, ArgsDesc, ARRAY_SIZE(ArgsDesc));
  ParseArgs(ARRAY_SIZE(DummyArgs1) - 1, DummyArgs1 + 1, ArgsDesc, ARRAY_SIZE(ArgsDesc));
/*   printf(szCmdLine); */

  ParseArgs(siArgc - 1, pszArgv + 1, ArgsDesc, ARRAY_SIZE(ArgsDesc));

  CreateArgvArgcBuffer(szCmdLine, &pszArgvTest, &siArgcTest);



  ParseArgs(siArgcTest , pszArgvTest, ArgsDesc, ARRAY_SIZE(ArgsDesc));

/*   for(siCharCnt=siArgcTest;-- siCharCnt ; ){ printf("ARG[%02i]=%s\n", siCharCnt, pszArgvTest[siCharCnt]); } */
  free(pszArgvTest);

  exit(EApiStatusCode);
}

#endif
