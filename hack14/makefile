#
# makefile for image and color utilities C library
#
#

CC = gcc -std=gnu99
FLAGS = -Wall
INCLUDES = -lm


airportTester: transaction.o transactionReport.c
	$(CC) $(FLAGS) transaction.o transactionReport.c -o transactionReport $(INCLUDES)

airport.o: transaction.c transaction.h
	$(CC) $(FLAGS) $(INCLUDES) -c transaction.c -o transaction.o

clean:
	rm -f *~ *.o
