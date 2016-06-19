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
int* takeInput(void)
{
	int status = 0;
	int currentInputCount = 0;
	int* inputEvents = new int[queueCapacity]; //allocate an array of size queueCapacity to store the text input
	while(cin >> inputEvents[currentInputCount]) //eof check and load data into array
	{
		cout << "Input " << currentInputCount << ": Value: " << inputEvents[currentInputCount] << endl; //debug
		currentInputCount++; //increment our counter
	}

	return inputEvents;
}

int main(void)
{


	Queue bankQueue; //represents the line of customers in the bank
	PQueue eventListPQueue; //stores the priority list of customers

	int* inputEvents = takeInput();
	//add all the the arrival events from bankQueue
	//now add the departure events


// Psuedocode
//	Initialize the line to “no customers”
//	while ( events remain to be processed )
//	{
//		currentTime = time of next event
//		if ( event is an arrival event )
//	else
//	{
//		//Process the departure event
//	}
//
//	When an arrival event and a departure event occur at the same time,
//	arbitrarily process the arrival event first




	return 0;
}