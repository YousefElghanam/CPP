#include <iostream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

const long	Form::minGrade = 150;
const long	Form::maxGrade = 1;

const char*	Form::GradeTooHighException::what(void) const throw() {
	return "ERROR: Grade too High";
}

const char*	Form::GradeTooLowException::what(void) const throw() {
	return "ERROR: Grade too Low";
}

const char*	Form::AlreadySigned::what(void) const throw() {
	return "ERROR: Form is already signed";
}

Form::Form(void):
	name("default_form"), signGrade(150), execGrade(150), sign(false) {}

Form::~Form(void) {}

Form::Form(const std::string& name, long signGrade, long execGrade):
	name(name), signGrade(signGrade), execGrade(execGrade), sign(false) {
		if (this->signGrade > Form::minGrade || this->execGrade > Form::minGrade) {
			throw Form::GradeTooLowException();
		}
		if (this->signGrade < Form::maxGrade || this->execGrade < Form::maxGrade) {
			throw Form::GradeTooHighException();
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

void				Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->signGrade) {
		if (this->sign) {
			throw Form::AlreadySigned();
		}
		this->sign = true;
	}
	else {
		throw Form::GradeTooLowException();
	}
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
