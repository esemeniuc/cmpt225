/*
 * SomeList_Test_Driver.cpp
 *
 * Date: July 2016
 *
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include "SomeList.h"

using namespace std;


int main () {

  // Create an empty SomeList 
  SomeList* mySomeList = new SomeList();

  // Testing Insert 
  cout << "Test Case 1 - Testing insert with odd and even elements!" << endl;
  cout << "Test data: 5 4 1 2 8 7 3" << endl;
  cout << "Expected Result: 3 7 1 5 4 2 8" << endl;

  cout << "Inserting 5: ";
  mySomeList->insert(5);
  cout << *mySomeList << endl; 

  cout << "Inserting 4: ";
  mySomeList->insert(4);
  cout << *mySomeList << endl; 

  cout << "Inserting 1: ";
  mySomeList->insert(1);
  cout << *mySomeList << endl; 

  cout << "Inserting 2: ";
  mySomeList->insert(2);
  cout << *mySomeList << endl; 

  cout << "Inserting 8: ";
  mySomeList->insert(8);
  cout << *mySomeList << endl;

  cout << "Inserting 7: ";
  mySomeList->insert(7);
  cout << *mySomeList << endl; 

  cout << "Inserting 3: ";
  mySomeList->insert(3);
  cout << *mySomeList << endl;


  // Create an empty SomeList 
  SomeList* mySomeList1 = new SomeList();

 // Testing Insert
  cout << "Test Case 2 - Testing insert with even elements!" << endl;
  cout << "Test data: 6 12 2 8" << endl;
  cout << "Expected Result: 6 12 2 8" << endl;

  cout << "Inserting 6: ";
  mySomeList1->insert(6);
  cout << *mySomeList1 << endl; 

  cout << "Inserting 12: ";
  mySomeList1->insert(12);
  cout << *mySomeList1 << endl; 

  cout << "Inserting 2: ";
  mySomeList1->insert(2);
  cout << *mySomeList1 << endl; 

  cout << "Inserting 8: ";
  mySomeList1->insert(8);
  cout << *mySomeList1 << endl; 


  // Create an empty SomeList
  SomeList* mySomeList2 = new SomeList();

 // Testing Insert
  cout << "Test Case 3 - Testing insert with odd elements!" << endl;
  cout << "Test data: 5 13 1 9 81" << endl;
  cout << "Expected Result: 81 9 1 13 5" << endl;

  cout << "Inserting 5: ";
  mySomeList2->insert(5);
  cout << *mySomeList2 << endl; 

  cout << "Inserting 13: ";
  mySomeList2->insert(13);
  cout << *mySomeList2 << endl; 

  cout << "Inserting 1: ";
  mySomeList2->insert(1);
  cout << *mySomeList2 << endl; 

  cout << "Inserting 9: ";
  mySomeList2->insert(9);
  cout << *mySomeList2 << endl; 

  cout << "Inserting 81: ";
  mySomeList2->insert(81);
  cout << *mySomeList2 << endl;
  
  // Create an empty SomeList
  SomeList* mySomeList3 = new SomeList();
  
  // Testing Insert
  cout << "\n\nTest Case 4 - Testing insert with mixed elements!" << endl;
  cout << "Test data: 4 5 9 1214" << endl;
  cout << "Expected Result: 9 5 4 1214" << endl;
  
  cout << "Inserting 4: ";
  mySomeList3->insert(4);
  cout << *mySomeList3 << endl;
  
  cout << "Inserting 5: ";
  mySomeList3->insert(5);
  cout << *mySomeList3 << endl;
  
  cout << "Inserting 9: ";
  mySomeList3->insert(9);
  cout << *mySomeList3 << endl;
  
  cout << "Inserting 1214: ";
  mySomeList3->insert(1214);
  cout << *mySomeList3 << endl;
  
  return 0;
}
