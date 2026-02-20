#include "PmergeMe.hpp"
#include <iostream>
#include <fstream>

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Takes only exactly two arguments" << std::endl;
		return 1;
	}
	return RPN::calculate(argv[1]);
}
