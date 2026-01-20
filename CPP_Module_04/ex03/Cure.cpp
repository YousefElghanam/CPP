#include <iostream>
#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure(void): AMateria("cure") {}

Cure::~Cure(void) {}

Cure::Cure(const Cure& obj): AMateria("Cure"){
	*this = obj;
}

Cure&		Cure::operator=(const Cure& obj) {
	(void)obj;
	return *this;
}


AMateria*	Cure::clone(void) const {
	return new Cure;
}

void		Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl; 
}
