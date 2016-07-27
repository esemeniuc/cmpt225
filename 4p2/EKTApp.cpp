/*
 * filename: EKTApp.cpp
 *
 * Description: A file with a main that creates the English - Klingon Translator
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
#include "fifostack.h"
#include "word.h"

using namespace std;

template <class Type>
void dictLoader(string inputFilename, btree<Type>* inputBtree)
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
			//cout << "src: " << tempSrc << " dest: " << tempDest << endl; //debug
			
			//add randomize function here
			inputBtree->insert(word(tempSrc, tempDest)); //insert the new word. Note: this is client code, no need to template
		}
	}
	
	inputFile.close();
}

void userInputLoader(fifostack* inputQueue)
{
	//keep taking user input until EOF
	string tempString; //temporary holder for cin input
	while(cin >> tempString) //load data into variable until we hit EOF
	{
		//cout << "Input #" << currentInputCount << ": Time = " << tempTime < << endl; //debug
		inputQueue->push(tempString); //insert our new string into the queue
	}
//	inputQueue->print();
}

int main(int argc, char* argv[])
{
	//load data into tree
	btree<word> dataBtree;
	dictLoader("dataFile.txt", &dataBtree);
	
	//dumps out the contents of the tree and ends if in display mode
	if(argc == 2 && std::string(argv[1]) == "display")
	{
		dataBtree.print(); //print out all contents of btree
		return 0; //all done, no need to continue running
	}

//	cout << "Tree contents:" << endl;
//	dataBtree.print();
	
	fifostack userInputQueue; //store user input here
	userInputLoader(&userInputQueue);
	
//	string poptest1 = userInputQueue.peek();
//	userInputQueue.dequeue();
//	string poptest2 = userInputQueue.peek();
//
//	cout << poptest1 << endl;
//	cout << poptest2 << endl;

	while(userInputQueue.getSize() > 0)
	{
		word tempSearchTerm = word(userInputQueue.pop()); //get stuff on the top
		//userInputQueue.dequeue(); //decrement
		word tempResult = dataBtree.search(&tempSearchTerm);
		
		if(tempResult.size() == 0) //check if empty object is returned
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
//	userInputQueue.randomizefifostack();
//	userInputQueue.print();
//	for(int i = 0; i < 5; i++)
//	{
//		cout << userInputQueue.pop() << endl;
//	}


	
}