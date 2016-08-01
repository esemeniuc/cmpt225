// Filename: exQueue.h/exQueue.cpp
// Created by eric on 16/06/16.
// Description:
//An array-based data collection implementation for an expandable queue ADT.

#ifndef INC_4P2_EXQUEUE_H
#define INC_4P2_EXQUEUE_H

#include "classException.h"

const unsigned int exQueueDefaultMax = 100; //as defined by Anne

//Class invariants: FIFO or LILO
class exQueue
{
private:
	uint32_t dataMax; //maximum number of elements in our array
	uint32_t dataCount; //number of elements in our exQueue
	uint32_t dataStart; //start of elements that haven't been popped
	std::string* dataArray; //array of data elements in the exQueue

//expands the array size to be 2 times the original size. returns 0 on success, 1 on error
//precondition: the data array is not null and dataMax is > 0
//postcondition: the data array is 2x as large and dataMax is doubled
	uint8_t expand(void);

public:

	// Description: default constructor for an empty exQueue
	exQueue();

	// Description: default destructor for an empty exQueue
	~exQueue();

	// Description: Returns the number of valid elements in exQueue
	// Time Efficiency: O(1)
	uint32_t getSize() const;

	// Description: Adds inputData to the top of exQueue and
	//              returns 0 if successful, otherwise 1.
	// Time Efficiency: O(1)
	uint8_t push(const std::string inputData);

	// Description: Removes the element at the bottom/front of exQueue and
	//              returns it
	// Precondition: This exQueue is not empty.
	// Exceptions: Throws classException if this exQueue is empty.
	// Time Efficiency: O(1)
	std::string pop(void) throw(classException);
	
	// Description: randomizes the elements of dataArray
	// Precondition: This exQueue is not empty.
	// Time Efficiency: O(n)
	void randomize(void);

	//Description: prints out the contents of the exQueue
	//Preconditions: none
	//Postconditions: prints out the contents of the exQueue
	void print(void) const; //debug
};


#endif //INC_4P2_EXQUEUE_H
