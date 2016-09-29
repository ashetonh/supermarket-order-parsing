CC = g++
DEBUG = -g -O0 -pedantic-errors
CFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)


all: p1

p1: p1.o Order.o Queue.o Stack.o
	$(CC) $(LFLAGS) -o p1 p1.o Order.o Queue.o Stack.o

p1.o: p1.cpp Order.h LinkedList.h Queue.h Stack.h SuperMarket.h
	$(CC) $(CFLAGS) p1.cpp

Stack.o: Stack.cpp Stack.h
	$(CC) $(CFLAGS) Stack.cpp

Queue.o: Queue.cpp Queue.h
	$(CC) $(CFLAGS) Queue.cpp

Order.o: Order.cpp Order.h
	$(CC) $(CFLAGS) Order.cpp


run: ./p1 input.txt
	./p1 input.txt

.PHONY: clean

clean: 
	rm -rf *.o
	rm -rf p1