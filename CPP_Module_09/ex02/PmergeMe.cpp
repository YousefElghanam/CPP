#include "PmergeMe.hpp"

#include <cstddef>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <exception>
#include <utility>

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

static bool		validPosNum(const char* num) {
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

static void		printPairElmnt(const std::pair<std::vector<long>, size_t>& pair) {
	std::cout << "idx " << pair.second << ": ";
	std::for_each(pair.first.begin(), pair.first.end(), printElmnt);
	std::cout << std::endl;
}

void		PmergeMe::printVec(const std::vector<long>& vec) {
	std::for_each(vec.begin(), vec.end(), printElmnt);
	std::cout << std::endl;
}

void		PmergeMe::printPairVec(const std::vector<Pair>& PairVec) {
	std::for_each(PairVec.begin(), PairVec.end(), printPairElmnt);
	std::cout << std::endl;
}

void		PmergeMe::merge(std::vector<Pair>& PairVec, int level) {
	(void)PairVec; (void)level;
	if (PairVec.size() == 1) {
		// do something ?? 
		return ;
	}
	std::vector<Pair>			newPairVec;
	
	for (std::vector<Pair>::iterator it = PairVec.begin(); it < PairVec.end(); it++, it++) {
		it++;
		if (it != PairVec.end()) {
			it++;
		}
	}
	// if (PairVec.size() == 2) {
	// 	if (PairVec.at(0) > PairVec.at(1)) {
	// 		std::cout << "swapping" << std::endl;
	// 		const long tmp = PairVec.at(0);
	// 		PairVec.at(0) = PairVec.at(1);
	// 		PairVec.at(1) = tmp;
	// 	}
	// 	return ;
	// }
	// std::cout << "level " << level << ":" << std::endl;
	// std::vector<long>	left(vec.begin(), vec.begin() + vec.size() / 2);
	// std::vector<long>	right(vec.begin() + vec.size() / 2, vec.end());
	// std::vector<long>	remainder;
	// if (left.size() < right.size()) {
	// 	remainder = std::vector<long>(vec.end() - 1, vec.end());
	// 	right.pop_back();
	// }
	// std::cout << "left: "; printVec(left);
	// std::cout << "right: "; printVec(right);
	// std::cout << "remainder: "; printVec(remainder);
	// std::cout << std::endl;
	// merge(left, level + 1);
	// merge(right, level + 1);
}

static std::vector<long>	insertionSequence(int size) {
	std::vector<long>	vec;
	vec.reserve(size + 2);
	vec.push_back(0);
	vec.push_back(1);
	for (int i = 2; i < size + 2; i++) {
		vec.push_back(vec.at(i - 1) + (2 * vec.at(i - 2)));
	}
	return vec;
}

int			PmergeMe::sort(const size_t argc, const char** argv) {
	std::vector<Pair>	PairVec;
	PairVec.reserve(argc - 1);
	for (size_t i = 1; i < argc; i++) {
		if (!validPosNum(argv[i])) {
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
			return 1;
		}
		Vec	vec;
		vec.push_back(std::atol(argv[i]));
		PairVec.push_back(Pair(vec, i));
	}
	std::vector<long>	seq = insertionSequence(argc - 1);
	printVec(seq);
	PmergeMe::merge(PairVec, 1);
	std::cout << "RES: " << std::endl;
	printPairVec(PairVec);
	return 0;
}
