#include "main.hpp"

#define MY_INT_MIN std::numeric_limits<int>::min()
#define MY_INT_MAX std::numeric_limits<int>::max()
#define MY_FLOAT_MIN std::numeric_limits<float>::min()
#define MY_FLOAT_MAX std::numeric_limits<float>::max()

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
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
