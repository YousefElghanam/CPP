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
	return this->getRawBits() > obj.getRawBits();
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

Fixed	Fixed::operator*(const Fixed& obj) const {
	Fixed	ret;
	// int		fractionExtractor = 0;

	// // for fractions of 12, Extractor will be 0000 0011 1111 1111 (12 zeros).
	// for (int i = 0; i < this->fractions; i++)
	// 	fractionExtractor |= (1 << i);
	// int		whole = this->raw >> this->fractions;
	// int		fractions = this->raw & fractionExtractor;
	// ret.setRawBits(whole * obj.getRawBits()
	// 		+ ((fractions * obj.getRawBits()) >> this->fractions));

	/* This multiplication will move the point 8 more bits to the left, so
		we scale it back by shifting 8 right. */
	long	mul = static_cast<long>(this->raw) * static_cast<long>(obj.raw);
	ret.setRawBits(mul >> this->fractions);
	return ret;
}

Fixed	Fixed::operator/(const Fixed& obj) const {
	Fixed	ret;

	/* NOTE: I don't want to handle division by 0 */

	/* We only scale the first operand to make the division more precise. Scaling both doesn't make sense,
		because in a division operation if both sides are multiplied by the same amount, that amount is ignored
		anyway. (100*x / 200*x == 100 / 200), but (100*x / 200) will give use more info */
	long	div = ((static_cast<long>(this->raw)) << this->fractions) / ((static_cast<long>(obj.raw)));
	/* the result (div) doesn't need to be shifted after this, because it's already scaled
		(the whole and fraction parts of the bits are in their correct position) */
	ret.setRawBits(static_cast<int>(div));
	return ret;
}

/* post increment/decrement */

Fixed	Fixed::operator++(int) {
	Fixed	ret(*this);
	this->setRawBits(this->raw + 1);
	return ret;
}

Fixed	Fixed::operator--(int) {
	Fixed	ret(*this);
	this->setRawBits(this->raw - 1);
	return ret;
}

/* pre increment/decrement */

Fixed	Fixed::operator++(void) {
	this->setRawBits(this->raw + 1);
	Fixed	ret(*this);
	return ret;
}

Fixed	Fixed::operator--(void) {
	this->setRawBits(this->raw + 1);
	Fixed	ret(*this);
	return ret;
}

/* Returns first paremeter if they're equal */
Fixed&	Fixed::min(Fixed& fp1, Fixed& fp2) {
	if (fp2 < fp1)
		return fp2;
	return fp1;
}

/* Returns first paremeter if they're equal */
Fixed&	Fixed::max(Fixed& fp1, Fixed& fp2) {
	if (fp2 > fp1)
		return fp2;
	return fp1;
}

/* Returns first paremeter if they're equal */
const Fixed&	Fixed::min(const Fixed& fp1, const Fixed& fp2) {
	if (fp2 < fp1)
		return fp2;
	return fp1;
}

/* Returns first paremeter if they're equal */
const Fixed&	Fixed::max(const Fixed& fp1, const Fixed& fp2) {
	if (fp2 > fp1)
		return fp2;
	return fp1;
}
