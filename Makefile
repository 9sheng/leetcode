.SUFFIXES: .exe .o .cpp

CC   = g++
CPPS = $(shell ls *[0-9]*.cpp)
EXES = $(CPPS:.cpp=.exe)

.PHONY: all
all: $(EXES) $(OBJS) 

%.exe: %.o
	$(CC) -Wall -Werror -Wno-unused -std=c++0x -g -o $@ $+

%.o: %.cpp
	$(CC) -std=c++0x -g -c $<

clean:
	rm -rf *.exe *.o
