#include "BitcoinExchange.hpp"

#include <cerrno>
#include <cstdlib>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>

#include <algorithm>
#include <map>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	(void)obj;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& obj) {
	(void)obj;
	return *this;
}

static bool	insertDateValuePair(const std::stringbuf* date, const std::stringbuf* value, std::map<long, long>& data_map) {
	// std::cout << "date is: " << date->str() << std::endl;
	char	*str_end = NULL;
	errno = 0;
	const long year = std::strtol(date->str().c_str(), &str_end, 10);
	if (errno == ERANGE) {
		std::cerr << "Year " << date->str() << " overflowed, come back from the future, old man!" << std::endl;
		return false;
	}
	if (str_end == date->str().c_str()) {
		std::cerr << "Empty year or unexpected form" << std::endl;
		return false;
	}
	if (year < 0) {
		std::cerr << "Negative year? No, sir!" << std::endl;
		return false;
	}

	str_end = NULL;
	errno = 0;
	const long value = std::strtol(date->str().c_str(), &str_end, 10);
	if (errno == ERANGE) {
		std::cerr << "Year " << date->str() << " overflowed, come back from the future, old man!" << std::endl;
		return false;
	}
	if (str_end == date->str().c_str()) {
		std::cerr << "Empty value or unexpected form" << std::endl;
		return false;
	}
	if (value < 0) {
		std::cerr << "Negative value? No, sir!" << std::endl;
		return false;
	}
	data_map.insert(std::pair<long, long>(year))
	return true;
}

int	BitcoinExchange::exchange(std::ifstream& data, std::ifstream& input) {
	std::stringbuf			line;
	std::stringbuf			date;
	std::stringbuf			value;
	std::map<long, long>	data_map;

	data.get(line);
	if (data.fail()) {
		std::cerr << "Unexpected error while reading data.csv" << std::endl;
		return 1;
	}
	if (line.str() != "date,exchange_rate") {
		std::cerr << "Invalid data.csv" << std::endl;
		return 1;
	}
	while (true) {
		data.get(date, ',');
		data.get(value, '\n');
		if (data.fail() || !insertDateValuePair(&date, &value, data_map)) {
			std::cerr << "Invalid data.csv format" << std::endl;
			return 1;
		}
		// line.(date, ',');
	}
	// std::cout << line.str() << std::endl;
	(void)input;
	return 0;
}

