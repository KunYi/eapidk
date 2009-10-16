@IF "%DEBUG%"=="1" GOTO Skip_Header
@ECHO OFF
GOTO Skip_Header
REM <KHeader>
REM +=========================================================================
REM I               EApiDK Embedded Application Development Kit
REM +=========================================================================
REM I  $HeadURL$
REM +=========================================================================
REM I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
REM I      Author: John Kearney,                  John.Kearney@kontron.com
REM I
REM I     License: All rights reserved. This program and the accompanying 
REM I              materials are licensed and made available under the 
REM I              terms and conditions of the BSD License which 
REM I              accompanies this distribution. The full text of the 
REM I              license may be found at 
REM I              http://opensource.org/licenses/bsd-license.php
REM I              
REM I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
REM I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
REM I              ANY KIND, EITHER EXPRESS OR IMPLIED.
REM I
REM I Description: Auto Created for buildnt.cmd
REM I
REM +------------------------------------------------------------------------=
REM I
REM I  File Name            : buildnt.cmd
REM I  File Location        : 
REM I  Last committed       : $Revision$
REM I  Last changed by      : $Author$
REM I  Last changed date    : $Date$
REM I  ID                   : $Id$
REM I
REM +=========================================================================
REM </KHeader>
:Skip_Header
if /i "%~1"=="/H" GOTO Usage
if /i "%~1"=="-H" GOTO Usage
if /i "%~1"=="/?" GOTO Usage
if /i "%~1"=="-?" GOTO Usage


SET TARGETLIB=EAPI_1
SET TARGETOSB=WNET
SET TARGETARCHS="" "I64" "AMD64"
REM SET TARGETARCHS=""
SET APPSBASE=%~dp0apps
SET EAPILIBBASE=%~dp0lib
SET VERBOSE=1
IF NOT "%~2"=="" SET TARGETARCHS=%~2

IF /I "%~1"=="BUILD_APP" GOTO BUILD_APP
IF /I "%~1"=="BUILD_LIB" GOTO BUILD_LIB
IF /I "%~1"=="PACK"      GOTO PACK_BUILD
IF /I "%~1"=="BUILD_INC" GOTO BUILD_INC
REM ########################################################################
REM MAIN PROGRAM
REM ########################################################################
:Main_Program
:BUILD_LIB
  SET LIBFILES="EApi.cpp" "EApiEmulGPIO.c" "EApiEmulI2C.c" "EApiInitLib.c" "EApiEmulBacklight.c" "EApiEmulBoardInfo.c" "EApiEmulStorage.c" "EApiEmulWDT.c"
  call :CopyFiles "%EAPILIBBASE%" "%EAPILIBBASE%\WINNT" %LIBFILES%
  for %%a in (%TARGETARCHS%) do @(
    call :BUILD_LIB_GENERIC %%a
  )
  call :DeleteFiles "%EAPILIBBASE%\WINNT" %LIBFILES%
  SET LIBFILES=
  call :RunProg "%~dp0BuildTools\WINNT\BuildInc.cmd" "%EAPILIBBASE%\LibVer.h" "LIB_BUILD"
IF /I "%~1"=="BUILD_LIB" GOTO Exit

:BUILD_APP
  SET APPHELPFILES="EApiAHI2C.c" "EApiAHStorage.c" "EApiAHStr.c"
  call :CopyFiles "%APPSBASE%\common" "%APPSBASE%\EApiValidateAPI\WINNT" %APPHELPFILES%
  for %%a in (%TARGETARCHS%) do @(
    call :BUILD_APP_GENERIC EApiValidateAPI EApiValidateAPI.c %%a
  )
  call :DeleteFiles "%APPSBASE%\EApiValidateAPI\WINNT" %APPHELPFILES% %LCLFILES% "%TARGETLIB%.lib"
  SET APPHELPFILES=
  call :RunProg "%~dp0BuildTools\WINNT\BuildInc.cmd" "%APPSBASE%\EApiValidateAPI\AppVer.h" "APP_BUILD"
  GOTO exit

:PACK_BUILD
  call :DeleteFiles "%~dp0" "EApiDK.*.*.*.7z"
  REM call :DeleteFiles "%~dp0" "EApiDK.*.*.*.tar.bz2"
  SET IGNOREFILE=Exclude.tmp
  ECHO *.RAR > "%IGNOREFILE%"
  ECHO *.zip >> "%IGNOREFILE%"
  ECHO *.7z  >> "%IGNOREFILE%"
  ECHO *.tar.bz2 >> "%IGNOREFILE%"
  ECHO *.tar.gz  >> "%IGNOREFILE%"
  ECHO *.tar     >> "%IGNOREFILE%"
  ECHO bin   >> "%IGNOREFILE%"
  ECHO .cvs  >> "%IGNOREFILE%"
  ECHO .svn  >> "%IGNOREFILE%"
  ECHO *.doc  >> "%IGNOREFILE%"
  ECHO *.pdf  >> "%IGNOREFILE%"
  ECHO *.docx >> "%IGNOREFILE%"
  ECHO *.odt  >> "%IGNOREFILE%"
  ECHO *.odt# >> "%IGNOREFILE%"
  ECHO *.o   >> "%IGNOREFILE%"
  ECHO *.s   >> "%IGNOREFILE%"
  ECHO *.so  >> "%IGNOREFILE%"
  ECHO *.stackdump  >> "%IGNOREFILE%"
  ECHO *.lst >> "%IGNOREFILE%"
  ECHO *.obj >> "%IGNOREFILE%"
  ECHO *.lib >> "%IGNOREFILE%"
  ECHO *.asm >> "%IGNOREFILE%"
  ECHO *.log >> "%IGNOREFILE%"
  ECHO *.pdb >> "%IGNOREFILE%"
  ECHO *.exe >> "%IGNOREFILE%"
  ECHO *.sbr >> "%IGNOREFILE%"
  ECHO *.dll >> "%IGNOREFILE%"
  ECHO *.exp >> "%IGNOREFILE%"
  ECHO *.mac >> "%IGNOREFILE%"
  ECHO *.tmp >> "%IGNOREFILE%"
  ECHO obj*_*_* >> "%IGNOREFILE%"
  ECHO "*~" >> "%IGNOREFILE%"
  ECHO TAGS  >> "%IGNOREFILE%"
  ECHO TAGS.*>> "%IGNOREFILE%"
  CALL :GetValueFromCHeaderFile "%EAPILIBBASE%\LibVer.h" "LIB_VERSION"
  CALL :GetValueFromCHeaderFile "%EAPILIBBASE%\LibVer.h" "LIB_REVISION"
  CALL :GetValueFromCHeaderFile "%EAPILIBBASE%\LibVer.h" "LIB_BUILD"
  call :RunProg "%~dp0BuildTools\WINNT\%PROCESSOR_ARCHITECTURE%\7za.exe" a -r -x@"%IGNOREFILE%" "%~dp0EApiDK.%LIB_VERSION%.%LIB_REVISION%.%LIB_BUILD%.7z" "%~dp0"
  IF ERRORLEVEL 1 GOTO Error_Exit
  call :DeleteFiles "." "%IGNOREFILE%"
  SET IGNOREFILE=
  SET LIB_VERSION=
  SET LIB_REVISION=
  SET LIB_BUILD=
  GOTO exit

:BUILD_INC 
  call :RunProg h2inc /Zu /C /Zp4 /WIN32 /Ht /zu /znCOM0 /Fa"include\masm\EeePConv.inc" "include\masm\EeePConv.h"
  IF ERRORLEVEL 1 GOTO Error_Exit
  call :RunProg h2inc /Zu /C /Zp4 /WIN32 /Ht /zu /znEApi /Fa"include\masm\EApiConv.inc" "include\masm\EApiConv.h"
  IF ERRORLEVEL 1 GOTO Error_Exit
  GOTO exit

REM ########################################################################
REM PROCEDURES
REM ########################################################################
:GetValueFromCHeaderFile 
  REM Extracts values with the following Format
  REM #define VALUE_NAME VALUE
  IF NOT EXIST "%~1" GOTO Error_NoFile
  SET %~2=
  for /f "tokens=2,3 " %%a in ('TYPE "%~1"') do if /I "%%a"=="%~2" SET %~2=%%b
  CALL :DoCommand IF "%%%~2%%"=="" SET %~2=0
  GOTO :EOF
  :Error_NoFile
    SET %~2=0
    GOTO :EOF

:DoCommand
  %*
  GOTO :EOF
:SETUP_VARS
  SET TARGETOSP=%~1
  SET TARGETOS=%TARGETOSB%%TARGETOSP%
  SET TARGETARCH=%TARGETOSP%
  REM 3 way to refer to names
  REM BUILD TYPE I ENV Variable  I Binary Name
  REM -----------+---------------+-------------
  REM TARGETOSP  I TARGETARCHENV I TARGETARCH
  REM WNET       I x86           I i386
  REM WNETIA64   I ia64          I ia64 
  REM WNETAMD64  I amd64         I amd64
  IF "%TARGETARCH%"=="I64"  SET TARGETARCH=ia64
  IF "%TARGETARCH%"==""  SET TARGETARCH=i386
  IF "%TARGETARCH%"=="AMD64"  SET TARGETARCH=amd64
  SET TARGETARCHENV=%TARGETARCH%
  IF "%TARGETARCHENV%"=="i386"  SET TARGETARCHENV=x86
  GOTO :EOF

:BUILD_LIB_GENERIC
  call :SETUP_VARS %1
  
  call :BuildProject checked  "%EAPILIBBASE%\WINNT"   
  IF ERRORLEVEL 1 GOTO Error_Exit
  call :BuildProject free     "%EAPILIBBASE%\WINNT"   
  IF ERRORLEVEL 1 GOTO Error_Exit

  call :CopyFiles  "%EAPILIBBASE%\WINNT\objchk_%TARGETOSB%_%TARGETARCHENV%\%TARGETARCH%" "%APPSBASE%\bin\winnt\%TARGETARCHENV%\chk" %TARGETLIB%.dll %TARGETLIB%.pdb
  call :CopyFiles  "%EAPILIBBASE%\WINNT\objfre_%TARGETOSB%_%TARGETARCHENV%\%TARGETARCH%" "%APPSBASE%\bin\winnt\%TARGETARCHENV%\fre" %TARGETLIB%.dll %TARGETLIB%.pdb
  call :CopyFiles  "%EAPILIBBASE%\WINNT\objfre_%TARGETOSB%_%TARGETARCHENV%\%TARGETARCH%" "%EAPILIBBASE%\lib\winnt\%TARGETARCHENV%" "%TARGETLIB%.lib"

  CALL :SignExes "%APPSBASE%\bin\winnt\%TARGETARCHENV%\fre\%TARGETLIB%.dll" 
  CALL :SignExes "%APPSBASE%\bin\winnt\%TARGETARCHENV%\chk\%TARGETLIB%.dll" 
  GOTO :EOF

:BUILD_APP_GENERIC
  call :SETUP_VARS %3
  SET LCLFILES=
  :LoopFiles
  IF "%~2"=="" GOTO Continue
  SET LCLFILES=%LCLFILES% %2 
  shift /2
  goto LoopFiles
  :Continue
  call :CopyFiles "%APPSBASE%\%~1"    "%APPSBASE%\%~1\WINNT" %LCLFILES%
  SET ERRORM= ERROR: Build Lib First missing "lib\winnt\%TARGETARCHENV%\%TARGETLIB%.lib"
  IF NOT EXIST "%EAPILIBBASE%\lib\winnt\%TARGETARCHENV%\%TARGETLIB%.lib" GOTO ERRORM
  call :CopyFiles "%EAPILIBBASE%\lib\winnt\%TARGETARCHENV%"  "%APPSBASE%\%~1\WINNT" "%TARGETLIB%.lib"

  call :BuildProject checked  "%APPSBASE%\%~1\WINNT"
  IF ERRORLEVEL 1 GOTO Error_Exit


  call :BuildProject free     "%APPSBASE%\%~1\WINNT"
  IF ERRORLEVEL 1 GOTO Error_Exit

  call :CopyFiles  "%APPSBASE%\%~1\WINNT\objfre_%TARGETOSB%_%TARGETARCHENV%\%TARGETARCH%" "%APPSBASE%\bin\winnt\%TARGETARCHENV%\fre" %~1.exe %~1.pdb
  call :CopyFiles  "%APPSBASE%\%~1\WINNT\objchk_%TARGETOSB%_%TARGETARCHENV%\%TARGETARCH%" "%APPSBASE%\bin\winnt\%TARGETARCHENV%\chk" %~1.exe %~1.pdb
  
  CALL :SignExes "%APPSBASE%\bin\winnt\%TARGETARCHENV%\fre\%~1.exe" 
  CALL :SignExes "%APPSBASE%\bin\winnt\%TARGETARCHENV%\chk\%~1.exe" 
  GOTO :EOF
  :ERRORM
  ECHO %ERRORM%
  call :SetErrorLevel 1
  GOTO :EOF
  

:BuildProject
  ECHO # 
  ECHO # Building %~2 (%~1)
  ECHO # 
  call :RunProg "%~dp0BuildTools\WINNT\ddkbuild.cmd" -%TARGETOS% %*
  GOTO :EOF

:RunProg
  IF "%VERBOSE%"=="1" ECHO %*
  call %*
  GOTO :EOF

:CopyFiles
  IF NOT EXIST "%~2" mkdir "%~2"
  :CopyLoop
    REM ECHO "%~1\%~3"
    IF NOT EXIST "%~1\%~3" GOTO TryNext
    call :RunProg copy /Y "%~1\%~3" "%~2"
  :TryNext
    shift /3
    if "%~3"=="" GOTO :EOF
    GOTO CopyLoop

:DeleteFiles
  :DeleteLoop
    IF NOT EXIST "%~1\%~2" GOTO TryNext
    call :RunProg erase /q "%~1\%~2"
  :TryNext
    shift /2
    if "%~2"=="" GOTO :EOF
    GOTO DeleteLoop

:SetErrorLevel
  cmd /C exit %1
  goto :EOF

:SignExes
  :SignLoop
    IF NOT EXIST "%~1" GOTO TryNext
    call :RunProg "%~dp0BuildTools\WINNT\SignEXE.cmd" %1
  :TryNext
    shift /1
    if "%~1"=="" GOTO :EOF
    GOTO SignLoop

REM ########################################################################
REM Usage
REM ########################################################################
:Usage
  ECHO ===============================================================================
  ECHO I  %~nx0                                              $$Rev$
  ECHO ===============================================================================
  ECHO I  
  ECHO I  Description:
  ECHO I    Please Enter a program description here
  ECHO I  
  ECHO I  Usage:
  ECHO I    %~nx0 [BUILD_APP^|BUILD_LIB^|PACK^|BUILD_INC]
  ECHO I  
  GOTO Exit

REM ########################################################################
REM Error_Exit
REM ########################################################################
:Error_Exit
  ECHO #
  ECHO # Build Error
  ECHO #
  GOTO PEXIT

:PEXIT
  IF NOT "%BATCHMODE%"=="1" pause

REM ########################################################################
REM Normal Exit
REM ########################################################################
:Exit
  REM Delete any used environment variables
  SET TARGETOS=
  SET APPSBASE=
  SET EAPILIBBASE=
  SET APPHELPFILES=
  SET LIBFILES=
  SET LCLFILES=

:Return

