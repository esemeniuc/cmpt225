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

//basic test function
//takes input until an EOF is reached, and returns an array (of size queueCapacity) of integers
//int* takeInputTest(void)
//{
//	int currentInputCount = 0; //counter for inputEvents array
//	int* inputEvents = new int[queueDefaultMax]; //allocate an array of size queueCapacity to store the text input
//	while(cin >> inputEvents[currentInputCount]) //eof check and load data into array
//	{
//		cout << "Input " << currentInputCount << ": Value: " << inputEvents[currentInputCount] << endl; //debug
//		currentInputCount++; //increment our counter
//	}
//
//	return inputEvents;
//}

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

void loadIntoQueue(Queue &inputQueue) //loads data into inputQueue
{
	// Create and add arrival events to event list
	int currentInputCount = 0; //counter for inputEvents array

	unsigned int tempTime;
	unsigned int tempLength;

	while(cin >> tempTime >> tempLength) //load data into both variables until hits EOF
	{
		//cout << "Input #" << currentInputCount << ": Time = " << tempTime << ", Length = " << tempLength << endl; //debug
		Event tempEvent(tempTime, tempLength);
		inputQueue.enqueue(tempEvent); //insert our new evnt into the queue
		currentInputCount++; //increment our counter
	}

	//inputQueue.print(); //debug
}

int main(void)
{
	bool tellerAvailable = true;

	Queue bankQueue; //represents the line of customers in the bank/bank line
	PQueue eventListPQueue; //priority queue eventListPQueue for the event list

	loadIntoQueue(bankQueue);


	//add all the the arrival events from bankQueue
	//now add the departure events


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