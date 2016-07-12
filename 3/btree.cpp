//
// Created by eric on 08/07/16.
//

#include "btree.h"

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

//preconditions: tree not empty?
//postconditions: returns the memory address of the parent to insert our new node, otherwise returns NULL
//description: finds the right parent node to insert a child node
node* btree::rTraverse(node* root, word& inputData) const
{
	if(root == NULL) //base case
	{
		return NULL;
	}
	
	if(inputData < root->data)
	{
		rTraverse(root->left, inputData);
	}
	else
	{
		rTraverse(root->right, inputData);
	}
	
	return root;
}

//preconditions: inputSrc and inputDest are not empty strings
//postconditions: returns 0 if successfully inputted, 1 if there is an error
//description: creates a node to insert in sorted order (based on src) into the tree
uint8_t btree::insert(word& inputData)
{
	//check if params are valid
	if(inputData.isEmpty() < 2) //check for non fully populated
	{
		return 0;
	}
	
	//create a node to insert based input params
	node* tempNode = new node(inputData);
	
	//check if root is NULL
	if(root == NULL)
	{
		root = tempNode; //make the new node our root
		nodeCount++; //update counter
		return 0; //all good
	}
	
	//find proper place in tree
	//node* insertLocation = rtraverse();
	
	//insert the node
	
	//increment count
	
	return 0;
}

//preconditions: tree is not empty
//postconditions: a word object matching inputSrc is returned, otherwise NULL is returned or throw exception
//description: finds a word matching inputSrc if it exists in the tree
word btree::getDest(string inputSrc) const
{
	//check if input is valid
	
	//do binary search on tree until we get a match
	
	//
	word test;
	return test;
}
