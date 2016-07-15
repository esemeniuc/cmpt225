// Filename: stack.h/stack.cpp
// Created by eric on 16/06/16.
// Description:
//A data collection stack ADT class. This class ***must not*** print anything
//on the computer monitor screen. Name this class stack (stack.h and stack.cpp).
//Use an array-based implementation for this stack class and make sure our
//implementation abides to its Public Interface described below (expressed in C++):

#include "stack.h"
#include <iostream> //debug
#include <algorithm>

//Class invariants: FIFO or LILO
/*
private:
	unsigned int dataMax; //maximum number of elements in our array
	
	unsigned int dataCount; //number of elements in our stack
	
	word* dataArray; //array of data elements in the stack
*/

// Description: default constructor for an empty stack
stack::stack():
		dataMax(stackDefaultMax),
		dataCount(0)
{
	dataArray = new word[stackDefaultMax];
}


// Description: default destructor for an empty stack
stack::~stack()
{
	dataCount = 0;
	delete[] dataArray;
}

// Description: Returns the size of the stack
// Time Efficiency: O(1)
uint32_t stack::getSize() const
{
	return dataCount;
}

//expands the array size to be 2 times the original size. returns 0 on success, 1 on error
//precondition: the data array is not null and dataMax is > 0
//postcondition: the data array is 2x as large and dataMax is doubled
uint8_t stack::expand(void)
{
	word* tempArray = new word[2 * dataMax]; //double the size of the old array
	//cout << "Size of profile: " << sizeof(Profile) << endl;
	copy(dataArray, dataArray + dataCount, tempArray); //copy profiles into temp
//	for(int i = 0; i < dataCount; i++)
//	{
//		tempArray = data[i];
//	}
	
	dataMax *= 2; //double capacity
	delete[] dataArray; //clean up old array
	dataArray = tempArray; //update the pointer to our new array
	return 0; //all good
}

// Description: Adds inputData to the of this stack and
//              returns 0 if successful, otherwise 1.
// Time Efficiency: O(1)
uint8_t stack::push(const word& inputData)
{
	//check if letter array is full, if so then expand
	if(dataCount == dataMax)
	{
		//expand(); //expand the array since its full
		uint8_t status = expand(); //expand the array since its full
		cout << "Expand status: " << (int)status << " Size: " << dataMax << endl;
	}
	
	//add the new element to the array
	dataArray[dataCount] = inputData; //insert the new element
	dataCount++; //increment our counter
	return 0; //all good
	
}

// Description: Removes the element at the "front" of this stack and
//              returns it
// Precondition: This stack is not empty.
// Exceptions: Throws ClassException if this stack is empty.
// Time Efficiency: O(1)
word stack::pop(void) throw(ClassException)
{
	if(dataCount == 0) //check for empty stack
	{
		throw ClassException("Cannot pop from an empty stack");
	}
	
	//remove element from the array
	dataCount--; //decrement our counter
	return dataArray[dataCount]; //all good
}

// Description: randomizes the elements of dataArray
// Precondition: This stack is not empty.
// Time Efficiency: O(n)
void stack::randomizeStack(void)
{
	if(dataCount >= 2) //no need to shuffle a tiny array
	{
		random_shuffle(&dataArray[0], &dataArray[dataCount]);
	}
	return; //nothing else to do
}

//Description: prints out the contents of the stack
//Preconditions: none
//Postconditions: prints out the contents of the stack
void stack::print(void) const //debug
{
	cout << "call print" << endl;
	for(unsigned int i = 0; i < dataCount; i++)
	{
		dataArray[i].print();
	}
}
