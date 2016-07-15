/*
 * filename: EKTApp.cpp
 *
 * Description: A file, with a main that tests the other components specified in the Makefile.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

// TODO:
// Put all files into templates.
// Reconfirm whether we should print all translation in a row, or "As our EKTApp reads the English words entered,
// it finds and retrieves their Klingon translations, then prints them on the computer monitor screen as follows."
// UML Diagram!!!
// Remove debug commenting -- http://i2.kym-cdn.com/photos/images/original/000/128/418/ea0.jpg
// Add more commenting to where it's needed. - Contact me (David) if needed.


#include <iostream> //for printing
#include <fstream> //for file input
#include <algorithm> //for lowercase
#include "btree.h"
#include "queue.h"

using namespace std;

void dictLoader(string inputFilename, btree* inputBtree)
{
	ifstream inputFile;
	inputFile.open(inputFilename, ios::in); //set to read as input mode only
	if (inputFile.is_open()) //check if file is available
	{
		string tempString; //temporary holding string to save result
		while(inputFile.eof() == 0) //while not reaching eof
		{
			getline(inputFile, tempString);
			uint64_t length = tempString.find(':', 1); //use uint64_t because find returns long ints
			string tempSrc = tempString.substr(0, length);
			string tempDest = tempString.substr(length+1, tempString.length());
			std::transform(tempSrc.begin(), tempSrc.end(), tempSrc.begin(), ::tolower); //make things lowercase
//			cout << "src: " << tempSrc << " dest: " << tempDest << endl; //debug
//			cout << tempDest << endl; //debug
			
			inputBtree->insert(word(tempSrc, tempDest)); //insert the new word
		}
	}
	
	inputFile.close();
}

void userInputLoader(queue* inputQueue)
{
	//keep taking user input until EOF
	string tempString; //temporary holder for cin input
	while(cin >> tempString) //load data into variable until we hit EOF
	{
		//cout << "Input #" << currentInputCount << ": Time = " << tempTime < << endl; //debug
		inputQueue->enqueue(tempString); //insert our new string into the queue
	}
//	inputQueue->print();
}

int main(int argc, char* argv[])
{
	//load data into tree
	btree dataBtree;
	dictLoader("dataFile.txt", &dataBtree);
	
	//dumps out the contents of the tree and ends if in display mode
	if(argc == 2 && std::string(argv[1]) == "display")
	{
		dataBtree.print(); //print out all contents of btree
		return 0; //all done, no need to continue running
	}

//	cout << "Tree contents:" << endl;
//	dataBtree.print();
	
	queue userInputQueue; //store user input here
	userInputLoader(&userInputQueue);
	
//	string poptest1 = userInputQueue.peek();
//	userInputQueue.dequeue();
//	string poptest2 = userInputQueue.peek();
//
//	cout << poptest1 << endl;
//	cout << poptest2 << endl;

	while(userInputQueue.isEmpty() == 0)
	{
		word tempSearchTerm = word(userInputQueue.peek()); //get stuff on the top
		userInputQueue.dequeue(); //decrement
		word tempResult = dataBtree.search(&tempSearchTerm);
		tempResult.print();
	}

	userInputQueue.print();
	
}