#include <iostream>
#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice(void): AMateria("ice") {
	std::cout <<"Ice Constructor Called" << std::endl;
}

Ice::~Ice(void) {
	std::cout <<"Ice Destructor Called" << std::endl;
}

Ice::Ice(const Ice& obj): AMateria("ice"){
	std::cout <<"Ice Copy Constructor Called" << std::endl;
	*this = obj;
}

Ice&		Ice::operator=(const Ice& obj) {
	std::cout <<"Ice Copy Assignment Called" << std::endl;
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
