#
# makefile for strings utilities C library
#
#

CC = gcc -std=gnu99
FLAGS = -Wall
INCLUDES = -lm


stringTester: string_utils.o stringTester.c
	$(CC) $(FLAGS) string_utils.o stringTester.c -o stringTester $(INCLUDES)

string_utils.o: string_utils.c string_utils.h
	$(CC) $(FLAGS) $(INCLUDES) -c string_utils.c -o string_utils.o

clean:
	rm -f *~ *.o
