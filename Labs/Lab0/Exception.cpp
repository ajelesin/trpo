#pragma once
#include "Exception.h"

Exception::Exception(char* message)
{
	_message = message;
}

char* Exception::getMessage()
{
	return _message;
}
