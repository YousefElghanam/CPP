#include "main.hpp"

#define MY_INT_MIN std::numeric_limits<int>::min()
#define MY_INT_MAX std::numeric_limits<int>::max()
#define MY_FLOAT_MIN std::numeric_limits<float>::min()
#define MY_FLOAT_MAX std::numeric_limits<float>::max()

void	print_binary(int num) {
	std::cout << "num: " << num << std::endl;
	for (int i = 31; i >= 0; i--) {
		std::cout << (((num >> i) & 1) > 0 ? 1 : 0);
		if (!(i % 8))
			std::cout << " ";
	}
	std::cout << std::endl;
}

int	main(void) {
	Point	p1(1.5, 2.5);
	std::cout << p1.getX() << std::endl;;
	std::cout << p1.getY() << std::endl;;
	Point	p2(p1);
	std::cout << p2.getX() << std::endl;;
	Point	p3 = p2;
	std::cout << p3.getX() << std::endl;;
	return 0;
}

// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }
