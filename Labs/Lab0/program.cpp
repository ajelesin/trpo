#include "TestSmartInt.h"
#include "TestSmartInt.cpp"
#include "TestSmartArray.h"
//#include "TestSmartArray.cpp"

int main()
{
	TestSmartInt::runTest();
	TestSmartArray::runTest();
	getchar();
	return 0;
}