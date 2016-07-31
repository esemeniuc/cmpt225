/* 
 * SomeList.cpp
 *
 * Description: Link-based implementation of an unsorted List ADT
 *              with the characteristic that 
 *              odd elements are inserted at the front of the List
 *              (i.e., at the front of the link-list) and
 *              the even elements are inserted at the back of the List
 *              (i.e., at the front of the link-list).
 * 
 * Date: July 2016
 *
 */ 

#include "SomeList.h"  // Header file
#include <cassert>
  
// Default Constructor
SomeList::SomeList() {
   Node* head = NULL;
   Node* tail = NULL;
   elementCount = 0;
} // end of default constructor

// Copy Constructor
SomeList::SomeList(const SomeList& rhsSomeList) {
   head = copyLinkedList(rhsSomeList.head);
   elementCount = rhsSomeList.elementCount;
}  // end copy constructor

// Utility method - Copy a linked list
Node* SomeList::copyLinkedList(const Node* originalHead) {
    Node* copiedHead = NULL;

	if (originalHead != NULL)
	{
		// Build new linked list from given one
		copiedHead = new Node(originalHead->data);
		if ( copiedHead != NULL )
			copiedHead->next = copyLinkedList(originalHead->next);
		else
		   return NULL; 
	}  // end if
   
	return copiedHead;
}  // end copylinked list

// Destructor
SomeList::~SomeList() {
   Node* toBeDeleted = head;
   Node* temp = NULL;

   // Traverse the list
   while (toBeDeleted != NULL){
     temp = toBeDeleted -> next; // Go to next Node
     delete toBeDeleted;
     toBeDeleted = temp;
   }
}  // end destructor


// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool SomeList::isEmpty() const {
   return ( elementCount == 0 );
}  // end isEmpty


// Description: Inserts newElement such that 
//              odd elements are inserted at the front of the List
//              (i.e., at the front of the linked list) and
//              the even elements are inserted at the back of the List
//              (i.e., at the front of the linked list). 
//              Example of such resulting List:  3 7 1 5 4 2 8 
//              It returns "true" if successful, otherwise "false". 
// Hint: An odd integer has a remainder of 1 after it has been divided by 2. 
// Time Efficiency: O(1)         
bool SomeList::insert(const int newElement)
{
	
	if(head == NULL || newElement % 2 == 1) //if empty or odd, insert at head
	{
		Node *tempNode = new Node(newElement, head); //make new node
		head = tempNode; //start linked list at new node
		elementCount++;
		return true; //all good
	}

	//if even, traverse until we reach null
	Node* previous = head;
	Node* current = head;
	while(current != NULL) //find insert position
	{
		previous = current;
		current = current->next; //iterate forward
	}
	
	Node* tempNode = new Node(newElement, current);
	previous->next = tempNode; //connect the last element to our new node
	elementCount++;
	return true;
	
} // end insert


// For Testing Purposes - See Labs 3 and 4.
// Description: Prints the content of "this". 
ostream& operator<<(ostream & os, const SomeList& rhs) {
  	Node* current = rhs.head;
	
	// Traverse the list
	while (current != NULL){
		cout << current -> data << " "; // Print data
		current = current -> next; // Go to next Node
	}
	
	return os;
} // end of operator <<

//  End of implementation file.