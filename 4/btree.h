/*
 * filename: btree.h
 *
 * Class Description: A data collection ADT class to satisfy Assn 3's requirements.

 * Class Invariant: Data collection with the following characteristics:
 * Assumes ==, <, empty(), print() are available for use in the templated object
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#ifndef INC_3_BTREE_H
#define INC_3_BTREE_H

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
	//description: finds a Type matching inputSrc if it exists in the tree.
	//Mode 0 for ordered traversal using left and right 1, mode 1 for left and right 2
	node<Type>* rSearchID(node<Type>* root, Type* inputData) const;
	node<Type>* rSearchLName(node<Type>* root, Type* inputData) const;
	
	//preconditions: inputNode has a valid filled class
	//postconditions: returns 0 on successful insertion our new node, 0 on failure
	//description: finds the correct parent node to allow insertion a child node
	//Mode 0 for ordered traversal using left and right 1, mode 1 for left and right 2
	uint8_t rInsertID(node<Type>* root, node<Type>* inputNode);
	uint8_t rInsertLName(node<Type>* root, node<Type>* inputNode);
	
	//preconditions: none
	//postconditions: none
	//description: prints out the contents of the array in order using in order traversal
	//Mode 0 for ordered traversal using left and right 1, mode 1 for left and right 2
	void rPrint(node<Type>* currentRoot, bool mode) const;

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
	
	//preconditions: inputData must not be empty
	//postconditions: a Type object matching inputSrc is returned, otherwise NULL is returned or throw exception
	//description: recursively calls rSearch and stops when a Type matching inputSrc is found, or reaches bottom of the tree
	//Mode 0 for ordered traversal using left and right 1, mode 1 for left and right 2
	Type searchID(Type* inputData) const throw(classException);
	Type searchLName(Type* inputData) const throw(classException);
	
	//preconditions: inputData.size() >= 1 (at least 1 term is entered)
	//postconditions: returns 0 if successfully inputted, 1 if there is an error
	//description: creates a node to insert in sorted order (based on src) into the tree
	//Mode 0 for ordered traversal using left and right 1, mode 1 for left and right 2
	uint8_t insert(Type inputData);
	
	//preconditions: none
	//postconditions: none
	//description: prints out the contents of the array in order
	void print(bool mode) const;
};

#include "btree.cpp"

#endif //INC_3_BTREE_H
