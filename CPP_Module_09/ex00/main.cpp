#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Takes only exactly two arguments" << std::endl;
		return 1;
	}
	std::ifstream	data("data.csv");
	if (data.fail()) {
		std::cerr << "Couldn't open data.csv" << std::endl;
		return 1;
	}
	std::ifstream	input(argv[1]);
	if (input.fail()) {
		std::cerr << "Couldn't open input file" << std::endl;
		return 1;
	}
	return BitcoinExchange::exchange(data, input);
}
