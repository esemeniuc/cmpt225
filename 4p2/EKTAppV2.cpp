#include <iostream>
#include "testDriver.h"
#include "ekt.h"

using namespace std;

int main(int argc, char* argv[])
{
//	testDriver testDriver1;
//	testDriver1.testAllNonException();
	
	cout << "Hello, World!" << endl;
	
	ekt userEKT;
	
	//load data into tree
	btree <word> dataBtree;
	userEKT.dictLoader("dataFile.txt", &dataBtree);
	
	//dumps out the contents of the tree and ends if in display mode
	if (argc == 2 && std::string(argv[1]) == "display")
	{
		dataBtree.print(); //print out all contents of btree
		return 0; //all done, no need to continue running
	}

//	cout << "Tree contents:" << endl;
//	dataBtree.print();
	
	exQueue userInputQueue; //store user input here
	userEKT.userInputLoader(&userInputQueue);

	while (userInputQueue.getSize() > 0)
	{
		word tempSearchTerm = word(userInputQueue.pop()); //get stuff on the top
		//userInputQueue.dequeue(); //decrement
		word tempResult = dataBtree.search(&tempSearchTerm);
		
		if (tempResult.size() == 0) //check if empty object is returned
		{
			//then mash together the tempSearchTerm src field with <not found>
			word printWord(tempSearchTerm.getSrc(), "<not found>");
			printWord.print();
		}
		else
		{
			tempResult.print();
		}
	}

//	for(int i = 0; i < 10; i++)
//	{
//		userInputQueue.push(std::to_string(i));
//
//	}
//	userInputQueue.print();
//
//	userInputQueue.randomize();
//	userInputQueue.print();
//	for(int i = 0; i < 5; i++)
//	{
//		cout << userInputQueue.pop() << endl;
//	}
}