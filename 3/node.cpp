/*
 * node.cpp
 *
 * Class Definition: node of a binary tree
 *                   in which the data is of template class type.
 *
 * Created on:
 * Author:
 */

#include "node.h"

node::node():
		left(NULL),
		right(NULL)
{
	//nothing else
}

node::node(word inputData):
		data(inputData),
		left(NULL),
		right(NULL)
{
	//nothing else
}

node::~node()
{
	
}