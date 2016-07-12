# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++-6
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS= -std=c++11 -c -Wall -ggdb

all: EKTApp

EKTApp: EKTApp.cpp btree.o node.o word.o
	$(CC) -std=c++11 -Wall -ggdb EKTApp.cpp btree.o node.o word.o -o EKTApp

btree.o: btree.cpp btree.h
	$(CC) $(CFLAGS) btree.cpp

node.o: node.cpp node.h
	$(CC) $(CFLAGS) node.cpp

word.o: word.cpp word.h
	$(CC) $(CFLAGS) word.cpp

clean:
	rm -r *.o EKTApp