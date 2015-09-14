#pragma once
#include "Exception.h"

template <class T>
class Array2D
{
public:
	Array2D();
	Array2D(int, int);
	Array2D(const Array2D<T>&);

	~Array2D();

	void set(T, int, int) throw (Exception);
	T get(int, int) throw (Exception);

	int length();
	int rank();
	void setLength(int, int) throw (Exception);

	Array2D<T> operator=(Array2D<T>);
	bool operator==(Array2D<T>);
	bool operator!=(Array2D<T>);

	static Array2D<T> asArray(T**, int, int);

	template <class T>
	class ProxyOperator {
	public:
		ProxyOperator(T* _array, int length) : _array(_array), _length(length) {}

		T operator[](int column) {
			if (column < 0 || column > _length - 1){
				throw new Exception("Index array out of bounds exception");
			}
			return _array[column];
		}
	private:
		T* _array;
		int _length;
	};

	ProxyOperator<T> operator[](int row) throw (Exception)	{
		if (row < 0 || row > _rank - 1){
			throw new Exception("Index array out of bounds exception");
		}
		return ProxyOperator<T>(_values[row], _length);
	};
private:
	T** _values;
	int _rank, _length;
};