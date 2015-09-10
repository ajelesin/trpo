#pragma once

#include "TestSmartArray.h"
#include "SmartArray.h"
#include "SmartArray.cpp"
#include "TestUtil.h"

void TestSmartArray::testEquality()
{
	int a1[2] = { 1, 2 };
	int a2[2] = { 1, 2 };

	SmartArray<int> s1(a1, 2);
	SmartArray<int> s2(a2, 2);

	bool realValue = s1 == s2;
	bool expectedValue = true;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Equality test failed!");
}

void TestSmartArray::testInequalityByElement()
{
	int a1[2] = { 1, 2 };
	int a2[2] = { 3, 2 };

	SmartArray<int> s1(a1, 2);
	SmartArray<int> s2(a2, 2);

	bool realValue = s1 != s2;
	bool expectedValue = true;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Inequality test failed!");
}

void TestSmartArray::testInequalityByLength()
{
	int a1[2] = { 1, 2 };
	int a2[2] = { 3 };

	SmartArray<int> s1(a1, 2);
	SmartArray<int> s2(a2, 2);

	bool realValue = s1 != s2;
	bool expectedValue = true;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Inequality test failed!");
}

void TestSmartArray::testAccessByIndex()
{
	SmartArray<int> s(10);
	for (int i = 0; i < 10; i++){
		s.set(i + 1, i);
	}

	int j = 0;
	for (int i = 0; i < 10; i++){
		j += s.get(i);
	}

	int expectedValue = 55;
	int realValue = j;

	TestUtil::assertEquals<int>(expectedValue, realValue, "Access by index test failed!");
}

void TestSmartArray::testAddition()
{
	int a1[2] = {1, 2};
	int a2[2] = { 1, 2 };
	int a[4] = { 1, 2, 1, 2 };

	SmartArray<int> s1(a1, 2), s2(a2, 2);

	SmartArray<int> realValue = s1 + s2;
	SmartArray<int> expectedValue(a, 4);

	TestUtil::assertEquals<SmartArray<int>>(expectedValue, realValue, "Addition test failed!");
}

void TestSmartArray::runTest()
{
	testEquality();
	testInequalityByElement();
	testInequalityByLength();
	testAddition();
	testAccessByIndex();
}