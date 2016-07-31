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


using namespace std;

void ekt::dictLoader(string inputFilename, btree<word>* inputBtree)
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

void ekt::userInputLoader(exQueue* inputQueue)
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

