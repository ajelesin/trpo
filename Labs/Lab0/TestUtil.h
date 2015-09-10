#pragma once

#include <iostream>
using namespace std;

class TestUtil
{
public:
	template<typename T> static void assertEquals(T left, T right, char* message)
	{
		if (left != right)
		{
			cout << message << endl;
		}
	};

	template<typename T> static void assertNoEquals(T left, T right, char* message)
	{
		if (left == right)
		{
			cout << message << endl;
		}
	};

	static void fail(char* message)
	{
		cout << message << endl;
	};
};