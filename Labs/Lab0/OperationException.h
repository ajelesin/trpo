#pragma once

class OperationException
{
public:
	OperationException(char*, int, int);
	char* getMessage();
private:
	char _operation[20];
	int _left, _right;
};