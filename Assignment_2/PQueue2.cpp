// Filename: PQueue.h/PQueue.cpp
// Created by eric on 16/06/16.Edited by Eugene Filatov,
//Description:
//A data collection Priority Queue ADT class. This class ***must
//not*** print anything on the computer monitor screen. Name this
//class PQueue (PQueue.h and PQueue.cpp). A priority queue keeps
//its elements in a particular "priority" sort order. Its peek
//operation peeks at the element with the "highest" priority and
//its dequeue operation removes the element with the "highest"
//priority. Note that "highest" priority does not always mean
//largest value.

//Arrival events and departure events are ordered by time, and we always want to remove and
//process the next event that should occur�the highest-priority event. The ADT priority queue is
//used in this way. Our events can be stored in the priority queue eventListPQueue . We can initialize
//eventListPQueue with the arrival events in the simulation data fi le and later add the departure
//events as they are generated.

//time of departure = time service begins + length of transaction

#ifndef INC_2_PQUEUE_H
#define INC_2_PQUEUE_H
#endif //INC_2_PQUEUE_H

#include <stdlib.h>
#include "Event.h"
#include "EmptyDataCollectionException.h"
#include "Node.h"
#include "PQueue2.h"



//Default constructor
PQueue::PQueue() {
	Head = NULL;
	Tail = NULL;

}
PQueue::~PQueue() {


}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool PQueue::isEmpty() const {
	if (Head == NULL) {
		return true;
	}
	return false;
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
bool PQueue::enqueue(const Event& newElement) {


	//Case: Empty queue
	if (this->isEmpty() == true) {
		Head = new Node(newElement);
		Tail = Head;
		return true;
	}

	// Case : comparison to front
	if ( newElement.getTime() < (Head->data).getTime() ) {
		Node* Nd = new Node(newElement);
		Nd->next = Head;
		Head = Nd;
		return true;
	}

	if (newElement.getTime() == (Head->data).getTime() && newElement.getType() < (Head->data).getType()) {
		Node* Nd = new Node(newElement);
		Nd->next = Head;
		Head = Nd;
		return true;
	}

	// Case: comparison to back
	if ((Tail->data).getTime() < newElement.getTime()) {
		Node* Nd = new Node(newElement);
		Tail->next = Nd;
		Tail = Nd;
		Nd->next;
		return true;
	}

	if ((Tail->data).getTime() == newElement.getTime() && (Tail->data).getType() < newElement.getType()) {
		Node* Nd = new Node(newElement);
		Tail->next = Nd;
		Tail = Nd;
		Nd->next;
		return true;
	}


// Case: comparison to the rest of the list
	Node* prev = Head;
	for (Node* curr = Head->next; !(curr->next->next == NULL); curr = curr->next) {

		if (newElement.getTime() < (curr->data).getTime()) {
			Node* Nd = new Node(newElement);
			Nd->next = curr;
			prev->next = Nd;
			return true;
		}

		if (newElement.getTime() == (Head->data).getTime() && newElement.getType() < (Head->data).getType()) {
			Node* Nd = new Node(newElement);
			Nd->next = curr;
			prev->next = Nd;
			return true;
		}

		prev = prev->next;







	}

	return false;

}



// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
bool PQueue::dequeue() {

	if (this->isEmpty()) {
		return false;
	}

	if(Head->next==NULL){
		Head=NULL;
		Tail=NULL;
		return true;
	}

	 Head=Head->next;

	return true;

}

// Description: Retrieves (but does not remove) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
Event PQueue::peek() const throw(EmptyDataCollectionException)

{
	if (this->isEmpty() == true) {
		throw EmptyDataCollectionException("PQueue is Empty");
	}

	return Head->data;

}

void PQueue::print(void) const
{
	Node* current = Head; //make tracking variable, start from head
	while(current != NULL)
	{
		current->data.print(); //print out the current element in priority queue
		current = current->next; //move up our tracking variable
	}
}

//#endif //INC_2_PQUEUE_H
