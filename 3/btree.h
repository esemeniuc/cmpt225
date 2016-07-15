/*
 * filename: btree.h
 *
 * Class Description: A data collection ADT class to satisfy Assn 3's requirements.

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
#include "ClassException.h"

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
	uint8_t rInsert(node<Type>* root, node<Type>* inputNode);
	
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
	
	//preconditions: none
	//postconditions: a Type object matching inputSrc is returned, otherwise NULL is returned or throw exception
	//description: recursively calls rSearch and stops when a Type matching inputSrc is found, or reaches bottom of the tree
	Type search(Type* inputData) const throw(ClassException);
	
	//preconditions: inputData.isEmpty() >= 1 (at least 1 term is entered)
	//postconditions: returns 0 if successfully inputted, 1 if there is an error
	//description: creates a node to insert in sorted order (based on src) into the tree
	uint8_t insert(Type inputData);
	
	//preconditions: none
	//postconditions: none
	//description: prints out the contents of the array in order
	void print(void) const;
};


/*
 * filename: btree.cpp
 *
 * Class Description: A data collection ADT class to satisfy Assn 3's requirements.

 * Class Invariant: Data collection with the following characteristics:
 *                   -
 *                   -
 *                   -
 *                   -
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

/*private:
	node<Type>* root; //root of the tree
	uint32_t nodeCount; //how many elements we have
*/

template <class Type>
//preconditions: none
//postconditions: creates a tree object with no nodes
//description: default constructor
btree<Type>::btree():
		root(NULL),
		nodeCount(0)
{
	//nothing else to do
}

template <class Type>
//preconditions: tree object exists
//postconditions: frees all the memory from the tree using in-order traversal
//description: default destructor
btree<Type>::~btree()
{
	//do a in-order traversal and delete each node
}

template <class Type>
//preconditions: tree is not empty, and the shell object is not empty
//postconditions: a Type object matching inputSrc is returned, otherwise NULL is returned or throw exception
//description: finds a Type matching inputSrc if it exists in the tree
node<Type>* btree<Type>::rSearch(node<Type>* root, Type* inputData) const
{
	if(root == NULL || root->data.getSrc() == inputData->getSrc()) //base case
	{
		return root;
	}
	
	if(*inputData < root->data)
	{
		return rSearch(root->left, inputData);
	}
	else
	{
		return rSearch(root->right, inputData);
	}
	
}

template <class Type>
//preconditions: inputNode has a valid filled class
//postconditions: returns 0 on successful insertion our new node, 0 on failure
//description: finds the correct parent node to allow insertion a child node
uint8_t btree<Type>::rInsert(node<Type>* currentRoot, node<Type>* inputNode)
{
	while(currentRoot != NULL) //base case
	{
		if (currentRoot->data.getSrc() == inputNode->data.getSrc()) //check for duplicates
		{
			return 1; // failure, don't want duplicates
		}
		
		if (inputNode->data < currentRoot->data) //check if we have to go to the left
		{
			if (currentRoot->left == NULL) //check if empty
			{
				currentRoot->left = inputNode; //insert
				return 0; //all good
			}
			else //non empty, so continue
			{
				currentRoot = currentRoot->left; //visit the left subtree
			}
		}
		else //go to right
		{
			if (currentRoot->right == NULL) //check if empty
			{
				currentRoot->right = inputNode; //insert
				return 0; //all good
			}
			else //non empty, so continue
			{
				currentRoot = currentRoot->right; //visit the right subtree
			}
		}
	}
	
	
	return 1; //shouldn't reach the end, so throw error
}

template <class Type>
//preconditions: inputData.isEmpty() >= 1 (at least 1 term is entered)
//postconditions: returns 0 if successfully inputted, 1 if there is an error
//description: creates a node to insert in sorted order (based on src) into the tree
uint8_t btree<Type>::insert(Type inputData)
{
	//check if params are valid
	if(inputData.isEmpty() < 2) //check for non fully populated
	{
		return 1; //can't input partially/non filled objects
	}
	
	//cout << "**about to insert**" << endl;
	//create a node to insert based input params
	node<Type>* tempNode = new node<Type>(inputData); //pass in inputData
	
	
	//if root is NULL, then insert at root, because insert function cant modify root variable
	if(root == NULL)
	{
		root = tempNode; //make the new node our root
		nodeCount++; //update counter
		return 0; //all good
	}
	
	//find proper place in tree to insert the node
	rInsert(root, tempNode);
//	uint8_t status = rInsert(root, tempNode);
//	cout << "insert status: " << (int)status << endl; //debug
	nodeCount++; //increment count
	return 0; //all good
}

template <class Type>
//preconditions: none
//postconditions: a Type object matching inputSrc is returned, otherwise NULL is returned or throw exception
//description: recursively calls rSearch and stops when a Type matching inputSrc is found, or reaches bottom of the tree
Type btree<Type>::search(Type* inputData) const throw(ClassException)
{
	if (inputData->isEmpty() == 0) //check for empty input
	{
		throw ClassException("Can't search with empty input");//can't search without proper input
	}
	
	node<Type>* searchResult = rSearch(root, inputData); //look for parent of matching node
	
	if(searchResult == NULL) //compare
	{
		inputData->setDest("<not found>");
		return *inputData;
		//throw ClassException("Type doesn't exist"); //failed, don't try to access searchResult->data unless segfault
	}
	
	return searchResult->data; //otherwise return Type, all is good
}

template <class Type>
//preconditions: none
//postconditions: none
//description: prints out the contents of the array in order using in order traversal
void btree<Type>::rPrint(node<Type>* currentRoot) const
{
	if(currentRoot == NULL) //base case
	{
		//cout << "base case" << endl; //debug
		return;
	}
	
	rPrint(currentRoot->left); //recurse left
	currentRoot->data.print(); //print the object
	rPrint(currentRoot->right); //recurse right
}

template <class Type>
//preconditions: none
//postconditions: none
//description: prints out the contents of the array in order
void btree<Type>::print(void) const
{
	rPrint(root);
}

#endif //INC_3_BTREE_H
