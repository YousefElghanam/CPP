#include <iostream>
#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice(void): AMateria("ice") {}

Ice::~Ice(void) {}

Ice::Ice(const Ice& obj): AMateria("ice"){
	*this = obj;
}

Ice&		Ice::operator=(const Ice& obj) {
	if (this != &obj) {
		this->type = "ice";
	}
	return *this;
}


AMateria*	Ice::clone(void) const {
	return new Ice;
}

void		Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}
