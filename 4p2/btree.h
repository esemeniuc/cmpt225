/*
 * filename: btree.h
 *
 * Class Description: A data collection ADT class to satisfy Assn 3's requirements.

 * Class Invariant: Data collection with the following characteristics:
 * - assumes size(), print() are available for use in templated object
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#ifndef INC_4P2_BTREE_H
#define INC_4P2_BTREE_H

#include "node.h"
#include "classException.h"
#include <iostream>

template <class Type>

class btree
{
private:
	node<Type>* root; //root of the tree
	uint32_t nodeCount; //how many elements we have
	
	//preconditions: tree is not empty, and the shell object is not empty
	//postconditions: a Type object matching inputSrc is returned, otherwise NULL is returned or throw exception
	//description: finds a Type matching inputSrc if it exists in the tree
	node<Type>* rSearch(node<Type>* root, Type* inputData) const;
	
	//preconditions: inputNode has a valid filled class
	//postconditions: returns 0 on successful insertion our new node, 0 on failure
	//description: finds the correct parent node to allow insertion a child node
	uint8_t rInsert(node<Type>* root, Type* inputData);
	
	//preconditions: none
	//postconditions: none
	//description: prints out the contents of the array in order
	void rPrint(node<Type>* currentRoot) const;

public:
	//preconditions: none
	//postconditions: creates a tree object with no nodes
	//description: default constructor
	btree();
	
	//preconditions: tree object exists
	//postconditions: frees all the memory from the tree using in-order traversal
	//description: default destructor
	~btree();
	
	//preconditions: root in not NULL
	//postconditions: frees all the memory from the tree using in-order traversal
	//description: for use in the default destructor, recursively frees memory
	// Time Efficiency: O(n)
	void deleteAll(node<Type>* current);
	
	//preconditions: none
	//postconditions: a Type object matching inputSrc is returned, otherwise NULL is returned or throw exception
	//description: recursively calls rSearch and stops when a Type matching inputSrc is found, or reaches bottom of the tree
	Type search(Type* inputData) const throw(classException);
	
	//preconditions: inputData.size() >= 1 (at least 1 term is entered)
	//postconditions: returns 0 if successfully inputted, 1 if there is an error
	//description: creates a node to insert in sorted order (based on src) into the tree
	uint8_t insert(Type inputData);
	
	//preconditions: none
	//postconditions: none
	//description: prints out the contents of the array in order
	void print(void) const;
};

#include "btree.cpp"

#endif //INC_4P2_BTREE_H
