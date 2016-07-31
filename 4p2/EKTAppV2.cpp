#include <iostream>
#include "testDriver.h"
#include "ekt.h"

int main(int argc, char* argv[])
{
//	testDriver testDriver1;
//	testDriver1.testAllNonException();
	
	std::cout << "Hello, World!" << std::endl;
	
	ekt userEKT;
	
//	std::cout << "Tree contents:" << std::endl;
//	userEKT.display();
	
	userEKT.loadFromFile("dataFile.txt");
	
	//dumps out the contents of the tree and ends if in display mode
	if (argc == 2 && std::string(argv[1]) == "display")
	{
		userEKT.display(); //print out all contents of btree
		return 0; //all done, no need to continue running
	}
	
	userEKT.translate(); //call up translation prompt

}