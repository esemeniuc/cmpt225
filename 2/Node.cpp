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


#include <iostream>
#include "Node.h"

Node::Node()
{
	next = NULL;
}

Node::Node(Event theData)
{
	data = theData;
	next = NULL;
}

Node::Node(Event theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}

Node::~Node()
{
}

// end Node.cpp