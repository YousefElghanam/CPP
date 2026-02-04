#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

const long	Bureaucrat::minGrade = 150;
const long	Bureaucrat::maxGrade = 1;

const char*	Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "ERROR: Grade too High";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "ERROR: Grade too Low";
}

Bureaucrat::Bureaucrat(void):
	name("defualt_name"), grade(1) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const std::string& name, long grade):
	name(name) {
		if (grade > Bureaucrat::minGrade) {
			this->grade = 150;
			throw Bureaucrat::GradeTooLowException();
		}
		if (grade < Bureaucrat::maxGrade) {
			this->grade = 150;
			throw Bureaucrat::GradeTooHighException();
		}
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):
	name(obj.name), grade(obj.grade) {}

Bureaucrat&			Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj) {
		this->grade = obj.getGrade();
	}
	return *this;
}

const std::string&	Bureaucrat::getName(void) const {
	return this->name;
}

long				Bureaucrat::getGrade(void) const {
	return this->grade;
}

void				Bureaucrat::operator++(int) {
	if (this->grade == Bureaucrat::maxGrade) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade--;
}

void				Bureaucrat::operator--(int) {
	if (this->grade == Bureaucrat::minGrade) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade++;
}

void				Bureaucrat::signForm(AForm& form) const {
	bool	success = true;

	try {
		form.beSigned(*this);
	}
	catch (std::exception& e) {
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		success = false;
	}
	if (success) {
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
}

void				Bureaucrat::executeForm(const AForm& form) const {
	if (form.execute(*this)) {
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	else {
		std::cout << this->name << " couldn't execute " << form.getName() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}
