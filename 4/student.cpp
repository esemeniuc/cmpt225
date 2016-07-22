//
// Created by eric on 21/07/16.
//

#include <iostream>
#include "student.h"

//private:
//	std::uint32_t studentNumber;
//	std::string lastName;
//	std::string firstName;
//	std::string address;
//	std::string email;
//	std::string enrolled[studentEnrollmentMax];
//	uint32_t enrolledCount;
//	std::string faculty;

//constructor with just studentNumber
//preconditions: studentNumber must not be blank
student::student(uint32_t inputStudentNumber) throw(classException):
		studentNumber(inputStudentNumber)
{
	if(inputStudentNumber == 0) //can't have empty studentNumber
	{
		throw(classException("Error: can't have empty studentNumber"));
	}
}

//constructor with just lastName
//preconditions: lastName must not be blank
student::student(std::string inputLastName) throw(classException):
		lastName(inputLastName)
{
	if(inputLastName.empty()) //can't have empty lastName
	{
		throw (classException("Error: can't have empty lastName"));
	}
}

//student constructor with parameters for all fields
//preconditions: studentNumber and lastName must not be blank
student::student(uint32_t inputStudentNumber,
				 std::string inputLastName,
				 std::string inputFirstName,
				 std::string inputAddress,
				 std::string inputEmail,
				 std::string inputEnrolled[],
				 uint32_t inputEnrolledCount,
				 std::string inputFaculty) throw(classException):
		studentNumber(inputStudentNumber),
		lastName(inputLastName),
		firstName(inputFirstName),
		address(inputAddress),
		email(inputEmail),
		enrolledCount(inputEnrolledCount),
		faculty(inputFaculty)
{
	if(inputStudentNumber == 0 || inputLastName.empty()) //can't have empty studentNumber or lastName
	{
		throw(classException("Error: can't have empty studentNumber or lastName"));
	}
	
	std::copy(inputEnrolled, inputEnrolled + inputEnrolledCount, enrolled);
}

//default destructor
student::~student()
{
	//nothing to do here
}

//preconditions: none
//postconditions: none
//description: prints out the student's info in O(1) time
void student::print(void) const
{
	std::cout << "Student #:\t" << studentNumber << "\nLastname:\t" << lastName << "\nFirstname:\t" << firstName << "\nAddress:\t" << address << "\nEmail:\t\t" << email << "\nEnrolled:\n";
	
	size_t index = 0;
	while(index < enrolledCount)
	{
		std::cout << "\t\t#" << index+1 << ": " << enrolled[index] << "\n";
		index++;
	}
	
	std::cout << "Faculty:\t" << faculty << std::endl;
}

//preconditions: none
//postconditions: none
//description: returns a string with the student's info in O(1) time
std::string student::printString(void) const
{
	std::string returnString = "Student #:\t" + std::to_string(studentNumber) + "\nLastname:\t" + lastName + "\nFirstname:\t" + firstName + "\nAddress:\t" + address + "\nEmail:\t\t" + email + "\nEnrolled:\n";
	
	size_t index = 0;
	while(index < enrolledCount)
	{
		returnString += "\t\t#" + std::to_string(index+1) + ": " + enrolled[index] + "\n";
		index++;
	}
	
	returnString += "Faculty:\t" + faculty + "\n";
	
	return returnString;
}

