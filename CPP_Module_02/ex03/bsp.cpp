#include "Point.hpp"
#include "Fixed.hpp"

static Fixed	cross_product(vec v1, vec v2) {
	return (v1.getX() * v2.getY()) - (v2.getX() * v1.getY());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	triangleArea = Fixed::abs(cross_product(vec(b - a), vec(c - a)) / 2);
	Fixed	miniTriArea1 = Fixed::abs(cross_product(vec(point - a), vec(point - b)) / 2);
	Fixed	miniTriArea2 = Fixed::abs(cross_product(vec(point - b), vec(point - c)) / 2);
	Fixed	miniTriArea3 = Fixed::abs(cross_product(vec(point - c), vec(point - a)) / 2);
	// std::cout << "BIG TRIANGLE AREA: " << triangleArea << std::endl;
	// std::cout << "MINI TRI 1 AREA: " << miniTriArea1 << std::endl;
	// std::cout << "MINI TRI 2 AREA: " << miniTriArea2 << std::endl;
	// std::cout << "MINI TRI 3 AREA: " << miniTriArea3 << std::endl;
	if (miniTriArea1 == 0 || miniTriArea2 == 0 || miniTriArea3 == 0)
		return false;
	if (miniTriArea1 + miniTriArea2 + miniTriArea3 == triangleArea)
		return true;
	return false;
}
