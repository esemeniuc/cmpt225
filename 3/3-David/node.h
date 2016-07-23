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
#include <string>


class node
{
public:
	// Public attributes - Why are the attributes public?
	std::string data;   // The data in the node
	node* left;   // Pointer to left node
	node* right;   // Pointer to right node
	unsigned int segIndex;
	
	// Constructors and destructor
	node();
	node(std::string inputData, unsigned int segIndexer);
	~node();
	
}; // end node
