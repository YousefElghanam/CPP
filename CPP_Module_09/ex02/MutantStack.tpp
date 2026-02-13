#include "MutantStack.hpp"
#include <stack>

template<class T>
MutantStack<T>::MutantStack(void): std::stack<T>() {}

template<class T>
MutantStack<T>::~MutantStack(void) {}

template<class T>
MutantStack<T>::MutantStack(const MutantStack<T>& obj): std::stack<T>(obj) {}

template<class T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& obj) {
	std::stack<T>::operator=(obj);
	return *this;
}

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) {
	return this->c.begin();
}

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) {
	return this->c.end();
}
