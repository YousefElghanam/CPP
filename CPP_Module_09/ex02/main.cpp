#include "PmergeMe.hpp"
#include <iostream>

#include <cstddef>
#include <ctime>
#include <cstdlib>

static long getTime() {
	struct timespec	ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec * 1000000000) + ts.tv_nsec;
}

int	main(int argc, char** argv) {
	std::srand(std::time(0));
	if (argc == 1) {
		std::cout << "After a very long time, finally managed to sort 0 numbers successfully ^_^" << std::endl;
		return 0;
	}
	if (argc == 2) {
		std::cout << "After a very long time, finally managed to sort 1 numbers successfully ^_^" << std::endl;
		return 0;
	}
	long	vectorProcessTime = 0;
	long	dequeProcessTime = 0;
	long	start = getTime();
	if (PmergeMe::sort(static_cast<size_t>(argc), const_cast<const char**>(argv)) != 0) {
		return 1;
	}
	vectorProcessTime = getTime() - start;
	start = getTime();
	if (PmergeMe::sortButDeque(static_cast<size_t>(argc), const_cast<const char**>(argv)) != 0) {
		return 1;
	}
	dequeProcessTime = getTime() - start;
	std::cout << std::fixed;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << static_cast<double>(vectorProcessTime) / 1000 << "us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << static_cast<double>(dequeProcessTime) / 1000 << "us" << std::endl;
	return 0;
}
