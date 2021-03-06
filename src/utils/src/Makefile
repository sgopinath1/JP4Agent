#
# Makefile.inc -- Makefile to build utils library
#
# JP4Agent : Juniper P4 Agent
#
# Created by Sandesh Kumar Sodhi, January 2018
# Copyright (c) [2018] Juniper Networks, Inc. All rights reserved.
#
# All rights reserved.
#
# Notice and Disclaimer: This code is licensed to you under the Apache
# License 2.0 (the "License"). You may not use this code except in compliance
# with the License. This code is not an official Juniper product. You can
# obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
#
# Third-Party Code: This code may depend on other components under separate
# copyright notice and license terms. Your use of the source code for those
# components is subject to the terms and conditions of the respective license
# as noted in the Third-Party source code file.
#

VERSION = 0

ifdef UBUNTU
CXX = g++
CPPFLAGS += -DUBUNTU
endif

TARGET_LIB = libutils.so.$(VERSION)
RM = rm -rf
OBJDIR  = ../obj

CXXFLAGS += -fPIC -std=c++14 -Wall -Werror

ifdef DEBUG_BUILD
	CXXFLAGS += -g -O0
endif

ifdef CODE_COVERAGE
	CXXFLAGS += -fprofile-arcs -ftest-coverage
endif

CPPFLAGS += \
	-I. \
	-I../include \

ifdef CODE_COVERAGE
	LDLIBS += -fprofile-arcs -ftest-coverage -lgcov
endif

LDFLAGS = -shared $(LDLIBS)

all: $(OBJDIR)/$(TARGET_LIB)
	@echo $(TARGET_LIB) compilation success!

SRCS = \
	uint128.cpp \
	Utils.cpp \
	JaegerLog.cpp

OBJS=$(subst .cc,.o, $(subst .cpp,.o, $(SRCS)))
OBJS := $(addprefix $(OBJDIR)/,$(OBJS))

$(OBJDIR)/$(TARGET_LIB): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
	rm -f ${basename $@}
	ln -s ${notdir $@} ${basename $@}

$(OBJDIR)/%.o : %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJDIR) ./.depend

ifeq ($(prefix),)
    prefix := /usr/local
endif

.PHONY: install
install: $(OBJDIR)/$(TARGET_LIB)
	install -d $(DESTDIR)$(prefix)/lib64/
	install -m 644 $(OBJDIR)/$(TARGET_LIB) $(DESTDIR)$(prefix)/lib64/
	rm -f $(DESTDIR)$(prefix)/lib64/${basename $(TARGET_LIB)}
	ln -s ${notdir $(TARGET_LIB)} $(DESTDIR)$(prefix)/lib64/${basename $(TARGET_LIB)}
	install -d $(DESTDIR)$(prefix)/include/jp4agent
	install -d $(DESTDIR)$(prefix)/include/jp4agent/src
	install -d $(DESTDIR)$(prefix)/include/jp4agent/src/utils
	cd ../; cp --parents `find -name \*.h` $(DESTDIR)$(prefix)/include/jp4agent/src/utils/

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MM $^ >  ./.depend;

include .depend
