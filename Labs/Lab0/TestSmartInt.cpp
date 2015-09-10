#pragma once

#include "TestUtil.h"
#include "SmartInt.h"
#include "TestSmartInt.h"

void TestSmartInt::testEquality()
{
	SmartInt ten1(10), ten2(10);

	bool expectedValue = true;
	bool realValue = ten1 == ten2;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Equality test failed!");
}
;
void TestSmartInt::testInequality()
{
	SmartInt ten(10), eleven(11);

	bool expectedValue = true;
	bool realValue = ten != eleven;

	TestUtil::assertEquals<bool>(realValue, expectedValue, "Inequality test failed!");
};

void TestSmartInt::testConversion()
{
	SmartInt v(128);

	int expectedValue = 128;
	int realValue = v.toInt();

	TestUtil::assertEquals<int>(realValue, expectedValue, "Conversion test failed!");
};

void TestSmartInt::testAddition()
{
	SmartInt v1(1), v2(5);

	SmartInt expectedValue(6);
	SmartInt realValue = v1 + v2;

	TestUtil::assertEquals<SmartInt>(realValue, expectedValue, "Addition test failed!");
};

void TestSmartInt::testBigNumbersAddition()
{
	try	{
		SmartInt v1(0x7FFFFFFF), v2(0x7FFFFFFF);
		SmartInt realValue = v1 + v2;

		TestUtil::fail("Big numbers addition test failed!");
	}
	catch (...)	{
	}
};

void TestSmartInt::testNegativeNumbersAddition()
{
	SmartInt v1(10), v2(-100);

	SmartInt expectedValue(-90);
	SmartInt realValue = v1 + v2;

	TestUtil::assertEquals<SmartInt>(realValue, expectedValue, "Negative numbers addition test failed!");
};

void TestSmartInt::testSubstraction()
{
	SmartInt v1(0), v2(10);

	SmartInt expectedValue(-10);
	SmartInt realValue = v1 - v2;

	TestUtil::assertEquals<SmartInt>(realValue, expectedValue, "Substraction test failed!");
};

void TestSmartInt::testBigNumbersSubstraction()
{
	try	{
		SmartInt v1(0x80000001), v2(80000001);
		SmartInt realValue = v1 - v2;

		TestUtil::fail("Big numbers substraction test failed!");
	}
	catch (...){
	}
};

void TestSmartInt::testMultiplication()
{
	SmartInt v1(10), v2(-10);

	SmartInt expectedValue(-100);
	SmartInt realValue = v1 * v2;

	TestUtil::assertEquals<SmartInt>(realValue, expectedValue, "Multiplication test failed!");
};

void TestSmartInt::testBigNumbersMultiplication()
{
	try	{
		SmartInt v1(0x80000001), v2(80000001);
		SmartInt realValue = v1 * v2;

		TestUtil::fail("Big numbers multiplication test failed!");
	}
	catch (...){
	}
};

void TestSmartInt::testDivision()
{
	SmartInt v1(15), v2(6);

	SmartInt expectedValue(2);
	SmartInt realValue = v1 / v2;

	TestUtil::assertEquals<SmartInt>(realValue, expectedValue, "Division test failed!");
};

void TestSmartInt::runTest()
{
	testEquality();
	testInequality();
	testConversion();
	testAddition();
	testBigNumbersAddition();
	testNegativeNumbersAddition();
	testSubstraction();
	testBigNumbersSubstraction();
	testMultiplication();
	testBigNumbersMultiplication();
	testDivision();
};