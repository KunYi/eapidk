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
 *I  File Name            : EeePProg.c
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

const char cszTitle[]= 
  "+=============================================================================+\n"
  "| EeePProg.exe  Copyright (C) Kontron Embedded Modules GmbH 2010   V %u.%u.%04u |\n"
  "+=============================================================================+\n"
  "\n"
;

const char syntaxErrMes[]  = "Syntax error / Use -h for info";


Options_t CurOptions;

ArgDesc_t  COM0R20M_Cfg[]={
  {
  &CurOptions.szCOM0R20M_Cfg_File        ,
  sizeof(CurOptions.szCOM0R20M_Cfg_File) ,
  "<Filename|stdout>  Destination File"  ,
  StringArg
  },
};
ArgDesc_t  COM0R20M_Img[]={
  {
  &CurOptions.szCOM0R20M_SCfg_File        ,
  sizeof(CurOptions.szCOM0R20M_SCfg_File) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
  {
  &CurOptions.szCOM0R20M_Img_File        ,
  sizeof(CurOptions.szCOM0R20M_Img_File) ,
  "<Filename>  Destination File"         ,
  StringArg
  },
};
ArgDesc_t  COM0R20M_EEP[]={
  {
  &CurOptions.szCOM0R20M_S2Cfg_File        ,
  sizeof(CurOptions.szCOM0R20M_S2Cfg_File) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
};
ArgDesc_t  COM0R20CB_Cfg[]={
  {
  &CurOptions.szCOM0R20CB_Cfg_File       ,
  sizeof(CurOptions.szCOM0R20CB_Cfg_File),
  "<Filename|stdout>  Destination File"  ,
  StringArg
  },
};
ArgDesc_t  COM0R20CB_Img[]={
  {
  &CurOptions.szCOM0R20CB_SCfg_File        ,
  sizeof(CurOptions.szCOM0R20CB_SCfg_File) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
  {
  &CurOptions.szCOM0R20CB_Img_File       ,
  sizeof(CurOptions.szCOM0R20CB_Img_File),
  "<Filename>  Destination File"          ,
  StringArg
  },
};
ArgDesc_t  COM0R20CB_EEP[]={
  {
  &CurOptions.szCOM0R20CB_S2Cfg_File        ,
  sizeof(CurOptions.szCOM0R20CB_S2Cfg_File) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
};
ArgDesc_t  EeePExpEEP_Cfg[]={
  {
  &CurOptions.szEeePExpEEP_Cfg_File        ,
  sizeof(CurOptions.szEeePExpEEP_Cfg_File) ,
  "<Filename|stdout>  Destination File"  ,
  StringArg
  },
};
ArgDesc_t  EeePExpEEP_Img[]={
  {
  &CurOptions.szEeePExpEEP_SCfg_File        ,
  sizeof(CurOptions.szEeePExpEEP_SCfg_File) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
  {
  &CurOptions.szEeePExpEEP_Img_File        ,
  sizeof(CurOptions.szEeePExpEEP_Img_File) ,
  "<Filename>  Destination File"            ,
  StringArg
  },
};
ArgDesc_t  EeePExpEEP_EEP[]={
  {
  &CurOptions.szEeePExpEEP_S2Cfg_File        ,
  sizeof(CurOptions.szEeePExpEEP_S2Cfg_File) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
  {
  &CurOptions.ulEeePExpEEP_Img_EApiBus     ,
  sizeof(CurOptions.ulEeePExpEEP_Img_EApiBus),
  "<EApi Id>      EApi Bus Id"             ,
  NumberArg
  },
  {
  &CurOptions.ulEeePExpEEP_Img_DevAddr     ,
  sizeof(CurOptions.ulEeePExpEEP_Img_DevAddr),
  "<I2C Address>  EEPROM Device Address"   ,
  NumberArg
  },
};
ArgDesc_t  EeePExpEEP_PEEP[]={
  {
  &CurOptions.szEeePExpEEP_SBIN_File        ,
  sizeof(CurOptions.szEeePExpEEP_SBIN_File) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
  {
  &CurOptions.ulEeePExpEEP_Bin_EApiBus     ,
  sizeof(CurOptions.ulEeePExpEEP_Bin_EApiBus),
  "<EApi Id>      EApi Bus Id"             ,
  NumberArg
  },
  {
  &CurOptions.ulEeePExpEEP_Bin_DevAddr     ,
  sizeof(CurOptions.ulEeePExpEEP_Bin_DevAddr),
  "<I2C Address>  EEPROM Device Address"   ,
  NumberArg
  },
};
ArgDesc_t  COM0R20CB_IMG[]={
  {
  &CurOptions.szCOM0R20CBEEP_To_Img_FName        ,
  sizeof(CurOptions.szCOM0R20CBEEP_To_Img_FName) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
};
ArgDesc_t  COM0R20M_IMG[]={
  {
  &CurOptions.szCOM0R20MEEP_To_Img_FName        ,
  sizeof(CurOptions.szCOM0R20MEEP_To_Img_FName) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
};
ArgDesc_t  EeePExpEEP_IMG[]={
  {
  &CurOptions.szEeePExpEEP_To_Img_FName        ,
  sizeof(CurOptions.szEeePExpEEP_To_Img_FName) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
  {
  &CurOptions.ulEeePExpEEP_To_Img_EApiBus     ,
  sizeof(CurOptions.ulEeePExpEEP_To_Img_EApiBus),
  "<EApi Id>      EApi Bus Id"             ,
  NumberArg
  },
  {
  &CurOptions.ulEeePExpEEP_To_Img_DevAddr     ,
  sizeof(CurOptions.ulEeePExpEEP_To_Img_DevAddr),
  "<I2C Address>  EEPROM Device Address"   ,
  NumberArg
  },
};
ArgDesc_t  COM0R20CB_PEEP[]={
  {
  &CurOptions.szCOM0R20CB_SBIN_File        ,
  sizeof(CurOptions.szCOM0R20CB_SBIN_File) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
};
ArgDesc_t  COM0R20M_PEEP[]={
  {
  &CurOptions.szCOM0R20M_SBIN_File        ,
  sizeof(CurOptions.szCOM0R20M_SBIN_File) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
};
ArgDesc_t  GEN_LIST_DBLOCKS_FILE[]={
  {
  &CurOptions.szGEN_List_DBlocks_File        ,
  sizeof(CurOptions.szGEN_List_DBlocks_File) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
};
ArgDesc_t  GEN_LIST_DBLOCKS_EEP[]={
  {
  &CurOptions.ulEEP_Img_EApiBus     ,
  sizeof(CurOptions.ulEEP_Img_EApiBus),
  "<EApi Id>      EApi Bus Id"             ,
  NumberArg
  },
  {
  &CurOptions.ulEEP_Img_DevAddr     ,
  sizeof(CurOptions.ulEEP_Img_DevAddr),
  "<I2C Address>  EEPROM Device Address"   ,
  NumberArg
  },
};

CmdDesc_t ArgsDesc[]={
  {
    'q'                                             , 
    "quiet"                                         , 
    &CurOptions.uiQuiet                             , 
    "Minimises Output"                              , 
    NULL                                            ,
    0                          
  },
  {
    'h'                                             , 
    "help"                                          , 
    &CurOptions.uiHelp                              , 
    "Print this usage message"                      , 
    NULL                                            ,
    0                          
  },
  {
    '?'                                             , 
    NULL                                            , 
    &CurOptions.uiHelp                              , 
    "Print this usage message"                      , 
    NULL                                            ,
    0                          
  },
  {
    'v'                                             , 
    "verbose"                                       , 
    &CurOptions.uiVerbose                           , 
    "Increases Verbosity Level"                     , 
    NULL                                            ,
    0                          
  },
  {
    0x00                                            , 
    "CREATE-COM0R20M-CFG"                           , 
    &CurOptions.uiCreateCOM0R20M_CFG                , 
    "Create COM0 Module Config File Template"       , 
    COM0R20M_Cfg                                    ,
    ARRAY_SIZE(COM0R20M_Cfg)
  },
  {
    0x00                                            , 
    "CREATE-COM0R20M-IMG"                           , 
    &CurOptions.uiCreateCOM0R20M_IMG                , 
    "Create COM0 Module Binary File"                , 
    COM0R20M_Img                                    ,
    ARRAY_SIZE(COM0R20M_Img)
  },
  {
    0x00                                            , 
    "CREATE-COM0R20M-EEP"                           , 
    &CurOptions.uiCreateCOM0R20M_EEP                , 
    "Create COM0 Module Content and Program over EApi", 
    COM0R20M_EEP                                    ,
    ARRAY_SIZE(COM0R20M_EEP)
  },
  {
    0x00, 
    "CREATE-COM0R20CB-CFG" , 
    &CurOptions.uiCreateCOM0R20CB_CFG , 
    "Create COM0 Carrier Config File Template"      , 
    COM0R20CB_Cfg                                   ,
    ARRAY_SIZE(COM0R20CB_Cfg)
  },
  {
    0x00                                            , 
    "CREATE-COM0R20CB-EEP"                          , 
    &CurOptions.uiCreateCOM0R20CB_EEP               , 
    "Create COM0 Carrier Content and Program over EApi", 
    COM0R20CB_EEP                                   ,
    ARRAY_SIZE(COM0R20CB_EEP)
  },
  {
    0x00                                            , 
    "CREATE-COM0R20CB-IMG"                          , 
    &CurOptions.uiCreateCOM0R20CB_IMG               , 
    "Create COM0 Carrier Binary File"               , 
    COM0R20CB_Img                                   ,
    ARRAY_SIZE(COM0R20CB_Img)
  },
  {
    0x00                                            , 
    "CREATE-EeePExpEEP-CFG"                         , 
    &CurOptions.uiCreateEeePExpEEP_CFG              , 
    "Create EeeP Expansion EEP Config File Template", 
    EeePExpEEP_Cfg                                  ,
    ARRAY_SIZE(EeePExpEEP_Cfg)
  },
  {
    0x00                                            , 
    "CREATE-EeePExpEEP-IMG"                         , 
    &CurOptions.uiCreateEeePExpEEP_IMG              , 
    "Create EeeP Expansion EEP Binary File"         , 
    EeePExpEEP_Img                                  ,
    ARRAY_SIZE(EeePExpEEP_Img)
  },
  {
    0x00                                            , 
    "CREATE-EeePExpEEP-EEP"                         , 
    &CurOptions.uiCreateEeePExpEEP_EEP              , 
    "Create EeeP Expansion EEP Image and Program over EApi", 
    EeePExpEEP_EEP                                  ,
    ARRAY_SIZE(EeePExpEEP_EEP)
  },
  {
    0x00                                            , 
    "PROGRAM-EeePExpEEP-EEP"                        , 
    &CurOptions.uiProgramEeePExpEEP_EEP             , 
    "Program EeeP Expansion EEP Image file over EApi", 
    EeePExpEEP_PEEP                                  ,
    ARRAY_SIZE(EeePExpEEP_PEEP)
  },
  {
    0x00                                            , 
    "PROGRAM-COM0R20CB-EEP"                         , 
    &CurOptions.uiProgramCOM0R20CB_EEP              , 
    "Program COM0 R2.0 Carrier Board EEP Image file over EApi", 
    COM0R20CB_PEEP                                  ,
    ARRAY_SIZE(COM0R20CB_PEEP)
  },
  {
    0x00                                            , 
    "PROGRAM-COM0R20M-EEP"                          , 
    &CurOptions.uiProgramCOM0R20M_EEP               , 
    "Program COM0 R2.0 Module EEP Image file over EApi", 
    COM0R20M_PEEP                                   ,
    ARRAY_SIZE(COM0R20M_PEEP)
  },
  {
    0x00                                                , 
    "SAVE-EeePExpEEP-IMG"                               , 
    &CurOptions.uiStoreEeePExpEEP_EEP                   , 
    "Stores EeeP Expansion EEP to Image file over EApi" , 
    EeePExpEEP_IMG                                      ,
    ARRAY_SIZE(EeePExpEEP_IMG)
  },
  {
    0x00                                                , 
    "SAVE-COM0R20CB-IMG"                                , 
    &CurOptions.uiStoreCOM0R20CB_EEP                    ,
    "Stores COM0 R2.0 Carrier Board EEP to Image file over EApi", 
    COM0R20CB_IMG                                       ,
    ARRAY_SIZE(COM0R20CB_IMG )
  },
  {
    0x00                                                ,
    "SAVE-COM0R20M-IMG"                                 ,
    &CurOptions.uiStoreCOM0R20M_EEP                     ,
    "Stores COM0 R2.0 Module EEP to Image file over EApi", 
    COM0R20M_IMG                                       ,
    ARRAY_SIZE(COM0R20M_IMG)
  },
  {
    0x00                                            , 
    "LIST-DBLOCKS-IMG"                              , 
    &CurOptions.uiListDBlocks_IMG                   , 
    "Lists Dynamic Blocks in Binary Image file"     , 
    GEN_LIST_DBLOCKS_FILE                           ,
    ARRAY_SIZE(GEN_LIST_DBLOCKS_FILE)
  },
  {
    0x00                                            , 
    "LIST-DBLOCKS-EEP"                              , 
    &CurOptions.uiListDBlocks_EEP                   , 
    "Lists Dynamic Blocks in Binary Image file"     , 
    GEN_LIST_DBLOCKS_EEP                           ,
    ARRAY_SIZE(GEN_LIST_DBLOCKS_EEP)
  },
  {
    0x00                                            , 
    "LIST-DBLOCKS-COM0R20CBEEP"                    , 
    &CurOptions.uiListDBlocks_COM0R20_CB_EEP        , 
    "Lists Dynamic Blocks in COM0 R2.0 Carrier Board EEPROM", 
    NULL                                            ,
    0                                 
  },
  {
    0x00                                           , 
    "LIST-DBLOCKS-COM0R20MEEP"                    , 
    &CurOptions.uiListDBlocks_COM0R20_M_EEP        , 
    "Lists Dynamic Blocks in COM0 R2.0 Module EEPROM", 
    NULL                                            ,
    0                                 
  },
};

EApiStatusCode_t
CreateTxtFilePtr(
    const char *Destination,
    FILE **     FilePtr
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  if(!strcmp(Destination, "stdout")){
     *FilePtr=stdout;
  }else if(!strcmp(Destination, "stderr")){
     *FilePtr=stderr;
  }else {
    *FilePtr=fopen(Destination, "w");
    EAPI_APP_RETURN_ERROR_IF_S(
         CreateTxtFilePtr,
         (FilePtr==NULL),
         EAPI_STATUS_WRITE_ERROR
      );
  }
ErrorExit:
  return EApiStatusCode;
}
EApiStatusCode_t
FreeFilePtr(
    FILE **     FilePtr
    )
{
  FILE *     LclFilePtr=*FilePtr;
  if(LclFilePtr!=stdout&&LclFilePtr!=stderr&&LclFilePtr!=NULL){
    fclose(LclFilePtr);
  };
  *FilePtr=NULL;
  return EAPI_STATUS_SUCCESS;
}
#define FREE_BUFFER(x) \
      if(x!=NULL){\
          free(x);\
          x=NULL;\
      }
#define FREE_STREAM(x) \
          FreeFilePtr(&x)

  




#define DO_MAIN(x) \
  EApiStatusCode=x;\
  if(!EAPI_STATUS_TEST_OK(EApiStatusCode)){ \
    EAPI_FORMATED_MES('E', main, EApiStatusCode, #x);\
    goto ErrorExit;\
  }

/*
// Create Block Content
*/
int 
__cdecl 
main(
    signed int argc,
    const char **argv
  )
{
  EeePHandel_t BHandel;
  FILE *lclStream=NULL;
  EApiStatusCode_t EApiStatusCode;
  DO_MAIN(EApiLibInitialize());

  EApiStatusCode=ParseArgs(argc - 1, argv + 1, ArgsDesc, ARRAY_SIZE(ArgsDesc));
  switch(EApiStatusCode){
    case EAPI_STATUS_INVALID_PARAMETER:
      printf("%s", syntaxErrMes);
      exit(EApiStatusCode);
      break;
    case EAPI_STATUS_SUCCESS:
      break;
    default:
      EAPI_FORMATED_MES('E', main, EApiStatusCode, TEXT("ParseArgs(argc, argv, ArgsDesc, ARRAY_SIZE(ArgsDesc))"));
      exit(EApiStatusCode);
      break;
  }

  if(!CurOptions.uiQuiet){
    fprintf(stderr, cszTitle, APP_VERSION, APP_REVISION, APP_BUILD);
  }

  if(CurOptions.uiHelp){
    PrintUsage(stderr, ArgsDesc, ARRAY_SIZE(ArgsDesc));
    exit(EApiStatusCode);
  }
  /*
   *
   */
  if(CurOptions.uiCreateCOM0R20CB_EEP){
    DO_MAIN(EeeP_CreateCOM0R20_CBImage(
          &BHandel                              ,
          CurOptions.szCOM0R20CB_S2Cfg_File
        ));
    DO_MAIN(EeePWriteBufferToEEP(BHandel, EAPI_ID_I2C_EXTERNAL, COM0R20_CB_EEP_DEV_ADDR));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiProgramCOM0R20CB_EEP){
    DO_MAIN(EeePReadBufferFromFile(
          &BHandel                              ,
          CurOptions.szCOM0R20CB_SBIN_File
        ));
    if(memcmp(((COM0R20_CB_t *)BHandel)->GenId, COM0R20_CB_HEADER_ID, sizeof(COM0R20_CB_HEADER_ID)-1)){
      EAPI_APP_RETURN_ERROR(
          main,
          EAPI_STATUS_ERROR,
          TEXT("Not Valid COM0 R2.0 Carrier Board Image")
        );
    }
    DO_MAIN(EeePWriteBufferToEEP(BHandel, EAPI_ID_I2C_EXTERNAL, COM0R20_CB_EEP_DEV_ADDR));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiCreateCOM0R20M_EEP){
    DO_MAIN(EeeP_CreateCOM0R20_MEEPImage(
          &BHandel                              ,
          CurOptions.szCOM0R20M_S2Cfg_File
        ));
    DO_MAIN(EeePWriteBufferToEEP(BHandel, EAPI_ID_I2C_EXTERNAL, COM0R20_M_EEP_DEV_ADDR));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiProgramCOM0R20M_EEP){
    DO_MAIN(EeePReadBufferFromFile(
          &BHandel                              ,
          CurOptions.szCOM0R20M_SBIN_File
        ));
    if(memcmp(((COM0R20_M_t *)BHandel)->GenId, COM0R20_M_HEADER_ID, sizeof(COM0R20_M_HEADER_ID)-1)){
      EAPI_APP_RETURN_ERROR(
          main,
          EAPI_STATUS_ERROR,
          TEXT("Not Valid COM0 R2.0 Module Image")
        );
    }
    DO_MAIN(EeePWriteBufferToEEP(BHandel, EAPI_ID_I2C_EXTERNAL, COM0R20_M_EEP_DEV_ADDR));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiCreateCOM0R20CB_IMG){
    DO_MAIN(EeeP_CreateCOM0R20_CBImage(
          &BHandel                              ,
          CurOptions.szCOM0R20CB_SCfg_File
        ));
    DO_MAIN(EeePWriteBufferToFile(BHandel, CurOptions.szCOM0R20CB_Img_File));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiCreateCOM0R20M_IMG){
    DO_MAIN(EeeP_CreateCOM0R20_MEEPImage(
          &BHandel                              ,
          CurOptions.szCOM0R20M_SCfg_File
        ));
    DO_MAIN(EeePWriteBufferToFile(BHandel, CurOptions.szCOM0R20M_Img_File));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiCreateEeePExpEEP_IMG){
    DO_MAIN(EeeP_CreateEeePExtEEPImage(
          &BHandel                              ,
          CurOptions.szEeePExpEEP_SCfg_File
        ));
    DO_MAIN(EeePWriteBufferToFile(BHandel, CurOptions.szEeePExpEEP_Img_File));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiCreateEeePExpEEP_EEP){
    DO_MAIN(EeeP_CreateEeePExtEEPImage(
          &BHandel                              ,
          CurOptions.szEeePExpEEP_S2Cfg_File
        ));
    DO_MAIN(EeePWriteBufferToEEP(
            BHandel, 
            (uint16_t)CurOptions.ulEeePExpEEP_Img_EApiBus, 
            (uint16_t)CurOptions.ulEeePExpEEP_Img_DevAddr
        ));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiProgramEeePExpEEP_EEP){
    DO_MAIN(EeePReadBufferFromFile(
          &BHandel                              ,
          CurOptions.szEeePExpEEP_SBIN_File
        ));
    if(memcmp(((Exp_EEP_t *)BHandel)->GenId, EEEP_EXP_HEADER_ID, sizeof(EEEP_EXP_HEADER_ID)-1)){
      EAPI_APP_RETURN_ERROR(
          main,
          EAPI_STATUS_ERROR,
          TEXT("Not Valid EeeP Extended EEP Image")
        );
    }
    DO_MAIN(EeePWriteBufferToEEP(
            BHandel, 
            (uint16_t)CurOptions.ulEeePExpEEP_Bin_EApiBus, 
            (uint16_t)CurOptions.ulEeePExpEEP_Bin_DevAddr
        ));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiListDBlocks_IMG){
    DO_MAIN(EeePReadBufferFromFile(
          &BHandel                              ,
          CurOptions.szGEN_List_DBlocks_File
        ));
    DO_MAIN(EeePListBlocks( BHandel, 0));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiListDBlocks_EEP){
    DO_MAIN(EeePReadBufferFromEEP(
            &BHandel, 
            (uint16_t)CurOptions.ulEEP_Img_EApiBus, 
            (uint16_t)CurOptions.ulEEP_Img_DevAddr
        ));
    DO_MAIN(EeePListBlocks( BHandel, 0));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  if(CurOptions.uiListDBlocks_COM0R20_CB_EEP){
    DO_MAIN(EeePReadBufferFromEEP(
            &BHandel, 
            EAPI_ID_I2C_EXTERNAL, COM0R20_CB_EEP_DEV_ADDR
        ));
    DO_MAIN(EeePListBlocks( BHandel, 0));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  if(CurOptions.uiListDBlocks_COM0R20_M_EEP){
    DO_MAIN(EeePReadBufferFromEEP(
            &BHandel, 
            EAPI_ID_I2C_EXTERNAL, COM0R20_M_EEP_DEV_ADDR
        ));
    DO_MAIN(EeePListBlocks( BHandel, 0));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  if(CurOptions.uiStoreEeePExpEEP_EEP){
    DO_MAIN(EeePReadBufferFromEEP(
            &BHandel, 
            (uint16_t)CurOptions.ulEeePExpEEP_To_Img_EApiBus, 
            (uint16_t)CurOptions.ulEeePExpEEP_To_Img_DevAddr
        ));
    DO_MAIN(EeePWriteBufferToFile(BHandel, CurOptions.szEeePExpEEP_To_Img_FName));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  if(CurOptions.uiStoreCOM0R20CB_EEP){
    DO_MAIN(EeePReadBufferFromEEP(
            &BHandel, 
            EAPI_ID_I2C_EXTERNAL, COM0R20_CB_EEP_DEV_ADDR
        ));
    DO_MAIN(EeePWriteBufferToFile(BHandel, CurOptions.szCOM0R20CBEEP_To_Img_FName));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  if(CurOptions.uiStoreCOM0R20M_EEP){
    DO_MAIN(EeePReadBufferFromEEP(
            &BHandel, 
            EAPI_ID_I2C_EXTERNAL, COM0R20_M_EEP_DEV_ADDR
        ));
    DO_MAIN(EeePWriteBufferToFile(BHandel, CurOptions.szCOM0R20MEEP_To_Img_FName));
    DO_MAIN(EeePFreeBuffer(&BHandel));
  }
  /*
   *
   */
  if(CurOptions.uiCreateCOM0R20CB_CFG){
    DO_MAIN(CreateTxtFilePtr(CurOptions.szCOM0R20CB_Cfg_File, &lclStream));
    DO_MAIN(EeeP_CreateCOM0R20_CBCfg(lclStream));
    FREE_STREAM(lclStream);
  }
  /*
   *
   */
  if(CurOptions.uiCreateCOM0R20M_CFG){
    DO_MAIN(CreateTxtFilePtr(CurOptions.szCOM0R20M_Cfg_File, &lclStream));
    DO_MAIN(EeeP_CreateCOM0R20_MEEPCfg(lclStream));
    FREE_STREAM(lclStream);
  }
  /*
   *
   */
  if(CurOptions.uiCreateEeePExpEEP_CFG){
    DO_MAIN(CreateTxtFilePtr(CurOptions.szEeePExpEEP_Cfg_File, &lclStream));
    DO_MAIN(EeeP_CreateEeePExtEEPCfg(lclStream));
    FREE_STREAM(lclStream);
  }
  
  DO_MAIN(EApiLibUnInitialize());
ErrorExit:
  exit(EApiStatusCode);

}
