#include <iostream>
#include "BaseClass.hpp"

Base::~Base(void) {
	std::cout << "calling destructor" << std::endl;
}
