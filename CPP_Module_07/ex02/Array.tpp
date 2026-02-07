#include "Array.hpp"
#include <exception>

template <class T>
Array<T>::Array(void): arr(new T[0]), arrLen(0) {}

template <class T>
Array<T>::~Array(void) {
	delete []this->arr;
}

template <class T>
Array<T>::Array(unsigned int n): arr(new T[n]), arrLen(n) {
	for (unsigned int i = 0; i < n; i++) {
		this->arr[i] = T();
	}
}

template <class T>
Array<T>::Array(const Array<T>& obj): arr(new T[obj.arrLen]), arrLen(obj.arrLen) {
	for (unsigned int i = 0; i < obj.arrLen; i++) {
		this->arr[i] = T(obj.arr[i]);
	}
}

template <class T>
Array<T>&	Array<T>::operator=(const Array& obj) {
	if (this != &obj) {
		delete []this->arr;
		this->arr = new T[obj.arrLen];
		this->arrLen = obj.arrLen;
		for (unsigned int i = 0; i < obj.arrLen; i++) {
			this->arr[i] = T(obj.arr[i]);
		}
	}
	return *this;
}

template <class T>
T&				Array<T>::operator[](unsigned int i) {
	if (i >= this->arrLen) {
		throw std::exception();
	}
	return this->arr[i];
}

template <class T>
const T&				Array<T>::operator[](unsigned int i) const {
	if (i >= this->arrLen) {
		throw std::exception();
	}
	return this->arr[i];
}

template <class T>
unsigned int	Array<T>::size(void) const {
	return this->arrLen;
}
