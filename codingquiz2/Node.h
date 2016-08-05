/*
 * Node.h
 * 
 * Description: Node
 *
 * Author: AL
 * Date: July 2016
 */

#pragma once
#include <cstdlib>  // NULL

using namespace std;

class Node {

private:

	// Data members
	int element;
	int height;    // Height of this node in the BST
	Node* left;
	Node* right;

public:

	// Constructors
	Node() ;
    Node(int element);
    Node(int element, Node* left, Node* right);
    Node(int element, int height, Node* left, Node* right);
    

	// Getters
	int getElement() const;
	int getHeight() const;
	Node* getLeft() const;
	Node* getRight() const;

	// Setters
	void setElement(int element);
	void setHeight(int height);
	void setLeft(Node* left);
	void setRight(Node* right);

	// Boolean helper functions
	bool isLeaf() const;
	bool hasLeft() const;
	bool hasRight() const;

};
