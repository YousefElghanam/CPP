#include <cstddef>
#include <cctype>
#include <string>

enum e_type {
	EMPTY,
	UNKOWN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

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
	while (it != copy.end()) {
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

e_type	getType(const std::string& input) {
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
