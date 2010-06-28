/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: Kontron Secure Bios
 *+=========================================================================
 *I  $HeadURL$
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Generic Command Line Argument Parsing Routines
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : ArgParse.c
 *I  File Location        : Aristo\common
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __STRPRINT_H__
#define __STRPRINT_H__

#ifdef __cplusplus
extern "C" {
#endif


EApiStatus_t
PrintStringBlockA(
    FILE       *OutStream     ,
    const char *cszStr        ,
    size_t      stMaxBlockLen ,
    const char *cszPreamble   ,
    signed int  siLen         ,
    const char *cszPostamble
    );

EApiStatus_t
PrintStringBlock(
    FILE       *OutStream     ,
    const char *cszStr        ,
    size_t      stMaxBlockLen ,
    const char *cszPreamble   ,
    signed int  siLen         ,
    const char *cszPostamble
    );


#ifdef __cplusplus
}
#endif
#endif /* __STRPRINT_H__ */

