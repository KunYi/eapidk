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
 *I Description: Auto Created for EApiAPI.cpp
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiAPI.cpp
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


int Initialized=0;
#define EAPI_CHECK_NOT_INITIALIZED(FuncName) \
  EAPI_LIB_RETURN_ERROR_IF(\
      FuncName, \
      Initialized==1, \
      EAPI_STATUS_NOT_INITIALIZED, \
      "Library Already Initialized" \
      )

#define EAPI_CHECK_INITIALIZED(FuncName) \
  EAPI_LIB_RETURN_ERROR_IF(FuncName, \
      Initialized==0, \
      EAPI_STATUS_NOT_INITIALIZED, \
      "Library Uninitialized" \
      )

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
EApiI2CGetBusCap(
    __IN  EApiId_t  Id         , /* I2C Bus Id */
    __OUT uint32_t *pMaxBlkLen   /* Max Block Length 
                                  * Supported on this
                                  * interface 
                                  */
    )
{
  EAPI_CHECK_INITIALIZED(EApiI2CGetBusCap);
  EAPI_LIB_ASSERT_PARAMATER_NULL(EApiI2CGetBusCap, pMaxBlkLen);

  return EApiI2CGetBusCapEmul(Id, pMaxBlkLen);
}

EApiStatusCode_t 
EAPI_CALLTYPE 
EApiI2CWriteReadRaw(
    __IN     EApiId_t  Id       , /* I2C Bus Id */
    __IN     uint8_t   Addr     , /* Encoded 7Bit I2C
                                   * Device Address 
                                   */
    __INOPT  void     *pWBuffer , /* Write Data pBuffer */
    __IN     uint32_t  WriteBCnt, /* Number of Bytes to 
                                   * write 
                                   */
    __OUTOPT void     *pRBuffer , /* Read Data pBuffer */
    __IN     uint32_t  RBufLen  , /* Data pBuffer Length */
    __IN     uint32_t  ReadBCnt   /* Number of Bytes to 
                                   * Read 
                                   */
    )
{
  EApiStatusCode_t ErrorCode=EAPI_STATUS_SUCCESS;
  EApiStatusCode_t ErrorCode2;
  EAPI_CHECK_INITIALIZED(EApiI2CWriteReadRaw);
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
      EApiI2CWriteReadRaw, 
      (WriteBCnt>1)&&(pWBuffer==NULL), 
      "pWBuffer is NULL"          
      );
#if (STRICT_VALIDATION>1)
  siFormattedMessage_M2(
          'L'                   ,
          __FILE__              ,
          "EApiI2CWriteTransfer",
          __LINE__              ,
          "Info"                ,
          "ADDR=%02hhX WriteBCnt=%04"PRIX32
          " RBufLen=%04"PRIX32" WriteBCnt=%04"PRIX32
          " ReadBCnt=%04"PRIX32" %08"PRIX32"\n", 
          Addr, WriteBCnt, RBufLen, WriteBCnt, ReadBCnt, 
          (WriteBCnt?((uint32_t*)pWBuffer)[0]:0)
      );
#endif
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
      EApiI2CWriteReadRaw, 
      (ReadBCnt>1)&&(pRBuffer==NULL) , 
      "pRBuffer is NULL"          
      );
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
      EApiI2CWriteReadRaw, 
      (ReadBCnt>1)&&(RBufLen==0) , 
      "RBufLen is ZERO"          
      );
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
      EApiI2CWriteReadRaw, 
      ((WriteBCnt==0)&&(ReadBCnt==0)), 
      "NO READ NO WRITE"
      );

  EAPI_LIB_PREVENT_BUF_OVERFLOW(
      EApiI2CWriteReadRaw, 
      ReadBCnt, 
      RBufLen+1
      );

  ErrorCode2=EApiI2CWriteReadEmul(
      Id,  
      Addr, 
      pWBuffer, 
      WriteBCnt, 
      pRBuffer, 
      ReadBCnt
      );
  if(ErrorCode2!=EAPI_STATUS_SUCCESS)
    return ErrorCode2;
  return ErrorCode;

}


EApiStatusCode_t 
EAPI_CALLTYPE 
EApiI2CReadTransfer(
    __IN  EApiId_t  Id      , /* I2C Bus Id */
    __IN  uint32_t  Addr    , /* Encoded 7/10Bit I2C
                               * Device Address
                               */
    __IN  uint32_t  Cmd     , /* I2C Command/Offset */
    __OUT     void *pBuffer , /* Transfer Data pBuffer */
    __IN  uint32_t  BufLen  , /* Data pBuffer Length */
    __IN  uint32_t  ByteCnt   /* Byte Count to read */
    )
{
  uint8_t LclpBuffer[8]={0};
  int LclByteCnt=0;
#if (STRICT_VALIDATION>1)
  uint32_t MaxBlkLen;
#endif
  EAPI_CHECK_INITIALIZED(EApiI2CReadTransfer);

#if (STRICT_VALIDATION>1)
  siFormattedMessage_M2(
          'L'                   ,
          __FILE__              ,
          "EApiI2CWriteTransfer",
          __LINE__              ,
          "Info"                ,
          "Id=%08"PRIX32" ADDR=%04"PRIX32
          " CMD=%04"PRIX32" BCNT=%04"PRIX32"\n", 
          Id, Addr, Cmd, ByteCnt
      );
#endif
  EAPI_LIB_ASSERT_PARAMATER_NULL(EApiI2CReadTransfer, pBuffer);
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiI2CReadTransfer, BufLen );
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiI2CReadTransfer, ByteCnt);
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiI2CReadTransfer, BufLen );

#if (STRICT_VALIDATION>1)
    EApiI2CGetBusCap(Id, &MaxBlkLen);
    EAPI_LIB_ASSERT_PARAMATER_CHECK(
        EApiI2CReadTransfer, 
        ByteCnt>MaxBlkLen, 
        " Transfer Length too long for interface"
        );
#endif

  if(EAPI_I2C_IS_10BIT_ADDR(Addr))
  {
    LclpBuffer[LclByteCnt++]=(uint8_t)(Addr&0xFF);
    Addr>>=8;
  }

  if(!EAPI_I2C_IS_NO_CMD(Cmd)){
    if(EAPI_I2C_IS_EXT_CMD(Cmd))
      LclpBuffer[LclByteCnt++]=(uint8_t)((Cmd>>8)&0xFF);
    LclpBuffer[LclByteCnt++]=(uint8_t)(Cmd&0xFF);
  }

  return EApiI2CWriteReadRaw(
      Id, 
      (uint8_t)Addr, 
      &LclpBuffer, 
      LclByteCnt+1, 
      pBuffer, 
      BufLen, 
      ByteCnt+1
      );
}



EApiStatusCode_t 
EAPI_CALLTYPE
EApiI2CWriteTransfer(
    __IN  EApiId_t  Id      , /* I2C Bus Id */
    __IN  uint32_t  Addr    , /* Encoded 7/10Bit I2C 
                               * Device Address 
                               */
    __IN  uint32_t  Cmd     , /* I2C Command/Offset */
    __IN      void *pBuffer , /* Transfer Data pBuffer */
    __IN  uint32_t  ByteCnt   /* Byte Count to write */
    )
{
  uint8_t * pLclBuffer;
  uint32_t LclByteCnt=0;
  uint32_t ReturnValue;
  uint32_t MaxBlkLen;
  EAPI_CHECK_INITIALIZED(EApiI2CWriteTransfer);

  EAPI_LIB_ASSERT_PARAMATER_NULL(EApiI2CWriteTransfer, pBuffer);
#if (STRICT_VALIDATION>1)
  siFormattedMessage_M2(
          'L'                   ,
          __FILE__              ,
          "EApiI2CWriteTransfer",
          __LINE__              ,
          "Info"                ,
          "Id=%08"PRIX32" ADDR=%04"PRIX32
          " CMD=%04"PRIX32" BCNT=%04"PRIX32" %08"PRIX32"\n", 
          Id, Addr, Cmd, ByteCnt, ((uint32_t*)pBuffer)[0]
      );
#endif
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiI2CWriteTransfer, ByteCnt);

  pLclBuffer=(uint8_t *)malloc(ByteCnt+3);
  EAPI_LIB_RETURN_ERROR_IF(
      EApiI2CWriteTransfer, 
      (pLclBuffer==NULL), 
      EAPI_STATUS_ALLOC_ERROR, 
      "Error Allocating Memory"
      );

  if(EAPI_I2C_IS_10BIT_ADDR(Addr))
  {
    *pLclBuffer=(uint8_t)Addr&0xFF;
    Addr>>=8;
    LclByteCnt++;
  }

  if(!EAPI_I2C_IS_NO_CMD(Cmd)){
    if(EAPI_I2C_IS_EXT_CMD(Cmd)){
      pLclBuffer[LclByteCnt++]=(uint8_t)((Cmd>>8)&UINT8_MAX);
    }
    pLclBuffer[LclByteCnt++]=(uint8_t)((Cmd)&UINT8_MAX);
  }

#if (STRICT_VALIDATION>1)
  EApiI2CGetBusCap(Id, &MaxBlkLen);
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
      EApiI2CWriteTransfer, 
      (LclByteCnt+ByteCnt>MaxBlkLen), 
      "Transfer Length too long for interface"
      );
#endif

  if(LclByteCnt)
    memcpy(pLclBuffer+LclByteCnt, pBuffer, ByteCnt);
  else
  {
    free(pLclBuffer);
    pLclBuffer=(uint8_t *)pBuffer;
  }
#if (STRICT_VALIDATION>1)
  siFormattedMessage_M2(
          'L'                   ,
          __FILE__              ,
          "EApiI2CWriteTransfer",
          __LINE__              ,
          "Info"                ,
          "Id=%08"PRIX32" ADDR=%04"PRIX32" CMD=%04"PRIX32
          " BCNT=%04"PRIX32" %08"PRIX32"\n", 
          Id, Addr, Cmd, ByteCnt, 
          ((uint32_t*)pLclBuffer)[0]
        );
#endif
  ReturnValue=EApiI2CWriteReadRaw(
      Id, 
      (uint8_t)Addr, 
      pLclBuffer, 
      LclByteCnt+ByteCnt+1, 
      NULL, 
      0, 
      0
      );
  if(LclByteCnt)
    free(pLclBuffer);
  return ReturnValue;
}

EApiStatusCode_t 
EAPI_CALLTYPE
EApiI2CProbeDevice(
    __IN  EApiId_t  Id   , /* I2C Bus Id */
    __IN  uint32_t  Addr   /* Encoded 7/10Bit 
                            * I2C Device Address 
                            */
    )
{
  EApiStatusCode_t ReturnValue;
  uint8_t LclpBuffer[8]={0};
  int LclByteCnt=0;
  EAPI_CHECK_INITIALIZED(EApiI2CWriteTransfer);
  if(EAPI_I2C_IS_10BIT_ADDR(Addr))
  {
    LclpBuffer[LclByteCnt++]=(uint8_t)(Addr&0xFF);
    Addr>>=8;
  }
  ReturnValue=EApiI2CWriteReadRaw(
      Id, 
      (uint8_t)Addr, 
      LclpBuffer, 
      LclByteCnt+1, 
      NULL, 
      0, 
      0
      );
  if(ReturnValue==EAPI_STATUS_WRITE_ERROR)
    ReturnValue=EAPI_STATUS_NOT_FOUND;
  return ReturnValue;
}
/*
 *
 *  
 *
 *  Get String
 *
 *
 *
 */

EApiStatusCode_t
EAPI_CALLTYPE
EApiBoardGetStringA(
    __IN      EApiId_t  Id      , /* Name Id */
    __OUT     char     *pBuffer , /* Destination pBuffer */
    __INOUT   uint32_t *pBufLen   /* pBuffer Length */
    )
{
  EAPI_CHECK_INITIALIZED(EApiBoardGetStringA);
  EAPI_LIB_ASSERT_PARAMATER_NULL (EApiBoardGetStringA, pBufLen);
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
      EApiBoardGetStringA, 
      ((*pBufLen!=0)&&(pBuffer==NULL)) , 
      "pBuffer is NULL"          
      );

  return EApiBoardGetStringAEmul(Id, pBuffer, pBufLen);
}

/*
 *
 *  
 *
 *  Get Value
 *
 *
 *
 */
EApiStatusCode_t 
EAPI_CALLTYPE 
EApiBoardGetValue(
    __IN  EApiId_t  Id      , /* Value Id */
    __OUT uint32_t *pValue    /* Return Value */
    )
{
  EAPI_CHECK_INITIALIZED(EApiBoardGetValue);
  EAPI_LIB_ASSERT_PARAMATER_NULL(EApiBoardGetValue, pValue);

  if(Id==EAPI_ID_GET_EAPI_SPEC_VERSION){
    *pValue=EAPI_VERSION;
    EAPI_LIB_RETURN_SUCCESS(EApiBoardGetValue, "");
  }

  return EApiBoardGetValueEmul(Id, pValue);
}

/*
 *
 *  
 *
 *  B A C K L I G H T
 *
 *
 *
 */
EApiStatusCode_t
EAPI_CALLTYPE
EApiVgaGetBacklightEnable( 
    __IN  EApiId_t  Id      , /* Backlight Id */
    __OUT uint32_t *pEnable   /* Backlight Enable */
    )
{
  EAPI_CHECK_INITIALIZED(EApiVgaGetBacklightEnable);
  EAPI_LIB_ASSERT_PARAMATER_NULL(EApiVgaGetBacklightEnable, pEnable);

  return EApiVgaGetBacklightEnableEmul(Id, pEnable);
}

EApiStatusCode_t
EAPI_CALLTYPE
EApiVgaSetBacklightEnable(
    __IN  EApiId_t  Id      , /* Backlight Id */
    __IN  uint32_t  Enable    /* Backlight Enable */
    )
{

  EAPI_CHECK_INITIALIZED(EApiVgaSetBacklightEnable);
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
      EApiVgaSetBacklightEnable, 
      ((Enable!=EAPI_BACKLIGHT_SET_ON)||(Enable!=EAPI_BACKLIGHT_SET_OFF)), 
      "Enable Invalid Value"
      );

  return EApiVgaSetBacklightEnableEmul(Id, Enable);
}
EApiStatusCode_t
EAPI_CALLTYPE
EApiVgaGetBacklightBrightness( 
    __IN  EApiId_t  Id      , /* Backlight Id */
    __OUT uint32_t *pBright   /* Backlight Brightness */
    )
{
  EAPI_CHECK_INITIALIZED(EApiVgaGetBacklightBrightness);
  EAPI_LIB_ASSERT_PARAMATER_NULL(EApiVgaGetBacklightBrightness, pBright);

  return EApiVgaGetBacklightBrightnessEmul(Id, pBright);
}

EApiStatusCode_t 
EAPI_CALLTYPE
EApiVgaSetBacklightBrightness(
    __IN  EApiId_t  Id      , /* Backlight Id */
    __IN  uint32_t  Bright    /* Backlight Brightness */
    )
{
  EAPI_CHECK_INITIALIZED(EApiVgaSetBacklightBrightness);
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
      EApiVgaSetBacklightBrightness, 
      (Bright>EAPI_BACKLIGHT_SET_BRIGHTEST), 
      "Brightness Invalid Value"
      );

  return EApiVgaSetBacklightBrightnessEmul(Id, Bright);
}



/*
 *
 *  
 *
 *  G P I O
 *
 *
 *
 */

EApiStatusCode_t 
EAPI_CALLTYPE 
EApiGPIOGetLevel(
    __IN  EApiId_t Id          , /* GPIO Id */
    __IN  uint32_t Bitmask     , /* Bit mask of Affected
                                  * Bits 
                                  */
    __OUT uint32_t *pLevel       /* Current Level */
    )
{
  EAPI_CHECK_INITIALIZED(EApiGPIOGetLevel);
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiGPIOGetLevel, Bitmask);
  EAPI_LIB_ASSERT_PARAMATER_NULL(EApiGPIOGetLevel, pLevel);

  return EApiGPIOGetLevelEmul(Id, Bitmask, pLevel);
}

EApiStatusCode_t
EAPI_CALLTYPE 
EApiGPIOSetLevel(
    __IN  EApiId_t Id          , /* GPIO Id */
    __IN  uint32_t Bitmask     , /* Bit mask of Affected 
                                  * Bits 
                                  */
    __IN  uint32_t Level         /* Level */  
    )
{
  EAPI_CHECK_INITIALIZED(EApiGPIOSetLevel);
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiGPIOSetLevel, Bitmask);

  return EApiGPIOSetLevelEmul(Id, Bitmask, Level);
}

EApiStatusCode_t 
EAPI_CALLTYPE 
EApiGPIOGetDirection(
    __IN  EApiId_t Id          , /* GPIO Id */
    __IN  uint32_t Bitmask     , /* Bit mask of Affected
                                  * Bits 
                                  */
    __OUT uint32_t *pDirection   /* Current Direction */
    )
{
  EAPI_CHECK_INITIALIZED(EApiGPIOGetDirection);
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiGPIOGetDirection, Bitmask);
  EAPI_LIB_ASSERT_PARAMATER_NULL(EApiGPIOGetDirection, pDirection);

  return EApiGPIOGetDirectionEmul(Id, Bitmask, pDirection);
}

EApiStatusCode_t 
EAPI_CALLTYPE 
EApiGPIOSetDirection(
    __IN  EApiId_t Id          , /* GPIO Id */
    __IN  uint32_t Bitmask     , /* Bit mask of Affected 
                                  * Bits 
                                  */
    __IN  uint32_t Direction     /* Direction */
    )
{
  EAPI_CHECK_INITIALIZED(EApiGPIOSetDirection);
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiGPIOSetDirection, Bitmask);

  return EApiGPIOSetDirectionEmul(Id, Bitmask, Direction);
}

EApiStatusCode_t
EAPI_CALLTYPE 
EApiGPIOGetDirectionCaps(
    __IN     EApiId_t Id        , /* GPIO Id */
    __OUTOPT uint32_t *pInputs  , /* Supported GPIO Input
                                   * Bit Mask 
                                   */
    __OUTOPT uint32_t *pOutputs   /* Supported GPIO Output
                                   * Bit Mask 
                                   */
    )
{
  uint32_t DpBuffer;

  EAPI_CHECK_INITIALIZED(EApiGPIOGetDirectionCaps);
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
      EApiGPIOGetDirectionCaps, 
      ((pOutputs==NULL)&&(pInputs==NULL)), 
      "((pOutputs==NULL)&&(pInputs==NULL))"
      );

  if(pInputs==NULL)
    pInputs=&DpBuffer;
  if(pOutputs==NULL)
    pOutputs=&DpBuffer;

  return EApiGPIOGetDirectionCapsEmul(Id, pInputs, pOutputs);
}


/*
 *
 *  
 *
 *  S T D 
 *
 *
 *
 */
EApiStatusCode_t 
EAPI_CALLTYPE 
EApiLibInitialize(void)
{
  EAPI_CHECK_NOT_INITIALIZED(EApiLibInitialize);
  Initialized=1;
  EApiInitLib();
  EAPI_LIB_RETURN_SUCCESS(EApiLibInitialize, "");
}
EApiStatusCode_t 
EAPI_CALLTYPE 
EApiLibUnInitialize(void)
{
  EAPI_CHECK_INITIALIZED(EApiLibUnInitialize);
  EApiUninitLib();
  Initialized=0;
  EAPI_LIB_RETURN_SUCCESS(EApiLibUnInitialize, "");
}



/*
 *
 *  
 *
 *  W A T C H D O G
 *
 *
 *
 */
EApiStatusCode_t 
EAPI_CALLTYPE
EApiWDogGetCap(
    __OUTOPT uint32_t *pMaxDelay       ,/* Maximum Supported 
                                         * Delay in milliseconds
                                         */
    __OUTOPT uint32_t *pMaxEventTimeout,/* Maximum Supported 
                                         * Event Timeout in 
                                         * milliseconds
                                         * 0 == Unsupported
                                         */
    __OUTOPT uint32_t *pMaxResetTimeout /* Maximum Supported 
                                         * Reset Timeout in 
                                         * milliseconds
                                         */
    )
{
  uint32_t DummyData;
  EAPI_CHECK_INITIALIZED(EApiWDogGetCap);
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
    EApiWDogGetCap, 
    ((pMaxDelay==NULL)&&(pMaxEventTimeout==NULL)&&(pMaxResetTimeout==NULL)), 
   "((pMaxDelay==NULL)&&(pMaxEventTimeout==NULL)&&(pMaxResetTimeout==NULL))"
  );

   if(pMaxDelay       ==NULL) pMaxDelay       =&DummyData;
   if(pMaxEventTimeout==NULL) pMaxEventTimeout=&DummyData;
   if(pMaxResetTimeout==NULL) pMaxResetTimeout=&DummyData;
  return EApiWDogGetCapEmul(pMaxDelay, pMaxEventTimeout, pMaxResetTimeout);
}

EApiStatusCode_t 
EAPI_CALLTYPE 
EApiWDogStart(
    __IN  uint32_t Delay       , /* Delay in milliseconds */
    __IN  uint32_t EventTimeout, /* Event Timeout in 
                                  * milliseconds 
                                  */
    __IN  uint32_t ResetTimeout  /* Reset Timeout in 
                                  * milliseconds 
                                  */
    )
{
  EAPI_CHECK_INITIALIZED(EApiWDogStart);
  return EApiWDogStartEmul(Delay, EventTimeout, ResetTimeout);
}
EApiStatusCode_t
EAPI_CALLTYPE 
EApiWDogTrigger(void)
{
  EAPI_CHECK_INITIALIZED(EApiWDogTrigger);
  return EApiWDogTriggerEmul();
}
EApiStatusCode_t 
EAPI_CALLTYPE 
EApiWDogStop(void)
{
  EAPI_CHECK_INITIALIZED(EApiWDogStop);
  return EApiWDogStopEmul();
}

/*
 *
 *  
 *
 *  S T O R A G E 
 *
 *
 *
 */
EApiStatusCode_t 
EAPI_CALLTYPE 
EApiStorageCap(
    __IN  EApiId_t  Id            , /* Storage Area Id */
    __OUT uint32_t  *pStorageSize , /* Total */
    __OUT uint32_t  *pBlockLength   /* Write Block Length & Alignment */
    )
{
  uint32_t DummyValue;

  EAPI_CHECK_INITIALIZED(EApiStorageCap);
  EAPI_LIB_ASSERT_PARAMATER_CHECK(
      EApiStorageCap, 
      ((pBlockLength==NULL)&&(pStorageSize==NULL)), 
      "((pBlockLength==NULL)&&(pStorageSize==NULL))"
      );
  if(pStorageSize==NULL)
    pStorageSize=&DummyValue;         /* Better Example for a wrapper */
  if(pBlockLength==NULL)
    pBlockLength=&DummyValue;

  return EApiStorageCapEmul(Id, pStorageSize, pBlockLength);
}
EApiStatusCode_t 
EAPI_CALLTYPE 
EApiStorageAreaRead(
    __IN  EApiId_t  Id      , /* Storage Area Id */
    __IN  uint32_t  Offset  , /* Byte Offset */
    __OUT     void *pBuffer , /* Pointer to Date pBuffer */
    __IN  uint32_t  BufLen  , /* Data pBuffer Size in bytes */
    __IN  uint32_t  ByteCnt   /* Number of bytes to read */
    )
{
  EApiStatusCode_t ErrorCode=EAPI_STATUS_SUCCESS;
  EApiStatusCode_t ErrorCode2;
  EAPI_CHECK_INITIALIZED(EApiStorageAreaRead);
#if (STRICT_VALIDATION>1)
  siFormattedMessage_M2(
          'L'                   ,
          __FILE__              ,
          "EApiI2CWriteTransfer",
          __LINE__              ,
          "Info"                ,
          "Id=%08"PRIX32" Offset=%04"PRIX32
          " BufLen=%04"PRIX32" ByteCnt=%04"PRIX32"\n", 
          Id, Offset, BufLen, ByteCnt
        );
#endif
  EAPI_LIB_ASSERT_PARAMATER_NULL(EApiStorageAreaRead, pBuffer);
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiStorageAreaRead, ByteCnt);
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiStorageAreaRead, BufLen);

  EAPI_LIB_PREVENT_BUF_OVERFLOW(EApiStorageAreaRead, ByteCnt, BufLen);

  ErrorCode2=EApiStorageAreaReadEmul(Id, Offset, pBuffer, ByteCnt);
  if(ErrorCode2!=EAPI_STATUS_SUCCESS)
    return ErrorCode2;
  return ErrorCode;
}

EApiStatusCode_t 
EAPI_CALLTYPE 
EApiStorageAreaWrite(
    __IN  EApiId_t  Id      , /* Storage Area Id */
    __IN  uint32_t  Offset  , /* Byte Offset */
    __IN      void *pBuffer , /* Pointer to Date pBuffer */
    __IN  uint32_t  ByteCnt   /* Number of bytes to write */
    )
{

  EAPI_CHECK_INITIALIZED(EApiStorageAreaWrite);
#if (STRICT_VALIDATION>1)
  siFormattedMessage_M2(
          'L'                   ,
          __FILE__              ,
          "EApiI2CWriteTransfer",
          __LINE__              ,
          "Info"                ,
          "Id=%08"PRIX32" Offset=%04"PRIX32
          " ByteCnt=%04"PRIX32"\n",
          Id, Offset, ByteCnt
        );
#endif
  EAPI_LIB_ASSERT_PARAMATER_NULL(EApiStorageAreaWrite, pBuffer);
  EAPI_LIB_ASSERT_PARAMATER_ZERO(EApiStorageAreaWrite, ByteCnt);

  return EApiStorageAreaWriteEmul(Id, Offset, pBuffer, ByteCnt);
}

