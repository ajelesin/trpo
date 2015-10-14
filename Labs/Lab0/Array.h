#pragma once
#include "Exception.h"

template <class T>
class Array
{
public:
	Array();
	Array(int);
	Array(const Array<T>&);

	~Array();

	void set(T, int) throw (Exception);
	T get(int) throw (Exception);
	int length();
	void setLength(int) throw (Exception);

	T& operator[](int) throw (Exception);
	Array<T> operator=(const Array<T>&);
	Array<T> operator+(const Array<T>&);
	bool operator==(const Array<T>&);
	bool operator!=(const Array<T>&);

	static Array<T> asArray(T[], int);

private:
	T* _values;
	int _length;
};