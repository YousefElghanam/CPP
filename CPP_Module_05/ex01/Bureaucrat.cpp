#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

const long	Bureaucrat::minGrade = 150;
const long	Bureaucrat::maxGrade = 1;

const char*	Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "ERROR: Grade too High";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "ERROR: Grade too Low";
}

Bureaucrat::Bureaucrat(void):
	name("defualt_name"), grade(0) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const std::string& name, long grade):
	name(name) {
		if (grade > Bureaucrat::minGrade) {
			this->grade = 0;
			throw Bureaucrat::GradeTooLowException();
			return ;
		}
		if (grade < Bureaucrat::maxGrade) {
			this->grade = 0;
			throw Bureaucrat::GradeTooHighException();
			return ;
		}
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) {
	*this = obj;
}

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
		return ;
	}
	this->grade--;
}

void				Bureaucrat::operator--(int) {
	if (this->grade == Bureaucrat::minGrade) {
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->grade++;
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}
