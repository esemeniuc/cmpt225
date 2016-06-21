# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall -ggdb

all: bsApp

bsApp: BankSimApp.o Event.o Queue.o PQueue.o Node.o EmptyDataCollectionException.o
	$(CC) BankSimApp.o Event.o Queue.o PQueue.o Node.o EmptyDataCollectionException.o -o bsApp
bsApp2: BankSimApp.o Event.o Queue.o PQueue2.o Node.o EmptyDataCollectionException.o
	$(CC) BankSimApp.o Event.o Queue.o PQueue2.o Node.o EmptyDataCollectionException.o -o bsApp

debug: Debug.o Event.o Queue.o PQueue.o Node.o EmptyDataCollectionException.o
	$(CC) Debug.o Event.o Queue.o PQueue.o Node.o EmptyDataCollectionException.o -o debug

BankSimApp.o: BankSimApp.cpp
	$(CC) $(CFLAGS) BankSimApp.cpp

Debug.o: Debug.cpp
	$(CC) $(CFLAGS) Debug.cpp

Event.o: Event.h Event.cpp
	$(CC) $(CFLAGS) Event.cpp

Queue.o: Queue.h Queue.cpp
	$(CC) $(CFLAGS) Queue.cpp

Queue2.o: Queue2.h Queue2.cpp
	$(CC) $(CFLAGS) Queue2.cpp

PQueue2.o: PQueue2.h PQueue2.cpp
	$(CC) $(CFLAGS) PQueue2.cpp

PQueue.o: PQueue.h PQueue.cpp
	$(CC) $(CFLAGS) PQueue.cpp

Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) Node.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	$(CC) $(CFLAGS) EmptyDataCollectionException.cpp

clean:
	rm -f *.o bsApp debug
