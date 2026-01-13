#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

# include "Fixed.hpp"
# include <iostream>

class Point {
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point(const Point& obj);
		Point&	operator=(Point& obj);
		~Point(void);
	
		Fixed	getX(void) const;
		Fixed	getY(void) const;

		Point	operator-(const Point& obj) const;
};

typedef Point vec;

#endif /* POINT_CLASS_HPP */
