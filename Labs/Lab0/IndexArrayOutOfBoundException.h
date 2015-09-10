#pragma once

class IndexArrayOutOfBoundsException
{
public:
	IndexArrayOutOfBoundsException(int);
	char* getMessage();
private:
	int _index;
};