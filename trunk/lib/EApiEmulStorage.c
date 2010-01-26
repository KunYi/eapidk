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
 *I Description: Auto Created for EApiEmulStorage.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiEmulStorage.c
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




/*
 *
 *  
 *
 *  S T O R A G E 
 *
 *
 *
 */
typedef struct StorageAreaMapping_s{
  uint32_t Id          ; /* EAPI Storage Area Id */
  uint32_t StorageSize ; /* Storage Area Size */
  uint32_t WBlockLength; /* Block Lenght/Alignment */
  uint8_t *pBuffer     ; /* Pointer to Storage pBuffer */
}StorageAreaMapping_t;
static uint8_t StorageID0[32]={0};
static uint8_t StorageID1[1024*4]={0};
const StorageAreaMapping_t StorageAreaTbl[]={
  {EAPI_ID_STORAGE_STD, sizeof(StorageID0), sizeof(StorageID0[0])       , StorageID0  },
  {EAPI_PMG_ID_STORAGE_SAMPLE, sizeof(StorageID1), sizeof(StorageID1[0])*1024  , StorageID1  }
};
uint32_t 
EApiStorageCapEmul (
    __IN      uint32_t  Id          , 
    __OUTOPT  uint32_t *pStorageSize, 
    __OUTOPT  uint32_t *pBlockLength
    )
{
  uint32_t i;

  for(i=0;i<ARRAY_SIZE(StorageAreaTbl);i++)
  {
      if(StorageAreaTbl[i].Id==Id)
      {
        *pStorageSize=StorageAreaTbl[i].StorageSize;
        *pBlockLength=StorageAreaTbl[i].WBlockLength;
        EAPI_LIB_RETURN_SUCCESS(EApiStorageCap, "");
      }
  }
  EAPI_LIB_RETURN_ERROR(
    EApiStorageCapEmul        , 
    EAPI_STATUS_UNSUPPORTED   , 
    "Unrecognised Storage ID"
    );
}
uint32_t 
EApiStorageAreaReadEmul(
  __IN  uint32_t Id     , 
  __IN  uint32_t Offset , 
  __OUT    void *pBuffer, 
  __IN  uint32_t ByteCnt
  )
{
  uint32_t i;

  for(i=0;i<ARRAY_SIZE(StorageAreaTbl);i++)
  {
      if(StorageAreaTbl[i].Id==Id)
      {
        EAPI_LIB_RETURN_ERROR_IF(
          EApiStorageAreaReadEmul                         , 
          (Offset+ByteCnt)>StorageAreaTbl[i].StorageSize  , 
          EAPI_STATUS_INVALID_BLOCK_LENGTH                , 
          "Read Len extends beyond End of Storage Area"
          );
        
        memcpy(pBuffer, StorageAreaTbl[i].pBuffer, ByteCnt);

        EAPI_LIB_RETURN_SUCCESS(EApiStorageAreaRead, "");
      }
  }
  EAPI_LIB_RETURN_ERROR(
      EApiStorageAreaReadEmul  , 
      EAPI_STATUS_UNSUPPORTED  , 
      "Unrecognised Storage ID"
      );
}

uint32_t 
EApiStorageAreaWriteEmul(
    __IN uint32_t Id, 
    __IN uint32_t Offset, 
    __IN void *pBuffer, 
    __IN uint32_t ByteCnt
    )
{
  uint32_t i;
  for(i=0;i<ARRAY_SIZE(StorageAreaTbl);i++)
  {
      if(StorageAreaTbl[i].Id==Id)
      {
        EAPI_LIB_RETURN_ERROR_IF(
          EApiStorageAreaWriteEmul, 
          (ByteCnt%StorageAreaTbl[i].WBlockLength)       , 
          EAPI_STATUS_INVALID_BLOCK_ALIGNMENT, 
          "Write length Not Aligned"        
          );
        EAPI_LIB_RETURN_ERROR_IF(
          EApiStorageAreaWriteEmul, 
          (Offset%StorageAreaTbl[i].WBlockLength)        , 
          EAPI_STATUS_INVALID_BLOCK_ALIGNMENT, 
          "Write Base Address Not Aligned"        
          );
        EAPI_LIB_RETURN_ERROR_IF(
            EApiStorageAreaWriteEmul, 
            (Offset+ByteCnt)>StorageAreaTbl[i].StorageSize , 
            EAPI_STATUS_INVALID_BLOCK_LENGTH, 
            "Write Len extends beyond End of Storage Area"
            );

        memcpy(StorageAreaTbl[i].pBuffer, pBuffer, ByteCnt);
        EAPI_LIB_RETURN_SUCCESS(EApiStorageAreaWriteEmul, "");
      }
  }
  EAPI_LIB_RETURN_ERROR(
      EApiStorageAreaWrite, 
      EAPI_STATUS_UNSUPPORTED  , 
      "Unrecognised Storage ID"
      );
}

