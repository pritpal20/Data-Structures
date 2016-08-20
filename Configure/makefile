CC=g++
CXX=CC
CCFLAGS= -g -w -Wall -Werror -std=c++11

TARGETS=main

OBJECTS=main.o configure.o

all: $(TARGETS)

%.o : %.cpp 
	$(CC) -c $(CCFLAGS)  	$<

$(TARGETS):$(OBJECTS)
	$(CC) $(CCFLAGS) -o $@ $(OBJECTS)
	
	
clean: 
	rm -f $(TARGETS) $(OBJECTS)
	
list:
	ls -ltr --color=auto
