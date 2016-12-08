PHONY: clean all

CXX= g++
CPPFLAGS= -g -std=c++14

TARGETS= testVector

all: testVector

%.o : %.cpp
		$(CXX) -c $@.cpp     $<
		
testVector.o : testVector.cpp
			$(CXX) -c testVector.cpp $<

testVector: testVector.o
			$(CXX) -o testVector testVector.o

clean: 
	rm -f *.o $(TARGETS) 
