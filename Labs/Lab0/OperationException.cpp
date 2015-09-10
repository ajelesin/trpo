#include <cstring>
#include <cstdio>
#include "OperationException.h"

OperationException::OperationException(char* operation, int left, int right)
{
	_left = left;
	_right = right;
	strncpy_s(_operation, operation, 80);
}

char* OperationException::getMessage()
{
	char message[50];
	sprintf_s(message, "Error in %s: %d and %d", _operation, _left, _right);
	return message;
}