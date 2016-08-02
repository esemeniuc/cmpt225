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
#include <cmath> //for pow() in std dev
#include "ekt.h"

/*private:
	btree<word> dataBtree; //store translations here
	exQueue userInputQueue; //store file input translations or user input here
	nodeSL<word>** wordTable; //hashtable for word entries
	size_t wordCount; //number of successfully added words in ekt
	size_t modulus; //modulus for wordTable
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
	uint64_t hashVal = 5381;
	int c;
	for(size_t i = 0; i < inputString.length(); ++i)
	{
		c = (int)inputString[i];
		hashVal = ((hashVal << 5) + hashVal) + c;
	}
	return (size_t)(hashVal % modulus);
}

size_t ekt::hashStringBad(std::string inputString) const
{
	uint64_t hashVal = 0;
	
	size_t index = 0;
	while(inputString[index] != '\0')
	{
		hashVal += (index + 1) * inputString[index];
		index++;
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
	//make our hash table to point to word
	wordTable = new nodeSL<word>*[modulus](); //() means initialize to NULL objects
	
	for(size_t i = 0; i < fileInputSize; i++)
	{
		tempString = fileInputQueue.pop();
		
		//string transformation stuff
		uint64_t length = tempString.find(':', 1); //use uint64_t because find returns long ints
		std::string tempSrc = tempString.substr(0, length);
		std::string tempDest = tempString.substr(length+1, tempString.length());
		std::transform(tempSrc.begin(), tempSrc.end(), tempSrc.begin(), ::tolower); //make things lowercase
		//cout << "src: " << tempSrc << " dest: " << tempDest << endl; //debug
		if(insert(word(tempSrc, tempDest)) == 0) //if successfully inserted
		{
			wordCount++; //increment count
		}
	}

	inputFile.close();
	return 0; //all good
}

//preconditions: inputWord is not empty
//postconditions: returns 0 on insertion, 1 if there is an error
//description: inserts word objects into the btree and hashtable
uint8_t ekt::insert(const word& inputWord)
{
	//begin chaining by getting the memory address of the object inserted into the btree;
	nodeDL<word>* insertedNodeAddress = dataBtree.insert(inputWord); //insert the new word
	if(insertedNodeAddress == nullptr)
	{
		return 1; //fail, can't insert with null
	}
	
	word* wordAddress = &(insertedNodeAddress->data);
	size_t hashIndex = hashString(inputWord.getSrc()); //hashString1 not working...
//	std::cout << hashIndex << "\n\n";
	wordTable[hashIndex] = new nodeSL<word>(wordAddress, wordTable[hashIndex]); //make a node to insert at front of list and set the new node into the hashtable
	
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

//preconditions: none
//postconditions: returns the standard deviation of the length of each chain in the hash table
//description: gets
double ekt::getStdDev(void) const
{
	//get the length of each chain from the hash table and store them in an array of length modulus
	double tempArray[modulus];
	
	//store length of each chain into tempArray
	for(size_t i = 0; i < modulus; i++)
	{
		size_t chainLength = 0;
		nodeSL<word>* current = wordTable[i];
		while(current != NULL)
		{
			chainLength++;
			current = current->next;
		}
		
		tempArray[i] = chainLength;
	}
	
	//get the average length of each chain
	double runningTotal = 0;
	for(size_t i = 0; i < modulus; i++)
	{
		runningTotal += tempArray[i];
	}
	double avg = runningTotal/modulus;
	
	double sumOfSquares = 0;
	for(size_t i = 0; i < modulus; i++) //sum up (x(i) - x(bar))^2
	{
		sumOfSquares += pow((tempArray[i] - avg), 2); //get the sum of square
	}
	
	double sigma = pow((sumOfSquares / modulus), 0.5); //divide by n
	
	return sigma;
}