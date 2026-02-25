#include "PmergeMe.hpp"
#include <iostream>

#include <cstddef>

int	main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Sorted 0 numbers successfully ^_^" << std::endl;
		return 0;
	}
	if (argc == 2) {
		std::cout << "Sorted 1 number successfully ^_^" << std::endl;
		return 0;
	}
	return PmergeMe::sort(static_cast<size_t>(argc), const_cast<const char**>(argv));
}
