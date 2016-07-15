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
#pragma once

#include <cstddef>  // defines NULL
#include "word.h"

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

/*
 * filename: node.cpp
 *
 * Description: A class to be used in the btree files, to act as a node in a binary tree.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

template <class Type>
//default constructor for an empty node
node<Type>::node():
		left(NULL),
		right(NULL)
{
	//nothing else
}

template <class Type>
//parameterized constructor
node<Type>::node(Type inputData):
		data(inputData),
		left(NULL),
		right(NULL)
{
	//nothing else
}

template <class Type>
//default destructor for an empty node
node<Type>::~node()
{
	data = NULL;
	left = NULL;
	right = NULL;
}