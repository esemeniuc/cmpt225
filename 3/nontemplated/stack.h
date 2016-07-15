// Filename: stack.h/stack.cpp
// Created by eric on 16/06/16.
// Description:
//A data collection stack ADT class. This class ***must not*** print anything
//on the computer monitor screen. Name this class stack (stack.h and stack.cpp).
//Use an array-based implementation for this stack class and make sure our
//implementation abides to its Public Interface described below (expressed in C++):

#ifndef INC_3_STACK_H
#define INC_3_STACK_H

#include "word.h"
#include "ClassException.h"

const unsigned int stackDefaultMax = 2; //as defined by Anne

//Class invariants: FIFO or LILO
class stack
{
private:
	uint32_t dataMax; //maximum number of elements in our array
	uint32_t dataCount; //number of elements in our stack
	word* dataArray; //array of data elements in the stack

//expands the array size to be 2 times the original size. returns 0 on success, 1 on error
//precondition: the data array is not null and dataMax is > 0
//postcondition: the data array is 2x as large and dataMax is doubled
	uint8_t expand(void);

public:

	// Description: default constructor for an empty stack
	stack();

	// Description: default destructor for an empty stack
	~stack();

	// Description: Returns the size of the stack
	// Time Efficiency: O(1)
	uint32_t getSize() const;

	// Description: Adds inputData to the back of this stack and
	//              returns 0 if successful, otherwise 1.
	// Time Efficiency: O(1)
	uint8_t push(const word& inputData);

	// Description: Removes the element at the "front" of this stack and
	//              returns it
	// Precondition: This stack is not empty.
	// Exceptions: Throws ClassException if this stack is empty.
	// Time Efficiency: O(1)
	word pop(void) throw(ClassException);
	
	// Description: randomizes the elements of dataArray
	// Precondition: This stack is not empty.
	// Time Efficiency: O(n)
	void randomizeStack(void);

	//Description: prints out the contents of the stack
	//Preconditions: none
	//Postconditions: prints out the contents of the stack
	void print(void) const; //debug
};


#endif //INC_3_STACK_H
