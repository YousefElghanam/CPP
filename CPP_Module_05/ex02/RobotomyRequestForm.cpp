#include <iostream>
#include <string>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

const long		RobotomyRequestForm::formSignGrade = 72;
const long		RobotomyRequestForm::formExecGrade = 45;
unsigned int	RobotomyRequestForm::state = 0;

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("default_presidential_form", RobotomyRequestForm::formSignGrade, RobotomyRequestForm::formExecGrade), target("default_target") {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("default_presidential_form", RobotomyRequestForm::formSignGrade, RobotomyRequestForm::formExecGrade), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj):
	AForm(obj.getName(), obj.getSignGrade(), obj.getExecGrade()), target(obj.target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	if (this != &obj) {
		if (obj.getSign()) {
			this->beSigned(Bureaucrat("tmp", 1));
		}
		this->target = obj.target;
	}
	return *this;
}

int			RobotomyRequestForm::rand(void) {
	RobotomyRequestForm::state = (RobotomyRequestForm::state * 1103515245) + 12345;
	return (RobotomyRequestForm::state / 65536) % 32768;
}

bool		RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (this->canExecuteForm(executor)) {
		std::cout << "* DRILLING NOISES *" << std::endl;
		if (this->rand() % 2 == 0) {
			std::cout << this->target << " has been successfully robotomized" << std::endl;
			return true;
		}
		std::cout << this->target << " could not be robotomized" << std::endl;
		return false;
	}
	return false;
}
