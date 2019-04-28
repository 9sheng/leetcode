.SUFFIXES: .exe .o .cpp

CC   = g++
CPPS = $(shell ls *[0-9]*.cpp)
EXES = $(CPPS:.cpp=.exe)
OBJS = $(CPPS:.cpp=.o)

.PHONY: all
all: $(EXES) $(OBJS) 

%.exe: %.o testharness.o
	$(CC) -Wall -Werror -Wno-unused -std=c++0x -g -o $@ $+ || true

%.o: %.cpp
	$(CC) -std=c++0x -g -c $<

clean:
	rm -rf *.exe *.o
