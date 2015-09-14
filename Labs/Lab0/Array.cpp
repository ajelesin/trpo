#pragma once
#include "Array.h"

template <class T>
Array<T>::Array()
{
	_length = 0;
}

template <class T>
Array<T>::Array(int length)
{
	_length = length;
	_values = new T[_length];
}

template <class T>
Array<T>::Array(const Array& other)
{
	_length = other._length;
	_values = new T[_length];
	for (int i = 0; i < _length; i++){
		_values[i] = other._values[i];
	}
}

template <class T>
Array<T>::~Array()
{
	delete[] _values;
}

template <class T>
void Array<T>::set(T element, int index)
{
	if (index < 0 || index > _length - 1){
		throw new Exception("Index array out of bounds exception");
	}

	_values[index] = element;
}

template <class T>
T Array<T>::get(int index)
{
	if (index < 0 || index > _length - 1){
		throw new Exception("Index array out of bounds exception");
	}

	return _values[index];
}

template <class T>
int Array<T>::length()
{
	return _length;
}

template <class T>
void Array<T>::setLength(int newLength)
{
	if (newLength < 0){
		throw new Exception("Invalid argument exception");
	}

	T* tmpValues = new T[newLength];
	int minLength = (_length < newLength) ? _length : newLength;
	for (int i = 0; i < minLength; i++){
		tmpValues[i] = _values[i];
	}

	delete[] _values;
	_values = tmpValues;
	_length = newLength;
}

template <class T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index > _length - 1){
		throw new Exception("Index array out of bounds exception");
	}

	return _values[index];
}

template <class T>
Array<T> Array<T>::operator=(Array<T> other)
{
	delete[] _values;

	_length = other._length;
	_values = new T[_length];
	for (int i = 0; i < _length; i++){
		_values[i] = other._values[i];
	}

	return *this;
}

template <class T>
Array<T> Array<T>::operator+(Array<T> other)
{
	int newLength = _length + other._length;
	int* newValues = new int[newLength];
	for (int i = 0; i < _length; i++){
		newValues[i] = _values[i];
	}
	for (int i = _length; i < _length + other._length; i++){
		newValues[i] = other._values[i - _length];
	}

	Array<T> newArray;
	newArray._length = newLength;
	newArray._values = newValues;
	return newArray;
}

template <class T>
bool Array<T>::operator==(Array<T> other)
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
bool Array<T>::operator!=(Array<T> other)
{
	return !(*this == other);
}

template <class T>
Array<T> Array<T>::asArray(T* values, int valuesLength)
{
	Array<T> newArray;
	newArray._length = valuesLength;
	newArray._values = new T[valuesLength];
	for (int i = 0; i < valuesLength; i++){
		newArray._values[i] = values[i];
	}

	return newArray;
}