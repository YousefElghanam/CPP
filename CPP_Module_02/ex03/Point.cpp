#include "Point.hpp"

Point::Point(void):
	x(0), y(0) {}

Point::Point(const float x, const float y):
	x(x), y(y) {}
	
Point::Point(Point& obj):
	x(obj.x), y(obj.y) {}

Point&	Point::operator=(Point& obj) {
	if (this != &obj) {
		(Fixed)this->x = obj.x;
		(Fixed)this->y = obj.y;
	}
	return *this;
}

Point::~Point(void) {}

Fixed	Point::getX(void) {
	return this->x;
}

Fixed	Point::getY(void) {
	return this->y;
}

Fixed	cross_product(Point v1, Point v2) {
	v1
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Point	vec[3];
	vec[0] = Point(float(a.getX() - b.getX()), )
	cross_product()
}
