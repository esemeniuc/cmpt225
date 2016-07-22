//
// Created by eric on 21/07/16.
//

#include "testDriver.h"
#include "classException.h"

void testDriver::throwException()
{
	throw(classException("Error, wtf mate?"));
}