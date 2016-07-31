/*
 * filename: EKTApp.cpp
 *
 * Description: An english klingon translator class
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#include <iostream> //for printing
#include <fstream> //for file input
#include <algorithm> //for lowercase
#include "ekt.h"

ekt::ekt()
{
	//load data into tree
	btree<word> dataBtree;
}

ekt::~ekt()
{
	
}

//0 on success, 1 on failure
uint8_t ekt::loadFromFile(std::string inputFilename)
{
	uint8_t status = 1; //default to fail
	
	std::ifstream inputFile;
	inputFile.open(inputFilename, std::ios::in); //set to read as input mode only
	if (inputFile.is_open()) //check if file is available
	{
		std::string tempString; //temporary holding string to save result
		while(inputFile.eof() == 0) //while not reaching eof
		{
			getline(inputFile, tempString);
			uint64_t length = tempString.find(':', 1); //use uint64_t because find returns long ints
			std::string tempSrc = tempString.substr(0, length);
			std::string tempDest = tempString.substr(length+1, tempString.length());
			std::transform(tempSrc.begin(), tempSrc.end(), tempSrc.begin(), ::tolower); //make things lowercase
			//cout << "src: " << tempSrc << " dest: " << tempDest << endl; //debug
			
			//add randomize function here
			dataBtree.insert(word(tempSrc, tempDest)); //insert the new word. Note: this is client code, no need to template
		}
		status = 0; //all good
	}
	
	inputFile.close();
	return status;
}


void ekt::translate(void)
{
	//keep taking user input until EOF
	std::string tempString; //temporary holder for cin input
	while(std::cin >> tempString) //load data into variable until we hit EOF
	{
		userInputQueue.push(tempString); //insert our new string into the queue
	}
//	userInputQueue.print(); //debug
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
}

//void ekt::dictLoader(std::string inputFilename, btree<word>* inputBtree)
//{
//	std::ifstream inputFile;
//	inputFile.open(inputFilename, std::ios::in); //set to read as input mode only
//	if (inputFile.is_open()) //check if file is available
//	{
//		std::string tempString; //temporary holding string to save result
//		while(inputFile.eof() == 0) //while not reaching eof
//		{
//			getline(inputFile, tempString);
//			uint64_t length = tempString.find(':', 1); //use uint64_t because find returns long ints
//			std::string tempSrc = tempString.substr(0, length);
//			std::string tempDest = tempString.substr(length+1, tempString.length());
//			std::transform(tempSrc.begin(), tempSrc.end(), tempSrc.begin(), ::tolower); //make things lowercase
//			//cout << "src: " << tempSrc << " dest: " << tempDest << endl; //debug
//
//			//add randomize function here
//			inputBtree->insert(word(tempSrc, tempDest)); //insert the new word. Note: this is client code, no need to template
//		}
//	}
//
//	inputFile.close();
//}
//
//void ekt::userInputLoader(exQueue* inputQueue)
//{
//	//keep taking user input until EOF
//	std::string tempString; //temporary holder for cin input
//	while(std::cin >> tempString) //load data into variable until we hit EOF
//	{
//		//cout << "Input #" << currentInputCount << ": Time = " << tempTime < << endl; //debug
//		inputQueue->push(tempString); //insert our new string into the queue
//	}
////	inputQueue->print();
//}

void ekt::display(void) const
{
	dataBtree.print();
}
