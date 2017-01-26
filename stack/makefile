PHONY: clean all

CXX= g++
CPPFLAGS= -g -std=c++11

TARGETS= teststack

all: teststack

%.o : %.cpp
		$(CXX) -c $@.cpp     $<
		
teststack.o : teststack.cpp
			$(CXX) $(CPPFLAGS) -c teststack.cpp $<

teststack: teststack.o
			$(CXX) $(CPPFLAGS) -o teststack teststack.o

clean: 
	rm -f *.o $(TARGETS)
	
run:
	./teststack 10
