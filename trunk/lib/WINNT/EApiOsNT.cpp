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
 *I Description: Auto Created for EApiOsNT.cpp
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiOsNT.cpp
 *I  File Location        : lib\WINNT
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EApiLib.h>

//***************************************************************************
extern "C" {
BOOL WINAPI _CRT_INIT(HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved);
}

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
    // Perform actions based on the reason for calling.
//     if (fdwReason == DLL_PROCESS_ATTACH)
//       EApiInitLib();

    if (fdwReason == DLL_PROCESS_ATTACH || fdwReason == DLL_THREAD_ATTACH)
    {
        if (!_CRT_INIT(hinstDLL, fdwReason, lpReserved))
            return(FALSE);
        // Load Driver
    }
    else if (fdwReason == DLL_PROCESS_DETACH || fdwReason == DLL_THREAD_DETACH)
    {
        if (!_CRT_INIT(hinstDLL, fdwReason, lpReserved))
            return(FALSE);
        // Load Driver
    }
//     if (fdwReason == DLL_PROCESS_DETACH)
//       EApiUninitLib();
    return(TRUE);
}

