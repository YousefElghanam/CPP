#include <iostream>
#include <string>
#include <cctype>

void	convertChar(const std::string& input) {
	std::cout << "char: ";
	if (std::isprint(input[0]) != 0) {
		std::cout << "\'"  << input[0] << "\'"  << std::endl;
	}
	else {
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;

	std::cout.setf(std::ios::fixed);
	std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);

	std::cout.setf(std::ios::fixed);
	std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
	std::cout.unsetf(std::ios::fixed);
}
