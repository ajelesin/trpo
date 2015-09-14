#pragma once
#include "TestArray2D.h"
#include "Array2D.h"
#include "Array2D.cpp"
#include "TestUtil.h"

void TestArray2D::testEquality()
{
	int a11[2] = { 1, 2 };
	int a12[2] = { 2, 1 };
	int* a1[2] = { a11, a12 };

	int a21[2] = { 1, 2 };
	int a22[2] = { 2, 1 };
	int* a2[2] = { a21, a22 };

	Array2D<int> s1 = Array2D<int>::asArray(a1, 2, 2);
	Array2D<int> s2 = Array2D<int>::asArray(a2, 2, 2);

	bool realValue = s1 == s2;
	bool expectedValue = true;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Equality test failed!");
}

void TestArray2D::testInequalityByElement()
{
	int a11[2] = { 1, 2 };
	int a12[2] = { 2, 1 };
	int* a1[2] = { a11, a12 };

	int a21[2] = { 1, 3 };
	int a22[2] = { 3, 1 };
	int* a2[2] = { a21, a22 };

	Array2D<int> s1 = Array2D<int>::asArray(a1, 2, 2);
	Array2D<int> s2 = Array2D<int>::asArray(a2, 2, 2);

	bool realValue = s1 != s2;
	bool expectedValue = true;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Inequality test failed!");
}

void TestArray2D::testInequalityByLength()
{
	int a11[2] = { 1, 2 };
	int a12[2] = { 2, 1 };
	int* a1[2] = { a11, a12 };

	int a21[2] = { 1, 2 };
	int* a2[2] = { a21 };

	Array2D<int> s1 = Array2D<int>::asArray(a1, 2, 2);
	Array2D<int> s2 = Array2D<int>::asArray(a2, 1, 2);

	bool realValue = s1 != s2;
	bool expectedValue = true;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Inequality test failed!");
}

void TestArray2D::testAccessByIndex()
{
	Array2D<int> s(10, 10);
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			s.set(i + j, i, j);
		}
	}

	int sumOfElements = 0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			sumOfElements += s.get(i, j);
		}
	}

	int expectedValue = 900;
	int realValue = sumOfElements;

	TestUtil::assertEquals<int>(expectedValue, realValue, "Access by index test failed!");
}

void TestArray2D::testChangeArrayLength()
{
	int a1[3] = { 1, 2, 3 };
	int a2[3] = { 2, 3, 4 };
	int* a[2] = { a1, a2 };
	Array2D<int> s = Array2D<int>::asArray(a, 2, 3);

	s.setLength(2, 1);
	TestUtil::assertEquals<int>(s.length(), 1, "Change length test failed!");
	TestUtil::assertEquals<int>(s.rank(), 2, "Change length test failed!");
	TestUtil::assertEquals<int>(s[0][0], 1, "Change length test failed!");
	try{
		int x = s[1][10];
		TestUtil::fail("Change length test failed!");
	}
	catch (...){
	}
}

void TestArray2D::runTest()
{
	testEquality();
	testInequalityByElement();
	testInequalityByLength();
	testAccessByIndex();
	testChangeArrayLength();
}