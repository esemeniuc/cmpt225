
//Filename: Event.h/Event.cpp
//Created by eric on 16/06/16. Edited by Eugene Filatov, 
//Description:
//stores the details of a bank customer event

//An Event class as described in Section 13.4. It must be designed and
//implemented as an ADT and have getters and setters for the attributes
//"type", "time" and "length". This class ***must not*** print anything
//on the computer monitor screen. Name this class Event (Event.h and Event.cpp).

#include "Event.h"

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
Event::Event(void)
{
	type = 'A';
	time = 0;
	length = 0;


}

//Description: Constructor with time and length inputs
//Preconditions: inputTime and inputLength are non negative
//Postconditions: constructs an empty Event with type = 'A' (Arrival), time = inputTime, and length = inputLength
Event::Event(unsigned int inputTime, unsigned int inputLength)
{

	type = 'A';
	time = 0;
	length = 0;

}

//Description: Constructor with type, time, and length inputs
//Preconditions: inputType is 'A' or 'D', inputTime and inputLength are non negative
//Postconditions: constructs an empty Event with type = inputType, time = inputTime, and length = inputLength
Event::Event(char inputType, unsigned int inputTime, unsigned int inputLength)
{
	type = 'A';
	time = inputType;
	length = inputLength;

}

//Description: default destructor
//Preconditions: the object exists
//Postconditions: the object no longer exists
Event::~Event()
{
	delete[] this; 
} //default destructor

//Getters

//Description: returns the type of the event
//Preconditions: none
//Postconditions: returns -1 if the type is not valid, 1 if the event is an arrival, 2 if the event is a departure
int Event::getType()
{
	if (type == 'A') {
		return 1;
	}
	if (type == 'D') {
		return 2;
	}

	return -1;
	
}

int Event::getType() const
{
	if (type == 'A') {
		return 1;
	}
	if (type == 'D') {
		return 2;
	}

	return -1;

}
//Description: returns the arrival time of the event
//Preconditions: time is non negative
//Postconditions: returns the arrival time of the event in minutes
int Event::getTime()
{
	return time;

}

int Event::getTime() const 
{
	return time;

}

//Description: returns the processing time of the event
//Preconditions: length is non negative
//Postconditions: returns the processing time of the event in minutes
int Event::getLength()
{
	return length; 
}

int Event::getLength() const
{
	return length;
}

//Setters

//Description: sets the type of the event
//Preconditions: Type is either 'A' or 'D'
//Postconditions: returns 1 if the type is not valid, 0 if it was successfully set
int Event::setType(char inputType)
{
	if (!(inputType == 'A' || inputType == 'D')) {
		return 1;
	}

	type = inputType;
	return 0;

}

//Description: sets the arrival time of the event
//Preconditions: inputTime is a non negative integer
//Postconditions: returns 1 if the time is not valid, 0 if it was successfully set
int Event::setTime(unsigned int inputTime)
{
	if (inputTime < 0) {
		return 1;
	}

	time = inputTime;
	return 0;
}

//Description: sets the processing length of the event
//Preconditions: inputLength is a non negative integer
//Postconditions: returns 1 if the length is not valid, 0 if it was successfully set
int Event::setLength(unsigned int inputLength)
{
	if (inputLength < 0) {
		return 1;
	}

	length = inputLength;
	return 0;
}


