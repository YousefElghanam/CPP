#include <exception>
#include <string>
#include "Bureaucrat.hpp"

const long	Bureaucrat::minGrade = 150;
const long	Bureaucrat::maxGrade = 1;

const char*	Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "ERROR: Grade too High";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "ERROR: Grade too Low";
}

// Bureaucrat::Bureaucrat(void) {}

// Bureaucrat::~Bureaucrat(void) {};

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

const std::string&	Bureaucrat::getName(void) const {
	return this->name;
}

long				Bureaucrat::getGrade(void) const {
	return this->grade;
}

void				Bureaucrat::operator++(void) {
	if (this->grade == Bureaucrat::maxGrade) {
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	this->grade--;
}

void				Bureaucrat::operator--(void) {
	if (this->grade == Bureaucrat::minGrade) {
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->grade++;
}
