//
// Created by eric on 21/07/16.
//

#include <cassert>
#include <iostream>
#include "testDriver.h"
#include "word.h"
#include "btree.h"

//	for(int i = 0; i < 10; i++)
//	{
//		userInputQueue.push(std::to_string(i));
//
//	}
//	userInputQueue.print();
//
//	userInputQueue.randomize();
//	userInputQueue.print();
//	for(int i = 0; i < 5; i++)
//	{
//		cout << userInputQueue.pop() << endl;
//	}

//void testDriver::throwException()
//{
//	throw(classException("Error, wtf mate?"));
//}
//
//void testDriver::studentValidate()
//{
////	uint32_t studentNumber;
////	std::string lastName;
////	std::string firstName;
////	std::string address;
////	std::string email;
////	std::string enrolled[studentEnrollmentMax];
////	std::string faculty;
//
//	student student1(112233); //studentID
//	student student2("lastname", "firstname"); //lastname
//
//	assert(student1.ID == 112233);
//	assert(student2.lastName == "lastname");
//
//	std::string student3Enrolled[] = {"Math", "Phys", "something"};
//	student student3(123, "smith", "john", "123 street", "js@js.com", student3Enrolled, 3, "CS Major");
//
//	std::string student3String = "Student #:\t123\n"
//			"Lastname:\tsmith\n"
//			"Firstname:\tjohn\n"
//			"Address:\t123 street\n"
//			"Email:\t\tjs@js.com\n"
//			"Enrolled:\n"
//			"\t\t#1: Math\n"
//			"\t\t#2: Phys\n"
//			"\t\t#3: something\n"
//			"Faculty:\tCS Major\n";
//
////	std::cout << student3String << std::endl;
////	std::cout << student3.printString() << std::endl;
//
//	assert(student3.printString() == student3String);
//
//}
//
//void testDriver::studentThrowException()
//{
//	student noStudentID = student(0); //should throw bad studentID exception
//	student emptyStudentLName = student("", ""); //should throw no LName exception
//	student noIDorStudentLName = student(0, "", "john", "123 street", "js@js.com", NULL, 0, "CS Major"); //should throw no ID or LName exception
//
//}
//
//void testDriver::universityValidate()
//{
////std::string name;
////std::string address;
////std::string email;
////std::string phone;
////btree<student> studentList;
////size_t studentCount; //for listInfo()
//
//
//}
//
//void testDriver::universityThrowException()
//{
//	university emptyName = university(""); //should throw empty name exception
//	university emptyNameParameterized = university("", "123 street", "js@js.com", ""); //should throw empty name exception
//
//}
//
//void testDriver::btreeInsertNormal()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "john", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(222, "smith", "joe", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << std::endl;
////	studentBtree.print(0);
//	assert(status1 == 0 && status2 == 0);
//}
//
//void testDriver::btreeInsertDuplicateID()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "john", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(111, "smith", "joe", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << std::endl;
////	studentBtree.print(0);
//	assert(status1 == 0 && status2 == 1);
//}
//
//void testDriver::btreeInsertDuplicateName()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "john", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(222, "smith", "john", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << std::endl;
////	studentBtree.print(1);
//	assert(status1 == 0 && status2 == 1);
//}
//
//void testDriver::btree4Valid()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(222, "smith", "j3", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent3 = student(444, "smith", "j2", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent4 = student(123, "smith", "j0", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
//	uint8_t status3 = studentBtree.insert(testStudent3);
//	uint8_t status4 = studentBtree.insert(testStudent4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	studentBtree.print(0);
//	assert(status1 == 0 && status2 == 0 && status3 == 0 && status4 == 0);
//}
//
//void testDriver::btree4Invalid()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(222, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent3 = student(111, "smith", "j2", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent4 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
//	uint8_t status3 = studentBtree.insert(testStudent3);
//	uint8_t status4 = studentBtree.insert(testStudent4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	studentBtree.print(0);
//	assert(status1 == 0 && status2 == 1 && status3 == 1 && status4 == 1);
//}
//
//void testDriver::btree2of4ValidFirst()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(222, "smith", "j2", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent3 = student(222, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent4 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
//	uint8_t status3 = studentBtree.insert(testStudent3);
//	uint8_t status4 = studentBtree.insert(testStudent4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	studentBtree.print(0);
//	assert(status1 == 0 && status2 == 0 && status3 == 1 && status4 == 1);
//}
//
//void testDriver::btree2of4ValidMiddle()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(222, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent3 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent4 = student(222, "smith", "j2", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
//	uint8_t status3 = studentBtree.insert(testStudent3);
//	uint8_t status4 = studentBtree.insert(testStudent4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	studentBtree.print(0);
//	assert(status1 == 0 && status2 == 1 && status3 == 1 && status4 == 0);
//}
//
//void testDriver::btreeSearchExistsID()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(222, "smith", "j3", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent3 = student(444, "smith", "j2", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent4 = student(123, "smith", "j0", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
//	uint8_t status3 = studentBtree.insert(testStudent3);
//	uint8_t status4 = studentBtree.insert(testStudent4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	studentBtree.print(0);
//
//	student searchStudent = student(123);
//	student searchResult = studentBtree.searchID(&searchStudent);
////	searchResult.print();
//	assert(searchStudent.getID() == searchResult.getID());
//}
//
//void testDriver::btreeSearchExistsLName()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(222, "smith", "j3", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent3 = student(444, "smith", "j2", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent4 = student(123, "smith", "j0", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
//	uint8_t status3 = studentBtree.insert(testStudent3);
//	uint8_t status4 = studentBtree.insert(testStudent4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	studentBtree.print(0);
//
//	student searchStudent = student("smith", "j0");
//	student searchResult = studentBtree.searchLName(&searchStudent);
////	searchResult.print();
//	assert(searchStudent.getFullName() == searchResult.getFullName());
//}
//
//void testDriver::btreeSearchNotExistsID()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(222, "smith", "j3", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent3 = student(444, "smith", "j2", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent4 = student(123, "smith", "j0", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
//	uint8_t status3 = studentBtree.insert(testStudent3);
//	uint8_t status4 = studentBtree.insert(testStudent4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	studentBtree.print(0);
//
//	student searchStudent = student(1341);
//	student searchResult = studentBtree.searchID(&searchStudent);
//	searchResult.print();
//	assert(searchStudent.getID() == searchResult.getID());
//}
//
//void testDriver::btreeSearchNotExistsLName()
//{
//	btree<student> studentBtree;
////	btree<student> studentBtree = btree<student>();
//	student testStudent1 = student(111, "smith", "j1", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent2 = student(222, "smith", "j3", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent3 = student(444, "smith", "j2", "123 street", "js@js.com", NULL, 0, "CS Major");
//	student testStudent4 = student(123, "smith", "j0", "123 street", "js@js.com", NULL, 0, "CS Major");
//
//	uint8_t status1 = studentBtree.insert(testStudent1);
//	uint8_t status2 = studentBtree.insert(testStudent2);
//	uint8_t status3 = studentBtree.insert(testStudent3);
//	uint8_t status4 = studentBtree.insert(testStudent4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	studentBtree.print(0);
//
//	student searchStudent = student("smith", "j4");
//	student searchResult = studentBtree.searchLName(&searchStudent);
//	searchResult.print();
//	assert(searchStudent.getFullName() == searchResult.getFullName());
//}
//
//
//void testDriver::testAllNonException()
//{
//	studentValidate();
//	universityValidate();
//	btreeInsertNormal();
//	btreeInsertDuplicateID();
//	btreeInsertDuplicateName();
//	btree4Valid();
//	btree4Invalid();
//	btree2of4ValidFirst();
//	btree2of4ValidMiddle();
//	btreeSearchExistsID();
//	btreeSearchExistsLName();
////	btreeSearchNotExistsID();
////	btreeSearchNotExistsLName();
//}
