#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

const long	PresidentialPardonForm::formSignGrade = 25;
const long	PresidentialPardonForm::formExecGrade = 5;

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("default_presidential_form", PresidentialPardonForm::formSignGrade, PresidentialPardonForm::formExecGrade), target("default_target") {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("default_presidential_form", PresidentialPardonForm::formSignGrade, PresidentialPardonForm::formExecGrade), target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj):
	AForm(obj.getName(), obj.getSignGrade(), obj.getExecGrade()), target(obj.target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	if (this != &obj) {
		if (obj.getSign()) {
			this->beSigned(Bureaucrat("tmp", 1));
		}
		this->target = obj.target;
	}
	return *this;
}

bool			PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (this->canExecuteForm(executor)) {
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		return true;
	}
	return false;
}
