#include <iostream>
#include "Event.h"
#include "Queue.h"
#include "PQueue.h"


using namespace std;

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

	//BankSimApp is not to open and read input files, but is to read input from the command line
	//eg ./bsApp < simulation.in


	//cin >> NULL;
	cout << "Hello, World!" << endl;

	int* inputEvents = takeInput();

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
}



	return 0;
}