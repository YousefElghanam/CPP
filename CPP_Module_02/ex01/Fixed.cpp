#include "Fixed.hpp"
#include <iostream>

const int Fixed::fractions = 8;

/* constructors + OCF */

Fixed::Fixed(void):
	raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num):
	raw(0) {
	std::cout << "Int constructor called" << std::endl;
	this->raw = static_cast<int>(static_cast<unsigned int>(num) << this->fractions);
}

Fixed::Fixed(const float num):
	raw(0) {
	std::cout << "Float constructor called" << std::endl;
	// We scale the float num, then because casting from float to int removes the
	//	fraction completely, we add 0.5 if it's positive so if it's closer to the
	//	next whole number it gets truncated to that one. (3.7 + 0.5 == 3.2; gets
	//	truncated to 3.0, then safely stored in an int).
	this->raw = (num * (1 << this->fractions) + (num > 0 ? 0.5 : -0.5));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&obj != this) {
		this->raw = obj.raw;
	}
	return *this;
}

/* MEMBER FUNCTIONS */

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->raw / (1 << this->fractions));
}

int		Fixed::toInt(void) const {
	return ((int)this->raw / (1 << this->fractions));
}

std::ostream&	operator<<(std::ostream &os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}
