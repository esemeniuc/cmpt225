//Filename: BankSimApp.cpp
//Created by eric on 16/06/16.
//Description:
//Processes the list of events ( customers entering the bank)
//Notes:
//BankSimApp is not to open and read input files, but is to read input from the command line
//eg ./bsApp < simulation.in

#include <iostream>
#include "Event.h"
#include "Queue.h"
#include "PQueue.h"

using namespace std;

// Performs the simulation.
/*void simulate(void) {
	//Create an empty queue bankQueue to represent the bank line
	//Create an empty priority queue eventListPQueue for the event list
	bool tellerAvailable = true;
	// Create and add arrival events to event list
	while (data file is not empty )
	{
		//Get next arrival time a and transaction time t from file
		newArrivalEvent = a new arrival event containinga andt;
		eventListPQueue.add(newArrivalEvent);
	}
	// Event loop
	while(eventListPQueue is not empty )
	{
		newEvent = eventListPQueue.peek();
		// Get current time
		currentTime = time of newEvent;
		if (newEvent is an arrival event )
		{
			processArrival(newEvent, eventListPQueue, bankQueue);
		}
		else
		{
			processDeparture(newEvent, eventListPQueue, bankQueue)
		}
	}
}*/

// Processes an arrival event.
void processArrival(Event &arrivalEvent, PQueue &eventListPQueue, Queue &bankQueue, bool &tellerAvailable, unsigned int currentTime)
{
	//Remove this event from the event list
	eventListPQueue.dequeue();
	Event customer = arrivalEvent; //customer referenced in arrivalEvent ?????????????????????
	if (bankQueue.isEmpty() && tellerAvailable)
	{
		unsigned int departureTime = currentTime + customer.getLength();//currentTime + transaction time in arrivalEvent
		Event newDepartureEvent('D', departureTime, 0); //a new departure event with departureTime
		eventListPQueue.enqueue(newDepartureEvent);
		tellerAvailable = false;
	}
	else
	{
		bankQueue.enqueue(customer);
	}
}

// Processes a departure event.
void processDeparture(Event departureEvent, PQueue eventListPQueue, Queue &bankQueue, bool &tellerAvailable, unsigned int currentTime)
{
	// Remove this event from the event list
	eventListPQueue.dequeue();

	if(!bankQueue.isEmpty())
	{
		// Customer at front of line begins transaction
		Event customer = bankQueue.peek();
		bankQueue.dequeue();
		unsigned int departureTime = currentTime + customer.getLength(); //currentTime + transaction time in customer
		Event newDepartureEvent('D', departureTime, 0); //a new departure event with departureTime
		eventListPQueue.enqueue(newDepartureEvent);
	}
	else
	{
		tellerAvailable = true;
	}
}

void loadIntoPriorityQueue(PQueue &inputPQueue) //loads data into inputQueue
{
	// Create and add arrival events to event list
	unsigned int tempTime; //temporary placeholders for cin
	unsigned int tempLength;

	while(cin >> tempTime >> tempLength) //load data into both variables until hits EOF
	{
		//cout << "Input #" << currentInputCount << ": Time = " << tempTime << ", Length = " << tempLength << endl; //debug
		Event tempEvent(tempTime, tempLength);
		//cout << "created event successfully" << endl; //debug
		inputPQueue.enqueue(tempEvent); //insert our new event into the queue
	}

	//inputPQueue.print(); //debug
}

void resultPrinter(PQueue &inputPQueue)
{
	unsigned int arrivalCount = 0; //track how many customers came in
	unsigned int avgTimeWait; //TODO: add time wait calculation
	cout << "Simulation Begins" << endl;

	while(!inputPQueue.isEmpty()) //while there are still elements
	{
		Event tempEvent = inputPQueue.peek();
		if (tempEvent.getType() == 'A') {
			cout << "Processing an arrival event at time: " << tempEvent.getTime() << endl;
			arrivalCount++;
		}
		else
		{
			cout << "Processing a departure event at time: " << tempEvent.getTime() << endl;
		}
	}

	cout << "Simulation Ends" << endl;
	cout << "Final Statistics:" << endl;
	cout << "Total number of people processed: " << arrivalCount << endl;
	cout << "Average amount of time spent waiting: " << avgTimeWait << endl;
}


int main(void)
{
	Queue bankQueue; //represents the line of customers in the bank/bank line
	PQueue eventListPQueue; //priority queue eventListPQueue for the event list

	bool tellerAvailable = true;
	loadIntoPriorityQueue(eventListPQueue); //load data into Priority Queue from file

	//??add all the the arrival events from bankQueue
	while(!eventListPQueue.isEmpty()) //run while eventListPQueue is not empty
	{
		Event newEvent = eventListPQueue.peek();
		// Get current time
		unsigned int currentTime = newEvent.getTime(); // get time of newEvent
		if (newEvent.getType() == 'A') //check if newEvent is an arrival event
		{
			processArrival(newEvent, eventListPQueue, bankQueue, tellerAvailable, currentTime);
		}
		else
		{
			processDeparture(newEvent, eventListPQueue, bankQueue, tellerAvailable, currentTime);
		}
	}


// Psuedocode
//	Initialize the line to “no customers”
//	while( events remain to be processed )
//	{
//		currentTime = time of next event
//		if( event is an arrival event )
//	else
//	{
//		//Process the departure event
//	}
//
//	When an arrival event and a departure event occur at the same time,
//	arbitrarily process the arrival event first

	return 0;
}