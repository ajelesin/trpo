#pragma once
#include "Array2D.h"

template <class T>
Array2D<T>::Array2D()
{
	_rank = 0;
	_length = 0;
}

template <class T>
Array2D<T>::Array2D(int rank, int length)
{
	_rank = rank;
	_length = length;
	_values = new T*[_rank];
	for (int i = 0; i < _rank; i++){
		_values[i] = new T[_length];
	}
}

template <class T>
Array2D<T>::Array2D(const Array2D<T>& other)
{
	_rank = other._rank;
	_length = other._length;

	_values = new T*[_rank];
	for (int i = 0; i < _rank; i++){
		_values[i] = new T[_length];
	}

	for (int i = 0; i < _rank; i++){
		for (int j = 0; j < _length; j++){
			_values[i][j] = other._values[i][j];
		}
	}
}

template <class T>
Array2D<T>::~Array2D()
{
	for (int i = 0; i < _rank; i++){
		delete[] _values[i];
	}

	delete[] _values;
}

template <class T>
void Array2D<T>::set(T element, int row, int column)
{
	if (row < 0 || row > _rank - 1
		|| column < 0 || column > _length - 1)
		throw new Exception("Index array out of bounds exception!");

	_values[row][column] = element;
}

template <class T>
T Array2D<T>::get(int row, int column)
{
	if (row < 0 || row > _rank - 1
		|| column < 0 || column > _length - 1)
		throw new Exception("Index array out of bounds exception!");

	return _values[row][column];
}

template <class T>
int Array2D<T>::length(){
	return _length;
}

template <class T>
int Array2D<T>::rank(){
	return _rank;
}

template <class T>
void Array2D<T>::setLength(int newRank, int newLength)
{
	int minRank = newRank > _rank ? _rank : newRank;
	int minLength = newLength > _length ? _length : newLength;

	T** newValues = new T*[newRank];
	for (int i = 0; i < newRank; i++){
		newValues[i] = new T[_length];
	}

	if (_values){
		for (int i = 0; i < minRank; i++){
			for (int j = 0; j < minLength; j++){
				newValues[i][j] = _values[i][j];
			}
			delete[] _values[i];
		}
		delete[] _values;
	}

	_values = newValues;
	_rank = newRank;
	_length = newLength;
}

template <class T>
Array2D<T> Array2D<T>::operator=(Array2D<T> other)
{
	if (_values){
		for (int i = 0; i < _rank; i++){
			delete[] _values[i];
		}
		delete[] _values;
	}

	_rank = other.rank;
	_length = other._length;
	_values = new T*[_rank];
	for (int i = 0; i < _rank; i++){
		_values[i] = new T[_length];
	}

	for (int i = 0; i < _rank; i++){
		for (int j = 0; j < _length; j++){
			_values[i][j] = other._values[i][j];
		}
	}

	return *this;
}

template <class T>
bool Array2D<T>::operator==(Array2D<T> other)
{
	if (_rank != other._rank || _length != other._length)
		return false;

	for (int i = 0; i < _rank; i++){
		for (int j = 0; j < _length; j++){
			if (_values[i][j] != other._values[i][j])
				return false;
		}
	}

	return true;
}

template <class T>
bool Array2D<T>::operator!=(Array2D<T> other)
{
	return !(*this == other);
}

template <class T>
Array2D<T> Array2D<T>::asArray(T** values, int rank, int length)
{
	Array2D<T> result;
	result._rank = rank;
	result._length = length;
	result._values = new T*[rank];
	for (int i = 0; i < rank; i++){
		result._values[i] = new T[length];
	}

	for (int i = 0; i < rank; i++){
		for (int j = 0; j < length; j++){
			result._values[i][j] = values[i][j];
		}
	}

	return result;
}