#include <iostream>
#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure(void): AMateria("cure") {
	// std::cout <<"Cure Constructor Called" << std::endl;
}

Cure::~Cure(void) {
	// std::cout <<"Cure Destructor Called" << std::endl;
}

Cure::Cure(const Cure& obj): AMateria("Cure"){
	// std::cout <<"Cure Copy Constructor Called" << std::endl;
	*this = obj;
}

Cure&		Cure::operator=(const Cure& obj) {
	// std::cout <<"Cure Copy Assignment Called" << std::endl;
	(void)obj;
	return *this;
}


AMateria*	Cure::clone(void) const {
	return new Cure;
}

void		Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl; 
}
