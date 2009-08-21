#!/bin/bash
#if [ "$DEBUG" != "1" ]; then stty -echo; fi
#+=========================================================================
#|               Embedded API Development Kit 
#+=========================================================================
#| 
#|  Copyright (c) 2009, Kontron Embedded Modules GmbH                                         
#|  All rights reserved. This program and the accompanying materials                          
#|  are licensed and made available under the terms and conditions of the BSD License         
#|  which accompanies this distribution.  The full text of the license may be found at        
#|  http://opensource.org/licenses/bsd-license.php                                            
#|                                                                                            
#|  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
#|  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             
#|
#|  Author: John Kearney,                      John.Kearney@kontron.com
#| 
#|  $Date$$Rev$
#+=========================================================================
ScriptDir=$(cd "$(dirname "$0")"; pwd)
EAPILIBBASE=$ScriptDir/lib
EAPIAPPSBASE=$ScriptDir/apps

#########################################################################
# Normal Exit
#########################################################################
function NormalExit {
	if [ "$DEBUG" != "1" ]; then stty echo; fi
	echo ERRORLEVEL=$1
	exit $1
}
function PEXIT {
	if [ "$BATCHMODE" != "1" ]; then
		pause
	fi
	NormalExit $1
}
#########################################################################
# Error_Exit
#########################################################################
function Error_Exit {
	echo \#
	echo \# $2
	echo \#
	PEXIT $1
}
function RunProg {
	echo $*
  $@
  return $?
}
#########################################################################
# PROCEDURES
#########################################################################
function GetValueFromCHeaderFile {
  if [ -f $1 ]; then 
    TmpVar=$(grep "$2" $1 | sed -r -n s/^\#\\s*define\\s\+$2\\s\+\([0-9]\+\).*/\\1/p)
  else
    echo $1 Doesn\'t exist
    TmpVar=
  fi
  return $TmpVar
}
function VariableInc {
  GetValueFromCHeaderFile "$1" "$2"
  if [ -n $TmpVar ]; then 
    TmpVar=`expr $TmpVar + 1`
    # the .* is on purpose to make it compatible to the 
    # cmd version
    sed -i -r s/^\(\#\\s*define\\s\+$2\\s\+\)[0-9]\+.*$/\\1$TmpVar/ $1;
    echo \#
    echo \# $2 incremented to $TmpVar
    echo \#
    echo \# in $1
    return 0
  fi
  return 1
}
function DeleteFiles {
  local BaseFolder=
  local ReturnValue=
  for VAR1 in "$@"
  do
    if [ -z $BaseFolder ]; then
      BaseFolder=$VAR1
    else
      if [ "$VAR1"!="" ]; then
        RunProg rm -f "$BaseFolder/$VAR1"
        ReturnValue=$?
      fi
    fi
  done
  return $ReturnValue
}
function BUILD_LIB {
  cd $EAPILIBBASE/linux/
  echo \#
  echo \# Building $EAPILIBBASE/linux/
  echo \#
  RunProg make $2
  local ReturnValue=$?
  cd $ScriptDir
  VariableInc "$EAPILIBBASE/LibVer.h" "LIB_BUILD"
  return $ReturnValue
}
function BUILD_APP {
  cd $EAPIAPPSBASE/EApiValidateAPI/linux/
  echo \#
  echo \# Building $EAPIAPPSBASE/EApiValidateAPI/linux/
  echo \#
  RunProg make $2
  local ReturnValue=$?
  cd $ScriptDir
  VariableInc "$EAPIAPPSBASE/EApiValidateAPI/AppVer.h" "APP_BUILD"
  return $ReturnValue
}
function INSTALL {
  cd $EAPILIBBASE/linux/
  echo \#
  echo \# Installing Shared Library
  echo \#
  RunProg make install $2
  local ReturnValue=$?
  cd $ScriptDir
  return $ReturnValue
}
function BUILD_INC {
  echo Not Supported for Linux
  return 0
}
function PACK {
  DeleteFiles "$ScriptDir" "EApiDK.*.*.*.tar.bz2"
  #DeleteFiles "$ScriptDir" "EApiDK.*.*.*.7z"
  local IGNOREFILE=Exclude.tmp
  echo '*.RAR' > "$IGNOREFILE"
  echo '*.zip' >> "$IGNOREFILE"
  echo '*.7z'  >> "$IGNOREFILE"
  echo '*.tar.bz2'  >> "$IGNOREFILE"
  echo '*.tar.gz'   >> "$IGNOREFILE"
  echo '*.tar'      >> "$IGNOREFILE"
  echo 'bin'   >> "$IGNOREFILE"
  echo '.cvs'  >> "$IGNOREFILE"
  echo '.svn'  >> "$IGNOREFILE"
  echo '*.doc'  >> "$IGNOREFILE"
  echo '*.pdf'  >> "$IGNOREFILE"
  echo '*.docx' >> "$IGNOREFILE"
  echo '*.odt'  >> "$IGNOREFILE"
  echo '*.odt#' >> "$IGNOREFILE"
  echo '*.o'   >> "$IGNOREFILE"
  echo '*.s'   >> "$IGNOREFILE"
  echo '*.so'  >> "$IGNOREFILE"
  echo '*.stackdump'  >> "$IGNOREFILE"
  echo '*.lst' >> "$IGNOREFILE"
  echo '*.obj' >> "$IGNOREFILE"
  echo '*.lib' >> "$IGNOREFILE"
  echo '*.asm' >> "$IGNOREFILE"
  echo '*.log' >> "$IGNOREFILE"
  echo '*.pdb' >> "$IGNOREFILE"
  echo '*.exe' >> "$IGNOREFILE"
  echo '*.sbr' >> "$IGNOREFILE"
  echo '*.dll' >> "$IGNOREFILE"
  echo '*.exp' >> "$IGNOREFILE"
  echo '*.mac' >> "$IGNOREFILE"
  echo '*.tmp' >> "$IGNOREFILE"
  echo 'obj*_*_*' >> "$IGNOREFILE"
  echo '*~' >> "$IGNOREFILE"
  echo 'TAGS'  >> "$IGNOREFILE"
  echo 'TAGS.*'>> "$IGNOREFILE"
  GetValueFromCHeaderFile "$EAPILIBBASE/LibVer.h" "LIB_VERSION"
  local LIB_VERSION=$TmpVar
  GetValueFromCHeaderFile "$EAPILIBBASE/LibVer.h" "LIB_REVISION"
  local LIB_REVISION=$TmpVar
  GetValueFromCHeaderFile "$EAPILIBBASE/LibVer.h" "LIB_BUILD"
  local LIB_BUILD=$TmpVar
  cd $ScriptDir
  RunProg tar -jcvf "./EApiDK.$LIB_VERSION.$LIB_REVISION.$LIB_BUILD.tar.bz2" --ignore-case --exclude-from="$IGNOREFILE" "."
  if [ $? -gt 1 ]; then return $?; fi
  DeleteFiles "." "$IGNOREFILE"
  return 0
}


#########################################################################
# Usage
#########################################################################
function Usage {
	echo .
	echo +==============================================================================
	echo I  $(basename $0) ................................................... \$Rev$
	echo +==============================================================================
	echo I  
	echo I  Description:
	echo I    Please Enter a program description here
	echo I  
	echo I  Usage:
	echo I    $(basename $0) [BUILD_APP\|BUILD_LIB\|PACK]
	echo I  
	NormalExit 0
}


#########################################################################
# Argument Processing
#########################################################################
for ARG in "$@"; do
	if [ "$ARG" = "/H" ]; then Usage; fi
	if [ "$ARG" = "/h" ]; then Usage; fi
	if [ "$ARG" = "/?" ]; then Usage; fi
	if [ "$ARG" = "-H" ]; then Usage; fi
	if [ "$ARG" = "-h" ]; then Usage; fi
	if [ "$ARG" = "-?" ]; then Usage; fi
done

if [ "$1" != "" ]; then 
  if [ `echo $1 | tr [:lower:] [:upper:]` = "BUILD_APP" ]; then BUILD_APP $2; NormalExit $?; fi
  if [ `echo $1 | tr [:lower:] [:upper:]` = "BUILD_LIB" ]; then BUILD_LIB $2; NormalExit $?; fi
  if [ `echo $1 | tr [:lower:] [:upper:]` = "PACK"      ]; then PACK $2;      NormalExit $?; fi
  if [ `echo $1 | tr [:lower:] [:upper:]` = "BUILD_INC" ]; then BUILD_INC $2; NormalExit $?; fi
  if [ `echo $1 | tr [:lower:] [:upper:]` = "INSTALL"   ]; then INSTALL $2; NormalExit $?; fi
  Error_Exit 2 "ERROR: Unsupported Argument \"$1\"" 
fi

#########################################################################
# MAIN PROGRAM
#########################################################################
BUILD_LIB quick
BUILD_APP quick

NormalExit 0



