//
// Created by eric on 21/07/16.
//

#ifndef INC_4_MUSLA_H
#define INC_4_MUSLA_H

#include <cstddef>
#include "student.h"
#include "classException.h"
#include "university.h"

const uint8_t muslaDefaultSize = 100; //arbitrarily defined

class musla
{
private:
	size_t universityCount; //default is 0
	
	student** lnameTable; //hashtable for last names
	student** idTable; //hashtable for student ids
	
public:
	musla(); //default constructor
	~musla(); //default destructor
	
	//preconditions: inputID is > 0
	//postconditions: a student object with ID inputID is returned. if not found, then ClassException is thrown
	//description: looks up a student based on their ID and returns it in O(1) time
	const student& lookupID(uint32_t inputID) const throw(classException);
	
	//preconditions: inputLName is not empty
	//postconditions: a student object with inputLName is returned. if not found, then ClassException is thrown
	//description: looks up a student based on their last name and returns it in O(1) time
	const student& lookupLName(std::string inputLName) const throw(classException);
	
	//preconditions: inputUniversity is not null
	//postconditions: returns a matching university object if a match is found, or throws an exception
	//description: returns a matching inputUniversity object
	const university& getUniversity(university* inputUniversity) const throw(classException);
	
	//preconditions: inputUniversity is not null
	//postconditions: returns 0 on success, 1 on failure
	//description: inputs a inputUniversity object to musla
	bool setUniversity(university* inputUniversity);
	
	//preconditions: inputStudentLName is not empty
	//postconditions: returns a matching student object if a lname match is found, or throws an exception
	//description: returns a matching student object
	const student& getStudentLName(std::string& inputStudentLName) const throw(classException);
	
	//preconditions: inputStudentID is not empty
	//postconditions: returns a matching student object if a ID match is found, or throws an exception
	//description: returns a matching student object
	const student& getStudentID(std::string& inputStudentID) const throw(classException);
};


#endif //INC_4_MUSLA_H
