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
 *I Description: COM0 R2.0 Specific Structures and Data
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : COM0EEP.h
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
#ifndef __COM0EEP_H__    
#define __COM0EEP_H__

/* COM0 R2.0 Standard Revision */
#define COM0R20_VER      2
#define COM0R20_REVISION 0
#define COM0R20_VERSION EEEP_VER_CREATE(COM0R20_VER, COM0R20_REVISION)


/*
 * COM R2.0
 * Backplane EEPROM Header
 *
 */
typedef struct COM0R20_BP_s{
    StdEep_t    EepHdr   ; /* 0x00 EEprom Id         */
    uint8_t     BPType   ; /* 0x0C Backplane Type    */
    uint8_t     SpecRev  ; /* 0x0D COM0 Specification Revision
                            *      
                            *      +=======+==================+
                            *      | Bits  | Descriptions     |
                            *      +=======+==================+
                            *      | 0 - 3 | Revision         |
                            *      +-------+------------------+
                            *      | 4 - 7 | Version          |
                            *      +=======+==================+
                            */
    uint8_t     UsbDesc  ; /* 0x0E Bit Mask Macros for 
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
#       define COM0R20_USB3_PCNT_MASK        EEEP_UINT8_C(0x07)
#       define COM0R20_USB3_PCNT_OFFSET      EEEP_UINT8_C(0x04)
#       define COM0R20_USB_PCNT_MASK         EEEP_UINT8_C(0x0F)
#       define COM0R20_USB_PCNT_OFFSET       EEEP_UINT8_C(0x00)

    uint8_t     SasDesc;   /* 0x0F BitMask Macros for 
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
                            *      |       | | 2      | Implemented        | |
                            *      |       | +--------+--------------------+ |
                            *      |       | | 3      | 0 SATA Device      | |
                            *      |       | |        | 1 SAS  Device      | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | 4 - 5 | SATA / SAS Channel 2            |
                            *      |       |                                 |
                            *      |       | +========+====================+ |
                            *      |       | | Bit    | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 4      | Implemented        | |
                            *      |       | +--------+--------------------+ |
                            *      |       | | 5      | 0 SATA Device      | |
                            *      |       | |        | 1 SAS  Device      | |
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | 6 - 7 | SATA / SAS Channel 3            |
                            *      |       |                                 |
                            *      |       | +========+====================+ |
                            *      |       | | Bit    | Description        | |
                            *      |       | +========+====================+ |
                            *      |       | | 6      | Implemented        | |
                            *      |       | +--------+--------------------+ |
                            *      |       | | 7      | 0 SATA Device      | |
                            *      |       | |        | 1 SAS  Device      | |
                            *      |       | +========+====================+ |
                            *      +=======+=================================+
                            */     

#       define COM0R20_SAS_CONNECTOR_PRESENT EEEP_UINT8_C(1<<0)
#       define COM0R20_SATA_SAS_DEVICE       EEEP_UINT8_C(1<<1)

#       define COM0R20_SAS_CHANNEL_0         EEEP_UINT8_C(0)
#       define COM0R20_SAS_CHANNEL_1         EEEP_UINT8_C(2)
#       define COM0R20_SAS_CHANNEL_2         EEEP_UINT8_C(4)
#       define COM0R20_SAS_CHANNEL_3         EEEP_UINT8_C(6)

    uint8_t     LanDesc;   /* 0x10 BitMask Macros for 
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
#       define COM0R20_GBE0_PRESENT          EEEP_UINT8_C(1<<0)
#       define COM0R20_GBE1_PRESENT          EEEP_UINT8_C(1<<1)
#       define COM0R20_GBE2_PRESENT          EEEP_UINT8_C(1<<2)
#       define COM0R20_GB1E0_PRESENT         EEEP_UINT8_C(1<<3)

    uint8_t     MiscIo1;   /* 0x11 BitMask Macros for 
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
#       define COM0R20_WAKE0_PRESENT        EEEP_UINT8_C(1<<0)
#       define COM0R20_WAKE1_PRESENT        EEEP_UINT8_C(1<<1)
#       define COM0R20_SUS_PRESENT          EEEP_UINT8_C(1<<2)
#       define COM0R20_BATLOW_PRESENT       EEEP_UINT8_C(1<<3)
#       define COM0R20_THRMP_PRESENT        EEEP_UINT8_C(1<<4)
#       define COM0R20_EBROM_PRESENT        EEEP_UINT8_C(1<<5)
#       define COM0R20_WDT_PRESENT          EEEP_UINT8_C(1<<6)
#       define COM0R20_AC97_PRESENT         EEEP_UINT8_C(1<<7)

    uint8_t     MiscIo2;   /* 0x12 BitMask Macros for 
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
#       define COM0R20_SSC_PRESENT          EEEP_UINT8_C(1<<0)
#       define COM0R20_SDIO_PRESENT         EEEP_UINT8_C(1<<1)
    uint8_t     DDIDesc;   /* 0x13 BitMask Macros for 
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
                            *      |       | +========+====================+ |
                            *      +-------+---------------------------------+
                            *      | 5     | Reserved                        |
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
#       define COM0R20_DDI_NOT_USED          EEEP_UINT8_C(0x0)
#       define COM0R20_DDI_eDispPort         EEEP_UINT8_C(0x1)
#       define COM0R20_DDI_DispPort          EEEP_UINT8_C(0x2)
#       define COM0R20_DDI_HDMI              EEEP_UINT8_C(0x3)
#       define COM0R20_DDI_SDVO              EEEP_UINT8_C(0x4)
#       define COM0R20_DDI_BITMASK           EEEP_UINT8_C(0x3)

#       define COM0R20_DDI1_OFFSET           EEEP_UINT8_C(0x0)
#       define COM0R20_DDI2_OFFSET           EEEP_UINT8_C(0x3)
#       define COM0R20_DDI3_OFFSET           EEEP_UINT8_C(0x6)
     uint8_t     Reserved0; /* 0x14 */
     uint8_t     Reserved1; /* 0x15 */
#       define COM0R20_VGA_PRESENT           EEEP_UINT8_C(1<<4)
#       define COM0R20_LVDSCB_PRESENT        EEEP_UINT8_C(1<<3)
#       define COM0R20_LVDSCA_PRESENT        EEEP_UINT8_C(1<<2)
#       define COM0R20_SDVOCC_PRESENT        EEEP_UINT8_C(1<<1)
#       define COM0R20_SDVOCB_PRESENT        EEEP_UINT8_C(1<<0)

    uint8_t    LaneMap[16];/* 0x16 +=======+=================================+
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
    uint8_t     MType    ; /* 0x0C Module Type        */
    uint8_t     SpecRev  ; /* 0x0D 
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

#define COM0R20_BLOCK_ID_EXP_CARD_DESC     EEEP_UINT8_C(0xE0)


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
#       define COM0R20_EXPCARD_MAP_EOL EEEP_UINT8_C(0x7F)
}ExpCardBlock_t;




#endif /* __COM0EEP_H__ */

