#include "MutantStack.hpp"
#include <stack>

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) {
	return this->c.begin();
}

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) {
	return this->c.end();
}
