#pragma once

class TestSmartArray
{
private:
	static void testEquality();
	static void testInequalityByElement();
	static void testInequalityByLength();
	static void testAddition();
	static void testAccessByIndex();

public:
	static void runTest();
};