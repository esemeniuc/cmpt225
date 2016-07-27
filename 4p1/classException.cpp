//
// Created by eric on 21/07/16.
//

#include "classException.h"


classException::classException(const std::string& message):
logic_error("Class Exception: " + message)
{
	//nothing else to do
}
