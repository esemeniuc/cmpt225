/*
 * filename: MyADT.cpp
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
#include <iostream>
#include <cstring>
#include "Profile.h"
#include "MyADT.h"

//MyADT Class Attributes:
/*
	//2d array of all letters of the alphabet
	Profile** data[letterCount];

	//profile counts of each letter of the alphabet
	unsigned int dataCount[letterCount];

	//profile max capacity of each letter of the alphabet
	unsigned int dataMax[letterCount];

	//how many profiles in total
	unsigned int totalCount;
*/

//Private Methods:

//expands the array size to be 2 times the original size. returns 0 on success, 1 on error
//precondition: the data[letter] subarray is not null and dataMax[letter] is > 0
//postcondition: the data[letter] subarray is 2x as large and dataMax[letter] is doubled
int MyADT::expand(unsigned int letterIndex)
{
	Profile* temp = new(std::nothrow) Profile[2 * dataCount[letterIndex]]; //double the size of the old array

	memcpy(temp, data[letterIndex], dataCount[letterIndex] * sizeof(Profile)); //copy data[i] into temp

	dataMax[letterIndex] *= 2; //double capacity
	delete[] data[letterIndex]; //clean up old array
	data[letterIndex] = temp; //update the pointer to our new array

	return 0; //all good
}


//gets the index the first letter of a users name, returns -1 if there is an error
//precondition: inputProfile is not null, first letter is between A-Z, a-z
//postcondition: returns the index if it is able to retrieve the first letter (0-25), returns -1 if error appears
int MyADT::getLetterIndex(const Profile inputProfile)
{
	string profileName = inputProfile.getName();
	char firstLetter = profileName[0];

	//check if character is in valid range
	if( firstLetter > 64 && firstLetter < 91 ) //returns uppercase letters
	{
		//cout << "Found Index: " << firstLetter - 65 << endl; //remove me
		return firstLetter - 65; //offset by 65 to base 0 (eg. 'A' = 0)
	}
	else if( firstLetter > 96 && firstLetter < 123 ) //returns lowercase letters
	{
		//cout << "Found Index: " << firstLetter - 97 << endl; //remove me
		return firstLetter - 97; //offset by 97 to base 0 (eg. 'a' = 0)
	}

	return -1; //not valid input, out of bounds
}

//returns the index of a input profile. If not found, getProfileIndex returns -1
//Preconditions: Profile is has a valid name, and there exists profiles in MyADT
//Postcondition: returns the index of profile name match the input profile
int MyADT::getProfileIndex(const Profile inputProfile, const unsigned int inputLetterIndex) {
	//check for valid inputLetterIndex
	if (inputLetterIndex < 0) {
		return -1; //error, string doesn't have proper first letter
	}

	//check if profile is in letter subarray, if yes, return the index
	string inputName = inputProfile.getName();
	for (int i = 0; i < dataCount[inputLetterIndex]; i++)
	{
		if ( inputName.compare(data[inputLetterIndex][i].getName()) == 0 ) //if match, then condition will pass
		{
			return i; //found it, return the index
		}
	}

	return -1; //not found
}



//Public Methods:

//Generic constructor, defaults to 10 profiles per letter of the alphabet
//postcondition: a 2d array of size 26 x 10 will be created
MyADT::MyADT():
data(NULL),
dataCount{0},
totalCount(0)
{
	data = new Profile*[letterCount]; //make new array of profile pointers
	for(int i = 0; i < letterCount; i++) //allocate each the default size for each letter of the alphabet
	{
		data[i] = new Profile[defaultSize];
		dataMax[i] = defaultSize; //set the max of each to be 10
	}

};


//Destructor
//postcondition: all data in or associated with MyADT will be cleared
MyADT::~MyADT()
{
	for(int i = 0; i < letterCount; i++)
	{
		delete[] data[i];
	}

	delete[] data;
}

// Description: Returns the total of elements currently stored in MyADT.
// Postcondition: The element (a positive integer) is returned
int MyADT::getElementCount() const
{
	return totalCount;
}

// Description: Inserts an element. Returns 1 on success, and 0 on failure
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
bool MyADT::insert(const Profile& newElement)
{
	//get first character from profile name and check if first letter is valid alphabet character
	int letterIndex = getLetterIndex(newElement);
	if(letterIndex < 0)
	{
		return 0; //error, string doesn't have proper first letter
	}

	//check if profile is already in letter subarray
	string inputName = newElement.getName();
	for (int i = 0; i < dataCount[letterIndex]; i++)
	{
		if ( inputName.compare(data[letterIndex][i].getName()) == 0 ) //if match, then condition will pass
		{
			return 0; //already exists, can't have duplicates
		}
	}

	//check if letter array is full, if so then expand
	if(dataCount[letterIndex] == dataMax[letterIndex])
	{
		expand((unsigned int)letterIndex); //expand the letter subarray since its full
	}

	//add new profile to letter subarray
	data[letterIndex][dataCount[letterIndex]] = newElement; //insert the new profile
	dataCount[letterIndex]++; //increment our counter
	totalCount++;

	return 1; //all good
}

// Description: Removes an element. Returns 1 on success, and 0 on failure
// Precondition: a valid name string is provided
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
bool MyADT::remove(const Profile& toBeRemoved)
{
	//get first character from profile name
	int letterIndex = getLetterIndex(toBeRemoved);
	if(letterIndex < 0)
	{
		return 1; //error, string doesn't have proper first letter
	}

	//find whats the index of profile to be deleted
	int profileIndexToBeRemoved = getProfileIndex(toBeRemoved, (unsigned int)letterIndex);

	//remove profile from the letter subarray
	data[letterIndex][profileIndexToBeRemoved] = data[letterIndex][dataCount[letterIndex]]; //move last profile into spot to be deleted
	//data[letterIndex][dataCount[letterIndex]] = NULL; //null the last value
	dataCount[letterIndex]--; //increment our counter
	totalCount--;
	return 0; //all good
}

// Description: Searches for target element.
// Precondition: a string for a name is entered
// Postcondition: On success returns a profile with a matching name; On failure, NULL is returned
Profile* MyADT::search(const Profile& target)
{
	//get first character from profile name and check if first letter is valid alphabet character
	int letterIndex = getLetterIndex(target);
	if(letterIndex < 0)
	{
		return NULL; //error, string doesn't have proper first letter
	}

	int targetProfileIndex = getProfileIndex(target, (unsigned int)letterIndex); //find the index

	if(targetProfileIndex > -1 )
	{
		return &data[letterIndex][targetProfileIndex];
	}

	return NULL;
}

// Description: Removes all elements.
// Postcondition: All elements in the data array will be remove, and array sizes will be reset to defaultSize
void MyADT::removeAll()
{
	for(int i = 0; i < letterCount; i++)
	{
		delete[] data[i]; //remove old array
		data[i] = new Profile[defaultSize]; //create new array
		dataCount[i] = 0; //reset the profile count
		dataMax[i] = defaultSize; //set the max of each to be 10
	}

	totalCount = 0;
}

// Description: Prints all elements stored in MyADT.
ostream& operator<<(ostream& os, const MyADT& rhs)
{
	for(int i = 0; i < letterCount; i++) //iterate through all letters
	{
		for(int j = 0; j < rhs.dataCount[i]; j++) //iterate through all elements of each letter
		{
			//Profile& p = rhs.data[i][j];
			//example: Barb, No image yet, Just joined, with 0 friends
			os << rhs.data[i][j].getName() << ", " << rhs.data[i][j].getImage() << ", " << rhs.data[i][j].getStatus() << ", with " << rhs.data[i][j].getNumberOfFriends() << " friends" << endl; //fixme
		}
	}
	return os;
}

// Description: Dumps all elements stored in MyADT.
void MyADT::contentDumper(void)
{
	for(int i = 0; i < letterCount; i++) //iterate through all letters
	{
		cout << "Letter: " << (char)(i + 65) << " Letter Count: " << dataCount[i] << " Letter Max:" << dataMax[i] << endl;
		for(int j = 0; j < dataCount[i]; j++) //iterate through all elements of each letter
		{
			Profile p = data[i][j];
			//example: Barb, No image yet, Just joined, with 0 friends
			cout << p.getName() << ", " << p.getImage() << ", " << p.getStatus() << ", with " << p.getNumberOfFriends() << " friends" << endl;
		}
	}
	return;
}
