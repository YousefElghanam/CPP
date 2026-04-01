#include "PmergeMe.hpp"

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#include <cmath>
#include <cstddef>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <sys/types.h>

size_t	comparisonCount = 0;
typedef std::pair<long, size_t> MainPair;

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

void		PmergeMe::printVec(const std::vector<long>& vec, size_t level) {
	const size_t comma = ye_pow(2, level - 1);
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i);
		if ((i + 1) % comma == 0) {
			std::cout << " | ";
		}
		else {
			std::cout << " ";
		}
	}
	// std::for_each(vec.begin(), vec.end(), printElmnt);
	std::cout << std::endl;
}

void		PmergeMe::printPairVec(const std::vector<MainPair>& vec, size_t level) {
	const size_t comma = ye_pow(2, level - 1);
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i).first;
		if ((i + 1) % comma == 0) {
			std::cout << " | ";
		}
		else {
			std::cout << " ";
		}
	}
}

static void	groupSwap(std::vector<long>& vec, size_t i, size_t elmntSize) {
	for (size_t x = 0; x < elmntSize; x++) {
		// std::cout << "swapping " << vec.at(i - x) << " with " << vec.at(i - x + elmntSize) << std::endl;;
		std::swap(vec.at(i - x), vec.at( i - x + elmntSize));
	}
}

static void	makeSubVecs(const std::vector<long>& vec,
std::vector<MainPair >& main,
std::vector<long>& pend,
std::vector<long>& remainder,
size_t elmntSize) {
	bool	isB = true;
	// std::cout << std::endl << "calling makeSubVecs with elmntSize=" << elmntSize << std::endl;

	for (size_t i = 0; i < elmntSize && i < vec.size(); i++) { // This inserts b1 into main
		// std::cout << "inserting b1, pushed " << i + 1 << " nums to main" << std::endl;
		main.push_back(MainPair(vec.at(i), 0));
	}
	if (elmntSize * 2 >= vec.size()) {
		for (size_t i = elmntSize; i < vec.size(); i++) {
			remainder.push_back(vec.at(i));
		}
		return ;
	}
	for (size_t i = elmntSize; i < elmntSize * 2 && i < vec.size(); i++) { // This inserts a1 into main
		// std::cout << "inserting a1, pushed " << i + 1 << " nums to main" << std::endl;
		main.push_back(MainPair(vec.at(i), 1));
	}
	for (size_t i = elmntSize * 2; i < vec.size(); i += elmntSize) { // This inserts remaining a's into main and remaining b's into pend
		// std::cout << "at elmntSize=" << elmntSize << " pushing starting from i=" << i << std::endl;
		if (i + elmntSize > vec.size()) {
			for (;i < vec.size(); i++) {
				remainder.push_back(vec.at(i));
			}
			return ;
		}
		if (isB) {
			for (size_t x = 0;  x < elmntSize && i + x < vec.size(); x++) {
				pend.push_back(vec.at(i + x));
			}
			isB = false;
		}
		else {
			for (size_t x = 0;  x < elmntSize && i + x < vec.size(); x++) {
				// std::cout << "pushing " << vec.at(i + x) << " to main" << std::endl;
				main.push_back(MainPair(vec.at(i + x), ((i / elmntSize) + 1) / 2));
			}
			isB = true;
		}
	}
}

static size_t	getJacobIndex(size_t n) {
	const size_t ret = (ye_pow(2, (n + 1)) + ye_pow(-1, n)) / 3;

	return ret - 2;
}

// static void	insertMultiSeq(std::vector<long>& main,
// std::vector<long>& pend,
// size_t elmntSize,
// size_t idx,
// size_t prevIdx) {
// 	(void)main, (void)pend, (void)elmntSize, (void)idx, (void)prevIdx;

// 	for (;;) {
// 		for (size_t i = 0; i < elmntSize; i++) {
// 			pend.at(idx * elmntSize + elmntSize)
// 		}
// 	}
// }

static std::vector<size_t>	makeJacobSeq(size_t pendElmntsCount) {
	std::vector<size_t>	vec;

	for (size_t i = 2; i < pendElmntsCount + 2; i++) {
		size_t	subSeqSize = 1;

		if (i > 0) {
			subSeqSize = getJacobIndex(i) - getJacobIndex(i - 1);
		}
		for (size_t x = 0; x < subSeqSize; x++) {
			vec.push_back(getJacobIndex(i) - x + 2);
		}
	}
	return vec;
}

static void	insert(std::vector<MainPair>& main,
const std::vector<long>& pend,
size_t start,
size_t end,
size_t idx,
size_t elmntSize) {
	const long		num = pend.at((idx * elmntSize) + elmntSize - 1);
	const size_t	n_start = (start * elmntSize) + elmntSize - 1;
	// size_t n_end = (end * elmntSize) + elmntSize - 1;

	// std::cout << "inserting num " << num << " with start " << n_start << " and end " << n_end << std::endl; // PRINT
	if (start >= end) {
		comparisonCount++;
		if (num > main.at(n_start).first) { // TODO 1 comparison
			for (size_t i = 0; i < elmntSize; i++) {
				main.insert(main.begin() + static_cast<long>(n_start + 1), MainPair(static_cast<long>(pend.at((idx * elmntSize) + elmntSize - 1 - i)), 0));
			}
		}
		else {
			for (size_t i = 0; i < elmntSize; i++) {
				main.insert(main.begin() + static_cast<long>(n_start + 1 - elmntSize), MainPair(static_cast<long>(pend.at((idx * elmntSize) + elmntSize - 1 - i)), 0));
			}
		}
		return ;
	}
	const size_t mid = start + ((end - start) / 2);
	comparisonCount++;
	// std::cout << "(((((((((mid is " << mid << ")))))))))" << std::endl;
	if (num <= main.at(mid > 0 ? (mid * elmntSize) - (elmntSize > 1): elmntSize - (elmntSize > 1)).first) { // TODO 2 comparisons
		insert(main, pend, start, mid == 0 ? 0 : mid - 1, idx, elmntSize);
	}
	else {
		insert(main, pend, mid + 1, end, idx, elmntSize);
	}
}

static void	binaryInsert(std::vector<MainPair>& main,
const std::vector<long>& pend,
size_t idx,
size_t elmntSize) {
	size_t	end = 0;

	while (end < main.size() && idx != main.at(end).second) {
		end++;
	}
	end -= elmntSize;
	end /= elmntSize;
	// std::cout << "========> end of binary search is end: " << end << " and idx - 2: " << idx - 2 << std::endl; 

	insert(main, pend, 0, end, idx - 2, elmntSize);
}

static void	insertToMain(std::vector<MainPair>& main,
const std::vector<long>& pend,
size_t elmntSize) {
	size_t				idx = 0;
	const size_t		pendElmntsCount = pend.size() / elmntSize;
	std::vector<size_t>	jacobSeq = makeJacobSeq(pendElmntsCount);
	size_t				lastInsertIdx = 3;

	for (size_t i = 0; i < pendElmntsCount; i++) {
		idx = jacobSeq.at(i);
		if (idx - 2 >= pendElmntsCount) {
			for (idx = pendElmntsCount + 1; idx > lastInsertIdx; idx--) {
				binaryInsert(main, pend, idx, elmntSize);
				// std::cout << std::endl << "labels after special insertion: ";
				// for (size_t zz = 0; zz < main.size(); zz++) {
				// 	std::cout << main.at(zz).second << " ";
				// }
				// std::cout << std::endl;
			}
			break ;
		}
		lastInsertIdx = std::max(idx, lastInsertIdx);
		binaryInsert(main, pend, idx, elmntSize);
		// std::cout << std::endl << "labels after normal insertion: ";
		// for (size_t zz = 0; zz < main.size(); zz++) {
		// 	std::cout << main.at(zz).second << " ";
		// }
		// std::cout << std::endl;
	}
}

void	PmergeMe::mergeRec(std::vector<long>& vec, size_t level) {
	if (ye_pow(2, level) > vec.size()) {
		return ;
	}
	const size_t	elmntSize = ye_pow(2, level - 1);
	size_t			i = elmntSize - 1;		// 0 1 3 7
	const size_t	step = elmntSize * 2;	// 2 4 8 16

	// std::cout << std::endl << "start of rec level " << level << " sequence is: " << std::endl; PmergeMe::printVec(vec, level);
	while (i < vec.size()) {
		if (i + (step / 2) >= vec.size()) {
			break ;
		}
		// std::cout << "pointing at " << vec.at(i) << " and next is " << vec.at(i + (step / 2)) << std::endl;
		comparisonCount++;
		// std::cout << "comparing " << vec.at(i) << " With " << vec.at(i + (step / 2));
		if (vec.at(i) > vec.at(i + (step / 2))) {
			// std::cout << " and swapping them";
			// tmp = vec.at(i);
			// vec.at(i) = vec.at(i + (step / 2));
			// vec.at(i + (step / 2)) = tmp;
			groupSwap(vec, i, elmntSize);
		}
		// std::cout << std::endl;
		i += step;
	}
	// std::cout << "and total comparisons became: " << comparisonCount << std::endl << "===============================" << std::endl;
	mergeRec(vec, level + 1);

	std::vector<MainPair>	main;
	std::vector<long>		pend;
	std::vector<long>		remainder;
	makeSubVecs(vec, main, pend, remainder, elmntSize);
	// std::cout << std::endl;
	// // std::cout << "end of rec level " << level << " ------ elmtSize is: " << elmntSize << std::endl;
	if (pend.empty()) {
		// std::cout << "end of rec level " << level << " sequence became: " << std::endl << "parnt is: "; PmergeMe::printVec(vec, level);
		// std::cout << "main  is: "; PmergeMe::printPairVec(main, level);
		// std::cout << std::endl << "labels: ";
		// for (size_t zz = 0; zz < main.size(); zz++) {
		// 	std::cout << main.at(zz).second << " ";
		// }
		// std::cout << std::endl;
		// std::cout << "pend  is: "; PmergeMe::printVec(pend, level);
		// std::cout << "rmndr is: "; PmergeMe::printVec(remainder, level);
		// std::cout << std::endl;
		return ;
	}
	// std::cout << "end of rec level " << level << " sequence became: " << std::endl << "parnt is: "; PmergeMe::printVec(vec, level);
	// std::cout << "main  is: "; PmergeMe::printPairVec(main, level);
	// std::cout << std::endl << "labels: ";
	// for (size_t zz = 0; zz < main.size(); zz++) {
	// 	std::cout << main.at(zz).second << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "pend  is: "; PmergeMe::printVec(pend, level);
	// std::cout << "rmndr is: "; PmergeMe::printVec(remainder, level);
	// std::cout << std::endl;
	insertToMain(main, pend, elmntSize);
	// std::cout << "rec lvl " << level << ", after insertToMain() main  is: " << std::endl; PmergeMe::printPairVec(main, level);
	// std::cout << std::endl;
	// std::cout << std::endl << "rec lvl " << level << ", after insertToMain() parnt is: " << std::endl; PmergeMe::printVec(vec, level);
	for (size_t idx = 0; idx < main.size(); idx++) {
		vec.at(idx) = main.at(idx).first;
	}
	// std::cout << "rec lvl " << level << ", after adjusting parnt is: " << std::endl; PmergeMe::printVec(vec, level);
	// std::cout << std::endl;
}

// static std::vector<long>	insertionSequence(int size) {
// 	std::vector<long>	vec;
// 	vec.reserve(size + 2);
// 	vec.push_back(0);
// 	vec.push_back(1);
// 	for (int i = 2; i < size + 2; i++) {
// 		vec.push_back(vec.at(i - 1) + (2 * vec.at(i - 2)));
// 	}
// 	return vec;
// }

static int	getOptimalComparisons(int count) {
    int sum = 0;
    for (int k = 1; k <= count; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

int			PmergeMe::sort(const size_t argc, const char** argv) {
	Vec	vec;

	vec.reserve(argc - 1);
	for (size_t i = 1; i < argc; i++) {
		if (!validPosNum(argv[i])) {
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
			return 1;
		}
		vec.push_back(std::atol(argv[i]));
	}
	mergeRec(vec, 1);
	if (DEBUG) {
		std::cout << "RES: " << std::endl;
		printVec(vec, 1);
	}
	for (size_t i = 1; i < vec.size(); i++) {
		if (vec.at(i) < vec.at(i - 1)) {
			std::cerr << "WARRRRRNINGGGGGGG, NOT SORTED AT INDEX (" << i - 1
					<< ") and (" << i << ") NUMBER: " << vec.at(i) << std::endl;
		}
	}
	if (DEBUG) {
		std::cout << "comparisons: " << comparisonCount << std::endl;
		std::cout << "optimal comparisons: " << getOptimalComparisons(static_cast<int>(vec.size())) << std::endl;
	}
	return 0;
}
