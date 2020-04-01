CC = gcc
CFLAGS += -g
PROG = HexToLinklist
INC = -I /Driver/Bus/
SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}

${PROG}: ${OBJS}
	${CC} ${OBJS} -o ${PROG}

clean:
	rm *.o
