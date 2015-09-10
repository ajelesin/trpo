#pragma once
#include "IndexArrayOutOfBoundException.h"

template <class T>
class SmartArray
{
public:
	SmartArray(int);
	SmartArray(T*, int);
	SmartArray(const SmartArray<T>&);

	~SmartArray();

	void set(T, int) throw (IndexArrayOutOfBoundsException);
	T get(int) throw (IndexArrayOutOfBoundsException);
	int length();

	SmartArray<T> operator=(SmartArray<T>);
	SmartArray<T> operator+(SmartArray<T>);
	bool operator==(SmartArray<T>);
	bool operator!=(SmartArray<T>);

private:
	SmartArray();
	T* _values;
	int _length;
};