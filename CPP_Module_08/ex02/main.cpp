#include <iostream>
#include "Span.hpp"

#include <exception>
#include <vector>
#include <ctime>
#include <cstdlib>

// int		main(void) {
// 	std::srand(std::time(0));
// 	std::vector<int>	vec;
// 	for (size_t i = 0; i < 10; i++) {
// 		vec.push_back(std::rand() % 1000000);
// 	}

// 	Span	span(9);
// 	try {
// 		span.addNumber(vec.begin(), vec.end());
// 		span.addNumber(2);
// 	}
// 	catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	span.printContainer();
// 	try {
// 		std::cout << "shortest span is: " << span.shortestSpan() << std::endl;
// 	}
// 	catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	try {
// 		std::cout << "longest span is: " << span.longestSpan() << std::endl;
// 	}
// 	catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// }
int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
