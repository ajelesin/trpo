#pragma once

class TestArray
{
private:
	static void testEquality();
	static void testInequalityByElement();
	static void testInequalityByLength();
	static void testAddition();
	static void testAccessByIndex();
	static void testChangeArrayLength();

public:
	static void runTest();
};