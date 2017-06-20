CC = gcc
CFLAGS  = -g -Wall

default: all

rebuild: clean all

all:  runner1.o runner2.o main.o 
	$(CC) $(CFLAGS) runner1.o runner2.o main.o -lpthread

main.o:  main.c 
	$(CC) $(CFLAGS) -c main.c

runner1.o:  runner1.c
	$(CC) $(CFLAGS) -c runner1.c

runner2.o:  runner2.c
	$(CC) $(CFLAGS) -c runner2.c

clean: 
	$(RM)  *.o *~
