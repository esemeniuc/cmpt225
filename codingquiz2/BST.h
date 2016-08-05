/*
 * BST.h
 * 
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: AL
 * Date: July 2016
 */
 
#pragma once
#include <cstdlib>  // NULL
#include "Node.h"

/** BST - Linked implementation. */

using namespace std;

class BST {
	
private:
	Node* root;        // Pointer to root node of tree
    int elementCount;  // Number of elements stored in the tree

    // Utility methods
    Node* copy( Node* aNode ) const;
    void destroy( Node* aNode );

	Node* insertR(Node* newNodePtr, Node* currentSubTreePtr);

	void traverseInOrderR(Node* current) const;
    void traverseHeightR(Node* current) const;

	// Description: Computes the height of each node in the tree 
	//              and stores the height of the node in the node's
	//              attribute "height" (see Node.h).
    //              For example, if current is a leaf, its height is 1.
    //              If current has a leaf as a left and as a right subtree,
    //              its height is 2, etc... If current is NULL, its height is 0.
	int heightR(Node *current) const;
		
public:
// Constructors and destructor:
	BST();                         // Default constructor
    BST(int& element);             // Parameterized constructor 
	BST(const BST& rhs);           // Copy constructor
    ~BST();                        // Destructor
	
// BST operations:
    // Description:
	int getElementCount() const;

    // Description: Insert an element into the tree.
	//              This is a wrapper method which call recursive insert( ).
	void insert(int newElement); 

	
    // Description:	
	void traverseInOrder() const;
	void traverseHeight() const;
		
	// Description: This public method is a wrapper method,
    //              which calls the recursive heightR(Node *current).
    //              It returns the height of the tree.
    int height() const;

	
}; // end BST
