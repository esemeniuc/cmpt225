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

void loadIntoPriorityQueue(PQueue &inputPQueue) // Create and add arrival events to event list
{
	unsigned int tempTime; //temporary holders for cin input
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


int main(void)
{
	Queue bankQueue; //represents the line of customers in the bank/bank line
	PQueue eventListPQueue; //priority queue eventListPQueue for the event list

	bool tellerAvailable = true;
	loadIntoPriorityQueue(eventListPQueue); //load data into Priority Queue from file/Create and add arrival events to event list

	//waitTime = SUM(time of departure) - SUM(processing time) - SUM(time of arrival)/COUNT(EVENTS)
	unsigned int sumDepartureTime = 0;
	unsigned int sumProcessingTime = 0;
	unsigned int sumArrivalTime = 0;
	unsigned int eventCount = 0; //track how many customers came in
	float waitTime; //Calculated at the end

	cout << "Simulation Begins" << endl;

	while(!eventListPQueue.isEmpty()) //run while eventListPQueue is not empty
	{
		Event newEvent = eventListPQueue.peek();
		// Get current time
		unsigned int currentTime = newEvent.getTime(); // get time of newEvent
		if (newEvent.getType() == 'A') //check if newEvent is an arrival event
		{
			// Processes an arrival event.
			//processArrival(newEvent, eventListPQueue, bankQueue, tellerAvailable, currentTime);

			eventListPQueue.dequeue(); //Remove this event from the event list
			Event customer = newEvent; //customer referenced in arrivalEvent
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

			cout << "Processing an arrival event at time:\t" << customer.getTime() << endl;
			eventCount++; //count how many customers arrived
			sumArrivalTime += customer.getTime();
			sumProcessingTime += customer.getLength();
		}
		else
		{
			// Processes a departure event.
//			processDeparture(newEvent, eventListPQueue, bankQueue, tellerAvailable, currentTime);
			eventListPQueue.dequeue(); // Remove this event from the event list

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

			cout << "Processing a departure event at time:\t" << currentTime << endl; //temp
			sumDepartureTime += currentTime;
		}

	}

	waitTime = (float)(sumDepartureTime - sumProcessingTime - sumArrivalTime)/eventCount; //do the average wait time calculation

	cout << "Simulation Ends\n\n";
	cout << "Final Statistics:" << endl;
	cout << "\tTotal number of people processed: " << eventCount << endl;
	cout << "\tAverage amount of time spent waiting: " << waitTime << endl;

//	cout << "Bank Queue Contents:" << endl;
//	bankQueue.print();
//	cout << "Priority Queue Contents:" << endl;
//	eventListPQueue.print();
//	resultPrinterQueue(bankQueue); //print out the results
	return 0;
}