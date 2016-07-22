//
// Created by eric on 21/07/16.
//

#ifndef INC_4_UNIVERSITY_H
#define INC_4_UNIVERSITY_H

#include <string>

class university
{
private:
	std::string name;
	std::string address;
	std::string email;
	std::string phone;
	size_t studentCount; //for display
	
public:
	
	//preconditions: none
	//postconditions: none
	//description: lists all of the students attending the university sorted by ID in O(n) time
	void listStudentsID(void) const;
	
	//preconditions: none
	//postconditions: none
	//description: lists all of the students attending the university sorted by last name in O(n) time
	void listStudentsLName(void) const;
	
	//preconditions: none
	//postconditions: none
	//description: displays all university info in O(1) time
	void listInfo(void) const;
};


#endif //INC_4_UNIVERSITY_H


