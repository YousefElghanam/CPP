#include "main.hpp"
#include <iostream>
#include <fstream>

void	open_file(const char *fileName) {
	std::ifstream	file(fileName, std::ifstream::in);
	char	line[5];
	file.getline(line, 5);
	std::cout << line << std::endl;
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Needs 3 arguments" << std::endl;
		return 1;
	}
	std::string		fileName(argv[1]);
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	if (fileName.empty()) {
		std::cerr << "Filename can not be empty" << std::endl;
		return 1;
	}
	if (s1.empty()) {
		std::cerr << "This argument can not be empty" << std::endl;
		return 1;
	}
	open_file(argv[1]);
	return 0;
}