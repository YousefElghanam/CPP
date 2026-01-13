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
		Point(Point& obj);
		Point&	operator=(Point& obj);
		~Point(void);
	
		Fixed	getX(void);
		Fixed	getY(void);
}	vec ;

#endif /* POINT_CLASS_HPP */
