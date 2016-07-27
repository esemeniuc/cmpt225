//
// Created by eric on 21/07/16.
//

#ifndef INC_4_MUSLA_H
#define INC_4_MUSLA_H

#include <cstddef>
#include "student.h"
#include "university.h"
#include "node.h"

#include "classException.h"

const uint8_t muslaDefaultSize = 100; //arbitrarily defined

class musla
{
private:
	
	university** universityArray; //array of universities
	size_t universityCount; //default is 0
	size_t studentCount; //default is 0
	
	university** universityTable; //hashtable for universities
	student** lnameTable; //hashtable for last names
	student** idTable; //hashtable for student ids
	
	//preconditions: none
	//postconditions: none
	//description: generates a hash based on inputInteger and returns it in O(1) time
	size_t hashInteger(uint32_t inputInteger, size_t modulus) const;
	
	//preconditions: none
	//postconditions: none
	//description: generates a hash based on inputInteger and returns it in O(1) time
	size_t hashString(std::string inputString, size_t modulus) const;
	size_t hashString2(std::string inputString, size_t modulus) const;
	
	//preconditions: inputID is a valid input
	//postconditions: a student object with ID == inputID is returned. if not found, then classException is thrown
	//description: looks up a student based on their ID and returns it in O(1) time
	const student& lookupStudentByID(uint32_t inputID) const throw(classException);
	
	//preconditions: inputLName is not empty
	//postconditions: a student object with inputLName is returned. if not found, then classException is thrown
	//description: looks up a student based on their last name and returns it in O(1) time
	const student& lookupStudentByLName(std::string inputLName) const throw(classException);
	
	//preconditions: inputID is > 0
	//postconditions: a student object with ID inputID is returned. if not found, then classException is thrown
	//description: looks up a student based on their ID and returns it in O(1) time
	const university& lookupUniversityByName(std::string inputName) const throw(classException);
	
public:
	//default constructor which allocates universityCount * 2 sized array for
	//hash lookup and studentCount * 2 sized array for students
 	musla(uint32_t inputUniversityCount, uint32_t inputStudentCount);
	
	~musla(); //default destructor
	
	//preconditions: filename is not empty
	//postconditions: returns 0 upon success, 1 on failure
	//description: reads all the file contents from inputFileName
	uint8_t loadFromFile(std::string inputFilename);
	
	//preconditions: inputUniversity is not null
	//postconditions: returns 0 on success, 1 on failure
	//description: inputs a inputUniversity object to musla
	university* addUniversity(university* inputUniversity);
	
	//preconditions: inputUniversity is not null
	//postconditions: returns a matching university object if a match is found, or throws an exception
	//description: returns a matching inputUniversity object
	const university& getUniversity(university* inputUniversity) const throw(classException);
	
	//preconditions: inputStudentLName is not empty
	//postconditions: returns a matching student object if a lname match is found, or throws an exception
	//description: returns a matching student object
	void printAllStudentByLName(std::string& inputStudentLName) const throw(classException);
	
	//preconditions: inputStudentID is not empty
	//postconditions: returns a matching student object if a ID match is found, or throws an exception
	//description: returns a matching student object
	void printAllStudentByID(std::string& inputStudentID) const throw(classException);
	
	//preconditions: none
	//postconditions: none
	//description: displays all university info (not including student info) in O(1) time
	void displayUniversityInfo(void) const;
};


#endif //INC_4_MUSLA_H
