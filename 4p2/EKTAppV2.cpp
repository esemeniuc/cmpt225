/*
* Description: Driver/main function for ekt class
* Creation date: July 21, 2016
* Author: Eric Semeniuc, David Magaril
* ID: esemeniu_dmagaril
*/

#include <iostream> //for debug
#include "testDriver.h"
#include "ekt.h"

int main(int argc, char* argv[])
{
	//debug stuff
//	testDriver testDriver1;
//	testDriver1.testAllNonException();
//	std::cout << "Hello, World!" << std::endl;
	
	ekt userEKT; //make ekt object
	userEKT.loadFromFile("dataFile.txt");
//	std::cout << "Tree contents:" << std::endl;
//	userEKT.display();
	
	//dumps out the contents of the tree and ends if in display mode
	if (argc == 2 && std::string(argv[1]) == "display")
	{
		userEKT.display(); //print out all contents of btree
		return 0; //all done, no need to continue running
	}
	
	userEKT.translate(); //call up translation prompt
}