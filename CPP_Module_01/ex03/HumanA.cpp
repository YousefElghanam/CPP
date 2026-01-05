#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon):
	name(name), weaponREF(weapon) {
		;
}

HumanA::~HumanA(void) {
	;
}

void				HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->weaponREF.getType() << std::endl;
}
