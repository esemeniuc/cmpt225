/*
 * filename: MyADT.h or MyADT.cpp
 *
 * Class Description: A data collection ADT class to satisfy Assn 1's requiremetns.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicate).
 *                   - Once it has been ascertained that the element has not already been
 *                     inserted, its data structure allows insertion in O(1)
 *                   - Once the element to be removed as been found,
 *                     its data structure allows removal in O(1).
 *                   - Its data structure is resizable: when full, it expands to accommodate
 *                     new element insertions. This is done unbeknown to the client code.
 *
 * Creation date: 28/05/16
 * Author: Eric Semeniuc
 */

#ifndef INC_1_MYADT_H
#define INC_1_MYADT_H

#include "Profile.h"

class MyADT
{
private:
	//Attributes:

	//2d array of all
	Profile** data[26];

	//Methods:

	//provides the last
	Profile top();

public:
	//Generic constructor, defaults to 10
	MyADT();

	//Constructor with customizable size, must be greater than 0
	MyADT(unsigned int size);

	//Destructor
	~MyADT();

// Description: Returns the total of elements currently stored in MyADT.
	int getElementCount() const;

// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
	bool insert(const Profile& newElement);

// Description: Removes an element.
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
	bool remove(const Profile& toBeRemoved);

// Description: Searches for target element.
	Profile* search(const Profile& target);

// Description: Removes all elements.
	void removeAll();

// Description: Prints all elements stored in MyADT.
	friend ostream & operator<<(ostream & os, const MyADT& rhs);

};


#endif //INC_1_MYADT_H
