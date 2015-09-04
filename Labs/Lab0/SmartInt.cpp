#include "SmartInt.h"
#include <limits.h>

SmartInt::SmartInt()
{
	_value = 0;
}

SmartInt::SmartInt(int value)
{
	_value = value;
}

SmartInt::SmartInt(const SmartInt& other)
{
	_value = other._value;
}

SmartInt::~SmartInt()
{
}

int SmartInt::toInt()
{
	return _value;
}

SmartInt SmartInt::operator+(SmartInt other) throw (char *)
{
	long long newValue = (long long)_value + (long long)other._value;
	SmartInt result = tryConvertFrom(newValue);
	return result;
}

SmartInt SmartInt::operator-(SmartInt other) throw (char*)
{
	long long newValue = (long long)_value - (long long)other._value;
	SmartInt result = tryConvertFrom(newValue);
	return result;
}

SmartInt SmartInt::operator*(SmartInt other) throw (char*)
{
	long long newValue = (long long)_value * (long long)other._value;
	SmartInt result = tryConvertFrom(newValue);
	return result;
}

SmartInt SmartInt::operator/(SmartInt other) throw (char*)
{
	long long newValue = (long long)_value / (long long)other._value;
	SmartInt result(newValue);
	return result;
}

SmartInt SmartInt::operator-() throw (char*)
{
	long long newValue = -((long long)_value);
	SmartInt result = tryConvertFrom(newValue);
	return result;
}

SmartInt SmartInt::operator=(SmartInt other)
{
	_value = other._value;
	return *this;
}

bool SmartInt::operator==(SmartInt other)
{
	return _value == other._value;
}

bool SmartInt::operator!=(SmartInt other)
{
	return _value != other._value;
}

SmartInt SmartInt::tryConvertFrom(long long newValue)
{
	long long maxValue = INT_MAX, minValue = INT_MIN;

	if (newValue > maxValue || newValue < minValue)
		throw "Operation overflow exception";

	SmartInt result((int)newValue);
	return result;
}