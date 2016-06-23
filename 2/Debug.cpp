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


//prints out the results of the simulation --broken
//void resultPrinterPQueue(PQueue &inputPQueue)
//{
//	unsigned int arrivalCount = 0; //track how many customers came in
//	unsigned int avgTimeWait; //TODO: add time wait calculation
//	cout << "Simulation Begins" << endl;
//
//	while(!inputPQueue.isEmpty()) //while there are still elements
//	{
//		Event tempEvent = inputPQueue.peek();
//		if (tempEvent.getType() == 'A') {
//			cout << "Processing an arrival event at time:\t" << tempEvent.getTime() << endl;
//			arrivalCount++;
//		}
//		else
//		{
//			cout << "Processing a departure event at time:\t" << tempEvent.getTime() << endl;
//		}
//		inputPQueue.dequeue(); //finished with the event
//	}
//
//	cout << "Simulation Ends\n\n";
//	cout << "Final Statistics:" << endl;
//	cout << "\tTotal number of people processed: " << arrivalCount << endl;
//	cout << "\tAverage amount of time spent waiting: " << avgTimeWait << endl;
//}

//prints out the results of the simulation --broken
//void resultPrinterQueue(Queue &inputQueue)
//{
//	unsigned int arrivalCount = 0; //track how many customers came in
//	unsigned int avgTimeWait; //TODO: add time wait calculation
//	cout << "Simulation Begins" << endl;
//
//	while(!inputQueue.isEmpty()) //while there are still elements
//	{
//		Event tempEvent = inputQueue.peek();
//		if (tempEvent.getType() == 'A') {
//			cout << "Processing an arrival event at time:\t" << tempEvent.getTime() << endl;
//			arrivalCount++;
//		}
//		else
//		{
//			cout << "Processing a departure event at time:\t" << tempEvent.getTime() << endl;
//		}
//		inputQueue.dequeue(); //finished with the event
//	}
//
//	cout << "Simulation Ends\n\n";
//	cout << "Final Statistics:" << endl;
//	cout << "\tTotal number of people processed: " << arrivalCount << endl;
//	cout << "\tAverage amount of time spent waiting: " << avgTimeWait << endl;
//}

//// Processes an arrival event.
//void processArrival(Event &arrivalEvent, PQueue &eventListPQueue, Queue &bankQueue, bool &tellerAvailable, unsigned int currentTime)
//{
//	//Remove this event from the event list
//	eventListPQueue.dequeue();
//	Event customer = arrivalEvent; //customer referenced in arrivalEvent ?????????????????????
//	if (bankQueue.isEmpty() && tellerAvailable)
//	{
//		unsigned int departureTime = currentTime + customer.getLength();//currentTime + transaction time in arrivalEvent
//		Event newDepartureEvent('D', departureTime, 0); //a new departure event with departureTime
//		eventListPQueue.enqueue(newDepartureEvent);
//		tellerAvailable = false;
//	}
//	else
//	{
//		bankQueue.enqueue(customer);
//	}
//}
//
//// Processes a departure event.
//void processDeparture(Event departureEvent, PQueue eventListPQueue, Queue &bankQueue, bool &tellerAvailable, unsigned int currentTime)
//{
//	// Remove this event from the event list
//	eventListPQueue.dequeue();
//
//	if(!bankQueue.isEmpty())
//	{
//		// Customer at front of line begins transaction
//		Event customer = bankQueue.peek();
//		bankQueue.dequeue();
//		unsigned int departureTime = currentTime + customer.getLength(); //currentTime + transaction time in customer
//		Event newDepartureEvent('D', departureTime, 0); //a new departure event with departureTime
//		eventListPQueue.enqueue(newDepartureEvent);
//	}
//	else
//	{
//		tellerAvailable = true;
//	}
//}

void loadIntoBankQueue(Queue &inputQueue) //loads data into inputQueue
{
	// Create and add arrival events to event list
	//int currentInputCount = 0; //counter for inputEvents array

	unsigned int tempTime; //temporary placeholders for cin
	unsigned int tempLength;

	while(cin >> tempTime >> tempLength) //load data into both variables until hits EOF
	{
		//cout << "Input #" << currentInputCount << ": Time = " << tempTime << ", Length = " << tempLength << endl; //debug
		Event tempEvent(tempTime, tempLength);
		inputQueue.enqueue(tempEvent); //insert our new event into the queue
		//currentInputCount++; //increment our counter
	}

	inputQueue.print(); //debug
}


void loadIntoPriorityQueue(PQueue &inputPQueue) //loads data into inputQueue
{
	// Create and add arrival events to event list
	int currentInputCount = 0; //counter for inputEvents array

	unsigned int tempTime; //temporary placeholders for cin
	unsigned int tempLength;

	while(cin >> tempTime >> tempLength) //load data into both variables until hits EOF
	{
		//cout << "Input #" << currentInputCount << ": Time = " << tempTime << ", Length = " << tempLength << endl; //debug
		Event tempEvent(tempTime, tempLength);
		//cout << "created event successfully" << endl; //debug
		inputPQueue.enqueue(tempEvent); //insert our new event into the queue
		currentInputCount++; //increment our counter
	}

	inputPQueue.print(); //debug
}

void loadIntoPriorityQueueAdvanced(PQueue &inputPQueue) //loads data into inputQueue
{
	// Create and add arrival events to event list
	int currentInputCount = 0; //counter for inputEvents array

	char tempType;
	unsigned int tempTime; //temporary placeholders for cin
	unsigned int tempLength;

	while(cin >> tempType >> tempTime >> tempLength) //load data into both variables until hits EOF
	{
		//cout << "Input #" << currentInputCount << ": Time = " << tempTime << ", Length = " << tempLength << endl; //debug
		Event tempEvent(tempType, tempTime, tempLength);
		//cout << "created event successfully" << endl; //debug
		inputPQueue.enqueue(tempEvent); //insert our new event into the queue
		currentInputCount++; //increment our counter
	}

	inputPQueue.print(); //debug
}

void bankQueueStressTest(Queue &inputQueue) //loads data into inputQueue
{
	for(unsigned int i= 1; i <= 5; i++)
//	for(int i = 1; i <= 105; i++)
	{
		Event tempEvent(i*2, i*10);
		bool status = inputQueue.enqueue(tempEvent); //insert our new event into the queue
		cout << "Enqueue Element #: " << i << ", Status: " << status << endl;
	}

//	for(int i = 1; i <= 3; i++)
//	{
//		bool status = inputQueue.dequeue(); //insert our new event into the queue
//		cout << "Dequeue Element #: " << i << ", Status: " << status << endl;
////		inputQueue.print(); //debug
//	}
//	Event testExceptionThrow = inputQueue.peek();
	inputQueue.print(); //debug
}

void pQueueStressTest(PQueue &inputPQueue) //loads data into inputQueue
{
//	for(unsigned int i= 1; i <= 5; i++)
	for(unsigned int i= 100; i >= 95; i--)
	{
		Event tempEvent(i, i);
		bool status = inputPQueue.enqueue(tempEvent); //insert our new event into the queue
		cout << "Dequeue Element #: " << i << ", Status: " << status << endl;
	}

	for(int i = 1; i <= 3; i++)
	{
		bool status = inputPQueue.dequeue(); //insert our new event into the queue
		//inputPQueue.print(); //debug
		cout << "Dequeue Element #: " << i << ", Status: " << status << endl;
	}

	Event exceptionTestEvent = inputPQueue.peek();
	inputPQueue.print(); //debug
}

int main(void)
{
	Queue bankQueue; //represents the line of customers in the bank/bank line
	PQueue eventListPQueue; //priority queue eventListPQueue for the event list

	bool tellerAvailable = true;

//	loadIntoBankQueue(bankQueue); //load data into bankQueue from file
//	loadIntoPriorityQueue(eventListPQueue); //load data into Priority Queue from file
//	loadIntoPriorityQueueAdvanced(eventListPQueue); //load data into Priority Queue from file
//
	bankQueueStressTest(bankQueue);
//	pQueueStressTest(eventListPQueue);

//	//??add all the the arrival events from bankQueue
//	while(!eventListPQueue.isEmpty()) //run while eventListPQueue is not empty
//	{
//		Event newEvent = eventListPQueue.peek();
//		// Get current time
//		unsigned int currentTime = newEvent.getTime(); // get time of newEvent
//		if (newEvent.getType() == 'A') //check if newEvent is an arrival event
//		{
//			processArrival(newEvent, eventListPQueue, bankQueue, tellerAvailable, currentTime);
//		}
//		else
//		{
//			processDeparture(newEvent, eventListPQueue, bankQueue, tellerAvailable, currentTime);
//		}
//	}


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