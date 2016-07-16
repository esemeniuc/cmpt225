/*
 * filename: word.h/word.cpp
 *
 * Description: A word object that stores a pair of strings
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#ifndef INC_3_WORD2_H
#define INC_3_WORD2_H

#include <string>

using namespace std;

class word2
{
private:
	string src; //lookup word
	
	string dest; //translation of the word

public:
	
	//preconditions: none
	//postconditions: creates a word object with empty fields for src and dest
	//description: default constructor
	word2();
	
	//preconditions: none
	//postconditions: creates a shell word object for searching
	//description: constructor that fills in the class
	word2(string inputSrc);
	
	//preconditions: none
	//postconditions: creates a word object
	//description: constructor that fills in the class
	word2(string inputSrc, string inputDest);
	
	//preconditions: none
	//postconditions: none
	//description: default destructor
	~word2();
	
	//preconditions: src is a non empty string
	//postconditions: 0 if src is set correctly, 1 if there is an error
	//description: sets the source word
	uint8_t setSrc(string inputSrc);
	
	//preconditions: dest is a non empty string
	//postconditions: 0 if dest is set correctly, 1 if there is an error
	//description: sets the destination word
	uint8_t setDest(string inputDest);
	
	//preconditions: none
	//postconditions: src is returned
	//description: gets the value of src
	string getSrc(void) const;
	
	//preconditions: none
	//postconditions: dest is returned
	//description: gets the value of dest
	string getDest(void) const;
	
	//preconditions: none
	//postconditions: returns 0 if src and dest are empty, returns 1 if dest is empty, and returns 2 if both are not empty
	//description: gets the value of dest
	uint8_t size(void) const;
	
	//preconditions: inputWord is not null
	//postconditions: 0 if inputWord is greater than "this", 1 if less than "this"
	//description: less than overloaded operator
	bool operator<(word2& inputWord) const;
	
	//preconditions: inputWord is not null
	//postconditions: 1 if src == inputWord.getSrc(), 0 otherwise
	//description: equality overloaded operator
	bool operator==(word2& inputWord) const;
	
	//preconditions: inputWord is not null
	//postconditions: 1 if src != inputWord.getSrc(), 0 otherwise
	//description: equality overloaded operator
	//bool operator!=(word& inputWord) const;
	
	/*
	//preconditions: none
	//postconditions: overloads cout to print out the word object
	//description: cout overloaded operator
	ostream& operator<<(ostream& os);
	*/
	
	//preconditions: none
	//postconditions: prints out the word object
	//description: cout overloaded operator
	void print(void) const;

};


#endif //INC_3_WORD2_H
