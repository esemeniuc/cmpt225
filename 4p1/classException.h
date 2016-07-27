//
// Created by eric on 21/07/16.
//

#ifndef INC_4_CLASSEXCEPTION_H
#define INC_4_CLASSEXCEPTION_H

#include <stdexcept>


class classException : public std::logic_error
{
public:
	classException(const std::string& message);
};


#endif //INC_4_CLASSEXCEPTION_H
