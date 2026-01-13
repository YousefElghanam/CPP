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

int	main(void) {
	Point	a(0, 0);
	Point	b(2, 0);
	Point	c(0, 2);
	// Point	point(0.1f, 0.1f);
	// bool	isInside = bsp(tr1, tr2, tr3, point);
	// if (isInside)
	// 	std::cout << "INSIDE!" << std::endl;
	// else
	// 	std::cout << "OUTSIDE!" << std::endl;
	// return 0;

	TEST("Inside simple", bsp(a, b, c, Point(0.5f, 0.5f)));
	TEST("On edge", bsp(a, b, c, Point(1, 0)));
	TEST("On vertex", bsp(a, b, c, Point(0, 0)));
	TEST("Outside", bsp(a, b, c, Point(2, 2)));
	return 0;
}
