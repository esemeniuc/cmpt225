/*
 * filename: btree.h
 *
 * Class Description: A data collection ADT class to satisfy Assn 3's requiremetns.

 * Class Invariant: Data collection with the following characteristics:
 *                   -
 *                   -
 *                   -
 *                   -
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#ifndef INC_3_BTREE_H
#define INC_3_BTREE_H

#include "node.h"

class btree
{
private:
	node* root; //root of the tree
	uint32_t nodeCount; //how many elements we have
	
	//preconditions: tree is not empty, and the shell object is not empty
	//postconditions: a word object matching inputSrc is returned, otherwise NULL is returned or throw exception
	//description: finds a word matching inputSrc if it exists in the tree
	node* rSearch(node* root, word* inputData) const;
	
	//preconditions: none
	//postconditions: returns the memory address of the parent matching inputData.getSrc() to insert our new node
	//description: finds the correct parent node to allow insertion a child node
	void rInsert(node* root, node* inputNode);
	
	//preconditions: none
	//postconditions: none
	//description: prints out the contents of the array in order
	void rPrint(node* currentRoot) const;
	
public:
	//preconditions: none
	//postconditions: creates a tree object with no nodes
	//description: default constructor
	btree();
	
	//preconditions: tree object exists
	//postconditions: frees all the memory from the tree using in-order traversal
	//description: default destructor
	~btree();
	
	//preconditions: none
	//postconditions: a word object matching inputSrc is returned, otherwise NULL is returned or throw exception
	//description: recursively calls rSearch and stops when a word matching inputSrc is found, or reaches bottom of the tree
	word search(word* inputData) const;
	
	//preconditions: inputData.isEmpty() >= 1 (at least 1 term is entered)
	//postconditions: returns 0 if successfully inputted, 1 if there is an error
	//description: creates a node to insert in sorted order (based on src) into the tree
	uint8_t insert(word inputData);
	
	//preconditions: none
	//postconditions: none
	//description: prints out the contents of the array in order
	void print(void) const;
};


#endif //INC_3_BTREE_H
