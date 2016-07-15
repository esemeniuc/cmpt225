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

#include "btree.h"
#include <iostream> //debug

/*private:
	node* root; //root of the tree
	uint32_t nodeCount; //how many elements we have
*/

//preconditions: none
//postconditions: creates a tree object with no nodes
//description: default constructor
btree::btree():
root(NULL),
nodeCount(0)
{
	//nothing else to do
}

//preconditions: tree object exists
//postconditions: frees all the memory from the tree using in-order traversal
//description: default destructor
btree::~btree()
{
	//do a in-order traversal and delete each node
}

//preconditions: tree is not empty, and the shell object is not empty
//postconditions: a word object matching inputSrc is returned, otherwise NULL is returned or throw exception
//description: finds a word matching inputSrc if it exists in the tree
node* btree::rSearch(node* root, word* inputData) const
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


//preconditions: inputNode has a valid filled class
//postconditions: inserts our new node
//description: finds the correct parent node to allow insertion a child node
void btree::rInsert(node* currentRoot, node* inputNode)
{
	if(currentRoot == NULL) //base case
	{
		//fix me
		currentRoot = inputNode; //insert our node
		return;
	}
	
	if(currentRoot->data.getSrc() == inputNode->data.getSrc()) //check for duplicates
	{
		return; // don't want duplicates
	}
	
	if(inputNode->data < currentRoot->data)
	{
		return rInsert(root->left, inputNode);
	}
	else
	{
		return rInsert(root->right, inputNode);
	}
	
}

//preconditions: inputData.isEmpty() >= 1 (at least 1 term is entered)
//postconditions: returns 0 if successfully inputted, 1 if there is an error
//description: creates a node to insert in sorted order (based on src) into the tree
uint8_t btree::insert(word inputData)
{
	//check if params are valid
	if(inputData.isEmpty() < 2) //check for non fully populated
	{
		return 1; //can't input partially/non filled objects
	}
	
	cout << "**about to insert**" << endl;
	//create a node to insert based input params
	node* tempNode = new node(inputData); //pass in inputData
	
	/* Not necessary
	//if root is NULL, then insert at root
	if(root == NULL)
	{
		root = tempNode; //make the new node our root
		nodeCount++; //update counter
		return 0; //all good
	}*/
	
	//find proper place in tree to insert the node
	rInsert(root, tempNode);
	nodeCount++; //increment count
	return 0; //all good
}

//preconditions: none
//postconditions: a word object matching inputSrc is returned, otherwise NULL is returned or throw exception
//description: recursively calls rSearch and stops when a word matching inputSrc is found, or reaches bottom of the tree
word btree::search(word* inputData) const
{
	if(inputData->isEmpty() == 0) //check for empty input
	{
		throw "Can't search with empty input"; //can't search without proper input
	}
	
	node* searchResult = rSearch(root, inputData); //look for parent of matching node
	
	if(searchResult == NULL) //compare
	{
		throw "Word doesn't exist"; //failed, don't try to access searchResult->data unless segfault
	}
	
	
	return searchResult->data; //all good
}

//preconditions: none
//postconditions: none
//description: prints out the contents of the array in order using in order traversal
void btree::rPrint(node* currentRoot) const
{
	if(root == NULL) //base case
	{
		cout << "base case" << endl; //debug
		return;
	}

	rPrint(currentRoot->left); //recurse left
	currentRoot->data.print(); //print the object
	rPrint(currentRoot->right); //recurse right
}

//preconditions: none
//postconditions: none
//description: prints out the contents of the array in order
void btree::print(void) const
{
	rPrint(root);
}