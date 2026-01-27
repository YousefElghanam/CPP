#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// static void	test_constructor() {
// 	const Bureaucrat	beroBero("Berooooooo", 151);
// }

// static void	test_increment() {
// 	Bureaucrat	bero("Jesse", 3);
// 	std::cout << bero << std::endl;
// 	bero++;
// 	std::cout << bero << std::endl;
// 	bero++;
// 	std::cout << bero << std::endl;
// }

// static void	test_decrement() {
// 	Bureaucrat	bero("Jesse", 149);
// 	std::cout << bero << std::endl;
// 	bero--;
// 	std::cout << bero << std::endl;
// 	bero--;
// 	std::cout << bero << std::endl;
// }

static void	test_form() {
	Form	bero("formal_form", 10, 20);
	std::cout << bero << std::endl;
}

int	main(void) {
	try {
		// test_constructor();
		// test_increment();
		// test_decrement();
		test_form();
	}
	catch (std::exception &e) {
		std::cout << "RUNTIME " << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "ERROR: Unhandled exception caught" << std::endl;
	}
	return 0;
}
