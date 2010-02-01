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
 *I Description: Auto Created for EApiValidateAPI.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiValidateAPI.c
 *I  File Location        : apps\EApiValidateAPI
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EApiApp.h>


#define END_OF_LIST_MARK ((uint32_t)-1)
typedef void EApiValidateTestFunction(void);
#define DESTRUCTIVE_ALLOWED 1



/*  */
FILE *LogStream;

#ifdef __cplusplus
extern "C" {
#endif


EApiStatusCode_t
EApiGetErrorStringA(
    __OUT const char  **const pszString     , 
    __IN EApiStatusCode_t StatusCode
    );

#ifdef __cplusplus
}
#endif


signed int
__cdecl
siFFormattedMessage_SC(
    FILE       *  OutStream   ,
    char          cType       ,
    const char *  cszFileName ,   
    const char *  cszFuncName ,   
    unsigned int  uiLineNum   ,
    EApiStatusCode_t  StatusCode  ,   
    const char *  cszFormat   ,   
    ...
    )
{
  signed int Ret;
  va_list _ArgList;
  const char *szStatusDesc;
  cszFileName=cszFileName;
  va_start(_ArgList, cszFormat);
  EApiGetErrorStringA(&szStatusDesc, StatusCode);
	Ret = fprintf(
      OutStream,
      "%c%04i %-30s | ", 
      cType       ,
      uiLineNum   ,
      cszFuncName 
    );
  if(szStatusDesc==NULL){
    fprintf(OutStream, "               0x%08"PRIX32" | ", StatusCode);
  }else{
    fprintf(OutStream, "%-25s | ", szStatusDesc);
  }
	Ret += vfprintf(OutStream, cszFormat, _ArgList);
	va_end(_ArgList);
	return Ret;
}





#define EAPI_LOG_FORMATED_MES(type, func, err, desc) \
    siFFormattedMessage_SC(LogStream, type, __FILE__, #func,  __LINE__, err, "%s\n", desc )
#define EAPI_LOG_RETURN_VALUE(func, tblRef) \
    siFFormattedMessage_SC(LogStream, 'L', __FILE__, #func, __LINE__, StatusCode, "   %2d    %2d    [%s]\n", \
    i, i2, FailPass[((tblRef[i2].StatusCode1==StatusCode)||(tblRef[i2].StatusCode2==StatusCode)||(tblRef[i2].StatusCode3==StatusCode))])



EApiValidateTestFunction EApiValidateStringApi ;
EApiValidateTestFunction EApiValidateValuesApi ;
EApiValidateTestFunction EApiValidateI2CApi    ;
EApiValidateTestFunction EApiValidateStorageApi;
EApiValidateTestFunction EApiValidateGPIOApi   ;

TCHAR Buffer[1024]={0};
const char *FailPass[]={
  "FAIL",
  "PASS",
};

typedef struct EApiBoardStringValidate_s{
        TCHAR    *BufPtr      ; /* Buffer Pointer */
  const uint32_t *BufPtrLen   ; /* Buffer Length */
  const EApiStatusCode_t  StatusCode1 ; /* Allowed Return Value 1 */
  const EApiStatusCode_t  StatusCode2 ; /* Allowed Return Value 2 */
  const EApiStatusCode_t  StatusCode3 ; /* Allowed Return Value 3 */
}EApiBoardStringValidate_t;
uint32_t BufPtrLen=ARRAY_SIZE(Buffer);
uint32_t Value0   =0;
uint32_t Value1   =1;
const EApiBoardStringValidate_t EApiStringInterfaceValidate[]={
  {Buffer, &BufPtrLen, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {NULL  , NULL      , EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {Buffer, NULL      , EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {NULL  , &BufPtrLen, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {Buffer, &Value0   , EAPI_STATUS_MORE_DATA        , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {Buffer, &Value1   , EAPI_STATUS_MORE_DATA        , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
};

/*
 * Test String Function Table
 *
 */
typedef struct EApiStringType_s{
  const EApiId_t Id  ;
  const TCHAR *const   Desc;
}EApiStringType_t;
const EApiStringType_t EApiStrings[]={
  {EAPI_ID_BOARD_MANUFACTURER_STR  , TEXT("Manufacturer"        )},
  {EAPI_ID_BOARD_NAME_STR          , TEXT("Board Name"          )},
  {EAPI_ID_BOARD_SERIAL_STR        , TEXT("Board Serial Number" )},
  {EAPI_ID_BOARD_BIOS_REVISION_STR , TEXT("Bios Revision"       )},
  {EAPI_ID_BOARD_PLATFORM_TYPE_STR , TEXT("Platform Type"       )},
  {0x00000F00                      , TEXT("Unsupported"         )},
};
void EApiValidateStringApi (void)
{
  TCHAR *TmpStrPtr;
  uint32_t StringLength;
  uint32_t *pStringLength=&StringLength;
  size_t StringLength2;
  EApiStatusCode_t StatusCode;
  unsigned i,i2;
  for(i=0;i<ARRAY_SIZE(EApiStrings);i++){
    EApiAHGetStringAlloc(EApiStrings[i].Id, &TmpStrPtr);
    if(TmpStrPtr==NULL){
      EAPI_ERR_OUT(
        TEXT("%-30s : %s\n"), 
        EApiStrings[i].Desc, 
        TEXT("Memory Allocation Error")
      );
    }else{
      EAPI_MSG_OUT(
        TEXT("%-30s : %s\n"), 
        EApiStrings[i].Desc, 
        TmpStrPtr
      );
      free(TmpStrPtr);
    }
  }
  /*
   * More Rigorous Interfaces Verification
   */
  for(i=0;i<10;i++) /* Iterated thought Ids */
  {
    for(i2=0;i2<ARRAY_SIZE(EApiStringInterfaceValidate);i2++) /* Iterated thought test cases */
    {
      if(EApiStringInterfaceValidate[i2].BufPtrLen==NULL)
        pStringLength=NULL;
      else
      {
        pStringLength=&StringLength;
        StringLength=*EApiStringInterfaceValidate[i2].BufPtrLen;
      }
      StatusCode=EApiBoardGetString(i, EApiStringInterfaceValidate[i2].BufPtr, pStringLength);
      EAPI_LOG_RETURN_VALUE(EApiBoardGetStringA, EApiStringInterfaceValidate);
      if((EAPI_STATUS_UNSUPPORTED!=StatusCode)&&(pStringLength!=NULL))
      {
        
        StringLength2=EApiStrLen(
          EApiStringInterfaceValidate[i2].BufPtr, 
          *EApiStringInterfaceValidate[i2].BufPtrLen
          );
/*         EAPI_fprintf(LogStream, TEXT("L%04u %-30s : %06")TEXT(PRIX32)TEXT(" %06")TEXT(PRIX32)TEXT(" %06")TEXT(PRIX32)TEXT(" : %s\n"), __LINE__, TEXT("EApiBoardGetStringA"),  */
/*           *EApiStringInterfaceValidate[i2].BufPtrLen, StringLength, StringLength2,  */
/*           ((EApiStringInterfaceValidate[i2].BufPtr==NULL)||(*EApiStringInterfaceValidate[i2].BufPtrLen==0)?TEXT("NULL"):EApiStringInterfaceValidate[i2].BufPtr) */
/*           ); */
        if((*EApiStringInterfaceValidate[i2].BufPtrLen>StringLength)&&
            (EApiStringInterfaceValidate[i2].BufPtr!=NULL))
        {
          if(StringLength2==StringLength)
          {
            EAPI_LOG_FORMATED_MES(
              'E', EApiBoardGetStringA, 1, 
              "Returned String Missing Terminating \\0 Character."
            );
          }
          else
          {
            if((StringLength2+1)!=StringLength)
            {
              EAPI_LOG_FORMATED_MES(
                'E', EApiBoardGetStringA, 1, 
                "Returned Incorrect String Length."
              );
            }
          }
        }
      }
    }
  }
  return ;
}
/*
 * Test Value Function Table
 *
 */

typedef struct EApiBoardValueValidate_s{
        void *         BufPtr      ; /* Buffer Pointer */
  const EApiStatusCode_t  StatusCode1 ; /* Allowed Return Value 1 */
  const EApiStatusCode_t  StatusCode2 ; /* Allowed Return Value 2 */
  const EApiStatusCode_t  StatusCode3 ; /* Allowed Return Value 3 */
}EApiBoardValueValidate_t;
const EApiBoardValueValidate_t BoardValueValidate[]={
  {Buffer, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {NULL  , EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
};
typedef struct EApiValueType_s{
  const EApiId_t  Id  ;
  const TCHAR *const   Desc;
  CreateStringFunction *const CreateString;
}EApiValueType_t;

const EApiValueType_t EApiValues[]={
  {EAPI_ID_GET_EAPI_SPEC_VERSION        , TEXT("EApi Spec Version"   ), EApiAHCreateSVersionString   },
  {EAPI_ID_BOARD_BOOT_COUNTER_VAL       , TEXT("Boot Counter"        ), EApiAHCreateDecimalString    },
  {EAPI_ID_BOARD_RUNNING_TIME_METER_VAL , TEXT("Running Time Meter"  ), EApiAHCreateTimeString       },
  {EAPI_ID_BOARD_PNPID_VAL              , TEXT("Manufacturer PNP ID" ), EApiAHCreatePNPIDString      },
  {EAPI_ID_BOARD_PLATFORM_REV_VAL       , TEXT("Platform Revision"   ), EApiAHCreateSVersionString   },
  {EAPI_ID_BOARD_DRIVER_VERSION_VAL     , TEXT("Driver Version"      ), EApiAHCreateVersionString    },
  {EAPI_ID_BOARD_LIB_VERSION_VAL        , TEXT("LIB Version"         ), EApiAHCreateVersionString    },
  /* HW Monitoring  */
  /* Temperature  */
  {EAPI_ID_HWMON_CPU_TEMP               , TEXT("CPU Temperature"     ), EApiAHCreateTempString       },
  {EAPI_ID_HWMON_CHIPSET_TEMP           , TEXT("Chipset Temperature" ), EApiAHCreateTempString       },
  {EAPI_ID_HWMON_SYSTEM_TEMP            , TEXT("System Temperature"  ), EApiAHCreateTempString       },
  /* Voltage */
  {EAPI_ID_HWMON_VOLTAGE_VCORE          , TEXT("VCORE"               ), EApiAHCreateVoltageString    },
  {EAPI_ID_HWMON_VOLTAGE_2V5            , TEXT("2.5V"                ), EApiAHCreateVoltageString    },
  {EAPI_ID_HWMON_VOLTAGE_3V3            , TEXT("3.3V"                ), EApiAHCreateVoltageString    },
  {EAPI_ID_HWMON_VOLTAGE_VBAT           , TEXT("VBAT"                ), EApiAHCreateVoltageString    },
  {EAPI_ID_HWMON_VOLTAGE_5V             , TEXT("5V"                  ), EApiAHCreateVoltageString    },
  {EAPI_ID_HWMON_VOLTAGE_5VSB           , TEXT("5VSB"                ), EApiAHCreateVoltageString    },
  {EAPI_ID_HWMON_VOLTAGE_12V            , TEXT("12V"                 ), EApiAHCreateVoltageString    },
  /* Fan Rotations */
  {EAPI_ID_HWMON_FAN_CPU                , TEXT("Cpu Fan"             ), EApiAHCreateRotationsString  },
  {EAPI_ID_HWMON_FAN_SYSTEM             , TEXT("System Fan"          ), EApiAHCreateRotationsString  },
  {0x00000f00                           , TEXT("Unsupported"         ), EApiAHCreateVersionString    },
};
void EApiValidateValuesApi (void)
{
  TCHAR TmpStrBuf[1024];
  uint32_t Value;
  EApiStatusCode_t StatusCode;
  unsigned i,i2;
  for(i=0;i<ARRAY_SIZE(EApiValues);i++){
    if((StatusCode=EApiBoardGetValue(EApiValues[i].Id, &Value))==EAPI_STATUS_SUCCESS)
    {
      EApiValues[i].CreateString(Value, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
      EAPI_MSG_OUT(TEXT("%-30s : %s\n"), EApiValues[i].Desc, TmpStrBuf);
    }else{
      EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
      EAPI_MSG_OUT(TEXT("%-30s : %s\n"), EApiValues[i].Desc, TmpStrBuf);
    }
  }
  /*
   * More Rigorous Interfaces Verification
   */
  for(i=0;i<10;i++) /* Iterated thought Ids */
  {
    for(i2=0;i2<ARRAY_SIZE(BoardValueValidate);i2++) /* Iterated thought test cases */
    {
      StatusCode=EApiBoardGetValue(i, (uint32_t *)BoardValueValidate[i2].BufPtr);
      EAPI_LOG_RETURN_VALUE(EApiBoardGetValue, BoardValueValidate);
    }
  }
  return ;
}

/*
 * Test I2C Function
 *
 */

typedef struct EApiI2CLLInterfaceValidate_s{
  const uint8_t   Address     ; /* Address */
        void *    WBufPtr     ; /* Write Buffer Pointer */
  const uint32_t  WByteCnt    ; /* Write Byte Count  */
        void *    RBufPtr     ; /* Read  Buffer Pointer */
  const uint32_t  RBufPtrLen  ; /* Read  Buffer Length */
  const uint32_t  RByteCnt    ; /* Read  Byte Count  */
  const EApiStatusCode_t  StatusCode1 ; /* Allowed Return Value 1 */
  const EApiStatusCode_t  StatusCode2 ; /* Allowed Return Value 2 */
  const EApiStatusCode_t  StatusCode3 ; /* Allowed Return Value 3 */
}EApiI2CLLInterfaceValidate_t;
const EApiI2CLLInterfaceValidate_t EApiI2CLLValidate[]={
  {0xF8, NULL  ,   0, NULL  ,                 0 ,   0, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {0xF8, NULL  ,  10, NULL  ,                 0 ,   0, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {0xF8, NULL  ,   0, NULL  ,                10 ,   0, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {0xF8, NULL  ,   0, NULL  ,                 0 ,  10, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {0xF8, NULL  ,   0, NULL  ,                 0 ,  10, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {0xF8, NULL  ,   0, NULL  ,                10 ,  20, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_MORE_DATA         , EAPI_STATUS_MORE_DATA         },
  {0xF8, NULL  ,   0, Buffer,                10 ,  20, EAPI_STATUS_NOT_FOUND        , EAPI_STATUS_MORE_DATA         , EAPI_STATUS_UNSUPPORTED       },
  {0xF8, Buffer,   0, NULL  ,                 0 ,   0, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {0xF8, Buffer,  10, NULL  ,                 0 ,   0, EAPI_STATUS_NOT_FOUND        , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {0xF8, NULL  ,   0, Buffer, ARRAY_SIZE(Buffer),  10, EAPI_STATUS_NOT_FOUND        , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
};

typedef struct EApiI2CHLInterfaceValidate_s{
  const uint32_t          Address     ; /* Address */
  const uint32_t          Offset      ; /* Address */
  void  *                 BufPtr      ; /* Buffer Pointer */
  const uint32_t          BufPtrLen   ; /* Buffer Length */
  const uint32_t          ByteCnt     ; /* Byte Count  */
  const EApiStatusCode_t  StatusCode1 ; /* Allowed Return Value 1 */
  const EApiStatusCode_t  StatusCode2 ; /* Allowed Return Value 2 */
  const EApiStatusCode_t  StatusCode3 ; /* Allowed Return Value 3 */
}EApiI2CHLInterfaceValidate_t;
const EApiI2CHLInterfaceValidate_t EApiI2CHLReadValidate[]={
  {0xF8, 0x00, Buffer, ARRAY_SIZE(Buffer),  10, EAPI_STATUS_NOT_FOUND        , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_NOT_FOUND         },
  {0xF8, 0x00, NULL  , ARRAY_SIZE(Buffer),  10, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {0xF8, 0x00, Buffer,             0x0000,  20, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {0xF8, 0x00, Buffer, ARRAY_SIZE(Buffer),   0, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {0xF8, 0x00, Buffer,             0x0010,  20, EAPI_STATUS_UNSUPPORTED      , EAPI_STATUS_MORE_DATA         , EAPI_STATUS_NOT_FOUND         },
  {0xF8, 0x00, Buffer, ARRAY_SIZE(Buffer),  10, EAPI_STATUS_NOT_FOUND        , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_NOT_FOUND         },
};
const EApiI2CHLInterfaceValidate_t EApiI2CHLWriteValidate[]={
  {0xF8, 0x00, Buffer,            0x0000 ,  10, EAPI_STATUS_NOT_FOUND        , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_NOT_FOUND         },
  {0xF8, 0x00, NULL  ,            0x0000 ,  10, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
  {0xF8, 0x00, Buffer,            0x0000 ,   0, EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
};

typedef struct EApiI2CCapValidate_s{
        uint32_t         *pValue      ; /* Value Pointer*/
  const EApiStatusCode_t  StatusCode1 ; /* Allowed Return Value 1 */
  const EApiStatusCode_t  StatusCode2 ; /* Allowed Return Value 2 */
  const EApiStatusCode_t  StatusCode3 ; /* Allowed Return Value 3 */
}EApiI2CCapValidate_t;
uint32_t I2CMaxClk=0;
const EApiI2CCapValidate_t EApiI2CInterfaceValidate[]={
  {&I2CMaxClk, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {NULL      , EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
};
typedef struct EApiI2CType_s{
  const EApiId_t      Id  ;
  const TCHAR *const  Desc;
}EApiI2CType_t;

const I2CDeviceDesc_t I2CDevices[]={
/*           Max                           Write           */
/* Encoded  Write    Index/Cmd Type        Recover  Device */
/* Address  Block   Standard/Extended      Time ms  Length */
  {0x00A0,    16 , EApiAPI2CExtIndex,       5, 0x0100},
  {0x00A2,    256, EApiAPI2CExtIndex,       5, 0x0100},
  {0x00A6,    16 , EApiAPI2CStdIndex,       5, 0x0100},
  {0x00AE,    16 , EApiAPI2CExtIndex,       5, 0x0100},
  {0xF255,    256, EApiAPI2CExtIndex,       5, 0x0100},
};
const EApiI2CType_t EApiI2CBuses[]={
  {EAPI_ID_I2C_EXTERNAL, TEXT("External I2C"  )},
  {EAPI_ID_I2C_LVDS_1  , TEXT("LVDS 1 I2C/DDC")},
  {EAPI_ID_I2C_LVDS_2  , TEXT("LVDS 2 I2C/DDC")},
  {0x00000F00          , TEXT("Unsupported"   )},
};
void printHex(
	__IN FILE*  OutStream,
	__IN void * pBuffer  ,
	__IN size_t ByteCount
	)
{
  for(; ByteCount --; ){
    EAPI_fprintf(OutStream, TEXT("%02")TEXT(PRIX8), *((uint8_t*)pBuffer));
    pBuffer=((uint8_t*)pBuffer)+1;
	}
}
void EApiValidateI2CApi (void)
{
  TCHAR TmpStrBuf[0x0800];
  EApiStatusCode_t StatusCode;
  unsigned i,i2;
    
  for(i=0;i<ARRAY_SIZE(EApiI2CBuses);i++){
    for(i2=0;i2<ARRAY_SIZE(I2CDevices);i2++){
      StatusCode=EApiAHI2CReadEeprom(
            EApiI2CBuses[i].Id, 
            &I2CDevices[i2]   , 
            0                 , 
            TmpStrBuf         , 
            ARRAY_SIZE(TmpStrBuf) , /* For Debug Purposes */
            (uint32_t)I2CDevices[i2].DevSize
          );
      if(EAPI_STATUS_TEST_OK(StatusCode))
      {
        EAPI_MSG_OUT(
              TEXT("%-25s %04")TEXT(PRIX16)TEXT(" : "), 
              EApiI2CBuses[i].Desc      , 
              I2CDevices[i2].DeviceAddr
            );
        printHex(stdout, TmpStrBuf, 16);
        EAPI_MSG_OUT(TEXT("\n"));
#if DESTRUCTIVE_ALLOWED
        StatusCode=EApiAHI2CWriteEeprom(
              EApiI2CBuses[i].Id, 
              &I2CDevices[i2]   , 
              13                , 
              TmpStrBuf         , 
              (uint32_t)I2CDevices[i2].DevSize/5
            );
        if(EAPI_STATUS_TEST_NOK(StatusCode))
        {
          EAPI_MSG_OUT(
                TEXT("%-25s %04")TEXT(PRIX16)TEXT(" : "), 
                EApiI2CBuses[i].Desc      , 
                I2CDevices[i2].DeviceAddr
              );
          printHex(stdout, TmpStrBuf, 16);
          EAPI_MSG_OUT(TEXT("\n"));
        }
        else
        {
          EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(
                TEXT("%-25s %04")TEXT(PRIX16)TEXT(" : %s\n"), 
                EApiI2CBuses[i].Desc      , 
                I2CDevices[i2].DeviceAddr , 
                TmpStrBuf
              );
        }
#endif
      }
      else
      {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(
            TEXT("%-25s %04")TEXT(PRIX16)TEXT(" : %s\n"), 
            EApiI2CBuses[i].Desc      , 
            I2CDevices[i2].DeviceAddr , 
            TmpStrBuf
            );
      }
    }
  }
  /*
   * More Rigorous Interfaces Verification
   */
  memset(Buffer, 0x00, ARRAY_SIZE(Buffer));
  for(i=0;i<10;i++) /* Iterated thought Ids */
  {
    for(i2=0;i2<ARRAY_SIZE(EApiI2CLLValidate);i2++) /* Iterated thought test cases */
    {
      StatusCode=EApiI2CWriteReadRaw(
            i                               , 
            EApiI2CLLValidate[i2].Address   , 
            EApiI2CLLValidate[i2].WBufPtr   , 
            EApiI2CLLValidate[i2].WByteCnt  , 
            EApiI2CLLValidate[i2].RBufPtr   , 
            EApiI2CLLValidate[i2].RBufPtrLen, 
            EApiI2CLLValidate[i2].RByteCnt
          );
      EAPI_LOG_RETURN_VALUE(EApiI2CWriteReadRaw, EApiI2CLLValidate);
    }
  }
  for(i=0;i<10;i++) /* Iterated thought Ids */
  {
    for(i2=0;i2<ARRAY_SIZE(EApiI2CHLReadValidate);i2++) /* Iterated thought test cases */
    {
      StatusCode=EApiI2CReadTransfer(
            i                                   , 
            EApiI2CHLReadValidate[i2].Address   , 
            EApiI2CHLReadValidate[i2].Offset    , 
            EApiI2CHLReadValidate[i2].BufPtr    , 
            EApiI2CHLReadValidate[i2].BufPtrLen , 
            EApiI2CHLReadValidate[i2].ByteCnt 
          );
      EAPI_LOG_RETURN_VALUE(EApiI2CReadTransfer, EApiI2CHLReadValidate);
    }
  }
  for(i=0;i<10;i++) /* Iterated thought Ids */
  {
    for(i2=0;i2<ARRAY_SIZE(EApiI2CHLWriteValidate);i2++) /* Iterated thought test cases */
    {
      StatusCode=EApiI2CWriteTransfer(
            i                                   , 
            EApiI2CHLWriteValidate[i2].Address  , 
            EApiI2CHLWriteValidate[i2].Offset   , 
            EApiI2CHLWriteValidate[i2].BufPtr   , 
            EApiI2CHLWriteValidate[i2].ByteCnt 
          );
      EAPI_LOG_RETURN_VALUE(EApiI2CWriteTransfer, EApiI2CHLWriteValidate);
    }
  }
  for(i=0;i<10;i++) /* Iterated thought Ids */
  {
    for(i2=0;i2<ARRAY_SIZE(EApiI2CInterfaceValidate);i2++) /* Iterated thought test cases */
    {
      StatusCode=EApiI2CGetBusCap(i, EApiI2CInterfaceValidate[i2].pValue);
      EAPI_LOG_RETURN_VALUE(EApiI2CGetBusCap, EApiI2CInterfaceValidate);
    }
  }
  return ;
}
/*
 * Test Storage Function
 *
 */

typedef struct EApiStorageType_s{
  const EApiId_t  Id     ;
  const TCHAR *const   Desc   ;
  const uint32_t  Length ;
}EApiStorageType_t;

const EApiStorageType_t EApiStorageDevices[]={
  {EAPI_ID_STORAGE_STD        , TEXT("Standard Storage"   ), 0x20},
  {EAPI_PMG_ID_STORAGE_SAMPLE , TEXT("Dummy PICMG Storage"), 0x80},
  {0x00000F00                 , TEXT("Unsupported"        ), 0x20},
};

typedef struct EApiStorageValidate_s{
  const uint32_t  Offset      ; /* Read Offset */
        void *    BufPtr      ; /* Buffer Pointer */
  const uint32_t  BufPtrLen   ; /* Buffer Length */
  const uint32_t  ByteCnt     ; /* Byte Count  */
  const EApiStatusCode_t  StatusCode1 ; /* Allowed Return Value 1 */
  const EApiStatusCode_t  StatusCode2 ; /* Allowed Return Value 2 */
  const EApiStatusCode_t  StatusCode3 ; /* Allowed Return Value 3 */
}EApiStorageValidate_t;
const EApiStorageValidate_t StorageValidate[]={
  {0x0000, Buffer, ARRAY_SIZE(Buffer),  10, EAPI_STATUS_SUCCESS             , EAPI_STATUS_UNSUPPORTED         , EAPI_STATUS_UNSUPPORTED       },
  {0x0000, NULL  , ARRAY_SIZE(Buffer), 100, EAPI_STATUS_INVALID_PARAMETER   , EAPI_STATUS_INVALID_PARAMETER   , EAPI_STATUS_INVALID_PARAMETER },
  {0x0021, Buffer,            0x0000 ,  20, EAPI_STATUS_INVALID_PARAMETER   , EAPI_STATUS_INVALID_BLOCK_LENGTH, EAPI_STATUS_UNSUPPORTED       },
  {0x0021, Buffer,            0x0010 ,  20, EAPI_STATUS_INVALID_BLOCK_LENGTH, EAPI_STATUS_SUCCESS             , EAPI_STATUS_UNSUPPORTED       },
  {0x0021, Buffer, ARRAY_SIZE(Buffer),   0, EAPI_STATUS_INVALID_PARAMETER   , EAPI_STATUS_INVALID_PARAMETER   , EAPI_STATUS_UNSUPPORTED       },
  {0x0001, Buffer, ARRAY_SIZE(Buffer),  10, EAPI_STATUS_SUCCESS             , EAPI_STATUS_UNSUPPORTED         , EAPI_STATUS_UNSUPPORTED       },
};
typedef struct EApiStorageCapValidate_s{
        uint32_t *pStorgeSize ; /* Read Offset */
        uint32_t *pBlockLen   ; /* Buffer Pointer */
  const EApiStatusCode_t  StatusCode1 ; /* Allowed Return Value 1 */
  const EApiStatusCode_t  StatusCode2 ; /* Allowed Return Value 2 */
  const EApiStatusCode_t  StatusCode3 ; /* Allowed Return Value 3 */
}EApiStorageCapValidate_t;
uint32_t StorageSize;
uint32_t BlockLength;
const EApiStorageCapValidate_t StorageCapValidate[]={
  {&StorageSize, &BlockLength, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {&StorageSize, NULL        , EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {NULL        , &BlockLength, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {NULL        , NULL        , EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
};
void EApiValidateStorageApi(void)
{
  TCHAR TmpStrBuf[1024];
  unsigned i,i2;
  EApiStatusCode_t StatusCode;
    
  for(i=0;i<ARRAY_SIZE(EApiStorageDevices);i++){
      StatusCode=EApiStorageAreaRead(
        EApiStorageDevices[i].Id, 
        0, 
        TmpStrBuf, 
        ARRAY_SIZE(TmpStrBuf) , /* For Debug Purposes */
        EApiStorageDevices[i].Length
        );
      if(EAPI_STATUS_TEST_OK(StatusCode))
      {
        EAPI_MSG_OUT(
              TEXT("%-30s : "), 
              EApiStorageDevices[i].Desc
            );
        printHex(stdout, TmpStrBuf, 16);
        EAPI_MSG_OUT(TEXT("\n"));
#if DESTRUCTIVE_ALLOWED
        StatusCode=EApiAHWriteStorage(
              EApiStorageDevices[i].Id      , 
              13                            , 
              TmpStrBuf                     ,
              EApiStorageDevices[i].Length/5
            );
        if(EAPI_STATUS_TEST_OK(StatusCode))
        {
          EAPI_MSG_OUT(
                TEXT("%-30s : "), 
                EApiStorageDevices[i].Desc
              );
          printHex(stdout, TmpStrBuf, 16);
          EAPI_MSG_OUT(TEXT("\n"));
        }
        else
        {
          EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(
              TEXT("%-30s : %02")TEXT(PRIX8)TEXT(" %s\n")      , 
              EApiStorageDevices[i].Desc, 
              I2CDevices[i].DeviceAddr  , 
              TmpStrBuf
              );
        }
#endif
      }
      else
      {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(TEXT("%-30s : %s\n"), EApiStorageDevices[i].Desc, TmpStrBuf);
      }
  }
  /*
   * More Rigorous Interfaces Verification
   */
  for(i=0;i<10;i++) /* Iterate thought Ids */
  {
    for(i2=0;i2<ARRAY_SIZE(StorageValidate);i2++) /* Iterated thought test cases */
    {
      StatusCode=EApiStorageAreaRead(
        i                             , 
        StorageValidate[i2].Offset    , 
        StorageValidate[i2].BufPtr    , 
        StorageValidate[i2].BufPtrLen , 
        StorageValidate[i2].ByteCnt
        );
      EAPI_LOG_RETURN_VALUE(EApiStorageAreaRead, StorageValidate);
#if DESTRUCTIVE_ALLOWED
      StatusCode=EApiStorageAreaWrite(
        i                           , 
        StorageValidate[i2].Offset  , 
        StorageValidate[i2].BufPtr  , 
        StorageValidate[i2].ByteCnt
        );
      EAPI_LOG_RETURN_VALUE(EApiStorageAreaWrite, StorageValidate);
#endif
    }
  }
  for(i=0;i<10;i++) /* Iterated thought Ids */
  {
    for(i2=0;i2<ARRAY_SIZE(StorageCapValidate);i2++) /* Iterated thought test cases */
    {
      StatusCode=EApiStorageCap(
        i                                 , 
        StorageCapValidate[i2].pStorgeSize, 
        StorageCapValidate[i2].pBlockLen
        );
      EAPI_LOG_RETURN_VALUE(EApiStorageCap, StorageCapValidate);
    }
  }
  return ;
}

/*
 * Test GPIO Function
 *
 */

typedef struct EApiGpioValidate_s{
        uint32_t *pInputs     ; /* Value Pointer*/
        uint32_t *pOutputs    ; /* Value Pointer*/
  const EApiStatusCode_t  StatusCode1 ; /* Allowed Return Value 1 */
  const EApiStatusCode_t  StatusCode2 ; /* Allowed Return Value 2 */
  const EApiStatusCode_t  StatusCode3 ; /* Allowed Return Value 3 */
}EApiGpioValidate_t;
uint32_t GpioInputs;
uint32_t GpioOutputs;
const EApiGpioValidate_t EApiGpioterfaceValidate[]={
  {&GpioInputs, &GpioOutputs, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {&GpioInputs, NULL        , EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {NULL       , &GpioOutputs, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
  {NULL       , NULL        , EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
};

typedef struct EApiGpioType_s{
  const EApiId_t  Id     ;
  const TCHAR *const   Desc   ;
}EApiGpioType_t;

const EApiGpioType_t EApiGpioDevices[]={
  {EAPI_ID_GPIO_BITMASK00, TEXT("GPIO Bitmask"    )},
  {EAPI_GPIO_GPIO_ID(0)  , TEXT("GPIO GPIO0"      )},
  {EAPI_GPIO_GPIO_ID(1)  , TEXT("GPIO GPIO1"      )},
  {EAPI_GPIO_GPIO_ID(2)  , TEXT("GPIO GPIO2"      )},
  {EAPI_GPIO_GPIO_ID(3)  , TEXT("GPIO GPIO3"      )},
  {EAPI_GPIO_GPIO_ID(4)  , TEXT("GPIO GPIO4"      )},
  {EAPI_GPIO_GPIO_ID(5)  , TEXT("GPIO GPIO5"      )},
  {EAPI_GPIO_GPIO_ID(6)  , TEXT("GPIO GPIO6"      )},
  {EAPI_GPIO_GPIO_ID(7)  , TEXT("GPIO GPIO7"      )},
  {EAPI_GPIO_GPIO_ID(8)  , TEXT("GPIO GPIO8"      )},
  {EAPI_GPIO_GPIO_ID(9)  , TEXT("GPIO GPIO9"      )},
  {0x00000F00            , TEXT("Unsupported"     )},
};


void EApiValidateGPIOApi(void)
{
  TCHAR TmpStrBuf[1024];
  unsigned i,i2;
  uint32_t Direction;
  uint32_t Level;
  uint32_t Inputs;
  uint32_t Outputs;
  EApiStatusCode_t StatusCode;
  for(i=0;i<ARRAY_SIZE(EApiGpioDevices);i++){
/*       *((int*)NULL)=0; */
      StatusCode=EApiGPIOGetDirectionCaps(EApiGpioDevices[i].Id, &Inputs, &Outputs);
      if(EAPI_STATUS_TEST_NOK(StatusCode))
      {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(
        TEXT("%-15s %-25s : %s\n"), 
        EApiGpioDevices[i].Desc, 
        TEXT("EApiGPIOGetDirectionCaps"), 
        TmpStrBuf
        );
        continue;
      }
      EAPI_MSG_OUT(
        TEXT("%-15s %-25s : Inputs   =%08")TEXT(PRIX32)TEXT(" Outputs=%08")TEXT(PRIX32)TEXT("\n"), 
        EApiGpioDevices[i].Desc, 
        TEXT("EApiGPIOGetDirectionCaps"), 
        Inputs, 
        Outputs
      );
      StatusCode=EApiGPIOGetDirection(EApiGpioDevices[i].Id, Inputs|Outputs, &Direction);
      if(EAPI_STATUS_TEST_NOK(StatusCode))
      {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(
          TEXT("%-15s %-25s : %s\n"), 
          EApiGpioDevices[i].Desc, 
          TEXT("EApiGPIOGetDirection"), 
          TmpStrBuf
          );
        continue;
      }
      EAPI_MSG_OUT(
        TEXT("%-15s %-25s : Direction=%08")TEXT(PRIX32)TEXT("\n"), 
        EApiGpioDevices[i].Desc, 
        TEXT("EApiGPIOGetDirection"), 
        Direction
        );
      StatusCode=EApiGPIOGetLevel(EApiGpioDevices[i].Id, Inputs|Outputs, &Level);
      if(EAPI_STATUS_TEST_NOK(StatusCode))
      {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(
          TEXT("%-15s %-25s : %s\n"), 
          EApiGpioDevices[i].Desc, 
          TEXT("EApiGPIOGetLevel"), 
          TmpStrBuf
          );
        continue;
      }
      EAPI_MSG_OUT(
        TEXT("%-15s %-25s : Level    =%08")TEXT(PRIX32)TEXT("\n"), 
        EApiGpioDevices[i].Desc, 
        TEXT("EApiGPIOGetLevel"), 
        Level
        );
      StatusCode=EApiGPIOSetDirection(
        EApiGpioDevices[i].Id, 
        Inputs|Outputs, 
        ((Inputs&0xFFFF))|((Outputs&0x0000))
        );
      if(EAPI_STATUS_TEST_NOK(StatusCode))
      {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(
          TEXT("%-15s %-25s : %s\n"), 
          EApiGpioDevices[i].Desc, 
          TEXT("EApiGPIOSetDirection"), 
          TmpStrBuf
          );
        continue;
      }
      StatusCode=EApiGPIOGetDirection(EApiGpioDevices[i].Id, Inputs|Outputs, &Direction);
      if(EAPI_STATUS_TEST_NOK(StatusCode))
      {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(
            TEXT("%-15s %-25s : %s\n"), 
            EApiGpioDevices[i].Desc, 
            TEXT("EApiGPIOGetDirection"), 
            TmpStrBuf
            );
        continue;
      }
      EAPI_MSG_OUT(
          TEXT("%-15s %-25s : Direction=%08")TEXT(PRIX32)TEXT("\n"), 
          EApiGpioDevices[i].Desc, 
          TEXT("EApiGPIOGetDirection"), 
          Direction
          );
      StatusCode=EApiGPIOSetLevel(EApiGpioDevices[i].Id, Outputs, Outputs);
      if(EAPI_STATUS_TEST_NOK(StatusCode))
      {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(
            TEXT("%-15s %-25s : %s\n"), 
            EApiGpioDevices[i].Desc, 
            TEXT("EApiGPIOSetLevel"), 
            TmpStrBuf
            );
        continue;
      }
      StatusCode=EApiGPIOGetLevel(EApiGpioDevices[i].Id, Inputs|Outputs, &Level);
      if(EAPI_STATUS_TEST_NOK(StatusCode))
      {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(
            TEXT("%-15s %-25s : %s\n"), 
            EApiGpioDevices[i].Desc, 
            TEXT("EApiGPIOGetDirection"), 
            TmpStrBuf
            );
        continue;
      }
      EAPI_MSG_OUT(
          TEXT("%-15s %-25s : Level    =%08")TEXT(PRIX32)TEXT("\n"), 
          EApiGpioDevices[i].Desc, 
          TEXT("EApiGPIOSetLevel"), 
          Level);
  }
  for(i=0;i<10;i++) /* Iterated throught Ids */
  {
    for(i2=0;i2<ARRAY_SIZE(EApiGpioterfaceValidate);i2++) /* Iterated thought test cases */
    {
      StatusCode=EApiGPIOGetDirectionCaps(
        i, 
        EApiGpioterfaceValidate[i2].pInputs, 
        EApiGpioterfaceValidate[i2].pOutputs
        );
      EAPI_LOG_RETURN_VALUE(EApiGPIOGetDirectionCaps, EApiGpioterfaceValidate);
    }
  }
  return ;
}
/*
 * Test Functions Table
 *
 */
typedef struct TestFunctionsTbl_s{
  EApiValidateTestFunction *TestHandler;
  const TCHAR *const TestDesc;
}TestFunctionsTbl_t;
const TestFunctionsTbl_t TestFunctions[]={
  {EApiValidateValuesApi  , TEXT("Values Function"     )},
  {EApiValidateStringApi  , TEXT("Strings Function"    )},
  {EApiValidateI2CApi     , TEXT("I2C Function"        )},
  {EApiValidateStorageApi , TEXT("Storage Function"    )},
  {EApiValidateGPIOApi    , TEXT("Gpio Function"       )},
};
/* void __cdecl main( __IN  char *const *const  argv, __IN const int argc) */
typedef enum ProgramStatusCodes_e{
    PRG_RETURN_OK             =0,
    PRG_RETURN_ERROR            ,
    PRG_RETURN_LIB_INIT_ERROR   ,
    PRG_RETURN_LIB_UNINIT_ERROR
}ProgramStatusCodes_t;
int 
__cdecl 
main(void)
{
  unsigned i;
  LogStream=EAPI_fopen(TEXT("EApiValidateAPI.log"), TEXT("w"));
  if(LogStream==NULL)
    LogStream=stdout;
  if(EAPI_STATUS_TEST_NOK(EApiLibInitialize()))
  {
    exit(PRG_RETURN_LIB_INIT_ERROR);
  }
  EAPI_fprintf(
      LogStream, 
      TEXT("L%04u %-30s | %-25s | %5s %5s    [%s]\n"), 
      __LINE__              , 
      TEXT("Function Name") , 
      TEXT("Status Code")   , 
      TEXT("Id")            , 
      TEXT("Test#")         , 
      TEXT("Status")
      );

    EAPI_fprintf(
        stderr        , 
        TEXT("EApi(Embedded Application Interface)\n")
        TEXT("EApi Verification Tool                            Version %u.%u.%u\n"),
        APP_VERSION   , 
        APP_REVISION  , 
        APP_BUILD
      );

  for(i=0;i<ARRAY_SIZE(TestFunctions);i++){
    EAPI_MSG_OUT(
      TEXT("#\n")
      TEXT("# %s\n")
      TEXT("#\n"),  TestFunctions[i].TestDesc
      );

    TestFunctions[i].TestHandler();
  }
  if(EAPI_STATUS_TEST_NOK(EApiLibInitialize()))
  {
    exit(PRG_RETURN_LIB_UNINIT_ERROR);
  }
  exit(PRG_RETURN_OK);
}
