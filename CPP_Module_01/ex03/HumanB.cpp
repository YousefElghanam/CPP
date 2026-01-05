#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name):
	name(name), weaponPTR(NULL) {
		;
}

HumanB::~HumanB(void) {
	;
}

void				HumanB::setWeapon(Weapon& weapon) {
	std::cout << "HumanB " << this->name << " is taking " << weapon.getType() << std::endl;
	this->weaponPTR = &weapon;
}

void				HumanB::attack(void) {
	if (this->weaponPTR)
		std::cout << this->name << " attacks with their " << this->weaponPTR->getType() << std::endl;
	else
		std::cout << this->name << " doesn't have a Weapon to attack with." << std::endl;
}
