CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g
DEPS = symbol.h
OBJS = symbol.o

all: $(OBJS) $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@ 

clean: 
	$(RM) *.o