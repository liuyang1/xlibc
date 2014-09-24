.SUFFIXES:
.SUFFIXES:		.c .o

all: targets

dir		:= src
include 	$(dir)/Rules.mk
dir		:= gtest
include 	$(dir)/Rules.mk
dir		:= test
include 	$(dir)/Rules.mk

%.o:	%.c
	$(COMP)

%:		%.o
	$(LINK)

%:		%.c
	$(COMPLINK)


.PHONY:	targets
targets:	$(TG_BIN) $(TG_SBIN) $(TG_ETC) $(TG_LIB)

.PHONY: clean
clean:
	rm -f $(CLEAN)
