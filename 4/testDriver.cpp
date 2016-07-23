//
// Created by eric on 21/07/16.
//

#include <cassert>
#include <iostream>
#include "testDriver.h"
#include "student.h"
#include "university.h"
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

void testDriver::studentThrowException()
{
	student noStudentID = student(0); //should throw bad studentID exception
	student emptyStudentLName = student(""); //should throw no LName exception
	student noIDorStudentLName = student(0, "", "john", "123 street", "js@js.com", NULL, 0, "CS Major"); //should throw no ID or LName exception
	
}

void testDriver::universityValidate()
{
//std::string name;
//std::string address;
//std::string email;
//std::string phone;
//btree<student> studentList;
//size_t studentCount; //for listInfo()

	
}

void testDriver::universityThrowException()
{
	university emptyName = university(""); //should throw empty name exception
	university emptyNameParameterized = university("", "123 street", "js@js.com", ""); //should throw empty name exception
	
}

