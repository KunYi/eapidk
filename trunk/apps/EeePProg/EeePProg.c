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
};

EApiStatusCode_t
CreateTxtFilePtr(
    const char *Source  , 
    FILE **     FilePtr
    )
{
  if(!_stricmp(Source, "stdout")){
     *FilePtr=stdout;
     return EAPI_STATUS_SUCCESS;
  }else {
     *FilePtr=fopen(Source, "w");
     return ((FilePtr==NULL)?EAPI_STATUS_ERROR:EAPI_STATUS_SUCCESS);
  }
}
#define FREE_BUFFER(x) \
      if(x!=NULL){\
          free(x);\
          x=NULL;\
      }
#define FREE_STREAM(x) \
      if(x!=stdout)\
          fclose(x);\
      x=NULL;

  



/*   EAPI_printf(TEXT("#####\n")TEXT("#\t%s\n")TEXT("#####\n"), TEXT(#x));\ */

#define DO_MAIN(x) \
  EApiStatusCode=x;\
  if(!EAPI_STATUS_TEST_OK(EApiStatusCode)){ \
    EAPI_printf(TEXT("ERROR: %s\n"), TEXT(#x));\
    return EApiStatusCode \
  }

//
// Create Block Content
//
int 
__cdecl 
main(
    signed int argc,
    char **argv
  )
{
  EeePHandel_t BHandel;
  FILE *lclStream=NULL;
  EApiStatusCode_t EApiStatusCode;

  DO(ParseArgs(argc, argv, ArgsDesc, ARRAY_SIZE(ArgsDesc)));
  if(!CurOptions.uiQuiet){
    fprintf(stderr, cszTitle, APP_VERSION, APP_REVISION, APP_BUILD);
  }

  if(CurOptions.uiHelp){
    PrintUsage(stderr, ArgsDesc, ARRAY_SIZE(ArgsDesc));
    exit(EApiStatusCode);
  }
  //
  //
  //
  if(CurOptions.uiCreateCOM0R20CB_EEP){
    DO(EeeP_CreateCOM0R20_CBImage(
          &BHandel                              ,
          CurOptions.szCOM0R20CB_S2Cfg_File
        ));
    DO(EeePWriteBufferToEEP(BHandel, EAPI_ID_I2C_EXTERNAL, 0xAE));
    DO(EeePFreeBuffer(&BHandel));
  }
  //
  //
  //
  if(CurOptions.uiCreateCOM0R20M_EEP){
    DO(EeeP_CreateCOM0R20_CBImage(
          &BHandel                              ,
          CurOptions.szCOM0R20M_S2Cfg_File
        ));
    DO(EeePWriteBufferToEEP(BHandel, EAPI_ID_I2C_EXTERNAL, 0xA0));
    DO(EeePFreeBuffer(&BHandel));
  }
  //
  //
  //
  if(CurOptions.uiCreateCOM0R20CB_IMG){
    DO(EeeP_CreateCOM0R20_CBImage(
          &BHandel                              ,
          CurOptions.szCOM0R20CB_SCfg_File
        ));
    DO(EeePWriteBufferToFile(BHandel, CurOptions.szCOM0R20CB_Img_File));
    DO(EeePFreeBuffer(&BHandel));
  }
  //
  //
  //
  if(CurOptions.uiCreateCOM0R20M_IMG){
    DO(EeeP_CreateCOM0R20_MEEPImage(
          &BHandel                              ,
          CurOptions.szCOM0R20M_SCfg_File
        ));
    DO(EeePWriteBufferToFile(BHandel, CurOptions.szCOM0R20M_Img_File));
    DO(EeePFreeBuffer(&BHandel));
  }
  //
  //
  //
  if(CurOptions.uiCreateEeePExpEEP_IMG){
    DO(EeeP_CreateEeePExtEEPImage(
          &BHandel                              ,
          CurOptions.szEeePExpEEP_SCfg_File
        ));
    DO(EeePWriteBufferToFile(BHandel, CurOptions.szEeePExpEEP_Img_File));
    DO(EeePFreeBuffer(&BHandel));
  }
  //
  //
  //
  if(CurOptions.uiCreateEeePExpEEP_EEP){
    DO(EeeP_CreateEeePExtEEPImage(
          &BHandel                              ,
          CurOptions.szEeePExpEEP_S2Cfg_File
        ));
    DO(EeePWriteBufferToFile(BHandel, CurOptions.szEeePExpEEP_Img_File));
    DO(EeePWriteBufferToEEP(
            BHandel, 
            (uint16_t)CurOptions.ulEeePExpEEP_Img_EApiBus, 
            (uint16_t)CurOptions.ulEeePExpEEP_Img_DevAddr
        ));
    DO(EeePFreeBuffer(&BHandel));
  }
  //
  //
  //
  if(CurOptions.uiCreateCOM0R20CB_CFG){
    DO(CreateTxtFilePtr(CurOptions.szCOM0R20CB_Cfg_File, &lclStream));
    DO(EeeP_CreateCOM0R20_CBCfg(lclStream));
    FREE_STREAM(lclStream);
  }
  //
  //
  //
  if(CurOptions.uiCreateCOM0R20M_CFG){
    DO(CreateTxtFilePtr(CurOptions.szCOM0R20M_Cfg_File, &lclStream));
    DO(EeeP_CreateCOM0R20_MEEPCfg(lclStream));
    FREE_STREAM(lclStream);
  }
  //
  //
  //
  if(CurOptions.uiCreateEeePExpEEP_CFG){
    DO(CreateTxtFilePtr(CurOptions.szEeePExpEEP_Cfg_File, &lclStream));
    DO(EeeP_CreateEeePExtEEPCfg(lclStream));
    FREE_STREAM(lclStream);
  }
  
  exit(EApiStatusCode);

}
