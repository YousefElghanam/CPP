#include <iostream>
#include "Span.hpp"

#include <vector>
#include <set>
#include <deque>

int		main(void) {
	std::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	Span	span(5);
	span.addNumber(vec.begin(), vec.end());
	span.printSet();
}
