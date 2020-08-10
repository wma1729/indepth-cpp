DBG     = -O
CFLAGS  = -c

OBJS   = integer.o real.o realcomp.o

EXES   = integer real realcomp

all: ${EXES}

integer: integer.cpp
	g++ ${DBG} $^ -o $@

real: real.cpp
	g++ ${DBG} $^ -o $@

realcomp: realcomp.cpp
	g++ ${DBG} $^ -o $@

clean:
	/bin/rm -rf ${OBJS} ${EXES} core.*
