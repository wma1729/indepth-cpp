DBG     = -O
CFLAGS  = -c

OBJS   = integer.o real.o

EXES   = integer real

all: ${EXES}

integer: integer.cpp
	g++ ${DBG} $^ -o $@

real: real.cpp
	g++ ${DBG} $^ -o $@

clean:
	/bin/rm -rf ${OBJS} ${EXES} core.*
