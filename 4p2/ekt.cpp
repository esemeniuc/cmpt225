/*
 * filename: EKTApp.cpp
 *
 * Description: An english klingon translator class
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#include <iostream>
#include <fstream> //for file input
#include <algorithm> //for lowercase
#include "ekt.h"

/*private:
btree<word> dataBtree; //store translations here
exQueue userInputQueue; //store translations or user input here
*/

ekt::ekt()
{
	//nothing else to do
}

ekt::~ekt()
{
	//nothing else to do
}

//preconditions: none
//postconditions: none
//description: generates a hash based on inputInteger and returns it in O(1) time
size_t ekt::hashInteger(uint32_t inputInteger) const
{
	//h(k) = k(k+3) mod m from https://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
	uint64_t hashVal = inputInteger * (inputInteger + 3);
	hashVal %= modulus;
	
	return (size_t)hashVal;
}

//preconditions: none
//postconditions: none
//description: generates a hash based on inputString and returns it in O(1) time
size_t ekt::hashString(std::string inputString) const
{
	uint64_t hashVal = 0;
	
	size_t index = 0;
	while(inputString[index] != '\0')
	{
		hashVal += (index + 1) * inputString[index];
	}
	
	return (size_t)(hashVal % modulus);
}

size_t ekt::hashString2(std::string inputString) const
{
	uint64_t hashVal = 5381;
	int c;
	for(size_t i = 0; i < inputString.length(); ++i)
	{
		c = (int) inputString[i];
		hashVal = ((hashVal << 5) + hashVal) + c;
	}
	return (size_t)(hashVal % modulus);
}

//preconditions: inputFilename is not empty
//postconditions: returns 0 on successful read from file, 1 if there is an error
//description: reads in english klingon translations in the from of english:klingon
uint8_t ekt::loadFromFile(std::string inputFilename)
{
	
	std::ifstream inputFile;
	inputFile.open(inputFilename, std::ios::in); //set to read as input mode only
	if (!inputFile.is_open()) //check if file is bad
	{
		return 1; //fail
	}
	
	std::string tempString; //temporary holding string to save result
	exQueue fileInputQueue;
	while(inputFile.eof() == 0) //keep reading until we reach eof
	{
		getline(inputFile, tempString);
		fileInputQueue.push(tempString); //load into our queue
	}
	
	fileInputQueue.randomize(); //randomize to guarantee O(log(n)) insertion later on
	size_t fileInputSize = fileInputQueue.getSize();
//	std::cout << fileInputSize << "\n\n";
	modulus = 2 * fileInputSize;
	wordTable = new nodeDL<word>*[modulus]; //make our hash table to point to word objects
	
	for(size_t i = 0; i < fileInputSize; i++)
	{
		tempString = fileInputQueue.pop();
		
		//string transform stuff
		uint64_t length = tempString.find(':', 1); //use uint64_t because find returns long ints
		std::string tempSrc = tempString.substr(0, length);
		std::string tempDest = tempString.substr(length+1, tempString.length());
		std::transform(tempSrc.begin(), tempSrc.end(), tempSrc.begin(), ::tolower); //make things lowercase
		//cout << "src: " << tempSrc << " dest: " << tempDest << endl; //debug
//		dataBtree.insert(word(tempSrc, tempDest));
		uint8_t insertStatus = insert(word(tempSrc, tempDest));
	}

	inputFile.close();
	return 0; //all good
}

//preconditions: inputWord is not empty
//postconditions: returns 0 on successful read from file, 1 if there is an error
//description: inserts word objects into the btree and hashtable
uint8_t ekt::insert(const word& inputWord)
{
	dataBtree.insert(inputWord); //insert the new word
	
	//note: get the memory address of the object in the btree;
	
	//begin chaining
	
	size_t hashIndex = hashString2(inputWord.getSrc()); //hashString1 not working....
//	std::cout << hashIndex << "\n\n";
	nodeDL<word>* current = wordTable[hashIndex]; //get the "head" of the linked list
//	while(current != NULL)
//	{
//		current = current->next;
//	}
//	word* wordAddress = dataBtree.insert(inputWord); //insert the new word
//	wordTable[hashIndex] = wordAddress; //set our hash index to store the memory address
	
	return 0; //all good
}

//preconditions: none
//postconditions: prints out klingon words based on user input
//description: creates an interactive prompt for user to enter words to be translated
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
		word searchResult = dataBtree.search(&tempSearchTerm);
		
		if (searchResult.size() == 0) //check if empty object is returned
		{
			//then mash together the tempSearchTerm src field with <not found>
			word emptyWord(tempSearchTerm.getSrc(), "<not found>");
			emptyWord.print();
		}
		else
		{
			searchResult.print();
		}
	}
}

//preconditions: none
//postconditions: none
//description: prints out all the available words for translation
void ekt::display(void) const
{
	dataBtree.print();
}