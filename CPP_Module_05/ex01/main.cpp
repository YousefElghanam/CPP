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
	Form	formoo("formal_form", 10, 20);
	std::cout << formoo << std::endl;
}

static void test_1(void) {
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
}

static void test_2(void) {
	Bureaucrat	bero1("bero1", 25);
	Bureaucrat	bero2("bero2", 5);
	Form		form1("form1", 30, 30);
	Form		form2("form2", 15, 15);

	std::cout << "bero1 attempts to sign form1: =======================" << std::endl;
	try {
		bero1.signForm(form1);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "bero1 attempts to sign form2: =======================" << std::endl;
	try {
		bero1.signForm(form2);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "bero2 attempts to sign form1: =======================" << std::endl;
	try {
		bero2.signForm(form1);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "bero2 attempts to sign form2: =======================" << std::endl;
	try {
		bero2.signForm(form2);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}

int	main(void) {
	test_1();
	std::cout << "========================================================" << std::endl;
	test_2();
	return 0;
}
