#pragma once

class SmartInt
{
public:
	SmartInt();
	SmartInt(int);
	SmartInt(const SmartInt&);
	~SmartInt();

	int toInt();
	SmartInt operator+(SmartInt) throw (char *);
	SmartInt operator-(SmartInt) throw (char*);
	SmartInt operator*(SmartInt) throw (char*);
	SmartInt operator/(SmartInt) throw (char*);
	SmartInt operator-() throw (char*);
	SmartInt operator=(SmartInt);
	bool operator==(SmartInt);
	bool operator!=(SmartInt);

private:
	int _value;

private:
	static SmartInt tryConvertFrom(long long);
};