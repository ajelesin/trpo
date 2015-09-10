#pragma once
#include "OperationException.h"

class SmartInt
{
public:
	SmartInt();
	SmartInt(int);
	SmartInt(const SmartInt&);
	~SmartInt();

	int toInt();
	SmartInt operator+(SmartInt) throw (OperationException);
	SmartInt operator-(SmartInt) throw (OperationException);
	SmartInt operator*(SmartInt) throw (OperationException);
	SmartInt operator/(SmartInt) throw (OperationException);
	SmartInt operator-() throw (OperationException);
	SmartInt operator=(SmartInt);
	bool operator==(SmartInt);
	bool operator!=(SmartInt);

private:
	int _value;

private:
	static SmartInt tryConvertFrom(long long);
};