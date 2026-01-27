#include <iostream>
#include <string>
#include "Form.hpp"

const long	Form::minGrade = 150;
const long	Form::maxGrade = 1;

const char*	Form::GradeTooHighException::what(void) const throw() {
	return "ERROR: Grade too High";
}

const char*	Form::GradeTooLowException::what(void) const throw() {
	return "ERROR: Grade too Low";
}

Form::Form(void):
	name("default_form"), signGrade(150), execGrade(150), sign(false) {}

Form::~Form(void) {}

Form::Form(const std::string& name, long signGrade, long execGrade):
	name(name), signGrade(signGrade), execGrade(execGrade), sign(false) {
		if (this->signGrade > Form::minGrade || this->execGrade > Form::minGrade) {
			throw Form::GradeTooLowException();
			return ;
		}
		if (this->signGrade < Form::maxGrade || this->execGrade < Form::maxGrade) {
			throw Form::GradeTooHighException();
			return ;
		}
}

Form::Form(const Form& obj):
	name(obj.name), signGrade(obj.signGrade), execGrade(obj.execGrade), sign(obj.sign) {}

Form&			Form::operator=(const Form& obj) {
	if (this != &obj) {
		this->sign = obj.getSign();
	}
	return *this;
}

const std::string&	Form::getName(void) const {
	return this->name;
}

long				Form::getSignGrade(void) const {
	return this->signGrade;
}

long				Form::getExecGrade(void) const {
	return this->execGrade;
}

bool				Form::getSign(void) const {
	return this->sign;
}

std::ostream&	operator<<(std::ostream &os, const Form& obj) {
	if (obj.getSign()) {
		os << "Signed ";
	}
	else {
		os << "Unsigned ";
	}
	os << obj.getName() << " form sign grade " << obj.getSignGrade()
		<<", execution grade " << obj.getExecGrade() << ".";
	return os;
}
