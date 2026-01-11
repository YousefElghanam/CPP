#include "main.hpp"

#define MY_INT_MIN std::numeric_limits<int>::min()
#define MY_INT_MAX std::numeric_limits<int>::max()
#define MY_FLOAT_MIN std::numeric_limits<float>::min()
#define MY_FLOAT_MAX std::numeric_limits<float>::max()

int	main(void) {
	Fixed		a=3.6f;
	Fixed const	b=2;
	Fixed		c;
	// Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	// print_binary(a.getRawBits());
	// print_binary(b.getRawBits());

	// std::cout << (b == Fixed(11.1016f) - 1) << std::endl;
	// std::cout << Fixed(11.1016f) << std::endl;
	// std::cout << b << std::endl;
	// c = a + b;
	// std::cout << a << std::endl;
	std::cout << a * b << std::endl;
	// std::cout << "missing" << std::endl;
	std::cout << a - b << std::endl;
	// std::cout << "missing" << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a > b) << std::endl;
	// std::cout << "missing" << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
