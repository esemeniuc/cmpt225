//
// Created by eric on 21/07/16.
//

#include <iostream>
#include "student.h"

//private:
//	std::uint32_t ID;
//	std::string lastName;
//	std::string firstName;
//	std::string address;
//	std::string email;
//	std::string enrolled[studentEnrollmentMax];
//	uint32_t enrolledCount;
//	std::string faculty;

//constructor with just ID
//preconditions: ID must not be blank
student::student(uint32_t inputID) throw(classException):
		ID(inputID)
{
	if(inputID <= 0) //can't have empty ID
	{
		throw(classException("Error: can't have empty ID"));
	}
}

//constructor with just lastName
//preconditions: lastName must not be blank
student::student(std::string inputLastName, std::string inputFirstName) throw(classException):
		lastName(inputLastName),
		firstName(inputFirstName)
{
	if(inputLastName.empty()) //can't have empty lastName
	{
		throw (classException("Error: can't have empty lastName"));
	}
}

//student constructor with parameters for all fields
//preconditions: ID and lastName must not be blank
student::student(uint32_t inputID,
				 std::string inputLastName,
				 std::string inputFirstName,
				 std::string inputAddress,
				 std::string inputEmail,
				 std::string inputEnrolled[],
				 uint32_t inputEnrolledCount,
				 std::string inputFaculty) throw(classException):
		ID(inputID),
		lastName(inputLastName),
		firstName(inputFirstName),
		address(inputAddress),
		email(inputEmail),
		enrolledCount(inputEnrolledCount),
		faculty(inputFaculty)
{
	if(inputID == 0 || inputLastName.empty()) //can't have empty ID or lastName
	{
		throw(classException("Error: can't have empty ID or lastName"));
	}
	
	std::copy(inputEnrolled, inputEnrolled + inputEnrolledCount, enrolled);
}

//default destructor
student::~student()
{
	//nothing to do here
}

//preconditions: none
//postconditions: returns 1 if student is empty, 0 if student has valid lastname and id
//description: checks if student object is empty
bool student::empty(void) const
{
	if(lastName.empty() && ID <= 0) //check if either lastName or ID is empty
	{
		return true;
	}

	return false;
}

//preconditions: inputStudent is not empty
//postconditions: 1 if lastName and ID match, 0 otherwise
//description: equality comparison
bool student::equals(const student& inputStudent) const
{
	if(ID == inputStudent.getID() || getFullName() == inputStudent.getFullName())
	{
		return true;
	}
	return false;
}

//preconditions: none
//postconditions: returns the ID member
//description: returns the Id member
uint32_t student::getID() const
{
	return ID;
}

//preconditions: none
//postconditions: returns the lastName member
//description: returns the lastName member
std::string student::getLName() const
{
	return lastName;
}

//preconditions: none
//postconditions: returns the lastName and firstName concatenated together
//description: returns the lastName and firstName concatenated together
std::string student::getFullName() const
{
	return (lastName + firstName);
}

////preconditions: inputStudent is not empty
////postconditions: 0 if inputStudent is greater than "this", 1 if less than "this"
////description: less than overloaded operator
//bool student::operator<(const student& inputStudent) const
//{
//	if(lastName.compare(inputStudent.lastName) =< 0) //check if rhs is less than inputStudent
//	{
//		return true;
//	}
//	
//	return false;
//}
//
////preconditions: inputStudent is not empty
////postconditions: 1 if lastName == inputStudent.lastName, 0 otherwise
////description: equality overloaded operator
//bool student::operator==(const student& inputStudent) const
//{
//	if(lastName == inputStudent.lastName) //check for match
//	{
//		return true;
//	}
//
//	return false;
//}

//preconditions: none
//postconditions: none
//description: prints out the student's info in O(1) time
void student::print(void) const
{
	std::cout << "Student #:\t" << ID << "\nLastname:\t" << lastName << "\nFirstname:\t" << firstName << "\nAddress:\t" << address << "\nEmail:\t\t" << email << "\nEnrolled:\n";
	
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
	std::string returnString = "Student #:\t" + std::to_string(ID) + "\nLastname:\t" + lastName + "\nFirstname:\t" + firstName + "\nAddress:\t" + address + "\nEmail:\t\t" + email + "\nEnrolled:\n";
	
	size_t index = 0;
	while(index < enrolledCount)
	{
		returnString += "\t\t#" + std::to_string(index+1) + ": " + enrolled[index] + "\n";
		index++;
	}
	
	returnString += "Faculty:\t" + faculty + "\n";
	
	return returnString;
}

