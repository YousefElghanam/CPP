#include "Fixed.hpp"
#include <iostream>

// const int Fixed::fractions = 8;

Fixed::Fixed(void):
	raw(0), fractions(8) {
	std::cout << "Default constructor called" << std::endl;
}

/* Numbers above () or below () is UB */
Fixed::Fixed(const int num):
	raw(0) {
	std::cout << "Int constructor called" << std::endl;
	this->raw = num << this->fractions;
}

Fixed::Fixed(const float num):
	raw(0) {
	std::cout << "Float constructor called" << std::endl;
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

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}

// int		Fixed::getFractions(void) const {
// 	std::cout << "getFractions member function called" << std::endl;
// 	return this->fractions;
// }

float	Fixed::toFloat(void) const {
	return ((float)this->raw / (1 << this->fractions));
}

int		Fixed::toInt(void) const {
	return ((int)this->raw / (1 << this->fractions));
}

std::ostream& operator<<(std::ostream &os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed& obj) const {
	return this->toFloat() > obj.toFloat();
}

bool	Fixed::operator<(const Fixed& obj) const {
	return this->toFloat() < obj.toFloat();
}

bool	Fixed::operator>=(const Fixed& obj) const {
	return this->toFloat() >= obj.toFloat();
}

bool	Fixed::operator<=(const Fixed& obj) const {
	return this->toFloat() <= obj.toFloat();
}

bool	Fixed::operator==(const Fixed& obj) const {
	return this->toFloat() == obj.toFloat();
}

bool	Fixed::operator!=(const Fixed& obj) const {
	return this->toFloat() != obj.toFloat();
}

Fixed	Fixed::operator+(const Fixed& obj) const {
	Fixed	ret(this->toFloat() + obj.toFloat());
	return ret.toFloat();
}

Fixed	Fixed::operator-(const Fixed& obj) const {
	Fixed	ret(this->toFloat() - obj.toFloat());
	return ret.toFloat();
}

Fixed	Fixed::operator*(const Fixed& obj) const {
	Fixed	ret(this->toFloat() * obj.toFloat());
	return ret.toFloat();
}

Fixed	Fixed::operator/(const Fixed& obj) const {
	Fixed	ret(this->toFloat() / obj.toFloat());
	return ret.toFloat();
}
