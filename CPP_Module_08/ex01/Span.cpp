#include <iostream>
#include <exception>
#include <algorithm>
#include "Span.hpp"

/* The subject did NOT specify that we should have multiple same value
	elements, Hence the use of set. It doesn't matter for functionality
	of shortestSpan() and longestSpan() if I have multiple elements of
	the same value */
#include <set>

Span::Span(void):
	cap(0) {}

Span::~Span(void) {}

Span&	Span::operator=(const Span& obj) {
	(void)obj;
	return *this;
}

Span::Span(const Span& obj):
	set(obj.set), cap(obj.cap) {}

Span::Span(const unsigned int cap):
	cap(cap) {}

void						Span::addNumber(const int num) {
	if (this->set.size() == this->cap) {
		throw std::exception();
	}
	this->set.insert(num);
}

static void					printElement(int element) {
	std::cout << element << " ";
}

void						Span::printSet(void) const {
	std::for_each(this->set.begin(), this->set.end(), printElement);
	std::cout << std::endl;
}
