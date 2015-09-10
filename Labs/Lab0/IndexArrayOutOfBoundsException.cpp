#include <cstdio>
#include "IndexArrayOutOfBoundException.h"

IndexArrayOutOfBoundsException::IndexArrayOutOfBoundsException(int index)
{
	_index = index;
}

char* IndexArrayOutOfBoundsException::getMessage()
{
	char message[50];
	sprintf_s(message, "Index array out at %d", _index);
	return message;
}