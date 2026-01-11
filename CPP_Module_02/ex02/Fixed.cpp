#include "Fixed.hpp"
#include <iostream>

const int Fixed::fractions = 8;

Fixed::Fixed(void):
	raw(0) {
	// std::cout << "Default constructor called" << std::endl;
}

/* Numbers above () or below () is UB */
Fixed::Fixed(const int num):
	raw(0) {
	// std::cout << "Int constructor called" << std::endl;
	this->raw = num << this->fractions;
}

Fixed::Fixed(const float num):
	raw(0) {
	// std::cout << "Float constructor called" << std::endl;
	this->raw = (num * (1 << this->fractions) + (num > 0 ? 0.5 : -0.5));
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (&obj != this) {
		this->raw = obj.raw;
	}
	return *this;
}

int		Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void	Fixed::setRawBits(const int raw) {
	// std::cout << "setRawBits member function called" << std::endl;
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

std::ostream&	operator<<(std::ostream &os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed& obj) const {
	return (this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator<(const Fixed& obj) const {
	return this->getRawBits() < obj.getRawBits();
}

bool	Fixed::operator>=(const Fixed& obj) const {
	return this->getRawBits() >= obj.getRawBits();
}

bool	Fixed::operator<=(const Fixed& obj) const {
	return this->getRawBits() <= obj.getRawBits();
}

bool	Fixed::operator==(const Fixed& obj) const {
	return this->getRawBits() == obj.getRawBits();
}

bool	Fixed::operator!=(const Fixed& obj) const {
	return this->getRawBits() != obj.getRawBits();
}

Fixed	Fixed::operator+(const Fixed& obj) const {
	Fixed	ret;
	ret.setRawBits(this->raw + obj.getRawBits());
	return ret;
}

Fixed	Fixed::operator-(const Fixed& obj) const {
	Fixed	ret;
	ret.setRawBits(this->raw - obj.getRawBits());
	return ret;
}

void	print_binary(int num) {
	std::cout << "num: " << num << std::endl;
	for (int i = 31; i >= 0; i--) {
		std::cout << (((num >> i) & 1) > 0 ? 1 : 0);
		if (!(i % 8))
			std::cout << " ";
	}
	std::cout << std::endl;
}

Fixed	Fixed::operator*(const Fixed& obj) const {
	Fixed	ret;
	int		fractionExtractor = 0;

	// for fractions of 12, Extractor will be 0000 0011 1111 1111 (12 zeros).
	for (int i = 0; i < this->fractions; i++)
		fractionExtractor |= (1 << i);
	int		whole = this->raw >> this->fractions;
	int		fractions = this->raw & fractionExtractor;
	ret.setRawBits(whole * obj.getRawBits()
			+ ((fractions * obj.getRawBits()) >> this->fractions));
	return ret;
}

// TODO
Fixed	Fixed::operator/(const Fixed& obj) const {
	Fixed	ret;
	ret.setRawBits(this->raw / obj.getRawBits());
	return ret;
}
