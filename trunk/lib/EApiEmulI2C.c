/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL$
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
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
 *I Description: Auto Created for EApiEmulI2C.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiEmulI2C.c
 *I  File Location        : lib
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */

#include <EApiLib.h>
#include <stdio.h>

#define END_OF_LIST_MARK ((uint32_t)-1)


/*
 *
 *  
 *
 *      I2C  Emulation
 *
 *
 *
 */
#define I2C_EMUL_FREQ  100000
#define I2C_EMUL_BYTE_DELAY_NS (1000000000/I2C_EMUL_FREQ*(8+1))
typedef 
uint32_t 
I2CDevEmulator(
    __IN uint32_t Arg1, 
    __IN void *pWBuffer, 
    __IN uint32_t WriteBCnt, 
    __OUT void *pRBuffer, 
    __IN uint32_t ReadBCnt
    );

I2CDevEmulator EmulateDIDEeprom;
I2CDevEmulator EmulateUDSEeprom;
I2CDevEmulator EmulateEPIEeprom;
I2CDevEmulator EmulatePICMGEeprom;

typedef struct CmdDesc_s{
  const unsigned long Cmd           ;/* Cmd */
  const unsigned long CmdBlockLen   ;/* Cmd Buffer Length */
  void     *const pBuffer      ;/* Cmd Content */ 
}CmdDesc_t;
typedef struct CmdDeviceCfgData_s{
  const unsigned long ExtendedCmd   ;/* Ext/Std Index */
  unsigned long CurrentCmd    ;/* Ext/Std Index */
  unsigned long CurrentOffset ;/* Ext/Std Index */
  const char *const cszDeviceName;
  CmdDesc_t *const Cmds        ;/* Commands Buffer pointer */ 
}CmdDeviceCfgData_t;

typedef struct EepromCfgData_s{
  const unsigned long ByteLen       ;/* EEPROM Length */
  const unsigned long ExtendedCmd   ;/* Ext/Std Index */
  const unsigned long PageLength    ;/* Write Page Alignment size */
#define STD_INDEX 1                  
#define EXT_INDEX 2                  
  unsigned long CurIndx       ;/* Current Index Value */
  uint8_t  *const pu8DBuffer   ;/* Eeprom pBuffer Pointer */ 
  const char *const cszFilename;
  FILE     *FStream;
}EepromCfgData_t;

typedef struct BusDevicesTbl_s{
  const unsigned long EncAddr         ;/* Device Address */
  I2CDevEmulator *const Emulator ;/* Emulator */
  const unsigned long Arg1            ;/* Argument to pass to Emulator */
}BusDevicesTbl_t;
#if (STRICT_VALIDATION>1)
char * StdExt[]={
  "   ",
  "Std",
  "Ext"
};
#endif

uint32_t 
EmulateEepromFS(
    __IN unsigned long Arg1, 
    __IN EepromCfgData_t *CfgData, 
    __IN uint8_t *pWBuffer, 
    __IN unsigned long WriteBCnt, 
    __OUT uint8_t *pRBuffer, 
    __IN unsigned long ReadBCnt
    )
{
  
#if (STRICT_VALIDATION>1)
  EAPI_LIB_MSG_OUT((
        "O%04u %-30s : %-30s : %3s CIDX=%04lX Arg1=%1lX DLEN=%04lX PLEN=%04lX"
        " WLEN=%04lX RLEN=%04lX %02"PRIX8",%02"PRIX8",%02"PRIX8",%02"PRIX8"\n", 
        __LINE__, 
        "EmulateEepromFS", 
        CfgData->cszFilename, 
        StdExt[CfgData->ExtendedCmd], 
        CfgData->CurIndx, 
        Arg1, 
        CfgData->ByteLen, 
        CfgData->PageLength, 
        WriteBCnt, 
        ReadBCnt, 
        pWBuffer[0],
        pWBuffer[1],
        pWBuffer[2],
        pWBuffer[3]
      ));
#endif
  if(WriteBCnt)
  {
    switch((CfgData->ExtendedCmd))  {      /* Emulate Standard IDX/CMD 
                                                    Device */
      case STD_INDEX:
        CfgData->CurIndx=*pWBuffer++;
        WriteBCnt--;
        CfgData->CurIndx|=Arg1<<8;                 /* Add the Device Address 
                                                      Index */
        EAPI_EMUL_DELAY_NS(I2C_EMUL_BYTE_DELAY_NS);
        break;
      case EXT_INDEX:                             /* Emulate Extended IDX/CMD
                                                    Device */
        EAPI_LIB_RETURN_ERROR_IF(
            EmulateEepromFS, 
            WriteBCnt<2, 
            EAPI_STATUS_READ_ERROR, 
            " STD INDEX Sent to EXT INDEX EEPROM"
            );

        CfgData->CurIndx =pWBuffer[0]<<8;
        CfgData->CurIndx|=pWBuffer[1];
        pWBuffer+=2;
        WriteBCnt-=2;
        CfgData->CurIndx|=Arg1<<16;                /* Add the Device Address Index */
        EAPI_EMUL_DELAY_NS(I2C_EMUL_BYTE_DELAY_NS*2);
        break;
      default:
        break;
    }
#if (STRICT_VALIDATION>1)
    EAPI_LIB_MSG_OUT((
          "O%04u %-30s : %-30s : CINDX=%04lX PLEN=%04lX EPLEN=%04lX\n", 
          __LINE__, 
          "EmulateEepromFS", 
          CfgData->cszFilename, 
          CfgData->CurIndx, 
          CfgData->CurIndx%CfgData->PageLength, 
          (CfgData->CurIndx%CfgData->PageLength)+WriteBCnt)
        );
#endif
    if(WriteBCnt)
    {
      EAPI_LIB_RETURN_ERROR_IF(
          EmulateEepromFS,
          ((CfgData->CurIndx%CfgData->PageLength)+WriteBCnt)>CfgData->PageLength,
          EAPI_STATUS_WRITE_ERROR, 
          "Device Page Wrap around"
          );
      EAPI_LIB_RETURN_ERROR_IF(
          EmulateEepromFS,
          (CfgData->CurIndx+WriteBCnt)>CfgData->ByteLen   , 
          EAPI_STATUS_WRITE_ERROR, 
          "Device Write Wrap around"
          );

      EAPI_EMUL_DELAY_NS(I2C_EMUL_BYTE_DELAY_NS*WriteBCnt);
      fseek(CfgData->FStream, CfgData->CurIndx, SEEK_SET);
      EAPI_LIB_RETURN_ERROR_IF(
          EmulateEepromFS,
          WriteBCnt!=fwrite(pWBuffer, sizeof(uint8_t), WriteBCnt, CfgData->FStream), 
          EAPI_STATUS_WRITE_ERROR, 
          "Device Write Error"
          );
      CfgData->CurIndx+=WriteBCnt;
    }
  }

  if(ReadBCnt)
  {
    EAPI_LIB_RETURN_ERROR_IF(
        EmulateEepromFS,
        (CfgData->CurIndx+ReadBCnt)>CfgData->ByteLen      , 
        EAPI_STATUS_READ_ERROR, 
        "Device Read Wrap around"
        );

    EAPI_EMUL_DELAY_NS(I2C_EMUL_BYTE_DELAY_NS*ReadBCnt);
    fseek(CfgData->FStream, CfgData->CurIndx, SEEK_SET);
    EAPI_LIB_RETURN_ERROR_IF(
        EmulateEepromFS,
        ReadBCnt!=fread(pRBuffer, sizeof(uint8_t), ReadBCnt, CfgData->FStream), 
        EAPI_STATUS_READ_ERROR, 
        "Device Read Error"
        );
    CfgData->CurIndx+=ReadBCnt;
  }
  EAPI_LIB_RETURN_SUCCESS(EmulateEepromFS, "");
}


uint32_t 
EmulateCmdDevice(
    __IN unsigned long  Arg1, 
    __IN CmdDeviceCfgData_t *CfgData, 
    __IN uint8_t *pWBuffer, 
    __IN unsigned long WriteBCnt, 
    __OUT uint8_t *pRBuffer, 
    __IN unsigned long ReadBCnt
    )
{
    unsigned long ReadBCnt2;
    CmdDesc_t *pCurCmd;
  
#if (STRICT_VALIDATION>1)
  EAPI_LIB_MSG_OUT((
        "O%04u %-30s : %-30s : %3s CCMD=%04lX Arg1=%1lX "
        " WLEN=%04lX RLEN=%04lX %02"PRIX8",%02"PRIX8",%02"PRIX8",%02"PRIX8"\n", 
        __LINE__, 
        "EmulateCmdDevice", 
        CfgData->cszDeviceName, 
        StdExt[CfgData->ExtendedCmd], 
        CfgData->CurrentCmd, 
        Arg1, 
        WriteBCnt, 
        ReadBCnt, 
        pWBuffer[0],
        pWBuffer[1],
        pWBuffer[2],
        pWBuffer[3]
      ));
#endif
  if(WriteBCnt)
  {
    switch((CfgData->ExtendedCmd))  {      /* Emulate Standard IDX/CMD 
                                                    Device */
      case STD_INDEX:
        CfgData->CurrentCmd=*pWBuffer++;
        WriteBCnt--;
        EAPI_EMUL_DELAY_NS(I2C_EMUL_BYTE_DELAY_NS);
        break;
      case EXT_INDEX:                             /* Emulate Extended IDX/CMD
                                                    Device */
        EAPI_LIB_RETURN_ERROR_IF(
            EmulateEepromFS, 
            WriteBCnt<2, 
            EAPI_STATUS_READ_ERROR, 
            " STD INDEX Sent to EXT INDEX EEPROM"
            );

        CfgData->CurrentCmd =pWBuffer[0]<<8;
        CfgData->CurrentCmd|=pWBuffer[1];
        pWBuffer+=2;
        WriteBCnt-=2;
        EAPI_EMUL_DELAY_NS(I2C_EMUL_BYTE_DELAY_NS*2);
        break;
      default:
        break;
    }
    if(WriteBCnt)
    {
      EAPI_EMUL_DELAY_NS(I2C_EMUL_BYTE_DELAY_NS*WriteBCnt);
      for(pCurCmd=CfgData->Cmds;pCurCmd->Cmd!=END_OF_LIST_MARK;pCurCmd++){
        if(pCurCmd->Cmd==CfgData->CurrentCmd){
          ReadBCnt2=pCurCmd->CmdBlockLen;
          memcpy(
            pCurCmd->pBuffer, 
            pRBuffer, 
            (ReadBCnt>ReadBCnt2?ReadBCnt2:ReadBCnt)
            );
        }
      }
    }
  }
  if(ReadBCnt)
  {
    EAPI_EMUL_DELAY_NS(I2C_EMUL_BYTE_DELAY_NS*ReadBCnt);
    for(pCurCmd=CfgData->Cmds;pCurCmd->Cmd!=END_OF_LIST_MARK;pCurCmd++){
      if(pCurCmd->Cmd==CfgData->CurrentCmd){
        ReadBCnt2=pCurCmd->CmdBlockLen;
        if(ReadBCnt2<ReadBCnt){
          memcpy(pRBuffer, pCurCmd->pBuffer, ReadBCnt2);
          memset(pRBuffer+ReadBCnt2, ReadBCnt-ReadBCnt2, 0xFF);
        }else{
          memcpy(pRBuffer, pCurCmd->pBuffer, ReadBCnt);
        }
      }
    }
  }
  EAPI_LIB_RETURN_SUCCESS(EmulateEepromFS, "");
}
#define bin_data DIDEEPROM
#include "DIDData.h"
#undef bin_data
static EepromCfgData_t DIDEEPromData={
  sizeof(DIDEEPROM),  /* EEPROM Length */
  EXT_INDEX        ,  /* Ext/Std Index */
  256              ,  /* Device Page Length */
  0                ,  /* Current Index Value */
  DIDEEPROM        ,  /* EEPROM pBuffer Pointer */
  "DID.EEPROM.EMUL",
  NULL
};
uint32_t 
EmulateDIDEeprom(
    __IN uint32_t Arg1, 
    __IN void *pWBuffer, 
    __IN uint32_t WriteBCnt, 
    __OUT void *pRBuffer, 
    __IN uint32_t ReadBCnt
    )
{
  return EmulateEepromFS(
      Arg1, 
      &DIDEEPromData, 
      pWBuffer, 
      WriteBCnt, 
      pRBuffer, 
      ReadBCnt
      );
}
#define bin_data UDSEEPROM
#include "UDSData.h"
#undef bin_data
static EepromCfgData_t UDSEEPromData={
  sizeof(UDSEEPROM),  /* EEPROM Length */
  STD_INDEX        ,  /* Ext/Std Index */
  16               ,  /* Device Page Length */
  0                ,  /* Current Index Value */
  UDSEEPROM        ,  /* EEPROM pBuffer Pointer */
  "UDS.EEPROM.EMUL",
  NULL
};
uint32_t 
EmulateUDSEeprom(
    __IN uint32_t Arg1, 
    __IN void *pWBuffer, 
    __IN uint32_t WriteBCnt, 
    __OUT void *pRBuffer, 
    __IN uint32_t ReadBCnt
    )
{
  return EmulateEepromFS(
      Arg1, 
      &UDSEEPromData, 
      pWBuffer, 
      WriteBCnt, 
      pRBuffer, 
      ReadBCnt
      );
}
#define bin_data EPIEEPROM
#include "EPIData.h"
#undef bin_data
static EepromCfgData_t EPIEEPromData={
  sizeof(EPIEEPROM),  /* EEPROM Length */
  STD_INDEX        ,  /* Ext/Std Index */
  16               ,  /* Device Page Length */
  0                ,  /* Current Index Value */
  EPIEEPROM        ,  /* EEPROM pBuffer Pointer */ 
  "EPI.EEPROM.EMUL",
  NULL
};

uint32_t 
EmulateEPIEeprom(
    __IN uint32_t Arg1, 
    __IN void *pWBuffer, 
    __IN uint32_t WriteBCnt, 
    __OUT void *pRBuffer, 
    __IN uint32_t ReadBCnt
    )
{
  return EmulateEepromFS(
      Arg1, 
      &EPIEEPromData, 
      pWBuffer, 
      WriteBCnt, 
      pRBuffer, 
      ReadBCnt
      );
}
/* #define bin_data PICMGEEPROM
 * #include "EPIData.h"
 * #undef bin_data
 */
uint8_t COM0MEEPROM[2048]={0};
static EepromCfgData_t COM0MEEPromData={
  sizeof(COM0MEEPROM),  /* EEPROM Length */
  EXT_INDEX          ,  /* Ext/Std Index */
  16                 ,  /* Max Block Write Length */
  0                  ,  /* Current Index Value */
  COM0MEEPROM        ,  /* EEPROM pBuffer Pointer */ 
  "COM0R20-M.EEPROM.EMUL" ,
  NULL
};
uint8_t COM0CBEEPROM[4096]={0};
static EepromCfgData_t COM0CBEEPromData={
  sizeof(COM0CBEEPROM), /* EEPROM Length */
  EXT_INDEX          ,  /* Ext/Std Index */
  64                 ,  /* Max Block Write Length */
  0                  ,  /* Current Index Value */
  COM0CBEEPROM       ,  /* EEPROM pBuffer Pointer */ 
  "COM0R20-CB.EEPROM.EMUL",
  NULL
};
uint8_t EeePExpEEPROM[1024]={0};
static EepromCfgData_t EeePExpEEPromData={
  sizeof(EeePExpEEPROM), /* EEPROM Length */
  STD_INDEX          ,  /* Ext/Std Index */
  8                  ,  /* Max Block Write Length */
  0                  ,  /* Current Index Value */
  EeePExpEEPROM      ,  /* EEPROM pBuffer Pointer */ 
  "EeePExp.EEPROM.EMUL",
  NULL
};
EepromCfgData_t *OpenFiles[]={
  &EeePExpEEPromData,
  &COM0CBEEPromData,
  &COM0MEEPromData,
  &EPIEEPromData,
  &UDSEEPromData,
  &DIDEEPromData,
};


uint32_t 
OpenI2CEepromFiles(void)
{
  int i;
  EepromCfgData_t **pOpenFiles=OpenFiles;
  for(i=ARRAY_SIZE(OpenFiles); i; i--, pOpenFiles++){
    (*pOpenFiles)->FStream=fopen((*pOpenFiles)->cszFilename, "rb+");
    if((*pOpenFiles)->FStream==NULL){
      (*pOpenFiles)->FStream=fopen((*pOpenFiles)->cszFilename, "wb+");
    }
    if((*pOpenFiles)->FStream!=NULL){
        fseek((*pOpenFiles)->FStream, 0, SEEK_END);
        if(ftell((*pOpenFiles)->FStream)<(signed)(*pOpenFiles)->ByteLen){
          rewind((*pOpenFiles)->FStream);
          fwrite((*pOpenFiles)->pu8DBuffer, sizeof(uint8_t), (*pOpenFiles)->ByteLen, (*pOpenFiles)->FStream);
      }
    }
  }
  return EAPI_STATUS_SUCCESS;
}
uint32_t 
CloseI2CEepromFiles(void)
{
  int i;
  EepromCfgData_t **pOpenFiles=OpenFiles;
  for(i=ARRAY_SIZE(OpenFiles); i; i--, pOpenFiles++){
    if((*pOpenFiles)->FStream!=NULL){
      fclose((*pOpenFiles)->FStream);
      (*pOpenFiles)->FStream=NULL;
    }
  }
  return EAPI_STATUS_SUCCESS;
}

uint32_t 
EmulateEeePExpEeprom(
    __IN uint32_t Arg1, 
    __IN void *pWBuffer, 
    __IN uint32_t WriteBCnt, 
    __OUT void *pRBuffer, 
    __IN uint32_t ReadBCnt
    )
{
  return EmulateEepromFS(
      Arg1, 
      &EeePExpEEPromData, 
      pWBuffer, 
      WriteBCnt, 
      pRBuffer, 
      ReadBCnt
      );
}


uint32_t 
EmulateCOM0CBEeprom(
    __IN uint32_t Arg1, 
    __IN void *pWBuffer, 
    __IN uint32_t WriteBCnt, 
    __OUT void *pRBuffer, 
    __IN uint32_t ReadBCnt
    )
{
  return EmulateEepromFS(
      Arg1, 
      &COM0CBEEPromData, 
      pWBuffer, 
      WriteBCnt, 
      pRBuffer, 
      ReadBCnt
      );
}

uint32_t 
EmulateCOM0MEeprom(
    __IN uint32_t Arg1, 
    __IN void *pWBuffer, 
    __IN uint32_t WriteBCnt, 
    __OUT void *pRBuffer, 
    __IN uint32_t ReadBCnt
    )
{
  return EmulateEepromFS(
      Arg1, 
      &COM0MEEPromData, 
      pWBuffer, 
      WriteBCnt, 
      pRBuffer, 
      ReadBCnt
      );
}

int8_t CpuTemp[1]={56};
int8_t ChipsetTemp[1]={46};
int8_t SystemTemp[1]={- 46};
CmdDesc_t HwmonCmdIndx[]={
  {0x0010, ARRAY_SIZE(CpuTemp)    , CpuTemp    },
  {0x0011, ARRAY_SIZE(ChipsetTemp), ChipsetTemp},
  {0x0012, ARRAY_SIZE(SystemTemp) , SystemTemp },
  {END_OF_LIST_MARK, 0 , NULL },
};
CmdDeviceCfgData_t HWMon={
  STD_INDEX,
  0,
  0,
  "ADT7447",
  HwmonCmdIndx
};
uint32_t 
EmulateHWMonDevice(
    __IN  uint32_t Arg1, 
    __IN  void    *pWBuffer, 
    __IN  uint32_t WriteBCnt, 
    __OUT void    *pRBuffer, 
    __IN  uint32_t ReadBCnt
    )
{
  return EmulateCmdDevice(
      Arg1, 
      &HWMon, 
      pWBuffer, 
      WriteBCnt, 
      pRBuffer, 
      ReadBCnt
      );
}

const BusDevicesTbl_t ExternalI2CDevices[]={
/* Device      Device         BLCK*/
/* Address    Emulator        CNT */
  {0x0052, EmulateHWMonDevice  , 0},
  {0x00A0, EmulateCOM0MEeprom  , 0},
  {0x00A2, EmulateEeePExpEeprom, 0},
  {0x00A4, EmulateEeePExpEeprom, 1},
  {0x00A6, EmulateEeePExpEeprom, 2},
  {0x00A8, EmulateEeePExpEeprom, 3},
  {0x00AE, EmulateCOM0CBEeprom , 0},
  {END_OF_LIST_MARK, NULL, 0}
};
const BusDevicesTbl_t LVDS_1I2CDevices[]={
/* Device      Device         BLCK*/
/* Address    Emulator        CNT */
  {0x00A0, EmulateUDSEeprom, 0},
  {0x00A2, EmulateUDSEeprom, 1},
  {0x00A4, EmulateDIDEeprom, 0},
  {0xF255, EmulateDIDEeprom, 0},
  {END_OF_LIST_MARK, NULL, 0}
};
const BusDevicesTbl_t LVDS_2I2CDevices[]={
/* Device      Device         BLCK*/
/* Address    Emulator        CNT */
  {0x00A0, EmulateEPIEeprom, 0},
  {0x00A2, EmulateEPIEeprom, 1},
  {0x00A4, EmulateDIDEeprom, 0},
  {END_OF_LIST_MARK, NULL, 0}
};

typedef struct InterfaceIdsTbl_s{
  const uint32_t         Id         ; /* I2C EAPI Bus Id */
  const BusDevicesTbl_t *DevicesList; /* Pointer to Device List for 
                                       * Emulated I2C Bus */
  uint32_t               MaxBlockLen; /* Max Block Length Supported 
                                       * by Interface */
}InterfaceIdsTbl_t;

const InterfaceIdsTbl_t EmulatedInterfaces[]={
/*                                           Interface */
/*                                           Max Block */
/* BUS EApi ID           Bus Device List     Length    */
  {EAPI_ID_I2C_EXTERNAL, ExternalI2CDevices, 0x10000},
  {EAPI_ID_I2C_LVDS_1,   LVDS_1I2CDevices  , 0x00100},
  {EAPI_ID_I2C_LVDS_2,   LVDS_2I2CDevices  , 0x00020}
};
uint32_t 
EAPI_CALLTYPE 
EApiI2CGetBusCapEmul(
    __IN  uint32_t  Id, 
    __OUT uint32_t *pMaxBlkLen
    )
{
  uint32_t i;

  for(i=0;i<ARRAY_SIZE(EmulatedInterfaces);i++)
  {
      if(EmulatedInterfaces[i].Id==Id)
      {
          *pMaxBlkLen=EmulatedInterfaces[i].MaxBlockLen;
          EAPI_LIB_RETURN_SUCCESS(
            EApiI2CGetBusCapEmul, 
            ""
            );
      }
  }

  EAPI_LIB_RETURN_ERROR(
    EApiI2CGetBusCapEmul, 
    EAPI_STATUS_UNSUPPORTED  , 
    "Unrecognised I2C ID"
    );
}

/*
 *
 *  
 *
 *      I2C
 *
 *
 *
 */
uint32_t 
EAPI_CALLTYPE 
EApiI2CWriteReadEmul(
    __IN      uint32_t Id         , 
    __IN      uint8_t  Addr       , 
    __INOPT   void    *pWBuffer  , 
    __IN      uint32_t WriteBCnt  , 
    __OUTOPT  void    *pRBuffer  , 
    __IN      uint32_t ReadBCnt
    )
{
  uint32_t i,i2;
  uint32_t LclAddr;

  for(i=0;i<ARRAY_SIZE(EmulatedInterfaces);i++)
  {
      if(EmulatedInterfaces[i].Id==Id)
      {
	EAPI_LIB_RETURN_ERROR_IF(
	    EApiI2CWriteReadEmul, 
	    (WriteBCnt>EmulatedInterfaces[i].MaxBlockLen+1), 
	    EAPI_STATUS_INVALID_BLOCK_LENGTH,
	    "WriteBCnt>(pMaxBlkLen+1)"
	    );
	EAPI_LIB_RETURN_ERROR_IF(
	    EApiI2CWriteReadEmul, 
	    (ReadBCnt>(EmulatedInterfaces[i].MaxBlockLen+1)), 
	    EAPI_STATUS_INVALID_BLOCK_LENGTH,
	    "ReadBCnt>(pMaxBlkLen+1)"
	    );
        if(EAPI_I2C_IS_10BIT_ADDR(Addr<<8)){
          LclAddr=Addr<<8;
          LclAddr|=*((uint8_t *)pWBuffer);
          pWBuffer=((uint8_t *)pWBuffer)+1;
          WriteBCnt--;
        }
        else
          LclAddr=Addr;

#if (STRICT_VALIDATION>1)
        EAPI_LIB_MSG_OUT(("O%04u %-30s : %-30s : ADDR=%02"PRIX16
            " \n", 
            __LINE__, 
            "EApiI2CWriteReadEmul", 
            "Info", 
            LclAddr
            ));
#endif
        for(i2=0;
            EmulatedInterfaces[i].DevicesList[i2].EncAddr!=END_OF_LIST_MARK;
            i2++
            )
        {
          if(EmulatedInterfaces[i].DevicesList[i2].EncAddr==LclAddr){
            return EmulatedInterfaces[i].DevicesList[i2].Emulator(
                EmulatedInterfaces[i].DevicesList[i2].Arg1, 
                pWBuffer, 
                (WriteBCnt?WriteBCnt-1:0), 
                pRBuffer, 
                (ReadBCnt?ReadBCnt-1:0)
                );
          }
        }
        
        EAPI_LIB_RETURN_ERROR(
            EApiI2CWriteReadEmul, 
            EAPI_STATUS_NOT_FOUND  , 
            "Device Not Present"
            );
      }
  }

  EAPI_LIB_RETURN_ERROR(
      EApiI2CWriteReadEmul, 
      EAPI_STATUS_UNSUPPORTED  , 
      "Unrecognised I2C ID"
      );
}

