#pragma once

class TestSmartInt
{
private:
	static void testEquality();
	static void testInequality();
	static void testConversion();
	static void testAddition();
	static void testBigNumbersAddition();
	static void testNegativeNumbersAddition();
	static void testSubstraction();
	static void testBigNumbersSubstraction();
	static void testMultiplication();
	static void testBigNumbersMultiplication();
	static void testDivision();

public:
	static void runTest();
};