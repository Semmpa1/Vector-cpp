#pragma once
#include <iostream>

template <class T>
class Vector
{
	T* arr;
	int _size;

public:
	Vector() {
		arr = new T[0];
		this->_size = 0;
	}
	Vector(int size) {
		arr = new T[size];
		this->_size = size;
	};

	int size() { return _size; }

	T* begin();

	T* end();

	void resize(int size);

	bool empty();

	T& at(int i);

	T& front();

	T& back();

	T* data();

	void assign(T val);

	void push_back(T val);

	void pop_back();

	void insert(int ind, T val);

	void erase(int ind);

	void clear();

	int& operator [](int i);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
int& Vector<T>::operator[] (int i) { return arr[i]; }

template <typename T>
T* Vector<T>::begin() {
	return arr;
}

template <typename T>
T* Vector<T>::end() {
	return arr+_size; //  :)
}

template <typename T>
void Vector<T>::resize(int size) {
	T* temp = new T[size];
	if (size > _size) {
		for (int i = 0; i < _size; ++i)  temp[i] = arr[i];
		for (int i = _size; i < size; i++) temp[i] = 0;
	}else {
		for (int i = 0; i < size; ++i)  temp[i] = arr[i];
	}

	_size = size;

	delete[] arr;
	arr = temp;
}

template <typename T>
bool Vector<T>::empty() { return _size == 0; }


template <typename T>
T& Vector<T>::at(int i) { 
	if (i > 0 && i < _size) return arr[i];
	else throw std::overflow_error("out of range");
}

template <typename T>
T& Vector<T>::front() { return *arr; }

template <typename T>
T& Vector<T>::back() { return *(arr+_size-1); }

template <typename T>
T* Vector<T>::data() { return arr; }



template <typename T>
void Vector<T>::assign(T val) { 
	for (size_t i = 0; i < _size; i++) arr[i] = val;
}

template <typename T>
void Vector<T>::push_back(T val) {
	T* temp = new T[Vector::_size + 1];

	for (int i = 0; i < _size; ++i)
	{
		temp[i] = arr[i];
	}
	temp[Vector::_size++] = val;

	delete[] arr;
	arr = temp;
}

template <typename T>
void Vector<T>::pop_back() {
	T* temp = new T[--_size];

	for (int i = 0; i < _size; ++i) {
		temp[i] = arr[i];
	}

	delete[] arr;
	arr = temp;
}

template <typename T>
void Vector<T>::insert(int ind,T val) {
	resize(++_size);
	for (size_t i = _size-1; i > ind; --i) {
		arr[i] = arr[i-1];
	}

	arr[ind] = val;
}

template <typename T>
void Vector<T>::erase(int ind) {
	for (size_t i = ind; i < _size; ++i) {
		arr[i] = arr[i + 1];
	}
	resize(--_size);
}

template <typename T>
void Vector<T>::clear() { resize(0); }