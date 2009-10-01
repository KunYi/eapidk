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
 *I Description: Auto Created for STDEEP.h
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

/* Structures for COM0 STDEEP */
#ifndef _STDEEP_H_    
#define _STDEEP_H_

#ifndef COM0_UINT32_C
#  define COM0_UINT8_C(x)  ((uint8_t)(x))
#  define COM0_UINT16_C(x) ((uint16_t)(x))
#  define COM0_UINT32_C(x) ((uint32_t)(x))
#endif


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


#define COM0R20_VER_MASK_VER     COM0_UINT8_C(0xF0)
#define COM0R20_VER_MASK_REV     COM0_UINT8_C(0x0F)
#define COM0R20_VER_GET_VER(x)   COM0_UINT8_C (((x)>>4)&0x0F )
#define COM0R20_VER_GET_REV(x)   COM0_UINT8_C (((x)>>0)&0x0F )
#define COM0R20_VER_CREATE(Version,Revision) (\
                      COM0_UINT8_C(\
                        (((Version )&0x0F )<<4)|\
                        (((Revision)&0x0F )<<0) \
                      )\
                    )

/* COM0 R2.0 Standard Revision */
#define COM0R20_VER      0
#define COM0R20_REVISION 5
#define COM0R20_VERSION COM0R20_VER_CREATE(COM0R20_VER, COM0R20_REVISION)




/*
 * EEPROM Common Header
 *
 */
typedef struct StdEep_s{
    uint8_t     EepId[4] ; /* 0x00 COM0 */
#       define  COM0R20_R2_EEPROM_MARKER 0x304D4F43
    uint16_t    VendId   ; /* 0x04 Compressed PNPID            */
    uint16_t    DeviceId ; /* 0x06 Vendor Specific Device ID   */
    uint8_t     RevId    ; /* 0x08 Vendor Specific Revision ID */
    uint8_t     BlkOffset; /* 0x09 Absolute Offset to
                            *      First Block
                            */
}StdEep_t;


/*
 * COM R2.0
 * Backplane EEPROM Header
 *
 */
typedef struct COM0R20_BP_s{
    StdEep_t    EepHdr   ; /* 0x00 EEprom Id         */
    uint8_t     BPType   ; /* 0x0A Backplane Type    */
    uint8_t     SpecRev  ; /* 0x0B COM0 Specification Revision
                            *      
                            *      +=======+==================+
                            *      | Bits  | Descriptions     |
                            *      +=======+==================+
                            *      | 0 - 3 | Revision         |
                            *      +-------+------------------+
                            *      | 4 - 7 | Version          |
                            *      +=======+==================+
                            */
    uint8_t     UsbDesc  ; /* 0x0C Bit Mask Macros for 
                            *      USB Descriptor Byte
                            *      
                            *      +=======+===============================+
                            *      | Bits  | Descriptions                  |
                            *      +=======+===============================+
                            *      | 0 - 3 | Count of High Speed Ports     |
                            *      +-------+-------------------------------+
                            *      | 4 - 6 | Count of Super Speed Ports    |
                            *      +-------+-------------------------------+
                            *      | 7     | Reserved                      |
                            *      +=======+===============================+
                            */
#       define COM0R20_USB3_PCNT_MASK        COM0_UINT8_C(0x07)
#       define COM0R20_USB3_PCNT_OFFSET      COM0_UINT8_C(0x04)
#       define COM0R20_USB_PCNT_MASK         COM0_UINT8_C(0x0F)
#       define COM0R20_USB_PCNT_OFFSET       COM0_UINT8_C(0x00)

    uint8_t     SasDesc;   /* 0x0D BitMask Macros for 
                            *      LAN Descriptor Byte
                            *      
                            *      +=======+=================================+
                            *      | Bits  | Descriptions                    |
                            *      +=======+=================================+
                            *      | 0 - 1 | SATA / SAS Channel 0            |
                            *      |       |                                 |
                            *      |       | +========+====================+ |
                            *      |       | | Bit    | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Implemented        | |
                            *      |       | +--------+--------------------+ |
                            *      |       | | 1      | 0 SATA Device      | |
                            *      |       | |        | 1 SAS  Device      | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | 2 - 3 | SATA / SAS Channel 1            |
                            *      |       |                                 |
                            *      |       | +========+====================+ |
                            *      |       | | Bit    | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Implemented        | |
                            *      |       | +--------+--------------------+ |
                            *      |       | | 1      | 0 SATA Device      | |
                            *      |       | |        | 1 SAS  Device      | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | 4 - 5 | SATA / SAS Channel 2            |
                            *      |       |                                 |
                            *      |       | +========+====================+ |
                            *      |       | | Bit    | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Implemented        | |
                            *      |       | +--------+--------------------+ |
                            *      |       | | 1      | 0 SATA Device      | |
                            *      |       | |        | 1 SAS  Device      | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | 6 - 7 | SATA / SAS Channel 3            |
                            *      |       |                                 |
                            *      |       | +========+====================+ |
                            *      |       | | Bit    | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Implemented        | |
                            *      |       | +--------+--------------------+ |
                            *      |       | | 1      | 0 SATA Device      | |
                            *      |       | |        | 1 SAS  Device      | |
                            *      |       | +========+====================+ |
                            *      +=======+=================================+
                            */     

#       define COM0R20_SAS_CONNECTOR_PRESENT COM0_UINT8_C(1<<0)
#       define COM0R20_SATA_SAS_DEVICE       COM0_UINT8_C(1<<1)

#       define COM0R20_SAS_CHANNEL_0         COM0_UINT8_C(0)
#       define COM0R20_SAS_CHANNEL_1         COM0_UINT8_C(2)
#       define COM0R20_SAS_CHANNEL_2         COM0_UINT8_C(4)
#       define COM0R20_SAS_CHANNEL_3         COM0_UINT8_C(6)

    uint8_t     LanDesc;   /* 0x0E BitMask Macros for 
                            *      LAN Descriptor Byte
                            *      
                            *      +=======+===============================+
                            *      | Bits  | Descriptions                  |
                            *      +=======+===============================+
                            *      | 0     | GBE0 Implemented              |
                            *      +-------+-------------------------------+
                            *      | 1     | GBE1 Implemented              |
                            *      +-------+-------------------------------+
                            *      | 2     | GBE2 Implemented              |
                            *      +-------+-------------------------------+
                            *      | 3     | GB1E0 Implemented             |
                            *      +-------+-------------------------------+
                            *      | 4 - 7 | Reserved                      |
                            *      +=======+===============================+
                            */     
#       define COM0R20_GBE0_PRESENT          COM0_UINT8_C(1<<0)
#       define COM0R20_GBE1_PRESENT          COM0_UINT8_C(1<<1)
#       define COM0R20_GBE2_PRESENT          COM0_UINT8_C(1<<2)
#       define COM0R20_GB1E0_PRESENT         COM0_UINT8_C(1<<3)

    uint8_t     MiscIo1;   /* 0x0F BitMask Macros for 
                            *      Miscellaneous I/O Descriptor Byte 1
                            *      
                            *      +======+===============================+
                            *      | Bits | Descriptions                  |
                            *      +======+===============================+
                            *      | 0    | WAKE0 Implemented             |
                            *      +------+-------------------------------+
                            *      | 1    | WAKE1 Implemented             |
                            *      +------+-------------------------------+
                            *      | 2    | SUS Implemented               |
                            *      +------+-------------------------------+
                            *      | 3    | BATLOW Implemented            |
                            *      +------+-------------------------------+
                            *      | 4    | THRMP Implemented             |
                            *      +------+-------------------------------+
                            *      | 5    | EBROM Implemented             |
                            *      +------+-------------------------------+
                            *      | 6    | WDT Implemented               |
                            *      +------+-------------------------------+
                            *      | 7    | AC97 Implemented              |
                            *      +======+===============================+
                            */
#       define COM0R20_WAKE0_PRESENT        COM0_UINT8_C(1<<0)
#       define COM0R20_WAKE1_PRESENT        COM0_UINT8_C(1<<1)
#       define COM0R20_SUS_PRESENT          COM0_UINT8_C(1<<2)
#       define COM0R20_BATLOW_PRESENT       COM0_UINT8_C(1<<3)
#       define COM0R20_THRMP_PRESENT        COM0_UINT8_C(1<<4)
#       define COM0R20_EBROM_PRESENT        COM0_UINT8_C(1<<5)
#       define COM0R20_WDT_PRESENT          COM0_UINT8_C(1<<6)
#       define COM0R20_AC97_PRESENT         COM0_UINT8_C(1<<7)

    uint8_t     MiscIo2;   /* 0x10 BitMask Macros for 
                            *      Miscellaneous I/O Descriptor Byte 2
                            *      
                            *      +=======+===============================+
                            *      | Bits  | Descriptions                  |
                            *      +=======+===============================+
                            *      | 0     | SSC Present                   |
                            *      +-------+-------------------------------+
                            *      | 1     | SDIO Present                  |
                            *      +-------+-------------------------------+
                            *      | 2 - 7 | Reserved                      |
                            *      +=======+===============================+
                            */     
#       define COM0R20_SSC_PRESENT          COM0_UINT8_C(1<<0)
#       define COM0R20_SDIO_PRESENT         COM0_UINT8_C(1<<1)
    uint8_t     DDIDesc;   /* 0x11 BitMask Macros for 
                            *      Digital Display Interface Descriptor Byte
                            *      
                            *      +=======+=================================+
                            *      | Bits  | Description                     |
                            *      +=======+=================================+
                            *      | 0 - 2 | DDI Port 1                      |
                            *      |       |                                 |
                            *      |       | +========+====================+ |
                            *      |       | | Value  | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Unused             | |
                            *      |       | | 1      | eDisplay Port      | |
                            *      |       | | 2      | Display Port       | |
                            *      |       | | 3      | HDMI/DVI           | |
                            *      |       | | 4      | SDVO               | |
                            *      |       | | 5-7    | Reserved           | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | 3 - 5 | DDI Port 2                      |
                            *      |       |                                 |
                            *      |       | +========+====================+ |
                            *      |       | | Value  | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Unused             | |
                            *      |       | | 1      | eDisplay Port      | |
                            *      |       | | 2      | Display Port       | |
                            *      |       | | 3      | HDMI/DVI           | |
                            *      |       | | 4-7    | Reserved           | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | 6 - 7 | DDI Port 3                      |
                            *      |       |                                 |
                            *      |       | +========+====================+ |
                            *      |       | | Value  | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Unused             | |
                            *      |       | | 1      | eDisplay Port      | |
                            *      |       | | 2      | Display Port       | |
                            *      |       | | 3      | HDMI/DVI           | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            */     
#       define COM0R20_DDI_NOT_USED          COM0_UINT8_C(0x0)
#       define COM0R20_DDI_eDispPort         COM0_UINT8_C(0x1)
#       define COM0R20_DDI_DispPort          COM0_UINT8_C(0x2)
#       define COM0R20_DDI_HDMI              COM0_UINT8_C(0x3)
#       define COM0R20_DDI_SDVO              COM0_UINT8_C(0x4)
#       define COM0R20_DDI_BITMASK           COM0_UINT8_C(0x3)

#       define COM0R20_DDI1_OFFSET           COM0_UINT8_C(0x0)
#       define COM0R20_DDI2_OFFSET           COM0_UINT8_C(0x3)
#       define COM0R20_DDI3_OFFSET           COM0_UINT8_C(0x6)
     uint8_t     Reserved0; /* 0x12 */
     uint8_t     Reserved1; /* 0x13 */
/*     uint8_t     DispDesc;/* 0x12 BitMask Macros for 
                            *      Display Descriptor Byte
                            *      
                            *      +=======+===============================+
                            *      | Bits  | Descriptions                  |
                            *      +=======+===============================+
                            *      | 0     | SDVO B Present                |
                            *      +-------+-------------------------------+
                            *      | 1     | SDVO C Present                |
                            *      +-------+-------------------------------+
                            *      | 2     | LVDS A Present                |
                            *      +-------+-------------------------------+
                            *      | 3     | LVDS B Present                |
                            *      +-------+-------------------------------+
                            *      | 4     | VGA Present                   |
                            *      +-------+-------------------------------+
                            *      | 5 - 7 | Reserved                      |
                            *      +=======+===============================+
                            */
#       define COM0R20_VGA_PRESENT           COM0_UINT8_C(1<<4)
#       define COM0R20_LVDSCB_PRESENT        COM0_UINT8_C(1<<3)
#       define COM0R20_LVDSCA_PRESENT        COM0_UINT8_C(1<<2)
#       define COM0R20_SDVOCC_PRESENT        COM0_UINT8_C(1<<1)
#       define COM0R20_SDVOCB_PRESENT        COM0_UINT8_C(1<<0)

    uint8_t    LaneMap[16];/* 0x14 +=======+=================================+
                            *      | Bits  | Description                     |
                            *      +=======+=================================+
                            *      | Lane 0                                  |
                            *      +-------+---------------------------------+
                            *      | 0 - 2 | +========+====================+ |
                            *      |       | | Value  | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Unused             | |
                            *      |       | | 1      | 1  Lane            | |
                            *      |       | | 2      | 2  Lanes           | |
                            *      |       | | 3      | 4  Lanes           | |
                            *      |       | | 4      | 8  Lanes           | |
                            *      |       | | 5      | 16 Lanes           | |
                            *      |       | | 6      | 32 Lanes           | |
                            *      |       | | 7      | Reserved           | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | 3     | +========+====================+ |
                            *      |       | | Value  | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Gen 1              | |
                            *      |       | | 1      | Gen 2              | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | Lane 1                                  |
                            *      +-------+---------------------------------+
                            *      | 4 - 6 | +========+====================+ |
                            *      |       | | Value  | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Unused             | |
                            *      |       | | 1      | 1  Lane            | |
                            *      |       | | 2      | 2  Lanes           | |
                            *      |       | | 3      | 4  Lanes           | |
                            *      |       | | 4      | 8  Lanes           | |
                            *      |       | | 5      | 16 Lanes           | |
                            *      |       | | 6      | 32 Lanes           | |
                            *      |       | | 7      | Reserved           | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | 7     | +========+====================+ |
                            *      |       | | Value  | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 0      | Gen 1              | |
                            *      |       | | 1      | Gen 2              | |
                            *      |       | +========+====================+ |
                            *      +=======+=================================+
                            */
}COM0R20_BP_t;
/* 
 * Pci Express Lane Mapping 
 *
 * Example 1
 * Standard Type 2
 * 6 x1
 * 1 x16
 * +======+=======+==================+
 * | Byte | Value | Description      |
 * +======+=======+==================+
 * | 00   | 11    | x1 Lane 00 & 01  |
 * | 01   | 11    | x1 Lane 02 & 03  |
 * | 02   | 11    | x1 Lane 04 & 05  |
 * | 03   | 00    | Unused           |
 * | 04   | 00    | Unused           |
 * | 05   | 00    | Unused           |
 * | 06   | 00    | Unused           |
 * | 07   | 00    | Unused           |
 * | 08   | 55    | x16 Lane 16 - 31 |
 * | 09   | 55    | x16 Lane 16 - 31 |
 * | 10   | 55    | x16 Lane 16 - 31 |
 * | 11   | 55    | x16 Lane 16 - 31 |
 * | 12   | 55    | x16 Lane 16 - 31 |
 * | 13   | 55    | x16 Lane 16 - 31 |
 * | 12   | 55    | x16 Lane 16 - 31 |
 * | 14   | 55    | x16 Lane 16 - 31 |
 * | 15   | 55    | x16 Lane 16 - 31 |
 * +======+=======+==================+
 *
 * Example 2
 * Type 2
 * 1 x4
 * 2 x1
 * 1 x16
 * +======+=======+==================+
 * | Byte | Value | Description      |
 * +======+=======+==================+
 * | 00   | 33    | x4 Lane 00 - 03  |
 * | 01   | 33    | x4 Lane 00 - 03  |
 * | 02   | 11    | x1 Lane 04 & 05  |
 * | 03   | 00    | Unused           |
 * | 04   | 00    | Unused           |
 * | 05   | 00    | Unused           |
 * | 06   | 00    | Unused           |
 * | 07   | 00    | Unused           |
 * | 08   | 55    | x16 Lane 16 - 31 |
 * | 09   | 55    | x16 Lane 16 - 31 |
 * | 10   | 55    | x16 Lane 16 - 31 |
 * | 11   | 55    | x16 Lane 16 - 31 |
 * | 12   | 55    | x16 Lane 16 - 31 |
 * | 13   | 55    | x16 Lane 16 - 31 |
 * | 12   | 55    | x16 Lane 16 - 31 |
 * | 14   | 55    | x16 Lane 16 - 31 |
 * | 15   | 55    | x16 Lane 16 - 31 |
 * +======+=======+==================+
 *
 * Example 3
 * Type 2
 * 2 x2
 * 2 x1
 * 4 x4
 * +======+=======+==================+
 * | Byte | Value | Description      |
 * +======+=======+==================+
 * | 00   | 22    | x2 Lane 00 - 01  |
 * | 01   | 11    | x1 Lane 02 & 03  |
 * | 02   | 00    | Unused           |
 * | 03   | 00    | Unused           |
 * | 04   | 00    | Unused           |
 * | 05   | 00    | Unused           |
 * | 06   | 00    | Unused           |
 * | 07   | 00    | Unused           |
 * | 08   | 33    | x4  Lane 16 - 19 |
 * | 09   | 33    | x4  Lane 16 - 19 |
 * | 10   | 33    | x4  Lane 20 - 23 |
 * | 11   | 33    | x4  Lane 20 - 23 |
 * | 12   | 33    | x4  Lane 24 - 27 |
 * | 13   | 33    | x4  Lane 24 - 27 |
 * | 14   | 33    | x4  Lane 28 - 31 |
 * | 15   | 33    | x4  Lane 28 - 31 |
 * +======+=======+==================+
 *
 */

/*
 * COM R2.0
 * Module EEPROM Header
 *
 */
typedef struct COM0R20_M_s{
    StdEep_t    EepHdr   ; /* 0x00 EEprom Id          */
    uint8_t     MType    ; /* 0x0A Module Type        */
    uint8_t     SpecRev  ; /* 0x0B 
                            *      +=======+==================+
                            *      | Bits  | Descriptions     |
                            *      +=======+==================+
                            *      | 0 - 3 | Revision         |
                            *      +-------+------------------+
                            *      | 4 - 7 | Version          |
                            *      +=======+==================+
                            */
   /*
    * Module Fixed Offset Information
    * 
    */
}COM0R20_M_t;

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
    uint8_t     BlockId    ; /* 0x00 Block Id       */
    uint16_t    BlockLength; /* 0x01 Block Length   */
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
#define COM0R20_BLOCK_ID_UNUSED            COM0_UINT8_C(0x00)
#define COM0R20_BLOCK_ID_VENDOR_SPECIFIC   COM0_UINT8_C(0xF0)
#define COM0R20_BLOCK_ID_EXP_EEPROM        COM0_UINT8_C(0xF1)
#define COM0R20_BLOCK_ID_EXP_CARD_DESC     COM0_UINT8_C(0xE0)
#define COM0R20_BLOCK_ID_SYSTEM_DESC       COM0_UINT8_C(0xD1)
#define COM0R20_BLOCK_ID_MODULE_DESC       COM0_UINT8_C(0xD2)
#define COM0R20_BLOCK_ID_CHASSIS_DESC      COM0_UINT8_C(0xD3)
#define COM0R20_BLOCK_ID_CRC_CHK           COM0_UINT8_C(0xF2)
#define COM0R20_BLOCK_ID_STD_SPECIFIC      COM0_UINT8_C(0xC0)
#define COM0R20_BLOCK_ID_IGNORE            COM0_UINT8_C(0xFF)

#define COM0R20_OFFSET_VALUE_EOL           COM0_UINT16_C(0x0000)
#define COM0R20_OFFSET_VALUE_EOL_ALT       COM0_UINT16_C(0xFFFF)

/*
 * CRC Checksum Block
 *
 */
typedef struct CRC16ChkBlock_s{
    BlockIdHdr_t  cHdr          ; /* 0x00 Block Header */
    uint16_t      CrC16         ; /* 0x03 CRC16 Checksum */
}CRC16ChkBlock_t;

/*
 * Express Card Slot Descriptor
 *
 */
typedef struct ExpCardBlock_s{
    BlockIdHdr_t  cHdr          ; /* 0x00 Block Header */
    uint8_t ExpressCardNumber   ; /* 0x03 0 - 1 */
    uint8_t ComExpressPort      ; /* 0x04 0 - 31 
                                   *      +=======+==================+
                                   *      | Bits  | Descriptions     |
                                   *      +=======+==================+
                                   *      | 0 - 4 | PCI Express Port |
                                   *      |       | Mapping.         |
                                   *      |       | Port Starting    |
                                   *      |       | Lane.            |
                                   *      |       | 0 - 31           |
                                   *      +-------+------------------+
                                   *      | 5 - 7 | USB Port Mapping |
                                   *      |       | 0 - 7            |
                                   *      +=======+==================+
                                   */
    uint8_t SwitchPortNumber[1] ; /* 0x05 An Array of
                                   *      Port/Device
                                   *      numbers Terminated
                                   *      with 0x7F
                                   */
#       define COM0R20_EXPCARD_MAP_EOL COM0_UINT8_C(0x7F)
}ExpCardBlock_t;


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
#       define SMBIOS_IS_Motherboard  COM0_UINT8_C(1 << 0)
#       define SMBIOS_REQ_DAUGHTER    COM0_UINT8_C(1 << 1)
#       define SMBIOS_REMOVABLE       COM0_UINT8_C(1 << 2)
#       define SMBIOS_REPLACEABLE     COM0_UINT8_C(1 << 3)
#       define SMBIOS_HOT_SWAP_CAP    COM0_UINT8_C(1 << 4)
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
 * Vendor Specific Block Header
 *
 */
typedef struct VendBlockHdr_s{
    BlockIdHdr_t  cHdr       ; /* 0x00 Block Header */
    uint16_t      VendId     ; /* 0x03 Compressed PNPID  */
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
    BlockIdHdr_t  cHdr       ; /* 0x00 Block Header */
    uint16_t      DeviceAddr ; /* 0x03 Encoded 7/10 Bit Device Address */
    uint8_t       DeviceDesc ; /* 0x05 Device Descriptor
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
#   define COM0R20_ExtEEP_EXT_INDX COM0_UINT8_C(1<<4)
}ExtI2CDeviceDesc_t;



#endif /* _STDEEP_H_ */

