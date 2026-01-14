#include "main.hpp"

#define TEST(desc, expr) \
    std::cout << desc << ": " << ((expr) ? "INSIDE" : "OUTSIDE") << '\n';

void	print_binary(int num) {
	std::cout << "num: " << num << std::endl;
	for (int i = 31; i >= 0; i--) {
		std::cout << (((num >> i) & 1) > 0 ? 1 : 0);
		if (!(i % 8))
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	test1(void) {
	std::cout << "Simple (0,0) (2,0) (0,2) triangle" << std::endl;
	Point	a(0, 0), b(2, 0), c(0, 2);
	std::cout << "(.5, .5)\t" << bsp(a, b, c, Point(0.5f, 0.5f)) << std::endl;	// inside
	std::cout << "(2, 2)\t\t" << bsp(a, b, c, Point(2, 2)) << std::endl;			// outside
	std::cout << "(1, 0)\t\t" << bsp(a, b, c, Point(1, 0)) << std::endl;	// outside
	std::cout << "(0, 1)\t\t" << bsp(a, b, c, Point(0, 1)) << std::endl;	// outside
	std::cout << "(1, 1)\t\t" << bsp(a, b, c, Point(1, 1)) << std::endl;	// outside
	std::cout << "(0, 0)\t\t" << bsp(a, b, c, Point(0, 0)) << std::endl;	// outside
}

void	test2(void) {
	Point	a(1, 1), b(-1, 1), c(0, -1);
	TEST("Inside simple", bsp(a, b, c, Point(0, 0)));
	TEST("On edge", bsp(a, b, c, Point(0, 1)));
	TEST("On vertex", bsp(a, b, c, Point(1, 1)));
	TEST("Outside", bsp(a, b, c, Point(2, 2)));
}

int	main(void) {
	// Point	a(-1, -1), b( 1, -1), c( 0,  1);
	// Point	a(0, 0), b(0, 2), c(2, 0); // reversed order
	// Point	a(0, 0), b(1, 0), c(0, 1);
	// Point	a(10000, 0), b(0, 10000), c(0, 0);
	// Point	a(0, 0), b(1, 1), c(2, 2); // collinear
	test1();
	std::cout << "===============================" << std::endl;
	test2();
	return 0;
}
