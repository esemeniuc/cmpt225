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

#include "queue.h"
#include <cmath>
#include <algorithm>
#include <iostream> //debug

//Class invariants: FIFO or LILO

//private attributes:
//unsigned int startPos; //starting position of the queue
//
//unsigned int endPos; //ending position of the queue. endPos - startPos = how many items currently of queue
//
//string* queueElements; //array of events in the queue

// Description: default constructor for an empty queue
queue::queue():
startPos(0),
endPos(0),
queueElements(NULL)
{
	queueElements = new string[queueDefaultMax]; //allocate heap memory
	//size + 1 to avoid segfault
}

// Description: default destructor for an empty queue
queue::~queue()
{
	delete[] queueElements; //clean up our heap memory
	queueElements = NULL; //avoid use after free errors
}

// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool queue::isEmpty() const
{
	if(startPos == endPos) //check if empty
	{
		return true; //-1 is defined to be empty, so return true
	}

	return false; //non empty
}


// Description: Adds newElement to the "back" of this queue and
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool queue::enqueue(const string& newElement) throw(ClassException)
{
	if((startPos % queueDefaultMax) == (endPos+1) % queueDefaultMax) //check if full
	{
		throw ClassException("Queue is full");
	}
	queueElements[(endPos) % queueDefaultMax] = newElement; //copy the element into our array
	endPos++;
	//endPos = (endPos+1) % queueDefaultMax ; //increment our count
	return true; //all is good
}

// Description: Removes the element at the "front" of this queue and
//              returns "true" if successful, otherwise "false".
// Precondition: This queue is not empty.
// Time Efficiency: O(1)
bool queue::dequeue()
{
	if(startPos == endPos) //check for empty queue
	{
		return false; //not successful, can't dequeue an empty queue
	}
	startPos++; //decrement our counter
	return true; //all is good

}

// Description: Retrieves (but does not remove) the element at the
//              "front" of this queue and returns it.
// Precondition: This queue is not empty.
// Postcondition: This queue is unchanged.
// Exceptions: Throws ClassException if this queue is empty.
// Time Efficiency: O(1)
string queue::peek() const throw(ClassException)
{
	if(startPos == endPos) //check for empty queue
	{
		throw ClassException("Cannot dequeue an empty queue"); //can't return an string in an empty queue
	}
	return queueElements[startPos % queueDefaultMax]; //return the newest item
}

// Description: randomizes the elements of queueElements
// Precondition: This queue is not empty.
// Time Efficiency: O(n)
void queue::randomize(void)
{
	if(endPos - startPos >= 2) //no need to shuffle a tiny array
	{
		random_shuffle(&queueElements[startPos % queueDefaultMax], &queueElements[(endPos+1) % queueDefaultMax]);
	}
	return; //nothing else to do
}

//Description: prints out the contents of the queue
//Preconditions: none
//Postconditions: prints out the contents of the queue
void queue::print(void) const //debug
{
	for(unsigned int i = startPos; i < endPos; i++)
	{
		std::cout << queueElements[i] << std::endl; //print out each element of our queue
	}
}