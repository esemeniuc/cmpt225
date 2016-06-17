// Filename: PQueue.h/PQueue.cpp
// Created by eric on 16/06/16.
//Description:
//A data collection Priority Queue ADT class. This class ***must
//not*** print anything on the computer monitor screen. Name this
//class PQueue (PQueue.h and PQueue.cpp). A priority queue keeps
//its elements in a particular "priority" sort order. Its peek
//operation peeks at the element with the "highest" priority and
//its dequeue operation removes the element with the "highest"
//priority. Note that "highest" priority does not always mean
//largest value.

#ifndef INC_2_PQUEUE_H
#define INC_2_PQUEUE_H

#include "Event.h"
#include "EmptyDataCollectionException.h"

//Class Invariant: The elements stored in this Priority Queue are always sorted.
class PQueue
{


	// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
	// Time Efficiency: O(1)
	bool isEmpty() const;

	// Description: Inserts newElement in sort order.
	//              It returns "true" if successful, otherwise "false".
	// Precondition: This Priority Queue is sorted.
	// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
	bool enqueue(const Event& newElement);

	// Description: Removes the element with the "highest" priority.
	//              It returns "true" if successful, otherwise "false".
	// Precondition: This Priority Queue is not empty.
	bool dequeue();

	// Description: Retrieves (but does not remove) the element with the "highest" priority.
	// Precondition: This Priority Queue is not empty.
	// Postcondition: This Priority Queue is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
	Event peek() const throw(EmptyDataCollectionException);
};


#endif //INC_2_PQUEUE_H
