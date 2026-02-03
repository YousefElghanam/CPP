#include <fstream>
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

const long	ShrubberyCreationForm::formSignGrade = 145;
const long	ShrubberyCreationForm::formExecGrade = 137;

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("default_shrubbery_form", ShrubberyCreationForm::formSignGrade, ShrubberyCreationForm::formExecGrade) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("default_shrubbery_form", ShrubberyCreationForm::formSignGrade, ShrubberyCreationForm::formExecGrade) {
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj):
	AForm(obj.getName(), obj.getSignGrade(), obj.getExecGrade()) {
	this->setTarget(obj.getTarget());
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	if (this != &obj) {
		if (obj.getSign()) {
			this->beSigned(Bureaucrat("tmp", 1));
		}
		this->setTarget(obj.getTarget());
	}
	return *this;
}

bool		ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (this->canExecuteForm(executor)) {
		std::ofstream	outputFile;

		outputFile.open((this->getTarget() + "_shrubbery").c_str());
		if (outputFile.fail()) {
			std::cerr << "Couldn't create or open file (" << this->getTarget() + "_shrubbery" << ")" << std::endl;
			return false;
		}
		outputFile << "This is a tree, trust me bro" << std::endl;
		return true;
	}
	return false;
}

AForm*			ShrubberyCreationForm::clone(void) const {
	AForm*	ret = new ShrubberyCreationForm();
	ret->setTarget(this->getTarget());
	return ret;
}
