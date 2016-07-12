/*
 * node.h
 *
 * Class Definition: node of a binary tree
 *                   in which the data is of template class type.
 *
 * Created on:
 * Author:
 */

// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _node and #define _node
#pragma once

#include <cstddef>  // defines NULL
#include "word.h"


class node
{
public:
	// Public attributes - Why are the attributes public?
	word data;   // The data in the node
	node* left;   // Pointer to left node
	node* right;   // Pointer to right node
	
	// Constructors and destructor
	node();
	node(word inputData);
	~node();
	
}; // end node