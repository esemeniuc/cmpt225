# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++-6
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS= -std=c++11 -c -Wall -ggdb

all: EKTAppV2

EKTAppV2: btree.o classException.o ekt.o EKTAppV2.o exQueue.o node.o word.o
	$(CC) -std=c++11 -Wall -ggdb classException.o ekt.o EKTAppV2.o exQueue.o word.o -o EKTAppV2
#note ignore btree.o and node.o from compile line otherwise compile will break

#templated
btree.o: btree.h
	$(CC) $(CFLAGS) btree.h

classException.o: classException.cpp classException.h
	$(CC) $(CFLAGS) classException.cpp

ekt.o: ekt.cpp ekt.h
	$(CC) $(CFLAGS) ekt.cpp

EKTAppV2.o: EKTAppV2.cpp
	$(CC) $(CFLAGS) EKTAppV2.cpp

exQueue.o: exQueue.cpp exQueue.h
	$(CC) $(CFLAGS) exQueue.cpp

#templated
node.o: node.h
	$(CC) $(CFLAGS) node.h

#queue.o: queue.cpp queue.h
#$(CC) $(CFLAGS) queue.cpp

word.o: word.cpp word.h
	$(CC) $(CFLAGS) word.cpp

clean:
	rm *.o *.h.gch EKTAppV2