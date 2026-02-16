#include "BitcoinExchange.hpp"

#include <cctype>
#include <cerrno>
#include <cstdlib>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <exception>

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

const char*			BitcoinExchange::InvalidDataFileException::what(void) const throw() {
	return "Invalid data.csv";
}

const char*			BitcoinExchange::InvalidInputFileException::what(void) const throw() {
	return "Input data.csv";
}

const char*			BitcoinExchange::InvalidInputFormatException::what(void) const throw() {
	return "Input data.csv";
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

bool	f_less_date::operator()(const t_date& d1, const t_date& d2) const {
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

static void	parseData(std::ifstream& data, std::map<t_date, double, f_less_date>& dataMap) {
	std::string	buf;
	t_date		curDate;

	std::getline(data, buf);
	if (buf != "date,exchange_rate") {
		throw BitcoinExchange::InvalidDataFileException();
	}
	while (true) {
		std::getline(data, buf, ',');
		if (data.eof()) {
			break ;
		}
		curDate.year = std::atoi(buf.c_str());
		curDate.month = std::atoi(buf.substr(buf.find('-') + 1).c_str());
		curDate.day = std::atoi(buf.substr(buf.rfind('-') + 1).c_str());
		std::getline(data, buf, '\n');
		dataMap.insert(std::pair<t_date, double>(curDate, std::strtod(buf.c_str(), NULL)));
	}
	// for (std::map<t_date, double, f_less_date>::iterator it = dataMap.begin(); it != dataMap.end(); it++) {
	// 	std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << ": " << it->second << std::endl;
	// }
}

static bool	validDateFormat(std::string dateStr) {
	char	c;
	size_t	found;
	std::string	yearStr;
	long	year;

	found = dateStr.find('-');
	if (found == std::string::npos || found > 4) {
		throw BitcoinExchange::InvalidInputFormatException();
	}
	yearStr = dateStr.substr(0, found);
	std::cout << "yearStr is: " << yearStr << std::endl;
	year = std::strtol(yearStr.c_str(), NULL, 10);
	for (std::string::iterator it = dateStr.begin(); it != dateStr.end(); it++) {
		c = *it;
		// if (!std::isdigit(c) && c != '-')
	}
	return true;
}

static void	validateInputLine(std::string buf) {
	// t_date		curDate;
	long		year;
	long		month;
	long		day;
	std::string	dateStr;
	size_t		found;

	found = buf.find('|');
	if (found == std::string::npos) {
		throw BitcoinExchange::InvalidInputFormatException();
	}
	if (!validDateFormat(buf.substr(0, found))) {
		throw BitcoinExchange::InvalidInputFormatException();
	}
	year = std::strtol(buf.c_str(), NULL, 10);
	month = std::strtol(buf.c_str() + buf.find('-') + 1, NULL, 10);
	day = std::strtol(buf.c_str() + buf.rfind('-') + 1, NULL, 10);
	// std::string	year = buf.substr(0, )
}

static void	parseInput(std::ifstream& input, std::map<t_date, double, f_less_date>& dataMap) {
	std::string	buf;
	// t_date		curDate;

	(void)dataMap;
	std::getline(input, buf);
	if (input.fail()) {
		throw BitcoinExchange::InvalidInputFileException();
	}
	if (input.eof()) {
		return ;
	}
	if (buf != "date | value") {
		std::cerr << "Invalid header in input file" << std::endl;
		throw BitcoinExchange::InvalidInputFileException();
	}
	while (std::getline(input, buf)) {
		if (input.fail()) {
			throw BitcoinExchange::InvalidInputFileException();
		}
		if (input.eof()) {
			return ;
		}
		try {
			validateInputLine(buf);
			// parseInputLine(buf, dataMap);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

int	BitcoinExchange::exchange(std::ifstream& data, std::ifstream& input) {
	std::map<t_date, double, f_less_date>	dataMap;

	try {
		parseData(data, dataMap);
		parseInput(input, dataMap);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
