#include <cstddef>
#include <string>
#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const unsigned int	Intern::formCount = 3;

const char*	Intern::FormDoesNotExistException::what(void) const throw() {
	return "ERROR: Intern doesn't have information about this form.";
}

Intern::Intern(void) {
	this->forms[0] = "shrubbery creation";
	this->forms[1] = "robotomy request";
	this->forms[2] = "presidential pardon";
	this->formArr[0] = new ShrubberyCreationForm();
	this->formArr[1] = new RobotomyRequestForm();
	this->formArr[2] = new PresidentialPardonForm();
	this->formArr[3] = NULL;
}

Intern::~Intern(void) {
	for (unsigned int i = 0; i < Intern::formCount; i++) {
		delete this->formArr[i];
	}
}

Intern::Intern(const Intern& obj) {
	for (unsigned int i = 0; i < Intern::formCount; i++ ) {
		this->formArr[i] = obj.formArr[i]->clone();
	}
}

Intern&	Intern::operator=(const Intern& obj) {
	if (this != &obj) {
		for (unsigned int i = 0; i < Intern::formCount; i++ ) {
			delete this->formArr[i];
			this->formArr[i] = obj.formArr[i]->clone();
		}
	}
	return *this;
}

unsigned int	Intern::getFormIdx(const std::string& formName) const {
	for (unsigned int i = 0; i < Intern::formCount; i++) {
		if (formName == this->forms[i]) {
			return i;
		}
	}
	return Intern::formCount;
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const {
	AForm*	ret = this->formArr[getFormIdx(formName)];
	if (!ret) {
		std::cerr << "Form making failed. ";
		throw FormDoesNotExistException();
	}
	ret = ret->clone();
	ret->setTarget(target);
	return ret;
}
