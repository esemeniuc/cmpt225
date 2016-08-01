/*
 * filename: nodeDL.h/nodeDL.cpp
 *
 * Description: A double linked node class to be primarily used in the btree.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#include "nodeDL.h"

template <class Type>
//default constructor for an empty node
nodeDL<Type>::nodeDL():
		left(NULL),
		right(NULL)
{
	//nothing else
}

template <class Type>
//parameterized constructor
nodeDL<Type>::nodeDL(Type inputData):
		data(inputData),
		left(NULL),
		right(NULL)
{
	//nothing else
}

template <class Type>
//default destructor for an empty node
nodeDL<Type>::~nodeDL()
{
	left = NULL;
	right = NULL;
}
