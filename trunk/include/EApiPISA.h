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
 *I Description: Auto Created for EApiPISA.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiPISA.h
 *I  File Location        : include
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */

#ifndef _EAPIPISA_H_        
#define _EAPIPISA_H_


/*
 *
 *      B O A R D   I N F O M A T I O N   S T R I N G S 
 *
 */
/* IDS */
#define EAPI_PISA_ID_BOARD_MANUFACTURER_STR     EAPI_ID_BOARD_MANUFACTURER_STR
#define EAPI_PISA_ID_BOARD_NAME_STR             EAPI_ID_BOARD_NAME_STR
#define EAPI_PISA_ID_BOARD_SERIAL_STR           EAPI_ID_BOARD_SERIAL_STR
#define EAPI_PISA_ID_BOARD_BIOS_REVISION_STR    EAPI_ID_BOARD_BIOS_REVISION_STR
#define EAPI_PISA_ID_BOARD_PLATFORM_TYPE_STR    EAPI_ID_BOARD_PLATFORM_TYPE_STR

#define EAPI_PISA_PLATFORM_STR     "PISA"

/*
 *
 *      B O A R D   I N F O M A T I O N   V A L U E S
 *
 */
/* IDS */
#define EAPI_PISA_ID_BOARD_BOOT_COUNTER_VAL        EAPI_ID_BOARD_BOOT_COUNTER_VAL
#define EAPI_PISA_ID_BOARD_RUNNING_TIME_METER_VAL  EAPI_ID_BOARD_RUNNING_TIME_METER_VAL
#define EAPI_PISA_ID_BOARD_PNPID_VAL               EAPI_ID_BOARD_PNPID_VAL
#define EAPI_PISA_ID_BOARD_PLATFORM_REV_VAL        EAPI_ID_BOARD_PLATFORM_REV_VAL


#define EAPI_PISA_ID_BOARD_DRIVER_VERSION_VAL    EAPI_ID_BOARD_DRIVER_VERSION_VAL
#define EAPI_PISA_ID_BOARD_LIB_VERSION_VAL       EAPI_ID_BOARD_LIB_VERSION_VAL

#define EAPI_PISA_REV_1_0      EAPI_VER_CREATE(1, 0, 0)

/*
 *
 *      B A C K L I G H T
 *
 */
/* IDS */
#define EAPI_PISA_ID_BACKLIGHT_1              EAPI_ID_BACKLIGHT_1
#define EAPI_PISA_ID_BACKLIGHT_2              EAPI_ID_BACKLIGHT_2


/*
 *
 *      S T O R A G E
 *
 */
/* IDs */
#define EAPI_PISA_ID_STORAGE_STD              EAPI_ID_STORAGE_STD

/*
 *
 *      I 2 C
 *
 */
/* IDs */
#define EAPI_PISA_ID_I2C_EXTERNAL       EAPI_ID_I2C_EXTERNAL
#define EAPI_PISA_ID_I2C_LVDS_1         EAPI_ID_I2C_LVDS_1
#define EAPI_PISA_ID_I2C_LVDS_2         EAPI_ID_I2C_LVDS_2


/*
 *
 *      G P I O
 *
 */
/* IDs */
/*
 * No GPIOs Supported
 *
 */


/*
 *
 *      T E M P E R A T U R E
 *
 */
/* IDs */
#define EAPI_PISA_ID_TEMP_CPU  EAPI_ID_TEMP_CPU



#endif /* _EAPIPISA_H_ */

