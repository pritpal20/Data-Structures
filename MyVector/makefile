PHONY: clean all

CXX= g++
CPPFLAGS= -g -std=c++11

TARGETS= testVector

all: testVector

%.o : %.cpp
		$(CXX) -c $@.cpp     $<
		
testVector.o : testVector.cpp
			$(CXX) $(CPPFLAGS) -c testVector.cpp $<

testVector: testVector.o
			$(CXX) $(CPPFLAGS) -o testVector testVector.o

clean: 
	rm -f *.o $(TARGETS)
	
run:
	./testVector 10
