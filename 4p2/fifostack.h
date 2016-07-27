// Filename: fifostack.h/fifostack.cpp
// Created by eric on 16/06/16.
// Description:
//An array-based data collection implementation fifostack ADT class.

#ifndef INC_3_FIFOSTACK_H
#define INC_3_FIFOSTACK_H

#include "ClassException.h"

const unsigned int fifostackDefaultMax = 100; //as defined by Anne

//Class invariants: FIFO or LILO
class fifostack
{
private:
	uint32_t dataMax; //maximum number of elements in our array
	uint32_t dataCount; //number of elements in our fifostack
	uint32_t dataStart; //start of elements that haven't been popped
	string* dataArray; //array of data elements in the fifostack

//expands the array size to be 2 times the original size. returns 0 on success, 1 on error
//precondition: the data array is not null and dataMax is > 0
//postcondition: the data array is 2x as large and dataMax is doubled
	uint8_t expand(void);

public:

	// Description: default constructor for an empty fifostack
	fifostack();

	// Description: default destructor for an empty fifostack
	~fifostack();

	// Description: Returns the number of valid elements in fifostack
	// Time Efficiency: O(1)
	uint32_t getSize() const;

	// Description: Adds inputData to the top of fifostack and
	//              returns 0 if successful, otherwise 1.
	// Time Efficiency: O(1)
	uint8_t push(const string inputData);

	// Description: Removes the element at the bottom/front of fifostack and
	//              returns it
	// Precondition: This fifostack is not empty.
	// Exceptions: Throws ClassException if this fifostack is empty.
	// Time Efficiency: O(1)
	string pop(void) throw(ClassException);
	
	// Description: randomizes the elements of dataArray
	// Precondition: This fifostack is not empty.
	// Time Efficiency: O(n)
	void randomizefifostack(void);

	//Description: prints out the contents of the fifostack
	//Preconditions: none
	//Postconditions: prints out the contents of the fifostack
	void print(void) const; //debug
};


#endif //INC_3_FIFOSTACK_H
