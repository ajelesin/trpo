#pragma once
#include "Exception.h"

class SmartInt
{
public:
	SmartInt();
	SmartInt(int);
	SmartInt(const SmartInt&);
	~SmartInt();

	int toInt();
	SmartInt operator+(SmartInt) throw (Exception);
	SmartInt operator-(SmartInt) throw (Exception);
	SmartInt operator*(SmartInt) throw (Exception);
	SmartInt operator/(SmartInt) throw (Exception);
	SmartInt operator-() throw (Exception);
	SmartInt operator=(SmartInt);
	bool operator==(SmartInt);
	bool operator!=(SmartInt);

private:
	int _value;

private:
	static SmartInt tryConvertFrom(long long);
};