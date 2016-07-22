//
// Created by eric on 21/07/16.
//

#ifndef INC_4_MUSLA_H
#define INC_4_MUSLA_H

#include <cstddef>
#include "student.h"
#include "classException.h"

class musla
{
private:
	size_t universityCount;
	
	student* lnameTable; //hashtable for last names
	student* idTable; //hashtable for student ids
	
public:
	musla(); //default constructor
	~musla(); //default destructor
	
	
	//preconditions: inputLName is not empty
	//postconditions: a student object with inputLName is returned. if not found, then ClassException is thrown
	//description: looks up a student based on their last name and returns it in O(1) time
	student lookupLName(std::string inputLName) const throw(classException);
	
	//preconditions: inputID is > 0
	//postconditions: a student object with ID inputID is returned. if not found, then ClassException is thrown
	//description: looks up a student based on their ID and returns it in O(1) time
	student lookupID(uint32_t inputID) const throw(classException);
};


#endif //INC_4_MUSLA_H
