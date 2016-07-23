//
// Created by eric on 21/07/16.
//

#include "university.h"

//private:
//std::string name;
//std::string address;
//std::string email;
//std::string phone;
//size_t studentCount; //for listInfo()

//preconditions: inputName is not empty
//postconditions: throws classException if inputName is empty
//description: constructor with only university name
university::university(std::string inputName) throw(classException):
name(inputName)
{
	if(inputName.empty()) //can't have empty inputName
	{
		throw(classException("Error: can't have empty inputName"));
	}
}

//preconditions: inputName is not empty
//postconditions: throws classException if inputName is empty
//description: constructor with all fields
university::university(std::string inputName,
					   std::string inputAddress,
					   std::string inputEmail,
					   std::string inputPhone) throw (classException):
name(inputName),
address(inputAddress),
email(inputEmail),
phone(inputPhone)
{
		if(inputName.empty()) //can't have empty inputName
		{
			throw(classException("Error: can't have empty inputName"));
		}
}

//preconditions: none
//postconditions: none
//description: inserts a student into the university in O(log(n)) time
bool university::setStudent(student& inputStudent) const
{
	
}

//preconditions: none
//postconditions: none
//description: lists all of the students attending the university sorted by ID in O(n) time
void university::listStudentsByID(void) const
{
	
}

//preconditions: none
//postconditions: none
//description: lists all of the students attending the university sorted by last name in O(n) time
void university::listStudentsByLName(void) const
{
	
}

//preconditions: none
//postconditions: none
//description: displays all university info in O(1) time
void university::listInfo(void) const
{
	
}