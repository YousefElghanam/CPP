#include <iostream>
#include <algorithm>
#include <utility>
#include <limits.h>
#include "Span.hpp"

/* The subject says addNumber should add a number to the container, but
	it did NOT specify that we should have multiple same value elements,
	Hence the use of set. It doesn't matter for functionality of
	shortestSpan() and longestSpan() if I have multiple elements of the
	same value */
#include <set>

const char*	Span::NotEnoughElementsException::what(void) const throw() {
	return "Container does not have enough elements";
}

const char*	Span::CapReachedException::what(void) const throw() {
	return "Container reached it's maximum capacity";
}

Span::Span(void):
	cap(0), curShortestSpan(LONG_MAX), curLongestSpan(0) {}

Span::~Span(void) {}

Span&	Span::operator=(const Span& obj) {
	if (&obj != this) {
		this->set = std::set<int>(obj.set);
		this->cap = obj.cap;
		this->curShortestSpan = obj.curShortestSpan;
		this->curLongestSpan = obj.curLongestSpan;
	}
	return *this;
}

Span::Span(const Span& obj):
	set(obj.set), cap(obj.cap), curShortestSpan(obj.curShortestSpan), curLongestSpan(obj.curLongestSpan) {}

Span::Span(const unsigned int cap):
	cap(cap), curShortestSpan(LONG_MAX), curLongestSpan(0) {}

void	Span::setShortestSpan(const std::set<int>::iterator& first,
								const std::set<int>::reverse_iterator& last,
								const std::set<int>::iterator num) {
	if (*num != *last) {
		std::set<int>::iterator	next = num;
		++next;
		this->curShortestSpan = std::min(this->curShortestSpan, static_cast<long>(*next - *num));
	}
	if (*num != *first) {
		std::set<int>::iterator	prev = num;
		--prev;
		this->curShortestSpan = std::min(this->curShortestSpan, static_cast<long>(*num - *prev));
	}
}

void	Span::setLongestSpan(const std::set<int>::iterator& first,
							const std::set<int>::reverse_iterator& last) {
	this->curLongestSpan = *last - *first;
}

void	Span::addNumber(const int num) {
	if (this->set.find(num) == this->set.end() && this->set.size() == this->cap) {
		throw Span::CapReachedException();
	}

	const std::pair<std::set<int>::iterator, bool> insertRet =  this->set.insert(num);
	if (!insertRet.second) {
		return ;
	}

	if (AT_INSERTION) {
		const std::set<int>::iterator			firstIt = this->set.begin();
		const std::set<int>::reverse_iterator	lastIt = this->set.rbegin();
		if (this->set.size() > 1) {
			setShortestSpan(firstIt, lastIt, insertRet.first);
			setLongestSpan(firstIt , lastIt);
		}
	}
}

static void	printElement(int element) {
	std::cout << element << " ";
}

void	Span::printContainer(void) const {
	std::cout << "The container contains (" << this->set.size() << "): ";
	if (this->set.empty()) {
		std::cout << "nothing" << std::endl;
	}
	else {
		std::for_each(this->set.begin(), this->set.end(), printElement);
		std::cout << std::endl;
	}
	std::cout << "first number (also the lowest): " << *this->set.begin() << std::endl;
	std::cout << "last number (also the highest): " << *this->set.rbegin() << std::endl;
}

long	Span::shortestSpan(void) const {
	if (this->set.empty() || this->set.size() == 1) {
		throw Span::NotEnoughElementsException();
	}
	if (AT_INSERTION) {
		return this->curShortestSpan;
	}
	int		prev = *this->set.begin();
	long	res = LONG_MAX;
	for (std::set<int>::iterator it = ++this->set.begin(); it != this->set.end(); it++) {
		res = std::min(res, static_cast<long>(*it - prev));
		prev = *it;
	}
	return res;
}

long	Span::longestSpan(void) const {
	if (this->set.empty() || this->set.size() == 1) {
		throw Span::NotEnoughElementsException();
	}
	if (AT_INSERTION) {
		return this->curLongestSpan;
	}
	return *this->set.rbegin() - *this->set.begin();
}
