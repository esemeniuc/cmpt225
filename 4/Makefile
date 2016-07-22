# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++-6
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS= -std=c++11 -c -Wall -ggdb

all: muslaApp

muslaApp: main.o musla.o student.o university.o classException.o testDriver.o
	$(CC) -std=c++11 -Wall -ggdb main.o musla.o student.o university.o classException.o testDriver.o -o muslaApp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

musla.o: musla.cpp
	$(CC) $(CFLAGS) musla.cpp

student.o: student.cpp
	$(CC) $(CFLAGS) student.cpp

university.o: university.cpp
	$(CC) $(CFLAGS) university.cpp

classException.o: classException.cpp
	$(CC) $(CFLAGS) classException.cpp

testDriver.o: testDriver.cpp
	$(CC) $(CFLAGS) testDriver.cpp

clean:
	rm *.o muslaApp