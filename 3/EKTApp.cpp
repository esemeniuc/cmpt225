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

//todo: lowercase input
//randomize, but later

#include <iostream>
#include <fstream>
#include "btree.h"
#include <algorithm>

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


int main(int argc, char* argv[])
{
	//load data into tree
	btree testbtree;
	dictLoader("dataFile.txt", &testbtree);
	
	if(argc == 2 && std::string(argv[1]) == "display") //dumps out the contents of the tree and ends if in display mode
	{
		testbtree.print();
		return 0; //all done, no need to continue running
	}
	
	cout << "Tree contents:" << endl;
	testbtree.print();

}