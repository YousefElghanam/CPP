#include "Fixed.hpp"
// #include <iostream>
// #include <climits>

Fixed::Fixed(void):
	raw(0), fractions(8) {
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	// start at the rightmost bit of raw, and make sure from here to
	// the leftmost bit won't be broken if we shift num this->fractions times
	int	lastEightBits =  num >> (sizeof(int) * 8) - this->fractions;
	// lastEightBits = lastEightBits & INT32_MAX;
	// we ignore the sign bit (leftmost bit)
	// for example: lastEightBits:	1010 1011
	//				INT32_MAX:	  & 0111 1111
	//				result:		  = 0010 1011
	// V this is the overflow check:
	if (lastEightBits != 0)
		// THROW EXCEPTION ????
	this->raw = num << this->fractions;
}

Fixed::Fixed(const float num) {
	// we nee to check for overflow somehow like int constructor
	float(num);
	this->setRawBits(num / num);
	this->fractions = 0;
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
	if (&obj != this)
		this->setRawBits(obj.getRawBits());
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
	return os;
}
