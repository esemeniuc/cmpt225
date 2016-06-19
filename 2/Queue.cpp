// Filename: Queue.h/Queue.cpp
// Created by eric on 16/06/16.
// Description:
//A data collection Queue ADT class. This class ***must not*** print anything
//on the computer monitor screen. Name this class Queue (Queue.h and Queue.cpp).
//Use an array-based implementation for this Queue class and make sure our
//implementation abides to its Public Interface described below (expressed in C++):

//bankQueue represents the line of customers in the bank, and stores events of in the order that they were received
//As customers arrive, they go to the back of the
//line. The current customer, who was at the front of the line, is being served, and it is this customer that
//you remove from the system next. It is thus natural to use a queue, bankQueue, to represent the line of
//customers in the bank. For this problem, the only information that you must store in the queue about
//each customer is the time of arrival and the length of the transaction.

#include "Queue.h"

//Class invariants: FIFO or LILO

//private attributes:

//unsigned int queueCount; //how many items are currently in the queue. Default value is -1
//
//unsigned int queueMax; //keeps track of the maximum elements in the queue
//
//Event* queueElements; //array of events in the queue

// Description: default constructor for an empty queue
Queue::Queue()
{

}

// Description: default destructor for an empty queue
Queue::~Queue()
{

}

// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool Queue::isEmpty() const
{

}


// Description: Adds newElement to the "back" of this queue and
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool Queue::enqueue(const Event& newElement)
{
	return 0;
}

// Description: Removes the element at the "front" of this queue and
//              returns "true" if successful, otherwise "false".
// Precondition: This queue is not empty.
// Time Efficiency: O(1)
bool Queue::dequeue()
{
	return 0;
}

// Description: Retrieves (but does not remove) the element at the
//              "front" of this queue and returns it.
// Precondition: This queue is not empty.
// Postcondition: This queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
// Time Efficiency: O(1)
Event Queue::peek() const throw(EmptyDataCollectionException)
{
	return NULL;
}

//Description: prints out the contents of the queue
//Preconditions: none
//Postconditions: prints out the contents of the queue
void Queue::print(void)
{
	for(int i = 0; i < queueCount; i++)
	{
		queueElements[i].print(); //print out each element of our queue
	}
}