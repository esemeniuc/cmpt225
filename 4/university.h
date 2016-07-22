//
// Created by eric on 21/07/16.
//

#ifndef INC_4_UNIVERSITY_H
#define INC_4_UNIVERSITY_H

#include <string>
#include "student.h"

class university
{
private:
	std::string name;
	std::string address;
	std::string email;
	std::string phone;
	size_t studentCount; //for listInfo()
	
public:
	//preconditions: inputName is not empty
	//postconditions: throws classException if inputName is empty
	//description: constructor with only university name
	university(std::string inputName) throw(classException);
	
	//preconditions: inputName is not empty
	//postconditions: throws classException if inputName is empty
	//description: constructor with all fields
	university(std::string inputName, std::string inputAddress, std::string inputEmail, std::string inputPhone) throw (classException);
	
	//default destructor
	~university();
	
	//preconditions: none
	//postconditions: none
	//description: inserts a student into the university in O(log(n)) time
	bool setStudent(student& inputStudent) const;
	
	//preconditions: none
	//postconditions: none
	//description: lists all of the students attending the university sorted by ID in O(n) time
	void listStudentsByID(void) const;
	
	//preconditions: none
	//postconditions: none
	//description: lists all of the students attending the university sorted by last name in O(n) time
	void listStudentsByLName(void) const;
	
	//preconditions: none
	//postconditions: none
	//description: displays all university info in O(1) time
	void listInfo(void) const;
};


#endif //INC_4_UNIVERSITY_H


