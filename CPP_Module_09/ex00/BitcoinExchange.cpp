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
#include <functional>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	(void)obj;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& obj) {
	(void)obj;
	return *this;
}

// static bool	insertDateValuePair(const std::stringbuf* date, const std::stringbuf* value, std::map<t_date, long, t_less_date> dataMap) {
// 	// std::cout << "date is: " << date->str() << std::endl;
// 	char	*str_end = NULL;
// 	errno = 0;
// 	const long year = std::strtol(date->str().c_str(), &str_end, 10);
// 	if (errno == ERANGE) {
// 		std::cerr << "Year " << date->str() << " overflowed, come back from the future, old man!" << std::endl;
// 		return false;
// 	}
// 	if (str_end == date->str().c_str()) {
// 		std::cerr << "Empty year or unexpected form" << std::endl;
// 		return false;
// 	}
// 	if (year < 0) {
// 		std::cerr << "Negative year? No, sir!" << std::endl;
// 		return false;
// 	}

// 	str_end = NULL;
// 	errno = 0;
// 	const long value = std::strtol(date->str().c_str(), &str_end, 10);
// 	if (errno == ERANGE) {
// 		std::cerr << "Year " << date->str() << " overflowed, come back from the future, old man!" << std::endl;
// 		return false;
// 	}
// 	if (str_end == date->str().c_str()) {
// 		std::cerr << "Empty value or unexpected form" << std::endl;
// 		return false;
// 	}
// 	if (value < 0) {
// 		std::cerr << "Negative value? No, sir!" << std::endl;
// 		return false;
// 	}
// 	// data_map.insert(std::pair<long, long>(year))
// 	// return true;
// }

bool	f_less_date::operator()(t_date& d1, t_date& d2) const {
	if (d1.year > d2.year) {
		return false;
	}
	if (d1.year < d2.year) {
		return true;
	}
	if (d1.month > d2.month) {
		return false;
	}
	if (d1.month < d2.month) {
		return true;
	}
	if (d1.day > d2.day) {
		return false;
	}
	if (d1.day < d2.day) {
		return true;
	}
	return false;
}

int	BitcoinExchange::exchange(std::ifstream& data, std::ifstream& input) {
	std::stringbuf						line;
	std::stringbuf						date;
	std::stringbuf						value;
	t_date								curDate;
	std::map<t_date, long, f_less_date>	dataMap;

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
		curDate.year = std::atoi(date.str().c_str());
		curDate.month = std::atoi(date.str().c_str() + date.str().find('-') + 1);
		curDate.day = std::atoi(date.str().c_str() + date.str().rfind('-') + 1);
		if (data.fail()) {
			std::cerr << "Invalid data.csv format" << std::endl;
			return 1;
		}
		dataMap.insert(std::pair<t_date, long>(curDate, std::atoi(value.str().c_str())));
	}
	// std::cout << line.str() << std::endl;
	for (std::map<t_date, long, f_less_date>::iterator it = dataMap.begin(); it != dataMap.end(); it++) {
		std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << ": " << it->second << std::endl;
	}
	(void)input;
	return 0;
}
