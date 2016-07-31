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
	exQueue userInputQueue; //store translations or user input here

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
