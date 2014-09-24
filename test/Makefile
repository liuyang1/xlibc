GTEST_DIR     = ../gtest
USER_DIR      = .
INC_DIR       = ../inc
SRC_DIR       = ../src

INCS		 += -I$(GTEST_DIR)/inc -I$(INC_DIR)
CXXFLAGS     += -g -Wall -Wextra

CXX				= g++

FILE_SUFFIX		= c
TEST_SUFFIX		= test
TESTSRCS		:= $(wildcard *.$(FILE_SUFFIX))
TESTOBJS		:= $(patsubst %.$(FILE_SUFFIX),%.o,$(TESTSRCS))
TESTS			:= $(patsubst %.$(FILE_SUFFIX),%,$(TESTSRCS))
OBJS			:= $(patsubst %.$(TEST_SUFFIX),%.o,$(TESTS))


GTEST_HEADERS = $(GTEST_DIR)/inc/gtest/*.h

all : $(TESTS)

card:
	echo $(OBJS) && echo $(TESTS) && echo $(TESTOBJS) && echo $(TESTSRCS)

$(TESTOBJS): %.o : %.$(FILE_SUFFIX) 
	$(CXX) -c $(INCS) $< -o $@
$(OBJS): %.o : ../%.$(FILE_SUFFIX)
	$(CXX) -c $(INCS) $< -o $@
$(TESTS): % : %.o  gtest_main.a $(OBJS) $(SRC_DIR)/*.o
	$(CXX) $(CXXFLAGS) $^ -o $@ -lpthread

.PHONY:run clean stat
run:
	./ts.test
clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o core core.*
stat:
	cloc .
