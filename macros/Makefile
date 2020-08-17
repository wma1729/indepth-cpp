DBG     = -O
CFLAGS  = -c -Wall

OBJS   = enum.o

EXES   = enum

all: ${EXES}

enum: enum.cpp
	g++ -Wall ${DBG} $^ -o $@

clean:
	/bin/rm -rf ${OBJS} ${EXES} core.*
