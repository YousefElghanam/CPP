// #include <iostream>
#include <string>
#include "AMateria.hpp"

AMateria::AMateria(const std::string& type):
	type(type) {
		// std::cout << "AMateria Constructor(string) called" << std::endl;
}

AMateria::~AMateria(void) {
	// std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj) {
	// std::cout << "AMateria Copy Constructor called" << std::endl;
	*this = obj;
}

AMateria&	AMateria::operator=(const AMateria& obj) {
	// std::cout << "AMateria Copy Assignment called" << std::endl;
	if (this != &obj) {
		this->type = obj.type;
	}
	return *this;
}

const std::string&	AMateria::getType(void) const {
	// std::cout << "AMateria getType called" << std::endl;
	return this->type;
}
