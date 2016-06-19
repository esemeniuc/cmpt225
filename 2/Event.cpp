//Filename: Event.h/Event.cpp
//Created by eric on 16/06/16.
//Description:
//stores the details of a bank customer event

//An Event class as described in Section 13.4. It must be designed and
//implemented as an ADT and have getters and setters for the attributes
//"type", "time" and "length". This class ***must not*** print anything
//on the computer monitor screen. Name this class Event (Event.h and Event.cpp).

#include "Event.h"
#include <iostream>

//Class Invariant: Type must be 'A' or 'D', time and length attributes cannot be negative

/*private attributes/methods

	char type; //Event type, either A or D
	unsigned int time; //Time of customer arrival
	unsigned int length; //Length of time it takes to process the event
*/

//public attributes/methods

//Description: default constructor
//Preconditions: None
//Postconditions: constructs an empty Event with type = 'A' (Arrival), time = 0, and length = 0
Event::Event(void):
type('A'),
time(0),
length(0)
{
	//nothing else to do here
	//std::cout << "Calling constructor on Type: " << type << ", Time: " << time << ", Length: " << length << std::endl; //debug
}

//Description: Constructor with time and length inputs
//Preconditions: inputTime and inputLength are non negative
//Postconditions: constructs an empty Event with type = 'A' (Arrival), time = inputTime, and length = inputLength
Event::Event(unsigned int inputTime, unsigned int inputLength):
type('A'),
time(inputTime),
length(inputLength)
{
	//nothing else to do here
	std::cout << "Calling constructor on Type: " << type << ", Time: " << time << ", Length: " << length << std::endl; //debug
}

//Description: Constructor with type, time, and length inputs
//Preconditions: inputType is 'A' or 'D', inputTime and inputLength are non negative
//Postconditions: constructs an empty Event with type = inputType, time = inputTime, and length = inputLength
Event::Event(char inputType, unsigned int inputTime, unsigned int inputLength):
type(inputType),
time(inputTime),
length(inputLength)
{
	//nothing else to do here
	std::cout << "Calling constructor on Type: " << type << ", Time: " << time << ", Length: " << length << std::endl; //debug
}

//Description: default destructor
//Preconditions: the object exists
//Postconditions: the object no longer exists
Event::~Event()
{
	//nothing else to do here
	//std::cout << "Calling destructor on Type: " << type << ", Time: " << time << ", Length: " << length << std::endl; //debug
}

//Getters

//Description: returns the type of the event
//Preconditions: none
//Postconditions: returns NULL if the type is not valid, 'A' if the event is an arrival, 'D' if the event is a departure
char Event::getType() const
{
	return type;
}

//Description: returns the arrival time of the event
//Preconditions: time is non negative
//Postconditions: returns the arrival time of the event in minutes
unsigned int Event::getTime() const
{
	return time;
}

//Description: returns the processing time of the event
//Preconditions: length is non negative
//Postconditions: returns the processing time of the event in minutes
unsigned int Event::getLength() const
{
	return length;
}

//Setters

//Description: sets the type of the event
//Preconditions: Type is either 'A' or 'D'
//Postconditions: returns 1 if the type is not valid, 0 if it was successfully set
int Event::setType(char inputType)
{
	if(inputType != 'A' && inputType != 'D') //check if input is bad
	{
		return 1; //invalid input
	}

	type = inputType; //then set
	return 0; //all is good
}

//Description: sets the arrival time of the event
//Preconditions: inputTime is a non negative integer
//Postconditions: returns 1 if the time is not valid, 0 if it was successfully set
int Event::setTime(unsigned int inputTime)
{
	if(inputTime < 0) //cant have negative inputTime
	{
		return 1; //invalid
	}
	time = inputTime;
	return 0; //all is good
}

//Description: sets the processing length of the event
//Preconditions: inputLength is a non negative integer
//Postconditions: returns 1 if the length is not valid, 0 if it was successfully set
int Event::setLength(unsigned int inputLength)
{
	if(inputLength < 0) //cant have negative inputLength
	{
		return 1; //invalid
	}
	length = inputLength;
	return 0; //all is good
}

//Description: prints out the contents of an event
//Preconditions: none
//Postconditions: prints out the contents of an event
void Event::print(void)
{
	std::cout << "Event of Type: " << type << ", Time: " << time << ", Length: " << length << std::endl;
}
