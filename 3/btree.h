//
// Created by eric on 08/07/16.
//

#ifndef INC_3_BTREE_H
#define INC_3_BTREE_H

#include "node.h"

class btree
{
private:
	node* root; //root of the tree
	uint32_t nodeCount; //how many elements we have
	
	//preconditions: none
	//postconditions: returns the memory address of the parent to insert our new node
	//description: finds the right parent node to insert a child node
	node* rTraverse(node* root, word& inputData) const;
	
public:
	//preconditions: none
	//postconditions: creates a tree object with no nodes
	//description: default constructor
	btree();
	
	//preconditions: tree object exists
	//postconditions: frees all the memory from the tree using inorder traversal
	//description: default destructor
	~btree();
	
	//preconditions: inputWord is nonempty
	//postconditions: a new node is inserted
	//description: creates a node to insert in sorted order (based on src) into the tree
	uint8_t insert(word& inputData);
	
	//preconditions: tree is not empty
	//postconditions: a word object matching inputSrc is returned, otherwise NULL is returned or throw exception
	//description: finds a word matching inputSrc if it exists in the tree
	word getDest(string inputSrc) const;
};


#endif //INC_3_BTREE_H
