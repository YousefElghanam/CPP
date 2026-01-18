#include <iostream>
#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure(void): AMateria("Cure") {}

Cure::~Cure(void) {}

Cure::Cure(const Cure& obj): AMateria("Cure"){
	*this = obj;
}

Cure&		Cure::operator=(const Cure& obj) {
	if (this != &obj) {
		this->type = "Cure";
	}
	return *this;
}


AMateria*	Cure::clone(void) const {
	return new Cure;
}

void		Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl; 
}
