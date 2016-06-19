//Filename: Event.h/Event.cpp
//Created by eric on 16/06/16.
//Description:
//stores the details of a bank customer event

//An Event class as described in Section 13.4. It must be designed and
//implemented as an ADT and have getters and setters for the attributes
//"type", "time" and "length". This class ***must not*** print anything
//on the computer monitor screen. Name this class Event (Event.h and Event.cpp).


#ifndef INC_2_EVENT_H
#define INC_2_EVENT_H

//Class Invariant: Type must be 'A' or 'D', time and length attributes cannot be negative
class Event
{
private:

	char type; //Event type, either A or D
	unsigned int time; //Time of customer arrival
	unsigned int length; //Length of time it takes to process the event

public:

	//Description: default constructor
	//Preconditions: None
	//Postconditions: constructs an empty Event with type = 'A' (Arrival), time = 0, and length = 0
	Event(void);

	//Description: Constructor with time and length inputs
	//Preconditions: inputTime and inputLength are non negative
	//Postconditions: constructs an empty Event with type = 'A' (Arrival), time = inputTime, and length = inputLength
	Event(unsigned int inputTime, unsigned int inputLength);

	//Description: Constructor with type, time, and length inputs
	//Preconditions: inputType is 'A' or 'D', inputTime and inputLength are non negative
	//Postconditions: constructs an empty Event with type = inputType, time = inputTime, and length = inputLength
	Event(char inputType, unsigned int inputTime, unsigned int inputLength);

	//Description: default destructor
	//Preconditions: the object exists
	//Postconditions: the object no longer exists
	~Event(); //default destructor

	//Getters

	//Description: returns the type of the event
	//Preconditions: none
	//Postconditions: returns NULL if the type is not valid, 'A' if the event is an arrival, 'D' if the event is a departure
	char getType() const;

	//Description: returns the arrival time of the event
	//Preconditions: time is non negative
	//Postconditions: returns the arrival time of the event in minutes
	unsigned int getTime() const;

	//Description: returns the processing time of the event
	//Preconditions: length is non negative
	//Postconditions: returns the processing time of the event in minutes
	unsigned int getLength() const;

	//Setters

	//Description: sets the type of the event
	//Preconditions: Type is either 'A' or 'D'
	//Postconditions: returns 1 if the type is not valid, 0 if it was successfully set
	int setType(char inputType);

	//Description: sets the arrival time of the event
	//Preconditions: inputTime is a non negative integer
	//Postconditions: returns 1 if the time is not valid, 0 if it was successfully set
	int setTime(unsigned int inputTime);

	//Description: sets the processing length of the event
	//Preconditions: inputLength is a non negative integer
	//Postconditions: returns 1 if the length is not valid, 0 if it was successfully set
	int setLength(unsigned int inputLength);

	//Description: prints out the contents of an event
	//Preconditions: none
	//Postconditions: prints out the contents of an event
	void print(void) const;
};


#endif //INC_2_EVENT_H
