all: sltd

sltd: SomeList_Test_Driver.o SomeList.o Node.o
	g++ -o sltd SomeList_Test_Driver.o SomeList.o Node.o

# Note, this makefile is very strong in terms of dependencies.
# It assumes most classes can depend on others, just to be safe.
# This results in much redundant compilation, and one could remove some of these dependencies.

SomeList_Test_Driver.o: SomeList_Test_Driver.cpp SomeList.h Node.h
	g++ -c SomeList_Test_Driver.cpp

SomeList.o: SomeList.cpp SomeList.h Node.h
	g++ -c SomeList.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f sltd *.o