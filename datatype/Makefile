DBG     = -O
CFLAGS  = -c

OBJS   = integer.o

EXES   = integer

all: ${EXES}

integer: integer.cpp
	g++ ${DBG} $^ -o $@

clean:
	/bin/rm -rf ${OBJS} ${EXES} core.*
