/*
 * filename: MyADT.h
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
const int letterCount = 26; //a-z
const int defaultSize = 2; //arbritrarily set

class MyADT
{
private:
	//Attributes:

	//2d array of all letters of the alphabet
	Profile** data;

	//profile counts of each letter of the alphabet
	//unsigned int dataCount[letterCount];

	//max capacity of profiles for each letter of the alphabet
	unsigned int dataMax[letterCount];

	//how many profiles are stored in MyADT in total
	unsigned int totalCount;

	//Methods:*******************************************

	//expands the array size to be 2 times the original size. returns 0 on success, 1 on error
	//precondition: the data[letter] subarray is not null and dataMax[letter] is > 0
	//postcondition: the data[letter] subarray is 2x as large and dataMax[letter] is doubled
	int expand(unsigned int letterIndex);

	//gets the index the first letter of a users name, returns -1 if there is an error
	//precondition: inputProfile is not null, first letter is between A-Z, a-z
	//postcondition: returns the index if it is able to retrieve the first letter, returns -1 if error appears
	int getLetterIndex(const Profile inputProfile);

	//returns the index of a input profile. If not found, getProfileIndex returns -1
	//Preconditions: Profile is has a valid name, and there exists profiles in MyADT
	//Postcondition: returns the index of profile name match the input profile
	int getProfileIndex(const Profile inputProfile, const unsigned int inputLetterIndex);

public:
	unsigned int dataCount[letterCount];

	//Generic constructor, defaults to 10 profiles per letter of the alphabet
	//postcondition: a 2d array of size 26 x 10 will be created
	MyADT();

	//Destructor
	//postcondition: all data in or associated with MyADT will be cleared
	~MyADT();

// Description: Returns the total of elements currently stored in MyADT.
// Postcondition: The element (a positive integer) is returned
	int getElementCount() const;

// Description: Inserts an element. Returns 1 on success, and 0 on failure
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
	bool insert(const Profile& newElement);

// Description: Removes an element. Returns 1 on success, and 0 on failure
// Precondition: a valid name string is provided
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
	bool remove(const Profile& toBeRemoved);

// Description: Searches for target element.
// Precondition: a string for a name is entered
// Postcondition: On success returns a profile with a matching name; On failure, NULL is returned
	Profile* search(const Profile& target);

// Description: Removes all elements.
// Postcondition: All elements in the data array will be remove, and array sizes will be reset to defaultSize
	void removeAll();

// Description: Prints all elements stored in MyADT.
	friend ostream & operator<<(ostream & os, const MyADT& rhs);

	//Dumps the contents of the array
	void contentDumper(void);
};


#endif //INC_1_MYADT_H
