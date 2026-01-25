#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	beroBero("Berooooooo", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "exception thrown: (" << e.what() << ")" << std::endl;
	}
	return 0;
}
