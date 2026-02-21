#include "PmergeMe.hpp"

#include <cstddef>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cstring>

#include <iostream>

#include <algorithm>
#include <vector>

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& obj) {
	(void)obj;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& obj) {
	(void)obj;
	return *this;
}

static bool		validPosNum(char* num) {
	const size_t	len = std::strlen(num);
	if (len == 0 || len > 10) {
		return false;
	}
	for (size_t i = 0; i < len; i++) {
		if (std::isdigit(num[i]) == 0) {
			return false;
		}
	}
	return true;
}

static void		printElmnt(long num) {
	std::cout << num << " ";
}

static void		printVec(std::vector<long> vec) {
	std::for_each(vec.begin(), vec.end(), printElmnt);
	std::cout << std::endl;
}

int			PmergeMe::sort(int argc, char** argv) {
	std::vector<long>	vec;
	vec.reserve(argc - 1);
	for (int i = 1; i < argc; i++) {
		if (!validPosNum(argv[i])) {
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
			return 1;
		}
		vec.push_back(std::atol(argv[i]));
	}
	printVec(vec);
	return 0;
}
