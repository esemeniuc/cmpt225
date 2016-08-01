/*
 * filename: nodeSL.h/nodeSL.cpp
 *
 * Description: A slingly linked node class to be primarily used for chaining.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#include "nodeSL.h"

template <class Type>
//default constructor for an empty node
nodeSL<Type>::nodeSL():
		next(NULL)
{
	//nothing else
}

template <class Type>
//parameterized constructor
nodeSL<Type>::nodeSL(Type inputData, nodeSL<Type>* inputNextNode):
		data(inputData),
		next(inputNextNode)
{
	//nothing else
}

template <class Type>
//default destructor for an empty node
nodeSL<Type>::~nodeSL()
{
	next = NULL;
}
