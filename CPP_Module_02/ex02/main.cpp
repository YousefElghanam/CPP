#include "main.hpp"

void	print_binary(int num) {
	std::cout << "num: " << num << std::endl;
	for (int i = 31; i >= 0; i--) {
		std::cout << (((num >> i) & 1) > 0 ? 1 : 0);
		if (!(i % 8))
			std::cout << " ";
	}
	std::cout << std::endl;
}

// int	main(void) {
// 	Fixed		a=0.006f;
// 	Fixed const	b=0.f;
// 	Fixed		c;
// 	// Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	// print_binary(a.getRawBits());
// 	// print_binary(b.getRawBits());

// 	// std::cout << (b == Fixed(11.1016f) - 1) << std::endl;
// 	// std::cout << Fixed(11.1016f) << std::endl;
// 	// std::cout << b << std::endl;
// 	// c = a + b;
// 	// std::cout << a << std::endl;
// 	// std::cout << b << std::endl;
// 	// a.operator++(2);
// 	// std::cout << a;
// 	Fixed	d = Fixed::max(a, b);
// 	std::cout << d << std::endl;
// 	std::cout << a++ << std::endl;
// 	a++;
// 	std::cout << a << std::endl;
// 	std::cout << a * b << std::endl;
// 	// std::cout << a / b << std::endl;
// 	// std::cout << "missing" << std::endl;
// 	std::cout << a - b << std::endl;
// 	// std::cout << "missing" << std::endl;
// 	std::cout << (a == b) << std::endl;
// 	std::cout << (a > b) << std::endl;
// 	// std::cout << "missing" << std::endl;
// 	// std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
