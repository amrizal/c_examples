CC = gcc
CFLAGS  = -g -Wall

default: all

all:  runner1.o main.o 
	$(CC) $(CFLAGS) runner1.o main.o -lpthread

main.o:  main.c 
	$(CC) $(CFLAGS) -c main.c

runner1.o:  runner1.c
	$(CC) $(CFLAGS) -c runner1.c

clean: 
	$(RM)  *.o *~
