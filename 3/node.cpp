/*
 * filename: node.cpp
 *
 * Description: A class to be used in the btree files, to act as a node in a binary tree.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#include "node.h"

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
	left = NULL;
	right = NULL;
}
