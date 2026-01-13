#include "Point.hpp"

Point::Point(void):
	x(0), y(0) {}

Point::Point(const float x, const float y):
	x(x), y(y) {}

Point::Point(const Fixed x, const Fixed y):
	x(x), y(y) {}

Point::Point(const Point& obj):
	x(obj.x), y(obj.y) {}
	
Point&	Point::operator=(Point& obj) {
	if (this != &obj) {
		(Fixed)this->x = obj.x;
		(Fixed)this->y = obj.y;
	}
	return *this;
}

Point::~Point(void) {}

vec	Point::operator-(const Point& obj) const {
	Point	ret(this->getX() - obj.getX(), this->getY() - obj.getY());
	return ret;
}

Fixed	Point::getX(void) const {
	return this->x;
}

Fixed	Point::getY(void) const {
	return this->y;
}
