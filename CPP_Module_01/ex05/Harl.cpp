#include "Harl.hpp"

Harl::Harl(void) {
	this->fnArr[0] = &Harl::debug;
	this->fnArr[1] = &Harl::info;
	this->fnArr[2] = &Harl::warning;
	this->fnArr[3] = &Harl::error;
	this->fnArr[4] = &Harl::unknown;
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

void		Harl::unknown(void) {
	std::cout << "UNKOWN LEVEL" << std::endl;
}

/**
 * Requires a valid std::string, NULL is undefined behaviour
 */
void		Harl::complain(std::string level) {
	int	levelIdx = -1;
	while (++levelIdx < 4 && this->levels[levelIdx] != level)
		;
	(this->*fnArr[levelIdx])();
}
