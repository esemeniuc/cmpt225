/*
 * Test_Driver.cpp
 *
 * Date: July 2016
 *
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include "BST.h"

using namespace std;


int main () {


  // Test Case 1
  cout << "Test Case 1: 5 3 8 4 7 1 2" << endl;
  
  // Create an empty BST for integers
  BST* myBST = new BST();

  cout << "Inserting 5: " ;
  myBST->insert(5);
  cout << "BST: ";
  myBST->traverseInOrder(); 
  cout << endl;

  cout << "Inserting 3: ";
  myBST->insert(3);
  cout << "BST: ";
  myBST->traverseInOrder(); 
  cout << endl;
    
  cout << "Inserting 8: " ;
  myBST->insert(8);
  cout << "BST: ";
  myBST->traverseInOrder(); 
  cout << endl;
  
  cout << "Inserting 4: " ;
  myBST->insert(4);
  cout << "BST: ";
  myBST->traverseInOrder();
  cout << endl;

  cout << "Inserting 7: " ;
  myBST->insert(7);
  cout << "BST: ";
  myBST->traverseInOrder();
  cout << endl;  

  cout << "Inserting 1: ";
  myBST->insert(1);
  cout << "BST: ";
  myBST->traverseInOrder(); 
  cout << endl;  

  cout << "Inserting 2: ";
  myBST->insert(2);
  cout << "BST: ";
  myBST->traverseInOrder(); 
  cout << endl;  

  cout << endl;
  cout << "There are: " << myBST->getElementCount( ) << " elements" << endl;  
  cout << "The height of this BST is: " << myBST->height() << endl;
  
  myBST->traverseHeight(); 
  cout <<  endl << endl;

  // Test Case 2
  cout << "Test Case 2: <empty BST>" << endl;
  
  // Create an empty BST for integers
  BST* myBST1 = new BST();

  cout << endl;
  cout << "There are: " << myBST1->getElementCount( ) << " elements" << endl;  
  cout << "The height of this BST is: " << myBST1->height() << endl;  
  
  myBST1->traverseHeight(); 
  cout <<  endl << endl;
  

  // Test Case 3
  cout << "Test Case 3: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" << endl;

  // Create an empty BST for integers
  BST* myBST2 = new BST();

  cout << "Inserting 1 x 15 times: " << endl;
  for (int times = 1; times <= 15; times++ ) {
      myBST2->insert(1);     
  }
  cout << "BST: " ;
  myBST2->traverseInOrder();
  cout << endl << endl;
  cout << "There are: " << myBST2->getElementCount( ) << " elements" << endl;  
  cout << "The height of this BST is: " << myBST2->height() << endl;
  
  myBST2->traverseHeight();  
  cout <<  endl << endl;  
 

  // Test Case 4
  cout << "Test Case 4: 2 3 1" << endl;
  
  // Create an empty BST for integers
  BST* myBST3 = new BST(); 

  cout << "Inserting 2: ";
  myBST3->insert(2);
  cout << "BST: ";
  myBST3->traverseInOrder(); 
  cout << endl; 
  cout << "Inserting 3: ";
  myBST3->insert(3);
  cout << "BST: ";
  myBST3->traverseInOrder(); 
  cout << endl;   
  cout << "Inserting 1: ";
  myBST3->insert(1);
  cout << "BST: ";
  myBST3->traverseInOrder(); 
  cout << endl << endl;       

  cout << "There are: " << myBST3->getElementCount( ) << " elements" << endl;  
  cout << "The height of this BST is: " << myBST3->height() << endl;
    
  myBST3->traverseHeight(); 
  cout <<  endl << endl;
  
  
  return 0;
}
