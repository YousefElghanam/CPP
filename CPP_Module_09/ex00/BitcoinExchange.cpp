#include "BitcoinExchange.hpp"

#include <cctype>
#include <cerrno>
#include <cstdlib>

#include <string>
#include <fstream>
#include <iostream>
#include <utility>
#include <exception>

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

const char*			BitcoinExchange::InvalidDataFileException::what(void) const throw() {
	return "Invalid data.csv";
}

const char*			BitcoinExchange::InvalidInputFileException::what(void) const throw() {
	return "Invalid input file";
}

const char*			BitcoinExchange::BadInputException::what(void) const throw() {
	return "Error: bad input => ";
}

const char*			BitcoinExchange::NegativeValueException::what(void) const throw() {
	return "Error: not a positive number.";
}

const char*			BitcoinExchange::ValueTooBigException::what(void) const throw() {
	return "Error: too large a number.";
}

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
	t_date		curDate = {0, 0, 0};

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
	if (curDate.year == 0 || curDate.month == 0 || curDate.day == 0) {
		throw BitcoinExchange::InvalidDataFileException();
	}
}

static void	parseYear(size_t* i, size_t* numStart, t_date* date, std::string& buf) {
	while (*i < buf.length()) {
		if (std::isdigit(buf.at(*i)) != 0) {
			(*i)++;
			continue;
		}
		if (buf.at(*i) != '-' || *i == *numStart || *i > 4) {
			throw BitcoinExchange::BadInputException();
		}
		date->year = std::strtol(buf.substr(*numStart, *i).c_str(), NULL, 10);
		(*i)++;
		break ;
		}
		*numStart = *i;
	}

static void	parseMonth(size_t* i, size_t* numStart, t_date* date, std::string& buf) {
	while (*i < buf.length()) {
		if (std::isdigit(buf.at(*i)) == 0) {
			if (buf.at(*i) != '-' || *i == *numStart || *i > 2 + *numStart) {
				throw BitcoinExchange::BadInputException();
			}
			date->month = std::strtol(buf.substr(*numStart, *i).c_str(), NULL, 10);
			(*i)++;
			break ;
		}
		(*i)++;
	}
	*numStart = *i;
}

static void	parseDay(size_t* i, const size_t* numStart, t_date* date, std::string& buf) {
	while (*i < buf.length()) {
		if (std::isdigit(buf.at(*i)) == 0) {
			if (std::isspace(buf.at(*i)) == 0 || *i == *numStart || *i > 2 + *numStart) {
				throw BitcoinExchange::BadInputException();
			}
			date->day = std::strtol(buf.substr(*numStart, *i).c_str(), NULL, 10);
			break ;
		}
		(*i)++;
	}
}

static void	parsePipe(size_t* i, std::string& buf) {
	try {
		while (true) {
			if (std::isspace(buf.at(*i)) != 0) {
				(*i)++;
			}
			else if (buf.at(*i) == '|') {
				(*i)++;
				break ;
			}
			else {
				throw BitcoinExchange::BadInputException();
			}
		}
		if (std::isspace(buf.at(*i)) == 0) {
			throw BitcoinExchange::BadInputException();
		}
		while (true) {
			if (std::isspace(buf.at(*i)) != 0) {
				(*i)++;
			}
			else {
				break ;
			}
		}
	}
	catch (...) {
		throw BitcoinExchange::BadInputException();
	}
}

static void	parseValue(size_t* i, double* value, std::string& buf) {
	char*	str_end;

	errno = 0;
	*value = std::strtod(buf.substr(*i).c_str(), &str_end);
	if (*value == 0 && str_end == buf.substr(*i).c_str()) { // TODO HANDLE INVALID VALUE FORMAT HERE
		throw BitcoinExchange::BadInputException();
	}
	if (errno == ERANGE) {
		throw BitcoinExchange::BadInputException();
	}
	errno = 0;
	if (*value < 0) {
		throw BitcoinExchange::NegativeValueException();
	}
	if (*value > 1000) {
		throw BitcoinExchange::ValueTooBigException();
	}
}

static void	printDate(const t_date date, std::ostream& stream) {
	stream << date.year << "-" << date.month << "-" << date.day;
}

static bool	thirtyMonth(long month) {
	return (month == 4 || month == 6 || month == 9 || month == 11);
}

static bool february(long month) {
	return (month == 2);
}

static bool	leapYear(long year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			return (year % 400 == 0);
		}
		return true;
	}
	return false;
}

static void	validateDate(const t_date date) {
	if (date.year == 0 || date.month == 0 || date.day == 0) {
		throw BitcoinExchange::BadInputException();
	}
	if (date.year < 1
		|| date.month < 1 || date.month > 12
		|| date.day < 1 || date.day > 31) {
		throw BitcoinExchange::BadInputException();
	}
	if (thirtyMonth(date.month) && date.day > 30) {
		throw BitcoinExchange::BadInputException();
	}
	if (february(date.month)
		&& (date.day > 29 || (!leapYear(date.year) && date.day > 28))) {
		throw BitcoinExchange::BadInputException();
	}
}

static void	parseInputLine(std::string& buf, std::map<t_date, double, f_less_date>& dataMap) {
	size_t											i;
	size_t											numStart;
	t_date											date = {0, 0, 0};
	double											value;
	const f_less_date								compare;
	std::map<t_date, double, f_less_date>::iterator	foundIt;
	bool											found = false;

	i = 0;
	numStart = 0;
	try {
		parseYear(&i, &numStart, &date, buf);
		parseMonth(&i, &numStart, &date, buf);
		parseDay(&i, &numStart, &date, buf);
		validateDate(date);
		parsePipe(&i, buf);
		parseValue(&i, &value, buf);
	}
	catch (BitcoinExchange::BadInputException& e) {
			std::cout << e.what() << buf << std::endl;
			return ;
	}
	for (std::map<t_date, double, f_less_date>::iterator it = dataMap.begin(); it != dataMap.end(); it++) {
		if (!compare(date, it->first)) {
			foundIt = it;
			found = true;
		}
	}
	if (found) {
		printDate(date, std::cout);
		std::cout << " => " << value << " = " << value * foundIt->second << std::endl;
	}
	else {
		printDate(date, std::cout);
		std::cout << " => No data avaliable at this date." << std::endl;
	}
}

static void	parseInput(std::ifstream& input, std::map<t_date, double, f_less_date>& dataMap) {
	std::string	lineBuf;

	std::getline(input, lineBuf);
	if (input.fail()) {
		throw BitcoinExchange::InvalidInputFileException();
	}
	if (input.eof()) {
		return ;
	}
	if (lineBuf != "date | value") {
		std::cerr << "Invalid header in input file" << std::endl;
		throw BitcoinExchange::InvalidInputFileException();
	}
	while (std::getline(input, lineBuf)) {
		if (input.fail()) {
			throw BitcoinExchange::InvalidInputFileException();
		}
		try {
			parseInputLine(lineBuf, dataMap);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		if (input.eof()) {
			return ;
		}
	}
}

int	BitcoinExchange::exchange(std::ifstream& data, std::ifstream& input) {
	std::map<t_date, double, f_less_date>	dataMap;

	try {
		parseData(data, dataMap);
	}
	catch (std::exception& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	try {
		parseInput(input, dataMap);
	}
	catch (std::exception& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	return 0;
}
