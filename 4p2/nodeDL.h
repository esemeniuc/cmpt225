/*
 * filename: nodeDL.h/nodeDL.cpp
 *
 * Description: A double linked node class to be primarily used in the btree.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#ifndef INC_4P2_NODEDL_H
#define INC_4P2_NODEDL_H

#include <cstddef>  // defines NULL

template <class Type>
class nodeDL
{
public:
	// Public attributes - Why are the attributes public?
	Type data;   // The data in the node
	nodeDL* left;   // Pointer to left node
	nodeDL* right;   // Pointer to right node
	
	// Constructors and destructor
	nodeDL(); //default constructor for an empty node
	nodeDL(Type inputData); //parameterized constructor
	~nodeDL();
	
}; // end node.h

#include "nodeDL.cpp"

#endif //INC_4P2_NODEDL_H