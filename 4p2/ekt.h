/*
 * filename: ekt.h/ekt.cpp
 *
 * Description: An english klingon translator class
 * Creation date: July 31, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 *
 * class invariant: btree and hashtable will not contain duplicates
 */

#ifndef INC_4P2_EKT_H
#define INC_4P2_EKT_H

#include "btree.h"
#include "exQueue.h"
#include "nodeSL.h"
#include "word.h"

//#define private public //debug: ugly hack to do assert testing

class ekt
{
private:
	btree<word> dataBtree; //store translations here
	exQueue userInputQueue; //store file input translations or user input here
	nodeSL<word>** wordTable; //hashtable for word entries
	size_t wordCount; //number of successfully added words in ekt
	size_t modulus; //modulus for wordTable
	
	
	//preconditions: none
	//postconditions: returns a hash index
	//description: generates a hash based on inputInteger and returns it in O(1) time
	size_t hashInteger(uint32_t inputInteger) const;
	
	//preconditions: none
	//postconditions: returns a hash index
	//description: generates a hash based on inputString and returns it in O(1) time
	size_t hashString(std::string inputString) const;
	
	//preconditions: none
	//postconditions: returns a hash index
	//description: generates a hash based on inputString and returns it in O(1) time
	size_t hashStringBad(std::string inputString) const;


public:
	ekt();
	
	~ekt();
	
	//preconditions: inputFilename is not empty
	//postconditions: returns 0 on successful read from file, 1 if there is an error
	//description: reads in english klingon translations in the from of english:klingon
	uint8_t loadFromFile(std::string inputFilename);
	
	//preconditions: inputWord is not empty
	//postconditions: returns 0 on successful read from file, 1 if there is an error
	//description: inserts word objects into the btree and hashtable
	uint8_t insert(const word& inputWord);
	
	//preconditions: none
	//postconditions: prints out klingon words based on user input
	//description: creates an interactive prompt for user to enter words to be translated
	void translate(void);
	
	//preconditions: none
	//postconditions: none
	//description: prints out all the available words for translation
	void display(void) const;
	
	//preconditions: none
	//postconditions: returns the standard deviation of the length of each chain in the hash table
	//description: gets
	double getStdDev(void) const;
	
	//preconditions: none
	//postconditions: returns the word pair based on inputWord
	//postconditions: returns the word pair based on inputWord
	word* getWord(word inputWord) const;
	
};

#endif //INC_4P2_EKT_H
