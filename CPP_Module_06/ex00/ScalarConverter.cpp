#include <cmath>
#include <climits>
#include <cerrno>
#include <cctype>
#include <cstdlib>
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

static void	convertInt(const std::string& input) {
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

static void	convertFloat(const std::string& input) {
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
	if (num > 127 || num < 0 || input == "inff" || input == "-inff" || input == "nanf") {
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

	if (input == "inff" || input == "-inff" || input == "nanf") {
		std::cout << "int: impossible" << std::endl;
	}
	else {
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	}

	if (input == "inff" || input == "-inff" || input == "nanf") {
		std::cout << "float: " << input << std::endl;
	}
	else {
		std::cout.setf(std::ios::fixed);
		std::cout << "float: " << num << "f" << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}

	if (input == "inff" || input == "-inff" || input == "nanf") {
		std::cout << input.substr(0, input.length() - 1);
	}
	else {
		std::cout.setf(std::ios::fixed);
		std::cout << "double: " << static_cast<double>(num) << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}

static void	convertDouble(const std::string& input) {
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
	if (num > 127 || num < 0) {
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

	if (input == "inf" || input == "-inf" || input == "nan") {
		std::cout << "int: impossible" << std::endl;
	}
	else {
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	}

	if (input == "inf" || input == "-inf" || input == "nan") {
		std::cout << "float: " << input + "f" << std::endl;
	}
	else {
		std::cout.setf(std::ios::fixed);
		std::cout << "float: " << num << "f" << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}

	if (input == "inf" || input == "-inf" || input == "nan") {
		std::cout << input << std::endl;
	}
	else {
		std::cout.setf(std::ios::fixed);
		std::cout << "double: " << static_cast<double>(num) << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}

void	ScalarConverter::convert(const std::string& input) {
	const e_type type = getType(input);

	if (type == EMPTY) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else if (type == UNKOWN) {
		std::cout << "char: unknown input type" << std::endl;
		std::cout << "int: unknown input type" << std::endl;
		std::cout << "float: unknown input type" << std::endl;
		std::cout << "double: unknown input type" << std::endl;
	}
	else if (type == CHAR) {
		convertChar(input);
	}
	else if (type == INT) {
		convertInt(input);
	}
	else if (type == FLOAT) {
		convertFloat(input);
	}
	else if (type == DOUBLE) {
		convertDouble(input);
	}
}
