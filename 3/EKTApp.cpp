#include <iostream>
#include <fstream>
#include "word.h" //debug
using namespace std;

void dictLoader(string inputFilename)
{
	
	string stringArray[100]; int i = 0;
	ifstream inputFile;
	inputFile.open(inputFilename, ios::in); //set to read as input mode only
	if (inputFile.is_open()) //check if file is available
	{
		string tempString; //temporary holding string to save result
		while(inputFile.eof() == 0) //while not reaching eof
		{
			//getline(inputFile, tempString);
			getline(inputFile, stringArray[i]);
			cout << "Input: " << stringArray[i] << endl;
			i++;
		}
	}
	
	
	
	inputFile.close();
}


int main()
{
	//load data into tree
	
	//receive input words from user and store the input into queue until eof is reached
	
	
	//process the queue by popping each element from the queue
	//and calling btree.getDest() to print out the corresponding word pair
	
	dictLoader("dataFile.txt");
	
	cout << "Hello, World!" << endl;
	
	word testword = word("tom2", "bob");
	word testword2 = word("tom3", "albert");
	word testword3 = word();
	word testword4 = word("rob", "");
	
	if (testword < testword2)
	{
		cout << "less" << endl;
	}
	else
	{
		cout << "greater" << endl;
	}
	
	cout << "1: " << (unsigned int)testword.isEmpty() << endl;
	cout << "2: " << (unsigned int)testword2.isEmpty() << endl;
	cout << "3: " << (unsigned int)testword3.isEmpty() << endl;
	cout << "4: " << (unsigned int)testword4.isEmpty() << endl;
	
	return 0;
}