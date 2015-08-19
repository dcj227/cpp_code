THIRD_64 = /home/dcj/projects/third-64
GTEST_DIR = ${THIRD_64}/gtest

INCLUDES += -I$(GTEST_DIR)/include

LIBS += -L$(GTEST_DIR)/lib

CPPFLAGS += -g -Wall $(INCLUDES) $(LIBS)

CXXFLAGS += -lgtest -lpthread

TESTS = fac_test

all: $(TESTS)

func.o: func.h func.cpp
	$(CXX) $(CPPFLAGS) -o func.o -c func.cpp $(CXXFLAGS)

fac_test.o: fac_test.cpp
	$(CXX) $(CPPFLAGS) -o fac_test.o -c fac_test.cpp $(CXXFLAGS)

fac_test: func.o fac_test.o
	$(CXX) $(CPPFLAGS) -o fac_test fac_test.o func.o $(CXXFLAGS)

.PHONY:
clean:
	rm -f $(TESTS) *.o
