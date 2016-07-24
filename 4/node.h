/*
 * filename: node.h
 *
 * Description: A class to be used in the btree files, to act as a node in a binary tree.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#ifndef INC_3_NODE_H
#define INC_3_NODE_H

#include <cstddef>  // defines NULL

template <class Type>
class node
{
public:
	// Public attributes - Why are the attributes public?
	Type data;   // The data in the node
	node* left1;   // Pointer to left node from set 1
	node* right1;   // Pointer to right node from set 1
	node* left2;   // Pointer to left node from set 2
	node* right2;   // Pointer to right node from set 2
	
	// Constructors and destructor
	node(); //default constructor for an empty node
	node(Type inputData); //parameterized constructor
	~node();
	
}; // end node.h

#include "node.cpp"

#endif //INC_3_NODE_H