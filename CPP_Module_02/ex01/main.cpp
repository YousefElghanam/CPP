#include "main.hpp"

// void	print_binary(int num) {
// 	std::cout << "num: " << num << std::endl;
// 	for (int i = 31; i >= 0; i--) {
// 		std::cout << (((num >> i) & 1) > 0 ? 1 : 0);
// 		if (!(i % 8))
// 			std::cout << " ";
// 	}
// 	std::cout << std::endl;
// }

int main(void) {
	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	return 0;
}
