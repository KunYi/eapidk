@IF "%DEBUG%"=="1" GOTO Skip_Header
@ECHO OFF
GOTO Skip_Header
@REM <KHeader>
@REM +=========================================================================
@REM I  Project Name: EApiDK Embedded Application Development Kit
@REM +=========================================================================
@REM I  $HeadURL$
@REM +=========================================================================
@REM I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
@REM I      Author: John Kearney,                  John.Kearney@kontron.com
@REM I
@REM I     License: All rights reserved. This program and the accompanying 
@REM I              materials are licensed and made available under the 
@REM I              terms and conditions of the BSD License which 
@REM I              accompanies this distribution. The full text of the 
@REM I              license may be found at 
@REM I              http://opensource.org/licenses/bsd-license.php
@REM I              
@REM I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
@REM I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
@REM I              ANY KIND, EITHER EXPRESS OR IMPLIED.
@REM I
@REM I Description: Auto Created for BuildInc.cmd
@REM I
@REM +-------------------------------------------------------------------------
@REM I
@REM I  File Name            : BuildInc.cmd
@REM I  File Location        : BuildTools\WINNT
@REM I  Last committed       : $Revision$
@REM I  Last changed by      : $Author$
@REM I  Last changed date    : $Date$
@REM I  ID                   : $Id$
@REM I
@REM +=========================================================================
@REM </KHeader>
:Skip_Header
if /i "%~1"=="/H" GOTO Usage
if /i "%~1"=="-H" GOTO Usage
if /i "%~1"=="/?" GOTO Usage
if /i "%~1"=="-?" GOTO Usage


REM ########################################################################
REM MAIN PROGRAM
REM ########################################################################
:Main_Program
  IF NOT EXIST "%~1" GOTO Error_Exit
  IF EXIST "%~1.tmp" erase /q "%~1.tmp"
  for /f "tokens=1-3* " %%a in ('TYPE "%~1"') do call :BuildIcrement "%%a" "%%b" "%%c" "%%d" "%~1.tmp" "%~2"
  IF ERRORLEVEL 1 GOTO Error_Exit
  move  /y "%~1.tmp" %1
  GOTO Exit

REM ########################################################################
REM PROCEDURES
REM ########################################################################
:BuildIcrement
  IF NOT "%~2"=="%~6" GOTO NormalLine
  SET /A VALUE=%~3+1
  ECHO #
  ECHO # %~6 Incremented to %VALUE%
  ECHO #
  ECHO # in %~dpn5

  SET TMP_VAL="%~1 %~2 %VALUE% %~4"
  GOTO :PrintLine
  
  :NormalLine
  SET TMP_VAL="%~1 %~2 %~3 %~4"

  :PrintLine
  SET TMP_VAL=%TMP_VAL:>=^>%
  SET TMP_VAL=%TMP_VAL:<=^<%
  SET TMP_VAL=%TMP_VAL:|=^|%
  ECHO %TMP_VAL:"=% 1>> %5
  GOTO :EOF


REM ########################################################################
REM Usage
REM ########################################################################
:Usage
  ECHO ===============================================================================
  ECHO I  %~nx0                                              $Revision$
  ECHO ===============================================================================
  ECHO I  
  ECHO I  Description:
  ECHO I    Please Enter a program description here
  ECHO I  
  ECHO I  Usage:
  ECHO I    %~nx0 ^<FileName^> ^<Token Name^> 
  ECHO I  
  GOTO Exit

REM ########################################################################
REM Error_Exit
REM ########################################################################
:Error_Exit_File
  ECHO #
  ECHO # Error File Doesn't Exist %1
  ECHO #
  GOTO PEXIT
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
 SET VALUE=

:Return


