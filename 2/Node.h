/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of Event class type.
 *
 * Created on: 16/06/16
 * Author: eric
 * Description: a definition for node elements to allow a singly linked list
 */
 
// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
#pragma once
#include "Event.h"

class Node
{
public:
	// Public attributes - Why are the attributes public?
	Event data;   // The data in the node
	Node* next;   // Pointer to next node
	
	// Constructors and destructor
	Node();
	Node(Event theData);
	Node(Event theData, Node* theNextNode);
	~Node();

}; // end Node