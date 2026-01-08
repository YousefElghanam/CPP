#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void):
	raw(0), fractions(8) {
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int num) {
	// INSERT MATH HERE
	this->setRawBits(num);
	this->fractions = 0;
}

Fixed::Fixed(const float num) {
	this->setRawBits(num / num);
	this->fractions = 0;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw = obj.getRawBits();
	this->fractions = obj.fractions;
	return (*this);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}

float	Fixed::toFloat(void) const {
	// INSERT MATHS HERE
	return (this->getRawBits());
}

int		Fixed::toInt(void) const {
	// INSET MATHS HERE
	return (this->getRawBits());
}

std::ostream& operator<<(std::ostream &os, Fixed fixed) {
	// INSERT MATHS HERE
	os << fixed.getRawBits();
}