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
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "DEBUG MESSAGE" << std::endl;
}

void		Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "INFO MESSAGE" << std::endl;
}

void		Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "WARNING MESSAGE" << std::endl;
}

void		Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "ERROR MESSAGE" << std::endl;
}

/* HEHE >:) */
void		Harl::unknown(void) {
	std::cout << "unknown" << std::endl;
	// std::cout << "terminate called after throwing an instance of 'std::logic_error'" << std::endl;
	// std::cout << "  what():  basic_string: construction from null is not valid" << std::endl;
	// std::cout << "Aborted (core dumped)" << std::endl;
}

/**
 * Requires a valid std::string, NULL is undefined behaviour
 */
void		Harl::complain(std::string level) {
	int	levelIdx = -1;
	while (++levelIdx < 4 && this->levels[levelIdx] != level)
		;
	switch (levelIdx) {
		case 0:
			(this->*fnArr[0])(); /* fall through */
		case 1:
			(this->*fnArr[1])(); /* fall through */
		case 2:
			(this->*fnArr[2])(); /* fall through */
		case 3:
			(this->*fnArr[3])(); break;
		default: // could use (case 4) here, I implemented it, but eval says i need default idk.
			(this->*fnArr[4])();
	}
	/* Same solution but with a while loop */
	// while (levelIdx++  < 4)
	// 	(this->*fnArr[levelIdx - 1])();
}
