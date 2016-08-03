// Filename: exQueue.h/exQueue.cpp
// Created by eric on 16/06/16.
// Description:
// An array-based data collection implementation for an expandable queue ADT.
// Author: Eric Semeniuc, David Magaril
// ID: esemeniu_dmagaril

#include <iostream> //debug
#include <algorithm>
#include "exQueue.h"

//Class invariants: FIFO or LILO
/*
private:
	uint32_t dataMax; //maximum number of elements in our array
	uint32_t dataCount; //number of elements in our exQueue
	uint32_t dataStart; //start of elements that haven't been popped
	string* dataArray; //array of data elements in the exQueue
*/

// Description: default constructor for an empty exQueue
exQueue::exQueue():
		dataMax(exQueueDefaultMax),
		dataCount(0),
		dataStart(0)
{
	dataArray = new std::string[exQueueDefaultMax];
}


// Description: default destructor for an empty exQueue
exQueue::~exQueue()
{
	dataCount = 0;
	dataStart = 0;
	delete[] dataArray;
}

// Description: Returns the number of valid elements in exQueue
// Time Efficiency: O(1)
uint32_t exQueue::getSize() const
{
	return dataCount - dataStart;
}

//expands the array size to be 2 times the original size. returns 0 on success, 1 on error
//precondition: the data array is not null and dataMax is > 0
//postcondition: the data array is 2x as large and dataMax is doubled
uint8_t exQueue::expand(void)
{
	std::string* tempArray = new std::string[2 * dataMax]; //double the size of the old array
	//cout << "Size of profile: " << sizeof(Profile) << endl;
	copy(dataArray+dataStart, dataArray + dataCount, tempArray); //copy profiles into temp, starting from beginning
//	for(int i = 0; i < dataCount; i++)
//	{
//		tempArray = data[dataCount+i];
//	}
	
	dataMax *= 2; //double capacity
	delete[] dataArray; //clean up old array
	dataArray = tempArray; //update the pointer to our new array
	
	dataCount -= dataStart; //rebase back to 0
	dataStart = 0; //no need to begin offset
	return 0; //all good
}

// Description: Adds inputData to the top of exQueue and
//              returns 0 if successful, otherwise 1.
// Time Efficiency: O(1)
uint8_t exQueue::push(const std::string inputData)
{
	//check if array is full, if so then expand
	if(dataCount == dataMax)
	{
		expand(); //expand the array since its full
//		uint8_t status = expand(); //expand the array since its full
//		cout << "Expand status: " << (int)status << " Size: " << dataMax << endl;
	}
	
	//add the new element to the array
	dataArray[dataCount] = inputData; //insert the new element
	dataCount++; //increment our counter
//	cout << dataCount << " " << dataMax << endl; //debug
	return 0; //all good
	
}

// Description: Removes the element at the bottom/front of exQueue and
//              returns it
// Precondition: This exQueue is not empty.
// Exceptions: Throws classException if this exQueue is empty.
// Time Efficiency: O(1)
std::string exQueue::pop(void) throw(classException)
{
	//cout << "#" << dataArray[dataStart] << ": Size: " << dataStart << " Count: " << dataCount << " Max: " << dataMax << endl;
	if((dataCount - dataStart) <= 0) //check for empty exQueue
	{
		throw classException("Cannot pop from an empty exQueue");
	}
	
	//remove element from the array
	dataStart++; //decrement our counter
	return dataArray[dataStart-1]; //all good
}

// Description: randomizes the elements of dataArray
// Precondition: This exQueue is not empty.
// Time Efficiency: O(n)
void exQueue::randomize(void)
{
	if((dataCount - dataStart) >= 2) //no need to shuffle a tiny array
	{
		random_shuffle(&dataArray[dataStart], &dataArray[dataCount]);
	}
	return; //nothing else to do
}

//Description: prints out the contents of the exQueue
//Preconditions: none
//Postconditions: prints out the contents of the exQueue
void exQueue::print(void) const //debug
{
//	cout << "call print" << endl;
	for(unsigned int i = dataStart; i < dataCount; i++)
	{
		std::cout << dataArray[i] << std::endl;
	}
}
