/*
 * filename: node.h
 *
 * Description: A class to be used in the btree files, to act as a node in a binary tree.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */


// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _node and #define _node
#ifndef INC_4P2_NODE_H
#define INC_4P2_NODE_H

#include <cstddef>  // defines NULL

template <class Type>
class node
{
public:
	// Public attributes - Why are the attributes public?
	Type data;   // The data in the node
	node* left;   // Pointer to left node
	node* right;   // Pointer to right node
	
	// Constructors and destructor
	node(); //default constructor for an empty node
	node(Type inputData); //parameterized constructor
	~node();
	
}; // end node.h

#include "node.cpp"

#endif //INC_4P2_NODE_H