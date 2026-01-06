#include "Harl.hpp"

Harl::Harl(void) {
	fnArr[0] = &Harl::debug;
	fnArr[1] = &Harl::info;
	fnArr[2] = &Harl::warning;
	fnArr[3] = &Harl::error;
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
}

Harl::~Harl(void) {}

void		Harl::debug(void) {
	std::cout << "DEBUG MESSAGE" << std::endl;
}


void		Harl::info(void) {
	std::cout << "INFO MESSAGE" << std::endl;
}


void		Harl::warning(void) {
	std::cout << "WARNING MESSAGE" << std::endl;
}


void		Harl::error(void) {
	std::cout << "ERROR MESSAGE" << std::endl;
}

void		Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (level == this->levels[i]) {
			(this->*fnArr[i])();
			return ;
		}
	}
	std::cout << "UNKOWN LEVEL" << std::endl;
}
