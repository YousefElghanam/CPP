#include "easyfind.hpp"
#include <exception>
#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator	easyfind(T& container, int num) {
	typename T::iterator	it = std::find(container.begin(), container.end(), num);
	if (it == container.end()) {
		throw std::exception();
	}
	std::cout << "Found " << *it << " at index " << std::distance(container.begin(), it) << std::endl;
	return typename T::iterator(it);
}
