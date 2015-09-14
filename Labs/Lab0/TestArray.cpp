#pragma once
#include "TestArray.h"
#include "Array.h"
#include "Array.cpp"
#include "TestUtil.h"

void TestArray::testEquality()
{
	int a1[2] = { 1, 2 };
	int a2[2] = { 1, 2 };

	Array<int> s1 = Array<int>::asArray(a1, 2);
	Array<int> s2 = Array<int>::asArray(a2, 2);

	bool realValue = s1 == s2;
	bool expectedValue = true;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Equality test failed!");
}

void TestArray::testInequalityByElement()
{
	int a1[2] = { 1, 2 };
	int a2[2] = { 3, 2 };

	Array<int> s1 = Array<int>::asArray(a1, 2);
	Array<int> s2 = Array<int>::asArray(a2, 2);

	bool realValue = s1 != s2;
	bool expectedValue = true;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Inequality test failed!");
}

void TestArray::testInequalityByLength()
{
	int a1[2] = { 1, 2 };
	int a2[2] = { 3 };

	Array<int> s1 = Array<int>::asArray(a1, 2);
	Array<int> s2 = Array<int>::asArray(a2, 2);

	bool realValue = s1 != s2;
	bool expectedValue = true;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Inequality test failed!");
}

void TestArray::testAccessByIndex()
{
	Array<int> s(10);
	for (int i = 0; i < 10; i++){
		s.set(i + 1, i);
	}

	int sumOfElements = 0;
	for (int i = 0; i < 10; i++){
		sumOfElements += s.get(i);
	}

	int expectedValue = 55;
	int realValue = sumOfElements;

	TestUtil::assertEquals<int>(expectedValue, realValue, "Access by index test failed!");
}

void TestArray::testAddition()
{
	int a1[2] = {1, 2};
	int a2[2] = { 1, 2 };
	int a[4] = { 1, 2, 1, 2 };

	Array<int>
		s1 = Array<int>::asArray(a1, 2),
		s2 = Array<int>::asArray(a2, 2);

	Array<int> realValue = s1 + s2;
	Array<int> expectedValue = Array<int>::asArray(a, 4);

	TestUtil::assertEquals<Array<int>>(expectedValue, realValue, "Addition test failed!");
}

void TestArray::testChangeArrayLength()
{
	int a[] = { 1, 2, 3 };
	Array<int> s = Array<int>::asArray(a, 3);

	s.setLength(1);
	TestUtil::assertEquals<int>(s.length(), 1, "Change length test failed!");
	TestUtil::assertEquals<int>(s[0], 1, "Change length test failed!");
	try{
		int x = s[1];
		TestUtil::fail("Change length test failed!");
	}
	catch (...){
	}
}

void TestArray::runTest()
{
	testEquality();
	testInequalityByElement();
	testInequalityByLength();
	testAddition();
	testAccessByIndex();
	testChangeArrayLength();
}