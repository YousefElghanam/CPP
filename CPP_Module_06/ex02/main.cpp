#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "BaseClass.hpp"
#include "AClass.hpp"
#include "BClass.hpp"
#include "CClass.hpp"

Base*	generate(void) {
	// std::srand(std::time(NULL));
	const int	idx = std::rand() % 3;

	switch (idx) {
		case 0: std::cout << "return A instance" << std::endl; return new A;
		case 1: std::cout << "return B instance" << std::endl; return new B;
		case 2: std::cout << "return C instance" << std::endl; return new C;
		default: std::cerr << "unexpected rand error" << std::endl; return NULL;
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "the pointer points to type A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "the pointer points to type B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "the pointer points to type C" << std::endl;
	}
}

void	identify(Base& p) {
	try {
		const A a = dynamic_cast<A&>(p);
		std::cout << "the reference points to type A" << std::endl;
	}
	catch (std::exception& e) {;}

	try {
		const B b = dynamic_cast<B&>(p);
		std::cout << "the reference points to type B" << std::endl;
	}
	catch (std::exception& e) {;}

	try {
		const C c = dynamic_cast<C&>(p);
		std::cout << "the reference points to type C" << std::endl;
	}
	catch (std::exception& e) {;}
}

int	main(void) {
	std::srand(std::time(NULL));
	Base*	ptr = generate();
	identify(ptr);
	std::cout << "---------------------------" << std::endl;
	identify(*ptr);
	std::cout << "===========================" << std::endl;
	delete ptr;
	ptr = generate();
	identify(ptr);
	std::cout << "---------------------------" << std::endl;
	identify(*ptr);
	std::cout << "===========================" << std::endl;
	delete ptr;
	ptr = generate();
	identify(ptr);
	std::cout << "---------------------------" << std::endl;
	identify(*ptr);
	delete ptr;
}
