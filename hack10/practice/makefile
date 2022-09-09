#
# makefile for strings utilities C library
#
#

CC = gcc -std=gnu99
FLAGS = -Wall
INCLUDES = -lm


tester: file_utils.o tester.c
	$(CC) $(FLAGS) file_utils.o tester.c -o tester $(INCLUDES)

file_utils.o: file_utils.c file_utils.h
	$(CC) $(FLAGS) $(INCLUDES) -c file_utils.c -o file_utils.o

clean:
	rm -f *~ *.o
