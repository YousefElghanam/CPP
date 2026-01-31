#include <cctype>
#include <string>
#include <iostream>
#include <cstddef>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj) {(void)obj;}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& obj) {
	(void)obj;
	return *this;
}

static bool	isInt(const std::string& input) {
	std::string				copy = input;
	std::string::iterator	it = copy.begin();
	size_t					count = 0;

	if (*it == '-' || *it == '+') {
		it++;
	}
	while (*it == '0') {
		it++;
		count++;
	}
	while (it != copy.end()) {
		if (std::isdigit(*it) == 0) {
			return false;
		}
		it++;
		count++;
	}
	return (count != 0);
}

static bool	isFloat(const std::string& input) {
	std::string				copy = input;
	std::string::iterator	it = copy.begin();
	size_t					dotCount = 0;

	if (input == "-inff" || input == "+inff" || input == "nanf") {
		return true;
	}
	if (*it == '-' || *it == '+') {
		it++;
	}
	while (*it == '0') {
		it++;
	}
	while (it != copy.end() - 1) {
		if (std::isdigit(*it) == 0 && *it != '.') {
			return false;
		}
		if (*it == '.') {
			dotCount++;
			if (dotCount > 1) {
				return false;
			}
		}
		it++;
	}
	return (*it == 'f');
}

static bool	isDouble(const std::string& input) {
	std::string				copy = input;
	std::string::iterator	it = copy.begin();
	size_t					dotCount = 0;

	if (input == "-inf" || input == "+inf" || input == "nan") {
		return true;
	}
	if (*it == '-' || *it == '+') {
		it++;
	}
	while (*it == '0') {
		it++;
	}
	while (it != copy.end() - 1) {
		if (std::isdigit(*it) == 0 && *it != '.') {
			return false;
		}
		if (*it == '.') {
			dotCount++;
			if (dotCount > 1) {
				return false;
			}
		}
		it++;
	}
	return (dotCount == 1);
}

static e_type	getType(const std::string& input) {
	const size_t	len = input.size();

	if (len == 0) {
		return EMPTY;
	}
	if (len == 1 && !isInt(input)) {
		return CHAR;
	}
	if (isInt(input)) {
		return INT;
	}
	if (isFloat(input)) {
		return FLOAT;
	}
	if (isDouble(input)) {
		return DOUBLE;
	}
	return UNKOWN;
}

static void	convertChar(const std::string& input) {
	std::cout << "char: ";
	if (std::isprint(input[0]) != 0) {
		std::cout << input[0] << std::endl;
	}
	else {
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;

	std::cout.setf(std::ios::fixed);
	std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);

	std::cout.setf(std::ios::showpoint);
	std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
	std::cout.unsetf(std::ios::showpoint);
}

static void	convertInt(const std::string& input) {
	std::cout << "char: ";
	if (input.)
}

void	ScalarConverter::convert(const std::string& input) {
	e_type type = getType(input);

	if (type == EMPTY) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (type == UNKOWN) {
		std::cout << "char: unknown input type" << std::endl;
		std::cout << "int: unknown input type" << std::endl;
		std::cout << "float: unknown input type" << std::endl;
		std::cout << "double: unknown input type" << std::endl;
		return ;
	}
	if (type == CHAR) {
		convertChar(input);
		return ;
	}
	if (type == INT) {
		convertInt(input);
		return ;
	}
	// if (type == FLOAT) {
	// 	convertFloat(input);
	// 	return ;
	// }
	// if (type == DOUBLE) {
	// 	convertDouble(input);
	// 	return ;
	// }
}
