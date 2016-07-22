//
// Created by eric on 21/07/16.
//

#ifndef INC_4_STUDENT_H
#define INC_4_STUDENT_H

#include "string"

const uint8_t studentEnrollmentMax = 100;
class student
{
private:
	std::string studentNumber;
	std::string lastName;
	std::string firstName;
	std::string address;
	std::string email;
	std::string enrolled[studentEnrollmentMax];
	std::string faculty;
};



#endif //INC_4_STUDENT_H
