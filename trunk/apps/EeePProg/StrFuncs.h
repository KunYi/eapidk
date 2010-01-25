/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
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
 *I Description: Auto Created for sprintf.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : StrFuncs.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision$
 *I  Last changed by      : $Author$
 *I  Last changed date    : $Date$
 *I  ID                   : $Id$
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __STRFUNCS_H__
#define __STRFUNCS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define iswhitespace(x) ((x==' ')||(x=='\t'))
#define iseol(x) (x=='\0')
#define isdecimal(x) ((x>='0')&&(x<='9'))
#define ishex(x) (isdecimal(x)||(x>='A')&&(x<='F')||(x>='a')&&(x<='f'))
#define isoctal(x)   ((x>='0')&&(x<='7'))
#define isbinary(x)  ((x>='0')&&(x<='1'))

void 
skipWhiteSpaces(
        char **const pcszStr
        );

void 
stripWhiteSpaces(
        char *const pszStr
        );

unsigned long 
ulConvertStr2Num(
    const char *  pcszStr, 
    char **       pcszEnd
    );


#ifdef __cplusplus
}
#endif
#endif /* __STRFUNCS_H__ */
