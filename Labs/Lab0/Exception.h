#pragma once
class Exception
{
public:
	Exception(char*);
	char* getMessage();
private:
	char* _message;
};

