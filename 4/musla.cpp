//
// Created by eric on 21/07/16.
//

#include "musla.h"

//private:
//	size_t universityCount; //default is 0
//
//	student* lnameTable; //hashtable for last names
//	student* idTable; //hashtable for student ids

//default constructor
musla::musla():
universityCount(0)
{
	lnameTable = new student[muslaDefaultSize];
	idTable = new student[muslaDefaultSize];
	//nothing else to do
}

//default destructor
musla::~musla()
{
	universityCount = 0;
	delete lnameTable;
	delete idTable;
}

//preconditions: inputID is > 0
//postconditions: a student object with ID inputID is returned. if not found, then ClassException is thrown
//description: looks up a student based on their ID and returns it in O(1) time
student musla::lookupID(uint32_t inputID) const throw(classException)
{
	
}

//preconditions: inputLName is not empty
//postconditions: a student object with inputLName is returned. if not found, then ClassException is thrown
//description: looks up a student based on their last name and returns it in O(1) time
student musla::lookupLName(std::string inputLName) const throw(classException)
{
	
}
