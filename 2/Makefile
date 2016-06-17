# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall

all: BankSimApp

BankSimApp: BankSimApp.o Event.o Queue.o PQueue.o Node.o EmptyDataCollectionException.o
	$(CC) BankSimApp.o Event.o Queue.o PQueue.o Node.o EmptyDataCollectionException.o -o BankSimApp

Debug: Debug.o Event.o Queue.o PQueue.o Node.o EmptyDataCollectionException.o
	$(CC) Debug.o Event.o Queue.o PQueue.o Node.o EmptyDataCollectionException.o -o Debug

BankSimApp.o: BankSimApp.cpp
	$(CC) $(CFLAGS) BankSimApp.cpp

Debug.o: Debug.cpp
	$(CC) $(CFLAGS) Debug.cpp

Event.o: Event.h Event.cpp
	$(CC) $(CFLAGS) Event.cpp

Queue.o: Queue.h Queue.cpp
	$(CC) $(CFLAGS) Queue.cpp

PQueue.o: PQueue.h PQueue.cpp
	$(CC) $(CFLAGS) PQueue.cpp

Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) Node.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	$(CC) $(CFLAGS) EmptyDataCollectionException.cpp

clean:
	rm -f *.o BankSimApp Debug
