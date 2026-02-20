#include "PmergeMe.hpp"

#include <climits>
#include <cctype>
#include <cstddef>
#include <exception>
#include <iostream>
#include <stack>

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& obj) {
	(void)obj;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& obj) {
	(void)obj;
	return *this;
}
