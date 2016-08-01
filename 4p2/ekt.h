/*
 * filename: EKTApp.cpp
 *
 * Description: An english klingon translator class
 * Creation date: July 31, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#ifndef INC_4P2_EKT_H
#define INC_4P2_EKT_H

#include "btree.h"
#include "exQueue.h"
#include "word.h"

class ekt
{
private:
	btree<word> dataBtree; //store translations here
	exQueue userInputQueue; //store file input translations or user input here
	word** wordTable; //hashtable for word entries
	
	//preconditions: none
	//postconditions: returns a hash index
	//description: generates a hash based on inputInteger and returns it in O(1) time
	size_t hashInteger(uint32_t inputInteger, size_t modulus) const;
	
	//preconditions: none
	//postconditions: returns a hash index
	//description: generates a hash based on inputString and returns it in O(1) time
	size_t hashString(std::string inputString, size_t modulus) const;
	
	//preconditions: none
	//postconditions: returns a hash index
	//description: generates a hash based on inputString and returns it in O(1) time
	size_t hashString2(std::string inputString, size_t modulus) const;


public:
	ekt();
	
	~ekt();
	
	//preconditions: inputFilename is not empty
	//postconditions: returns 0 on successful read from file, 1 if there is an error
	//description: reads in english klingon translations in the from of english:klingon
	uint8_t loadFromFile(std::string inputFilename);
	
	//preconditions: none
	//postconditions: prints out klingon words based on user input
	//description: creates an interactive prompt for user to enter words to be translated
	void translate(void);
	
	//preconditions: none
	//postconditions: none
	//description: prints out all the available words for translation
	void display(void) const;
	
};

#endif //INC_4P2_EKT_H
