/*
 * Node.cpp
 * 
 * Description: Node
 *
 * Author: AL
 * Date: July 2016
 */

#include "Node.h"


// Constructors
Node::Node() {
	this->height = 0;
	this->left = NULL;
	this->right = NULL;
}

Node::Node(int element) {
	this->element = element;
	this->height = 0;
	this->left = NULL;
	this->right = NULL;
}

Node::Node(int element, Node* left, Node* right) {
	this->element = element;
	this->height = 0;
	this->left = left;
	this->right = right;	
}

Node::Node(int element, int height, Node* left, Node* right) {
	this->element = element;
	this->height = height;
	this->left = left;
	this->right = right;	
}


// Getters
int Node::getElement() const {
	return element;
}

int Node::getHeight() const {
	return height;
}

Node* Node::getLeft() const {
	return left;
}

Node* Node::getRight() const {
	return right;
}

// Setters
void Node::setElement(int element) {
	this->element = element;
}

void Node::setHeight(int height) {
	this->height = height;
}
	
void Node::setLeft(Node* left) {
	this->left = left;
}

void Node::setRight(Node* right) {
	this->right = right;
}

// Boolean helper functions
bool Node::isLeaf() const {
	return (left == NULL && right == NULL);
}

bool Node::hasLeft() const {
	return (left != NULL);
}

bool Node::hasRight() const {
	return (right != NULL);
}