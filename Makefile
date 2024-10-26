.PHONY: all run clean

CC=gcc
CFLAGS=-Wall -ansi -pedantic
PROJECTNAME=oop_in_c
EXAMPLE=example

INC=include
SRC=src

INCLUDE=-I$(INC)
CFILES+=$(SRC)/point.c
CFILES+=$(SRC)/rectangle.c

ifeq ($(OS),Windows_NT)
	TARGET=$(EXAMPLE).exe
    EXTENSION=.dll
    SLIB=lib$(PROJECTNAME)$(EXTENSION)
    ECHO=echo
	RM=del
	ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        TARGET=$(EXAMPLE)
        EXTENSION=.so
        SLIB=lib$(PROJECTNAME)$(EXTENSION)
		ECHO=echo
		RM=rm -fv
    endif
    ifeq ($(UNAME_S),Darwin)
        
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        
    endif
endif

all: $(SLIB) $(TARGET)

$(SLIB): $(CFILES)
	@$(ECHO) "Building $(@F)"
	@$(CC) $(CFLAGS) -shared $(INCLUDE) $(CFILES) -o $@

$(TARGET): $(SRC)/$(EXAMPLE).c $(CFILES)
	@$(ECHO) "Building $(@F)"
	@$(CC) $(CFLAGS) $(INCLUDE) $< -o $@ -L./ -Wl,-rpath ./ -l$(PROJECTNAME)

run:
	@./$(TARGET)

clean:
	@$(RM) $(TARGET)
	@$(RM) $(SLIB)
