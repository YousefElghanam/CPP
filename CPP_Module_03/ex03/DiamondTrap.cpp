#include "DiamondTrap.hpp"
#include <iostream>
#include <stdint.h>

/* OCF */

DiamondTrap::DiamondTrap(void):
	ScavTrap() {
		std::cout << "DiamondTrap Constructor called" << std::endl;
		this->hp = 100;
		this->energy = 100;
		this->ad = 30;
}

DiamondTrap::DiamondTrap(const std::string& name):
	ClapTrap(name) {
		std::cout << "DiamondTrap Constructor(string) called" << std::endl;
		this->hp = 100;
		this->energy = 100;
		this->ad = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj):
	ClapTrap(obj) {
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	std::cout << "DiamondTrap Copy Assignment operator called => " << this->name << std::endl;
	if (this != &obj) {
		ClapTrap::operator=(obj);
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

/* MEMBER FUNCTIONS */

void	DiamondTrap::attack(const std::string& target) {
	if (this->hp == 0) {
		std::cout << "I'm dead, idiot. I can't attack" << std::endl;
		return ;
	}
	if (this->energy == 0) {
		std::cout << "No energy to attack" << std::endl;
		return ;
	}
	this->energy -= 1;
	std::cout << "DiamondTrap " << this->name << " attacks " << target \
				<< ", causing " << this->ad << " points of damage!" << std::endl;
}

void	DiamondTrap::highFivesGuys(void){
	std::cout << "DiamondTrap " << this->name << " requesting high-fives" << std::endl;
}
