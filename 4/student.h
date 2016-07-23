//
// Created by eric on 21/07/16.
//

#ifndef INC_4_STUDENT_H
#define INC_4_STUDENT_H

#include "string"
#include "classException.h"

#define private public //debug: ugly hack to do assert testing

const uint8_t studentEnrollmentMax = 100;
class student
{
private:
	uint32_t studentNumber;
	std::string lastName;
	std::string firstName;
	std::string address;
	std::string email;
	std::string enrolled[studentEnrollmentMax];
	uint32_t enrolledCount;
	std::string faculty;
	
public:
	
	//constructor with just studentNumber
	//preconditions: studentNumber must not be blank
	student(uint32_t inputStudentNumber) throw(classException);
	
	//constructor with just lastName
	//preconditions: lastName must not be blank
	student(std::string inputLastName) throw(classException);
	
	//student constructor with parameters for all fields
	//preconditions: studentNumber and lastName must not be blank
	student(uint32_t inputStudentNumber,
			 std::string inputLastName,
			 std::string inputFirstName,
			 std::string inputAddress,
			 std::string inputEmail,
			 std::string inputEnrolled[],
			 uint32_t enrolledCount,
			 std::string inputFaculty) throw(classException);
	
	//default destructor
	~student();
	
	//preconditions: none
	//postconditions: returns 1 if student is empty, 0 if student has valid lastname and id
	//description: checks if student object is empty
	bool empty(void) const;
	
	//preconditions: inputStudent is not empty
	//postconditions: 0 if inputStudent is greater than "this", 1 if less than "this"
	//description: less than overloaded operator
	bool operator<(const student& inputStudent) const;
	
	//preconditions: inputStudent is not empty
	//postconditions: 1 if lastName == inputStudent.lastName, 0 otherwise
	//description: equality overloaded operator
	bool operator==(const student& inputStudent) const;
	
	//preconditions: none
	//postconditions: none
	//description: prints out the student's info in O(1) time
	void print(void) const;
	
	//preconditions: none
	//postconditions: none
	//description: returns a string with the student's info in O(1) time
	std::string printString(void) const;
};



#endif //INC_4_STUDENT_H
