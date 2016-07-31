/*
 * classException.cpp
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection ADT class is empty.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */

#include "classException.h"

classException::classException(const std::string& message):
		logic_error("Class Exception: " + message)
{
	//nothing else to do
}