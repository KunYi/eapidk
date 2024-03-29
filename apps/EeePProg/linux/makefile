#<KHeader>
#+=========================================================================
#I  Project Name: EApiDK Embedded Application Development Kit
#+=========================================================================
#I  $HeadURL$
#+=========================================================================
#I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
#I      Author: John Kearney,                  John.Kearney@kontron.com
#I
#I     License: All rights reserved. This program and the accompanying 
#I              materials are licensed and made available under the 
#I              terms and conditions of the BSD License which 
#I              accompanies this distribution. The full text of the 
#I              license may be found at 
#I              http://opensource.org/licenses/bsd-license.php
#I              
#I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
#I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
#I              ANY KIND, EITHER EXPRESS OR IMPLIED.
#I
#I Description: Auto Created for makefile
#I
#+-------------------------------------------------------------------------
#I
#I  File Name            : makefile
#I  File Location        : apps\EeePProg\linux
#I  Last committed       : $Revision$
#I  Last changed by      : $Author$
#I  Last changed date    : $Date$
#I  ID                   : $Id$
#I
#+=========================================================================
#</KHeader>
ARCH = $(shell uname -s)
ifndef MACH
MACH = $(shell uname -m)
endif
ifeq ($(ARCH), HP-UX)
ARCH=HPUX
endif
# Note: for cross compilation
# This script does allow for CROSS Compilation
# to achieve this specify the following
# variables
# CFLAGS
# MACH
.SUFFIXES:
.SUFFIXES: .c .s .o .exe .H

# static library
AR = ar
RANLIB = ranlib
ARFLAGS = -ruv

BinFolder=../../bin/$(ARCH)/$(MACH)/rel
DBinFolder=../../bin/$(ARCH)/$(MACH)/dbg
BuildDir=./build/$(MACH)/rel
DBuildDir=./build/$(MACH)/dbg
PrgFldr=$(join $(shell pwd)/, ..)
CmnFldr=$(join $(shell pwd)/, ../../common)
EAPI_INC=$(join $(shell pwd)/, ../../../include/EApi.h)
GET_VAR_FROM_CFILE=$(shell grep "$(2)" $(1) |sed -rn "s/^\#\s*define\s+$2\s+([0-9]+).*/\1/p")
EAPI_VERSION=$(call GET_VAR_FROM_CFILE,$(EAPI_INC),EAPI_VER)
EAPI_REVISION=$(call GET_VAR_FROM_CFILE,$(EAPI_INC),EAPI_REVISION)

LibName:=EApi
VPNPID:=PMG
LibFName:=$(LibName).$(EAPI_VERSION).$(EAPI_REVISION).o
SoName:=lib$(LibName).so.$(EAPI_VERSION)
SoFName:=lib$(LibName)$(VPNPID).so.$(EAPI_VERSION).$(EAPI_REVISION)
StaticLibFName:=$(LibName).a
ExeName=EeePProg

#DBGOPT:=-gxcoff3
#DBGOPT:=-gxcoff+
#DBGOPT:=-gcoff3
#DBGOPT:=-gdwarf-2
#DBGOPT:=-g3
#DBGOPT:=-gstabs
#DBGOPT:=-gstabs+
DBGOPT:=-g -O0 
RELOPT:=-O3
INCLUDS=-I../../../include/linux -I../ -I../../include -I../../../include 
CFLAGS:= -std=gnu99 -Wall -W -Werror -pedantic $(INCLUDS)

define FLD_BUILD_RULE
@mkdir -p $(@)
endef

define PRG_BUILD_RULE
gcc -v $(CFLAGS) $(1) -L. -ldl -o $(@) -Wl,-Map,$(basename $(@)).map $^
objcopy --only-keep-debug  "$(@)" "$(@).debug" 
strip --strip-debug --strip-unneeded "$(@)"
objcopy --add-gnu-debuglink="$(@).debug" "$(@)"
endef

define C_BUILD_RULE
$(CC) $(CFLAGS) $(1) -x c -c -g -Wa,-a,-ad -o  $(@) $< > $(basename $(@)).lst
$(CC) $(CFLAGS) $(1) -x c -S -o  $(basename $(@)).s $<
endef

define CLEAN_BUILD_FOLDER
@rm -f $(1)/*.log
@rm -f $(1)/*.o
@rm -f $(1)/*
@rm -f $(1)/*.s
@rm -f $(1)/*.a
@rm -f $(1)/*.lst
@rm -f $(1)/*.map
@rm -f $(1)/*.exeendef
endef

define REMOVE_BIN_FILES
@rm -f $(1)
@rm -f $(basename $(1)).map
@rm -f $(basename $(1)).debug
endef

OBJECTS=$(ExeName).o \
      EApiAHI2C.o \
      EApiAHStorage.o \
      EApiAHStr.o  \
	ArgParse.o \
	BinFuncs.o \
	CfgParser.o \
	CfgPHelper.o \
	EeePCfg.o \
	EeePDB.o \
	StrFuncs.o TokenFunc.o RangeFunc.o DbgChk.o Str2Value.o StrPrint.o
      
      

DefaultTgt: buildall

buildall: clean quick

quick:$(BinFolder) \
      $(BuildDir) \
      $(DBinFolder) \
      $(DBuildDir) \
      $(DBinFolder)/$(ExeName) \
      $(BinFolder)/$(ExeName)
	@echo SYSTEM ARCHITECTURE : $(ARCH)
	@echo CPU ARCHITECTURE .. : $(MACH)
	@echo Library Name ...... : $(LibName)
	@echo Shared Lib Name ... : $(SoName)
	@echo Static Lib Filename : $(StaticLibFName)
	@echo Shared Lib Filename : $(SoFName)
	@echo Program Name ...... : $(ExeName)

  

$(BinFolder):
	$(FLD_BUILD_RULE)

$(BuildDir):
	$(FLD_BUILD_RULE)

$(DBinFolder):
	$(FLD_BUILD_RULE)

$(DBuildDir):
	$(FLD_BUILD_RULE)

$(DBinFolder)/$(ExeName): $(addprefix $(DBuildDir)/,$(OBJECTS)) $(DBinFolder)/$(SoFName)
	$(call PRG_BUILD_RULE,$(DBGOPT))

$(BinFolder)/$(ExeName):  $(addprefix $(BuildDir)/,$(OBJECTS))  $(BinFolder)/$(SoFName)
	$(call PRG_BUILD_RULE,$(RELOPT))

$(DBuildDir)/%.o:$(CmnFldr)/%.c
	$(call C_BUILD_RULE,$(DBGOPT))

$(BuildDir)/%.o:$(CmnFldr)/%.c
	$(call C_BUILD_RULE,$(RELOPT))

$(DBuildDir)/%.o:$(PrgFldr)/%.c
	$(call C_BUILD_RULE,$(DBGOPT))

$(BuildDir)/%.o:$(PrgFldr)/%.c
	$(call C_BUILD_RULE,$(RELOPT))

$(DBuildDir)/%.o:$(PrgFldr)/%.cpp
	$(call C_BUILD_RULE,$(DBGOPT))

$(BuildDir)/%.o:$(PrgFldr)/%.cpp
	$(call C_BUILD_RULE,$(RELOPT))


.PHONY: clean
.PHONY: help
clean::
	$(call REMOVE_BIN_FILES,$(DBuildDir)/$(ExeName))
	$(call REMOVE_BIN_FILES,$(BuildDir)/$(ExeName))
	$(call CLEAN_BUILD_FOLDER,$(DBuildDir))
	$(call CLEAN_BUILD_FOLDER,$(BuildDir))


help::
	@echo ###############################################################################
	@echo #        Build Mak Files
	@echo ###############################################################################
	@echo # help
	@echo # clean
	@echo # quick
	@echo # buildall
	@echo #

