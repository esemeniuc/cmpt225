/*
 * filename: btree.cpp
 *
 * Class Description: A data collection ADT class to satisfy Assn 3's requirements.

 * Class Invariant: Data collection with the following characteristics:
 * Assumes ==, <, empty(), print() are available for use in the templated object
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

/*private:
	node<Type>* root; //root of the tree
	uint32_t nodeCount; //how many elements we have
*/

#include "btree.h"
#include "student.h"

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
	deleteAll(root);
	//cout << "called delete" << endl;
}

template <class Type>
void btree<Type>::deleteAll(node<Type>* current)
{
//	cout << "called delete, root = " << root << endl;
	if(current == NULL)
	{
		return;
	}
	
	if(current->left1 != NULL){
		deleteAll(current->left1);
	}
	if(current->right1 != NULL){
		deleteAll(current->right1);
	}
	
	delete current;
}

template <class Type>
//preconditions: tree is not empty, and the shell object is not empty
//postconditions: a Type object matching inputSrc is returned, otherwise NULL is returned or throw exception
//description: finds a Type matching inputSrc if it exists in the tree
node<Type>* btree<Type>::rSearchID(node<Type>* currentRoot, Type* inputData) const
{
	if(currentRoot == NULL || currentRoot->data.getID() == inputData->getID()) //base case
	{
		return currentRoot;
	}
	
	if(inputData->getID() < currentRoot->data.getID())
	{
		return rSearchID(currentRoot->left1, inputData);
	}
	else
	{
		return rSearchID(currentRoot->right1, inputData);
	}
}

template <class Type>
node<Type>* btree<Type>::rSearchLName(node<Type>* currentRoot, Type* inputData) const
{
	if(currentRoot == NULL || currentRoot->data.getFullName() == inputData->getFullName()) //base case
	{
		return currentRoot;
	}
	
	if(inputData->getFullName() < currentRoot->data.getFullName())
	{
		return rSearchLName(currentRoot->left2, inputData);
	}
	else
	{
		return rSearchLName(currentRoot->right2, inputData);
	}
}


template <class Type>
//preconditions: inputNode has a valid filled class
//postconditions: returns 0 on successful insertion our new node, 0 on failure
//description: finds the correct parent node to allow insertion a child node
uint8_t btree<Type>::rInsertID(node<Type>* currentRoot, node<Type>* inputNode)
{
	while(currentRoot != NULL) //base case
	{
		if (currentRoot->data.equals(inputNode->data)) //check for duplicates
		{
			return 1; // failure, don't want duplicates
		}
		
		if (inputNode->data.getID() < currentRoot->data.getID()) //check if we have to go to the left
		{
			if (currentRoot->left1 == NULL) //check if empty
			{
				currentRoot->left1 = inputNode; //insert into empty slot
				return 0; //all good
			}
			else //non empty, so continue
			{
				currentRoot = currentRoot->left1; //visit the left subtree
			}
		}
		else //go to right
		{
			if (currentRoot->right1 == NULL) //check if empty
			{
				currentRoot->right1 = inputNode; //insert
				return 0; //all good
			}
			else //non empty, so continue
			{
				currentRoot = currentRoot->right1; //visit the right subtree
			}
		}
	}
	
	return 1; //shouldn't reach the end, so return error
}

template <class Type>
uint8_t btree<Type>::rInsertLName(node<Type>* currentRoot, node<Type>* inputNode)
{
	while(currentRoot != NULL) //base case
	{
		if (currentRoot->data.equals(inputNode->data)) //check for duplicates
		{
			return 1; // failure, don't want duplicates
		}
		
		if (inputNode->data.getFullName() < currentRoot->data.getFullName()) //check if we have to go to the left
		{
			if (currentRoot->left2 == NULL) //check if empty
			{
				currentRoot->left2 = inputNode; //insert into empty slot
				return 0; //all good
			}
			else //non empty, so continue
			{
				currentRoot = currentRoot->left2; //visit the left subtree
			}
		}
		else //go to right
		{
			if (currentRoot->right2 == NULL) //check if empty
			{
				currentRoot->right2 = inputNode; //insert
				return 0; //all good
			}
			else //non empty, so continue
			{
				currentRoot = currentRoot->right2; //visit the right subtree
			}
		}
	}
	
	return 1; //shouldn't reach the end, so return error
}

template <class Type>
//preconditions: inputData must not be empty
//postconditions: returns 0 if successfully inputted, 1 if there is an error
//description: creates a node to insert in sorted order (based on src) into the tree
uint8_t btree<Type>::insert(Type inputData)
{
	//check if params are valid
	if(inputData.empty()) //check for non fully populated
	{
		return 1; //can't non filled objects
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
	uint8_t insertIDStatus = rInsertID(root, tempNode);
	uint8_t insertLNameStatus = rInsertLName(root, tempNode);
//	std::cout << "Nonfirst insert: insertIDStatus: " << (int)insertIDStatus << " insertLNameStatus: " << (int)insertLNameStatus << std::endl; //debug
	if(insertIDStatus == 0 && insertLNameStatus == 0) ///if all is good, then increment
	{
		nodeCount++; //increment count
		return 0; //all good
	}
	else //some error occurred
	{
		delete tempNode; //no need for node that failed to insert
		return 1; //error
	}
	
}

template <class Type>
//preconditions: inputData must not be empty
//postconditions: a Type object matching inputSrc is returned, otherwise NULL is returned or throw exception
//description: recursively calls rSearch and stops when a Type matching inputSrc is found, or reaches bottom of the tree
Type btree<Type>::searchID(Type* inputData) const throw(classException)
{
	if(inputData->getID() <= 0) //check for empty input
	{
		throw classException("Can't search with empty ID");//can't search without proper input
	}
	
	node<Type>* searchResult = rSearchID(root, inputData);//look for parent of matching node

	if(searchResult == NULL) //compare
	{
		//option 1
//		inputData->setDest("<not found>");
//		return *inputData;
		
		//option 2
		throw classException("Search object not found"); //failed, don't try to access searchResult->data unless segfault
		
		//option 3 - make an empty object and have client code check if it's empty, to make the <not found> version
//		Type emptyObject;
//		return emptyObject;
	}
	
	return searchResult->data; //otherwise return Type, all is good
}

template <class Type>
Type btree<Type>::searchLName(Type* inputData) const throw(classException)
{
	if(inputData->getLName().empty()) //check for empty input
	{
		throw classException("Can't search with empty lastname");//can't search without proper input
	}
	
	node<Type>* searchResult = rSearchLName(root, inputData);//look for parent of matching node
	
	if(searchResult == NULL) //compare
	{
		//option 1
//		inputData->setDest("<not found>");
//		return *inputData;
		
		//option 2
		throw classException("Search object not found"); //failed, don't try to access searchResult->data unless segfault
		
		//option 3 - make an empty object and have client code check if it's empty, to make the <not found> version
//		Type emptyObject;
//		return emptyObject;
	}
	
	return searchResult->data; //otherwise return Type, all is good
}

template <class Type>
//preconditions: none
//postconditions: none
//description: prints out the contents of the array in order using in order traversal
void btree<Type>::rPrint(node<Type>* currentRoot, bool mode) const
{
	if(currentRoot == NULL) //base case
	{
		//cout << "base case" << endl; //debug
		return;
	}
	
	node<Type>* left;
	node<Type>* right;
	if(mode == 0) //use first set of pointers when mode = 0, second set when mode = 1
	{
		left = currentRoot->left1;
		right = currentRoot->right1;
	}
	else
	{
		left = currentRoot->left2;
		right = currentRoot->right2;
	}
	
	rPrint(left, mode); //recurse left
	currentRoot->data.print(); //print the object
	rPrint(right, mode); //recurse right
}

template <class Type>
//preconditions: none
//postconditions: none
//description: prints out the contents of the array in order
void btree<Type>::print(bool mode) const
{
	rPrint(root, mode);
}
