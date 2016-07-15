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
			cout << "src: " << tempSrc << " dest: " << tempDest << endl; //debug
			
			//word inputWord = ; //make a word object
			inputBtree->insert(word(tempSrc, tempDest)); //insert the new word
		}
	}
	
	inputFile.close();
}


int main(int argc, char* argv[])
{
	//load data into tree
	
	//receive input words from user and store the input into queue until eof is reached
	
	
	//process the queue by popping each element from the queue
	//and calling btree.getDest() to print out the corresponding word pair

//	word testword = word("tom2", "bob");
//	word testword2 = word("tom3", "albert");
//	word testword3 = word();
//	word testword4 = word("rob", "");
//
//	if (testword < testword2)
//	{
//		cout << "less" << endl;
//	}
//	else
//	{
//		cout << "greater" << endl;
//	}
//
//	cout << "1: " << (unsigned int)testword.isEmpty() << endl;
//	cout << "2: " << (unsigned int)testword2.isEmpty() << endl;
//	cout << "3: " << (unsigned int)testword3.isEmpty() << endl;
//	cout << "4: " << (unsigned int)testword4.isEmpty() << endl;
	
	btree testbtree; //testing on heap for now
	dictLoader("dataFile.txt", &testbtree);

//	word testword1 = word("aaaa1", "zzzz1");
//	word testword2 = word("aaaa3", "zzzz3");
//	word testword3 = word("bbb2", "yyy2");
//	word testword4 = word("aaaa2", "zzzz2");
//	testbtree.insert(testword1);
//	testbtree.insert(testword2);
//	testbtree.insert(testword3);
//	testbtree.insert(testword4);
//
//	word searchword1 = word("aaaa1");
//	word searchresult1 = testbtree.search(&searchword1);
//	cout << "Retrieving searchword1 contents:" << endl;
//	searchresult1.print();
//	cout << endl;
//
//	word searchword2 = word("aaaa3");
//	word searchresult2 = testbtree.search(&searchword2);
//	cout << "Retrieving searchword2 contents:" << endl;
//	searchresult2.print();
//	cout << endl;
//
//	word searchword3 = word("bbb2");
//	word searchresult3 = testbtree.search(&searchword3);
//	cout << "Retrieving searchword3 contents:" << endl;
//	searchresult3.print();
//	cout << endl;
//
//	word searchword4 = word("aaaa2");
//	word searchresult4 = testbtree.search(&searchword4);
//	cout << "Retrieving searchword4 contents:" << endl;
//	searchresult4.print();
//	cout << endl;
	
	
	std::string tempStringArray[5]; //have 5 random things to shuffle
	random_shuffle(tempStringArray[0], tempStringArray[4]);
	
	bool displayMode = false;
	if(std::string(argv[1]) == "display") //dumps out the contents of the tree
	{
		displayMode = true;
		testbtree.print();
		return 0; //all done
	}
	
	
	cout << "Tree contents:" << endl;
	testbtree.print();
	
	return 0;
}