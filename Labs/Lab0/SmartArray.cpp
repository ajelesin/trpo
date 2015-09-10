#pragma once
#include "SmartArray.h"

template <class T>
SmartArray<T>::SmartArray(int length)
{
	_length = length;
	_values = new T[_length];
}

template <class T>
SmartArray<T>::SmartArray(T* values, int valuesLength)
{
	_length = valuesLength;
	_values = new T[_length];
	for (int i = 0; i < _length; i++){
		_values[i] = values[i];
	}
}

template <class T>
SmartArray<T>::SmartArray(const SmartArray& other)
{
	_length = other._length;
	_values = new T[_length];
	for (int i = 0; i < _length; i++){
		_values[i] = other._values[i];
	}
}

template <class T>
SmartArray<T>::~SmartArray()
{
	delete[] _values;
}

template <class T>
void SmartArray<T>::set(T element, int index)
{
	if (index < 0 || index > _length - 1){
		throw new IndexArrayOutOfBoundsException(index);
	}

	_values[index] = element;
}

template <class T>
T SmartArray<T>::get(int index)
{
	if (index < 0 || index > _length - 1){
		throw new IndexArrayOutOfBoundsException(index);
	}

	return _values[index];
}

template <class T>
int SmartArray<T>::length()
{
	return _length;
}

template <class T>
SmartArray<T> SmartArray<T>::operator=(SmartArray<T> other)
{
	_length = other._length;
	_values = new T[_length];
	for (int i = 0; i < _length; i++){
		_values[i] = other._values[i];
	}

	return *this;
}

template <class T>
SmartArray<T> SmartArray<T>::operator+(SmartArray<T> other)
{
	int newLength = _length + other._length;
	int* newValues = new int[newLength];
	for (int i = 0; i < _length; i++){
		newValues[i] = _values[i];
	}
	for (int i = _length; i < _length + other._length; i++){
		newValues[i] = other._values[i - _length];
	}

	SmartArray newArray(newLength);
	newArray._length = newLength;
	newArray._values = newValues;
	return newArray;
}

template <class T>
bool SmartArray<T>::operator==(SmartArray<T> other)
{
	if (_length != other._length){
		return false;
	}

	for (int i = 0; i < _length; i++){
		if (_values[i] != other._values[i])
			return false;
	}
	return true;
}

template <class T>
bool SmartArray<T>::operator!=(SmartArray<T> other)
{
	return !(*this == other);
}