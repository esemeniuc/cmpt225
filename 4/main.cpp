#include <iostream>
#include "testDriver.h"

using namespace std;

int main()
{
	testDriver testDriver1;
//	testDriver1.throwException();
	testDriver1.studentValidate();
//	testDriver1.studentThrowException();
	testDriver1.universityValidate();
//	testDriver1.universityThrowException();
	cout << "Hello, World!" << endl;
	return 0;
}
