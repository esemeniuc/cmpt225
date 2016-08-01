/*
 * filename: nodeSL.h/nodeSL.cpp
 *
 * Description: A singly linked node class to be primarily used for chaining.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#ifndef INC_4P2_NODESL_H
#define INC_4P2_NODESL_H

#include <cstddef>  // defines NULL

template <class Type>
class nodeSL
{
public:
	// Public attributes - Why are the attributes public?
	Type* data;   // The data in the node
	nodeSL* next;   // Pointer to next node
	
	// Constructors and destructor
	nodeSL(); //default constructor for an empty node
	nodeSL(Type* inputData, nodeSL<Type>* inputNextNode); //parameterized constructor
	~nodeSL();
	
}; // end nodeSL.h

#include "nodeSL.cpp"

#endif //INC_4P2_NODESL_H