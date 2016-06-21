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

//Arrival events and departure events are ordered by time, and we always want to remove and
//process the next event that should occur—the highest-priority event. The ADT priority queue is
//used in this way. Our events can be stored in the priority queue eventListPQueue. We can initialize
//eventListPQueue with the arrival events in the simulation data file and later add the departure
//events as they are generated.

//time of departure = time service begins + length of transaction

#include "PQueue.h"
#include <iostream>

//Class Invariant: The elements stored in this Priority Queue are always sorted.

//private attributes
//unsigned int pQueueCount; //count of how many elements are in our priority queue, 0 indexed
//Node* head; //head pointer of our singly headed singly linked list

//public methods

// Description: default constructor for an empty priority queue
PQueue::PQueue():
		head(NULL)
{
	//nothing else to do here
	//cout << "Calling pQueue default constructor" << endl;
}

// Description: default destructor for a priority queue
PQueue::~PQueue()
{
	//TODO: check for memory leaks
	Node* last; //keep a tracker
	Node* current = head;
	while(current != NULL)
	{
		last = current;
		current = current->next; //iterate forward
		delete last;
	}
	head = NULL; //avoid use after free

}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool PQueue::isEmpty() const
{
	if(head == NULL) //check if empty
	{
		return true; //-1 is defined to be empty, so return true
	}

	return false; //non empty
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
bool PQueue::enqueue(const Event& newElement)
{
	if(&newElement == NULL) //check for null
	{
		//cout << "failed null check" << endl; //debug
		return false; //can't insert NULL event
	}
	//cout << "passed null check" << endl; //debug

	//compare with head


	if(head == NULL || newElement.getTime() < head->data.getTime()) //for empty list where the head is null
	{
//		cout << "had null list or less than head time" << endl; //debug
		Node* tempNode = new Node(newElement, head); //make a new node with newElement as our event, and next = NULL
		//insert tempNode into our front of priority queue
		head = tempNode; //set our tempNode to be the head of the linked list
		return true;
	}
//	else if(newElement.getTime() > head->data.getTime()) //prob unnecessary
//	{
//		cout << "small than head" << endl; //debug
//		Node* tempNode = new Node(newElement, head); //make a new node with newElement as our event, and next = NULL
//		//insert tempNode into our front of priority queue
//		head = tempNode; //set our tempNode to be the head of the linked list
//		return true;
//	}

	//iterate through our pQueue to find proper location to put our event in
	//TODO: make sure this doesn't segfault with null or out of bound errors
	Node* current = head; //keep a tracking variable
	Node* previous = head; //keep a second tracking variable

	//for non empty list
	while(current != NULL && (newElement.getTime() > current->data.getTime()) ) //check until newElement's arrival time is not greater than the other elements
	{
//		cout << "ran loop - newElement: " << newElement.getTime() << "-" << newElement.getLength() << " currentTime: " << current->data.getTime() << "-" << current->data.getLength() << " current : " << current << endl; //debug
		previous = current; //move our backup variable up
		current = current->next; //move our tracking variable up
	}
	//cout << "finished loop, current = " << current << endl; //debug

	//check if newElement is a Departure, and the next variable is an arrival,
	//since arrivals must be (arbitrarily) processed before departures
	if(current != NULL && (newElement.getType() == 'D' && current->data.getType() == 'A'))
	{
		if(newElement.getTime() == current->data.getTime()) //check if the times collide, if they do, they make the departure follow the arrival event
		{
			current = current->next; //increment next because the times match, but the arrival must be closer to the front
		}
	}

	//insert new node
//	cout << "had existing list, current = " << current << endl; //debug
	Node* tempNode = new Node(newElement, previous->next); //make a new node with newElement as our event, and next = the following element in the linked list
	//insert tempNode into our priority queue
	previous->next = tempNode; //connect our tempNode to the current->next pointer
	return true;
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
bool PQueue::dequeue()
{
	if(head == NULL) //check if head is null
	{
		return false; //can't dequeue an empty linked list
	}

	Node* headNext = head->next; //store second element pointer (head->next)
	delete head; //free up first element
	head = headNext; //set head to be the new second element
	return true; //all good
}

// Description: Retrieves (but does not remove) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
Event PQueue::peek() const throw(EmptyDataCollectionException)
{
	if(head == NULL) //check for empty priority queue
	{
		//TODO: fix exception handling
		throw 2; //throw an exception
	}

	return head->data; //return event
}

//Description: prints out the contents of the priority queue
//Preconditions: none
//Postconditions: prints out the contents of the priority queue
void PQueue::print(void) const
{
	Node* current = head; //make tracking variable, start from head
	while(current != NULL)
	{
		current->data.print(); //print out the current element in priority queue
		current = current->next; //move up our tracking variable
	}
}
