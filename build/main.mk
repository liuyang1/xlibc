CF_ALL		= -g -Wall
LF_ALL		=
LL_ALL		=

CC			= ./build/ccd-gcc
INST		= ./build/install
COMP		= $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK		= $(CC) $(LF_ALL) $(LF_TGT) -o $@ $^ $(LL_TGT) $(LL_ALL)
COMPLINK	= $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)

include Rules.mk
