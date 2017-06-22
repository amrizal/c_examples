CC = gcc
CFLAGS  = -g -Wall

default: all

rebuild: clean all

all:  util.o runner1.o runner2.o main.o 
	$(CC) $(CFLAGS) util.o runner1.o runner2.o main.o -lpthread

main.o:  main.c 
	$(CC) $(CFLAGS) -c main.c

runner1.o:  runner1.c
	$(CC) $(CFLAGS) -c runner1.c

runner2.o:  runner2.c
	$(CC) $(CFLAGS) -c runner2.c

util.o:	util.c
	$(CC) $(CFLAGS) -c util.c

clean: 
	$(RM)  *.o *~
