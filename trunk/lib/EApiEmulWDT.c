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
 *I Description: Auto Created for EApiEmulWDT.c
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiEmulWDT.c
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
 *  W A T C H D O G
 *
 *
 *
 */
#define WATCHDOG_ENABLED  ((unsigned)-1)
#define WATCHDOG_DISABLED ((unsigned)0)
static unsigned WatchdogState=WATCHDOG_DISABLED;


uint32_t 
EApiWDogStartEmul(
    __IN uint32_t timeout, 
    __IN uint32_t delay
    )
{
  EAPI_LIB_RETURN_ERROR_IF(
      EApiWDogStartEmul, 
      (WatchdogState==WATCHDOG_ENABLED), 
      EAPI_STATUS_RUNNING, 
      "Watchdog alread runing, need to stop before starting"
      );
  if(timeout&delay)
    WatchdogState=WATCHDOG_DISABLED;
  else
    WatchdogState=WATCHDOG_ENABLED;
  EAPI_LIB_RETURN_SUCCESS(EApiWDogStartEmul, "");
}
uint32_t 
EApiWDogTriggerEmul(void)
{
  EAPI_LIB_RETURN_ERROR_IF(
      EApiWDogTriggerEmul, 
      (WatchdogState==WATCHDOG_DISABLED), 
      EAPI_STATUS_ERROR, 
      "Watchdog Disabled therefore not possible to trigger"
      );

  EAPI_LIB_RETURN_SUCCESS(
      EApiWDogTriggerEmul, 
      ""
      );
}
uint32_t 
EApiWDogStopEmul(void)
{
  WatchdogState=WATCHDOG_DISABLED;
  EAPI_LIB_RETURN_SUCCESS(
      EApiWDogStopEmul, 
      ""
      );
}



