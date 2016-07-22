//
// Created by eric on 21/07/16.
//

#include <cassert>
#include <iostream>
#include "testDriver.h"
#include "classException.h"

void testDriver::throwException()
{
	throw(classException("Error, wtf mate?"));
}

void testDriver::studentValidate()
{
//	uint32_t studentNumber;
//	std::string lastName;
//	std::string firstName;
//	std::string address;
//	std::string email;
//	std::string enrolled[studentEnrollmentMax];
//	std::string faculty;
	
	student student1(112233); //studentID
	student student2("lastname"); //lastname
	
	assert(student1.studentNumber == 112233);
	assert(student2.lastName == "lastname");
	
	std::string student3Enrolled[] = {"Math", "Phys", "something"};
	student student3(123, "smith", "john", "123 street", "js@js.com", student3Enrolled, 3, "CS Major");

	std::string student3String = "Student #:\t123\n"
			"Lastname:\tsmith\n"
			"Firstname:\tjohn\n"
			"Address:\t123 street\n"
			"Email:\t\tjs@js.com\n"
			"Enrolled:\n"
			"\t\t#1: Math\n"
			"\t\t#2: Phys\n"
			"\t\t#3: something\n"
			"Faculty:\tCS Major\n";
	
//	std::cout << student3String << std::endl;
//	std::cout << student3.printString() << std::endl;
	
	assert(student3.printString() == student3String);
	
}

void testDriver::universityValidate()
{
//private:
//std::string name;
//std::string address;
//std::string email;
//std::string phone;
//size_t studentCount; //for listInfo()
	
}
