#include <cstddef>
#include <string>
#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {

}

Intern::~Intern(void) {}

Intern::Intern(const Intern& obj) {
	(void)obj;
}

Intern&	Intern::operator=(const Intern& obj) {
	(void)obj;
	return *this;
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const {
	AForm*	shrub = new ShrubberyCreationForm(target);
	AForm*	robot = new RobotomyRequestForm(target);
	AForm*	pres = new PresidentialPardonForm(target);

	if (formName == "shrubbery creation") {
		delete robot;
		delete pres;
		std::cout << "intern creates " << shrub->getName() << std::endl;
		return shrub;
	}
	if (formName == "robotomy request") {
		delete shrub;
		delete pres;
		std::cout << "intern creates " << robot->getName() << std::endl;
		return robot;
	}
	if (formName == "presidential pardon") {
		delete shrub;
		delete robot;
		std::cout << "intern creates " << pres->getName() << std::endl;
		return pres;
	}
	delete shrub;
	delete robot;
	delete pres;
	std::cerr << "form " << formName << " not found" << std::endl;
	return NULL;
}
