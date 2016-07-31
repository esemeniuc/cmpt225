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

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;


class SomeList {

private:
   Node* head;         // Pointer to first node in the chain
   Node* tail;         // Pointer to last node in the chain
   int elementCount;   // Current count of list items
   

   // Utility method - Copy a linked list
   Node* copyLinkedList(const Node* originalHead);

   
public:
   // Default Constructor
   SomeList();
   // Copy Constructor
   SomeList(const SomeList& rhsSomeList);
   // Destructor
   ~SomeList();   
   
   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
   

   // Description: Inserts newElement such that 
   //              odd elements are inserted at the front of the List
   //              (i.e., at the front of the link-list) and
   //              the even elements are inserted at the back of the List
   //              (i.e., at the front of the link-list).  
   //              It returns "true" if successful, otherwise "false".
   // Hint: An odd integer has a remainder of 1 after it has been divided by 2. 
   // Time Efficiency: O(1)       
   bool insert(const int newElement);     
      

   // For Testing Purposes - See Labs 3 and 4.
   // Description: Prints the content of "this". 
   friend ostream & operator<<(ostream & os, const SomeList& rhs);
   
}; // end SomeList