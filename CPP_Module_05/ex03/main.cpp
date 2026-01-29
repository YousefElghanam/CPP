#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

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

// static void	test_form() {
// 	PresidentialPardonForm	formoo;
// 	std::cout << formoo << std::endl;
// }

// static void test_1(void) {
// 	try {
// 		// test_constructor();
// 		// test_increment();
// 		// test_decrement();
// 		test_form();
// 	}
// 	catch (std::exception &e) {
// 		std::cout << "RUNTIME " << e.what() << std::endl;
// 	}
// 	catch (...) {
// 		std::cout << "ERROR: Unhandled exception caught" << std::endl;
// 	}
// }

// static void test_2(void) {
// 	Bureaucrat	bero1("bero1", 25);
// 	Bureaucrat	bero2("bero2", 5);
// 	AForm*	form1 = new PresidentialPardonForm("THE MAIN TARGET");
// 	AForm*	form2 = new PresidentialPardonForm("THE SECONDARY TARGET");

// 	std::cout << "bero1 attempts to sign form1: =======================" << std::endl;
// 	try {
// 		bero1.signForm(*form1);
// 	}
// 	catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	std::cout << "bero1 attempts to sign form2: =======================" << std::endl;
// 	try {
// 		bero1.signForm(*form2);
// 	}
// 	catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	std::cout << "bero2 attempts to sign form1: =======================" << std::endl;
// 	try {
// 		bero2.signForm(*form1);
// 	}
// 	catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	std::cout << "bero2 attempts to sign form2: =======================" << std::endl;
// 	try {
// 		bero2.signForm(*form2);
// 	}
// 	catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	delete form1;
// 	delete form2;
// }

// static void	test_presidential(void) {
// 	Bureaucrat	bero1("bero1", 150);
// 	Bureaucrat	bero2("bero2", 5);
// 	AForm*	form1 = new PresidentialPardonForm("THE MAIN TARGET");
// 	AForm*	form2 = new PresidentialPardonForm("THE SECONDARY TARGET");
// 	std::cout << "========================================================" << std::endl;
// 	bero2.signForm(*form1);
// 	bero2.signForm(*form2);
// 	std::cout << "========================================================" << std::endl;
// 	bero1.executeForm(*form1);
// 	std::cout << "========================================================" << std::endl;
// 	bero2.executeForm(*form1);
// 	bero2.executeForm(*form2);
// 	std::cout << "========================================================" << std::endl;
// 	delete form1;
// 	delete form2;
// }

// static void	test_shrubbery(void) {
// 	Bureaucrat	bero1("bero1", 150);
// 	Bureaucrat	bero2("bero2", 5);
// 	AForm*	form1 = new ShrubberyCreationForm("THE MAIN TARGET");
// 	AForm*	form2 = new ShrubberyCreationForm("THE SECONDARY TARGET");
// 	std::cout << "========================================================" << std::endl;
// 	bero2.signForm(*form1);
// 	bero2.signForm(*form2);
// 	std::cout << "========================================================" << std::endl;
// 	bero1.executeForm(*form1);
// 	std::cout << "========================================================" << std::endl;
// 	bero2.executeForm(*form1);
// 	bero2.executeForm(*form2);
// 	std::cout << "========================================================" << std::endl;
// 	delete form1;
// 	delete form2;
// }

// static void	test_robotomy(void) {
// 	Bureaucrat	bero1("bero1", 150);
// 	Bureaucrat	bero2("bero2", 5);
// 	AForm*	form1 = new RobotomyRequestForm("THE MAIN TARGET");
// 	AForm*	form2 = new RobotomyRequestForm("THE SECONDARY TARGET");
// 	std::cout << "========================================================" << std::endl;
// 	bero2.signForm(*form1);
// 	bero2.signForm(*form2);
// 	std::cout << "========================================================" << std::endl;
// 	bero1.executeForm(*form1);
// 	std::cout << "========================================================" << std::endl;
// 	bero2.executeForm(*form1);
// 	bero2.executeForm(*form2);
// 	bero2.executeForm(*form2);
// 	bero2.executeForm(*form2);
// 	bero2.executeForm(*form2);
// 	bero2.executeForm(*form2);
// 	bero2.executeForm(*form2);
// 	bero2.executeForm(*form2);
// 	bero2.executeForm(*form2);
// 	bero2.executeForm(*form2);
// 	bero2.executeForm(*form2);
// 	bero2.executeForm(*form2);
// 	std::cout << "========================================================" << std::endl;
// 	delete form1;
// 	delete form2;
// }

static void test_intern(void) {
	Bureaucrat	president("MR. President", 1);
	Intern		newIntern;

	AForm*	newForm_0 = newIntern.makeForm("robotomy request", "THE_TARGET");
	if (newForm_0) {
		std::cout << newForm_0->getName() << std::endl;
		newForm_0->beSigned(president);
		newForm_0->execute(president);
	}
	delete newForm_0;
	std::cout << "========================================================" << std::endl;

	AForm*	newForm_1 = newIntern.makeForm("shrubbery creation", "THE_TARGET");
	if (newForm_1) {
		std::cout << newForm_1->getName() << std::endl;
		newForm_1->beSigned(president);
		newForm_1->execute(president);
	}
	delete newForm_1;
	std::cout << "========================================================" << std::endl;

	AForm*	newForm_2 = newIntern.makeForm("presidential pardon", "THE_TARGET");
	if (newForm_2) {
		std::cout << newForm_2->getName() << std::endl;
		newForm_2->beSigned(president);
		newForm_2->execute(president);
	}
	delete newForm_2;
	std::cout << "========================================================" << std::endl;

	AForm*	newForm_3 = newIntern.makeForm("xxx", "THE_TARGET");
	if (newForm_3) {
		std::cout << newForm_3->getName() << std::endl;
		newForm_3->beSigned(president);
		newForm_3->execute(president);
	}
	delete newForm_3;
}

int	main(void) {
	// test_1();
	// std::cout << "========================================================" << std::endl;
	// test_2();
	// std::cout << "========================================================" << std::endl;
	// test_presidential();
	// std::cout << "====================================================================================================================" << std::endl;
	// std::cout << "====================================================================================================================" << std::endl;
	// test_shrubbery();
	// std::cout << "====================================================================================================================" << std::endl;
	// std::cout << "====================================================================================================================" << std::endl;
	// test_robotomy();
	// std::cout << "====================================================================================================================" << std::endl;
	// std::cout << "====================================================================================================================" << std::endl;
	test_intern();
	return 0;
}
