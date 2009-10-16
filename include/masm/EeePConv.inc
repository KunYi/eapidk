
option expr32
option casemap:none

; Begin of file include\masm\EeePConv.h
; 
;  *<KHeader>
;  *+=========================================================================
;  *I               EApiDK Embedded Application Development Kit
;  *+=========================================================================
;  *I  $HeadURL$
;  *+=========================================================================
;  *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
;  *I      Author: John Kearney,                  John.Kearney@kontron.com
;  *I
;  *I     License: All rights reserved. This program and the accompanying 
;  *I              materials are licensed and made available under the 
;  *I              terms and conditions of the BSD License which 
;  *I              accompanies this distribution. The full text of the 
;  *I              license may be found at 
;  *I              http://opensource.org/licenses/bsd-license.php
;  *I              
;  *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
;  *I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
;  *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
;  *I
;  *I Description: Auto Created for EApiConv.h
;  *I
;  *+------------------------------------------------------------------------=
;  *I
;  *I  File Name            : EApiConv.h
;  *I  File Location        : includemasm
;  *I  Last committed       : $Revision$
;  *I  Last changed by      : $Author$
;  *I  Last changed date    : $Date$
;  *I  ID                   : $Id$
;  *I
;  *+=========================================================================
;  *</KHeader>
;  
; Begin of file include\masm\h2inc.h
; 
;  *<KHeader>
;  *+=========================================================================
;  *I               EApiDK Embedded Application Development Kit
;  *+=========================================================================
;  *I  $HeadURL$
;  *+=========================================================================
;  *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
;  *I      Author: John Kearney,                  John.Kearney@kontron.com
;  *I
;  *I     License: All rights reserved. This program and the accompanying 
;  *I              materials are licensed and made available under the 
;  *I              terms and conditions of the BSD License which 
;  *I              accompanies this distribution. The full text of the 
;  *I              license may be found at 
;  *I              http://opensource.org/licenses/bsd-license.php
;  *I              
;  *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
;  *I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
;  *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
;  *I
;  *I Description: Auto Created for EApiConv.h
;  *I
;  *+------------------------------------------------------------------------=
;  *I
;  *I  File Name            : EApiConv.h
;  *I  File Location        : includemasm
;  *I  Last committed       : $Revision$
;  *I  Last changed by      : $Author$
;  *I  Last changed date    : $Date$
;  *I  ID                   : $Id$
;  *I
;  *+=========================================================================
;  *</KHeader>
;  
; 
;  * Conversion File to allow easier Conversion using h2inc
;  * h2inc /C /WIN32 /Zu /Ht /FaincludemasmEApiConv.inc includemasmEApiConv.h
;  * Please note this settings are only for valid for WIN32
;  
; 
;  *  Necessary to do change 
;  *  uint64_t		TYPEDEF		DWORD
;  *  int64_t		  TYPEDEF		SDWORD
;  *  to
;  *  uint64_t		TYPEDEF		QWORD
;  *  int64_t		  TYPEDEF		QWORD
;  *
;  *  h2inc doesn't recognise unsigned long long
;  *
;  * Masm doesn't support SQWORD
;  
uint64_t		TYPEDEF		DWORD

; typedef   signed long   int64_t;
uint32_t		TYPEDEF		DWORD

int32_t		TYPEDEF		SDWORD

uint16_t		TYPEDEF		WORD

int16_t		TYPEDEF		SWORD

uint8_t		TYPEDEF		BYTE

int8_t		TYPEDEF		SBYTE

size_t		TYPEDEF		int32_t

wchar_t		TYPEDEF		uint16_t

EEEP_INT32_C		TEXTEQU		<>
EEEP_INT16_C		TEXTEQU		<>
EEEP_INT8_C		TEXTEQU		<>
EEEP_UINT32_C		TEXTEQU		<>
EEEP_UINT16_C		TEXTEQU		<>
EEEP_UINT8_C		TEXTEQU		<>
EAPI_INT32_C		TEXTEQU		<>
EAPI_INT16_C		TEXTEQU		<>
EAPI_INT8_C		TEXTEQU		<>
EAPI_UINT32_C		TEXTEQU		<>
EAPI_UINT16_C		TEXTEQU		<>
EAPI_UINT8_C		TEXTEQU		<>
__IN		TEXTEQU		<>
__OUT		TEXTEQU		<>
__INOPT		TEXTEQU		<>
__INOUT		TEXTEQU		<>
__OUTOPT		TEXTEQU		<>
__INOUTOPT		TEXTEQU		<>
UINT8_MAX		EQU		0000000ffh
INT8_MAX		EQU		00000007fh
UINT16_MAX		EQU		00000ffffh
INT16_MAX		EQU		000007fffh
UINT32_MAX		EQU		0ffffffffh
INT32_MAX		EQU		07fffffffh
UINT64_MAX		EQU		0ffffffffh
INT64_MAX		EQU		0ffffffffh
; End of file include\masm\h2inc.h
; Begin of file include\masm\..\EeeP.h
; 
;  *<KHeader>
;  *+=========================================================================
;  *I               EApiDK Embedded Application Development Kit
;  *+=========================================================================
;  *I  $HeadURL$
;  *+=========================================================================
;  *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
;  *I      Author: John Kearney,                  John.Kearney@kontron.com
;  *I
;  *I     License: All rights reserved. This program and the accompanying 
;  *I              materials are licensed and made available under the 
;  *I              terms and conditions of the BSD License which 
;  *I              accompanies this distribution. The full text of the 
;  *I              license may be found at 
;  *I              http://opensource.org/licenses/bsd-license.php
;  *I              
;  *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN 
;  *I              "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
;  *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
;  *I
;  *I Description: Embedded EEPROM
;  *I
;  *+------------------------------------------------------------------------=
;  *I
;  *I  File Name            : STDEEP.h
;  *I  File Location        : include
;  *I  Last committed       : $Revision$
;  *I  Last changed by      : $Author$
;  *I  Last changed date    : $Date$
;  *I  ID                   : $Id$
;  *I
;  *+=========================================================================
;  *</KHeader>
;  
;  Structures for Embedded EEPROM 
__EEEP_H__		TEXTEQU		<>
; #pragma pack(push)
;  
;  * Detecting COM0 R2.0 EEPROM
;  *
;  * High Level Check
;  * if(!memcmp(
;  *        &COM0EEP[0x00]            , 
;  *        "COM0"                    , 
;  *        0x04
;  *      )
;  *   )
;  * {
;  *    // Found COM0R20 EEPROM
;  * }
;  *
;  * Sample I2C Transfer
;  *  Device Address : 0xA8
;  *  Index Type     : Standard
;  *    Start<0xA8><W>Ack<0x00>Ack
;  *    Start<0xA8><R>Ack<'C'>Ack<'O'>Ack<'M'>Ack<'0'>Nak Stop
;  *  Device Address : 0xA8
;  *  Index Type     : Extended
;  *    Start<0xA8><W>Ack<0x00>Ack<0x00>Ack
;  *    Start<0xA8><R>Ack<'C'>Ack<'O'>Ack<'M'>Ack<'0'>Nak Stop
;  * 
;  
;  
;  * Detecting COM0 R1.0 EEPROM
;  *
;  * High Level Check
;  * if(!memcmp(
;  *        &COM0EEP[0xE0]            , 
;  *        "COMExpressConfig"        , 
;  *        0x10
;  *      )
;  *   )
;  * {
;  *    // Found COM0R10 EEPROM
;  * }
;  *
;  * Sample I2C Transfer
;  *  Device Address : 0xA8
;  *  Index Type     : Standard
;  *    Start<0xA8><W>Ack<0xE0>Ack 
;  *    Start<0xA8><R>Ack<'C'>Ack<'O'>Ack<'M'>Ack<'E'>Ack<'x'>Ack<'p'>Ack
;  *                     <'r'>Ack<'e'>Ack<'s'>Ack<'s'>Ack<'C'>Ack<'o'>Ack
;  *                     <'n'>Ack<'f'>Ack<'i'>Ack<'g'>Nak Stop                                              
;  * 
;  
EEEP_VER_MASK_VER		EQU		0000000f0h
EEEP_VER_MASK_REV		EQU		00000000fh
;  COM0 R2.0 Standard Revision 
EEEP_VER		EQU		0t
EEEP_REVISION		EQU		5t
EEEP_VERSION		EQU		000000005h
; 
;  * EEPROM Common Header
;  *
;  
;  0x00 COM0 
EEEP_R2_EEPROM_MARKER		EQU		0304d4f43h
;  0x04 Absolute Offset to
;                               *      First Block
;                               
;  0x05 Device Descriptor
;                               * +========+========================+
;                               * | Bits   | Description            |
;                               * +========+========================+
;                               * | 0 - 3  | Size 2^(8+n) Bytes     |
;                               * |        | (256 << n) Bytes       |
;                               * |        |                        |
;                               * |        | Addressable Bytes      |
;                               * |        |   Standard Index       |
;                               * |        |     8bit - 11Bit       |
;                               * |        |   Extended Index       |
;                               * |        |     16bit - 19Bit      |
;                               * |        | 2048 KBit - 4096 MBit  |
;                               * |        | 256 Bytes - 512 KBytes |
;                               * |        |                        |
;                               * +--------+------------------------+
;                               * | 4      | Std/Ext Index          |
;                               * +--------+------------------------+
;                               * | 5 - 7  | Reserved               |
;                               * +========+========================+
;                               
;  0x06 Compressed PNPID            
;  0x08 Vendor Specific Device ID   
;  0x0A 
;  0x0B Vendor Specific Revision ID 
@tag_StdEep_s		STRUCT 1t
EepId		uint8_t		4t DUP (?)
BlkOffset		uint8_t		?
DeviceDesc		uint8_t		?
VendId		uint8_t		2t DUP (?)
DeviceId		uint8_t		2t DUP (?)
DeviceFlav		uint8_t		?
RevId		uint8_t		?
@tag_StdEep_s		ENDS

StdEep_t		TYPEDEF		@tag_StdEep_s

; 
;  * COM R2.0
;  * Expansion EEPROM Header
;  *
;  
;  0x00 EEprom Id       
@tag_Exp_EEP_s		STRUCT 1t
EepHdr		StdEep_t		<>
@tag_Exp_EEP_s		ENDS

Exp_EEP_t		TYPEDEF		@tag_Exp_EEP_s

; 
;  * Block Common Header
;  *
;  
;  0x00 Block Id       
;  0x01 Block Length   
@tag_BlockIdHdr_s		STRUCT 1t
BlockId		uint8_t		?
BlockLength		uint8_t		2t DUP (?)
@tag_BlockIdHdr_s		ENDS

BlockIdHdr_t		TYPEDEF		@tag_BlockIdHdr_s

; 
;  *
;  *
;  *
;  * Block Types
;  *
;  *
;  *
;  
; 
;  * Block Ids
;  *
;  
EEEP_BLOCK_ID_UNUSED		EQU		000000000h
; 
;  * 0xC0 -0xCF See Platform Specific Headers
;  *
;  
EEEP_BLOCK_ID_VENDOR_SPECIFIC		EQU		0000000f0h
EEEP_BLOCK_ID_EXP_EEPROM		EQU		0000000f1h
; 
;  * 0xE0 -0xEF See Platform Specific Headers
;  *
;  
EEEP_BLOCK_ID_SYSTEM_DESC		EQU		0000000d1h
EEEP_BLOCK_ID_MODULE_DESC		EQU		0000000d2h
EEEP_BLOCK_ID_CHASSIS_DESC		EQU		0000000d3h
EEEP_BLOCK_ID_CRC_CHK		EQU		0000000f2h
EEEP_BLOCK_ID_IGNORE		EQU		0000000ffh
EEEP_OFFSET_VALUE_EOL		EQU		000000000h
EEEP_OFFSET_VALUE_EOL_ALT		EQU		00000ffffh
; 
;  * CRC Checksum Block
;  *
;  
;  0x00 Block Header 
;  0x03 CRC16 Checksum 
@tag_CRC16ChkBlock_s		STRUCT 1t
cHdr		BlockIdHdr_t		<>
CrC16		uint8_t		2t DUP (?)
@tag_CRC16ChkBlock_s		ENDS

CRC16ChkBlock_t		TYPEDEF		@tag_CRC16ChkBlock_s

; 
;  *      System Information
;  *
;  *  see http://www.dmtf.org/standards/documents/SMBIOS/DSP0134.pdf
;  
;  0x00 Block Header 
;  0x03 Number of ASCIIZ String 
;  0x04 Number of ASCIIZ String 
;  0x05 Number of ASCIIZ String 
;  0x06 Number of ASCIIZ String 
;  0x07 Number of ASCIIZ String 
;  0x08 Number of ASCIIZ String 
;  0x09 Number of ASCIIZ String 
;  0x0A String Block 
@tag_SystemInfo_s		STRUCT 1t
cHdr		BlockIdHdr_t		<>
Manufacturer		uint8_t		?
ProductName		uint8_t		?
Version		uint8_t		?
SerialNumber		uint8_t		?
SKU_Number		uint8_t		?
Family		uint8_t		?
AssetTagNumber		uint8_t		?
StringsBlock		SBYTE		1t DUP (?)
@tag_SystemInfo_s		ENDS

SystemInfo_t		TYPEDEF		@tag_SystemInfo_s

; 
;  *      Chassis Information
;  *
;  *  see http://www.dmtf.org/standards/documents/SMBIOS/DSP0134.pdf
;  
;  0x00 Block Header 
;  0x03 Number of ASCIIZ String 
;  0x04 ENUM 
;  0x05 Number of ASCIIZ String 
;  0x05 Number of ASCIIZ String 
;  0x06 Number of ASCIIZ String 
;  0x07 String Block 
@tag_ChassisInfo_s		STRUCT 1t
cHdr		BlockIdHdr_t		<>
Manufacturer		uint8_t		?
ChassisType		uint8_t		?
Version		uint8_t		?
SerialNumber		uint8_t		?
AssetTagNumber		uint8_t		?
StringsBlock		SBYTE		1t DUP (?)
@tag_ChassisInfo_s		ENDS

ChassisInfo_t		TYPEDEF		@tag_ChassisInfo_s

; 
;  *     Base Board (or Module) Information
;  *
;  *  see http://www.dmtf.org/standards/documents/SMBIOS/DSP0134.pdf
;  
;  0x00 Block Header 
;  0x03 Number of ASCIIZ String 
;  0x04 Number of ASCIIZ String 
;  0x05 Number of ASCIIZ String 
;  0x06 Number of ASCIIZ String 
;  0x07 Number of ASCIIZ String 
;  0x08 A collection of 
;                             *      flags that identify 
;                             *      features of this 
;                             *      baseboard.
;                             *      +=======+=========================+
;                             *      | Bits  | Descriptions            |
;                             *      +=======+=========================+
;                             *      | 0     | Is Motherboard          |
;                             *      +-------+-------------------------+
;                             *      | 1     | Requires Daughter Board |
;                             *      +-------+-------------------------+
;                             *      | 2     | Removable               |
;                             *      +-------+-------------------------+
;                             *      | 3     | Replaceable             |
;                             *      +-------+-------------------------+
;                             *      | 4     | Hot Swap Capable        |
;                             *      +-------+-------------------------+
;                             *      | 5 - 7 | Reserved                |
;                             *      +=======+=========================+
;                             
SMBIOS_IS_Motherboard		EQU		000000001h
SMBIOS_REQ_DAUGHTER		EQU		000000002h
SMBIOS_REMOVABLE		EQU		000000004h
SMBIOS_REPLACEABLE		EQU		000000008h
SMBIOS_HOT_SWAP_CAP		EQU		000000010h
;  0x09 Number of ASCIIZ String 
;  0x0A SMBIOS_BoardTypes_t 
;  0x0B String Block 
@tag_ModuleInfo_s		STRUCT 1t
cHdr		BlockIdHdr_t		<>
Manufacturer		uint8_t		?
Product		uint8_t		?
Version		uint8_t		?
SerialNumber		uint8_t		?
AssetTag		uint8_t		?
FeatureFlag		uint8_t		?
Location		uint8_t		?
BoardType		uint8_t		?
StringsBlock		SBYTE		1t DUP (?)
@tag_ModuleInfo_s		ENDS

ModuleInfo_t		TYPEDEF		@tag_ModuleInfo_s

SMBIOS_BoardType_Unknown		EQU		0t
SMBIOS_BoardType_Other		EQU		1t
SMBIOS_BoardType_ServerBlade		EQU		2t
SMBIOS_BoardType_ConnectivitySwitch		EQU		3t
SMBIOS_BoardType_SystemManagementModule		EQU		4t
SMBIOS_BoardType_ProcessorModule		EQU		5t
SMBIOS_BoardType_IO_Module		EQU		6t
SMBIOS_BoardType_Memory_Module		EQU		7t
SMBIOS_BoardType_DaughterBoard		EQU		8t
SMBIOS_BoardType_Motherboard		EQU		9t
SMBIOS_BoardType_ProcessorMemory_Module		EQU		10t
SMBIOS_BoardType_Interconnect_Board		EQU		11t

SMBIOS_BoardTypes_t		TYPEDEF		SDWORD

; 
;  * Display Device Data Block
;  *
;  
;  0x00 Block Header 
;  0x03 Display Interface 
EEEP_DISP_INT_LVDS		EQU		000000002h
EEEP_DISP_INT_SDVOB		EQU		000000003h
EEEP_DISP_INT_SDVOC		EQU		000000004h
EEEP_DISP_INT_DDI1		EQU		000000005h
EEEP_DISP_INT_DDI2		EQU		000000006h
EEEP_DISP_INT_DDI3		EQU		000000007h
;  0x04 Display Raw Data
; 			       *      DisplayID
; 			       *      EDID
; 			       *      UDS
; 			       *      EPI
;     			       
@tag_LFPDataBlock_s		STRUCT 1t
cHdr		BlockIdHdr_t		<>
Interface		uint8_t		?
RawData		uint8_t		1t DUP (?)
@tag_LFPDataBlock_s		ENDS

LFPDataBlock_t		TYPEDEF		@tag_LFPDataBlock_s

; 
;  * Vendor Specific Block Header
;  *
;  
;  0x00 Block Header 
;  0x03 Compressed PNPID  
;  After This Point is only 
;      * Suggested
;      
; uint8_t       VendBlockId; /* 0x04 Vendor Specific Block Id  */
; uint8_t       VendData[1]; /* 0x05 Vendor Data */
@tag_VendBlockHdr_s		STRUCT 1t
cHdr		BlockIdHdr_t		<>
VendId		uint8_t		2t DUP (?)
@tag_VendBlockHdr_s		ENDS

VendBlockHdr_t		TYPEDEF		@tag_VendBlockHdr_s

; 
;  * Descriptor for Additional EEPROMS
;  *
;  * I.E. For Chassis/System/Base Board EEPROMs
;  
;  0x00 Block Header 
;  0x03 Encoded 7/10 Bit Device Address 
;  0x05 Device Bus       
EEEP_I2CBuSID_I2C		EQU		000000000h
EEEP_I2CBuSID_SMB		EQU		000000001h
EEEP_I2CBuSID_LVDS		EQU		000000002h
EEEP_I2CBuSID_DDI1		EQU		000000003h
EEEP_I2CBuSID_DDI2		EQU		000000004h
EEEP_I2CBuSID_DDI3		EQU		000000005h
;  0x06 Device Descriptor
;                                 * +========+========================+
;                                 * | Bits   | Description            |
;                                 * +========+========================+
;                                 * | 0 - 3  | Size 2^(8+n) Bytes     |
;                                 * |        | (256 << n) Bytes       |
;                                 * |        |                        |
;                                 * |        | Addressable Bytes      |
;                                 * |        |   Standard Index       |
;                                 * |        |     8bit - 11Bit       |
;                                 * |        |   Extended Index       |
;                                 * |        |     16bit - 19Bit      |
;                                 * |        | 2048 KBit - 4096 MBit  |
;                                 * |        | 256 Bytes - 512 KBytes |
;                                 * |        |                        |
;                                 * +--------+------------------------+
;                                 * | 4      | Std/Ext Index          |
;                                 * +--------+------------------------+
;                                 * | 5 - 7  | Reserved               |
;                                 * +========+========================+
;                                 
EEEP_ExtEEP_EXT_INDX		EQU		000000010h
@tag_ExtI2CDeviceDesc_s		STRUCT 1t
cHdr		BlockIdHdr_t		<>
DeviceAddr		uint8_t		2t DUP (?)
DeviceBus		uint8_t		?
DeviceDesc		uint8_t		?
@tag_ExtI2CDeviceDesc_s		ENDS

ExtI2CDeviceDesc_t		TYPEDEF		@tag_ExtI2CDeviceDesc_s

; 
;  * Platform Specific Headers
;  *
;  
; Begin of file include\masm\..\COM0EEP.h
; 
;  *<KHeader>
;  *+=========================================================================
;  *I               EApiDK Embedded Application Development Kit
;  *+=========================================================================
;  *I  $HeadURL$
;  *+=========================================================================
;  *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
;  *I      Author: John Kearney,                  John.Kearney@kontron.com
;  *I
;  *I     License: All rights reserved. This program and the accompanying 
;  *I              materials are licensed and made available under the 
;  *I              terms and conditions of the BSD License which 
;  *I              accompanies this distribution. The full text of the 
;  *I              license may be found at 
;  *I              http://opensource.org/licenses/bsd-license.php
;  *I              
;  *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN 
;  *I              "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
;  *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
;  *I
;  *I Description: COM0 R2.0 Specific Structures and Data
;  *I
;  *+------------------------------------------------------------------------=
;  *I
;  *I  File Name            : COM0EEP.h
;  *I  File Location        : include
;  *I  Last committed       : $Revision$
;  *I  Last changed by      : $Author$
;  *I  Last changed date    : $Date$
;  *I  ID                   : $Id$
;  *I
;  *+=========================================================================
;  *</KHeader>
;  
;  Structures for COM0 STDEEP 
__COM0EEP_H__		TEXTEQU		<>
;  COM0 R2.0 Standard Revision 
COM0R20_VER		EQU		2t
COM0R20_REVISION		EQU		0t
COM0R20_VERSION		EQU		000000020h
; 
;  * COM R2.0
;  * Backplane EEPROM Header
;  *
;  
;  0x00 EEprom Id         
;  0x0C Backplane Type    
;  0x0D COM0 Specification Revision
;                             *      
;                             *      +=======+==================+
;                             *      | Bits  | Descriptions     |
;                             *      +=======+==================+
;                             *      | 0 - 3 | Revision         |
;                             *      +-------+------------------+
;                             *      | 4 - 7 | Version          |
;                             *      +=======+==================+
;                             
;  0x0E Bit Mask Macros for 
;                             *      USB Descriptor Byte
;                             *      
;                             *      +=======+===============================+
;                             *      | Bits  | Descriptions                  |
;                             *      +=======+===============================+
;                             *      | 0 - 3 | Count of High Speed Ports     |
;                             *      +-------+-------------------------------+
;                             *      | 4 - 6 | Count of Super Speed Ports    |
;                             *      +-------+-------------------------------+
;                             *      | 7     | Reserved                      |
;                             *      +=======+===============================+
;                             
COM0R20_USB3_PCNT_MASK		EQU		000000007h
COM0R20_USB3_PCNT_OFFSET		EQU		000000004h
COM0R20_USB_PCNT_MASK		EQU		00000000fh
COM0R20_USB_PCNT_OFFSET		EQU		000000000h
;  0x0F BitMask Macros for 
;                             *      LAN Descriptor Byte
;                             *      
;                             *      +=======+=================================+
;                             *      | Bits  | Descriptions                    |
;                             *      +=======+=================================+
;                             *      | 0 - 1 | SATA / SAS Channel 0            |
;                             *      |       |                                 |
;                             *      |       | +========+====================+ |
;                             *      |       | | Bit    | Description        | |
;                             *      |       | +========+====================+ |
;                             *      |       | | 0      | Implemented        | |
;                             *      |       | +--------+--------------------+ |
;                             *      |       | | 1      | 0 SATA Device      | |
;                             *      |       | |        | 1 SAS  Device      | |
;                             *      |       | +========+====================+ |
;                             *      +-------+---------------------------------+
;                             *      | 2 - 3 | SATA / SAS Channel 1            |
;                             *      |       |                                 |
;                             *      |       | +========+====================+ |
;                             *      |       | | Bit    | Description        | |
;                             *      |       | +========+====================+ |
;                             *      |       | | 2      | Implemented        | |
;                             *      |       | +--------+--------------------+ |
;                             *      |       | | 3      | 0 SATA Device      | |
;                             *      |       | |        | 1 SAS  Device      | |
;                             *      |       | +========+====================+ |
;                             *      +-------+---------------------------------+
;                             *      | 4 - 5 | SATA / SAS Channel 2            |
;                             *      |       |                                 |
;                             *      |       | +========+====================+ |
;                             *      |       | | Bit    | Description        | |
;                             *      |       | +========+====================+ |
;                             *      |       | | 4      | Implemented        | |
;                             *      |       | +--------+--------------------+ |
;                             *      |       | | 5      | 0 SATA Device      | |
;                             *      |       | |        | 1 SAS  Device      | |
;                             *      |       | +========+====================+ |
;                             *      +-------+---------------------------------+
;                             *      | 6 - 7 | SATA / SAS Channel 3            |
;                             *      |       |                                 |
;                             *      |       | +========+====================+ |
;                             *      |       | | Bit    | Description        | |
;                             *      |       | +========+====================+ |
;                             *      |       | | 6      | Implemented        | |
;                             *      |       | +--------+--------------------+ |
;                             *      |       | | 7      | 0 SATA Device      | |
;                             *      |       | |        | 1 SAS  Device      | |
;                             *      |       | +========+====================+ |
;                             *      +=======+=================================+
;                             
COM0R20_SAS_CONNECTOR_PRESENT		EQU		000000001h
COM0R20_SATA_SAS_DEVICE		EQU		000000002h
COM0R20_SAS_CHANNEL_0		EQU		000000000h
COM0R20_SAS_CHANNEL_1		EQU		000000002h
COM0R20_SAS_CHANNEL_2		EQU		000000004h
COM0R20_SAS_CHANNEL_3		EQU		000000006h
;  0x10 BitMask Macros for 
;                             *      LAN Descriptor Byte
;                             *      
;                             *      +=======+===============================+
;                             *      | Bits  | Descriptions                  |
;                             *      +=======+===============================+
;                             *      | 0     | GBE0 Implemented              |
;                             *      +-------+-------------------------------+
;                             *      | 1     | GBE1 Implemented              |
;                             *      +-------+-------------------------------+
;                             *      | 2     | GBE2 Implemented              |
;                             *      +-------+-------------------------------+
;                             *      | 3     | GB1E0 Implemented             |
;                             *      +-------+-------------------------------+
;                             *      | 4 - 7 | Reserved                      |
;                             *      +=======+===============================+
;                             
COM0R20_GBE0_PRESENT		EQU		000000001h
COM0R20_GBE1_PRESENT		EQU		000000002h
COM0R20_GBE2_PRESENT		EQU		000000004h
COM0R20_GB1E0_PRESENT		EQU		000000008h
;  0x11 BitMask Macros for 
;                             *      Miscellaneous I/O Descriptor Byte 1
;                             *      
;                             *      +======+===============================+
;                             *      | Bits | Descriptions                  |
;                             *      +======+===============================+
;                             *      | 0    | WAKE0 Implemented             |
;                             *      +------+-------------------------------+
;                             *      | 1    | WAKE1 Implemented             |
;                             *      +------+-------------------------------+
;                             *      | 2    | SUS Implemented               |
;                             *      +------+-------------------------------+
;                             *      | 3    | BATLOW Implemented            |
;                             *      +------+-------------------------------+
;                             *      | 4    | THRMP Implemented             |
;                             *      +------+-------------------------------+
;                             *      | 5    | EBROM Implemented             |
;                             *      +------+-------------------------------+
;                             *      | 6    | WDT Implemented               |
;                             *      +------+-------------------------------+
;                             *      | 7    | AC97 Implemented              |
;                             *      +======+===============================+
;                             
COM0R20_WAKE0_PRESENT		EQU		000000001h
COM0R20_WAKE1_PRESENT		EQU		000000002h
COM0R20_SUS_PRESENT		EQU		000000004h
COM0R20_BATLOW_PRESENT		EQU		000000008h
COM0R20_THRMP_PRESENT		EQU		000000010h
COM0R20_EBROM_PRESENT		EQU		000000020h
COM0R20_WDT_PRESENT		EQU		000000040h
COM0R20_AC97_PRESENT		EQU		000000080h
;  0x12 BitMask Macros for 
;                             *      Miscellaneous I/O Descriptor Byte 2
;                             *      
;                             *      +=======+===============================+
;                             *      | Bits  | Descriptions                  |
;                             *      +=======+===============================+
;                             *      | 0     | SSC Present                   |
;                             *      +-------+-------------------------------+
;                             *      | 1     | SDIO Present                  |
;                             *      +-------+-------------------------------+
;                             *      | 2 - 7 | Reserved                      |
;                             *      +=======+===============================+
;                             
COM0R20_SSC_PRESENT		EQU		000000001h
COM0R20_SDIO_PRESENT		EQU		000000002h
;  0x13 BitMask Macros for 
;                             *      Digital Display Interface Descriptor Byte
;                             *      
;                             *      +=======+=================================+
;                             *      | Bits  | Description                     |
;                             *      +=======+=================================+
;                             *      | 0 - 2 | DDI Port 1                      |
;                             *      |       |                                 |
;                             *      |       | +========+====================+ |
;                             *      |       | | Value  | Description        | |
;                             *      |       | +========+====================+ |
;                             *      |       | | 0      | Unused             | |
;                             *      |       | | 1      | eDisplay Port      | |
;                             *      |       | | 2      | Display Port       | |
;                             *      |       | | 3      | HDMI/DVI           | |
;                             *      |       | | 4      | SDVO               | |
;                             *      |       | | 5-7    | Reserved           | |
;                             *      |       | +========+====================+ |
;                             *      +-------+---------------------------------+
;                             *      | 3 - 5 | DDI Port 2                      |
;                             *      |       |                                 |
;                             *      |       | +========+====================+ |
;                             *      |       | | Value  | Description        | |
;                             *      |       | +========+====================+ |
;                             *      |       | | 0      | Unused             | |
;                             *      |       | | 1      | eDisplay Port      | |
;                             *      |       | | 2      | Display Port       | |
;                             *      |       | | 3      | HDMI/DVI           | |
;                             *      |       | +========+====================+ |
;                             *      +-------+---------------------------------+
;                             *      | 5     | Reserved                        |
;                             *      +-------+---------------------------------+
;                             *      | 6 - 7 | DDI Port 3                      |
;                             *      |       |                                 |
;                             *      |       | +========+====================+ |
;                             *      |       | | Value  | Description        | |
;                             *      |       | +========+====================+ |
;                             *      |       | | 0      | Unused             | |
;                             *      |       | | 1      | eDisplay Port      | |
;                             *      |       | | 2      | Display Port       | |
;                             *      |       | | 3      | HDMI/DVI           | |
;                             *      |       | +========+====================+ |
;                             *      +-------+---------------------------------+
;                             
COM0R20_DDI_NOT_USED		EQU		000000000h
COM0R20_DDI_eDispPort		EQU		000000001h
COM0R20_DDI_DispPort		EQU		000000002h
COM0R20_DDI_HDMI		EQU		000000003h
COM0R20_DDI_SDVO		EQU		000000004h
COM0R20_DDI_BITMASK		EQU		000000003h
COM0R20_DDI1_OFFSET		EQU		000000000h
COM0R20_DDI2_OFFSET		EQU		000000003h
COM0R20_DDI3_OFFSET		EQU		000000006h
;  0x14 
;  0x15 
COM0R20_VGA_PRESENT		EQU		000000010h
COM0R20_LVDSCB_PRESENT		EQU		000000008h
COM0R20_LVDSCA_PRESENT		EQU		000000004h
COM0R20_SDVOCC_PRESENT		EQU		000000002h
COM0R20_SDVOCB_PRESENT		EQU		000000001h
;  0x16 +=======+=================================+
;                             *      | Bits  | Description                     |
;                             *      +=======+=================================+
;                             *      | Lane 0                                  |
;                             *      +-------+---------------------------------+
;                             *      | 0 - 2 | +========+====================+ |
;                             *      |       | | Value  | Description        | |
;                             *      |       | +========+====================+ |
;                             *      |       | | 0      | Unused             | |
;                             *      |       | | 1      | 1  Lane            | |
;                             *      |       | | 2      | 2  Lanes           | |
;                             *      |       | | 3      | 4  Lanes           | |
;                             *      |       | | 4      | 8  Lanes           | |
;                             *      |       | | 5      | 16 Lanes           | |
;                             *      |       | | 6      | 32 Lanes           | |
;                             *      |       | | 7      | Reserved           | |
;                             *      |       | +========+====================+ |
;                             *      +-------+---------------------------------+
;                             *      | 3     | +========+====================+ |
;                             *      |       | | Value  | Description        | |
;                             *      |       | +========+====================+ |
;                             *      |       | | 0      | Gen 1              | |
;                             *      |       | | 1      | Gen 2              | |
;                             *      |       | +========+====================+ |
;                             *      +-------+---------------------------------+
;                             
@tag_COM0R20_BP_s		STRUCT 1t
EepHdr		StdEep_t		<>
BPType		uint8_t		?
SpecRev		uint8_t		?
UsbDesc		uint8_t		?
SasDesc		uint8_t		?
LanDesc		uint8_t		?
MiscIo1		uint8_t		?
MiscIo2		uint8_t		?
DDIDesc		uint8_t		?
Reserved0		uint8_t		?
Reserved1		uint8_t		?
LaneMap		uint8_t		16t DUP (?)
@tag_COM0R20_BP_s		ENDS

COM0R20_BP_t		TYPEDEF		@tag_COM0R20_BP_s

;  
;  * Pci Express Lane Mapping 
;  *
;  * Example 1
;  * Standard Type 2
;  * 6 x1
;  * 1 x16
;  * +======+=======+==================+
;  * | Byte | Value | Description      |
;  * +======+=======+==================+
;  * | 00   | 11    | x1 Lane 00 & 01  |
;  * | 01   | 11    | x1 Lane 02 & 03  |
;  * | 02   | 11    | x1 Lane 04 & 05  |
;  * | 03   | 00    | Unused           |
;  * | 04   | 00    | Unused           |
;  * | 05   | 00    | Unused           |
;  * | 06   | 00    | Unused           |
;  * | 07   | 00    | Unused           |
;  * | 08   | 55    | x16 Lane 16 - 31 |
;  * | 09   | 55    | x16 Lane 16 - 31 |
;  * | 10   | 55    | x16 Lane 16 - 31 |
;  * | 11   | 55    | x16 Lane 16 - 31 |
;  * | 12   | 55    | x16 Lane 16 - 31 |
;  * | 13   | 55    | x16 Lane 16 - 31 |
;  * | 12   | 55    | x16 Lane 16 - 31 |
;  * | 14   | 55    | x16 Lane 16 - 31 |
;  * | 15   | 55    | x16 Lane 16 - 31 |
;  * +======+=======+==================+
;  *
;  * Example 2
;  * Type 2
;  * 1 x4
;  * 2 x1
;  * 1 x16
;  * +======+=======+==================+
;  * | Byte | Value | Description      |
;  * +======+=======+==================+
;  * | 00   | 33    | x4 Lane 00 - 03  |
;  * | 01   | 33    | x4 Lane 00 - 03  |
;  * | 02   | 11    | x1 Lane 04 & 05  |
;  * | 03   | 00    | Unused           |
;  * | 04   | 00    | Unused           |
;  * | 05   | 00    | Unused           |
;  * | 06   | 00    | Unused           |
;  * | 07   | 00    | Unused           |
;  * | 08   | 55    | x16 Lane 16 - 31 |
;  * | 09   | 55    | x16 Lane 16 - 31 |
;  * | 10   | 55    | x16 Lane 16 - 31 |
;  * | 11   | 55    | x16 Lane 16 - 31 |
;  * | 12   | 55    | x16 Lane 16 - 31 |
;  * | 13   | 55    | x16 Lane 16 - 31 |
;  * | 12   | 55    | x16 Lane 16 - 31 |
;  * | 14   | 55    | x16 Lane 16 - 31 |
;  * | 15   | 55    | x16 Lane 16 - 31 |
;  * +======+=======+==================+
;  *
;  * Example 3
;  * Type 2
;  * 2 x2
;  * 2 x1
;  * 4 x4
;  * +======+=======+==================+
;  * | Byte | Value | Description      |
;  * +======+=======+==================+
;  * | 00   | 22    | x2 Lane 00 - 01  |
;  * | 01   | 11    | x1 Lane 02 & 03  |
;  * | 02   | 00    | Unused           |
;  * | 03   | 00    | Unused           |
;  * | 04   | 00    | Unused           |
;  * | 05   | 00    | Unused           |
;  * | 06   | 00    | Unused           |
;  * | 07   | 00    | Unused           |
;  * | 08   | 33    | x4  Lane 16 - 19 |
;  * | 09   | 33    | x4  Lane 16 - 19 |
;  * | 10   | 33    | x4  Lane 20 - 23 |
;  * | 11   | 33    | x4  Lane 20 - 23 |
;  * | 12   | 33    | x4  Lane 24 - 27 |
;  * | 13   | 33    | x4  Lane 24 - 27 |
;  * | 14   | 33    | x4  Lane 28 - 31 |
;  * | 15   | 33    | x4  Lane 28 - 31 |
;  * +======+=======+==================+
;  *
;  
; 
;  * COM R2.0
;  * Module EEPROM Header
;  *
;  
;  0x00 EEprom Id          
;  0x0C Module Type        
;  0x0D 
;                             *      +=======+==================+
;                             *      | Bits  | Descriptions     |
;                             *      +=======+==================+
;                             *      | 0 - 3 | Revision         |
;                             *      +-------+------------------+
;                             *      | 4 - 7 | Version          |
;                             *      +=======+==================+
;                             
; 
;     * Module Fixed Offset Information
;     * 
;     
@tag_COM0R20_M_s		STRUCT 1t
EepHdr		StdEep_t		<>
MType		uint8_t		?
SpecRev		uint8_t		?
@tag_COM0R20_M_s		ENDS

COM0R20_M_t		TYPEDEF		@tag_COM0R20_M_s

COM0R20_BLOCK_ID_EXP_CARD_DESC		EQU		0000000e0h
; 
;  * Express Card Slot Descriptor
;  *
;  
;  0x00 Block Header 
;  0x03 0 - 1 
;  0x04 0 - 31 
;                                    *      +=======+==================+
;                                    *      | Bits  | Descriptions     |
;                                    *      +=======+==================+
;                                    *      | 0 - 4 | PCI Express Port |
;                                    *      |       | Mapping.         |
;                                    *      |       | Port Starting    |
;                                    *      |       | Lane.            |
;                                    *      |       | 0 - 31           |
;                                    *      +-------+------------------+
;                                    *      | 5 - 7 | USB Port Mapping |
;                                    *      |       | 0 - 7            |
;                                    *      +=======+==================+
;                                    
;  0x05 An Array of
;                                    *      Port/Device
;                                    *      numbers Terminated
;                                    *      with 0x7F
;                                    
COM0R20_EXPCARD_MAP_EOL		EQU		00000007fh
@tag_ExpCardBlock_s		STRUCT 1t
cHdr		BlockIdHdr_t		<>
ExpressCardNumber		uint8_t		?
ComExpressPort		uint8_t		?
SwitchPortNumber		uint8_t		1t DUP (?)
@tag_ExpCardBlock_s		ENDS

ExpCardBlock_t		TYPEDEF		@tag_ExpCardBlock_s

;  __COM0EEP_H__ 
; End of file include\masm\..\COM0EEP.h
;  n = 2 , stack popped
; 
;  * CPU Independent Multi Byte 
;  * Big Endian Memory Access
;  
; 
;  * CPU Independent Multi Byte 
;  * Little Endian Memory Access
;  
;  __EEEP_H__ 
; End of file include\masm\..\EeeP.h
; End of file include\masm\EeePConv.h
