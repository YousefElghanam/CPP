#include "Fixed.hpp"
#include <iostream>

const int Fixed::fractions = 8;

Fixed::Fixed(void):
	raw(0) {
}

Fixed::Fixed(const int num):
	raw(0) {
	this->raw = static_cast<int>(static_cast<unsigned int>(num) << this->fractions);
}

Fixed::Fixed(const float num):
	raw(0) {
	// We scale the float num, then because casting from float to int removes the
	//	fraction completely, we add 0.5 if it's positive so if it's closer to the
	//	next whole number it gets truncated to that one. (3.7 + 0.5 == 3.2; gets
	//	truncated to 3.0, then safely stored in an int).
	this->raw = (num * (1 << this->fractions) + (num > 0 ? 0.5 : -0.5));
}

Fixed::~Fixed(void) {
}

Fixed::Fixed(const Fixed& obj) {
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	if (&obj != this) {
		this->raw = obj.raw;
	}
	return *this;
}

int		Fixed::getRawBits(void) const {
	return this->raw;
}

void	Fixed::setRawBits(const int raw) {
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
	ret.setRawBits(static_cast<int>(mul >> this->fractions));
	return ret;
}

Fixed	Fixed::operator/(const Fixed& obj) const {
	Fixed	ret;

	/* NOTE: I don't want to handle division by 0 */

	int	sign = 1;
	if (this->raw < 0)
		sign = -1;
	/* We only scale the first operand to make the division more precise. Scaling both doesn't make sense,
		because in a division operation if both sides are multiplied by the same amount, that amount is ignored
		anyway. (100*x / 200*x == 100 / 200), but (100*x / 200) will give use more info */
	unsigned long	div = ((static_cast<unsigned long>(this->raw)) << this->fractions)
						/ ((static_cast<unsigned long>(obj.raw)));
	/* the result (div) doesn't need to be shifted after this, because it's already scaled
		(the whole and fraction parts of the bits are in their correct position) */
	ret.setRawBits(static_cast<int>(div * sign));
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

Fixed			Fixed::abs(Fixed& fp1) {
	if (fp1 < 0)
		return Fixed(-1) * fp1;
	return Fixed(fp1);
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

Fixed			Fixed::abs(const Fixed& fp1) {
	if (fp1 < 0)
		return Fixed(-1) * fp1;
	return Fixed(fp1);
}
