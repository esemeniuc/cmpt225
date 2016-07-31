/*
 * filename: EKTApp.cpp
 *
 * Description: An english klingon translator class
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

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

//preconditions: inputFilename is not empty
//postconditions: returns 0 on successful read from file, 1 if there is an error
//description: reads in english klingon translations in the from of english:klingon
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

//preconditions: none
//postconditions: none
//description: prints out all the available words for translation
void ekt::display(void) const
{
	dataBtree.print();
}

//preconditions: none
//postconditions: none
//description: generates a hash based on inputInteger and returns it in O(1) time
size_t ekt::hashInteger(uint32_t inputInteger, size_t modulus) const
{
	//h(k) = k(k+3) mod m from https://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
	uint64_t hashVal = inputInteger * (inputInteger + 3);
	hashVal %= modulus;
	
	return (size_t)hashVal;
}

//preconditions: none
//postconditions: none
//description: generates a hash based on inputString and returns it in O(1) time
size_t ekt::hashString(std::string inputString, size_t modulus) const
{
	uint64_t hashVal = 0;
	
	size_t index = 0;
	while(inputString[index] != '\0')
	{
		hashVal += (index + 1) * inputString[index];
	}
	
	hashVal %= modulus; //shrink to new range
	
	return (size_t)hashVal;
}

size_t ekt::hashString2(std::string inputString, size_t modulus) const
{
	uint64_t hashVal = 5381;
	int c;
	for(int i = 0; i < inputString.length(); ++i)
	{
		c = (int) inputString[i];
		hashVal = ((hashVal << 5) + hashVal) + c;
	}
	return (size_t)hashVal;
}

