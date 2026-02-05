#include <string>
#include <iostream>
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <cctype>
#include <climits>

void	convertDouble(const std::string& input) {
	const double	num = std::strtod(input.c_str(), NULL);
	errno = 0;
	if (errno == ERANGE) {
		std::cout << "char: Conversion value is out of range" << std::endl;
		std::cout << "int: Conversion value is out of range" << std::endl;
		std::cout << "float: Conversion value is out of range" << std::endl;
		std::cout << "double: Conversion value is out of range" << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (num > 127 || num < 0
		|| input == "+inff" || input == "-inff" || input == "nanf"
		|| input == "+inf" || input == "-inf" || input == "nan") {
		std::cout << "impossible" << std::endl;
	}
	else {
		if (std::isprint(num) != 0) {
			std::cout << "\'" << static_cast<char>(num) << "\'" << std::endl;
		}
		else {
			std::cout << "Non displayable" << std::endl;
		}
	}

	if (input == "+inff" || input == "-inff" || input == "nanf"
		|| input == "+inf" || input == "-inf" || input == "nan"
		|| num > static_cast<double>(INT_MAX) || num < static_cast<double>(INT_MIN)) {
		std::cout << "int: impossible" << std::endl;
	}
	else {
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	}

	if (input == "+inf" || input == "-inf" || input == "nan") {
		std::cout << "float: " << input + "f" << std::endl;
	}
	else {
		std::cout.setf(std::ios::fixed);
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}

	if (input == "+inf" || input == "-inf" || input == "nan") {
		std::cout << "double: " << input << std::endl;
	}
	else {
		std::cout.setf(std::ios::fixed);
		std::cout << "double: " << num << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}
