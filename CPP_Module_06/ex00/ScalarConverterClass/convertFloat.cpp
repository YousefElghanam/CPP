#include <string>
#include <iostream>
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <cctype>
#include <climits>

void	convertFloat(const std::string& input) {
	const float	num = std::strtof(input.c_str(), NULL);
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
			std::cout << "\'"  << static_cast<char>(num) << "\'"  << std::endl;
		}
		else {
			std::cout << "Non displayable" << std::endl;
		}
	}

	if (input == "+inff" || input == "-inff" || input == "nanf"
		|| input == "+inf" || input == "-inf" || input == "nan"
		|| static_cast<double>(num) > static_cast<double>(INT_MAX) || static_cast<double>(num) < static_cast<double>(INT_MIN)) {
		std::cout << "int: impossible" << std::endl;
	}
	else {
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	}

	if (input == "+inff" || input == "-inff" || input == "nanf") {
		std::cout << "float: " << input << std::endl;
	}
	else {
		std::cout.setf(std::ios::fixed);
		std::cout << "float: " << num << "f" << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}

	if (input == "+inff" || input == "-inff" || input == "nanf") {
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
	}
	else {
		std::cout.setf(std::ios::fixed);
		std::cout << "double: " << static_cast<double>(num) << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}
