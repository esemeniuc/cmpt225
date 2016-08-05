all: bsttd

bsttd: Test_Driver.o BST.o Node.o
	g++ -o bsttd Test_Driver.o BST.o Node.o

# Note, this makefile is very strong in terms of dependencies.
# It assumes most classes can depend on others, just to be safe.
# This results in much redundant compilation, and one could remove some of these dependencies.

Test_Driver.o: Test_Driver.cpp BST.h Node.h
	g++ -c Test_Driver.cpp

BST.o: BST.cpp BST.h Node.h
	g++ -c BST.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f bsttd *.o