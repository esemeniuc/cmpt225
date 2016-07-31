# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++-6
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS= -std=c++11 -c -Wall -ggdb

all: EKTApp

EKTApp: EKTAppV2.o btree.o node.o exQueue.o word.o classException.o
	$(CC) -std=c++11 -Wall -ggdb EKTAppV2.o exQueue.o word.o classException.o -o EKTAppV2

EKTAppV2.o: EKTAppV2.cpp
	$(CC) $(CFLAGS) EKTAppV2.cpp

#templated
btree.o: btree.h
	$(CC) $(CFLAGS) btree.h

#templated
node.o: node.h
	$(CC) $(CFLAGS) node.h

exQueue.o: exQueue.cpp exQueue.h
	$(CC) $(CFLAGS) exQueue.cpp

ekt.o: ekt.cpp ekt.h
	$(CC) $(CFLAGS) ekt.cpp

#queue.o: queue.cpp queue.h
#$(CC) $(CFLAGS) queue.cpp

word.o: word.cpp word.h
	$(CC) $(CFLAGS) word.cpp

classException.o: classException.cpp classException.h
	$(CC) $(CFLAGS) classException.cpp

clean:
	rm *.o *.h.gch EKTAppV2