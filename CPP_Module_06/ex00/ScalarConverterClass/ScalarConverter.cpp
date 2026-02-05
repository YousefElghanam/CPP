#include <cmath>
#include <climits>
#include <cerrno>
#include <cctype>
#include <cstdlib>
#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

enum e_type {
	EMPTY,
	UNKOWN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

e_type	getType(const std::string& input);
void	convertChar(const std::string& input);
void	convertInt(const std::string& input);
void	convertFloat(const std::string& input);
void	convertDouble(const std::string& input);

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj) {(void)obj;}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& obj) {
	(void)obj;
	return *this;
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
