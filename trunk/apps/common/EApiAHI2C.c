/*
 *<KHeader>
 *+=========================================================================
 *I               EApiDK Embedded Application Development Kit
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
 *I Description: Auto Created for EApiAHI2C.c
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiAHI2C.c
 *I  File Location        : apps\common
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EApiApp.h>

uint32_t 
EApiAHI2CProbeDevice(
    __IN  uint32_t              Id    , 
    __IN  uint32_t              EncAddr
    )
{
  uint32_t ReturnValue;
  ReturnValue=EApiI2CReadTransfer(
    Id, 
    EncAddr, 
    EAPI_I2C_NO_CMD, 
    &ReturnValue, 
    sizeof(ReturnValue), 
    1
  );
  if(ReturnValue==EAPI_STATUS_READ_ERROR)
    ReturnValue=EAPI_STATUS_SUCCESS;

  return ReturnValue;
}

uint32_t 
EApiAHI2CCCreateAddrOffset(
    __IN  const I2CDeviceDesc_t *const pDDesc     , 
    __IN  uint32_t                     Offset     , 
    __OUT uint32_t                    *pEncAddr   , 
    __OUT uint32_t                    *pEncOffset
    )
{
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CCCreateAddrOffset, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pDDesc
        );
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CCCreateAddrOffset, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pEncAddr
        );
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CCCreateAddrOffset, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pEncOffset
        );
    if(pDDesc->ExtIndx==EApiAPI2CExtIndex)
    {
      *pEncOffset=EAPI_I2C_ENC_EXT_CMD(Offset);
      Offset>>=16;
      Offset&=3;
      if(EAPI_I2C_IS_10BIT_ADDR(pDDesc->DeviceAddr))
        *pEncAddr=EAPI_I2C_ENC_10BIT_ADDR(
            EAPI_I2C_DEC_10BIT_ADDR(pDDesc->DeviceAddr)+Offset);
      else
        *pEncAddr=EAPI_I2C_ENC_7BIT_ADDR(
            EAPI_I2C_DEC_7BIT_ADDR(pDDesc->DeviceAddr)+Offset);
    }
    else
    {
      *pEncOffset=EAPI_I2C_ENC_STD_CMD(Offset);
      Offset>>=8;
      Offset&=3;
      if(EAPI_I2C_IS_10BIT_ADDR(pDDesc->DeviceAddr))
        *pEncAddr=EAPI_I2C_ENC_10BIT_ADDR(
            EAPI_I2C_DEC_10BIT_ADDR(pDDesc->DeviceAddr)+Offset);
      else
        *pEncAddr=EAPI_I2C_ENC_7BIT_ADDR(
            EAPI_I2C_DEC_7BIT_ADDR(pDDesc->DeviceAddr)+Offset);

    }
  return EAPI_STATUS_SUCCESS;
}
uint32_t
EApiAHI2CWriteEeprom(
    __IN uint32_t               Id          , 
    __IN const I2CDeviceDesc_t *const pDDesc, 
    __IN const uint32_t         ByteOffset  , 
    __IN void *                 pBuffer     , 
    __IN uint32_t               ByteCnt 
    )
{
/*     char TmpStrBuf[256]; */
    uint32_t IntMaxBlckLen;
    uint32_t BlockEndAddress;
    uint32_t BlockLength;
    uint32_t BlockLengthStd;
    uint32_t CurOffset;
    uint32_t EncAddr;
    uint32_t EncOffset;
    uint32_t ReturnValue;
    
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CWriteEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pDDesc
        );
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CWriteEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pBuffer
        );
    EAPI_APP_ASSERT_PARAMATER_ZERO(
        EApiAHI2CWriteEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ByteCnt
        );
    EAPI_APP_ASSERT_PARAMATER_CHECK(
        EApiAHI2CWriteEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ByteOffset+ByteCnt>pDDesc->DevSize, 
        TEXT("Prevented Write beyond Device Boundary")
        );
#if STRICT_VALIDATION
    if(ByteOffset+ByteCnt>pDDesc->DevSize)
    {
      ByteCnt=pDDesc->DevSize-ByteOffset;
    }
#endif
    
    /* Get Storage Capabilities */
    ReturnValue=EApiI2CGetBusCap(Id, &IntMaxBlckLen);
    if(ReturnValue!=EAPI_STATUS_SUCCESS)
      return ReturnValue;

    BlockEndAddress=ByteOffset+ByteCnt;
    /* Just use BlockLength as write overhead calculator briefly 
     * Write Overhead is CMD + 10Bit Address
     * I.E. First Byte of address is not included
     * so CMD/INDX can be 1  or 2 Bytes and the Address can add an extra byte
     * so we can have between 1 and 3 bytes overhead on an write.
     */
    BlockLength=(EAPI_I2C_DEC_10BIT_ADDR(pDDesc->DeviceAddr)?1:0)+pDDesc->ExtIndx;
    /* Ok so now we need to check if Page Size+ Write overhead is greater than the 
     * Max Transfer length on this interface
     * Basically use whichever is shorter for our Block Length
     */
    BlockLength=(IntMaxBlckLen<(pDDesc->PageSize+BlockLength)?IntMaxBlckLen-BlockLength:pDDesc->PageSize);
    /* This check is more important for reads than writes */
    if(pDDesc->ExtIndx==EApiAPI2CExtIndex)
      /* After this length it is necessary to increment the Device Address */
      BlockLength=(BlockLength<0x10000?BlockLength:0x10000);
    else
      /* After this length it is necessary to increment the Device Address */
      BlockLength=(BlockLength<0x100?BlockLength:0x100);
    CurOffset=ByteOffset;
    BlockLengthStd=BlockLength;
    while(CurOffset<BlockEndAddress)
    {
      /* Adjust block length so we don't write more than we intended 
       */
      if(CurOffset+BlockLength>BlockEndAddress){
        BlockLength=BlockEndAddress - CurOffset;
      }
      /* Adjust block length so we don't overrun the end of the Page 
       * As we've already verified all the maximum block lengths above
       * This should only be because of 2 reasons
       * 1. Start offset isn't aligned. 
       * 2. Bus interfaces maximum block length is not a divisor of the 
       *    EEPROM page length. 
       * To adequately address both situations, or indeed a combination
       * of them we check here if we're going to overwrite the page boundary
       * and if so adjust the Block length. At the end of the transfer we 
       * restore the Max calculate block length, from above and do it all over 
       * again 
       * Example 1.
       * Max Bus length = 16 Bytes
       * Page Size      = 16 Bytes
       * Start Offset   =  1
       * Write Overhead =  2 Bytes     For the Ext Index
       * Total Transfer = 32 Bytes
       *
       * Results in a 
       * Max Block length of 14 Bytes
       * This results in 5 transfers
       * 14Bytes 1Byte 14Bytes 2Bytes 1Byte
       *
       * Example 2.
       * Max Bus length = 18 Bytes
       * Page Size      = 16 Bytes
       * Start Offset   =  3
       * Write Overhead =  3 Bytes     For the Ext Index & 10Bit Address
       * Total Transfer = 30 Bytes
       *
       * Results in a 
       * Max Block length of 15 Bytes
       * This results in 4 transfers
       * 13Bytes 15Bytes 1Bytes 1Bytes 
       *
       * Example 3.
       * Max Bus length =  32 Bytes
       * Page Size      = 256 Bytes
       * Start Offset   = 230 
       * Write Overhead =   2 Bytes     For the Extended Index
       * Total Transfer =  60 Bytes
       *
       * Results in a 
       * Max Block length of 30 Bytes
       * This results in 3 transfers
       * 26Bytes 30Bytes 4Bytes
       */
      if(((CurOffset%pDDesc->PageSize)+BlockLength)>pDDesc->PageSize){
        BlockLength-=(CurOffset+BlockLength)%pDDesc->PageSize;
      }
      /* Get Encoded Device and Offset */
      ReturnValue=EApiAHI2CCCreateAddrOffset(pDDesc, CurOffset, &EncAddr, &EncOffset);
      if(ReturnValue!=EAPI_STATUS_SUCCESS)
        return ReturnValue;
      /* Do the actual transfer */
      ReturnValue=EApiI2CWriteTransfer(
          Id, 
          EncAddr, 
          EncOffset, 
          &((int_least8_t *)pBuffer)[CurOffset-ByteOffset], 
          BlockLength
          );
      if(ReturnValue!=EAPI_STATUS_SUCCESS)
        return ReturnValue;
      CurOffset+=BlockLength;
      BlockLength=BlockLengthStd; /* Restore Standard Block Length */
      if(pDDesc->WRecTimems)
        EApiSleep(pDDesc->WRecTimems); /* Allow Device Time to Recover */
    }
    return ReturnValue;
}
uint32_t
EApiAHI2CReadEeprom(
    __IN uint32_t              Id           , 
    __IN const I2CDeviceDesc_t *const pDDesc, 
    __IN const uint32_t        ByteOffset   , 
    __IN void *                pBuffer      , 
    __IN const uint32_t        BufLength    , 
    __IN uint32_t              ByteCnt 
    )
{
/*     char TmpStrBuf[256]; */
    uint32_t IntMaxBlckLen;
    uint32_t BlockEndAddress;
    uint32_t BlockLength;
    uint32_t CurOffset;
    uint32_t EncAddr;
    uint32_t EncOffset;
    uint32_t ReturnValue;
    
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CReadEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pDDesc
        );
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CReadEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pBuffer
        );
    EAPI_APP_ASSERT_PARAMATER_ZERO(
        EApiAHI2CReadEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        BufLength
        );
    EAPI_APP_ASSERT_PARAMATER_ZERO(
        EApiAHI2CReadEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ByteCnt
        );
    EAPI_APP_PREVENT_BUF_OVERFLOW(
        EApiAHI2CReadEeprom, 
        ByteCnt, 
        BufLength
        );
#if STRICT_VALIDATION
    if(ByteOffset+ByteCnt>pDDesc->DevSize)
    {
      ByteCnt=pDDesc->DevSize-ByteOffset;
    }
#endif
    
    /* Get Storage Capabilities */
    ReturnValue=EApiI2CGetBusCap(Id, &IntMaxBlckLen);
    if(ReturnValue!=EAPI_STATUS_SUCCESS)
      return ReturnValue;

    BlockEndAddress=ByteOffset+ByteCnt;

    BlockLength=IntMaxBlckLen;
    if(pDDesc->ExtIndx==EApiAPI2CExtIndex)
      /* After this length it is necessary to increment the Device Address */
      BlockLength=(BlockLength<0x10000?BlockLength:0x10000);
    else
      /* After this length it is necessary to increment the Device Address */
      BlockLength=(BlockLength<0x100?BlockLength:0x100);
    CurOffset=ByteOffset;
    while(CurOffset<BlockEndAddress)
    {
      /* Adjust block length so we don't overrun the end of the device */
      if(CurOffset+BlockLength>BlockEndAddress){
        BlockLength=BlockEndAddress-CurOffset;
      }
      /* Get Encoded Device and Offset */
      ReturnValue=EApiAHI2CCCreateAddrOffset(pDDesc, CurOffset, &EncAddr, &EncOffset);
      if(ReturnValue!=EAPI_STATUS_SUCCESS)
        return ReturnValue;
      /* Do the actual transfer */
      ReturnValue=EApiI2CReadTransfer(
          Id, 
          EncAddr, 
          EncOffset, 
          &((int_least8_t *)pBuffer)[CurOffset-ByteOffset], 
          BlockLength, 
          BlockLength
          );
      if(ReturnValue!=EAPI_STATUS_SUCCESS)
        return ReturnValue;
      CurOffset+=BlockLength;
    }


    return ReturnValue;
}
