# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++-6
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS= -std=c++11 -c -Wall -ggdb

all: EKTApp

EKTApp: EKTApp.o btree.o node.o exQueue.o word.o ClassException.o
	$(CC) -std=c++11 -Wall -ggdb EKTApp.o exQueue.o word.o ClassException.o -o EKTApp

EKTApp.o: EKTApp.cpp
	$(CC) $(CFLAGS) EKTApp.cpp

#templated
btree.o: btree.h
	$(CC) $(CFLAGS) btree.h

#templated
node.o: node.h
	$(CC) $(CFLAGS) node.h

exQueue.o: exQueue.cpp exQueue.h
	$(CC) $(CFLAGS) exQueue.cpp

#queue.o: queue.cpp queue.h
#$(CC) $(CFLAGS) queue.cpp

word.o: word.cpp word.h
	$(CC) $(CFLAGS) word.cpp

ClassException.o: ClassException.cpp ClassException.h
	$(CC) $(CFLAGS) ClassException.cpp

clean:
	rm *.o *.h.gch EKTApp