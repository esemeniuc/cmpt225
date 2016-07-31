/*
 * classException.h
 *
 * Class Description: Defines the exception that is thrown when the
 *                    data collection ADT class is empty.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */

#ifndef INC_4P2_CLASSEXCEPTION_H
#define INC_4P2_CLASSEXCEPTION_H

#include <stdexcept>


class classException : public std::logic_error
{
public:
	classException(const std::string& message);
};


#endif //INC_4P2_CLASSEXCEPTION_H