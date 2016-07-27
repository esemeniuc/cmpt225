//
// Created by eric on 21/07/16.
//

#include "musla.h"

//private:
//university* universityArray; //array of universities
//size_t universityCount; //default is 0
//size_t studentCount; //default is 0
//
//university** universityTable; //hashtable for universities
//student** lnameTable; //hashtable for last names
//student** idTable; //hashtable for student ids

//preconditions: none
//postconditions: none
//description: generates a hash based on inputInteger and returns it in O(1) time
size_t musla::hashInteger(uint32_t inputInteger, size_t modulus) const
{
	//h(k) = k(k+3) mod m from https://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
	uint64_t hashVal = inputInteger * (inputInteger + 3);
	hashVal %= modulus;
	
	return (size_t)hashVal;
}

//preconditions: none
//postconditions: none
//description: generates a hash based on inputInteger and returns it in O(1) time
size_t musla::hashString(std::string inputString, size_t modulus) const
{
	uint64_t hashVal = 0;
	
	size_t index = 0;
	while(inputString[index] != '\0')
	{
		hashVal += (index + 1) * inputString[index];
	}
	
	hashVal %= modulus; //shrink to new range
	
	return (size_t)hashVal;
}

size_t musla::hashString2(std::string inputString, size_t modulus) const
{
	uint64_t hashVal = 5381;
	int c;
	for(int i = 0; i < inputString.length(); ++i)
	{
		c = (int) inputString[i];
		hashVal = ((hashVal << 5) + hashVal) + c;
	}
	return (size_t)hashVal;
}

//preconditions: filename is not empty
//postconditions: returns 0 upon success, 1 on failure
//description: reads all the file contents from inputFileName
uint8_t musla::loadFromFile(std::string inputFilename)
{
	//read in the universityCount from file, then total studentCount
	//create appropriate universityArray size, hash table sizes
	
	
	
	//while(getline) from file pointer
	//if(detectUni)
	//{
	//while(loop until reach empty line)
	//{
	//insert students into university
}

//preconditions: inputID is a valid input
//postconditions: a student object with ID == inputID is returned. if not found, then classException is thrown
//description: looks up a student based on their ID and returns it in O(1) time
const student& musla::lookupStudentByID(uint32_t inputID) const throw(classException)
{

}

//preconditions: inputLName is not empty
//postconditions: a student object with inputLName is returned. if not found, then classException is thrown
//description: looks up a student based on their last name and returns it in O(1) time
const student& musla::lookupStudentByLName(std::string inputLName) const throw(classException)
{
	
}

//preconditions: inputID is > 0
//postconditions: a student object with ID inputID is returned. if not found, then classException is thrown
//description: looks up a student based on their ID and returns it in O(1) time
const university& musla::lookupUniversityByName(std::string inputName) const throw(classException)
{
	
}

//public
//default constructor which allocates universityCount * 2 sized array for
//hash lookup and studentCount * 2 sized array for students
musla::musla(uint32_t inputUniversityCount, uint32_t inputStudentCount):
universityCount(inputUniversityCount),
studentCount(inputStudentCount)
{
	universityArray = new university*[2 * universityCount];
	universityTable = new university*[2 * universityCount];
	idTable = new student*[2 * studentCount];
	lnameTable = new student*[2 * studentCount];
	//nothing else to do
}

//default destructor
musla::~musla()
{
	universityCount = 0;
	delete[] universityArray;
	delete[] universityTable;
	delete[] lnameTable;
	delete[] idTable;
}

//preconditions: inputUniversity is not null
//postconditions: returns 0 on success, 1 on failure
//description: inputs a inputUniversity object to musla
university* musla::addUniversity(university* inputUniversity)
{
	//hash university name
	//lookup index and check if the current index is NULL
	//if null, then then add uni there
	//if not, then traverse until we reach a null
	//return the memory address of the university
}

//preconditions: inputUniversity is not null
//postconditions: returns a matching university object if a match is found, or throws an exception
//description: returns a matching inputUniversity object
const university& musla::getUniversity(university* inputUniversity) const throw(classException)
{
	
}

//preconditions: inputStudentLName is not empty
//postconditions: returns a matching student object if a lname match is found, or throws an exception
//description: returns a matching student object
void musla::printAllStudentByLName(std::string& inputStudentLName) const throw(classException)
{
	
}

//preconditions: inputStudentID is not empty
//postconditions: returns a matching student object if a ID match is found, or throws an exception
//description: returns a matching student object
void musla::printAllStudentByID(std::string& inputStudentID) const throw(classException)
{
	
}

//preconditions: none
//postconditions: none
//description: displays all university info (not including student info) in O(1) time
void musla::displayUniversityInfo(void) const
{
	
}