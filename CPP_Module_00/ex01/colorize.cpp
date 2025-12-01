#include "phonebook.hpp"
#include <iostream>

void	black(std::string str, short endl) {
	std::cout << BLACK << str << RESET;
	if (endl)
		std::cout << std::endl;
}

void	red(std::string str, short endl) {
	std::cout << RED << str << RESET;
	if (endl)
		std::cout << std::endl;
}

void	green(std::string str, short endl) {
	std::cout << GREEN << str << RESET;
	if (endl)
		std::cout << std::endl;
}

void	yellow(std::string str, short endl) {
	std::cout << YELLOW << str << RESET;
	if (endl)
		std::cout << std::endl;
}

void	blue(std::string str, short endl) {
	std::cout << BLUE << str << RESET;
	if (endl)
		std::cout << std::endl;
}

void	magenta(std::string str, short endl) {
	std::cout << MAGENTA << str << RESET;
	if (endl)
		std::cout << std::endl;
}

void	cyan(std::string str, short endl) {
	std::cout << CYAN << str << RESET;
	if (endl)
		std::cout << std::endl;
}

void	white(std::string str, short endl) {
	std::cout << WHITE << str << RESET;
	if (endl)
		std::cout << std::endl;
}
