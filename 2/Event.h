//Filename: Event.h/Event.cpp
//Created by eric on 16/06/16.
//Description:
//stores the list of events of customers

//An Event class as described in Section 13.4. It must be designed and
//implemented as an ADT and have getters and setters for the attributes
//"type", "time" and "length". This class ***must not*** print anything
//on the computer monitor screen. Name this class Event (Event.h and Event.cpp).

//As customers arrive, they go to the back of the
//line. The current customer, who was at the front of the line, is being served, and it is this customer that
//you remove from the system next. It is thus natural to use a queue, bankQueue, to represent the line of
//customers in the bank. For this problem, the only information that you must store in the queue about
//each customer is the time of arrival and the length of the transaction.

#ifndef INC_2_EVENT_H
#define INC_2_EVENT_H


class Event
{
private:

	int type;

	int time;

	int length;

public:

	//Getters
	int getType();

	int getTime();

	int getLength();

	//Setters
	int setType();

	int setTime();

	int setLength();
};


#endif //INC_2_EVENT_H
