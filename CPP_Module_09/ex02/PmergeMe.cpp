#include "PmergeMe.hpp"

#include <cmath>
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

size_t	comparisonCount = 0;

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& obj) {
	(void)obj;
}

PmergeMe&		PmergeMe::operator=(const PmergeMe& obj) {
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

void		PmergeMe::printPairVec(const std::vector<Pair>& pairVec) {
	std::for_each(pairVec.begin(), pairVec.end(), printPairElmnt);
	std::cout << std::endl;
}

void		PmergeMe::merge(std::vector<Pair>& pairVec, int level) {
	(void)pairVec; (void)level;
	if (pairVec.size() == 1) {
		return ;
	}
	std::vector<Pair>	newPairVec;
	std::vector<long>	vec;
	for (std::vector<Pair>::iterator it = pairVec.begin(); it < pairVec.end(); it++, it++) {
		vec.clear();
		if ((it + 1) == pairVec.end()) {
			vec.push_back(it->first.at(0));
			newPairVec.push_back(Pair(vec, it->second));
			break ;
		}
		if (it->first.at(0) >= ((it + 1)->first.at(0))) {
			for (std::vector<long>::iterator vecIt = it->first.begin(); vecIt != it->first.end(); vecIt++) {
				vec.push_back(*vecIt);
			}
			for (std::vector<long>::iterator vecIt = (it + 1)->first.begin(); vecIt != (it + 1)->first.end(); vecIt++) {
				vec.push_back(*vecIt);
			}
			newPairVec.push_back(Pair(vec, it->second));
		}
		else {
			for (std::vector<long>::iterator vecIt = (it + 1)->first.begin(); vecIt != (it + 1)->first.end(); vecIt++) {
				vec.push_back(*vecIt);
			}
			for (std::vector<long>::iterator vecIt = it->first.begin(); vecIt != it->first.end(); vecIt++) {
				vec.push_back(*vecIt);
			}
			newPairVec.push_back(Pair(vec, (it + 1)->second));
		}
	}
	std::cout << "rec level " << level << std::endl;
	PmergeMe::printPairVec(newPairVec);
	PmergeMe::merge(newPairVec, level + 1);
	// if (pairVec.size() == 2) {
	// 	if (pairVec.at(0) > pairVec.at(1)) {
	// 		std::cout << "swapping" << std::endl;
	// 		const long tmp = pairVec.at(0);
	// 		pairVec.at(0) = pairVec.at(1);
	// 		pairVec.at(1) = tmp;
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

static size_t	ye_pow(size_t x, size_t y) {
	size_t	res = 1;
	if (x == 0) {
		if (y > 0) {
			return 0;
		}
		return 1;
	}
	for (size_t i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

static void	groupSwap(std::vector<long>& vec, size_t i, size_t step, size_t level) {
	for (size_t x = 0; x < ye_pow(2, level - 1); x++) {
		std::cout << "swapping " << vec.at(i - x) << " with " << vec.at(i - x + (step / 2)) << std::endl;;
		std::swap(vec.at(i - x), vec.at( i - x + (step / 2)));
	}
}

static void	mergeRaw(std::vector<long>& vec, size_t level) {
	// if (static_cast<size_t>(std::pow(2, level)) > vec.size()) {
	if (ye_pow(2, level) > vec.size()) {
		return ;
	}
	size_t	i = ye_pow(2, level - 1) - 1;	// 0 1 3 7
	size_t	step = ye_pow(2, level);		// 2 4 8 16
	// long	tmp;
	std::vector<long>	bigElmntVec;
	std::vector<long>	smallElmntVec;
	std::cout << "at level " << level << " sequence is: " << std::endl;
	PmergeMe::printVec(vec);
	while (i < vec.size()) {
		if (i + (step / 2) >= vec.size()) {
			break ;
		}
		std::cout << "pointing at " << vec.at(i) << " and next is " << vec.at(i + (step / 2)) << std::endl;
		comparisonCount++;
		if (vec.at(i) > vec.at(i + (step / 2))) {
			// tmp = vec.at(i);
			// vec.at(i) = vec.at(i + (step / 2));
			// vec.at(i + (step / 2)) = tmp;
			groupSwap(vec, i, step, level);
		}
		i += step;
	}
	std::cout << "end of level " << level << " sequence became: " << std::endl;
	PmergeMe::printVec(vec);
	std::cout << "comparisons done: " << comparisonCount << std::endl << std::endl;
	mergeRaw(vec, level + 1);
	// for (;i + 1 < vec.size(); i += 2) {
	// 	if (vec.at(i) >= vec.at(i + 1)) {
	// 		bigElmntVec.push_back(vec.at(i));
	// 		smallElmntVec.push_back(vec.at(i + 1));
	// 	}
	// 	else {
	// 		bigElmntVec.push_back(vec.at(i + 1));
	// 		smallElmntVec.push_back(vec.at(i));
	// 	}
	// }
	// if (i < vec.size()) {
	// 	smallElmntVec.push_back(vec.at(i));
	// }
	// std::cout << "level " << level << std::endl;
	// std::cout << "biig: ";
	// PmergeMe::printVec(bigElmntVec);
	// std::cout << "smal: ";
	// PmergeMe::printVec(smallElmntVec);
	// std::cout << std::endl;
	// mergeRaw(bigElmntVec, level + 1);
	// mergeRaw(smallElmntVec, level + 1);
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
	std::vector<Pair>	pairVec;
	std::vector<long>	rawVec;
	pairVec.reserve(argc - 1);
	rawVec.reserve(argc - 1);
	for (size_t i = 1; i < argc; i++) {
		if (!validPosNum(argv[i])) {
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
			return 1;
		}
		Vec	vec;
		vec.push_back(std::atol(argv[i]));
		rawVec.push_back(std::atol(argv[i]));
		pairVec.push_back(Pair(vec, i));
	}
	std::vector<long>	seq = insertionSequence(argc - 1);
	// printVec(seq);
	if (rawVec.size() == 1) {
		return 0;
	}
	// PmergeMe::merge(pairVec, 1);
	mergeRaw(rawVec, 1);
	// std::cout << "RES: " << std::endl;
	// printPairVec(pairVec);
	return 0;
}
