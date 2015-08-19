.SUFFIXES: .exe .o .cpp

CC   = clang++
CPPS = $(shell ls [1-9]*.cpp)
EXES = $(CPPS:.cpp=.exe)

all : $(EXES)

%.exe : %.o testharness.o
	$(CC) -Wall -Werror -Wno-unused -std=c++0x -g -o $@ $+ || true

%.o : %.cpp
	$(CC) -std=c++0x -g -c $<

clean:
	rm -rf *.exe *.o
