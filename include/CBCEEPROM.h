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
 *I Description: Auto Created for CBCEEPROM.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : CBCEEPROM.h
 *I  File Location        : include
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
/* Structures for COM0 CBCEEP */
#ifndef _CBCEEPROM_H_    
#define _CBCEEPROM_H_

typedef union LaneDescData_u{
  uint32_t D[1]
  uint16_t W[2]
  uint8_t  B[4]
  struct LaneDescData_s{
    uint8_t  LinkSLN        ; /* 0x00 Descriptor bits 7..0 
                               *      describe the starting 
                               *      lane number of the link. 
                               */
    uint8_t  LinkWidth      ; /* 0x01 Descriptor bits 15..8 
                               *      describe the width of the PCI
                               *      Express link.
                               */
    uint16_t LinkAttribute  ; /* 0x02 Bit 31 
                               *      0: Gen 1 PCI Express link; 
                               *      1: Gen 2 PCI Express link
                               */
  }S;
}LaneDescData_t;

typedef union CBCEepromLayout_u{
  uint32_t D[0x100/sizeof(uint32_t)];
  uint16_t W[0x100/sizeof(uint16_t)];
  uint8_t  B[0x100/sizeof(uint8_t)];
  struct CBCEepromLayout_s{
    LaneDescData_t LDD[32]               ; /* 0x00 */       
    uint8_t        Reserved1[0xD6 - 0x80]; /* 0x80 Reserved */
    uint8_t        DDIDesc               ; /* 0xD6 Digital Display Interface Descriptor Byte */
    uint8_t        MiscIo2               ; /* 0xD7 Miscellaneous I/O Descriptor Byte 2 */
    uint8_t        MiscIo1               ; /* 0xD8 Miscellaneous I/O Descriptor Byte 1 */
    uint8_t        LanDesc               ; /* 0xD9 LAN Descriptor Byte */
    uint8_t        DispDesc              ; /* 0xDA Display Descriptor Byte */
    uint8_t        UsbDesc               ; /* 0xDB USB Descriptor Byte */
    uint8_t        ExpCardDesc0          ; /* 0xDC Express Card 0 Descriptor Byte */
    uint8_t        ExpCardDesc1          ; /* 0xDD Express Card 1 Descriptor Byte */
    uint8_t        SasDevDesc            ; /* 0xDE SAS Device Descriptor Byte */
    uint8_t        FruRevision           ; /* 0xDF FRU Revision: fill with 01 for R2.0 */
    uint8_t        Identifier[0x10]      ; /* 0xE0 ASCII ID string: "COMExpressConfig" */
    uint8_t        Reserved2[0xFE - 0xF0]; /* 0xF0 Reserved */
    uint8_t        Checksum              ; /* 0xFE Unsigned 16 bit checksum over the 
                                            * unsigned bytes at addresses 
                                            * 0x00 through 0xFD
                                            */
  }S;
}CBCEepromLayout_t;
/*
 * BitMask Macros for 
 * SATA / SAS Device Descriptor Byte
 */
#define SAS_CONNECTOR_PRESENT (1<<0)
#define SAS_DEVICE            (1<<1)
/*
 * BitMask Macros for 
 * Express Card Descriptor Byte
 */
#define EXPC_PRESENT          (1<<7)
#define EXPC_PMAP_MASK        0x7
#define EXPC_PMAP_OFFSET      4
#define EXPC_ELANE_MASK       0x7
#define EXPC_ELANE_OFFSET     0
/*
 * BitMask Macros for 
 * USB Descriptor Byte
 */
#define USB3_PCNT_MASK        0x7
#define USB3_PCNT_OFFSET      0x4
#define USB_PCNT_MASK         0xF
#define USB_PCNT_OFFSET       0x0
/*
 * BitMask Macros for 
 * Display Descriptor Byte
 */
#define VGA_PRESENT           (1<<4)
#define LVDSCB_PRESENT        (1<<3)
#define LVDSCA_PRESENT        (1<<2)
#define SDVOCC_PRESENT        (1<<1)
#define SDVOCB_PRESENT        (1<<0)
/*
 * BitMask Macros for 
 * Digital Display Interface Descriptor Byte
 */
#define DDI_NOT_USED          (0x0)
#define DDI_SDVO              (0x1)
#define DDI_DispPort          (0x2)
#define DDI_HDMI              (0x3)
#define DDI_BITMASK           (0x3)
#define DDI1_OFFSET           (0x0)
#define DDI2_OFFSET           (0x3)
#define DDI3_OFFSET           (0x6)
/*
 * BitMask Macros for 
 * LAN Descriptor Byte
 */
#define GBE0_PRESENT        (1<<0)
#define GBE1_PRESENT        (1<<1)
#define GBE2_PRESENT        (1<<2)
#define GB1E0_PRESENT       (1<<3)
/*
 * BitMask Macros for 
 * Miscellaneous I/O Descriptor Byte 1
 */
#define WAKE0_PRESENT        (1<<0)
#define WAKE1_PRESENT        (1<<1)
#define SUS_PRESENT          (1<<2)
#define BATLOW_PRESENT       (1<<3)
#define THRMP_PRESENT        (1<<4)
#define EBROM_PRESENT        (1<<5)
#define WDT_PRESENT          (1<<6)
#define AC97_PRESENT         (1<<7)
/*
 * BitMask Macros for 
 * Miscellaneous I/O Descriptor Byte 2
 */
#define SSC_PRESENT         (1<<0)
#define SDIO_PRESENT        (1<<1)
#endif /* _CBCEEPROM_H_ */

