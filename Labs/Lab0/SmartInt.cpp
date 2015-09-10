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

SmartInt SmartInt::operator+(SmartInt other) throw (OperationException)
{
	try	{
		long long newValue = (long long)_value + (long long)other._value;
		SmartInt result = tryConvertFrom(newValue);
		return result;
	}
	catch (...){
		throw new OperationException("addition", _value, other._value);
	}
}

SmartInt SmartInt::operator-(SmartInt other) throw (OperationException)
{
	try{
		long long newValue = (long long)_value - (long long)other._value;
		SmartInt result = tryConvertFrom(newValue);
		return result;
	}
	catch (...){
		throw new OperationException("subtraction", _value, other._value);
	}
}

SmartInt SmartInt::operator*(SmartInt other) throw (OperationException)
{
	try {
		long long newValue = (long long)_value * (long long)other._value;
		SmartInt result = tryConvertFrom(newValue);
		return result;
	}
	catch (...){
		throw new OperationException("multiplication", _value, other._value);
	}
}

SmartInt SmartInt::operator/(SmartInt other) throw (OperationException)
{
	try {
		long long newValue = (long long)_value / (long long)other._value;
		SmartInt result(newValue);
		return result;
	}
	catch (...){
		throw new OperationException("division", _value, other._value);
	}
}

SmartInt SmartInt::operator-() throw (OperationException)
{
	try {
		long long newValue = -((long long)_value);
		SmartInt result = tryConvertFrom(newValue);
		return result;
	}
	catch (...){
		throw new OperationException("inversion", 0, _value);
	}
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