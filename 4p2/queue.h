/*
 * filename: queue.h/queue.cpp
 *
 * Description: A file, with a main that tests the other components specified in the Makefile.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

// Description:
//A data collection Queue ADT class that uses an array-based implementation

#ifndef INC_3_QUEUE_H
#define INC_3_QUEUE_H

#include "ClassException.h"

const unsigned int queueDefaultMax = 10000; //arbitrarily defined

//Class invariants: FIFO or LILO
class queue
{
private:
	unsigned int startPos; //starting position of the queue

	unsigned int endPos; //ending position of the queue. endPos - startPos = how many items currently of queue

	string* queueElements; //array of events in the queue

public:

	// Description: default constructor for an empty queue
	queue();

	// Description: default destructor for an empty queue
	~queue();

	// Description: Returns "true" is this queue is empty, otherwise "false".
	// Time Efficiency: O(1)
	bool isEmpty() const;
	
	// Description: Adds inputData to the "back" of this queue and
	//              returns "true" if successful, otherwise "false".
	// Time Efficiency: O(1)
	bool enqueue(const string & inputData) throw(ClassException);

	// Description: Removes the element at the "front" of this queue and
	//              returns "true" if successful, otherwise "false".
	// Precondition: This queue is not empty.
	// Time Efficiency: O(1)
	bool dequeue();

	// Description: Retrieves (but does not remove) the element at the
	//              "front" of this queue and returns it.
	// Precondition: This queue is not empty.
	// Postcondition: This queue is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
	// Time Efficiency: O(1)
	string peek() const throw(ClassException);
	
	// Description: randomizes the elements of queueElements
	// Precondition: This queue is not empty.
	// Time Efficiency: O(n)
	void randomize(void);

	//Description: prints out the contents of the queue
	//Preconditions: none
	//Postconditions: prints out the contents of the queue
	void print(void) const; //debug
};


#endif //INC_3_QUEUE_H
