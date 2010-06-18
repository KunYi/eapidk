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
 *I  File Name            : EeePCfg.c
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

ElementHandler_t COM0PCIe_Element;
ElementHandler_t SMBIOS_CE_Element;

ElementHelpTxt_t COM0PCIe_Help;
ElementHelpTxt_t SMBIOS_CE_Help;
/*  */

Handlers_t  COM0PCIe_Element_funcs ={ COM0PCIe_Element , GenClear_Element , COM0PCIe_Help   , No_Default_Txt};
Handlers_t  SMBIOS_CE_Element_funcs={ SMBIOS_CE_Element, GenClear_Element , SMBIOS_CE_Help  , No_Default_Txt};

TokenDesc_t  SmbiosStructureTypesTokens[]={
  {"BIOS_INFORMATION"                               ,  SMBIOS_TypeBIOS_INFORMATION                    },
  {"SYSTEM_INFORMATION"                             ,  SMBIOS_TypeSYSTEM_INFORMATION                  },
  {"BASE_BOARD_(OR_MODULE)_INFORMATION"             ,  SMBIOS_TypeBASE_BOARD_MODULE_INFORMATION       },
  {"SYSTEM_ENCLOSURE_OR_CHASSIS"                    ,  SMBIOS_TypeSYSTEM_ENCLOSURE_OR_CHASSIS         },
  {"PROCESSOR_INFORMATION"                          ,  SMBIOS_TypePROCESSOR_INFORMATION               },
  {"MEMORY_CONTROLLER_INFORMATION"                  ,  SMBIOS_TypeMEMORY_CONTROLLER_INFORMATION       },
  {"MEMORY_MODULE_INFORMATION"                      ,  SMBIOS_TypeMEMORY_MODULE_INFORMATION           },
  {"CACHE_INFORMATION"                              ,  SMBIOS_TypeCACHE_INFORMATION                   },
  {"PORT_CONNECTOR_INFORMATION"                     ,  SMBIOS_TypePORT_CONNECTOR_INFORMATION          },
  {"SYSTEM_SLOTS"                                   ,  SMBIOS_TypeSYSTEM_SLOTS                        },
  {"ON_BOARD_DEVICES_INFORMATION"                   ,  SMBIOS_TypeON_BOARD_DEVICES_INFORMATION        },
  {"OEM_STRINGS"                                    ,  SMBIOS_TypeOEM_STRINGS                         },
  {"SYSTEM_CONFIGURATION_OPTIONS"                   ,  SMBIOS_TypeSYSTEM_CONFIGURATION_OPTIONS        },
  {"BIOS_LANGUAGE_INFORMATION"                      ,  SMBIOS_TypeBIOS_LANGUAGE_INFORMATION           },
  {"GROUP_ASSOCIATIONS"                             ,  SMBIOS_TypeGROUP_ASSOCIATIONS                  },
  {"SYSTEM_EVENT_LOG"                               ,  SMBIOS_TypeSYSTEM_EVENT_LOG                    },
  {"PHYSICAL_MEMORY_ARRAY"                          ,  SMBIOS_TypePHYSICAL_MEMORY_ARRAY               },
  {"MEMORY_DEVICE"                                  ,  SMBIOS_TypeMEMORY_DEVICE                       },
  {"32_BIT_MEMORY_ERROR_INFORMATION"                ,  SMBIOS_Type32_BIT_MEMORY_ERROR_INFORMATION     },
  {"MEMORY_ARRAY_MAPPED_ADDRESS"                    ,  SMBIOS_TypeMEMORY_ARRAY_MAPPED_ADDRESS         },
  {"MEMORY_DEVICE_MAPPED_ADDRESS"                   ,  SMBIOS_TypeMEMORY_DEVICE_MAPPED_ADDRESS        },
  {"BUILT_IN_POINTING_DEVICE"                       ,  SMBIOS_TypeBUILT_IN_POINTING_DEVICE            },
  {"PORTABLE_BATTERY"                               ,  SMBIOS_TypePORTABLE_BATTERY                    },
  {"SYSTEM_RESET"                                   ,  SMBIOS_TypeSYSTEM_RESET                        },
  {"HARDWARE_SECURITY"                              ,  SMBIOS_TypeHARDWARE_SECURITY                   },
  {"SYSTEM_POWER_CONTROLS"                          ,  SMBIOS_TypeSYSTEM_POWER_CONTROLS               },
  {"VOLTAGE_PROBE"                                  ,  SMBIOS_TypeVOLTAGE_PROBE                       },
  {"COOLING_DEVICE"                                 ,  SMBIOS_TypeCOOLING_DEVICE                      },
  {"TEMPERATURE_PROBE"                              ,  SMBIOS_TypeTEMPERATURE_PROBE                   },
  {"ELECTRICAL_CURRENT_PROBE"                       ,  SMBIOS_TypeELECTRICAL_CURRENT_PROBE            },
  {"OUT_OF_BAND_REMOTE_ACCESS"                      ,  SMBIOS_TypeOUT_OF_BAND_REMOTE_ACCESS           },
  {"BOOT_INTEGRITY_SERVICES_(BIS)_ENTRY_POINT"      ,  SMBIOS_TypeBOOT_INTEGRITY_SERVICES_ENTRY_POINT },
  {"SYSTEM_BOOT_INFORMATION"                        ,  SMBIOS_TypeSYSTEM_BOOT_INFORMATION             },
  {"64_BIT_MEMORY_ERROR_INFORMATION"                ,  SMBIOS_Type64_BIT_MEMORY_ERROR_INFORMATION     },
  {"MANAGEMENT_DEVICE"                              ,  SMBIOS_TypeMANAGEMENT_DEVICE                   },
  {"MANAGEMENT_DEVICE_COMPONENT"                    ,  SMBIOS_TypeMANAGEMENT_DEVICE_COMPONENT         },
  {"MANAGEMENT_DEVICE_THRESHOLD_DATA"               ,  SMBIOS_TypeMANAGEMENT_DEVICE_THRESHOLD_DATA    },
  {"MEMORY_CHANNEL"                                 ,  SMBIOS_TypeMEMORY_CHANNEL                      },
  {"IPMI_DEVICE_INFORMATION"                        ,  SMBIOS_TypeIPMI_DEVICE_INFORMATION             },
  {"SYSTEM_POWER_SUPPLY"                            ,  SMBIOS_TypeSYSTEM_POWER_SUPPLY                 },
  {"INACTIVE"                                       ,  SMBIOS_TypeINACTIVE                            },
  {"END_OF_TABLE"                                   ,  SMBIOS_TypeEND_OF_TABLE                        },
};
PCFG_TOKEN_LIST_DESC(SmbiosStructureTypesTL, SmbiosStructureTypesTokens);

TokenDesc_t  SmbiosBoardTypesTokens[]={
  {"Unknown"	                , SMBIOS_BoardType_Unknown                },
  {"Other"	                  , SMBIOS_BoardType_Other                  },
  {"ServerBlade"	            , SMBIOS_BoardType_ServerBlade            },
  {"ConnectivitySwitch"	      , SMBIOS_BoardType_ConnectivitySwitch     },
  {"SystemManagementModule"	  , SMBIOS_BoardType_SystemManagementModule },
  {"ProcessorModule"	        , SMBIOS_BoardType_ProcessorModule        },
  {"IO_Module"	              , SMBIOS_BoardType_IO_Module              },
  {"Memory_Module"	          , SMBIOS_BoardType_Memory_Module          },
  {"DaughterBoard"	          , SMBIOS_BoardType_DaughterBoard          },
  {"Motherboard"	            , SMBIOS_BoardType_Motherboard            },
  {"ProcessorMemory_Module"	  , SMBIOS_BoardType_ProcessorMemory_Module },
  {"Interconnect_Board"	      , SMBIOS_BoardType_Interconnect_Board     },
};
PCFG_TOKEN_LIST_DESC(SmbiosBoardTypesTL, SmbiosBoardTypesTokens);

EApiStatusCode_t
SMBIOS_CE_Help(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream,
    const char *Indent
  )
{ 
  unsigned int i;
  pElementDesc=pElementDesc;
  fprintf(stream, "%s %s\n", Indent, "SMBios Contained Element Description");
  fprintf(stream, "%s %s\n", Indent, "  Format:");
  fprintf(stream, "%s %s\n", Indent, "    Element Type, Minimum Count, Maximum Count");
  fprintf(stream, "%s %s\n", Indent, "  Examples:");
  fprintf(stream, "%s %s\n", Indent, "    SYSTEM_POWER_SUPPLY,  1, 1");
  fprintf(stream, "%s %s\n", Indent, "    ServerBlade        ,  1, 5");
  fprintf(stream, "%s %s\n", Indent, "  Element Type Tokens:"  );
  for(i=0;i<ARRAY_SIZE(SmbiosBoardTypesTokens);i++){
    fprintf(stream, "%s     %s\n", Indent, SmbiosBoardTypesTokens[i].pszTokenList);
  }
  for(i=0;i<ARRAY_SIZE(SmbiosStructureTypesTokens);i++){
    fprintf(stream, "%s     %s\n", Indent, SmbiosStructureTypesTokens[i].pszTokenList);
  }
  fprintf(stream, "%s %s\n", Indent, "  Minimum Count:");
  fprintf(stream, "%s %s\n", Indent, "    0 - 255     ");
  fprintf(stream, "%s %s\n", Indent, "  Maximum Count:");
  fprintf(stream, "%s %s\n", Indent, "    0 - 255     ");
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
SMBIOS_CE_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void   *pElement,
    char   *pszValue
  )
{ 
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  CCElement_t *pCurElement=pElement;
  char *pszCEType, *pszMinCount, *pszMaxCount;
  unsigned long uiCEType, uiMinCount, uiMaxCount;
  pszCEType=pszValue;
  pElementDesc=pElementDesc;

  pszMinCount=strchr(pszCEType, ',');
  if(pszMinCount==NULL ){
    EApiStatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }
  *pszMinCount++='\0';
  
  pszMaxCount=strchr(pszMinCount, ',');
  if(pszMaxCount==NULL ){
    EApiStatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }
  *pszMaxCount++='\0';

  EApiStatusCode=GetTokenValueStrip(
      &SmbiosStructureTypesTL, 
      pszCEType, 
      &uiCEType
    );
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode))
    EApiStatusCode=GetTokenValueStrip(
        &SmbiosBoardTypesTL, 
        pszCEType, 
        &uiCEType
      );
  else
    uiCEType|=0x80;

  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
    printf("SMBIOS_CE_Element = Unknown Token, %s\n", pszValue);
    goto ErrorExit;
  }

  uiMinCount=ulConvertStr2NumEx(pszMinCount, NULL                  );
  uiMaxCount=ulConvertStr2NumEx(pszMaxCount, NULL                  );
  if(uiMinCount>UINT8_MAX){
    printf("SMBIOS_CE_Element = Invalid MinCount, %s\n", pszMinCount);
    EApiStatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }
  if(uiMaxCount>UINT8_MAX){
    printf("SMBIOS_CE_Element = Invalid MaxCount, %s\n", pszMaxCount);
    EApiStatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }


  pCurElement->ElementType=(uint8_t)uiCEType;
  pCurElement->MinNum=(uint8_t)uiMinCount;
  pCurElement->MaxNum=(uint8_t)uiMaxCount;
/*   PrintHexAsciiTableEx( */
/*       pCurElement,  */
/*       3,  */
/*       pCurElement,  */
/*       NULL, */
/*       HEXTBL_8BIT_ELEMENT|3 */
/*     ); */
ErrorExit:
  return EApiStatusCode;
}



TokenDesc_t  PCIeLaneWidths[]={
  {"x1"	, 1  },
  {"x2"	, 2  },
  {"x4"	, 3  },
  {"x8"	, 4  },
  {"x16", 5  },
  {"x32", 6  },
};
PCFG_TOKEN_LIST_DESC(PCIeLaneWidthsTL, PCIeLaneWidths);

TokenDesc_t  PCIeGeneration[]={
  {"Gen1"	, COM0R20_PCIe_GEN1  },
  {"Gen2"	, COM0R20_PCIe_GEN2  },
  {"Gen3"	, COM0R20_PCIe_GEN3  },
};
PCFG_TOKEN_LIST_DESC(PCIeGenerationTL, PCIeGeneration);


EApiStatusCode_t
COM0PCIe_Help(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream,
    const char *Indent
  )
{ 
  unsigned int i;
  pElementDesc=pElementDesc;
  fprintf(stream, "%s %s\n", Indent, "COM0 PCIe Port Description"                     );
  fprintf(stream, "%s %s\n", Indent, "  Format:"                                      );
  fprintf(stream, "%s %s\n", Indent, "    Starting Lane, Link Width, PCIe Generation" );
  fprintf(stream, "%s %s\n", Indent, "  Examples:"                                    );
  fprintf(stream, "%s %s\n", Indent, "     0,   x1, Gen1"                             );
  fprintf(stream, "%s %s\n", Indent, "    16,  x16, Gen2"                             );
  fprintf(stream, "%s %s\n", Indent, "  Starting Lanes:"                              );
  fprintf(stream, "%s %s\n", Indent, "    0 - 31      "                               );
  fprintf(stream, "%s %s\n", Indent, "  Link Widths Tokens:"                          );
  for(i=0;i<ARRAY_SIZE(PCIeLaneWidths);i++){
    fprintf(stream, "%s     %s\n", Indent, PCIeLaneWidths[i].pszTokenList);
  }
  fprintf(stream, "%s %s\n", Indent, "  Generations Tokens:"  );
  for(i=0;i<ARRAY_SIZE(PCIeGeneration);i++){
    fprintf(stream, "%s     %s\n", Indent, PCIeGeneration[i].pszTokenList);
  }
  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
COM0PCIe_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void          *pCurElement,
    char          *pszValue
  )
{ 
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  char *pszStartingLane, *pszWidth, *pszGen;
  unsigned long uiStartingLane, uiWidth, uiGen;
  pszStartingLane=pszValue;
  memset(pCurElement, 0x00, pElementDesc->cstElementSize);

  pszWidth=strchr(pszStartingLane, ',');
  if(pszWidth==NULL ){
    EApiStatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }
  *pszWidth++='\0';
  
  pszGen=strchr(pszWidth, ',');
  if(pszGen==NULL  ) {
    EApiStatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }
  *pszGen++='\0';

  uiStartingLane=ulConvertStr2NumEx(pszStartingLane, NULL                  );
  if(uiStartingLane>31){
    printf("COM0PCIe_Element = Invalid Starting Lane, %s\n", pszStartingLane);
    EApiStatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }

  EApiStatusCode=GetTokenValueStrip(
      &PCIeLaneWidthsTL, 
      pszWidth, 
      &uiWidth
    );
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
    printf("COM0PCIe_Element = Unknown Token, %s\n", pszWidth);
    goto ErrorExit;
  }

  EApiStatusCode=GetTokenValueStrip(
      &PCIeGenerationTL, 
      pszGen, 
      &uiGen
    );
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
    printf("COM0PCIe_Element = Unknown Token, %s\n", pszGen);
    goto ErrorExit;
  }
  if(uiStartingLane&((1<<(uiWidth - 1))-1)){
    printf("COM0PCIe_Element = Invalid Starting Lane/Width, %s/%s\n", pszStartingLane, pszWidth);
    EApiStatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }
  *(unsigned long*)pCurElement=(uiStartingLane<<16)|(uiWidth<<8)|(uiGen);
#if TEST_EEPCFG
/*   printf("COM0PCIe_Element = 0x%06lX, %s\n", *pCurElement, pszValue); */
#endif
ErrorExit:
  return EApiStatusCode;
}

   

TokenDesc_t  SasTokens[]={
  {"NotImplemented"	, 0  },
  {"SAS"            , COM0R20_SAS_CONNECTOR_PRESENT|COM0R20_SATA_SAS_DEVICE },
  {"SATA"           , COM0R20_SAS_CONNECTOR_PRESENT },
};
PCFG_TOKEN_LIST_DESC(SasTL, SasTokens);

TokenDesc_t  ImpNotImpTokens[]={
  {"NotImplemented"	, 0  },
  {"Implemented"    , 1  },
};
PCFG_TOKEN_LIST_DESC(ImpNotImpTL, ImpNotImpTokens);

TokenDesc_t  DDI1Tokens[]={
  {"NotImplemented"	, COM0R20_DDI_NOT_USED },
  {"eDisplayPort"   , COM0R20_DDI_eDispPort},
  {"DisplayPort"    , COM0R20_DDI_DispPort },
  {"HDMI/DVI"       , COM0R20_DDI_HDMI     },
  {"SDVO"           , COM0R20_DDI_SDVO     },
};
PCFG_TOKEN_LIST_DESC(DDI1TL, DDI1Tokens);

TokenDesc_t  DDI2Tokens[]={
  {"NotImplemented"	, COM0R20_DDI_NOT_USED },
  {"eDisplayPort"   , COM0R20_DDI_eDispPort},
  {"DisplayPort"    , COM0R20_DDI_DispPort },
  {"HDMI/DVI"       , COM0R20_DDI_HDMI     },
};
PCFG_TOKEN_LIST_DESC(DDI2TL, DDI2Tokens);

TokenDesc_t  DisplayInterfaceTokens[]={
  {"LVDS"	, EEEP_DISP_INT_LVDS  },
  {"SDVOB", EEEP_DISP_INT_SDVOB },
  {"SDVOC", EEEP_DISP_INT_SDVOC },
  {"DDI1" , EEEP_DISP_INT_DDI1	},
  {"DDI2" , EEEP_DISP_INT_DDI2	},
  {"DDI3" , EEEP_DISP_INT_DDI3	},
};
PCFG_TOKEN_LIST_DESC(DisplayInterfaceTL, DisplayInterfaceTokens);

TokenDesc_t  I2CBusTokens[]={
  {"I2C"	, EEEP_I2CBuSID_I2C  },
  {"SMB"	, EEEP_I2CBuSID_SMB  },
  {"LVDS" , EEEP_I2CBuSID_LVDS },
  {"DDI1" , EEEP_I2CBuSID_DDI1 },
  {"DDI2" , EEEP_I2CBuSID_DDI2 },
  {"DDI3" , EEEP_I2CBuSID_DDI3 },
  {"SDVOB", EEEP_I2CBuSID_SDVOB},
  {"SDVOC", EEEP_I2CBuSID_SDVOC},
  {"CRT"  , EEEP_I2CBuSID_CRT  },
};
PCFG_TOKEN_LIST_DESC(I2CBusTL, I2CBusTokens);

TokenDesc_t  StandardExtendedTokens[]={
  {"Extended"	, 1<<EEEP_DEVICE_TYPE_OFFSET  },
  {"Standard"	, 0<<EEEP_DEVICE_TYPE_OFFSET  },
};
PCFG_TOKEN_LIST_DESC(StandardExtendedTL, StandardExtendedTokens);



TokenDesc_t  SmbiosModuleFeatureFlagsTokens[]={
  {"IS_Motherboard"    , SMBIOS_IS_Motherboard },
  {"REQUIRES_DAUGHTER" , SMBIOS_REQ_DAUGHTER   },
  {"REMOVABLE"         , SMBIOS_REMOVABLE      },
  {"REPLACEABLE"       , SMBIOS_REPLACEABLE    },
  {"HOT_SWAP_CAPABLE"	 , SMBIOS_HOT_SWAP_CAP   },
};
PCFG_TOKEN_LIST_DESC(SmbiSmbiosModuleFeatureFlagsTL, SmbiosModuleFeatureFlagsTokens);

TokenDesc_t  SmbiosChassisTypesTokens[]={
  {"Other"                        , SMBIOS_ChassisType_Other                 },
  {"Unknown"                      , SMBIOS_ChassisType_Unknown               },
  {"Desktop"                      , SMBIOS_ChassisType_Desktop               },
  {"Low_Profile_Desktop"          , SMBIOS_ChassisType_Low_Profile_Desktop   },
  {"Pizza_Box"             	      , SMBIOS_ChassisType_Pizza_Box             },
  {"Mini_Tower"                   , SMBIOS_ChassisType_Mini_Tower            },
  {"Tower"                        , SMBIOS_ChassisType_Tower                 },
  {"Portable"                     , SMBIOS_ChassisType_Portable              },
  {"Laptop"                       , SMBIOS_ChassisType_Laptop                },
  {"Notebook"                     , SMBIOS_ChassisType_Notebook              },
  {"Hand_Held"                    , SMBIOS_ChassisType_Hand_Held             },
  {"Docking_Station"              , SMBIOS_ChassisType_Docking_Station       },
  {"All_In_One"            	      , SMBIOS_ChassisType_All_In_One            },
  {"Sub_Notebook"          	      , SMBIOS_ChassisType_Sub_Notebook          },
  {"Space_saving_Lunch_Box"	      , SMBIOS_ChassisType_Space_saving_Lunch_Box},
  {"Main_Server_Chassis"   	      , SMBIOS_ChassisType_Main_Server_Chassis   },
  {"Expansion_Chassis"            , SMBIOS_ChassisType_Expansion_Chassis     },
  {"SubChassis"            	      , SMBIOS_ChassisType_SubChassis            },
  {"Bus_Expansion_Chassis" 	      , SMBIOS_ChassisType_Bus_Expansion_Chassis },
  {"Peripheral_Chassis"    	      , SMBIOS_ChassisType_Peripheral_Chassis    },
  {"RAID_Chassis"          	      , SMBIOS_ChassisType_RAID_Chassis          },
  {"Rack_Mount_Chassis"    	      , SMBIOS_ChassisType_Rack_Mount_Chassis    },
  {"Sealed_case_PC"        	      , SMBIOS_ChassisType_Sealed_case_PC        },
  {"Multi_system_chassis"  	      , SMBIOS_ChassisType_Multi_system_chassis  },
};
PCFG_TOKEN_LIST_DESC(SmbiosChassisTypesTL, SmbiosChassisTypesTokens);

NumberRange_t ValidHandles[]={
  {0xE000, 0xFFFF, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidHandlesDesc, ValidHandles);

TokenDesc_t  IRQTokens[]={
  {"Auto"	  , 0},
  {"No_IRQ"	, 1},
  {"IRQ3"	  , 3},
  {"IRQ4"	  , 4},
  {"IRQ5"	  , 5},
  {"IRQ6"	  , 6},
  {"IRQ7"	  , 7},
  {"IRQ8"	  , 8},
  {"IRQ9"	  , 9},
  {"IRQ10"	, 10},
  {"IRQ11"	, 11},
  {"IRQ12"	, 12},
  {"IRQ13"	, 13},
  {"IRQ14"	, 14},
  {"IRQ15"	, 15},
};
PCFG_TOKEN_LIST_DESC(IRQTL, IRQTokens);

typedef struct SmbiosModule_s{
  unsigned long aulHandle         [1];
  char *        aszManuf          [1];
  char *        aszProduct        [1];
  char *        aszVersion        [1];
  char *        aszSerialNum      [1];
  char *        aszAssetTag       [1];
  unsigned long aulFeatureFlag    [5];
  char *        aszLocation       [1];
  unsigned long aulLocationHandle [1];
  unsigned long aulBoardType      [1];
  unsigned long aulInsideCrc      [1];
  unsigned long aulHandles        [20];
}SmbiosModule_t;

SmbiosModule_t COM0_SMBIOS_Module ={{0xE000},{NULL},{NULL},{NULL},{NULL},{NULL},{0},{NULL},{0},{0},{0},{0}};
SmbiosModule_t COM0_SMBIOS_Carrier={{0xE001},{NULL},{NULL},{NULL},{NULL},{NULL},{0},{NULL},{0},{0},{0},{0}};


typedef struct SmbiosSystem_s{
  unsigned long aulHandle         [1];
  char *        aszManuf          [1];
  char *        aszProduct        [1];
  char *        aszVersion        [1];
  char *        aszSerialNum      [1];
  EeePGUID_t    aUUID             [1];
  char *        aszSKU_Number     [1];
  unsigned long aulInsideCrc      [1];
  char *        aszFamily         [1];
}SmbiosSystem_t;

SmbiosSystem_t COM0_SMBIOS_System={{0xE002},{NULL},{NULL},{NULL},{NULL},{{{{0}},{{{0}}},{0}}},{NULL},{0},{NULL}};

typedef struct SmbiosChassis_s{
  unsigned long aulHandle         [1];
  char *        aszManuf          [1];
  unsigned long aulChassisType    [1];
  char *        aszVersion        [1];
  char *        aszSerialNum      [1];
  char *        aszAssetTag       [1];
  unsigned long aulOEM            [1];
  unsigned long aulHeight         [1];
  unsigned long aulNumPowerCords  [1];
  unsigned long aulInsideCrc      [1];
  CCElement_t   aCElements        [20];
}SmbiosChassis_t;

SmbiosChassis_t COM0_SMBIOS_Chassis={{0xE003},{NULL},{0},{NULL},{NULL},{NULL},{0},{0},{0},{0},{{0,0,0}}};

typedef struct EeePLFP_s{
  unsigned long aulInterface   [1];
  char *        aszFilename    [1];
  unsigned long aulInsideCrc   [1];
}EeePLFP_t;

EeePLFP_t EeeP_LFP0_Cfg;
EeePLFP_t EeeP_LFP1_Cfg;
EeePLFP_t EeeP_LFP2_Cfg;
EeePLFP_t EeeP_LFP3_Cfg;

typedef struct EeePVendorBlock_s{
  char *        aszFilename   [1];
  unsigned long aulVendorId   [1];
  unsigned long aulInsideCrc  [1];
  unsigned long aulVSBlockId  [1];
}EeePVendorBlock_t;

EeePVendorBlock_t EeeP_VendorBlock0_Cfg;
EeePVendorBlock_t EeeP_VendorBlock1_Cfg;
EeePVendorBlock_t EeeP_VendorBlock2_Cfg;
EeePVendorBlock_t EeeP_VendorBlock3_Cfg;
EeePVendorBlock_t EeeP_VendorBlock4_Cfg;
EeePVendorBlock_t EeeP_VendorBlock5_Cfg;
EeePVendorBlock_t EeeP_VendorBlock6_Cfg;

typedef struct EeePCustomBlock_s{
  unsigned long aulBlockId    [1];
  char *        aszFilename   [1];
  unsigned long aulInsideCrc  [1];
}EeePCustomBlock_t;

EeePCustomBlock_t EeeP_CustomBlock0_Cfg;
EeePCustomBlock_t EeeP_CustomBlock1_Cfg;
EeePCustomBlock_t EeeP_CustomBlock2_Cfg;
EeePCustomBlock_t EeeP_CustomBlock3_Cfg;
EeePCustomBlock_t EeeP_CustomBlock4_Cfg;
EeePCustomBlock_t EeeP_CustomBlock5_Cfg;
EeePCustomBlock_t EeeP_CustomBlock6_Cfg;

typedef struct EeePExtI2CDevice_s{
  unsigned long aulAddr      [1];
  unsigned long aulBus       [1];
  unsigned long aulDeviceType      [1];
  unsigned long aulDeviceSize      [1];
  unsigned long aulInsideCrc [1];
}EeePExtI2CDevice_t;

EeePExtI2CDevice_t EeePExtI2CDevice0;
EeePExtI2CDevice_t EeePExtI2CDevice1;

typedef struct EeePI2CDevice_s{
  unsigned long aulDeviceType         [1];
  unsigned long aulDeviceSize         [1];
  unsigned long aulWriteLength  [1];
  unsigned long aulInsideCrc    [1];
}EeePI2CDevice_t;

EeePI2CDevice_t EeePI2CDevice;

typedef struct COM0R20_CB_HDR_s{
  unsigned long aulDeviceType [1];
  unsigned long aulDeviceSize [1];
  unsigned long aulWriteLength[1];
  unsigned long aulVendorId   [1];
  unsigned long aulDeviceId   [1];
  unsigned long aulDeviceFlav [1];
  unsigned long aulRevId      [1];
  unsigned long aulCBType     [1];
  unsigned long aulSpecRev    [1];
  unsigned long aulUSBHSCount [1];
  unsigned long aulUSBSSCount [1];
  unsigned long aulSASPort0   [1];
  unsigned long aulSASPort1   [1];
  unsigned long aulSASPort2   [1];
  unsigned long aulSASPort3   [1];
  unsigned long aulGBE0       [1];
  unsigned long aulGBE1       [1];
  unsigned long aulGBE2       [1];
  unsigned long aulWAKE0      [1];
  unsigned long aulWAKE1      [1];
  unsigned long aulSUS        [1];
  unsigned long aulBatLow     [1];
  unsigned long aulTHRMP      [1];
  unsigned long aulEBROM      [1];
  unsigned long aulWDT        [1];
  unsigned long aulAC97       [1];
  unsigned long aulSSC        [1];
  unsigned long aulSDIO       [1];
  unsigned long aulLID        [1];
  unsigned long aulSleep      [1];
  unsigned long aulFAN0       [1];
  unsigned long aulSER0       [1];
  unsigned long aulSER1       [1];
  unsigned long aulDDI0       [1];
  unsigned long aulDDI1       [1];
  unsigned long aulDDI2       [1];
  unsigned long aulDDI3       [1];
  unsigned long aulPCIePorts  [32];
}COM0R20_CB_HDR_t;

COM0R20_CB_HDR_t COM0R20_CB_cgf;

typedef struct COM0R20_M_HDR_s{
  unsigned long aulDeviceType  [1];
  unsigned long aulDeviceSize  [1];
  unsigned long aulWriteLength [1];
  unsigned long aulVendorId    [1];
  unsigned long aulDeviceId    [1];
  unsigned long aulDeviceFlav  [1];
  unsigned long aulRevId       [1];
  unsigned long aulMType       [1];
  unsigned long aulSpecRev     [1];
}COM0R20_M_HDR_t;

COM0R20_M_HDR_t COM0R20_M_cgf;

typedef struct COM0R20_ECard_s{
  unsigned long aulExpCardNum[1];
  unsigned long aulPCIe_Port [1];
  unsigned long aulUSB_Port  [1];
  unsigned long aulSwitchPFA [30];
  unsigned long aulInsideCrc [1];
}COM0R20_ECard_t;

COM0R20_ECard_t COM0R20_ECard0_cgf={{0},{0},{0},{0},{0}};
COM0R20_ECard_t COM0R20_ECard1_cgf={{1},{0},{0},{0},{0}};

typedef struct COM0R20_SERIAL_s{
  unsigned long aulSER0_IOADDRESS        [1];
  unsigned long aulSER0_IRQ              [1];
  unsigned long aulSER1_IOADDRESS        [1];
  unsigned long aulSER1_IRQ              [1];
  unsigned long aulInsideCrc             [1];
}COM0R20_SERIAL_t;

COM0R20_SERIAL_t COM0R20_SER_cgf;

typedef struct EeeP_Exp_Hdr_s{
  unsigned long aulDeviceType  [1];
  unsigned long aulDeviceSize  [1];
  unsigned long aulWriteLength [1];
  unsigned long aulVendorId    [1];
  unsigned long aulDeviceId    [1];
  unsigned long aulDeviceFlav  [1];
  unsigned long aulRevId       [1];
  unsigned long aulInsideCrc   [1];
}EeeP_Exp_Hdr_t;

EeeP_Exp_Hdr_t EeePExpHdr_cgf;


CfgElementDesc_t SmbiosModuleDesc[]={
  ELEMENT_DESC("InsideCRC"     , COM0_SMBIOS_Module.aulInsideCrc      , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("Manufacturer"  , COM0_SMBIOS_Module.aszManuf          , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Product"       , COM0_SMBIOS_Module.aszProduct        , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Version"       , COM0_SMBIOS_Module.aszVersion        , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("SerialNumber"  , COM0_SMBIOS_Module.aszSerialNum      , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("AssetTag"      , COM0_SMBIOS_Module.aszAssetTag       , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("FeatureFlag"   , COM0_SMBIOS_Module.aulFeatureFlag    , &Token_Element_funcs , &SmbiSmbiosModuleFeatureFlagsTL, ELEMENT_REQUIRED)
  ELEMENT_DESC("Location"      , COM0_SMBIOS_Module.aszLocation       , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("LocationHandle", COM0_SMBIOS_Module.aulLocationHandle , &Number_Element_funcs, &ValidHandlesDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BoardType"     , COM0_SMBIOS_Module.aulBoardType      , &Token_Element_funcs , &SmbiosBoardTypesTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("Handles"       , COM0_SMBIOS_Module.aulHandles        , &Number_Element_funcs, &ValidHandlesDesc              , ELEMENT_OPTIONAL)
};                                
CfgElementDesc_t SmbiosCarrierDesc[]={  
  ELEMENT_DESC("InsideCRC"     , COM0_SMBIOS_Carrier.aulInsideCrc     , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("Manufacturer"  , COM0_SMBIOS_Carrier.aszManuf         , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Product"       , COM0_SMBIOS_Carrier.aszProduct       , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Version"       , COM0_SMBIOS_Carrier.aszVersion       , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("SerialNumber"  , COM0_SMBIOS_Carrier.aszSerialNum     , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("AssetTag"      , COM0_SMBIOS_Carrier.aszAssetTag      , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("FeatureFlag"   , COM0_SMBIOS_Carrier.aulFeatureFlag   , &Token_Element_funcs , &SmbiSmbiosModuleFeatureFlagsTL, ELEMENT_REQUIRED)
  ELEMENT_DESC("Location"      , COM0_SMBIOS_Carrier.aszLocation      , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("LocationHandle", COM0_SMBIOS_Carrier.aulLocationHandle, &Number_Element_funcs, &ValidHandlesDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BoardType"     , COM0_SMBIOS_Carrier.aulBoardType     , &Token_Element_funcs , &SmbiosBoardTypesTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("Handles"       , COM0_SMBIOS_Carrier.aulHandles       , &Number_Element_funcs, &ValidHandlesDesc              , ELEMENT_OPTIONAL)
};
CfgElementDesc_t SmbiosSystemDesc[]={
  ELEMENT_DESC("InsideCRC"     , COM0_SMBIOS_System.aulInsideCrc      , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("Manufacturer"  , COM0_SMBIOS_System.aszManuf          , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Product"       , COM0_SMBIOS_System.aszProduct        , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Version"       , COM0_SMBIOS_System.aszVersion        , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("SerialNumber"  , COM0_SMBIOS_System.aszSerialNum      , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("UUID"          , COM0_SMBIOS_System.aUUID             , &GUID_Element_funcs  , NULL                           , ELEMENT_OPTIONAL)
  ELEMENT_DESC("SKU_Number"    , COM0_SMBIOS_System.aszSKU_Number     , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Family"        , COM0_SMBIOS_System.aszFamily         , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
};                                                         
                                                           
CfgElementDesc_t SmbiosChassisDesc[]={                     
  ELEMENT_DESC("InsideCRC"     , COM0_SMBIOS_Chassis.aulInsideCrc     , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("Manufacturer"  , COM0_SMBIOS_Chassis.aszManuf         , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Type"          , COM0_SMBIOS_Chassis.aulChassisType   , &Token_Element_funcs , &SmbiosChassisTypesTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("Version"       , COM0_SMBIOS_Chassis.aszVersion       , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("SerialNumber"  , COM0_SMBIOS_Chassis.aszSerialNum     , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("AssetTag"      , COM0_SMBIOS_Chassis.aszAssetTag      , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("OEM"           , COM0_SMBIOS_Chassis.aulOEM           , &Number_Element_funcs, &UINT32RangeDesc               , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Height"        , COM0_SMBIOS_Chassis.aulHeight        , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("NumPowerCords" , COM0_SMBIOS_Chassis.aulNumPowerCords , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("CElements"     , COM0_SMBIOS_Chassis.aCElements       , &SMBIOS_CE_Element_funcs, NULL                        , ELEMENT_OPTIONAL)
};

CfgElementDesc_t LFPData0Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_LFP0_Cfg.aulInsideCrc         , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("Interface"     , EeeP_LFP0_Cfg.aulInterface         , &Token_Element_funcs , &DisplayInterfaceTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_LFP0_Cfg.aszFilename          , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t LFPData1Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_LFP1_Cfg.aulInsideCrc         , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("Interface"     , EeeP_LFP1_Cfg.aulInterface         , &Token_Element_funcs , &DisplayInterfaceTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_LFP1_Cfg.aszFilename          , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t LFPData2Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_LFP2_Cfg.aulInsideCrc         , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("Interface"     , EeeP_LFP2_Cfg.aulInterface         , &Token_Element_funcs , &DisplayInterfaceTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_LFP2_Cfg.aszFilename          , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t LFPData3Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_LFP3_Cfg.aulInsideCrc         , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("Interface"     , EeeP_LFP3_Cfg.aulInterface         , &Token_Element_funcs , &DisplayInterfaceTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_LFP3_Cfg.aszFilename          , &String_Element_funcs, &DeleteTrailingSpaces           , ELEMENT_REQUIRED)
};

CfgElementDesc_t VendorBlock0Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock0_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock0_Cfg.aulVendorId  , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock0_Cfg.aulVSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock0_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock1Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock1_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock1_Cfg.aulVendorId  , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock1_Cfg.aulVSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock1_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock2Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock2_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock2_Cfg.aulVendorId  , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock2_Cfg.aulVSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock2_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock3Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock3_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock3_Cfg.aulVendorId  , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock3_Cfg.aulVSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock3_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock4Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock4_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock4_Cfg.aulVendorId  , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock4_Cfg.aulVSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock4_Cfg.aszFilename  , &String_Element_funcs, NULL                    , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock5Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock5_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock5_Cfg.aulVendorId  , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock5_Cfg.aulVSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock5_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock6Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock6_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock6_Cfg.aulVendorId  , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock6_Cfg.aulVSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock6_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};

CfgElementDesc_t CustomBlock0Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock0_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock0_Cfg.aulBlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock0_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock1Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock1_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock1_Cfg.aulBlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock1_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock2Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock2_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock2_Cfg.aulBlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock2_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock3Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock3_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock3_Cfg.aulBlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock3_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock4Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock4_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock4_Cfg.aulBlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock4_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock5Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock5_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock5_Cfg.aulBlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock5_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock6Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock6_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock6_Cfg.aulBlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock6_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
TokenDesc_t  EEPDeviceSizeTokens[]={
  {"256Bytes"	  , 0},
  {"512Bytes"	  , 1},
  {"1KBytes"	  , 2},
  {"2KBytes"	  , 3},
  {"4KBytes"	  , 4},
  {"8KBytes"	  , 5},
  {"16KBytes"	  , 6},
  {"32KBytes"	  , 7},
  {"64KBytes"	  , 8},
  {"128KBytes"	, 9},
  {"256KBytes"  , 10},
  {"512KBytes"  , 11},
  {"2Kbits"     , 0},
  {"4Kbits"     , 1},
  {"8Kbits"     , 2},
  {"16Kbits"    , 3},
  {"32Kbits"    , 4},
  {"64Kbits"    , 5},
  {"128Kbits"   , 6},
  {"256Kbits"   , 7},
  {"512Kbits"   , 8},
  {"1Mbits"     , 9},
  {"2Mbits"     , 10},
  {"4Mbits"     , 11},
};
PCFG_TOKEN_LIST_DESC(EEPDeviceSizeTL, EEPDeviceSizeTokens);

TokenDesc_t  EeePEEPWriteLenTokens[]={
  {"1"	  , 0<<EEEP_DEVICE_WRITE_LEN_OFFSET},
  {"8"	  , 1<<EEEP_DEVICE_WRITE_LEN_OFFSET},
  {"16"	  , 2<<EEEP_DEVICE_WRITE_LEN_OFFSET},
  {"32"	  , 3<<EEEP_DEVICE_WRITE_LEN_OFFSET},
  {"64"	  , 4<<EEEP_DEVICE_WRITE_LEN_OFFSET},
  {"128"  , 5<<EEEP_DEVICE_WRITE_LEN_OFFSET},
  {"256"  , 6<<EEEP_DEVICE_WRITE_LEN_OFFSET},
  {"512"  , 7<<EEEP_DEVICE_WRITE_LEN_OFFSET},
};
PCFG_TOKEN_LIST_DESC(EeePEEPWriteLenTL, EeePEEPWriteLenTokens);


CfgElementDesc_t ExtI2CDevice0Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeePExtI2CDevice0.aulInsideCrc, &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceBus"     , EeePExtI2CDevice0.aulBus      , &Token_Element_funcs  , &I2CBusTL             , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceAddr"    , EeePExtI2CDevice0.aulAddr     , &I2C_EEPROM_Addr_funcs, NULL                  , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceType"    , EeePExtI2CDevice0.aulDeviceType     , &Token_Element_funcs  , &StandardExtendedTL   , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceSize"    , EeePExtI2CDevice0.aulDeviceSize     , &Token_Element_funcs  , &EEPDeviceSizeTL      , ELEMENT_REQUIRED)
};
CfgElementDesc_t ExtI2CDevice1Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeePExtI2CDevice1.aulInsideCrc, &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceBus"     , EeePExtI2CDevice1.aulBus      , &Token_Element_funcs  , &I2CBusTL             , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceAddr"    , EeePExtI2CDevice1.aulAddr     , &I2C_EEPROM_Addr_funcs, NULL                  , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceType"    , EeePExtI2CDevice1.aulDeviceType     , &Token_Element_funcs  , &StandardExtendedTL   , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceSize"    , EeePExtI2CDevice1.aulDeviceSize     , &Token_Element_funcs  , &EEPDeviceSizeTL      , ELEMENT_REQUIRED)
};

CfgElementDesc_t I2CDeviceDesc[]={
  ELEMENT_DESC("DeviceType"    , EeePI2CDevice.aulDeviceType        , &Token_Element_funcs , &StandardExtendedTL    , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceSize"    , EeePI2CDevice.aulDeviceSize        , &Token_Element_funcs , &EEPDeviceSizeTL       , ELEMENT_REQUIRED)
  ELEMENT_DESC("WriteLength"   , EeePI2CDevice.aulWriteLength , &Token_Element_funcs , &EeePEEPWriteLenTL     , ELEMENT_REQUIRED)
};
NumberRange_t ValidUsbHSRange[]={
  {0x0000, 0x0008, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidUsbHSRangeDesc, ValidUsbHSRange);

NumberRange_t ValidUsbSSRange[]={
  {0x0000, 0x0004, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidUsbSSRangeDesc, ValidUsbSSRange);

NumberRange_t ValidModuleTypes[]={
  {0x0000, 0x0006, RANGE_INCLUSIVE},
  {0x000A, 0x000A, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidModuleTypesDesc, ValidModuleTypes);

CfgElementDesc_t COM0R20_CB_Desc[]={
  ELEMENT_DESC("EepDeviceType" , COM0R20_CB_cgf.aulDeviceType , &Token_Element_funcs   , &StandardExtendedTL   , ELEMENT_REQUIRED)
  ELEMENT_DESC("EepDeviceSize" , COM0R20_CB_cgf.aulDeviceSize , &Token_Element_funcs   , &EEPDeviceSizeTL      , ELEMENT_REQUIRED)
  ELEMENT_DESC("WriteLength"   , COM0R20_CB_cgf.aulWriteLength, &Token_Element_funcs   , &EeePEEPWriteLenTL    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"      , COM0R20_CB_cgf.aulVendorId   , &PNPID_Element_funcs   , NULL                  , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceId"      , COM0R20_CB_cgf.aulDeviceId   , &Number_Element_funcs  , &UINT16RangeDesc      , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceFlav"    , COM0R20_CB_cgf.aulDeviceFlav , &Number_Element_funcs  , &UINT8RangeDesc       , ELEMENT_REQUIRED)
  ELEMENT_DESC("RevId"         , COM0R20_CB_cgf.aulRevId      , &Number_Element_funcs  , &UINT8RangeDesc       , ELEMENT_REQUIRED)
  ELEMENT_DESC("CBType"        , COM0R20_CB_cgf.aulCBType     , &Number_Element_funcs  , &ValidModuleTypesDesc , ELEMENT_REQUIRED)
  ELEMENT_DESC("SpecRevision"  , COM0R20_CB_cgf.aulSpecRev    , &SpecRev_Element_funcs , NULL                  , ELEMENT_REQUIRED)
  ELEMENT_DESC("USBHSCount"    , COM0R20_CB_cgf.aulUSBHSCount , &Number_Element_funcs  , &ValidUsbHSRangeDesc  , ELEMENT_REQUIRED)
  ELEMENT_DESC("USBSSCount"    , COM0R20_CB_cgf.aulUSBSSCount , &Number_Element_funcs  , &ValidUsbSSRangeDesc  , ELEMENT_REQUIRED)
  ELEMENT_DESC("SASPort0"      , COM0R20_CB_cgf.aulSASPort0   , &Token_Element_funcs   , &SasTL                , ELEMENT_REQUIRED)
  ELEMENT_DESC("SASPort1"      , COM0R20_CB_cgf.aulSASPort1   , &Token_Element_funcs   , &SasTL                , ELEMENT_REQUIRED)
  ELEMENT_DESC("SASPort2"      , COM0R20_CB_cgf.aulSASPort2   , &Token_Element_funcs   , &SasTL                , ELEMENT_REQUIRED)
  ELEMENT_DESC("SASPort3"      , COM0R20_CB_cgf.aulSASPort3   , &Token_Element_funcs   , &SasTL                , ELEMENT_REQUIRED)
  ELEMENT_DESC("GBE0"          , COM0R20_CB_cgf.aulGBE0       , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("GBE1"          , COM0R20_CB_cgf.aulGBE1       , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("GBE2"          , COM0R20_CB_cgf.aulGBE2       , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("WAKE0"         , COM0R20_CB_cgf.aulWAKE0      , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("WAKE1"         , COM0R20_CB_cgf.aulWAKE1      , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("SUS"           , COM0R20_CB_cgf.aulSUS        , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("BatLow"        , COM0R20_CB_cgf.aulBatLow     , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("THRMP"         , COM0R20_CB_cgf.aulTHRMP      , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("EBROM"         , COM0R20_CB_cgf.aulEBROM      , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("WDT"           , COM0R20_CB_cgf.aulWDT        , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("AC97/HDA"      , COM0R20_CB_cgf.aulAC97       , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("SSC"           , COM0R20_CB_cgf.aulSSC        , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("SDIO"          , COM0R20_CB_cgf.aulSDIO       , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("LID"           , COM0R20_CB_cgf.aulLID        , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("Sleep"         , COM0R20_CB_cgf.aulSleep      , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("FAN0"          , COM0R20_CB_cgf.aulFAN0       , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("SER0"          , COM0R20_CB_cgf.aulSER0       , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("SER1"          , COM0R20_CB_cgf.aulSER1       , &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("DDI0"          , COM0R20_CB_cgf.aulDDI0       , &Token_Element_funcs   , &DDI1TL               , ELEMENT_REQUIRED)
  ELEMENT_DESC("DDI1"          , COM0R20_CB_cgf.aulDDI1       , &Token_Element_funcs   , &DDI1TL               , ELEMENT_REQUIRED)
  ELEMENT_DESC("DDI2"          , COM0R20_CB_cgf.aulDDI2       , &Token_Element_funcs   , &DDI2TL               , ELEMENT_REQUIRED)
  ELEMENT_DESC("DDI3"          , COM0R20_CB_cgf.aulDDI3       , &Token_Element_funcs   , &DDI2TL               , ELEMENT_REQUIRED)
  ELEMENT_DESC("PCIePorts"     , COM0R20_CB_cgf.aulPCIePorts  , &COM0PCIe_Element_funcs, NULL                  , ELEMENT_REQUIRED)
};
CfgElementDesc_t COM0R20_M_Desc[]={
  ELEMENT_DESC("EepDeviceType" , COM0R20_M_cgf.aulDeviceType  , &Token_Element_funcs  , &StandardExtendedTL  , ELEMENT_REQUIRED)
  ELEMENT_DESC("EepDeviceSize" , COM0R20_M_cgf.aulDeviceSize  , &Token_Element_funcs  , &EEPDeviceSizeTL     , ELEMENT_REQUIRED)
  ELEMENT_DESC("WriteLength"   , COM0R20_M_cgf.aulWriteLength , &Token_Element_funcs  , &EeePEEPWriteLenTL   , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"      , COM0R20_M_cgf.aulVendorId    , &PNPID_Element_funcs  , NULL                 , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceId"      , COM0R20_M_cgf.aulDeviceId    , &Number_Element_funcs , &UINT16RangeDesc     , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceFlav"    , COM0R20_M_cgf.aulDeviceFlav  , &Number_Element_funcs , &UINT8RangeDesc      , ELEMENT_REQUIRED)
  ELEMENT_DESC("RevId"         , COM0R20_M_cgf.aulRevId       , &Number_Element_funcs , &UINT8RangeDesc      , ELEMENT_REQUIRED)
  ELEMENT_DESC("MType"         , COM0R20_M_cgf.aulMType       , &Number_Element_funcs , &ValidModuleTypesDesc, ELEMENT_REQUIRED)
  ELEMENT_DESC("SpecRevision"  , COM0R20_M_cgf.aulSpecRev     , &SpecRev_Element_funcs, NULL                 , ELEMENT_REQUIRED)
};
CfgElementDesc_t EeePExpHdr_Desc[]={
  ELEMENT_DESC("EepDeviceType" , EeePExpHdr_cgf.aulDeviceType  , &Token_Element_funcs , &StandardExtendedTL  , ELEMENT_REQUIRED)
  ELEMENT_DESC("EepDeviceSize" , EeePExpHdr_cgf.aulDeviceSize  , &Token_Element_funcs , &EEPDeviceSizeTL     , ELEMENT_REQUIRED)
  ELEMENT_DESC("WriteLength"   , EeePExpHdr_cgf.aulWriteLength , &Token_Element_funcs , &EeePEEPWriteLenTL   , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"      , EeePExpHdr_cgf.aulVendorId    , &PNPID_Element_funcs , NULL                 , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceId"      , EeePExpHdr_cgf.aulDeviceId    , &Number_Element_funcs, &UINT16RangeDesc     , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceFlav"    , EeePExpHdr_cgf.aulDeviceFlav  , &Number_Element_funcs, &UINT8RangeDesc      , ELEMENT_REQUIRED)
  ELEMENT_DESC("RevId"         , EeePExpHdr_cgf.aulRevId       , &Number_Element_funcs, &UINT8RangeDesc      , ELEMENT_REQUIRED)
};
NumberRange_t ValidCOM0PCIePort[]={
  {0, 31, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidCOM0PCIePortDesc, ValidCOM0PCIePort);

NumberRange_t ValidCOM0USBPort[]={
  {0, 7, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidCOM0USBPortDesc, ValidCOM0USBPort);

CfgElementDesc_t COM0R20_ExpCard0Desc[]={
  ELEMENT_DESC("InsideCRC"     , COM0R20_ECard0_cgf.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("COM0_PCIe_Port", COM0R20_ECard0_cgf.aulPCIe_Port , &Number_Element_funcs, &ValidCOM0PCIePortDesc, ELEMENT_REQUIRED)
  ELEMENT_DESC("COM0_USB_Port" , COM0R20_ECard0_cgf.aulUSB_Port  , &Number_Element_funcs, &ValidCOM0USBPortDesc , ELEMENT_REQUIRED)
  ELEMENT_DESC("SwitchPFA"     , COM0R20_ECard0_cgf.aulSwitchPFA , &Number_Element_funcs, &UINT8RangeDesc       , ELEMENT_OPTIONAL)
};

CfgElementDesc_t COM0R20_ExpCard1Desc[]={
  ELEMENT_DESC("InsideCRC"     , COM0R20_ECard1_cgf.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("COM0_PCIe_Port", COM0R20_ECard1_cgf.aulPCIe_Port , &Number_Element_funcs, &ValidCOM0PCIePortDesc, ELEMENT_REQUIRED)
  ELEMENT_DESC("COM0_USB_Port" , COM0R20_ECard1_cgf.aulUSB_Port  , &Number_Element_funcs, &ValidCOM0USBPortDesc , ELEMENT_REQUIRED)
  ELEMENT_DESC("SwitchPFA"     , COM0R20_ECard1_cgf.aulSwitchPFA , &Number_Element_funcs, &UINT8RangeDesc       , ELEMENT_OPTIONAL)
};

NumberRange_t ValidIOAddrPort[]={
  {0x200, 0xFFF8, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidIOAddrPortDesc, ValidIOAddrPort);

CfgElementDesc_t COM0R20_SerialPortsDesc[]={
  ELEMENT_DESC("InsideCRC"     , COM0R20_SER_cgf.aulInsideCrc              , &Token_Element_funcs , &InsideCrcTL        , ELEMENT_REQUIRED)
  ELEMENT_DESC("SER0_IOADDRESS", COM0R20_SER_cgf.aulSER0_IOADDRESS         , &Number_Element_funcs, &ValidIOAddrPortDesc, ELEMENT_OPTIONAL)
  ELEMENT_DESC("SER0_IRQ"      , COM0R20_SER_cgf.aulSER0_IRQ               , &Token_Element_funcs , &IRQTL              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("SER1_IOADDRESS", COM0R20_SER_cgf.aulSER1_IOADDRESS         , &Number_Element_funcs, &ValidIOAddrPortDesc, ELEMENT_OPTIONAL)
  ELEMENT_DESC("SER1_IRQ"      , COM0R20_SER_cgf.aulSER1_IRQ               , &Token_Element_funcs , &IRQTL              , ELEMENT_OPTIONAL)
};
EApiStatusCode_t
HandleCOM0R20CBHeaderBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  COM0R20_CB_t *pHeader=BHandel;
  size_t i, i2;
  COM0R20_CB_HDR_t *pCOM0R20_CB_cgf=pDesc->pDataContainer;
  pHeader=BHandel;


  pHeader->EeePHdr.DeviceDesc=(uint8_t)pCOM0R20_CB_cgf->aulDeviceSize[0];
  pHeader->EeePHdr.DeviceDesc|=pCOM0R20_CB_cgf->aulDeviceType[0];
  pHeader->EeePHdr.DeviceDesc|=pCOM0R20_CB_cgf->aulWriteLength[0];

  memcpy(pHeader->GenId, COM0R20_CB_HEADER_ID, sizeof(COM0R20_CB_HEADER_ID)-1);

  EeeP_Set16BitValue_BE(pHeader->DevId.VendId  , (uint16_t)pCOM0R20_CB_cgf->aulVendorId[0]);
  EeeP_Set16BitValue_BE(pHeader->DevId.DeviceId, (uint16_t)pCOM0R20_CB_cgf->aulDeviceId[0]);
  pHeader->DevId.DeviceFlav=(uint8_t)pCOM0R20_CB_cgf->aulDeviceFlav[0];
  pHeader->DevId.RevId     =(uint8_t)pCOM0R20_CB_cgf->aulRevId[0];

  pHeader->CBType =(uint8_t)pCOM0R20_CB_cgf->aulCBType[0];
  pHeader->SpecRev=(uint8_t)pCOM0R20_CB_cgf->aulSpecRev[0];

  pHeader->UsbDesc =(uint8_t)pCOM0R20_CB_cgf->aulUSBHSCount[0]<<COM0R20_USB_PCNT_OFFSET;
  pHeader->UsbDesc|=pCOM0R20_CB_cgf->aulUSBSSCount[0]<<COM0R20_USB3_PCNT_OFFSET;

  pHeader->SasDesc =(uint8_t)pCOM0R20_CB_cgf->aulSASPort0[0]<<COM0R20_SAS_CHANNEL_0;
  pHeader->SasDesc|=pCOM0R20_CB_cgf->aulSASPort1[0]<<COM0R20_SAS_CHANNEL_1;
  pHeader->SasDesc|=pCOM0R20_CB_cgf->aulSASPort2[0]<<COM0R20_SAS_CHANNEL_2;
  pHeader->SasDesc|=pCOM0R20_CB_cgf->aulSASPort3[0]<<COM0R20_SAS_CHANNEL_3;

  pHeader->LanDesc =(pCOM0R20_CB_cgf->aulGBE0[0]?COM0R20_GBE0_PRESENT:0);
  pHeader->LanDesc|=(pCOM0R20_CB_cgf->aulGBE1[0]?COM0R20_GBE1_PRESENT:0);
  pHeader->LanDesc|=(pCOM0R20_CB_cgf->aulGBE2[0]?COM0R20_GBE2_PRESENT:0);

  pHeader->MiscIo1 =(pCOM0R20_CB_cgf->aulWAKE0 [0]?COM0R20_WAKE0_PRESENT :0);
  pHeader->MiscIo1|=(pCOM0R20_CB_cgf->aulWAKE1 [0]?COM0R20_WAKE1_PRESENT :0);
  pHeader->MiscIo1|=(pCOM0R20_CB_cgf->aulSUS   [0]?COM0R20_SUS_PRESENT   :0);
  pHeader->MiscIo1|=(pCOM0R20_CB_cgf->aulBatLow[0]?COM0R20_BATLOW_PRESENT:0);
  pHeader->MiscIo1|=(pCOM0R20_CB_cgf->aulTHRMP [0]?COM0R20_THRMP_PRESENT :0);
  pHeader->MiscIo1|=(pCOM0R20_CB_cgf->aulEBROM [0]?COM0R20_EBROM_PRESENT :0);
  pHeader->MiscIo1|=(pCOM0R20_CB_cgf->aulWDT   [0]?COM0R20_WDT_PRESENT   :0);
  pHeader->MiscIo1|=(pCOM0R20_CB_cgf->aulAC97  [0]?COM0R20_AC97_PRESENT  :0);

  pHeader->MiscIo2 =(pCOM0R20_CB_cgf->aulSSC   [0]?COM0R20_SSC_PRESENT   :0);
  pHeader->MiscIo2|=(pCOM0R20_CB_cgf->aulSDIO  [0]?COM0R20_SDIO_PRESENT  :0);
  pHeader->MiscIo2|=(pCOM0R20_CB_cgf->aulLID   [0]?COM0R20_LID_PRESENT   :0);
  pHeader->MiscIo2|=(pCOM0R20_CB_cgf->aulSleep [0]?COM0R20_SLEEP_PRESENT :0);
  pHeader->MiscIo2|=(pCOM0R20_CB_cgf->aulFAN0  [0]?COM0R20_FAN0_PRESENT  :0);
  pHeader->MiscIo2|=(pCOM0R20_CB_cgf->aulSER0  [0]?COM0R20_SER0_PRESENT  :0);
  pHeader->MiscIo2|=(pCOM0R20_CB_cgf->aulSER1  [0]?COM0R20_SER1_PRESENT  :0);

  memset(pHeader->DDIDesc, 0x00, sizeof(pHeader->DDIDesc));
  pHeader->DDIDesc[0] =(uint8_t)pCOM0R20_CB_cgf->aulDDI0[0]<<COM0R20_DDI0_OFFSET;
  pHeader->DDIDesc[0]|=(uint8_t)pCOM0R20_CB_cgf->aulDDI1[0]<<COM0R20_DDI1_OFFSET;
  pHeader->DDIDesc[1] =(uint8_t)pCOM0R20_CB_cgf->aulDDI2[0]<<COM0R20_DDI2_OFFSET;
  pHeader->DDIDesc[1]|=(uint8_t)pCOM0R20_CB_cgf->aulDDI3[0]<<COM0R20_DDI3_OFFSET;

  memset(pHeader->PCIeGen, 0x00, sizeof(pHeader->PCIeGen));
  memset(pHeader->LaneMap, 0x00, sizeof(pHeader->LaneMap));
  if(pDesc->pElementsDesc[pDesc->stElementCount - 1].stElementCount){
    unsigned long *pulCurPort;
    unsigned int  uiBasePort;
    unsigned int  uiEncWidth;
    unsigned int  uiEndPort ;
    unsigned int  uiGen     ;
    for(
        i=pDesc->pElementsDesc[pDesc->stElementCount - 1].stElementCount, 
        pulCurPort=pCOM0R20_CB_cgf->aulPCIePorts; 
        i; 
        i--,pulCurPort++
        )
    {
      uiBasePort=*pulCurPort>>16;
      uiEncWidth=((*pulCurPort>>8)&UINT8_MAX);
      uiEndPort =uiBasePort+(1<<(uiEncWidth-1));
      uiGen     =(*pulCurPort&UINT8_MAX);
      for(i2=uiBasePort;i2<uiEndPort;i2++){
        /*
         *  4 PCIe Gen Per Byte
         */
        pHeader->PCIeGen[i2/4]|=uiGen<<((i2%4)*2);
        /*
         *  2 PCIe Lane Widths Per Byte
         */
        pHeader->LaneMap[i2/2]|=uiEncWidth<<((i2%2)*4);
      }

    }
  }
  return EAPI_STATUS_SUCCESS;
}
EApiStatusCode_t
HandleCOM0R20MHeaderBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  COM0R20_M_t *pHeader=BHandel;
  COM0R20_M_HDR_t *pCOM0R20_M_cgf=pDesc->pDataContainer;
  pHeader=BHandel;


  pHeader->EeePHdr.DeviceDesc=(uint8_t)pCOM0R20_M_cgf->aulDeviceSize[0];
  pHeader->EeePHdr.DeviceDesc|=pCOM0R20_M_cgf->aulDeviceType[0];
  pHeader->EeePHdr.DeviceDesc|=pCOM0R20_M_cgf->aulWriteLength[0];

  memcpy(pHeader->GenId, COM0R20_M_HEADER_ID, sizeof(COM0R20_M_HEADER_ID)-1);

  EeeP_Set16BitValue_BE(pHeader->DevId.VendId  , (uint16_t)pCOM0R20_M_cgf->aulVendorId[0]);
  EeeP_Set16BitValue_BE(pHeader->DevId.DeviceId, (uint16_t)pCOM0R20_M_cgf->aulDeviceId[0]);
  pHeader->DevId.DeviceFlav=(uint8_t)pCOM0R20_M_cgf->aulDeviceFlav[0];
  pHeader->DevId.RevId=(uint8_t)pCOM0R20_M_cgf->aulRevId[0];

  pHeader->MType=(uint8_t)pCOM0R20_M_cgf->aulMType[0];
  pHeader->SpecRev=(uint8_t)pCOM0R20_M_cgf->aulSpecRev[0];

  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
HandleEeePExpEepHeaderBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  Exp_EEP_t *pHeader=BHandel;
  EeeP_Exp_Hdr_t *pEeePExp_cgf=pDesc->pDataContainer;
  pHeader=BHandel;


  pHeader->EeePHdr.DeviceDesc=(uint8_t)pEeePExp_cgf->aulDeviceSize[0];
  pHeader->EeePHdr.DeviceDesc|=pEeePExp_cgf->aulDeviceType[0];
  pHeader->EeePHdr.DeviceDesc|=pEeePExp_cgf->aulWriteLength[0];

  memcpy(pHeader->GenId, EEEP_EXP_HEADER_ID, sizeof(EEEP_EXP_HEADER_ID)-1);

  EeeP_Set16BitValue_BE(pHeader->DevId.VendId  , (uint16_t)pEeePExp_cgf->aulVendorId[0]);
  EeeP_Set16BitValue_BE(pHeader->DevId.DeviceId, (uint16_t)pEeePExp_cgf->aulDeviceId[0]);
  pHeader->DevId.DeviceFlav=(uint8_t)pEeePExp_cgf->aulDeviceFlav[0];
  pHeader->DevId.RevId=(uint8_t)pEeePExp_cgf->aulRevId[0];

  return EAPI_STATUS_SUCCESS;
}

EApiStatusCode_t
HandleEeePExpI2CBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  EeePExtI2CDeviceDesc_t Header;
  EeePExtI2CDevice_t *pExtI2C_cgf=pDesc->pDataContainer;
  size_t stBlockLength=EeePAlignLength(sizeof(Header));


  DO(SetDynBlockHeader(&Header, EEEP_BLOCK_ID_EXP_EEPROM, stBlockLength));
  EeeP_Set16BitValue_BE(Header.DeviceAddr  , (uint16_t)pExtI2C_cgf->aulAddr[0]);

  Header.DeviceBus  =(uint8_t)pExtI2C_cgf->aulBus[0];

  Header.DeviceDesc =(uint8_t)pExtI2C_cgf->aulDeviceSize[0];
  Header.DeviceDesc|=pExtI2C_cgf->aulDeviceType[0];

  DO(EeePAddBlock(BHandel, &Header, NULL, pExtI2C_cgf->aulInsideCrc[0]));

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}


EApiStatusCode_t
HandleCOM0R20SerialCfgBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  SerPortCfgBlock_t Header;
  COM0R20_SERIAL_t *pCOM0Serial_cgf=pDesc->pDataContainer;
  size_t stBlockLength=EeePAlignLength(sizeof(Header));


  DO(SetDynBlockHeader(&Header, COM0R20_BLOCK_ID_SERIO_DESC, stBlockLength));

  EeeP_Set16BitValue_BE(Header.Ser0BaseAddr  , (uint16_t)pCOM0Serial_cgf->aulSER0_IOADDRESS[0]);
  EeeP_Set16BitValue_BE(Header.Ser1BaseAddr  , (uint16_t)pCOM0Serial_cgf->aulSER1_IOADDRESS[0]);

  Header.SerIRQ=(uint8_t)pCOM0Serial_cgf->aulSER0_IRQ[0];
  Header.SerIRQ|=pCOM0Serial_cgf->aulSER1_IRQ[0]<<4;

  DO(EeePAddBlock(BHandel, &Header, NULL, pCOM0Serial_cgf->aulInsideCrc[0]));

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}


EApiStatusCode_t
HandleCOM0R20ExpCardCfgBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  ExpCardBlock_t   *pHeader;
  COM0R20_ECard_t  *pCOM0ExpCard_cgf=pDesc->pDataContainer;
  size_t stElementCnt =pDesc->pElementsDesc[pDesc->stElementCount - 1].stElementCount;
  size_t stBlockLength=EeePAlignLength(
            sizeof(*pHeader)- 
            sizeof(pHeader->SwitchDevFuncAddr)+
            (stElementCnt*sizeof(pHeader->SwitchDevFuncAddr[0]))
          );
  uint8_t *pSwitchDevFuncAddr;
  unsigned long *pulSwitchDevFuncAddr;
  pHeader=calloc(stBlockLength, sizeof(uint8_t));
  EAPI_APP_ASSERT_PARAMATER_NULL(
        HandleCOM0R20ExpCardCfgBlock ,
        EAPI_STATUS_ALLOC_ERROR,
        pHeader
      );


  DO(SetDynBlockHeader(pHeader, COM0R20_BLOCK_ID_EXP_CARD_DESC, stBlockLength));

  pHeader->ExpressCardNumber=(uint8_t)pCOM0ExpCard_cgf->aulExpCardNum[0];
  pHeader->ComExpressPort   =(uint8_t)pCOM0ExpCard_cgf->aulPCIe_Port[0];
  pHeader->ComExpressPort  |=         pCOM0ExpCard_cgf->aulUSB_Port[0]<<5;


  for(
        pSwitchDevFuncAddr=pHeader->SwitchDevFuncAddr,
        pulSwitchDevFuncAddr=pCOM0ExpCard_cgf->aulSwitchPFA;
        stElementCnt;
        stElementCnt--,
        pSwitchDevFuncAddr++,
        pulSwitchDevFuncAddr++
      )
  {
    *pSwitchDevFuncAddr=(uint8_t)*pulSwitchDevFuncAddr;
  }

  *pSwitchDevFuncAddr=COM0R20_EXPCARD_MAP_EOL;

  DO(EeePAddBlock(BHandel, pHeader, NULL, pCOM0ExpCard_cgf->aulInsideCrc[0]));

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}

#define COUNT_STRLEN(StrName) \
  if(StrName!=NULL) stBlockLength+=strlen(StrName)+1;


#define APPEND_STRING(String, VarName)  \
  if(String    !=NULL){                 \
    VarName=(uint8_t)++i;                        \
    strcpy(pszStrBuffer, String);       \
    pszStrBuffer+=strlen(String)+1;     \
  }

EApiStatusCode_t
HandleSmbiosChassisBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  EeePChassisInfo_t *pHeader;
  unsigned int i;
  SmbiosChassis_t *pSmbiosChassis_cgf=pDesc->pDataContainer;
  size_t stHeaderLength=sizeof(*pHeader)- sizeof(pHeader->CElement[0]);
  size_t stBlockLength=0;
  CCElement_t *pHandles1;
  CCElement_t *pHandles2;
  char *pszStrBuffer;

  COUNT_STRLEN(pSmbiosChassis_cgf->aszManuf[0]     );
  COUNT_STRLEN(pSmbiosChassis_cgf->aszVersion[0]   );
  COUNT_STRLEN(pSmbiosChassis_cgf->aszSerialNum[0] );
  COUNT_STRLEN(pSmbiosChassis_cgf->aszAssetTag[0]  );

  stHeaderLength +=pDesc->pElementsDesc[pDesc->stElementCount - 1].stElementCount*sizeof(pHeader->CElement[0]);
  stBlockLength  +=stHeaderLength+1;
  stBlockLength  +=stBlockLength%2;

  stHeaderLength -=sizeof(DBlockIdHdr_t) ;
  pHeader=calloc(stBlockLength, sizeof(uint8_t));
  EAPI_APP_ASSERT_PARAMATER_NULL(
        HandleSmbiosChassisBlock ,
        EAPI_STATUS_ALLOC_ERROR,
        pHeader
      );

  pHeader->Type         =(uint8_t)pSmbiosChassis_cgf->aulChassisType[0]     ;
  EeeP_Set32BitValue_BE(pHeader->OEM.b  , (uint32_t)pSmbiosChassis_cgf->aulOEM[0]);
  pHeader->Height       =(uint8_t)pSmbiosChassis_cgf->aulHeight[0]     ;
  pHeader->NumPowerCords=(uint8_t)pSmbiosChassis_cgf->aulNumPowerCords[0]     ;
  pHeader->CElementCnt  =(uint8_t)pDesc->pElementsDesc[pDesc->stElementCount - 1].stElementCount;
  pHeader->CElementSize =(uint8_t)sizeof(pHeader->CElement[0]);
  for(
        i=pHeader->CElementCnt,
        pHandles1=pHeader->CElement,
        pHandles2=pSmbiosChassis_cgf->aCElements;
        i;
        i--,
        pHandles1++,
        pHandles2++
      )
  {
    *pHandles1=*pHandles2;
  }

  pszStrBuffer=(char*)pHandles1;
  i=0;

  APPEND_STRING(pSmbiosChassis_cgf->aszManuf[0]     , pHeader->Manufacturer  );
  APPEND_STRING(pSmbiosChassis_cgf->aszVersion[0]   , pHeader->Version       );
  APPEND_STRING(pSmbiosChassis_cgf->aszSerialNum[0] , pHeader->SerialNumber  );
  APPEND_STRING(pSmbiosChassis_cgf->aszAssetTag[0]  , pHeader->AssetTagNumber);

  DO(SetDynBlockHeader(pHeader, EEEP_BLOCK_ID_SMBIOS, stBlockLength));

  pHeader->SDBHdr.Type=SMBIOS_TypeSYSTEM_ENCLOSURE_OR_CHASSIS;
  pHeader->SDBHdr.Length=(uint8_t)stHeaderLength;
  EeeP_Set16BitValue_BE(pHeader->SDBHdr.Handle.b, (uint16_t)pSmbiosChassis_cgf->aulHandle[0]);

  DO(EeePAddBlock(BHandel, pHeader, NULL, pSmbiosChassis_cgf->aulInsideCrc[0]));
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}

EApiStatusCode_t
HandleSmbiosSystemBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  EeePSystemInfo_t *pHeader;
  unsigned int i;
  SmbiosSystem_t *pSmbiosSystem_cgf=pDesc->pDataContainer;
  size_t stHeaderLength=sizeof(*pHeader);
  size_t stBlockLength=0;
  char *pszStrBuffer;

  COUNT_STRLEN(pSmbiosSystem_cgf->aszManuf[0]     );
  COUNT_STRLEN(pSmbiosSystem_cgf->aszProduct[0]   );
  COUNT_STRLEN(pSmbiosSystem_cgf->aszVersion[0]   );
  COUNT_STRLEN(pSmbiosSystem_cgf->aszSerialNum[0] );
  COUNT_STRLEN(pSmbiosSystem_cgf->aszSKU_Number[0]);
  COUNT_STRLEN(pSmbiosSystem_cgf->aszFamily[0]    );

  stBlockLength  +=stHeaderLength+1;
  stBlockLength  +=stBlockLength%2;

  stHeaderLength -=sizeof(DBlockIdHdr_t) ;
  pHeader=calloc(stBlockLength, sizeof(uint8_t));
  EAPI_APP_ASSERT_PARAMATER_NULL(
        HandleSmbiosSystemBlock ,
        EAPI_STATUS_ALLOC_ERROR,
        pHeader
      );


  pHeader->UUID=pSmbiosSystem_cgf->aUUID[0];
  
  pszStrBuffer=(char*)pHeader;
  pszStrBuffer+=sizeof(*pHeader);
  i=0;

  APPEND_STRING(pSmbiosSystem_cgf->aszManuf[0]     , pHeader->Manufacturer);
  APPEND_STRING(pSmbiosSystem_cgf->aszProduct[0]   , pHeader->ProductName );
  APPEND_STRING(pSmbiosSystem_cgf->aszVersion[0]   , pHeader->Version     );
  APPEND_STRING(pSmbiosSystem_cgf->aszSerialNum[0] , pHeader->SerialNumber);
  APPEND_STRING(pSmbiosSystem_cgf->aszSKU_Number[0], pHeader->SKU_Number  );
  APPEND_STRING(pSmbiosSystem_cgf->aszFamily[0]    , pHeader->Family      );

  DO(SetDynBlockHeader(pHeader, EEEP_BLOCK_ID_SMBIOS, stBlockLength));

  pHeader->SDBHdr.Type=SMBIOS_TypeSYSTEM_INFORMATION;
  pHeader->SDBHdr.Length=(uint8_t)stHeaderLength;
  EeeP_Set16BitValue_BE(pHeader->SDBHdr.Handle.b, (uint16_t)pSmbiosSystem_cgf->aulHandle[0]);

  DO(EeePAddBlock(BHandel, pHeader, NULL, pSmbiosSystem_cgf->aulInsideCrc[0]));
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}


EApiStatusCode_t
HandleSmbiosModuleBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  EeePModuleInfo_t *pHeader;
  unsigned int i;
  SmbiosModule_t *pSmbiosModule_cgf=pDesc->pDataContainer;
  size_t stHeaderLength=sizeof(*pHeader)- sizeof(pHeader->Handles[0].b);
  size_t stBlockLength=0;
  SmbiosHandle_t *pHandles1;
  unsigned long *pHandles2;
  char *pszStrBuffer;


  COUNT_STRLEN(pSmbiosModule_cgf->aszManuf[0]     );
  COUNT_STRLEN(pSmbiosModule_cgf->aszProduct[0]   );
  COUNT_STRLEN(pSmbiosModule_cgf->aszVersion[0]   );
  COUNT_STRLEN(pSmbiosModule_cgf->aszSerialNum[0] );
  COUNT_STRLEN(pSmbiosModule_cgf->aszAssetTag[0]  );
  COUNT_STRLEN(pSmbiosModule_cgf->aszLocation[0]  );

  stHeaderLength +=pDesc->pElementsDesc[pDesc->stElementCount - 1].stElementCount*sizeof(pHeader->Handles[0].b);
  stBlockLength  +=stHeaderLength+1;
  stBlockLength  +=stBlockLength%2;

  stHeaderLength -=sizeof(DBlockIdHdr_t) ;
  pHeader=calloc(stBlockLength, sizeof(uint8_t));
  EAPI_APP_ASSERT_PARAMATER_NULL(
        HandleSmbiosModuleBlock ,
        EAPI_STATUS_ALLOC_ERROR,
        pHeader
      );

  pHeader->FeatureFlag   =0   ;
  for(
        i=ARRAY_SIZE(pSmbiosModule_cgf->aulFeatureFlag),
        pHandles2=pSmbiosModule_cgf->aulFeatureFlag;
        i;
        i--,
        pHandles2++
      )
  {
    pHeader->FeatureFlag   |=*pHandles2;
  }
  EeeP_Set16BitValue_BE(pHeader->LocHdl.b  , (uint16_t)pSmbiosModule_cgf->aulLocationHandle[0]);
  pHeader->BoardType     =(uint8_t)pSmbiosModule_cgf->aulBoardType[0]     ;
  pHeader->ContainedHndls=(uint8_t)pDesc->pElementsDesc[pDesc->stElementCount - 1].stElementCount;
  for(
        i=pHeader->ContainedHndls,
        pHandles1=pHeader->Handles,
        pHandles2=pSmbiosModule_cgf->aulHandles;
        i;
        i--,
        pHandles1++,
        pHandles2++
      )
  {
    EeeP_Set16BitValue_BE(pHandles1->b  , (uint16_t)*pHandles2);
  }

  pszStrBuffer=(char*)pHandles1;
  i=0;

  APPEND_STRING(pSmbiosModule_cgf->aszManuf[0]      , pHeader->Manufacturer);
  APPEND_STRING(pSmbiosModule_cgf->aszProduct[0]    , pHeader->Product     );
  APPEND_STRING(pSmbiosModule_cgf->aszVersion[0]    , pHeader->Version     );
  APPEND_STRING(pSmbiosModule_cgf->aszSerialNum[0]  , pHeader->SerialNumber);
  APPEND_STRING(pSmbiosModule_cgf->aszAssetTag[0]   , pHeader->AssetTag    );
  APPEND_STRING(pSmbiosModule_cgf->aszLocation[0]   , pHeader->Location    );

  DO(SetDynBlockHeader(pHeader, EEEP_BLOCK_ID_SMBIOS, stBlockLength));

  pHeader->SDBHdr.Type=SMBIOS_TypeBASE_BOARD_MODULE_INFORMATION;
  pHeader->SDBHdr.Length=(uint8_t)stHeaderLength;
  EeeP_Set16BitValue_BE(pHeader->SDBHdr.Handle.b, (uint16_t)pSmbiosModule_cgf->aulHandle[0]);

  DO(EeePAddBlock(BHandel, pHeader, NULL, pSmbiosModule_cgf->aulInsideCrc[0]));
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}


EApiStatusCode_t
HandleVendorBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  EeePVendBlockHdr_t *pHeader;
  void *pvFileBuffer;
  size_t stFileSize;
  size_t stBlockLength;
  EeePVendorBlock_t *pVendorBlock=pDesc->pDataContainer;
  EApiStatusCode=ReadBinaryFile(pVendorBlock->aszFilename[0], &pvFileBuffer, &stFileSize);
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
        fprintf(stderr, "ERROR: Opening %s\n", pVendorBlock->aszFilename[0]);
        return EApiStatusCode;
  }
  stBlockLength=EeePAlignLength(stFileSize+sizeof(*pHeader));

  pHeader=calloc(stBlockLength, sizeof(uint8_t));
  EAPI_APP_ASSERT_PARAMATER_NULL(
        HandleVendorBlock ,
        EAPI_STATUS_ALLOC_ERROR,
        pHeader
      );

  DO(SetDynBlockHeader(pHeader, EEEP_BLOCK_ID_VENDOR_SPECIFIC, stBlockLength));
  EeeP_Set16BitValue_BE(pHeader->VendId, (uint16_t)pVendorBlock->aulVendorId[0]);
  pHeader->VendBlockId=(uint8_t)pVendorBlock->aulVSBlockId[0];
  memcpy(
      EAPI_CREATE_PTR(pHeader, sizeof(*pHeader), void*), 
      pvFileBuffer, 
      stFileSize
    );

  DO(EeePAddBlock(BHandel, pHeader, NULL, pVendorBlock->aulInsideCrc[0]));
  free(pvFileBuffer);
  pvFileBuffer=NULL;
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}


EApiStatusCode_t
HandleLFPDescBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  EeePLFPDataBlock_t *pHeader;
  void *pvFileBuffer;
  size_t stFileSize;
  size_t stBlockLength;
  EeePLFP_t *pLfpBlock=pDesc->pDataContainer;
  EApiStatusCode=ReadBinaryFile(pLfpBlock->aszFilename[0], &pvFileBuffer, &stFileSize);
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
        fprintf(stderr, "ERROR: Opening %s\n", pLfpBlock->aszFilename[0]);
        return EApiStatusCode;
  }
  stBlockLength=EeePAlignLength(stFileSize+sizeof(*pHeader) - sizeof(pHeader->RawData));

  pHeader=calloc(stBlockLength, sizeof(uint8_t));
  EAPI_APP_ASSERT_PARAMATER_NULL(
        HandleLFPDescBlock ,
        EAPI_STATUS_ALLOC_ERROR,
        pHeader
      );

  DO(SetDynBlockHeader(pHeader, EEEP_BLOCK_ID_LFP, stBlockLength));
  pHeader->Interface=(uint8_t)pLfpBlock->aulInterface[0];

  memcpy( pHeader->RawData, pvFileBuffer, stFileSize);

  DO(EeePAddBlock(BHandel, pHeader, NULL, pLfpBlock->aulInsideCrc[0]));
  free(pvFileBuffer);
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}


EApiStatusCode_t
HandleCustomBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  DBlockIdHdr_t *pHeader;
  void *pvFileBuffer;
  size_t stFileSize;
  size_t stBlockLength;
  EeePCustomBlock_t *pCustomBlock=pDesc->pDataContainer;
  EApiStatusCode=ReadBinaryFile(pCustomBlock->aszFilename[0], &pvFileBuffer, &stFileSize);
  if(EAPI_STATUS_TEST_NOK(EApiStatusCode)){
        fprintf(stderr, "ERROR: Opening %s\n", pCustomBlock->aszFilename[0]);
        return EApiStatusCode;
  }
  stBlockLength=EeePAlignLength(stFileSize+sizeof(*pHeader));

  pHeader=calloc(stBlockLength, sizeof(uint8_t));
  EAPI_APP_ASSERT_PARAMATER_NULL(
        HandleCustomBlock ,
        EAPI_STATUS_ALLOC_ERROR,
        pHeader
      );

  DO(SetDynBlockHeader(pHeader, (uint8_t)pCustomBlock->aulBlockId[0], stBlockLength));

  memcpy( EAPI_CREATE_PTR(pHeader, sizeof(*pHeader), void*), pvFileBuffer, stFileSize);

  DO(EeePAddBlock(BHandel, pHeader, NULL, pCustomBlock->aulInsideCrc[0]));
  free(pvFileBuffer);
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}


CfgBlockDesc_t COM0R20_CB_CfgDesc[]={
  BLOCK_DESC("COM0R20_CB"         , COM0R20_CB_Desc        , &COM0R20_CB_cgf        , HandleCOM0R20CBHeaderBlock  , BLOCK_REQUIRED)
  BLOCK_DESC("SmbiosCarrier"      , SmbiosCarrierDesc      , &COM0_SMBIOS_Carrier   , HandleSmbiosModuleBlock     , BLOCK_OPTIONAL)
  BLOCK_DESC("SmbiosSystem"       , SmbiosSystemDesc       , &COM0_SMBIOS_System    , HandleSmbiosSystemBlock     , BLOCK_OPTIONAL)
  BLOCK_DESC("SmbiosChassis"      , SmbiosChassisDesc      , &COM0_SMBIOS_Chassis   , HandleSmbiosChassisBlock    , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData0"           , LFPData0Desc           , &EeeP_LFP0_Cfg         , HandleLFPDescBlock          , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData1"           , LFPData1Desc           , &EeeP_LFP1_Cfg         , HandleLFPDescBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("ExtI2CDevice0"      , ExtI2CDevice0Desc      , &EeePExtI2CDevice0     , HandleEeePExpI2CBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("ExtI2CDevice1"      , ExtI2CDevice1Desc      , &EeePExtI2CDevice1     , HandleEeePExpI2CBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_Exp0Card"   , COM0R20_ExpCard0Desc   , &COM0R20_ECard0_cgf    , HandleCOM0R20ExpCardCfgBlock, BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_Exp1Card"   , COM0R20_ExpCard1Desc   , &COM0R20_ECard1_cgf    , HandleCOM0R20ExpCardCfgBlock, BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_SerialPorts", COM0R20_SerialPortsDesc, &COM0R20_SER_cgf       , HandleCOM0R20SerialCfgBlock , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock0"       , VendorBlock0Desc       , &EeeP_VendorBlock0_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock1"       , VendorBlock1Desc       , &EeeP_VendorBlock1_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock2"       , VendorBlock2Desc       , &EeeP_VendorBlock2_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock3"       , VendorBlock3Desc       , &EeeP_VendorBlock3_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock4"       , VendorBlock4Desc       , &EeeP_VendorBlock4_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock5"       , VendorBlock5Desc       , &EeeP_VendorBlock5_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock6"       , VendorBlock6Desc       , &EeeP_VendorBlock6_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock0"       , CustomBlock0Desc       , &EeeP_CustomBlock0_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock1"       , CustomBlock1Desc       , &EeeP_CustomBlock1_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock2"       , CustomBlock2Desc       , &EeeP_CustomBlock2_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock3"       , CustomBlock3Desc       , &EeeP_CustomBlock3_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock4"       , CustomBlock4Desc       , &EeeP_CustomBlock4_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock5"       , CustomBlock5Desc       , &EeeP_CustomBlock5_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock6"       , CustomBlock6Desc       , &EeeP_CustomBlock6_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
};

CfgBlockDesc_t COM0R20_M_CfgDesc[]={
  BLOCK_DESC("COM0R20_M"          , COM0R20_M_Desc         , &COM0R20_M_cgf         , HandleCOM0R20MHeaderBlock, BLOCK_REQUIRED)
  BLOCK_DESC("SmbiosModule"       , SmbiosModuleDesc       , &COM0_SMBIOS_Module    , HandleSmbiosModuleBlock  , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData0"           , LFPData0Desc           , &EeeP_LFP0_Cfg         , HandleLFPDescBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData1"           , LFPData1Desc           , &EeeP_LFP1_Cfg         , HandleLFPDescBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock0"       , VendorBlock0Desc       , &EeeP_VendorBlock0_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock1"       , VendorBlock1Desc       , &EeeP_VendorBlock1_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock2"       , VendorBlock2Desc       , &EeeP_VendorBlock2_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock3"       , VendorBlock3Desc       , &EeeP_VendorBlock3_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock4"       , VendorBlock4Desc       , &EeeP_VendorBlock4_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock5"       , VendorBlock5Desc       , &EeeP_VendorBlock5_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock6"       , VendorBlock6Desc       , &EeeP_VendorBlock6_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock0"       , CustomBlock0Desc       , &EeeP_CustomBlock0_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock1"       , CustomBlock1Desc       , &EeeP_CustomBlock1_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock2"       , CustomBlock2Desc       , &EeeP_CustomBlock2_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock3"       , CustomBlock3Desc       , &EeeP_CustomBlock3_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock4"       , CustomBlock4Desc       , &EeeP_CustomBlock4_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock5"       , CustomBlock5Desc       , &EeeP_CustomBlock5_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock6"       , CustomBlock6Desc       , &EeeP_CustomBlock6_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
};

CfgBlockDesc_t EeePExpEEP_CfgDesc[]={
  BLOCK_DESC("EeePExpEEP"         , EeePExpHdr_Desc        , &EeePExpHdr_cgf        , HandleEeePExpEepHeaderBlock , BLOCK_REQUIRED)
  BLOCK_DESC("SmbiosCarrier"      , SmbiosCarrierDesc      , &COM0_SMBIOS_Carrier   , HandleSmbiosModuleBlock     , BLOCK_OPTIONAL)
  BLOCK_DESC("SmbiosSystem"       , SmbiosSystemDesc       , &COM0_SMBIOS_System    , HandleSmbiosSystemBlock     , BLOCK_OPTIONAL)
  BLOCK_DESC("SmbiosChassis"      , SmbiosChassisDesc      , &COM0_SMBIOS_Chassis   , HandleSmbiosChassisBlock    , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData0"           , LFPData0Desc           , &EeeP_LFP0_Cfg         , HandleLFPDescBlock          , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData1"           , LFPData1Desc           , &EeeP_LFP1_Cfg         , HandleLFPDescBlock          , BLOCK_OPTIONAL)
  BLOCK_DESC("ExtI2CDevice0"      , ExtI2CDevice0Desc      , &EeePExtI2CDevice0     , HandleEeePExpI2CBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("ExtI2CDevice1"      , ExtI2CDevice1Desc      , &EeePExtI2CDevice1     , HandleEeePExpI2CBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_Exp0Card"   , COM0R20_ExpCard0Desc   , &COM0R20_ECard0_cgf    , HandleCOM0R20ExpCardCfgBlock, BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_Exp1Card"   , COM0R20_ExpCard1Desc   , &COM0R20_ECard1_cgf    , HandleCOM0R20ExpCardCfgBlock, BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_SerialPorts", COM0R20_SerialPortsDesc, &COM0R20_SER_cgf       , HandleCOM0R20SerialCfgBlock , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock0"       , VendorBlock0Desc       , &EeeP_VendorBlock0_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock1"       , VendorBlock1Desc       , &EeeP_VendorBlock1_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock2"       , VendorBlock2Desc       , &EeeP_VendorBlock2_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock3"       , VendorBlock3Desc       , &EeeP_VendorBlock3_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock4"       , VendorBlock4Desc       , &EeeP_VendorBlock4_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock5"       , VendorBlock5Desc       , &EeeP_VendorBlock5_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock6"       , VendorBlock6Desc       , &EeeP_VendorBlock6_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock0"       , CustomBlock0Desc       , &EeeP_CustomBlock0_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock1"       , CustomBlock1Desc       , &EeeP_CustomBlock1_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock2"       , CustomBlock2Desc       , &EeeP_CustomBlock2_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock3"       , CustomBlock3Desc       , &EeeP_CustomBlock3_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock4"       , CustomBlock4Desc       , &EeeP_CustomBlock4_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock5"       , CustomBlock5Desc       , &EeeP_CustomBlock5_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock6"       , CustomBlock6Desc       , &EeeP_CustomBlock6_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
};



EApiStatusCode_t
EeeP_CreateEEPROMImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName,
    __IN   CfgBlockDesc_t * pCfgBlockDesc ,
    __IN   size_t           stCfgBlockCnt ,
    __IN   unsigned long  * pulEEPSize    ,
    __IN   size_t           stHeaderSize 
    )
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  CfgBlockDesc_t *pDesc;
  size_t i;
  EAPI_APP_ASSERT_PARAMATER_NULL(
        EeeP_CreateEEPROMImage,
        EAPI_STATUS_INVALID_PARAMETER,
        cszCfgFileName
      );
  EAPI_APP_ASSERT_PARAMATER_NULL(
        EeeP_CreateEEPROMImage,
        EAPI_STATUS_INVALID_PARAMETER,
        pCfgBlockDesc
      );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
        EeeP_CreateEEPROMImage,
        EAPI_STATUS_INVALID_PARAMETER,
        stCfgBlockCnt
      );
  EAPI_APP_ASSERT_PARAMATER_NULL(
        EeeP_CreateEEPROMImage,
        EAPI_STATUS_INVALID_PARAMETER,
        pulEEPSize
      );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
        EeeP_CreateEEPROMImage,
        EAPI_STATUS_INVALID_PARAMETER,
        stHeaderSize
      );
  /*
   * 
   */
  DO(ParseCfgFile(cszCfgFileName, pCfgBlockDesc, stCfgBlockCnt));
  /*
   * 
   */
  DO(EeePCreateNewBuffer(pBHandel, 256<<*pulEEPSize, stHeaderSize, EEEP_INIT_INCLUDE_CRC));
  /*
   * 
   */
  for(i=stCfgBlockCnt, pDesc=pCfgBlockDesc; i; i--, pDesc++){
    if(pDesc->uiFound&&(pDesc->Handler!=NULL))
      DO(pDesc->Handler(pDesc, *pBHandel));
  }
  DO(EeePSetCRC(*pBHandel));
  /*
   * 
   */
/*   PrintHexAsciiTable( */
/*       *pBHandel,  */
/*       256<<*pulEEPSize,  */
/*       *pBHandel,  */
/*       NULL */
/*     ); */
  /*
   * 
   */
  DO(CleanStruct(pCfgBlockDesc, stCfgBlockCnt));

EAPI_APP_ASSERT_EXIT
  return EApiStatusCode;
}
EApiStatusCode_t
EeeP_CreateCOM0R20_CBImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    )
{
  return EeeP_CreateEEPROMImage(
        pBHandel                              ,
        cszCfgFileName                        ,
        COM0R20_CB_CfgDesc                    , 
        ARRAY_SIZE(COM0R20_CB_CfgDesc)        ,
        COM0R20_CB_cgf.aulDeviceSize  ,
        sizeof(COM0R20_CB_t)
      );
}
EApiStatusCode_t
EeeP_CreateCOM0R20_MEEPImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    )
{
  return EeeP_CreateEEPROMImage(
        pBHandel                              ,
        cszCfgFileName                        ,
        COM0R20_M_CfgDesc                     , 
        ARRAY_SIZE(COM0R20_M_CfgDesc)         ,
        COM0R20_M_cgf.aulDeviceSize   ,
        sizeof(COM0R20_M_t)
      );
}
EApiStatusCode_t
EeeP_CreateEeePExtEEPImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    )
{
  return EeeP_CreateEEPROMImage(
        pBHandel                              ,
        cszCfgFileName                        ,
        EeePExpEEP_CfgDesc                    ,
        ARRAY_SIZE(EeePExpEEP_CfgDesc)        ,
        EeePExpHdr_cgf.aulDeviceSize   ,
        sizeof(Exp_EEP_t)
      );
}

EApiStatusCode_t
EeeP_CreateCOM0R20_CBCfg(
    __OUT  FILE           * OutStream
    )
{
  return  PrintCfgFile(
      COM0R20_CB_CfgDesc, 
      ARRAY_SIZE(COM0R20_CB_CfgDesc), 
      OutStream
    );
}

EApiStatusCode_t
EeeP_CreateCOM0R20_MEEPCfg(
    __OUT  FILE           * OutStream
    )
{
  return  PrintCfgFile(
      COM0R20_M_CfgDesc, 
      ARRAY_SIZE(COM0R20_M_CfgDesc), 
      OutStream
    );
}

EApiStatusCode_t
EeeP_CreateEeePExtEEPCfg(
    __OUT  FILE           * OutStream
    )
{
  return  PrintCfgFile(
      EeePExpEEP_CfgDesc, 
      ARRAY_SIZE(EeePExpEEP_CfgDesc), 
      OutStream
    );
}

#if TEST_EEPCFG
#define DO_MAIN(x)  \
  do{\
  EAPI_printf(        \
      TEXT("#####\n") \
      TEXT("#\t%s\n") \
      TEXT("#####\n"),\
      TEXT(#x)        \
    );                \
  EApiStatusCode=x;   \
  if(!EAPI_STATUS_TEST_OK(EApiStatusCode)) \
    goto ErrorExit; \
  }while(0)

/*
 * Create Block Content
 */
int 
__cdecl 
main(void)
{
  EApiStatusCode_t EApiStatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t     BHandel ;

#ifdef _DEBUG
  _CrtSetDbgFlag( _CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag());
#endif

  DO_MAIN(EeeP_CreateCOM0R20_CBImage(
        &BHandel                              ,
        "COM0R20_CB.cfg"
      ));
  DO(EeePFreeBuffer(&BHandel));
  DO_MAIN(EeeP_CreateCOM0R20_MEEPImage(
        &BHandel                              ,
        "COM0R20_M.cfg"
      ));
  DO(EeePFreeBuffer(&BHandel));
  DO_MAIN(EeeP_CreateEeePExtEEPImage(
        &BHandel                              ,
        "EeePExpEEP.cfg"
      ));
  DO(EeePFreeBuffer(&BHandel));


  DO_MAIN(EeeP_CreateCOM0R20_CBCfg(stdout));
  DO_MAIN(EeeP_CreateCOM0R20_MEEPCfg(stdout));
  DO_MAIN(EeeP_CreateEeePExtEEPCfg(stdout));

EAPI_APP_ASSERT_EXIT
  exit(EApiStatusCode);
}

#endif
