#include "DiamondTrap.hpp"
#include <iostream>
#include <stdint.h>

/* OCF */

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap Constructor called" << std::endl;
	this->ClapTrap::name = "_clap_name";
	// this->hp = this->FragTrap::hp;
	// this->energy = this->ScavTrap::energy;
	// this->ad = this->FragTrap::ad;
}

DiamondTrap::DiamondTrap(const std::string& name):
	name(name) {
		std::cout << "DiamondTrap Constructor(string) called" << std::endl;
		this->ClapTrap::name = name + "_clap_name";
		// this->hp = 100;
		// this->energy = 100;
		// this->ad = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = obj;
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

void	DiamondTrap::whoAmI(void) {
	std::cout << "My name is Walter White (joke), it's (" << this->name << ")" << std::endl;
	std::cout << "	and my ClapTrap's name is (" << ClapTrap::name << ")" << std::endl;
}
