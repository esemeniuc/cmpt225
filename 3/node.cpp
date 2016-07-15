/*
 * filename: node.cpp
 *
 * Description: A class to be used in the btree files, to act as a node in a binary tree.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
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