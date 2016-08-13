# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS= -std=c++11 -c -Wall -ggdb

all: EKTAppV2

EKTAppV2: btree.o classException.o ekt.o EKTAppV2.o exQueue.o nodeDL.o nodeSL.o testDriver.o word.o
	$(CC) -std=c++11 -Wall -ggdb classException.o ekt.o EKTAppV2.o exQueue.o testDriver.o word.o -o EKTAppV2
#note ignore btree.o and node.o from compile line otherwise compile will break

#templated
btree.o: btree.h
	$(CC) $(CFLAGS) btree.h

classException.o: classException.h classException.cpp
	$(CC) $(CFLAGS) classException.cpp

ekt.o: ekt.cpp ekt.h
	$(CC) $(CFLAGS) ekt.cpp

EKTAppV2.o: EKTAppV2.cpp
	$(CC) $(CFLAGS) EKTAppV2.cpp

exQueue.o: exQueue.h exQueue.cpp
	$(CC) $(CFLAGS) exQueue.cpp

#templated
nodeDL.o: nodeDL.h
	$(CC) $(CFLAGS) nodeDL.h

#templated
nodeSL.o: nodeSL.h
	$(CC) $(CFLAGS) nodeSL.h

#queue.o: queue.cpp queue.h
#$(CC) $(CFLAGS) queue.cpp

testDriver.o: testDriver.h testDriver.cpp
	$(CC) $(CFLAGS) testDriver.cpp

word.o: word.h word.cpp
	$(CC) $(CFLAGS) word.cpp

clean:
	rm *.o *.h.gch EKTAppV2
