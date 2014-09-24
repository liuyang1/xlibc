sp			:= $(sp).x
dirstack_$(sp)	:= $(d)
d			:= $(dir)

# local rules and targets
OBJS_$(d)	:= $(d)/string.o $(d)/outputbuf.o $(d)/ctype.o

DEPS_$(d)	:= $(OBJS_$(d):%=%.d)

CLEAN		:= $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d)) $(d)/common.a $(d)/platform.h

$(BOJS_$(d)):	CF_TGT := -I$(d)

$(d)/common.a: $(OBJS_$(d))
	$(ARCH)
#------------------------

-include 	$(DEPS_$(d))

d			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))
