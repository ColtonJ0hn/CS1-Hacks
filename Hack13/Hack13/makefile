#
# makefile for image and color utilities C library
#
#

CC = gcc -std=gnu99
FLAGS = -Wall
INCLUDES = -lm


airportTester: airport.o airportReport.c
	$(CC) $(FLAGS) airport.o airportReport.c -o airportreport $(INCLUDES)

airport.o: airport.c airport.h
	$(CC) $(FLAGS) $(INCLUDES) -c airport.c -o airport.o

clean:
	rm -f *~ *.o
