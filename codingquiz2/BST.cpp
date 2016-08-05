/*
 * BST.cpp
 * 
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: AL
 * Date: July 2016
 */

#include <iostream>
#include "BST.h"


// Constructors and destructor:
	BST::BST() {
		root = NULL;
		elementCount = 0;
	}
	      
    BST::BST(int& element) {
		root = new Node(element);
		elementCount = 1;	
	}               
	BST::BST(const BST& aBST) {
		root = copy( aBST.root );
		elementCount = aBST.elementCount;
	}     

	Node* BST::copy( Node* aNode ) const {
		
		if ( aNode == NULL ) return NULL;
        
        return new Node( aNode->getElement(), copy( aNode->getLeft() ), copy( aNode->getRight() ) );
 
	} 

	BST::~BST() {
		destroy( root );
	}

	void BST::destroy( Node* aNode ) {
		if ( aNode != NULL ) {
			destroy( aNode->getLeft() );
			destroy( aNode->getRight());
			delete root;
		}
    	root = NULL;
	}                       	
	
	// Getters

// BST operations:
    // Description: Returns the number of elements currently stored in the tree.
	int BST::getElementCount() const {
		return elementCount;
	}


    // Description: Insert an element into the tree.
	//              This is a wrapper method which call recursive insert( ).	
	void BST::insert(const int newElement) { 
        
       Node* newNode = new Node(newElement);
       root = insertR( newNode, root );
       elementCount++;
  	   return;
  	}


	Node* BST::insertR(Node* newNodePtr, Node* currentSubTreePtr) { 

        if ( currentSubTreePtr == NULL ) {
			return newNodePtr;
		}
		else {
            if ( newNodePtr->getElement() < currentSubTreePtr->getElement() ) 
			    currentSubTreePtr->setLeft(insertR(newNodePtr, currentSubTreePtr->getLeft()));
		    else
		     	currentSubTreePtr->setRight(insertR(newNodePtr, currentSubTreePtr->getRight()));
		    return currentSubTreePtr;
		}
	}

	// Description: This public method is a wrapper method,
    //              which calls the recursive heightR(Node *current) defined below.
    //              It returns the height of the tree.
	int BST::height() const {
	    int nodeHeight = heightR(root);

		return nodeHeight;
	}
	
	// Description: Computes the height of each node in the tree 
	//              and stores the height of the node in the node's
	//              attribute "height" (see Node.h).
    //              For example, if current is a leaf, its height is 1.
    //              If current has a leaf as a left and as a right subtree,
    //              its height is 2, etc... If current is NULL, its height is 0.
	int BST::heightR(Node* current) const {
		if(current == NULL) //base case
		{
			return 0;
		}
		
		int leftHeight = 0;
		int rightHeight = 0;
		
		Node* leftNode = current->getLeft();
		Node* rightNode = current->getRight();
		
		if(leftNode != NULL)
		{
			leftHeight = heightR(leftNode);
		}
		if(rightNode != NULL)
		{
			rightHeight = heightR(rightNode);
			
		}
		
		
		if(leftHeight > rightHeight)
		{
			current->setHeight(leftHeight + 1);
			return current->getHeight();
		}
	  	else
		{
			current->setHeight(rightHeight + 1);
			return current->getHeight();
		}
	}
	

	
    // Description:	
	void BST::traverseInOrder() const {
		if (elementCount != 0) 
			traverseInOrderR(root);
		return;
	}
	
	void BST::traverseInOrderR(Node *current) const {
		if (current != NULL) {
			traverseInOrderR(current->getLeft());
            cout << current->getElement() << " ";
			traverseInOrderR(current->getRight());
		}

		return;
	}
		
    // Description:	
	void BST::traverseHeight() const {
		if (elementCount != 0) 
			traverseHeightR(root);
		return;
	}
	
	void BST::traverseHeightR(Node *current) const {
		if (current != NULL) {
			traverseHeightR(current->getLeft());
            cout << current->getElement() << " (" << current->getHeight() << ") ";
			traverseHeightR(current->getRight());
		}

		return;
	}
	