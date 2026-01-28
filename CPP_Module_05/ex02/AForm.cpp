#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

const long	AForm::minGrade = 150;
const long	AForm::maxGrade = 1;

const char*	AForm::GradeTooHighException::what(void) const throw() {
	return "ERROR: Grade too High";
}

const char*	AForm::GradeTooLowException::what(void) const throw() {
	return "ERROR: Grade too Low";
}

const char*	AForm::AlreadySignedException::what(void) const throw() {
	return "ERROR: Form is already signed";
}

const char*	AForm::NotSignedException::what(void) const throw() {
	return "ERROR: Form is not signed";
}

AForm::AForm(void):
	name("default_form"), signGrade(150), execGrade(150), sign(false) {}

AForm::~AForm(void) {}

AForm::AForm(const std::string& name, long signGrade, long execGrade):
	name(name), signGrade(signGrade), execGrade(execGrade), sign(false) {
		if (this->signGrade > AForm::minGrade || this->execGrade > AForm::minGrade) {
			throw AForm::GradeTooLowException();
		}
		if (this->signGrade < AForm::maxGrade || this->execGrade < AForm::maxGrade) {
			throw AForm::GradeTooHighException();
		}
}

AForm::AForm(const AForm& obj):
	name(obj.name), signGrade(obj.signGrade), execGrade(obj.execGrade), sign(obj.sign) {}

AForm&			AForm::operator=(const AForm& obj) {
	if (this != &obj) {
		this->sign = obj.getSign();
	}
	return *this;
}

const std::string&	AForm::getName(void) const {
	return this->name;
}

long				AForm::getSignGrade(void) const {
	return this->signGrade;
}

long				AForm::getExecGrade(void) const {
	return this->execGrade;
}

bool				AForm::getSign(void) const {
	return this->sign;
}

bool				AForm::canExecuteForm(const Bureaucrat& executor) const {
	try {
		if (!this->sign) {
			throw AForm::NotSignedException();
		}
		if (executor.getGrade() > this->execGrade) {
			throw AForm::GradeTooLowException();
		}
	}
	catch (std::exception& e) {
		std::cerr << "canExecuteForm(): " << e.what() << std::endl;
		return false;
	}
	return true;
}

void				AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->signGrade) {
		if (this->sign) {
			throw AForm::AlreadySignedException();
		}
		this->sign = true;
	}
	else {
		throw AForm::GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream &os, const AForm& obj) {
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
