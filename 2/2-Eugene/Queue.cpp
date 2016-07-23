//
// Created by eric on 16/06/16. Edited by Eugene Filatov, 
//

#include "Queue.h"
#include "EmptyDataCollectionException.h"

//Default constructor
Queue::Queue(){
	size = 0;
}



// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool Queue::isEmpty() const

{
	if (size == 0) {
		return true;
	}
	return false;
}

// Description: Adds newElement to the "back" of this queue and
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool Queue::enqueue(const Event& newElement) {

	if (size + 1 > queueCapacity) {
		return false;
	}

	Data[size] = newElement;
	size++;
	return true;


}

// Description: Removes the element at the "front" of this queue and
//              returns "true" if successful, otherwise "false".
// Precondition: This queue is not empty.
// Time Efficiency: O(1)
bool Queue::dequeue() {

	if (size == 0) {
		return false;
	}

	for (int i = 0; i <= size-2; i++) {    // O(1) as size <= queueCapacity 
		Data[i] = Data[i + 1];
}
	size--;
	return true;

}

// Description: Retrieves (but does not remove) the element at the
//              "front" of this queue and returns it.
// Precondition: This queue is not empty.
// Postcondition: This queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
// Time Efficiency: O(1)
Event Queue::peek() const throw(EmptyDataCollectionException)

{
	if (size == 0) {
		throw EmptyDataCollectionException("Queue is Empty");
	}

	return Data[size - 1];

}