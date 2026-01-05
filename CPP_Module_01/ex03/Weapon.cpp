#include "Weapon.hpp"

#include <iostream>

Weapon::Weapon(std::string name):
	type(name) {
		;
}

Weapon::~Weapon(void) {
	;
}

void		Weapon::setType(std::string newType) {
	this->type = newType;
}

const std::string&	Weapon::getType(void) const {
	return this->type;
}
