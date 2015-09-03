#include <iostream>
#include "SmartInt.h"
using namespace std;

template<typename T> void assertEquals(T left, T right, char* message)
{
	if (left != right)
	{
		cout << message << endl;
	}
}

template<typename T> void assertNoEquals(T left, T right, char* message)
{
	if (left == right)
	{
		cout << message << endl;
	}
}

void fail(char* message)
{
	cout << message << endl;
}

void testEquality()
{
	SmartInt ten1(10), ten2(10);

	bool expectedValue = true;
	bool realValue = ten1 == ten2;

	assertEquals<bool>(realValue, expectedValue, "Equality test failed!");
}

void testInequality()
{
	SmartInt ten(10), eleven(11);

	bool expectedValue = true;
	bool realValue = ten != eleven;

	assertEquals<SmartInt>(realValue, expectedValue, "Inequality test failed!");
}

void testConversion()
{
	SmartInt v(128);

	int expectedValue = 128;
	int realValue = v.toInt();

	assertEquals<int>(realValue, expectedValue, "Conversion test failed!");
}

void testAddition()
{
	SmartInt v1(1), v2(5);

	SmartInt expectedValue(6);
	SmartInt realValue = v1 + v2;

	assertEquals<SmartInt>(realValue, expectedValue, "Addition test failed!");
}

void testBigNumbersAddition()
{
	try
	{
		SmartInt v1(0x7FFFFFFF), v2(0x7FFFFFFF);
		SmartInt realValue = v1 + v2;

		fail("Big numbers addition test failed!");
	}
	catch (...)
	{
	}
}

void testNegativeNumbersAddition()
{
	SmartInt v1(10), v2(-100);

	SmartInt expectedValue(-90);
	SmartInt realValue = v1 + v2;

	assertEquals(realValue, expectedValue, "Negative numbers addition test failed!");
}



void main()
{
	testEquality();
	testInequality();
	testConversion();
	testAddition();
	testBigNumbersAddition();
	testNegativeNumbersAddition();
	getchar();
}