#include <string>
#include <iostream>
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <cctype>

void	convertInt(const std::string& input) {
	errno = 0;
	const long	num = std::strtol(input.c_str(), NULL, 10);
	if (errno == ERANGE) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	std::cout << "char: ";
	if (num > 127 || num < 0) {
		std::cout << "impossible" << std::endl;
	}
	else {
		if (std::isprint(num) != 0) {
			std::cout << "\'"  << static_cast<char>(num) << "\'"  << std::endl;
		}
		else {
			std::cout << "Non displayable" << std::endl;
		}
	}

	std::cout << "int: " << num << std::endl;

	std::cout.setf(std::ios::fixed);
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);


	std::cout.setf(std::ios::fixed);
	std::cout << "double: " << static_cast<double>(num) << std::endl;
	std::cout.unsetf(std::ios::fixed);
}
