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
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN 
 *I              "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: Embedded EEPROM
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : STDEEP.h
 *I  File Location        : include
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */

/* Structures for Embedded EEPROM */
#ifndef __EEEP_H__    
#define __EEEP_H__

#ifndef EEEP_UINT32_C
#  define EEEP_UINT8_C(x)  ((uint8_t)(x))
#  define EEEP_UINT16_C(x) ((uint16_t)(x))
#  define EEEP_UINT32_C(x) ((uint32_t)(x))
#endif

//#pragma pack(push)
#pragma pack(1)


/* 
 * Detecting COM0 R2.0 EEPROM
 *
 * High Level Check
 * if(!memcmp(
 *        &COM0EEP[0x00]            , 
 *        "COM0"                    , 
 *        0x04
 *      )
 *   )
 * {
 *    // Found COM0R20 EEPROM
 * }
 *
 * Sample I2C Transfer
 *  Device Address : 0xA8
 *  Index Type     : Standard
 *    Start<0xA8><W>Ack<0x00>Ack
 *    Start<0xA8><R>Ack<'C'>Ack<'O'>Ack<'M'>Ack<'0'>Nak Stop
 *  Device Address : 0xA8
 *  Index Type     : Extended
 *    Start<0xA8><W>Ack<0x00>Ack<0x00>Ack
 *    Start<0xA8><R>Ack<'C'>Ack<'O'>Ack<'M'>Ack<'0'>Nak Stop
 * 
 */

/* 
 * Detecting COM0 R1.0 EEPROM
 *
 * High Level Check
 * if(!memcmp(
 *        &COM0EEP[0xE0]            , 
 *        "COMExpressConfig"        , 
 *        0x10
 *      )
 *   )
 * {
 *    // Found COM0R10 EEPROM
 * }
 *
 * Sample I2C Transfer
 *  Device Address : 0xA8
 *  Index Type     : Standard
 *    Start<0xA8><W>Ack<0xE0>Ack 
 *    Start<0xA8><R>Ack<'C'>Ack<'O'>Ack<'M'>Ack<'E'>Ack<'x'>Ack<'p'>Ack
 *                     <'r'>Ack<'e'>Ack<'s'>Ack<'s'>Ack<'C'>Ack<'o'>Ack
 *                     <'n'>Ack<'f'>Ack<'i'>Ack<'g'>Nak Stop                                              
 * 
 */


#define EEEP_VER_MASK_VER     EEEP_UINT8_C(0xF0)
#define EEEP_VER_MASK_REV     EEEP_UINT8_C(0x0F)
#define EEEP_VER_GET_VER(x)   EEEP_UINT8_C (((x)>>4)&0x0F )
#define EEEP_VER_GET_REV(x)   EEEP_UINT8_C (((x)>>0)&0x0F )
#define EEEP_VER_CREATE(Version,Revision) (\
                      EEEP_UINT8_C(\
                        (((Version )&0x0F )<<4)|\
                        (((Revision)&0x0F )<<0) \
                      )\
                    )

/* COM0 R2.0 Standard Revision */
#define EEEP_VER      0
#define EEEP_REVISION 5
#define EEEP_VERSION EEEP_VER_CREATE(EEEP_VER, EEEP_REVISION)




/*
 * EEPROM Common Header
 *
 */
typedef struct StdEep_s{
    uint8_t     EepId[4]   ; /* 0x00 COM0 */
#       define  EEEP_R2_EEPROM_MARKER 0x304D4F43
    uint8_t     BlkOffset  ; /* 0x04 Absolute Offset to
                              *      First Block
                              */
    uint8_t     DeviceDesc ; /* 0x05 Device Descriptor
                              * +========+========================+
                              * | Bits   | Description            |
                              * +========+========================+
                              * | 0 - 3  | Size 2^(8+n) Bytes     |
                              * |        | (256 << n) Bytes       |
                              * |        |                        |
                              * |        | Addressable Bytes      |
                              * |        |   Standard Index       |
                              * |        |     8bit - 11Bit       |
                              * |        |   Extended Index       |
                              * |        |     16bit - 19Bit      |
                              * |        | 2048 KBit - 4096 MBit  |
                              * |        | 256 Bytes - 512 KBytes |
                              * |        |                        |
                              * +--------+------------------------+
                              * | 4      | Std/Ext Index          |
                              * +--------+------------------------+
                              * | 5 - 7  | Reserved               |
                              * +========+========================+
                              */
    uint8_t     VendId[2]  ; /* 0x06 Compressed PNPID            */
    uint8_t     DeviceId[2]; /* 0x08 Vendor Specific Device ID   */
    uint8_t     DeviceFlav ; /* 0x0A */
    uint8_t     RevId      ; /* 0x0B Vendor Specific Revision ID */
}StdEep_t;



/*
 * COM R2.0
 * Expansion EEPROM Header
 *
 */
typedef struct Exp_EEP_s{
    StdEep_t    EepHdr     ; /* 0x00 EEprom Id       */
}Exp_EEP_t;




/*
 * Block Common Header
 *
 */
typedef struct BlockIdHdr_s{
    uint8_t    BlockId       ; /* 0x00 Block Id       */
    uint8_t    BlockLength[2]; /* 0x01 Block Length   */
}BlockIdHdr_t;

/*
 *
 *
 *
 * Block Types
 *
 *
 *
 */

/*
 * Block Ids
 *
 */
#define EEEP_BLOCK_ID_UNUSED            EEEP_UINT8_C(0x00)
/*
 * 0xC0 -0xCF See Platform Specific Headers
 *
 */
#define EEEP_BLOCK_ID_VENDOR_SPECIFIC   EEEP_UINT8_C(0xF0)
#define EEEP_BLOCK_ID_EXP_EEPROM        EEEP_UINT8_C(0xF1)
/*
 * 0xE0 -0xEF See Platform Specific Headers
 *
 */
#define EEEP_BLOCK_ID_SYSTEM_DESC       EEEP_UINT8_C(0xD1)
#define EEEP_BLOCK_ID_MODULE_DESC       EEEP_UINT8_C(0xD2)
#define EEEP_BLOCK_ID_CHASSIS_DESC      EEEP_UINT8_C(0xD3)
#define EEEP_BLOCK_ID_CRC_CHK           EEEP_UINT8_C(0xF2)
#define EEEP_BLOCK_ID_IGNORE            EEEP_UINT8_C(0xFF)

#define EEEP_OFFSET_VALUE_EOL           EEEP_UINT16_C(0x0000)
#define EEEP_OFFSET_VALUE_EOL_ALT       EEEP_UINT16_C(0xFFFF)

/*
 * CRC Checksum Block
 *
 */
typedef struct CRC16ChkBlock_s{
    BlockIdHdr_t  cHdr          ; /* 0x00 Block Header */
    uint8_t       CrC16[2]      ; /* 0x03 CRC16 Checksum */
}CRC16ChkBlock_t;


/*
 *      System Information
 *
 *  see http://www.dmtf.org/standards/documents/SMBIOS/DSP0134.pdf
 */

typedef struct SystemInfo_s{
    BlockIdHdr_t  cHdr    ; /* 0x00 Block Header */
    uint8_t Manufacturer  ; /* 0x03 Number of ASCIIZ String */
    uint8_t ProductName   ; /* 0x04 Number of ASCIIZ String */
    uint8_t Version       ; /* 0x05 Number of ASCIIZ String */
    uint8_t SerialNumber  ; /* 0x06 Number of ASCIIZ String */
    uint8_t SKU_Number    ; /* 0x07 Number of ASCIIZ String */
    uint8_t Family        ; /* 0x08 Number of ASCIIZ String */
    uint8_t AssetTagNumber; /* 0x09 Number of ASCIIZ String */
    char StringsBlock[1] ;  /* 0x0A String Block */
}SystemInfo_t;

/*
 *      Chassis Information
 *
 *  see http://www.dmtf.org/standards/documents/SMBIOS/DSP0134.pdf
 */
typedef struct ChassisInfo_s{
    BlockIdHdr_t  cHdr    ; /* 0x00 Block Header */
    uint8_t Manufacturer  ; /* 0x03 Number of ASCIIZ String */
    uint8_t ChassisType   ; /* 0x04 ENUM */
    uint8_t Version       ; /* 0x05 Number of ASCIIZ String */
    uint8_t SerialNumber  ; /* 0x05 Number of ASCIIZ String */
    uint8_t AssetTagNumber; /* 0x06 Number of ASCIIZ String */
    char StringsBlock[1] ;  /* 0x07 String Block */
}ChassisInfo_t;

/*
 *     Base Board (or Module) Information
 *
 *  see http://www.dmtf.org/standards/documents/SMBIOS/DSP0134.pdf
 */
typedef struct ModuleInfo_s{
    BlockIdHdr_t  cHdr   ; /* 0x00 Block Header */
    uint8_t Manufacturer ; /* 0x03 Number of ASCIIZ String */
    uint8_t Product      ; /* 0x04 Number of ASCIIZ String */
    uint8_t Version      ; /* 0x05 Number of ASCIIZ String */
    uint8_t SerialNumber ; /* 0x06 Number of ASCIIZ String */
    uint8_t AssetTag     ; /* 0x07 Number of ASCIIZ String */
    uint8_t FeatureFlag  ; /* 0x08 A collection of 
                            *      flags that identify 
                            *      features of this 
                            *      baseboard.
                            *      +=======+=========================+
                            *      | Bits  | Descriptions            |
                            *      +=======+=========================+
                            *      | 0     | Is Motherboard          |
                            *      +-------+-------------------------+
                            *      | 1     | Requires Daughter Board |
                            *      +-------+-------------------------+
                            *      | 2     | Removable               |
                            *      +-------+-------------------------+
                            *      | 3     | Replaceable             |
                            *      +-------+-------------------------+
                            *      | 4     | Hot Swap Capable        |
                            *      +-------+-------------------------+
                            *      | 5 - 7 | Reserved                |
                            *      +=======+=========================+
                            */
#       define SMBIOS_IS_Motherboard  EEEP_UINT8_C(1 << 0)
#       define SMBIOS_REQ_DAUGHTER    EEEP_UINT8_C(1 << 1)
#       define SMBIOS_REMOVABLE       EEEP_UINT8_C(1 << 2)
#       define SMBIOS_REPLACEABLE     EEEP_UINT8_C(1 << 3)
#       define SMBIOS_HOT_SWAP_CAP    EEEP_UINT8_C(1 << 4)
    uint8_t Location     ; /* 0x09 Number of ASCIIZ String */
    uint8_t BoardType    ; /* 0x0A SMBIOS_BoardTypes_t */
    char StringsBlock[1] ; /* 0x0B String Block */
}ModuleInfo_t;
typedef enum SMBIOS_BoardTypes_e{
  SMBIOS_BoardType_Unknown=0,
  SMBIOS_BoardType_Other,
  SMBIOS_BoardType_ServerBlade,
  SMBIOS_BoardType_ConnectivitySwitch,
  SMBIOS_BoardType_SystemManagementModule,
  SMBIOS_BoardType_ProcessorModule,
  SMBIOS_BoardType_IO_Module,
  SMBIOS_BoardType_Memory_Module,
  SMBIOS_BoardType_DaughterBoard,
  SMBIOS_BoardType_Motherboard,
  SMBIOS_BoardType_ProcessorMemory_Module,
  SMBIOS_BoardType_Interconnect_Board,
}SMBIOS_BoardTypes_t;


/*
 * Display Device Data Block
 *
 */
typedef struct LFPDataBlock_s{
    BlockIdHdr_t  cHdr       ; /* 0x00 Block Header */
    uint8_t	  Interface  ; /* 0x03 Display Interface */
#	define 	  EEEP_DISP_INT_LVDS  EEEP_UINT8_C(0x02)
#	define 	  EEEP_DISP_INT_SDVOB EEEP_UINT8_C(0x03)
#	define 	  EEEP_DISP_INT_SDVOC EEEP_UINT8_C(0x04)
#	define 	  EEEP_DISP_INT_DDI1	 EEEP_UINT8_C(0x05)
#	define 	  EEEP_DISP_INT_DDI2	 EEEP_UINT8_C(0x06)
#	define 	  EEEP_DISP_INT_DDI3	 EEEP_UINT8_C(0x07)
    uint8_t	  RawData[1]; /* 0x04 Display Raw Data
			       *      DisplayID
			       *      EDID
			       *      UDS
			       *      EPI
    			       */
}LFPDataBlock_t;

/*
 * Vendor Specific Block Header
 *
 */
typedef struct VendBlockHdr_s{
    BlockIdHdr_t  cHdr       ; /* 0x00 Block Header */
    uint8_t       VendId[2]  ; /* 0x03 Compressed PNPID  */
    /* After This Point is only 
     * Suggested
     */
    //uint8_t       VendBlockId; /* 0x04 Vendor Specific Block Id  */
    //uint8_t       VendData[1]; /* 0x05 Vendor Data */
}VendBlockHdr_t;


/*
 * Descriptor for Additional EEPROMS
 *
 * I.E. For Chassis/System/Base Board EEPROMs
 */
typedef struct ExtI2CDeviceDesc_s{
    BlockIdHdr_t  cHdr         ; /* 0x00 Block Header */
    uint8_t       DeviceAddr[2]; /* 0x03 Encoded 7/10 Bit Device Address */
    uint8_t       DeviceBus    ; /* 0x05 Device Bus       */
#	define 	  EEEP_I2CBuSID_I2C	   EEEP_UINT8_C(0x00)
#	define 	  EEEP_I2CBuSID_SMB	   EEEP_UINT8_C(0x01)
#	define 	  EEEP_I2CBuSID_LVDS   EEEP_UINT8_C(0x02)
#	define 	  EEEP_I2CBuSID_DDI1	 EEEP_UINT8_C(0x03)
#	define 	  EEEP_I2CBuSID_DDI2	 EEEP_UINT8_C(0x04)
#	define 	  EEEP_I2CBuSID_DDI3	 EEEP_UINT8_C(0x05)
    uint8_t       DeviceDesc   ; /* 0x06 Device Descriptor
                                * +========+========================+
                                * | Bits   | Description            |
                                * +========+========================+
                                * | 0 - 3  | Size 2^(8+n) Bytes     |
                                * |        | (256 << n) Bytes       |
                                * |        |                        |
                                * |        | Addressable Bytes      |
                                * |        |   Standard Index       |
                                * |        |     8bit - 11Bit       |
                                * |        |   Extended Index       |
                                * |        |     16bit - 19Bit      |
                                * |        | 2048 KBit - 4096 MBit  |
                                * |        | 256 Bytes - 512 KBytes |
                                * |        |                        |
                                * +--------+------------------------+
                                * | 4      | Std/Ext Index          |
                                * +--------+------------------------+
                                * | 5 - 7  | Reserved               |
                                * +========+========================+
                                */
#   define EEEP_ExtEEP_EXT_INDX EEEP_UINT8_C(1<<4)
}ExtI2CDeviceDesc_t;


/*
 * Platform Specific Headers
 *
 */
#include "COM0EEP.h"


#pragma pack(pop)   // n = 2 , stack popped

/*
 * CPU Independent Multi Byte 
 * Big Endian Memory Access
 */
void
EeeP_Set16BitValue_BE(
    uint8_t  pBuffer,
    uint16_t Value
     )
{
  pBuffer[1]=(Value   )&0xFF;
  pBuffer[0]=(Value>>8)&0xFF;
}
uint16_t
EeeP_Get16BitValue_BE(
    uint8_t  pBuffer
     )
{
  return (pBuffer[1]    ) |
         (pBuffer[0]<< 8) ;
}
EeeP_Set32BitValue_BE(
    uint8_t  pBuffer,
    uint32_t Value
     )
{
  pBuffer[3]=(Value    )&0xFF;
  pBuffer[2]=(Value>> 8)&0xFF;
  pBuffer[1]=(Value>>16)&0xFF;
  pBuffer[0]=(Value>>24)&0xFF;
}
uint32_t
EeeP_Get32BitValue_BE(
    uint8_t  pBuffer
     )
{
  return (pBuffer[3]    ) |
         (pBuffer[2]<< 8) |
         (pBuffer[1]<<16) |
         (pBuffer[0]<<24) ;
}
/*
 * CPU Independent Multi Byte 
 * Little Endian Memory Access
 */
void
EeeP_Set16BitValue_LE(
    uint8_t  pBuffer,
    uint16_t Value
     )
{
  pBuffer[0]=(Value   )&0xFF;
  pBuffer[1]=(Value>>8)&0xFF;
}
uint16_t
EeeP_Get16BitValue_LE(
    uint8_t  pBuffer
     )
{
  return (pBuffer[0]    ) |
         (pBuffer[1]<< 8) ;
}
EeeP_Set32BitValue_LE(
    uint8_t  pBuffer,
    uint32_t Value
     )
{
  pBuffer[0]=(Value    )&0xFF;
  pBuffer[1]=(Value>> 8)&0xFF;
  pBuffer[2]=(Value>>16)&0xFF;
  pBuffer[3]=(Value>>24)&0xFF;
}
uint32_t
EeeP_Get32BitValue_LE(
    uint8_t  pBuffer
     )
{
  return (pBuffer[0]    ) |
         (pBuffer[1]<< 8) |
         (pBuffer[2]<<16) |
         (pBuffer[3]<<24) ;
}


#endif /* __EEEP_H__ */
