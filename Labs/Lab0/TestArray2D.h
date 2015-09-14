#pragma once

class TestArray2D
{
private:
	static void testEquality();
	static void testInequalityByElement();
	static void testInequalityByLength();
	static void testAccessByIndex();
	static void testChangeArrayLength();

public:
	static void runTest();
};