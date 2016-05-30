//
// Created by eric on 28/05/16.
//

#include <cstring>
#include <string.h>
#include "Profile.h"
#include "MyADT.h"

//Attributes:
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

	if(temp == NULL)
	{
		return 1; //error
	}
	memcpy(temp, data[letterIndex], dataCount[letterIndex] * sizeof(Profile)); //copy data[i] into temp

	dataMax[letterIndex] *= 2; //double capacity
	delete[] data[letterIndex]; //clean up old array
	data[letterIndex] = temp; //update the pointer to our new array

	return 0; //all good
}


//gets the index the first letter of a users name, returns -1 if there is an error
//precondition: inputProfile is not null, first letter is between A-Z, a-z
//postcondition: returns the index if it is able to retrieve the first letter (0-25), returns -1 if error appears
int MyADT::getLetterIndex(Profile inputProfile)
{
	string profileName = inputProfile.getName();
	char firstLetter = profileName[0];
	if( firstLetter > 64 && firstLetter < 91 ) //returns uppercase letters
	{
		return firstLetter - 65; //offset by 65 to base 0 (eg. 'A' = 0)
	}

	if( firstLetter > 96 && firstLetter < 123 ) //returns uppercase letters
	{
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
		dataMax[i] = 10; //set the max of each to be 10
	}

};

//Constructor with customizable size of profile per letter, must be greater than 0
//precondition: size is greater than 0
//postcondition: a 2d array 26 x size will be created
MyADT::MyADT(unsigned int size):
data(NULL),
dataCount{0},
totalCount(0)
{
	data = new Profile*[letterCount]; //make new array of profile pointers
	for(int i = 0; i < letterCount; i++) //allocate each the default size for each letter of the alphabet
	{
		data[i] = new Profile[defaultSize];
		dataMax[i] = size; //set the max of each to be size
	}

};

//Destructor
//postcondition: all data in MyADT will be cleared
MyADT::~MyADT()
{
	for(int i = 0; i < letterCount; i++)
	{
		delete[] data[i];
	}

	delete[] data;
}

// Description: Returns the total of elements currently stored in MyADT.
int MyADT::getElementCount() const
{
	return totalCount;
}

// Description: Inserts an element. Returns 1 on error, and 0 if all is good
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
bool MyADT::insert(const Profile& newElement)
{
	//get first character from profile name and check if first letter is valid alphabet character
	int letterIndex = getLetterIndex(newElement);
	if(letterIndex < 0)
	{
		return 1; //error, string doesn't have proper first letter
	}

	//check if profile is already in letter subarray
	string inputName = newElement.getName();
	for (int i = 0; i < dataCount[letterIndex]; i++)
	{
		if ( inputName.compare(data[letterIndex][i].getName()) == 0 ) //if match, then condition will pass
		{
			return 1; //already exists, can't have duplicates
		}
	}

	//check if letter array is full, if so then expand
	if(dataCount[letterIndex] == dataMax[letterIndex])
	{
		expand((unsigned int)letterIndex); //expand the subarray since its full
	}

	//add new profile to letter subarray
	data[letterIndex][dataCount[letterIndex]] = newElement; //insert the new profile
	dataCount[letterIndex]++; //increment our counter
	totalCount++;
	return 0;
}

// Description: Removes an element.
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
}

// Description: Removes all elements.
void MyADT::removeAll()
{
	
}

// Description: Prints all elements stored in MyADT.
ostream & operator<<(ostream & os, const MyADT& rhs)
{
	
}
