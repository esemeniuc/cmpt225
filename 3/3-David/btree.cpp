/*
 * filename: btree.cpp
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
// Time Efficiency: O(1)
btree::btree():
root(NULL),
nodeCount(0)
{
	//nothing else to do
}

//preconditions: root in not NULL
//postconditions: frees all the memory from the tree using in-order traversal
//description: for use in the default deconstructor, recursively deconstructs.
// Time Efficiency: O(n)

void btree::deleteAll(node* current){
	//std::cout << "GO" << std::endl;
	if(current != NULL){
		if(current->left != NULL){
			deleteAll(current->left);
		}
		if(current->right != NULL){
			deleteAll(current->right);
		}	
		delete current;
		//std::cout << "WENT" << std::endl;
	}
}

//preconditions: tree object exists
//postconditions: frees all the memory from the tree using in-order traversal
//description: default destructor
// Time Efficiency: O(n)
btree::~btree()
{
	deleteAll(root);//do a in-order traversal and delete each node
}



//preconditions: tree is not empty, and the shell object is not empty
//postconditions: a word object matching inputSrc is returned, otherwise NULL is returned or throw exception
//description: finds a word matching inputSrc if it exists in the tree
// Time Efficiency: O(logN)
std::string btree::rSearch(node* root, std::string inputData) const
{
	//std::cout << "GO" << std::endl;
	if(root == NULL)
	{
		return ""; // Represents false
	}
	int path = (root->data).compare(0,root->segIndex,inputData);
	//std::cout << "OB " << path << " " << inputData << " " << root->data << " " << root->segIndex << std::endl;
	if(path == 0){
		//std::cout << "OBS" << std::endl;
		return root->data;
	}
	else if(path>0)
	{
		//std::cout << "OBS2" << std::endl;
		return rSearch(root->left, inputData);
		
	}
	else
	{
		//std::cout << "OBS3" << std::endl;
		return rSearch(root->right, inputData);
	}
	
}


//preconditions: inputNode has a valid filled class
//postconditions: inserts our new node
//description: finds the correct parent node to allow insertion a child node
// Time Efficiency: O(logN)
void btree::rInsert(node* currentRoot, node* inputNode, node* previous, bool goLeft)
{
	if(currentRoot == NULL) //base case
	{
		//std::cout << "NULLREACH" << std::endl;
		//fix me
		if(goLeft){
			previous->left = inputNode; //insert our node
		}
		else {
			previous->right = inputNode;
		}
		return;
	}
	else if(currentRoot->data == inputNode->data) //check for duplicates
	{
		//std::cout << "SAME" << std::endl;
		return; // don't want duplicates -- David: TODO this assumes that there won't be any updates to dictionary.
							// Maybe replace instead?
		//-- Not tested code below.
		//currentRoot->data = inputNode->data;
		// delete inputNode;
		//return;
		//--
	}
	
	else if(inputNode->data < currentRoot->data) // Go left
	{
		//std::cout << "GOLEFT" << std::endl;
		return rInsert(currentRoot->left, inputNode, currentRoot, true);
	}
	else // Go right
	{
		//std::cout << "GORIGHT" << std::endl;
		return rInsert(currentRoot->right, inputNode, currentRoot, false); 
	}
	
}

//preconditions: inputData.isEmpty() >= 1 (at least 1 term is entered)
//postconditions: returns 0 if successfully inputted, 1 if there is an error
//description: creates a node to insert in sorted order (based on src) into the tree
// Time Efficiency: O(logN)
uint8_t btree::insert(std::string inputData)
{

	// --- --- IF STRING
	bool valid = false;
	if(inputData.length() == 0){
		//ERROR
	}
	unsigned int segIndex = 0; 
	for(unsigned int i = 0;i<inputData.length();i++){ // Turn into lowercase. This will not make the translation translated, as
								// in example data.
		char letter = inputData[i];
		if(letter == 58){
			valid = true;
			if(i+1 == inputData.length()){
				// Translation has no meaning.
				// ERROR OR DISREGARD
			}
			if(i==0){
				// English has no meaning.
				// ERROR OR DISREGARD
			}
			segIndex = i;
			break; // Detected ":"
		}
		if(letter>64 && letter<91){
			inputData[i] = (letter)+32;
		}
	}
	if(valid==false){ // Means ":" was not found.
		//ERROR
	}
	// --- --- IF STRING
	
	//create a node to insert based input params
	node* tempNode = new node(inputData,segIndex); //pass in inputData
	
	//if root is NULL, then insert at root
	if(root == NULL)
	{
		root = tempNode; //make the new node our root
		nodeCount++; //update counter
		return 0; //all good
	}
	
	//find proper place in tree to insert the node
	rInsert(root, tempNode, NULL, false);
	nodeCount++; //increment count
	return 0; //all good
}

//preconditions: none
//postconditions: a word object matching inputSrc is returned, otherwise NULL is returned or throw exception
//description: recursively calls rSearch and stops when a word matching inputSrc is found, or reaches bottom of the tree
// Time Efficiency: O(logN)
std::string btree::search(std::string inputData)
{
	//std::cout << "OKAYer " << inputData.length() << std::endl;
	if(inputData.length() == 0) //check for empty input
	{
		std::cout << "Can't search with empty input!" << std::endl; //can't search without proper input
	}
	//std::cout << "OKAYerd" << std::endl;
	std::string searchResult = rSearch(root, inputData); //look for parent of matching node
	//std::cout << "OKAYerdo" << std::endl;
	if(searchResult == "") //compare
	{
		//std::cout << "OKAYerdosdo" << std::endl;
		std::cout << "Word does not exist!" << std::endl; //failed, don't try to access searchResult->data unless segfault
	}
	
	//std::cout << "OKAYerds" << std::endl;
	return searchResult; //all good
}


//preconditions: none
//postconditions: none
//description: prints out the contents of the array in order
// Time Efficiency: O(N)
void btree::rPrint(node* currentRoot) const
{
	if(currentRoot == NULL) //base case
	{
		return;
	}

	rPrint(currentRoot->left);
	std::cout << currentRoot->data << std::endl;
	rPrint(currentRoot->right);
}

//preconditions: none
//postconditions: none
//description: prints out the contents of the array in order
// Time Efficiency: O(N)
void btree::print(void) const
{
	rPrint(root);
}
